
undefined4 FUN_00846220(void)

{
  int unaff_ESI;
  int local_c;
  undefined4 local_8;
  
  local_8 = 0xa2500000;
  FUN_0082ef00(&local_8);
  if ((local_c != *(int *)(unaff_ESI + 0x38)) && (*(int *)(local_c + 0x10) != 0)) {
    return *(undefined4 *)(*(int *)(local_c + 0x10) + 0x30);
  }
  return 0;
}

