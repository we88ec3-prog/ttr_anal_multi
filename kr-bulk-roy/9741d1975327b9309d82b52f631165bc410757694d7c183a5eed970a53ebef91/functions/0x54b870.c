
undefined4 FUN_0054b870(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int unaff_EDI;
  
  uVar2 = *(int *)(unaff_EDI + 0x30) - *(int *)(unaff_EDI + 0x2c) >> 4;
  uVar1 = 0;
  uVar4 = 0;
  if (uVar2 != 0) {
    piVar3 = *(int **)(unaff_EDI + 0x2c);
    while (((*piVar3 != param_1 || (piVar3[1] != param_2)) || (piVar3[2] != param_3))) {
      uVar4 = uVar4 + 1;
      piVar3 = piVar3 + 4;
      if (uVar2 <= uVar4) {
        return uVar1;
      }
    }
    param_1 = piVar3[3];
    uVar1 = 0;
    FUN_008438c0(&param_1);
    if (param_2 != *(int *)(unaff_EDI + 8)) {
      uVar1 = *(undefined4 *)(param_2 + 0x10);
    }
  }
  return uVar1;
}

