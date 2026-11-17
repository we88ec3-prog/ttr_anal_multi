#!/usr/bin/env python3
"""Synthetic checks of narrowly derived arithmetic/order contracts, NOT Client execution.
No sockets, game files, Lua, Server behavior, or deployment is performed.
"""
from __future__ import annotations
import struct
import unittest
from dataclasses import dataclass, field

def projected_delete_key(argument: int) -> int:
    """Post-marshalling integer projection only; does not model x87 coercion."""
    return (argument & 255) << 8

def ready_mask(mask: int, q_active: bool) -> int:
    return mask if q_active else mask & ~1

@dataclass
class Point:
    category: int
    key: int
    enabled: int

def point_delta(points: list[Point], category: int, key: int, status: int) -> bool:
    """First-match effect model; bool is THIS MODEL's diagnostic, not a native ACK."""
    for point in points:
        if (point.category, point.key) == (category, key):
            point.enabled = status
            return True
    return False

@dataclass
class TransitionModel:
    """Only selected directly observed fields, NOT a Client emulator."""
    map_key: int = 191
    points: list[Point] = field(default_factory=lambda: [Point(0, 7, 0)])
    slots: list[int] = field(default_factory=lambda: [0x0100,0x0200])
    graphics_requests: int = 0
    bounds_requests: int = 0
    minimap_requests: int = 0
    audio_tails: int = 0
    def world_map_loader(self, requested: int) -> None:
        if requested != self.map_key:
            self.map_key = requested  # request key precedes success
            self.graphics_requests += 1  # assumes changed valid basename for this model
            self.bounds_requests += 1
            self.minimap_requests += 1
        self.audio_tails += 1
    def network_map(self, requested: int) -> None:
        self.points.clear()
        self.slots.clear()
        self.world_map_loader(requested)
    def lua_map(self, requested: int) -> None:
        self.world_map_loader(requested)

def apply_association(world: set[int], rows: list[int]) -> list[int]:
    return [actor for actor in rows if actor in world]

class ContractChecks(unittest.TestCase):
    def test_projected_example(self): self.assertEqual(projected_delete_key(240),0xF000)
    def test_full_id_is_not_argument(self): self.assertEqual(projected_delete_key(0xF000),0)
    def test_argument_alias(self): self.assertEqual(projected_delete_key(496),projected_delete_key(240))
    def test_no_monster_low_byte(self):
        self.assertTrue(all(projected_delete_key(i)&255==0 for i in range(256)))
    def test_preserve_word_domain(self):
        self.assertTrue(all(0<=projected_delete_key(i)<=0xffff for i in (-1,0,240,65536)))
    def test_0007_hit_is_not_upsert(self):
        indexed={0x0101:("original",1001)}
        if 0x0101 not in indexed: indexed[0x0101]=("incoming",1036)
        self.assertEqual(indexed[0x0101],("original",1001))
    def test_removal_is_not_death(self):
        states={0x0101:"alive"}; removed=states.pop(0x0101)
        self.assertEqual(removed,"alive"); self.assertNotIn(0x0101,states)
    def test_repeated_state_enter_is_not_distinct_death(self):
        state=3; transitions=0
        for incoming in (3,3):
            state=incoming;transitions+=1
        self.assertEqual((state,transitions),(3,2))
    def test_control_hit_clears_collection(self):
        slots=[0x0100,0x0200,0x0300]
        if 0x0200 in slots:slots.clear()
        self.assertEqual(slots,[])
    def test_association_skips_missing_actor(self):
        self.assertEqual(apply_association({0x0100},[0x0100,0x0200]),[0x0100])
    def test_late_actor_does_not_replay_association(self):
        world={0x0100};slots=apply_association(world,[0x0200]);world.add(0x0200)
        self.assertEqual(slots,[])
    def test_association_shape(self):
        packet=struct.pack("<HIbHH",0xA,12,1,0x100,0x100)
        self.assertEqual(len(packet),11)
    def test_signed_count(self):
        self.assertEqual(struct.unpack("<b",b"\x80")[0],-128)
    def test_network_same_map_resets_points(self):
        m=TransitionModel();m.network_map(191);self.assertEqual(m.points,[])
    def test_network_same_map_resets_slots(self):
        m=TransitionModel();m.network_map(191);self.assertEqual(m.slots,[])
    def test_same_map_skips_resources(self):
        m=TransitionModel();m.network_map(191)
        self.assertEqual((m.graphics_requests,m.bounds_requests,m.minimap_requests,m.audio_tails),(0,0,0,1))
    def test_lua_same_map_keeps_direct_preamble_state(self):
        m=TransitionModel();m.lua_map(191);self.assertEqual((len(m.points),len(m.slots)),(1,2))
    def test_new_map_has_new_dependency_requests(self):
        m=TransitionModel();m.network_map(192)
        self.assertEqual((m.map_key,m.graphics_requests,m.bounds_requests,m.minimap_requests),(192,1,1,1))
    def test_ready_only_clears_mask1(self):self.assertEqual(ready_mask(3,False),2)
    def test_active_q_skips_mask1_clear(self):self.assertEqual(ready_mask(3,True),3)
    def test_ready_keeps_other_ui_mask(self):self.assertEqual(ready_mask(9,False),8)
    def test_loading_end_is_not_ready(self):
        loading=False;controller_ready=False
        self.assertEqual((loading,controller_ready),(False,False))
    def test_point_missing_not_created(self):
        p=[];self.assertFalse(point_delta(p,0,7,1));self.assertEqual(p,[])
    def test_point_first_only(self):
        p=[Point(0,7,0),Point(0,7,0)];point_delta(p,0,7,1)
        self.assertEqual([x.enabled for x in p],[1,0])
    def test_point_typed_category(self):
        p=[Point(2,7,0)];point_delta(p,0,7,1);self.assertEqual(p[0].enabled,0)
    def test_snapshot_overwrites_prior_delta(self):
        p=[Point(0,7,0)];point_delta(p,0,7,1);p=[Point(0,7,0)]
        self.assertEqual(p[0].enabled,0)
    def test_delta_before_snapshot_not_replayed(self):
        p=[];point_delta(p,0,7,1);p=[Point(0,7,0)];self.assertEqual(p[0].enabled,0)
    def test_world_key_is_not_resource_success(self):
        world_key=192;resource_success=False
        self.assertEqual((world_key,resource_success),(192,False))
    def test_q_restore_has_single_backup(self):
        world_key=192;saved_key=191
        requested_graphic=saved_key;saved_key=world_key
        self.assertEqual((world_key,saved_key,requested_graphic),(192,192,191))
    def test_native_messages_no_generation_field(self):
        point_delta_packet=struct.pack("<HHBB",0x48,7,0,1)
        ready_packet=struct.pack("<H",0x14)
        self.assertEqual((len(point_delta_packet),len(ready_packet)),(6,2))

if __name__ == "__main__":
    unittest.main()
