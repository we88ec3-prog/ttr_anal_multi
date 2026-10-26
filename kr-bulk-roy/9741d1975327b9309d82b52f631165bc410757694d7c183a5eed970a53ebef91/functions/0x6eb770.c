
undefined4 FUN_006eb770(void)

{
  int *piVar1;
  int iVar2;
  int unaff_ESI;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(unaff_ESI + 0x10)) {
    iVar2 = 0;
    do {
      piVar1 = *(int **)(*(int *)(unaff_ESI + 0xc) + 0x214 + iVar2);
      (**(code **)(*piVar1 + 0x118))(piVar1);
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x218;
    } while (iVar3 < *(int *)(unaff_ESI + 0x10));
  }
  iVar3 = 0;
  if (0 < *(int *)(unaff_ESI + 0x1c)) {
    iVar2 = 0;
    do {
      piVar1 = *(int **)(iVar2 + 0x58 + *(int *)(unaff_ESI + 0x18));
      (**(code **)(*piVar1 + 0x44))(piVar1);
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x5c;
    } while (iVar3 < *(int *)(unaff_ESI + 0x1c));
  }
  return 0;
}

