
undefined4 FUN_007cca50(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int *in_EDX;
  undefined4 local_18;
  undefined1 local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00934e97;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar3 = FUN_007c6700(param_1);
  if (iVar3 == 0) {
    FID_conflict__wprintf(&DAT_00c4feac);
    ExceptionList = local_10;
    return 0;
  }
  uVar1 = *(undefined4 *)(iVar3 + 0x74);
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(uVar2);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  FUN_0079be00(param_2);
  piVar4 = (int *)FUN_0083b440();
  if (*piVar4 != 0) {
    FID_conflict__wprintf(&DAT_00c4fe74);
    (**(code **)(*in_EDX + 0x6c))(local_14);
  }
  iVar3 = (**(code **)(*in_EDX + 0x50))(param_2,param_3,local_14);
  if (iVar3 == 0) {
    FID_conflict__wprintf(&DAT_00c4fea4);
    ExceptionList = local_10;
    return 0;
  }
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 1;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  FUN_0079be00(param_2);
  iVar3 = FUN_00891268(0xbc);
  local_8 = 2;
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_00856910();
  }
  local_8 = 0xffffffff;
  *(undefined4 *)(iVar3 + 0xb8) = local_18;
  FUN_00843fa0(uVar1,2);
  ExceptionList = local_10;
  return 1;
}

