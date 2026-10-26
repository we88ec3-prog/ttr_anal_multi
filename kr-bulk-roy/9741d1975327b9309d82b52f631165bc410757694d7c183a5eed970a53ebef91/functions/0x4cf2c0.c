
void FUN_004cf2c0(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int in_ECX;
  uint local_28;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009405be;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffc8;
  ExceptionList = &local_14;
  iVar3 = FUN_004c9580(in_ECX);
  iVar4 = *(int *)(in_ECX + 0x368);
  if (iVar4 != 0) {
    *(undefined4 *)(iVar4 + 0x1c) = 0x42800000;
    *(undefined4 *)(iVar4 + 0x20) = 0x41600000;
  }
  if (iVar3 == 0x10) {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590(uVar2);
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c = 0xffffffff;
    }
    if (DAT_00f93930 == *(int *)(in_ECX + 0x9c)) {
      iVar4 = *(int *)(in_ECX + 0x368);
      *(undefined4 *)(iVar4 + 0x1c) = 0x42900000;
      *(undefined4 *)(iVar4 + 0x20) = 0x41700000;
      uVar1 = *(undefined4 *)(in_ECX + 0x368);
      local_28 = 4;
      iVar4 = FUN_007b4ed0(uVar1);
      *(undefined4 *)(iVar4 + 8) = 0x3ecccccd;
      iVar4 = FUN_007b4ed0(uVar1);
      *(undefined4 *)(iVar4 + 4) = 4;
      uVar1 = *(undefined4 *)(in_ECX + 0x368);
      iVar4 = FUN_007b4ed0(uVar1);
      *(undefined4 *)(iVar4 + 8) = 0x3e99999a;
      iVar4 = FUN_007b4ed0(uVar1);
      *(undefined4 *)(iVar4 + 4) = 1;
      uVar1 = *(undefined4 *)(in_ECX + 0x368);
      iVar4 = FUN_007b4ed0(uVar1);
      *(undefined4 *)(iVar4 + 8) = 0x3e99999a;
      iVar4 = FUN_007b4ed0(uVar1);
      *(undefined4 *)(iVar4 + 4) = 3;
      puVar5 = (undefined4 *)FUN_007b4ed0(*(undefined4 *)(in_ECX + 0x368));
      *puVar5 = 1;
      puVar5 = (undefined4 *)FUN_007b4ed0(*(undefined4 *)(in_ECX + 0x368));
      *puVar5 = 1;
      goto LAB_004cf56c;
    }
    local_28 = 2;
  }
  else {
    local_28 = (iVar3 != 0x11) - 1 & 2;
  }
  uVar1 = *(undefined4 *)(in_ECX + 0x368);
  iVar4 = FUN_007b4ed0(uVar1);
  *(undefined4 *)(iVar4 + 8) = 0x3f800000;
  iVar4 = FUN_007b4ed0(uVar1);
  *(uint *)(iVar4 + 4) = local_28;
  iVar4 = *(int *)(in_ECX + 0x368);
  *(undefined4 *)(iVar4 + 0x1c) = 0x42800000;
  *(undefined4 *)(iVar4 + 0x20) = 0x41000000;
  uVar1 = *(undefined4 *)(in_ECX + 0x368);
  iVar4 = FUN_007b4ed0(uVar1);
  *(undefined4 *)(iVar4 + 8) = 0;
  iVar4 = FUN_007b4ed0(uVar1);
  *(undefined4 *)(iVar4 + 4) = 1;
  uVar1 = *(undefined4 *)(in_ECX + 0x368);
  iVar4 = FUN_007b4ed0(uVar1);
  *(undefined4 *)(iVar4 + 8) = 0;
  iVar4 = FUN_007b4ed0(uVar1);
  *(undefined4 *)(iVar4 + 4) = 3;
  puVar5 = (undefined4 *)FUN_007b4ed0(*(undefined4 *)(in_ECX + 0x368));
  *puVar5 = 0;
  puVar5 = (undefined4 *)FUN_007b4ed0(*(undefined4 *)(in_ECX + 0x368));
  *puVar5 = 0;
LAB_004cf56c:
  iVar4 = FUN_007b4ed0(*(undefined4 *)(in_ECX + 0x368));
  *(uint *)(iVar4 + 4) = local_28;
  if (*(int *)(in_ECX + 0x368) != 0) {
    *(undefined4 *)(*(int *)(in_ECX + 0x368) + 0x28) = 1;
  }
  ExceptionList = local_14;
  return;
}

