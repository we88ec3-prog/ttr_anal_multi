"""SYNTHETIC bounded reasoning models, NOT_NATIVE_MEF, not Client emulation.

These models encode selected normal-value branches documented in REPORT.md.
They do not run Lua, native code, network I/O, game resources, or a Server.
Owner replacement, rendering/device failures and scheduler fairness are excluded.
"""
from __future__ import annotations
from dataclasses import dataclass, field

@dataclass
class Camera:
    playing: bool = True
    current: bool = True
    frame: int = 0
    last_frame: int = 5
    snapshot_depth: int = 1
    restored: bool = False
    def ended(self) -> bool:
        return not self.current or not self.playing or self.frame > self.last_frame
    def apply_writes(self) -> bool:
        # 54E080 also checks playing; a tick tail-call alone does not mean a write.
        return self.current and self.playing and self.frame <= self.last_frame
    def stop(self) -> None:
        self.playing = False
    def detach(self) -> None:
        self.current = False
    def paired_pop(self) -> None:
        if self.snapshot_depth != 1:
            raise ValueError('model permits exactly one owned snapshot; no blind pop')
        self.snapshot_depth = 0
        self.restored = True

@dataclass
class Presentation:
    q_active: bool = True
    render_disabled: bool = False
    slow: bool = False
    countdown: float = 0.0
    letterbox: bool = False
    def normal_end(self) -> None:
        # Normal initialized Q End plus original qco cleanup is NOT an owner reset.
        self.q_active = False
    def selected_animation_delta(self, delta: float) -> float:
        if delta < 0:
            raise ValueError('negative dt excluded from this bounded model')
        scaled = self.slow or self.countdown > 0
        if scaled:
            self.countdown = max(0.0, self.countdown - delta)
        return delta * (0.20000000298023224 if scaled else 1.0)

@dataclass
class Image:
    fade_in: int = 2
    hold: int = 2
    fade_out: int = 2
    delay: int = 0
    phase: int = 1
    alive: bool = True
    alpha: int = 0
    released: bool = False
    deleted: bool = False
    in_left: int = field(init=False)
    out_left: int = field(init=False)
    def __post_init__(self) -> None:
        if self.fade_in <= 0 or self.fade_out <= 0 or self.hold < -1 or self.delay < 0:
            raise ValueError('only positive fade counts, hold -1/nonnegative and delay>=0')
        self.in_left = self.fade_in
        self.out_left = self.fade_out
    def native_tick(self) -> None:
        """Selected 553B60 phases. Alpha arithmetic models positive normal values only."""
        if self.phase == 0:
            self.alive = False
            return
        if self.phase == 1:
            if self.delay > 0:
                self.delay -= 1
                return
            self.phase = 2  # Native fall-through into fade-in.
        if self.phase == 2:
            if self.in_left > 0:
                self.in_left -= 1
                self.alpha = int(255 - self.in_left / self.fade_in * 255)
            else:
                self.alpha = 255
                self.phase = 3
        elif self.phase == 3:
            if self.hold > 0:
                self.hold -= 1
            elif self.hold == 0:
                self.phase = 4
            # hold=-1 remains here; this is not a duration of one tick.
        elif self.phase == 4:
            if self.out_left > 0:
                self.out_left -= 1
                self.alpha = int(self.out_left / self.fade_out * 255)
            else:
                self.alpha = 0
                self.phase = 0  # alive is cleared on a later native tick.
    def manager_tick(self) -> None:
        if self.deleted:
            return
        self.native_tick()
        if not self.alive:
            self.released = self.deleted = True  # Selected release/dtor/erase branch.

@dataclass
class ImageHolder:
    images: dict[int, Image] = field(default_factory=dict)
    last_handle: int = -1
    def create(self, handle: int, image: Image) -> None:
        if handle in self.images:
            raise ValueError('unique model handles required')
        self.images[handle] = image
        self.last_handle = handle
    def cancel_last(self) -> None:
        if self.last_handle in self.images:
            self.images[self.last_handle].alive = False
        self.last_handle = -1

@dataclass
class Actors:
    moving: dict[int, bool] = field(default_factory=dict)
    def stop(self, slot: int) -> None:
        if slot in self.moving:
            self.moving[slot] = False
    def all_stopped(self) -> bool:
        return all(not value for value in self.moving.values())
    def delete_all(self) -> None:
        self.moving.clear()

@dataclass
class Music:
    busy_slots: set[int] = field(default_factory=lambda: {0, 1})
    gain: float = 1.0
    def fade_to_zero(self) -> None:
        self.gain = 0.0
    def stop_all(self) -> None:
        self.busy_slots.clear()

# Analysis tool only: recommendations are narrower than native permissiveness.
# No generated .seq/.mef/.lua, and no encoded network messages.
def check_plan(plan: dict) -> list[str]:
    errors: list[str] = []
    if plan.get('kind') != 'NOT_NATIVE_MEF_ANALYSIS_PLAN':
        errors.append('analysis-only kind must be explicit')
    if plan.get('uninterrupted_claim'):
        errors.append('A finite interlude must not be labeled uninterrupted B')
    if plan.get('wait_after_q_end'):
        errors.append('removed qco is not a future cleanup timer')
    expected = {'world_hidden':'enable_world', 'slow_flag':'end_slow',
                'letterbox':'hide_letterbox', 'camera':'camera_restore_plan',
                'q_actors':'all_q_owner_cleanup', 'music':'shared_music_policy',
                'image_hold':'last_handle_cleanup'}
    cleanup=set(plan.get('cleanup', []))
    for state in plan.get('retained_states', []):
        if state not in expected:
            errors.append('state outside this bounded checker: '+str(state))
        elif expected[state] not in cleanup:
            errors.append('missing policy for '+state)
    if plan.get('retained_states') and not plan.get('exclusive_owner'):
        errors.append('shared state needs established exclusive ownership/baseline')
    if plan.get('image_hold_count', 0) > 1:
        errors.append('single Q saved handle does not track multiple persistent images')
    if plan.get('uses_stub_delete'):
        errors.append('Q.DeleteObject is not a cleanup implementation')
    return errors
