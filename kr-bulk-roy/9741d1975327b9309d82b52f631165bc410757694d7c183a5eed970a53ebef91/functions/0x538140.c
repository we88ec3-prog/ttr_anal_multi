
uint FUN_00538140(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091b411;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_8 = 0;
    FUN_0051c120(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccc90);
  }
  local_8 = 0xffffffff;
  FUN_008438c0(&param_1);
  if (local_14 == DAT_00f8d91c) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(local_14 + 0x10);
  }
  if ((*(int *)(iVar3 + 0x1c) == 0) && (*(int *)(iVar3 + 0x20) == 0)) {
    ExceptionList = local_10;
    return local_14 & 0xffffff00;
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
  param_1 = *(undefined4 *)(iVar3 + 0x20);
  FUN_008438c0(&param_1);
  if (local_14 == DAT_00f8d9b0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(local_14 + 0x10);
  }
  uVar2 = FUN_00537e70(iVar3,uVar1,param_2);
  ExceptionList = local_10;
  return uVar2;
}

