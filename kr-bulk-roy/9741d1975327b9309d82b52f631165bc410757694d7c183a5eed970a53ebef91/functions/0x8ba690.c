
undefined4 FUN_008ba690(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (param_1 == (int *)0x0) {
    return 0x24;
  }
  iVar2 = *param_1;
  if (iVar2 == 0) {
    return 0x23;
  }
  iVar3 = *(int *)(iVar2 + 0x60);
  if (iVar3 == 0) {
    return 0x22;
  }
  uVar4 = *(undefined4 *)(iVar3 + 8);
  piVar1 = (int *)(iVar2 + 0x6c);
  iVar5 = FUN_008ba070(piVar1,param_1);
  if (iVar5 != 0) {
    FUN_008ba0c0(piVar1,iVar5);
    FUN_008b9f80(uVar4,iVar5);
    if (*(int **)(iVar2 + 0x58) == param_1) {
      *(undefined4 *)(iVar2 + 0x58) = 0;
      if (*piVar1 != 0) {
        *(undefined4 *)(iVar2 + 0x58) = *(undefined4 *)(*piVar1 + 8);
      }
    }
    FUN_008ba4d0(uVar4,param_1,iVar3);
    return 0;
  }
  return 0x24;
}

