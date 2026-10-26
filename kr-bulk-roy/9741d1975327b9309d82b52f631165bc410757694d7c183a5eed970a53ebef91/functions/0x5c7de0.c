
undefined4 FUN_005c7de0(void)

{
  uint in_EAX;
  int iVar1;
  int *unaff_EDI;
  
  *unaff_EDI = 0;
  unaff_EDI[1] = 0;
  unaff_EDI[2] = 0;
  if (in_EAX == 0) {
    return 0;
  }
  if (0x7ffffff < in_EAX) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  iVar1 = FUN_00527d70();
  *unaff_EDI = iVar1;
  unaff_EDI[1] = iVar1;
  unaff_EDI[2] = in_EAX * 0x20 + iVar1;
  return 1;
}

