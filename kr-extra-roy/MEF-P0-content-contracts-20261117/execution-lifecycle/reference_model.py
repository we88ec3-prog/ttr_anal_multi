#!/usr/bin/env python3
"""SYN projections for P0 ownership contracts, never a Client/Lua emulator.

These counterexamples separate the normal immediate Q creation path from the
conditional deferred path, and call return from resource-release processing.
Symbolic identities are not real model IDs, slots, packets or run keys.
Only the displayed state/hold projections are modeled. In particular the item
dirty example checks retained immediate mode; it does not simulate the new/old
resource leases and release records of a complete replacement apply.
"""
from dataclasses import dataclass, field
import json
from pathlib import Path

@dataclass
class Doll:
    identity: str
    state: int = 0
    instance: str | None = None
    immediate: bool = True
    dirty: bool = False
    actor_holds: int = 1
    request_holds: int = 0
    release_jobs: list = field(default_factory=list)

    def cleanup_secondary(self):
        # This is only the proved D+8 state1 block of 7A57C0. The remaining
        # native effect/attachment cleanup is deliberately not simulated.
        if self.state == 1:
            self.release_jobs.append((self.identity, self.instance))
            self.instance = None
            self.state = 0
            self.dirty = True

    def drop_actor(self):
        self.actor_holds -= 1
        self.maybe_destroy()

    def maybe_destroy(self):
        if self.actor_holds == self.request_holds == 0 and self.state == 1:
            self.release_jobs.append((self.identity, self.instance))
            self.instance = None
            self.state = -1  # SYN destroyed marker, not a native D.state value.

    def request(self):
        self.request_holds += 1
        self.state = 2
        self.dirty = False
        if self.immediate:
            self.apply_and_release_request()

    def apply_and_release_request(self):
        self.instance = self.identity + ':instance'
        self.state = 1
        self.request_holds -= 1
        self.maybe_destroy()


def order_errors(sequence, dag):
    """Check conditional authoring order only; no claim of native enforcement."""
    positions = {name: i for i, name in enumerate(sequence)}
    if len(positions) != len(sequence):
        return ['duplicate action requires a separately scoped acquisition']
    return [x['before'] + ' must precede ' + x['after']
            for x in dag['conditional_edges']
            if x['before'] in positions and x['after'] in positions
            and positions[x['before']] >= positions[x['after']]]


def run_examples(dag=None):
    if dag is None:
        dag=json.loads((Path(__file__).resolve().parent/'cleanup-order.json').read_text())
    result=[]
    def record(name, condition, boundary):
        if not condition:
            raise ValueError('SYN counterexample failed: '+name)
        result.append({'name':name,'pass':True,'kind':'SYN','boundary':boundary})

    a=Doll('A',state=1,instance='A:instance')
    a.cleanup_secondary();a.drop_actor()
    record('applied_cleanup_then_destructor_does_not_duplicate_same_release',
           a.release_jobs==[('A','A:instance')] and a.state==0,
           'Normal state1 cleanup queues once then resets state; destructor state1 gate is skipped. Worker must still process the queued release.')

    a=Doll('A')
    a.request()
    record('normal_Q_immediate_creation_returns_after_apply',
           a.state==1 and a.request_holds==0,
           'Models normal worker apply-before-signal only. This does not prove draw/assets ready or that wait errors are handled.')

    a.dirty=True
    a.request()
    record('item_dirty_does_not_change_immediate_mode',
           a.immediate and a.state==1 and a.request_holds==0,
           'Selected item setter changes dirty/map, not D+20. Later request uses then-current immediate flag. Not a proof every engine writer preserves it.')

    old=Doll('old',immediate=False)
    old.request();old.cleanup_secondary();old.drop_actor()
    new=Doll('new',state=1,instance='new:instance')
    record('conditional_deferred_cleanup_does_not_reset_pending_state',
           old.state==2 and old.request_holds==1 and not old.release_jobs,
           'Conditional non-immediate branch only; not claimed to occur after normal initial Q.CreateObject returns in the selected scenes.')
    old.apply_and_release_request()
    record('conditional_late_apply_targets_old_D_not_reused_slot',
           old.release_jobs==[('old','old:instance')] and new.instance=='new:instance',
           'Request/result retains original D. A same-number slot is not used as callback lookup in the selected chain.')

    record('selected_SEQ_clear_before_restore_is_allowed',
           not order_errors(dag['original_selected_sequence'],dag),
           'Observed content order; not a runtime success test.')
    record('native_Stop_restore_before_clear_is_allowed',
           not order_errors(dag['native_active_stop_sequence'],dag),
           'Avoids inventing a universal ordering between map restore and actor clear.')
    record('reject_End_before_owned_cleanup',
           bool(order_errors(['normal_end','q_tree_clear_if_exclusive'],dag)),
           'Authoring policy: current callback can still execute synchronously, but removed qco provides no future cleanup scheduling guarantee.')
    record('reject_Detach_then_Stop_for_same_current_work',
           bool(order_errors(['camera_detach_if_chosen','camera_stop'],dag)),
           'Detach discards current access. Does not assert the old camera object is destroyed.')
    record('reject_map_restore_overwriting_final_snapshot',
           bool(order_errors(['snapshot_pop_if_acquired','map_restore_if_acquired'],dag)),
           'Conditional policy when final baseline is the acquired snapshot; both write camera state.')

    old_name='first.ogg'
    after_empty=old_name+''
    after_second=after_empty+'second.ogg'
    after_accepted_start=''  # 402A70 assign len0, not the setter append branch.
    record('empty_setter_retains_but_Start_assign_clears',
           after_empty==old_name and after_accepted_start=='',
           'Different native string helpers. No locale or audio output is emulated.')
    record('nonempty_SetFinalMusic_appends',
           after_second=='first.oggsecond.ogg',
           'Bounded nonspace branch; shows why a second policy write is not a replacement API.')
    return result

if __name__=='__main__':
    print(json.dumps({'kind':'SYN','examples':run_examples(),'client_executed':False,
                     'lua_executed':False,'server_executed':False},ensure_ascii=False,indent=2))
