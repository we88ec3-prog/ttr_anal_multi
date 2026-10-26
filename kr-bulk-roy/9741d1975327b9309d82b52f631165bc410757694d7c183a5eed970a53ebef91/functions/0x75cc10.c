
void FUN_0075cc10(void)

{
  int in_EAX;
  int iVar1;
  undefined2 *unaff_ESI;
  
  if (*(int *)(in_EAX + 0x24c) != 0) {
    iVar1 = FUN_00408810(0);
    *(undefined4 *)(unaff_ESI + 10) = 7;
    *(undefined4 *)(unaff_ESI + 8) = 0;
    *unaff_ESI = 0;
    FUN_004026e0(iVar1 + 0xe8,0,0xffffffff);
    return;
  }
  *(undefined4 *)(unaff_ESI + 10) = 7;
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *unaff_ESI = 0;
  return;
}

