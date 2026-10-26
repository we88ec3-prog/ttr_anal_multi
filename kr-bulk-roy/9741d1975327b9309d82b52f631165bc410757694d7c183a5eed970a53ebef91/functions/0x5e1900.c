
void FUN_005e1900(int param_1,int param_2,int param_3,int param_4,uint param_5,int param_6,
                 undefined1 param_7,int param_8)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00912701;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar1 = DAT_00f8d9a8 & 1;
  in_ECX[0x59] = param_2;
  in_ECX[0x5a] = param_3;
  in_ECX[0x5b] = param_4;
  in_ECX[0x58] = param_1;
  in_ECX[0x5d] = param_5 & 0xff;
  *(undefined1 *)(in_ECX + 0x5e) = (undefined1)param_6;
  *(undefined1 *)((int)in_ECX + 0x179) = param_7;
  if (uVar1 == 0) {
    DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
    local_8 = 0;
    FUN_00523540(uVar2);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_00521080(&DAT_00f8d9bc);
    _atexit((_func_4879 *)&LAB_00bccc50);
  }
  local_8 = 0xffffffff;
  param_5 = param_1;
  FUN_008438c0(&param_5);
  if (param_6 == DAT_00f8d9b0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(param_6 + 0x10);
  }
  uVar1 = DAT_00f8d9a4 & 1;
  in_ECX[0x61] = iVar3;
  if (uVar1 == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_8 = 2;
    FUN_0051c120();
    _atexit((_func_4879 *)&LAB_00bccc90);
    local_8 = 0xffffffff;
  }
  param_5 = in_ECX[0x59];
  FUN_008438c0(&param_5);
  if (param_6 == DAT_00f8d91c) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(param_6 + 0x10);
  }
  in_ECX[0x60] = iVar3;
  in_ECX[0x5f] = param_8;
  (**(code **)(*in_ECX + 0x194))();
  ExceptionList = local_10;
  return;
}

