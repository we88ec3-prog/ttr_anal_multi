
undefined2 * FUN_0058fe70(undefined2 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  short sVar1;
  short *psVar2;
  short *psVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00912d88;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  psVar2 = (short *)*param_2;
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  psVar3 = psVar2;
  do {
    sVar1 = *psVar3;
    psVar3 = psVar3 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar2,(int)psVar3 - (int)(psVar2 + 1) >> 1);
  local_8 = 0;
  psVar2 = (short *)*param_3;
  *(undefined4 *)(param_1 + 0x18) = 7;
  *(undefined4 *)(param_1 + 0x16) = 0;
  param_1[0xe] = 0;
  psVar3 = psVar2;
  do {
    sVar1 = *psVar3;
    psVar3 = psVar3 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar2,(int)psVar3 - (int)(psVar2 + 1) >> 1);
  ExceptionList = local_10;
  return param_1;
}

