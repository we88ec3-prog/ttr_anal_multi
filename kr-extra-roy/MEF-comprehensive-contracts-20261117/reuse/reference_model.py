"""SYN-only image handoff examples and ZERO-DOLL layer projections.

Not native emulation, not deployable Lua, not a test of allocation/renderer errors.
The model makes the proven cancel-before-publish and deferred-sweep distinction
explicit. An interrupted stage is an analytical cut, not a native error-return API.
The layer projection intentionally requires ZERO CDoll or other unmodelled
leases. It cannot predict residency for retained actors. The sibling
reuse-followup/reference_model.py supplies the CDoll lease/reload examples.
"""
from dataclasses import dataclass, field

@dataclass
class Image:
    alive: bool = True
    deleted: bool = False

@dataclass
class QImageOwner:
    images: dict = field(default_factory=dict)
    last: int = -1

    def cancel_last(self):
        image = self.images.get(self.last)
        if image is not None:
            image.alive = False
        self.last = -1

    def begin_replacement(self):
        # 56496A calls 564A60 BEFORE allocator/constructor/publication.
        self.cancel_last()

    def publish_replacement(self, handle, image):
        # Synthetic fresh handle is supplied by the model, NOT an exposed Lua API.
        if handle in self.images:
            raise ValueError('bounded model excludes handle wrap/reuse')
        self.images[handle] = image
        self.last = handle

    def create(self, handle, image):
        self.begin_replacement()
        self.publish_replacement(handle, image)

    def qualifying_sweep(self):
        # Existing native manager semantics, abstracted without a timer/render loop.
        for key, image in list(self.images.items()):
            if not image.alive:
                image.deleted = True
                del self.images[key]

@dataclass
class ZeroDollLayerProjection:
    """Assumes ZERO doll/other leases and successful initialized-model reload.

    This restricted projection is not a complete native resource reference model.
    """
    levels: dict = field(default_factory=lambda: {i:set() for i in range(4)})
    resident: set = field(default_factory=set)

    def replace_level3(self, incoming):
        touched = self.levels[3] | set(incoming)
        self.levels[3] = set(incoming)
        held = set().union(*self.levels.values())
        self.resident |= held
        self.resident -= touched - held


def run_examples():
    """Meaningful counterexamples, not authority for the native semantics."""
    outcomes=[]
    def record(name, ok):
        if not ok:
            raise AssertionError(name)
        outcomes.append({'name':name,'result':'PASS_SYN_ONLY'})

    q=QImageOwner();a=Image();b=Image()
    q.create(1,a);q.create(2,b)
    record('replacement_cancels_previous_before_final_explicit_cancel', not a.alive and b.alive and q.last==2)
    record('cancel_does_not_synchronously_delete', not a.deleted and 1 in q.images)
    q.cancel_last();q.qualifying_sweep()
    record('old_test_last_handle_does_not_delete_first_is_superseded', a.deleted and b.deleted and not q.images)

    q=QImageOwner();old=Image();q.create(10,old)
    # A normal End/new accepted Start does not directly reset this field in the
    # bounded native bodies; event/script side effects are outside this example.
    q.begin_replacement()
    record('inherited_handle_is_cancelled_by_first_new_image', not old.alive and q.last==-1)
    record('interruption_before_publish_has_no_model_rollback', not old.alive and not old.deleted and q.last==-1)

    q=QImageOwner(images={77:Image()});foreign=q.images[77]
    q.cancel_last();q.create(11,Image());q.cancel_last();q.qualifying_sweep()
    record('q_cancel_is_not_global_shared_image_sweep', foreign.alive and not foreign.deleted and 77 in q.images)

    levels=ZeroDollLayerProjection();levels.replace_level3({'A'});levels.replace_level3(set())
    record('zero_doll_projection_empty_prepass_can_retire_previous_layer', 'A' not in levels.resident)
    levels=ZeroDollLayerProjection();levels.levels[1]={'A'};levels.replace_level3({'A'});levels.replace_level3(set())
    record('zero_doll_projection_lower_layer_prevents_unload', 'A' in levels.resident)
    levels=ZeroDollLayerProjection();levels.replace_level3({'A'});levels.replace_level3({'B'});levels.replace_level3(set())
    record('zero_doll_projection_cleanup_in_B_removes_B_layer_too', not levels.resident)
    levels=ZeroDollLayerProjection();levels.replace_level3({'A'});levels.replace_level3(set());levels.replace_level3({'B'})
    record('zero_doll_projection_A_cleanup_before_B_preserves_B_layer', levels.resident=={'B'})
    return outcomes

if __name__=='__main__':
    import json
    print(json.dumps(run_examples(),ensure_ascii=False,indent=2))
