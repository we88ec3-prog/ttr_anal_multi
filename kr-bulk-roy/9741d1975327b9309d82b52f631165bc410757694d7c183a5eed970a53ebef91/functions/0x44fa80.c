
undefined4 * FUN_0044fa80(undefined4 *param_1,int param_2,int param_3)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  undefined4 *puVar4;
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
  uVar3 = *(int *)(param_2 + 0x10) + *(int *)(param_3 + 0x10);
  uVar1 = param_1[4];
  if (((uVar1 <= uVar3) && (param_1[5] != uVar3)) && (cVar2 = FUN_00402610(uVar3,1), cVar2 != '\0'))
  {
    param_1[4] = uVar1;
    puVar4 = param_1;
    if (7 < (uint)param_1[5]) {
      puVar4 = (undefined4 *)*param_1;
    }
    *(undefined2 *)((int)puVar4 + uVar1 * 2) = 0;
  }
  FUN_004041f0(param_2,0,0xffffffff);
  FUN_004041f0(param_3,0,0xffffffff);
  ExceptionList = local_10;
  return param_1;
}

