
undefined1 * FUN_007c5e90(undefined1 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009056d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pcVar2 = (char *)*param_2;
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *param_1 = 0;
  pcVar3 = pcVar2;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(pcVar2,(int)pcVar3 - (int)(pcVar2 + 1));
  local_8 = 0;
  pcVar2 = (char *)*param_3;
  *(undefined4 *)(param_1 + 0x30) = 0xf;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  param_1[0x1c] = 0;
  pcVar3 = pcVar2;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(pcVar2,(int)pcVar3 - (int)(pcVar2 + 1));
  ExceptionList = local_10;
  return param_1;
}

