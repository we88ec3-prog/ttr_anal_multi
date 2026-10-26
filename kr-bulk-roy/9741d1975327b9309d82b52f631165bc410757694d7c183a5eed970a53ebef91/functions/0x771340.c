
undefined2 * FUN_00771340(undefined2 *param_1,short *param_2)

{
  short sVar1;
  short *psVar2;
  short *in_EDX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090d633;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  *(undefined4 *)(param_1 + 0x18) = 7;
  *(undefined4 *)(param_1 + 0x16) = 0;
  param_1[0xe] = 0;
  local_8 = 1;
  psVar2 = in_EDX;
  do {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  } while (sVar1 != 0);
  FUN_00402160(in_EDX,(int)psVar2 - (int)(in_EDX + 1) >> 1);
  psVar2 = param_2;
  do {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  } while (sVar1 != 0);
  FUN_00402160(param_2,(int)psVar2 - (int)(param_2 + 1) >> 1);
  ExceptionList = local_10;
  return param_1;
}

