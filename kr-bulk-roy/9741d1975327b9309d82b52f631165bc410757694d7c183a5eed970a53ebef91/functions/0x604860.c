
void FUN_00604860(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  if (*(int *)(param_1 + 0x10) == 0x387) {
    puVar2 = (undefined4 *)FUN_00891268(0x18);
    if (puVar2 != (undefined4 *)0x0) {
      puVar2[1] = 0xffffffff;
      puVar2[2] = 0xffffffff;
      puVar2[3] = 0;
      puVar2[4] = 0xf4350;
      *puVar2 = FoxUI::FXUIEventP1::vftable;
      puVar2[5] = in_ECX;
    }
    FUN_004072a0();
  }
  uVar1 = *(uint *)(param_1 + 0x10);
  if (uVar1 < 0x70b) {
    if (uVar1 == 0x70a) {
      if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0xfc) + 0x20)) {
        FUN_00604d10();
        return;
      }
    }
    else if (1000 < uVar1) {
      if (uVar1 < 0x3eb) {
        FUN_00604660();
        return;
      }
      if (uVar1 == 0x578) {
        if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x184) + 0x20)) {
          FUN_006042b0(in_ECX);
          return;
        }
        if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x188) + 0x20)) {
          FUN_00604330();
          return;
        }
      }
    }
  }
  else if (uVar1 == 0xf43a4) {
    FUN_00604800(in_ECX);
  }
  else if (uVar1 == 0xf43b1) {
    FUN_00604490();
    return;
  }
  return;
}

