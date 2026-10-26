
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_005eee70(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091647f;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fab0d8 & 1) == 0) {
    DAT_00fab0d8 = DAT_00fab0d8 | 1;
    local_8 = 0;
    FUN_004dd4a0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    DAT_00fab0ec = 0;
    _DAT_00fab0f0 = 0;
    _DAT_00fab0f4 = 0;
    _atexit((_func_4879 *)&LAB_00bccdb0);
  }
  local_8 = 0xffffffff;
  local_20 = *(undefined4 *)(in_ECX + 0x1a8);
  local_1c = *(undefined4 *)(in_ECX + 0x1ac);
  FUN_004dd400(&DAT_00fab0dc,&local_18,&local_20);
  if (local_18 == DAT_00fab0e0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(local_18 + 0x18);
  }
  if ((DAT_00f8d9a8 & 1) == 0) {
    DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
    local_8 = 1;
    FUN_00523540();
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_00521080(&DAT_00f8d9bc);
    _atexit((_func_4879 *)&LAB_00bccc50);
    local_8 = 0xffffffff;
  }
  local_18 = *(int *)(in_ECX + 0x1a0);
  FUN_008438c0(&local_18);
  if ((local_14 != DAT_00f8d9b0) && (iVar1 = *(int *)(local_14 + 0x10), iVar1 != 0)) {
    iVar3 = *(int *)(iVar1 + 0x4c);
    if (iVar4 != 0) {
      iVar4 = *(int *)(iVar4 + 0x30);
      local_14 = 0;
      local_1c = iVar4;
      local_18 = iVar3;
      if ((DAT_00fc1b00 & 1) == 0) {
        DAT_00fc1b00 = DAT_00fc1b00 | 1;
        local_8 = 3;
        FUN_00829b30();
        _atexit(FUN_00bce3e0);
      }
      iVar2 = FUN_008295e0(*(undefined4 *)(iVar1 + 0x50),iVar4,&local_14);
      if (iVar2 != 0) {
        local_1c = *(int *)(iVar1 + 0x54) * iVar4;
        iVar3 = FUN_008fed10();
      }
    }
    ExceptionList = local_10;
    return iVar3;
  }
  ExceptionList = local_10;
  return 0;
}

