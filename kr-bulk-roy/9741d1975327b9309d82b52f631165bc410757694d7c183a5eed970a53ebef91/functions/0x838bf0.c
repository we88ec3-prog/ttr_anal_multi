
undefined4 * FUN_00838bf0(undefined4 *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00906e9c;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = gbDxDynamicVBPool::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  local_8 = 2;
  uStack_7 = 0;
  param_1[5] = 0xffffffff;
  param_1[0x16] = param_2;
  param_1[0x17] = 0xfa000;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 4))(param_2,uVar1);
  }
  iVar2 = FUN_00891268(0x30);
  local_8 = 3;
  if (iVar2 != 0) {
    FUN_00838980(iVar2,param_1[0x16]);
  }
  _local_8 = CONCAT31(uStack_7,2);
  FUN_007bb350();
  param_1[5] = ((int)(param_1[2] - param_1[1]) >> 2) + -1;
  ExceptionList = local_10;
  return param_1;
}

