
undefined2 *
FUN_00531a80(undefined2 *param_1,short *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  short sVar1;
  short *psVar2;
  short *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00912d88;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  psVar2 = in_ECX;
  do {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  } while (sVar1 != 0);
  FUN_00402160(in_ECX,(int)psVar2 - (int)(in_ECX + 1) >> 1);
  local_8 = 0;
  *(undefined4 *)(param_1 + 0xe) = param_3;
  *(undefined4 *)(param_1 + 0x10) = param_4;
  *(undefined4 *)(param_1 + 0x12) = param_5;
  *(undefined4 *)(param_1 + 0x1e) = 7;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  param_1[0x14] = 0;
  psVar2 = param_2;
  do {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  } while (sVar1 != 0);
  FUN_00402160(param_2,(int)psVar2 - (int)(param_2 + 1) >> 1);
  ExceptionList = local_10;
  return param_1;
}

