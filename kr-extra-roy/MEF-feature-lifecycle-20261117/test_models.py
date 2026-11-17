"""Offline SYN examples; not native execution or gameplay tests."""
import unittest
from models import Camera, Presentation, Image, ImageHolder, Actors, Music, check_plan

class SyntheticOwnerTests(unittest.TestCase):
    def test_camera_stop_ends(self):
        c=Camera();c.stop();self.assertTrue(c.ended())
    def test_stopped_camera_does_not_apply(self):
        c=Camera();c.stop();self.assertFalse(c.apply_writes())
    def test_camera_stop_not_restore(self):
        c=Camera();c.stop();self.assertFalse(c.restored);self.assertEqual(c.snapshot_depth,1)
    def test_detach_not_restore_or_stop(self):
        c=Camera();c.detach();self.assertTrue(c.ended());self.assertTrue(c.playing);self.assertFalse(c.restored)
    def test_pop_requires_owned_frame(self):
        c=Camera();c.stop();c.detach();c.paired_pop();self.assertTrue(c.restored)
        with self.assertRaises(ValueError):c.paired_pop()
    def test_camera_natural_tail_ended_not_pop(self):
        c=Camera(frame=6,last_frame=5);self.assertTrue(c.ended());self.assertFalse(c.restored)
    def test_end_preserves_world_render_flag(self):
        p=Presentation(render_disabled=True);p.normal_end();self.assertTrue(p.render_disabled)
    def test_end_preserves_letterbox(self):
        p=Presentation(letterbox=True);p.normal_end();self.assertTrue(p.letterbox)
    def test_end_preserves_slow_flag(self):
        p=Presentation(slow=True);p.normal_end();self.assertTrue(p.slow)
    def test_countdown_or_slow(self):
        for slow,countdown in [(True,0),(False,1),(True,1)]:
            p=Presentation(slow=slow,countdown=countdown)
            self.assertAlmostEqual(p.selected_animation_delta(0.1),0.020000000298023224)
    def test_clear_flag_with_countdown(self):
        p=Presentation(slow=False,countdown=.05);self.assertLess(p.selected_animation_delta(.1),.1)
        self.assertEqual(p.selected_animation_delta(.1),.1)
    def test_native_dt_not_server_clock(self):
        p=Presentation(slow=False,countdown=0);self.assertEqual(p.selected_animation_delta(.1),.1)
    def test_image_finite_finishes(self):
        i=Image()
        for _ in range(30):i.manager_tick()
        self.assertTrue(i.deleted);self.assertTrue(i.released)
    def test_image_alpha_zero_not_immediately_deleted(self):
        i=Image(phase=4);i.out_left=0;i.manager_tick()
        self.assertEqual((i.alpha,i.phase),(0,0));self.assertTrue(i.alive);self.assertFalse(i.deleted)
        i.manager_tick();self.assertTrue(i.deleted)
    def test_hold_minus_one_indefinite(self):
        i=Image(hold=-1)
        for _ in range(100):i.manager_tick()
        self.assertEqual(i.phase,3);self.assertFalse(i.deleted)
    def test_cancel_is_deferred(self):
        h=ImageHolder();i=Image(hold=-1);h.create(1,i);h.cancel_last()
        self.assertFalse(i.alive);self.assertFalse(i.deleted);i.manager_tick();self.assertTrue(i.deleted)
    def test_last_handle_does_not_delete_first(self):
        h=ImageHolder();a=Image(hold=-1);b=Image(hold=-1);h.create(1,a);h.create(2,b);h.cancel_last()
        a.manager_tick();b.manager_tick();self.assertFalse(a.deleted);self.assertTrue(b.deleted)
    def test_delay_postpones_finite_image(self):
        i=Image(delay=2);i.manager_tick();self.assertEqual(i.phase,1);i.manager_tick();self.assertEqual(i.phase,1)
        i.manager_tick();self.assertEqual(i.phase,2)
    def test_positive_fades_required_by_model(self):
        with self.assertRaises(ValueError):Image(fade_in=0)
    def test_stopped_actor_not_deleted(self):
        a=Actors({1:True});a.stop(1);self.assertTrue(a.all_stopped());self.assertIn(1,a.moving)
    def test_empty_actor_query_true(self):
        self.assertTrue(Actors().all_stopped())
    def test_delete_all_is_global_scope(self):
        a=Actors({1:True,2:False});a.delete_all();self.assertEqual(a.moving,{})
    def test_music_fade_not_release(self):
        m=Music();m.fade_to_zero();self.assertEqual(m.gain,0);self.assertEqual(m.busy_slots,{0,1})
    def test_music_stop_all_scope(self):
        m=Music();m.stop_all();self.assertEqual(m.busy_slots,set())

class PlanTests(unittest.TestCase):
    def plan(self,**kw):return {'kind':'NOT_NATIVE_MEF_ANALYSIS_PLAN',**kw}
    def test_simple_finite_plan(self):self.assertEqual(check_plan(self.plan()),[])
    def test_no_background_claim(self):self.assertTrue(check_plan(self.plan(uninterrupted_claim=True)))
    def test_no_wait_after_end(self):self.assertTrue(check_plan(self.plan(wait_after_q_end=True)))
    def test_missing_visual_restore(self):self.assertTrue(check_plan(self.plan(retained_states=['world_hidden'],exclusive_owner=True)))
    def test_explicit_visual_restore(self):self.assertEqual(check_plan(self.plan(retained_states=['world_hidden'],exclusive_owner=True,cleanup=['enable_world'])),[])
    def test_shared_ownership_needed(self):self.assertTrue(check_plan(self.plan(retained_states=['music'],cleanup=['shared_music_policy'])))
    def test_two_persistent_images_rejected(self):self.assertTrue(check_plan(self.plan(image_hold_count=2)))
    def test_invalid_actions_rejected(self):
        self.assertTrue(check_plan(self.plan(uses_stub_delete=True)))
        self.assertTrue(check_plan(self.plan(retained_states=['unproved_callback'],exclusive_owner=True)))

if __name__=='__main__':unittest.main()
