
void FUN_0069b1c0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  uint extraout_ECX;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 local_2c;
  uint local_28;
  ushort local_24;
  undefined1 local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093c8be;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_c = 0;
    FUN_0051c120(DAT_00d61f20 ^ (uint)&stack0xffffffc8);
    _atexit((_func_4879 *)&LAB_00bccc90);
  }
  local_c = 0xffffffff;
  local_2c = param_1;
  FUN_008438c0(&local_2c);
  if (local_28 == DAT_00f8d91c) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(local_28 + 0x10);
  }
  iVar3 = *(int *)(*(int *)(iVar3 + 0x54) + 8);
  if ((iVar3 - 1U < 0x2b) && (iVar1 = FUN_00520f40(), iVar1 != 0)) {
    uVar2 = 0;
    if (extraout_ECX < 0x2b) {
      uVar2 = FUN_00520f40();
    }
    FUN_006dc350(*(undefined4 *)(DAT_00fb1318 + 0xbfe8),uVar2);
    ExceptionList = local_14;
    return;
  }
  if (iVar3 == 0x26) {
    iVar3 = FUN_00404ba0();
    if (*(int *)(in_ECX + 0x120) - 1U < 0xf) {
      iVar3 = *(int *)(in_ECX + 0x120) * 0x108 + *(int *)(iVar3 + 0x6920);
    }
    else {
      iVar3 = 0;
    }
    local_28 = (uint)*(ushort *)(iVar3 + 0x100);
    uVar4 = *(undefined1 *)(iVar3 + 0x102);
    iVar3 = FUN_006dd0e0();
    uVar5 = (uint)local_24;
    if (iVar3 == 0) {
      uVar5 = local_28;
    }
  }
  else {
    if (iVar3 != 0x27) {
      ExceptionList = local_14;
      return;
    }
    iVar3 = FUN_00404ba0();
    if (*(int *)(in_ECX + 0x120) - 1U < 0xf) {
      iVar3 = *(int *)(in_ECX + 0x120) * 0x108 + *(int *)(iVar3 + 0x6920);
    }
    else {
      iVar3 = 0;
    }
    local_28 = (uint)*(ushort *)(iVar3 + 0x100);
    uVar4 = *(undefined1 *)(iVar3 + 0x102);
    iVar3 = FUN_006dd0e0();
    uVar5 = local_28;
    if (iVar3 != 0) {
      uVar4 = local_20;
    }
  }
  uVar5 = uVar5 & 0xffff;
  uVar6 = uVar5;
  uVar2 = FUN_00474db0(uVar5);
  iVar3 = FUN_00826610(uVar2,uVar6);
  if (iVar3 != 0) {
    uVar4 = 0;
  }
  FUN_006dc180(uVar5,uVar4,0);
  ExceptionList = local_14;
  return;
}

