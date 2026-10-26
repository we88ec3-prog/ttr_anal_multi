
void FUN_00403790(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091e71f;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar1 = DAT_00f8d9a4 & 1;
  *(undefined4 *)(in_ECX + 0x24c) = param_1;
  if (uVar1 == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_8 = 0;
    FUN_0051c120(uVar2);
    _atexit((_func_4879 *)&LAB_00bccc90);
  }
  local_8 = 0xffffffff;
  param_1 = *(undefined4 *)(in_ECX + 0x24c);
  FUN_008438c0(&param_1);
  if ((in_ECX == DAT_00f8d91c) || (*(int *)(in_ECX + 0x10) == 0)) {
    *(undefined4 *)(in_ECX + 0x248) = 0xffffffff;
  }
  else {
    *(undefined4 *)(in_ECX + 0x248) = *(undefined4 *)(*(int *)(in_ECX + 0x10) + 0x20);
  }
  if (*(int *)(in_ECX + 0x248) == -1) {
    *(undefined4 *)(in_ECX + 0x254) = 0;
  }
  else {
    if ((DAT_00f8d9a8 & 1) == 0) {
      DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
      local_8 = 1;
      FUN_00523540();
      local_8 = CONCAT31(local_8._1_3_,2);
      FUN_00521080(&DAT_00f8d9bc);
      _atexit((_func_4879 *)&LAB_00bccc50);
      local_8 = 0xffffffff;
    }
    param_1 = *(undefined4 *)(in_ECX + 0x248);
    FUN_008438c0(&param_1);
    if (in_ECX == DAT_00f8d9b0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(in_ECX + 0x10);
    }
    *(int *)(in_ECX + 0x254) = iVar3;
    if (iVar3 != 0) {
      *(undefined4 *)(in_ECX + 600) = *(undefined4 *)(iVar3 + 8);
      goto LAB_004038bf;
    }
  }
  *(undefined4 *)(in_ECX + 600) = 0xffffffff;
LAB_004038bf:
  if (*(int *)(in_ECX + 0x24c) == -1) {
    *(undefined4 *)(in_ECX + 0x250) = 0;
  }
  else {
    if ((DAT_00f8d9a4 & 1) == 0) {
      DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
      local_8 = 3;
      FUN_0051c120(uVar2);
      _atexit((_func_4879 *)&LAB_00bccc90);
      local_8 = 0xffffffff;
    }
    param_1 = *(undefined4 *)(in_ECX + 0x24c);
    FUN_008438c0(&param_1);
    if (in_ECX == DAT_00f8d91c) {
      *(undefined4 *)(in_ECX + 0x250) = 0;
    }
    else {
      *(undefined4 *)(in_ECX + 0x250) = *(undefined4 *)(in_ECX + 0x10);
    }
  }
  FUN_00403950();
  ExceptionList = local_10;
  return;
}

