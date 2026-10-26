
void FUN_00642700(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  if (uVar1 < 0x579) {
    if (uVar1 == 0x578) {
      if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x13c) + 0x20)) {
        puVar2 = (undefined4 *)FUN_00891268(0x18);
        if (puVar2 != (undefined4 *)0x0) {
          puVar2[1] = 0xffffffff;
          puVar2[2] = 0xffffffff;
          puVar2[3] = 0;
          puVar2[4] = 0xf433c;
          *puVar2 = FoxUI::FXUIEventI1::vftable;
          puVar2[5] = 0;
          FUN_004072a0();
          FUN_00643220();
          return;
        }
      }
      else {
        if (*(int *)(param_1 + 8) != *(int *)(*(int *)(in_ECX + 0x140) + 0x20)) {
          return;
        }
        puVar2 = (undefined4 *)FUN_00891268(0x18);
        if (puVar2 != (undefined4 *)0x0) {
          puVar2[1] = 0xffffffff;
          puVar2[2] = 0xffffffff;
          puVar2[3] = 0;
          puVar2[4] = 0xf433c;
          *puVar2 = FoxUI::FXUIEventI1::vftable;
          puVar2[5] = 1;
          FUN_004072a0();
          FUN_00643220();
          return;
        }
      }
      FUN_004072a0();
      FUN_00643220();
      return;
    }
    switch(uVar1) {
    case 0x3ea:
      FUN_00641c60(in_ECX);
    case 0x3ed:
      puVar2 = (undefined4 *)FUN_00891268(0x14);
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = FoxUI::FXUIEvent::vftable;
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0xf4367;
        FUN_004072a0();
        return;
      }
      FUN_004072a0();
      return;
    case 0x3eb:
      FUN_00642470();
      return;
    case 0x3ec:
      if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x138) + 0x20)) {
        FUN_006426a0();
        return;
      }
      break;
    case 0x3ee:
      FUN_00642320();
      return;
    case 0x3ef:
      FUN_006423b0();
      return;
    }
  }
  else if (uVar1 == 0x641) {
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x130) + 0x20)) {
      FUN_006425a0();
      FUN_00643220();
      return;
    }
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x134) + 0x20)) {
      FUN_00643220();
    }
  }
  return;
}

