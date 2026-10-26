
undefined4 * FUN_005e92c0(undefined4 *param_1,short *param_2,int param_3)

{
  short sVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  undefined4 *puVar5;
  short *psVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091bbd9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  param_1[5] = 7;
  param_1[4] = 0;
  *(undefined2 *)param_1 = 0;
  local_8 = 0;
  psVar6 = param_2;
  do {
    sVar1 = *psVar6;
    psVar6 = psVar6 + 1;
  } while (sVar1 != 0);
  uVar2 = param_1[4];
  uVar4 = ((int)psVar6 - (int)(param_2 + 1) >> 1) + *(int *)(param_3 + 0x10);
  if (((uVar2 <= uVar4) && (param_1[5] != uVar4)) && (cVar3 = FUN_00402610(uVar4,1), cVar3 != '\0'))
  {
    param_1[4] = uVar2;
    puVar5 = param_1;
    if (7 < (uint)param_1[5]) {
      puVar5 = (undefined4 *)*param_1;
    }
    *(undefined2 *)((int)puVar5 + uVar2 * 2) = 0;
  }
  psVar6 = param_2;
  do {
    sVar1 = *psVar6;
    psVar6 = psVar6 + 1;
  } while (sVar1 != 0);
  FUN_00404300(param_2,(int)psVar6 - (int)(param_2 + 1) >> 1);
  FUN_004041f0(param_3,0,0xffffffff);
  ExceptionList = local_10;
  return param_1;
}

