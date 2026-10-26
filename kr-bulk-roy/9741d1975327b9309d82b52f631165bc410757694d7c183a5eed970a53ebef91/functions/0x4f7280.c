
void FUN_004f7280(int param_1,undefined4 param_2,short *param_3,int param_4)

{
  short sVar1;
  int iVar2;
  undefined2 *puVar3;
  short *psVar4;
  undefined4 uVar5;
  undefined2 *puVar6;
  
  if (param_4 == -1) {
    FUN_004a8680();
    param_4 = 0;
  }
  FUN_008438c0(&param_2);
  if (param_1 != *(int *)(param_1 + 0x124)) {
    iVar2 = *(int *)(param_1 + 0x10);
    psVar4 = param_3;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00402160(param_3,(int)psVar4 - (int)(param_3 + 1) >> 1);
    *(int *)(iVar2 + 0x1c) = param_4;
    return;
  }
  puVar3 = (undefined2 *)FUN_00891268(0x20);
  puVar6 = (undefined2 *)0x0;
  if (puVar3 != (undefined2 *)0x0) {
    *(undefined4 *)(puVar3 + 8) = 0;
    *(undefined4 *)(puVar3 + 10) = 7;
    *puVar3 = 0;
    puVar6 = puVar3;
  }
  psVar4 = param_3;
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  FUN_00402160(param_3,(int)psVar4 - (int)(param_3 + 1) >> 1);
  *(int *)(puVar6 + 0xe) = param_4;
  uVar5 = FUN_0057ef20();
  FUN_0057e850(param_1 + 0x120,uVar5);
  return;
}

