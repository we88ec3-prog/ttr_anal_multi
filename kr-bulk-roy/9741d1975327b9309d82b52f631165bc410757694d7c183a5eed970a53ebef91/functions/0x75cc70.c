
undefined4 FUN_0075cc70(int param_1,short *param_2)

{
  short sVar1;
  int iVar2;
  int *piVar3;
  short *psVar4;
  int iVar5;
  int *piVar6;
  
  if (((*(int *)(param_1 + 0x24c) != 0) &&
      (iVar2 = *(int *)(*(int *)(param_1 + 0x24c) + 0xcc), iVar2 != 0)) &&
     ((undefined4 *)(iVar2 + 0xa8) != (undefined4 *)0x0)) {
    piVar3 = *(int **)(iVar2 + 0xac);
    for (piVar6 = *(int **)(iVar2 + 0xa8); piVar6 != piVar3; piVar6 = piVar6 + 1) {
      iVar2 = *piVar6;
      psVar4 = param_2;
      do {
        sVar1 = *psVar4;
        psVar4 = psVar4 + 1;
      } while (sVar1 != 0);
      iVar5 = FUN_0044df20(0,param_2,(int)psVar4 - (int)(param_2 + 1) >> 1);
      if (iVar5 == 0) {
        if (*(int *)(*(int *)(param_1 + 0x24c) + 0xcc) != 0) {
          FUN_0042c8e0(*(undefined4 *)(iVar2 + 0x20));
        }
        FUN_00405300(param_1 + 0xe8);
        *(undefined4 *)(param_1 + 0x154) = *(undefined4 *)(iVar2 + 0x154);
        return *(undefined4 *)(iVar2 + 0x20);
      }
    }
  }
  return 0xffffffff;
}

