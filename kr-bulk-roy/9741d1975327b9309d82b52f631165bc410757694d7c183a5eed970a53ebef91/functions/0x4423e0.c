
void FUN_004423e0(void)

{
  int unaff_EDI;
  undefined4 local_10;
  undefined4 local_c;
  
  if ((*(int *)(unaff_EDI + 0xf8) != 0) &&
     ((*(uint *)(*(int *)(unaff_EDI + 0xf8) + 0x28) >> 8 & 1) != 0)) {
    FUN_00443da0();
    FUN_00749970(local_c,local_10);
    FUN_00749920(*(undefined4 *)(unaff_EDI + 0xf8));
  }
  return;
}

