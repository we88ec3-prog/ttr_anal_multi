
int FUN_0042c0c0(int param_1)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int in_ECX;
  uint uVar5;
  ushort *puVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int iVar9;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009480bc;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar3 = *(int *)(*(int *)(param_1 + 0x108) + 0xcc);
  if (iVar3 == 0) {
    return 0;
  }
  iVar3 = *(int *)(iVar3 + 0xdc);
  uVar5 = 0xffffffff;
  if (iVar3 != 0) {
    uVar5 = *(uint *)(iVar3 + 0x20);
  }
  if (uVar5 == 0xffffffff) {
    return iVar3;
  }
  ExceptionList = &local_10;
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_8 = 0;
    FUN_00539c20(uVar2);
    _atexit((_func_4879 *)&LAB_00bccfb0);
  }
  iVar3 = (DAT_00fb723c - DAT_00fb7238) * 0x4bda12f7;
  if ((uint)((DAT_00fb723c - DAT_00fb7238) / 0x36) <= uVar5) {
    ExceptionList = local_10;
    return iVar3;
  }
  puVar6 = (ushort *)(uVar5 * 0x36 + DAT_00fb7238);
  if (puVar6 == (ushort *)0x0) {
    ExceptionList = local_10;
    return iVar3;
  }
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_8 = 1;
    FUN_00539c20(uVar2);
    _atexit((_func_4879 *)&LAB_00bccfb0);
  }
  local_8 = 0xffffffff;
  if (((char)puVar6[0x1a] == '\0') && ((char)puVar6[0x19] != *(char *)((int)puVar6 + 0x33))) {
    if (DAT_00fb7258 == 0) {
      iVar3 = FUN_0042bee0(param_1);
      ExceptionList = local_10;
      return iVar3;
    }
    if ((uint)*puVar6 != *(uint *)(DAT_00fb7258 + 0x24)) {
      puVar8 = (undefined4 *)FUN_00891268(0x14);
      if (puVar8 == (undefined4 *)0x0) {
        puVar8 = (undefined4 *)0x0;
      }
      else {
        *puVar8 = FoxUI::FXUIEvent::vftable;
        puVar8[1] = 0xffffffff;
        puVar8[2] = 0xffffffff;
        puVar8[3] = 0;
        puVar8[4] = 0xf43a2;
      }
      uVar7 = 0x196;
      iVar9 = param_1;
      FUN_005854b0(0x196,puVar8,param_1);
      iVar3 = FUN_00585330(uVar7);
      uVar7 = 0x5c;
      FUN_005854b0(0x5c,iVar3);
      puVar4 = (undefined4 *)FUN_00585330(uVar7);
      uVar7 = 0xcf;
      goto LAB_0042c2ed;
    }
    iVar9 = 0;
    puVar8 = (undefined4 *)0x0;
    uVar7 = 0x196;
    FUN_005854b0(0x196,0,0);
    iVar3 = FUN_00585330(uVar7);
    uVar7 = 0x5b;
    FUN_005854b0(0x5b,iVar3);
    puVar4 = (undefined4 *)FUN_00585330(uVar7);
  }
  else {
    param_1 = 0x196;
    iVar3 = FUN_005854b0();
    FUN_005740f0(&param_1);
    if (in_ECX == *(int *)(iVar3 + 4)) {
      pcVar1 = (code *)swi(3);
      iVar3 = (*pcVar1)();
      return iVar3;
    }
    if (*(uint *)(in_ECX + 0x24) < 8) {
      iVar3 = in_ECX + 0x10;
    }
    else {
      iVar3 = *(int *)(in_ECX + 0x10);
    }
    param_1 = 0x5a;
    iVar9 = FUN_005854b0();
    FUN_005740f0(&param_1);
    if (in_ECX == *(int *)(iVar9 + 4)) {
      pcVar1 = (code *)swi(3);
      iVar3 = (*pcVar1)();
      return iVar3;
    }
    puVar4 = (undefined4 *)(in_ECX + 0x10);
    if (7 < *(uint *)(in_ECX + 0x24)) {
      puVar4 = (undefined4 *)*puVar4;
    }
    iVar9 = 0;
    puVar8 = (undefined4 *)0x0;
  }
  uVar7 = 0xca;
LAB_0042c2ed:
  iVar3 = FUN_00404b10(uVar7,puVar4,iVar3,puVar8,iVar9);
  ExceptionList = local_10;
  return iVar3;
}

