"""Deterministic offline contract checks. No native/game/Server tests are run."""
from pathlib import Path
import json,struct
from contract import *

def run() -> dict:
    names=[]
    def check(name,condition):
        if not condition:raise ValueError('model assertion failed: '+name)
        names.append(name)
    def rejects(name,fn):
        try:fn()
        except (ValueError,struct.error):names.append(name);return
        raise ValueError('expected strict schema rejection: '+name)
    p=Path(__file__).resolve().parent
    trans=json.loads((p/'transition-profile.json').read_text())
    avatar=json.loads((p/'actor-operation-profile.json').read_text())
    edges=trans['release_order_policy']['required_before'];steps=trans['release_order_policy']['steps']
    row=(0x12345678,7,3,11,22,33,44,55,-1) # explicitly synthetic, NOT observed session data
    packet=relation_message([row],1)
    check('0008_size',len(packet)==26)
    check('0008_roundtrip',read_relations(packet)==(1,[row]))
    check('0008_two_rows',len(relation_message([row,row]))==48)
    check('0008_empty_snapshot',read_relations(relation_message([],1))==(1,[]))
    rejects('0008_fractional_tail',lambda:read_relations(packet+b'\0'))
    rejects('0008_bad_row_count',lambda:relation_message([(1,2)]))
    rejects('0008_bool_not_u32',lambda:relation_message([(True,)+row[1:]]))
    rejects('0008_signed_overflow',lambda:relation_message([row[:-1]+(32768,)]))
    pair=[(0x0100,0x0100)]
    check('000A_size',len(binding_message(row[0],pair))==11)
    check('000A_key_u32',struct.unpack_from('<I',binding_message(row[0],pair),2)[0]==row[0])
    check('000A_count_signed',struct.unpack_from('<b',binding_message(row[0],pair),6)[0]==1)
    check('000A_ready_dependencies',not binding_dependencies(row[0],pair,{row[0]},{0x0100}))
    check('000A_missing_relation',binding_dependencies(row[0],pair,set(),{0x0100})==['MISSING_RELATION'])
    check('000A_missing_actor',binding_dependencies(row[0],pair,{row[0]},set())==['MISSING_WORLD_ACTOR:256'])
    rejects('000A_profile_four_slots',lambda:binding_message(1,pair*4))
    rejects('000A_world_key_overflow',lambda:binding_message(1,[(65536,0)]))
    check('transition_order',not order_problems(steps,edges))
    bad=steps.copy();a=bad.index('publish_world_actors');b=bad.index('bind_control_slots');bad[a],bad[b]=bad[b],bad[a]
    check('transition_bind_before_actor_detected',bool(order_problems(bad,edges)))
    bad=steps.copy();a=bad.index('load_target_map');b=bad.index('publish_complete_points');bad[a],bad[b]=bad[b],bad[a]
    check('point_before_map_clear_detected',bool(order_problems(bad,edges)))
    check('transition_null_bindings_preserved',len(unbound(trans))==6)
    check('actor_null_bindings_preserved',len(unbound(avatar))==10)
    check('both_deployable_false',not trans['deployable']and not avatar['deployable'])
    base=dict(found=True,variant=2,part_present=True,old_variant=1,render_ptr=True,render_ready=True,catalog_allows=True)
    x=avatar_model(**base);check('avatar_metadata',x['metadata_variant']==2)
    check('avatar_dirty',x['dirty_requested'])
    check('avatar_not_visual_ack',not x['visual_success_proven'])
    x=avatar_model(**dict(base,render_ptr=False));check('metadata_before_model_gate',x['metadata_variant']==2 and x['selection_variant']==1 and not x['dirty_requested'])
    x=avatar_model(**dict(base,render_ready=False));check('render_ready_gate',not x['dirty_requested'])
    x=avatar_model(**dict(base,catalog_allows=False));check('catalog_gate',x['metadata_variant']==2 and not x['dirty_requested'])
    x=avatar_model(**dict(base,old_variant=2));check('same_selection_no_retry',not x['dirty_requested'])
    x=avatar_model(**dict(base,variant=0));check('zero_removes_override',x['selection_variant']is None and x['dirty_requested'])
    x=avatar_model(**dict(base,found=False));check('missing_actor_no_write',x['metadata_variant']is None)
    q=dict(type=11,event=10,current=0,required=1,selector=99)
    check('00DF_match',selected_intent([q],10)==99)
    check('00DF_completed_no_intent',selected_intent([dict(q,current=1)],10)is None)
    check('00DF_last_match_wins',selected_intent([q,dict(q,selector=22)],10)==22)
    check('00DF_last_zero_suppresses',selected_intent([q,dict(q,selector=0)],10)is None)
    check('00DF_wrong_event',selected_intent([q],9)is None)
    r=struct.pack('<HHHB',14,0x100,0x101,2)+b'\0'*8
    check('000E_pair_identity',result_pairs(r)==[(0x100,0x101,2)])
    rejects('000E_not_whole_record',lambda:result_pairs(r+b'\0'))
    return dict(status='PASS',model_tests=len(names),checks=names,synthetic=True,native_executed=False)
if __name__=='__main__':print(json.dumps(run(),ensure_ascii=False,indent=2))
