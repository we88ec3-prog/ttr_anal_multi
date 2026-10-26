
void FUN_0076d1b0(void)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  int unaff_ESI;
  int local_14;
  int local_c;
  
  if ((*(int *)(unaff_ESI + 0xd4) != 0) &&
     (piVar1 = *(int **)(unaff_ESI + 0xd0), piVar1 != (int *)0x0)) {
    FUN_0076c900();
    uVar4 = ((*(int *)(unaff_ESI + 0xa8) - *(int *)(unaff_ESI + 0xb0)) - local_14) + local_c;
    uVar4 = ((int)uVar4 < 1) - 1 & uVar4;
    if ((uVar4 != piVar1[0x2e]) && (piVar1[0x2e] = uVar4, (int)uVar4 < piVar1[0x31])) {
      pcVar2 = *(code **)(*piVar1 + 0x128);
      piVar1[0x31] = uVar4;
      (*pcVar2)();
      (**(code **)(*piVar1 + 200))();
    }
    piVar1 = *(int **)(unaff_ESI + 0xd0);
    if ((int)uVar4 < piVar1[0x31]) {
      pcVar2 = *(code **)(*piVar1 + 0x128);
      piVar1[0x31] = uVar4;
      (*pcVar2)();
      (**(code **)(*piVar1 + 200))();
    }
    iVar3 = *(int *)(*(int *)(unaff_ESI + 0xd0) + 0xc4);
    if (*(int *)(*(int *)(unaff_ESI + 0xd4) + 0xa8) != iVar3) {
      FUN_0076cd50(*(int *)(unaff_ESI + 0xd4),iVar3);
      FUN_00745b80();
    }
  }
  return;
}

