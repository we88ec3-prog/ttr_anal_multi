#!/usr/bin/env python3
"""Bounded static register-origin analysis for the three pinned Lua 5.1 chunks.

This does not execute Lua. Values represent origins, not runtime values. Both
conditional successors are retained. Global/table lookup names are not asserted
to be immutable function identities, and calls are not assumed to be pure.
"""
from collections import deque
import json

OPS = ['MOVE','LOADK','LOADBOOL','LOADNIL','GETUPVAL','GETGLOBAL','GETTABLE','SETGLOBAL',
       'SETUPVAL','SETTABLE','NEWTABLE','SELF','ADD','SUB','MUL','DIV','MOD','POW','UNM',
       'NOT','LEN','CONCAT','JMP','EQ','LT','LE','TEST','TESTSET','CALL','TAILCALL',
       'RETURN','FORLOOP','FORPREP','TFORLOOP','SETLIST','CLOSE','CLOSURE','VARARG']

def analyze(proto):
    assert proto['nups'] == 0, 'Selected chunks have no captured upvalues'
    words=proto['words']; stack=proto['stack']; idx=proto['index']
    initial=tuple(frozenset([f'arg:{r}']) if r<proto['params'] else frozenset(['uninitialized'])
                  for r in range(stack))
    states={0:initial}; queue=deque([0]); calls={}; writes={}; table_writes={}
    def constant(k):
        return frozenset(['constant:'+json.dumps(proto['constants'][k],ensure_ascii=False)])
    def join(a,b):
        v=a|b
        return frozenset(['unknown:merged']) if len(v)>16 or 'unknown:merged' in v else v
    def fields(b,k):
        r=frozenset('field('+x+','+y+')' for x in b for y in k)
        return frozenset(['unknown:field']) if len(r)>16 or any(len(x)>400 for x in r) else r
    while queue:
        pc=queue.popleft(); state=list(states[pc]); w=words[pc]
        op=OPS[w&63]; a=(w>>6)&255;b=(w>>23)&511;c=(w>>14)&511;bx=w>>14
        nexts=[pc+1]
        def rk(v): return constant(v-256) if v>=256 else state[v]
        if op=='MOVE': state[a]=state[b]
        elif op=='LOADK': state[a]=constant(bx)
        elif op=='LOADBOOL':
            state[a]=frozenset(['constant:'+str(bool(b)).lower()])
            if c: nexts=[pc+2]
        elif op=='LOADNIL':
            for r in range(a,b+1):state[r]=frozenset(['constant:null'])
        elif op=='GETGLOBAL': state[a]=frozenset(['global:'+proto['constants'][bx]])
        elif op=='SETGLOBAL': writes[pc]=join(writes.get(pc,frozenset()),state[a])
        elif op=='GETTABLE': state[a]=fields(state[b],rk(c))
        elif op=='SETTABLE':
            table_writes[pc]=dict(table=sorted(state[a]),key=sorted(rk(b)),value=sorted(rk(c)))
        elif op=='NEWTABLE': state[a]=frozenset([f'newtable:{idx}:{pc}'])
        elif op=='SELF':
            recv=state[b]; key=rk(c)
            state[a+1]=recv;state[a]=fields(recv,key)
        elif op=='CLOSURE': state[a]=frozenset([f'closure:{proto["children"][bx]}'])
        elif op in ('ADD','SUB','MUL','CONCAT'):
            state[a]=frozenset([f'expression:{idx}:{pc}:{op}'])
        elif op in ('CALL','TAILCALL'):
            prev=calls.get(pc,dict(callee=frozenset(),args=[]))
            args=state[a+1:a+b] if b else state[a+1:]
            oldargs=prev['args']
            args=[join(v,oldargs[i] if i<len(oldargs) else frozenset()) for i,v in enumerate(args)]
            calls[pc]=dict(callee=join(prev['callee'],state[a]),args=args)
            if op=='TAILCALL': nexts=[]
            else:
                end=a+c-1 if c else stack
                for r in range(a,end):state[r]=frozenset([f'call-result:{idx}:{pc}:{r-a}'])
        elif op=='RETURN': nexts=[]
        elif op=='JMP': nexts=[pc+1+bx-131071]
        elif op in ('EQ','LE','TEST'):nexts=[pc+1,pc+2]
        else:raise ValueError(f'Unsupported opcode {op} at prototype {idx} pc {pc}')
        for nxt in nexts:
            if not 0<=nxt<len(words):raise ValueError('CFG outside selected prototype')
            if nxt in states:
                merged=tuple(join(x,y) for x,y in zip(states[nxt],state))
                if merged==states[nxt]:continue
                states[nxt]=merged
            else:states[nxt]=tuple(state)
            queue.append(nxt)
    call_records=[]
    for pc,r in sorted(calls.items()):
        w=words[pc]
        call_records.append(dict(pc=pc,chunk_offset=proto['code_offset']+pc*4,
             word=f'{w:08x}',opcode=OPS[w&63],A=(w>>6)&255,B=(w>>23)&511,C=(w>>14)&511,
             callee_origins=sorted(r['callee']),argument_origins=[sorted(v) for v in r['args']],
             argument_count_open=((w>>23)&511)==0))
    return dict(prototype=idx,code_offset=proto['code_offset'],word_count=len(words),
                reachable_pcs=sorted(states),calls=call_records,
                global_writes=[dict(pc=pc,name=proto['constants'][words[pc]>>14],origins=sorted(v)) for pc,v in sorted(writes.items())],
                table_writes=[dict(pc=pc,**v) for pc,v in sorted(table_writes.items())])
