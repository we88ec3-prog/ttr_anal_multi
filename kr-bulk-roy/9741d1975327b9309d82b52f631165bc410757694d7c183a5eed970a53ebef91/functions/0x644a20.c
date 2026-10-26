
/* WARNING: Removing unreachable block (ram,0x00644cc6) */
/* WARNING: Removing unreachable block (ram,0x00644e8c) */

void FUN_00644a20(void)

{
  uint uVar1;
  uint uVar2;
  int in_ECX;
  int iVar3;
  uint local_38;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00920ed6;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8 = 0;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
  }
  local_8 = 0xffffffff;
  FUN_0040ef80();
  local_8 = 1;
  FUN_0058ec10();
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    FUN_0089120c();
  }
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8 = 2;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_8 = 0xffffffff;
  }
  FUN_0040ef80();
  local_8 = 3;
  FUN_0058ec10();
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    FUN_0089120c();
  }
  iVar3 = 0;
  do {
    FUN_00645060();
    FUN_0040ef80();
    FUN_00424c80(L"Filter{0}");
    local_8._1_3_ = 0;
    if ((DAT_00faaf7c & 1) == 0) {
      DAT_00faaf7c = DAT_00faaf7c | 1;
      local_8._0_1_ = 5;
      local_8._1_3_ = 0;
      FUN_0058d410();
      _atexit((_func_4879 *)&LAB_00bccdc0);
    }
    local_8._0_1_ = 4;
    FUN_00590230();
    local_8 = CONCAT31(local_8._1_3_,6);
    FUN_0058ec10();
    if (7 < local_1c) {
      FUN_0089120c();
    }
    local_8 = 0xffffffff;
    if (7 < local_38) {
      FUN_0089120c();
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 5);
  uVar1 = *(uint *)(*(int *)(in_ECX + 0x150) + 0x28);
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8 = 7;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_8 = 0xffffffff;
  }
  FUN_00402160();
  local_8 = 8;
  if ((uVar1 >> 9 & 1) != 0) {
    FUN_00402160();
  }
  FUN_0058ec10();
  local_8 = 0xffffffff;
  if ((*(int *)(*(int *)(in_ECX + 0x110) + 0xcc) != 0) &&
     (*(int *)(*(int *)(in_ECX + 0x110) + 0xd8) != 0)) {
    FUN_005f55a0();
  }
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8 = 9;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_8 = 0xffffffff;
  }
  FUN_00590230();
  local_8 = 10;
  FUN_0058ec10();
  local_8 = 0xffffffff;
  if (7 < local_38) {
    FUN_0089120c();
  }
  iVar3 = 0;
  do {
    FUN_0040aa10();
    iVar3 = iVar3 + 1;
  } while (iVar3 < 5);
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 0xc;
  FUN_004095e0();
  FUN_004095e0();
  FUN_004095e0();
  FUN_004095e0();
  FUN_004095e0();
  FUN_004095e0();
  FUN_004095e0();
  FUN_004095e0();
  FUN_004095e0();
  FUN_004095e0();
  *(undefined4 *)(in_ECX + 0x128) = 0;
  *(undefined4 *)(in_ECX + 300) = 0;
  *(undefined4 *)(in_ECX + 0x130) = 0;
  *(undefined4 *)(in_ECX + 0x134) = 0;
  *(undefined4 *)(in_ECX + 0x138) = 0;
  *(undefined4 *)(in_ECX + 0x13c) = 0;
  *(undefined4 *)(in_ECX + 0x140) = 0;
  *(undefined4 *)(in_ECX + 0x144) = 0;
  *(undefined4 *)(in_ECX + 0x148) = 0;
  *(undefined4 *)(in_ECX + 0x14c) = 0;
  (**(code **)(**(int **)(in_ECX + 0x154) + 0xa0))();
  ExceptionList = local_10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

