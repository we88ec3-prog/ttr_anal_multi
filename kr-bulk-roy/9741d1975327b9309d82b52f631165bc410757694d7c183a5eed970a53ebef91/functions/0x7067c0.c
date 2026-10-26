
int FUN_007067c0(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  if (((*(undefined4 **)(param_1 + 8) <= puVar1) || (puVar1 == &DAT_00c0bfc8)) || (puVar1[2] == -1))
  {
    FUN_006f5da0(1);
  }
  piVar2 = *(int **)(param_1 + 0xc);
  piVar3 = *(int **)(param_1 + 8);
  piVar6 = &DAT_00c0bfc8;
  if (piVar2 < piVar3) {
    piVar6 = piVar2;
  }
  if ((piVar6[2] != 0) && ((piVar6[2] != 1 || (*piVar6 != 0)))) {
    return (int)piVar3 - (int)piVar2 >> 4;
  }
  if (((piVar2 + 4 < piVar3) && (piVar2 + 4 != &DAT_00c0bfc8)) && (0 < piVar2[6])) {
    uVar5 = FUN_006f6210(param_1);
    iVar4 = FUN_006f5f30(param_1,&DAT_00bfc638,uVar5);
    return iVar4;
  }
  iVar4 = FUN_006f5f30(param_1,&DAT_00bfc638,"assertion failed!");
  return iVar4;
}

