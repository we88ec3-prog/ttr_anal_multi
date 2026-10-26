
void FUN_006f8970(void)

{
  uint uVar1;
  int iVar2;
  uint in_ECX;
  int unaff_ESI;
  
  uVar1 = **(uint **)(unaff_ESI + 0x14);
  do {
    if ((*(uint **)(unaff_ESI + 0x14))[2] <= uVar1) {
LAB_006f899e:
      FUN_006f8b60();
      return;
    }
    if (in_ECX == uVar1) {
      iVar2 = FUN_006f8750();
      if (iVar2 != 0) {
        FUN_006f8b60();
        return;
      }
      goto LAB_006f899e;
    }
    uVar1 = uVar1 + 0x10;
  } while( true );
}

