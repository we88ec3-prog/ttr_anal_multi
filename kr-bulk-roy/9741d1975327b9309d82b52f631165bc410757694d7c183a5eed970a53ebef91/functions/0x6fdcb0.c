
void FUN_006fdcb0(void)

{
  int in_EAX;
  int iVar1;
  int unaff_ESI;
  
  if (in_EAX + 7U < 0x10000000) {
    iVar1 = FUN_00700880();
  }
  else {
    iVar1 = FUN_00700860();
  }
  *(int *)(unaff_ESI + 0x20) = iVar1;
  *(int *)(unaff_ESI + 0x2c) = in_EAX + 6;
  *(int *)(unaff_ESI + 0x1c) = in_EAX * 0x10 + iVar1;
  FUN_006fdc30();
  return;
}

