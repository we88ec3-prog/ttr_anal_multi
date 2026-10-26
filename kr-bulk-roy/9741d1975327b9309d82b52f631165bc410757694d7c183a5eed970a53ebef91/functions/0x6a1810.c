
void FUN_006a1810(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *in_ECX;
  
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
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0x3ec) {
    FUN_006a2340();
  }
  else if (iVar1 == 0x578) {
    iVar1 = *(int *)(param_1 + 8);
    if (iVar1 == *(int *)(in_ECX[0x3e] + 0x20)) {
      FUN_006a1ef0(0);
      return;
    }
    if (iVar1 == *(int *)(in_ECX[0x3f] + 0x20)) {
      FUN_006a1ef0(1);
      return;
    }
    if (iVar1 == *(int *)(in_ECX[0x40] + 0x20)) {
      FUN_006a1ef0(2);
      return;
    }
    if (iVar1 == *(int *)(in_ECX[0x43] + 0x20)) {
      (**(code **)(*in_ECX + 0xd4))();
      return;
    }
    if (iVar1 == *(int *)(in_ECX[0x42] + 0x20)) {
      FUN_006a26b0(in_ECX);
      (**(code **)(*in_ECX + 0xd4))();
      return;
    }
    if (iVar1 == *(int *)(in_ECX[0x44] + 0x20)) {
      FUN_006a2fb0();
      return;
    }
  }
  else if ((iVar1 == 0xf43a4) && (*(int *)(param_1 + 0x14) == 0xf43a5)) {
    FUN_006a1960(in_ECX,*(undefined4 *)(*(int *)(param_1 + 0x1c) + 4),
                 *(undefined4 *)(*(int *)(param_1 + 0x1c) + 8),*(undefined4 *)(param_1 + 0x18));
    return;
  }
  return;
}

