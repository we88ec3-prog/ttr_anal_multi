
void FUN_005a83f0(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int unaff_ESI;
  int iVar5;
  
  iVar2 = FUN_006dfc40();
  iVar2 = *(int *)(iVar2 + 0x18);
  iVar3 = FUN_006dfc40();
  piVar1 = *(int **)(unaff_ESI + 0x13c);
  iVar2 = (int)(float)(((piVar1[2] - piVar1[4]) + iVar2) / 2);
  iVar5 = (int)(float)(((piVar1[3] - piVar1[5]) + *(int *)(iVar3 + 0x1c)) / 2);
  (**(code **)(*piVar1 + 0xb4))(6);
  (**(code **)(**(int **)(unaff_ESI + 0x140) + 0xb4))(6);
  iVar3 = *(int *)(unaff_ESI + 0x13c);
  iVar4 = (iVar2 - *(int *)(iVar3 + 8)) + -0x96;
  *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + iVar4;
  *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + iVar4;
  iVar4 = iVar5 - *(int *)(iVar3 + 0xc);
  *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + iVar4;
  *(int *)(iVar3 + 0x14) = *(int *)(iVar3 + 0x14) + iVar4;
  FUN_00746f70();
  iVar3 = *(int *)(unaff_ESI + 0x140);
  iVar2 = ((*(int *)(*(int *)(unaff_ESI + 0x13c) + 0x10) - *(int *)(iVar3 + 8)) -
          *(int *)(*(int *)(unaff_ESI + 0x13c) + 8)) + -0x96 + iVar2;
  *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + iVar2;
  *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + iVar2;
  iVar5 = iVar5 - *(int *)(iVar3 + 0xc);
  *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + iVar5;
  *(int *)(iVar3 + 0x14) = *(int *)(iVar3 + 0x14) + iVar5;
  FUN_00746f70();
  return;
}

