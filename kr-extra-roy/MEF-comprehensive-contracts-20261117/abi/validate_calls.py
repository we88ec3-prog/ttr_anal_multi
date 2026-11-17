#!/usr/bin/env python3
"""Strict ABI preflight for a declarative call plan. NOT_NATIVE_MEF.
Reads JSON only. Does not execute Lua, resolve world identities, load assets,
modify resources, send packets, or certify a deployment/gameplay result.
"""
from pathlib import Path
import argparse,json,math,sys
HERE=Path(__file__).resolve().parent

def validate(doc):
 defs=json.loads((HERE/'abi-contracts.json').read_text());known={r['name']:r for r in defs['bindings']};errors=[];warnings=[]
 def issue(dst,code,message,index=None):dst.append(dict(code=code,message=message,call_index=index))
 if not isinstance(doc,dict)or not isinstance(doc.get('calls'),list):
  issue(errors,'PLAN_SHAPE','Expected an object with a calls array.');calls=[]
 else:calls=doc['calls']
 for i,c in enumerate(calls):
  if not isinstance(c,dict):issue(errors,'CALL_SHAPE','Call must be an object.',i);continue
  name=c.get('name');args=c.get('args')
  if not isinstance(name,str)or name not in known:issue(errors,'UNKNOWN_BINDING','Binding is outside the pinned normal namespace set.',i);continue
  r=known[name]
  if r['binding_status']in('STUB','NOT_COUNT_QUERY'):issue(errors,'NONFUNCTIONAL_ENTRY','This name does not provide the requested operation/count; consult the capability report.',i)
  if not isinstance(args,list):issue(errors,'ARGUMENT_SHAPE','args must be an explicit array, including [] for zero arguments.',i);continue
  if len(args)!=r['argument_count']:
   issue(errors,'EXACT_ARITY','Expected '+str(r['argument_count'])+' arguments; native uses a suffix window and does not validate missing arguments.',i);continue
  for j,(value,kind)in enumerate(zip(args,r['argument_kinds']),1):
   label=name+' argument '+str(j)
   if kind in('integer32','float32'):
    valid=type(value)in(int,float)
    if valid:
     try:valid=math.isfinite(value)
     except(OverflowError,TypeError):valid=False
    if kind=='integer32':valid=valid and -2147483648<=value<=2147483647 and value==int(value)
    else:valid=valid and abs(value)<=3.4028234663852886e38
    if not valid:issue(errors,'NUMERIC_ABI',label+' requires a finite '+kind+' value; booleans and numeric strings are rejected by this authoring policy.',i)
   elif kind=='string':
    if not isinstance(value,str)or not value or '\0'in value:issue(errors,'STRING_ABI',label+' requires a nonempty string without NUL.',i)
   elif kind=='lua_truthiness':
    if type(value)is not bool:issue(errors,'BOOLEAN_ABI',label+' requires explicit true/false; native numeric 0 is true here.',i)
  use=c.get('result_use','ignore')
  if use not in('ignore','read_number'):issue(errors,'RESULT_USE','Use ignore or read_number; boolean truthiness/implicit ACK is not a valid numeric result contract.',i)
  if use=='read_number'and not r['produces_new_lua_value']:issue(errors,'NO_VALUE_PRODUCER','This binding does not establish a new result; return-count 1 is not success.',i)
  if c.get('trust_as_success'):issue(errors,'NO_GENERIC_ACK','An invocation or query value does not certify the whole operation.',i)
  if name=='lb.DoFile':issue(warnings,'LOADER_ZERO_AMBIGUOUS','Opening failure and successful execution both can return 0; verify current exports/version and use the established entry contract.',i)
  if name in('Tutorial.IsCharacterAvailable','Q.Book'):issue(warnings,'IGNORED_PARAMETER','Native accepts this positional argument but does not use it to choose an arbitrary character/book.',i)
  if name in('Tutorial.SetControlStatus','Tutorial.GetControlStatus')and args and type(args[0])in(int,float)and not 0<=args[0]<=31:issue(errors,'CONTROL_INDEX','The evidence-backed Tutorial control layout is 0..31; native has no general bounds check.',i)
 return dict(status='REJECTED'if errors else'ABI_PASS_ONLY',native_format=False,deployment_ready=False,gameplay_verified=False,calls_checked=len(calls),errors=errors,warnings=warnings,remaining_checks=['typed IDs and real receiver/context','resource dependency existence and selected bytes','prepass/formal agreement','owner acquisition/release and second-run behavior','Server state, completion and original Client play verification'])
if __name__=='__main__':
 p=argparse.ArgumentParser(description=__doc__);p.add_argument('plan',type=Path);a=p.parse_args()
 doc=json.loads(a.plan.read_text(encoding='utf-8'));r=validate(doc);print(json.dumps(r,ensure_ascii=False,indent=2));raise SystemExit(1 if r['errors']else 0)
