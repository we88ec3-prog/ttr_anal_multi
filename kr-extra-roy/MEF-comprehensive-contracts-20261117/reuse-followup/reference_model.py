"""SYN examples of bounded lease/queue claims, not a Client emulator.

The symbols below are illustrative identities, never actual scene/model/slot
assignments. Native evidence proves the selected writers and gates; these
examples only expose invalid deductions from a layer-only projection.
No files, threads, Lua, Client or Server are executed by this model.
"""
from dataclasses import dataclass, field


@dataclass(eq=False)
class Resource:
    identity: str = 'SYN_SAME_RESOURCE'
    layer_leases: int = 0
    doll_leases: int = 0
    resident: bool = False

    @property
    def references(self):
        return self.layer_leases + self.doll_leases

    def level_replace(self, present):
        self.layer_leases = int(present)
        # Other native layers/owners are intentionally absent in these cases.
        self.resident = bool(self.references)


@dataclass(eq=False)
class Doll:
    state: int = 0
    dirty: bool = True
    instance: bool = False
    q_owned: bool = True
    request_holds: int = 0
    destroyed: bool = False


@dataclass
class World:
    resource: Resource = field(default_factory=Resource)
    updates: list = field(default_factory=list)
    results: list = field(default_factory=list)
    releases: list = field(default_factory=list)

    def submit(self, d):
        first = d.state == 0
        d.request_holds += 1
        d.dirty = False
        d.state = 2
        self.updates.append((d, first))

    def tick_request_gate(self, d):
        if d.dirty and d.state not in (2, 3):
            self.submit(d)

    def work_one(self, catalog_valid=True, asset_available=True):
        d, first = self.updates.pop(0)
        if catalog_valid:
            # Same Resource object survives residency retirement/reload.
            self.resource.doll_leases += 1
            if not self.resource.resident:
                self.resource.resident = asset_available
        self.results.append((d, first, catalog_valid,
                             catalog_valid and self.resource.resident))

    def apply_one(self):
        d, first, valid, instance = self.results.pop(0)
        if valid:
            if not first:
                self.releases.append(self.resource)
            d.state, d.instance = 1, instance
        else:
            d.state, d.instance = 3, False
        d.request_holds -= 1
        self.maybe_destroy(d)

    def drop_q_reference(self, d):
        d.q_owned = False
        self.maybe_destroy(d)

    def maybe_destroy(self, d):
        if not d.destroyed and not d.q_owned and d.request_holds == 0:
            d.destroyed = True
            if d.state == 1:
                self.releases.append(self.resource)

    def release_one(self):
        r = self.releases.pop(0)
        r.doll_leases -= 1
        if r.doll_leases < 0:
            raise AssertionError('SYN unbalanced release')
        # Native release decrement alone is not a full-unload completion ACK.


def run_examples():
    out=[]
    def record(name, ok):
        if not ok:raise AssertionError(name)
        out.append({'name':name,'kind':'SYN','passed':True})

    w=World();d=Doll();w.resource.level_replace(True)
    w.submit(d);w.work_one();w.apply_one();w.resource.level_replace(False)
    record('retained_applied_doll_protects_resource_after_level3_removed',
           w.resource.references==1 and w.resource.resident and d.instance)

    w=World();w.resource.level_replace(True);w.resource.level_replace(False)
    record('zero_other_leases_can_retire_residency',not w.resource.resident)

    d=Doll();same=w.resource;w.submit(d);w.work_one();w.apply_one()
    record('valid_request_reloads_same_resource_identity_without_layer_lease',
           w.resource is same and w.resource.layer_leases==0 and
           w.resource.doll_leases==1 and w.resource.resident and d.instance)

    w=World();d=Doll();w.submit(d);w.work_one(catalog_valid=False);w.apply_one()
    d.dirty=True;w.resource.level_replace(True);w.tick_request_gate(d)
    record('new_level_job_does_not_repair_failed_doll_or_enable_tick_retry',
           d.state==3 and not d.instance and not w.updates and
           w.resource.doll_leases==0)

    w=World();d=Doll();w.submit(d);d.dirty=True;w.tick_request_gate(d)
    record('pending_state_does_not_create_second_request_on_tick',
           len(w.updates)==1 and d.request_holds==1)

    w.work_one();w.apply_one();d.dirty=True;w.tick_request_gate(d)
    w.work_one();w.apply_one()
    record('replacement_acquires_before_old_release',
           w.resource.doll_leases==2 and len(w.releases)==1)
    w.release_one()
    record('replacement_release_preserves_one_live_doll_lease',
           w.resource.doll_leases==1 and d.state==1)
    w.drop_q_reference(d);w.release_one()
    record('final_doll_destruction_balances_successful_request_lease',
           w.resource.doll_leases==0 and d.destroyed)

    w=World();d=Doll();w.resource.level_replace(True);w.submit(d)
    w.drop_q_reference(d);w.resource.level_replace(False)
    record('level_job_completion_does_not_drain_pending_doll_request',
           len(w.updates)==1 and not d.destroyed and d.request_holds==1)
    w.work_one();w.apply_one()
    record('retained_request_applies_original_doll_then_queues_final_release',
           d.destroyed and d.state==1 and len(w.releases)==1 and
           w.resource.doll_leases==1)
    w.release_one()
    record('late_apply_release_balances_without_new_scene_target',
           w.resource.doll_leases==0)

    w=World();d=Doll();w.submit(d);w.work_one(asset_available=False);w.apply_one()
    record('valid_request_state1_is_not_asset_or_draw_success_ack',
           d.state==1 and not d.instance and not w.resource.resident and
           w.resource.doll_leases==1)
    return out


if __name__=='__main__':
    import json
    print(json.dumps({'scope':'SYN only','examples':run_examples()},indent=2))
