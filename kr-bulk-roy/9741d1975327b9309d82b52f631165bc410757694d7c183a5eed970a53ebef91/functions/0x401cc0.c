
undefined4 * FUN_00401cc0(undefined4 *param_1,char *param_2,int param_3)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  undefined4 *puVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00913839;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  param_1[5] = 0xf;
  param_1[4] = 0;
  *(undefined1 *)param_1 = 0;
  local_8 = 0;
  pcVar3 = param_2;
  do {
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  pcVar1 = (char *)param_1[4];
  pcVar3 = pcVar3 + (*(int *)(param_3 + 0x10) - (int)(param_2 + 1));
  if (((pcVar1 <= pcVar3) && ((char *)param_1[5] != pcVar3)) &&
     (cVar2 = FUN_00402f80(pcVar3,1), cVar2 != '\0')) {
    param_1[4] = pcVar1;
    puVar4 = param_1;
    if (0xf < (uint)param_1[5]) {
      puVar4 = (undefined4 *)*param_1;
    }
    *(char *)((int)puVar4 + (int)pcVar1) = '\0';
  }
  pcVar3 = param_2;
  do {
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  FUN_00401fc0(param_2,(int)pcVar3 - (int)(param_2 + 1));
  FUN_00401ed0(param_3,0,0xffffffff);
  ExceptionList = local_10;
  return param_1;
}

