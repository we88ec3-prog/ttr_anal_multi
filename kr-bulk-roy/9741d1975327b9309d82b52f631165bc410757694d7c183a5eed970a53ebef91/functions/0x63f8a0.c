
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0063f8a0(void)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int in_ECX;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  uVar2 = *(uint *)(*(int *)(in_ECX + 0x110) + 0x28);
  if (((uVar2 >> 8 & 1) == 0) || ((uVar2 >> 9 & 1) == 0)) {
    iVar6 = *(int *)(*(int *)(in_ECX + 0xfc) + 0xcc);
    if (iVar6 == 0) {
      return;
    }
    iVar6 = *(int *)(iVar6 + 0xdc);
    if (iVar6 == 0) {
      return;
    }
    if (*(int *)(iVar6 + 0x20) == -1) {
      return;
    }
    iVar6 = *(int *)(*(int *)(in_ECX + 0xfc) + 0xcc);
    if (iVar6 == 0) {
      iVar6 = -1;
    }
    else {
      iVar6 = *(int *)(iVar6 + 0xdc);
      if (iVar6 == 0) {
        iVar6 = -1;
      }
      else {
        iVar6 = *(int *)(iVar6 + 0x20);
      }
    }
    if ((_DAT_00fd94dc & 1) == 0) {
      _DAT_00fd94dc = _DAT_00fd94dc | 1;
      FUN_004f10f0();
      _atexit((_func_4879 *)&LAB_00bce260);
    }
    uVar4 = DAT_00fdf3b4 - DAT_00fdf3b0 >> 2;
    uVar2 = 0;
    if (uVar4 == 0) {
      return;
    }
    while (iVar5 = *(int *)(DAT_00fdf3b0 + uVar2 * 4), *(int *)(iVar5 + 8) != iVar6) {
      uVar2 = uVar2 + 1;
      if (uVar4 <= uVar2) {
        return;
      }
    }
  }
  else {
    iVar5 = DAT_00fdf3ac;
    if ((_DAT_00fd94dc & 1) == 0) {
      _DAT_00fd94dc = _DAT_00fd94dc | 1;
      FUN_004f10f0();
      _atexit((_func_4879 *)&LAB_00bce260);
      iVar5 = DAT_00fdf3ac;
    }
  }
  if (iVar5 != 0) {
    puVar3 = (undefined4 *)FUN_00891268(0x18);
    if (puVar3 != (undefined4 *)0x0) {
      uVar1 = *(undefined4 *)(iVar5 + 8);
      puVar3[1] = 0xffffffff;
      puVar3[2] = 0xffffffff;
      puVar3[3] = 0;
      puVar3[4] = 0xf4378;
      *puVar3 = FoxUI::FXUIEventI1::vftable;
      puVar3[5] = uVar1;
      FUN_004072a0();
      return;
    }
    FUN_004072a0();
  }
  return;
}

