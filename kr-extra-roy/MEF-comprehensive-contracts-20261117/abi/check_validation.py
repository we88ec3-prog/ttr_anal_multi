from pathlib import Path
import json
from validate_calls import validate
H=Path(__file__).parent
cases=[
 ('numeric_switch_explicit_integer',{'calls':[{'name':'Tutorial.SetKeymapEnabled','args':[1]}]},'ABI_PASS_ONLY',None),
 ('boolean_is_not_integer_one',{'calls':[{'name':'Tutorial.SetKeymapEnabled','args':[True]}]},'REJECTED','NUMERIC_ABI'),
 ('manual_false_is_explicit_boolean',{'calls':[{'name':'ScenarioTalkTable.open','args':[12,11,False]}]},'ABI_PASS_ONLY',None),
 ('manual_zero_is_native_truthy',{'calls':[{'name':'ScenarioTalkTable.open','args':[12,11,0]}]},'REJECTED','BOOLEAN_ABI'),
 ('setter_has_no_native_success_value',{'calls':[{'name':'Q.ShowObject','args':[1,1],'result_use':'read_number'}]},'REJECTED','NO_VALUE_PRODUCER'),
 ('query_is_numeric_not_truthiness',{'calls':[{'name':'Q.IsCutSceneRunning','args':[],'result_use':'truthiness'}]},'REJECTED','RESULT_USE'),
 ('missing_suffix_argument',{'calls':[{'name':'Q.ShowObject','args':[1]}]},'REJECTED','EXACT_ARITY'),
 ('extra_suffix_argument',{'calls':[{'name':'Q.ShowObject','args':[1,1,0]}]},'REJECTED','EXACT_ARITY'),
 ('stub_is_not_delete',{'calls':[{'name':'Q.DeleteObject','args':[1]}]},'REJECTED','NONFUNCTIONAL_ENTRY'),
 ('count_name_is_not_count_producer',{'calls':[{'name':'lb.GetObjectCount','args':[],'result_use':'read_number'}]},'REJECTED','NONFUNCTIONAL_ENTRY'),
 ('fractional_integer_cannot_depend_on_rounding',{'calls':[{'name':'Tutorial.SetKeymapEnabled','args':[0.5]}]},'REJECTED','NUMERIC_ABI'),
 ('unsigned_overflow_cannot_depend_on_fistp',{'calls':[{'name':'Q.FadeColor','args':[4294967295]}]},'REJECTED','NUMERIC_ABI'),
 ('ignored_parameter_warning',{'calls':[{'name':'Q.Book','args':[0]}]},'ABI_PASS_ONLY',None),
 ('out_of_layout_control_index',{'calls':[{'name':'Tutorial.GetControlStatus','args':[32],'result_use':'read_number'}]},'REJECTED','CONTROL_INDEX'),
]
actual=[]
for name,plan,status,code in cases:
 r=validate(plan)
 if r['status']!=status or (code and code not in [x['code']for x in r['errors']]):raise ValueError(name)
 if r['deployment_ready']or r['gameplay_verified']or r['native_format']:raise ValueError('scope promoted')
 actual.append(dict(case=name,expected_status=status,expected_error=code,result=r))
(H/'validation-examples.json').write_text(json.dumps(dict(scope='Synthetic authoring-policy fixtures only; not actual world IDs or deployment',cases=[dict(name=n,plan=p)for n,p,_,_ in cases]),ensure_ascii=False,indent=2)+'\n')
(H/'validation-results.json').write_text(json.dumps(dict(status='PASS',checks=len(cases),scope='Pure JSON preflight behavior; no target execution',results=actual),ensure_ascii=False,indent=2)+'\n')
print('PASS',len(cases),'bounded ABI preflight checks')
