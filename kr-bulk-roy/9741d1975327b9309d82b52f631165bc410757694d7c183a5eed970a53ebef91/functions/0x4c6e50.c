
void FUN_004c6e50(void)

{
  undefined4 in_EAX;
  int iVar1;
  int unaff_EDI;
  int local_c;
  undefined1 local_8 [4];
  
  *(undefined4 *)(unaff_EDI + 4) = in_EAX;
  iVar1 = FUN_0040f060();
  FUN_0082ef00(local_8);
  if ((local_c != *(int *)(iVar1 + 0xc)) && (*(int *)(local_c + 0x10) != 0)) {
    *(uint *)(unaff_EDI + 8) = (uint)*(ushort *)(*(int *)(local_c + 0x10) + 0x88);
    return;
  }
  *(undefined4 *)(unaff_EDI + 8) = 0;
  return;
}

