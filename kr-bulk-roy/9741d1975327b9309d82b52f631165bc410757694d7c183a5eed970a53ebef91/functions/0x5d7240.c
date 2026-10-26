
void FUN_005d7240(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091e71f;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if ((((in_ECX[0x94] == param_1) && (in_ECX[0x95] == param_2)) && (in_ECX[0x92] == param_3)) &&
     (in_ECX[0x93] == param_4)) {
    return;
  }
  ExceptionList = &local_10;
  in_ECX[0x95] = param_2;
  in_ECX[0x94] = param_1;
  in_ECX[0x92] = param_3;
  in_ECX[0x93] = param_4;
  if (param_1 == -1) {
    if ((DAT_00f8d9a4 & 1) == 0) {
      DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
      local_8 = 0;
      FUN_0051c120(uVar1);
      _atexit((_func_4879 *)&LAB_00bccc90);
    }
    local_8 = 0xffffffff;
    param_1 = in_ECX[0x95];
    FUN_008438c0(&param_1);
    if ((param_2 != DAT_00f8d91c) && (*(int *)(param_2 + 0x10) != 0)) {
      in_ECX[0x94] = *(int *)(*(int *)(param_2 + 0x10) + 0x20);
    }
  }
  if (in_ECX[0x94] == -1) {
    in_ECX[0x97] = 0;
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
    param_1 = in_ECX[0x94];
    FUN_008438c0(&param_1);
    if (param_2 == DAT_00f8d9b0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(param_2 + 0x10);
    }
    in_ECX[0x97] = iVar2;
    if (iVar2 != 0) {
      in_ECX[0x98] = *(int *)(iVar2 + 8);
      goto LAB_005d73a4;
    }
  }
  in_ECX[0x98] = -1;
LAB_005d73a4:
  if (in_ECX[0x95] == -1) {
    in_ECX[0x96] = 0;
  }
  else {
    if ((DAT_00f8d9a4 & 1) == 0) {
      DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
      local_8 = 3;
      FUN_0051c120(uVar1);
      _atexit((_func_4879 *)&LAB_00bccc90);
      local_8 = 0xffffffff;
    }
    param_1 = in_ECX[0x95];
    FUN_008438c0(&param_1);
    if (param_2 == DAT_00f8d91c) {
      in_ECX[0x96] = 0;
    }
    else {
      in_ECX[0x96] = *(int *)(param_2 + 0x10);
    }
  }
  FUN_005d7040();
  (**(code **)(*in_ECX + 0x1a4))();
  ExceptionList = local_10;
  return;
}

