
void FUN_0059aa60(void)

{
  int iVar1;
  int unaff_EDI;
  undefined4 local_14;
  undefined4 local_10;
  
  if (((*(int *)(unaff_EDI + 0x180) != 0) && (iVar1 = *(int *)(unaff_EDI + 0x184), iVar1 != 0)) &&
     (*(int *)(unaff_EDI + 0x188) != 0)) {
    FUN_00443da0();
    if ((*(uint *)(iVar1 + 0x28) >> 8 & 1) != 0) {
      FUN_00749970(local_10,local_14);
    }
    if ((*(uint *)(*(int *)(unaff_EDI + 0x188) + 0x28) >> 8 & 1) != 0) {
      FUN_00749970(local_10,local_14);
    }
  }
  return;
}

