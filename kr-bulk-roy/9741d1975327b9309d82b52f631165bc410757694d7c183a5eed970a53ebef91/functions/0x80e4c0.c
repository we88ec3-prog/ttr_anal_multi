
void FUN_0080e4c0(float *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  float local_20;
  float local_1c;
  float local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009205ce;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x24) == 0) {
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      local_8 = 0;
      FUN_0080a3a0(local_14);
      _atexit((_func_4879 *)&LAB_00bccdd0);
    }
    local_8 = 0xffffffff;
    uVar1 = FUN_0080ab00(&DAT_00fab028);
    *(undefined4 *)(in_ECX + 0x24) = uVar1;
  }
  if (*(int **)(in_ECX + 0x24) != (int *)0x0) {
    iVar2 = *(int *)(in_ECX + 0x28);
    if (iVar2 == 0) {
      local_20 = *param_1 * 0.1;
      local_1c = param_1[1] * 0.1;
      local_18 = param_1[2] * 0.1;
      iVar2 = (**(code **)(**(int **)(in_ECX + 0x24) + 0x10))(&local_20,0);
      *(int *)(in_ECX + 0x28) = iVar2;
      if (iVar2 != 0) {
        *(undefined4 *)(iVar2 + 0xc) = 0;
      }
    }
    else {
      if (*(int *)(iVar2 + 8) != 0) {
        (**(code **)(**(int **)(iVar2 + 8) + 0x28))();
      }
      FUN_0080cbe0();
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

