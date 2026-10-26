
void FUN_00735530(void)

{
  int iVar1;
  uint in_ECX;
  int unaff_EDI;
  undefined1 local_8 [4];
  
  if ((*(uint *)(unaff_EDI + 0x2c) != 0) &&
     (((int)in_ECX < 0 || (in_ECX < *(uint *)(unaff_EDI + 0x2c))))) {
    do {
      iVar1 = *(int *)(**(int **)(unaff_EDI + 0x28) + 0xc);
      if ((uint)(*(int *)(unaff_EDI + 0x40) - *(int *)(unaff_EDI + 0x48)) <= *(uint *)(iVar1 + 0x34)
         ) {
        return;
      }
      FUN_004ca200(unaff_EDI + 0x24,local_8,**(undefined4 **)(unaff_EDI + 0x28));
      FUN_00734ce0(*(undefined4 *)(unaff_EDI + 0x38));
      if (*(int *)(unaff_EDI + 0x44) != 0) {
        FUN_007354c0(*(undefined4 *)(unaff_EDI + 4));
      }
      if (7 < *(uint *)(iVar1 + 0x18)) {
        FUN_0089120c(*(undefined4 *)(iVar1 + 4));
      }
      *(undefined4 *)(iVar1 + 0x18) = 7;
      *(undefined4 *)(iVar1 + 0x14) = 0;
      *(undefined2 *)(iVar1 + 4) = 0;
      FUN_0089120c(iVar1);
    } while (*(int *)(unaff_EDI + 0x2c) != 0);
  }
  return;
}

