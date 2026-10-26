
void FUN_00767fa0(void)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  char cVar4;
  uint uVar5;
  int *piVar6;
  int unaff_EDI;
  
  iVar1 = *(int *)(unaff_EDI + 0x110);
  iVar2 = *(int *)(unaff_EDI + 0x114);
  if (iVar1 == iVar2) {
    piVar6 = *(int **)(unaff_EDI + 0x10c);
    piVar6[0x2e] = 0;
    if (0 < piVar6[0x31]) {
      pcVar3 = *(code **)(*piVar6 + 0x128);
      piVar6[0x31] = 0;
      (*pcVar3)();
      (**(code **)(*piVar6 + 200))();
    }
    piVar6 = *(int **)(unaff_EDI + 0x10c);
    piVar6[0x31] = 0;
  }
  else {
    cVar4 = FUN_00768190();
    uVar5 = iVar2 - iVar1 >> 2;
    if (*(int *)(unaff_EDI + 0x15c) == 1) {
      if (cVar4 == '\0') {
        uVar5 = uVar5 - 1;
      }
      uVar5 = uVar5 - *(int *)(unaff_EDI + 0x138);
      uVar5 = ((int)uVar5 < 0) - 1 & uVar5;
    }
    else if (cVar4 == '\0') {
      uVar5 = uVar5 - 1;
    }
    piVar6 = *(int **)(unaff_EDI + 0x10c);
    piVar6[0x2e] = uVar5;
    if ((int)uVar5 < piVar6[0x31]) {
      pcVar3 = *(code **)(*piVar6 + 0x128);
      piVar6[0x31] = uVar5;
      (*pcVar3)();
      (**(code **)(*piVar6 + 200))();
    }
    if ((int)uVar5 < *(int *)(unaff_EDI + 0x134)) {
      *(uint *)(unaff_EDI + 0x134) = uVar5;
    }
    piVar6 = *(int **)(unaff_EDI + 0x10c);
    piVar6[0x31] = *(int *)(unaff_EDI + 0x134);
  }
  (**(code **)(*piVar6 + 0x128))();
  (**(code **)(*piVar6 + 200))();
  FUN_00749920(*(undefined4 *)(unaff_EDI + 0x10c));
  return;
}

