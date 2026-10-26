
undefined4 FUN_004dfb60(void)

{
  int in_EAX;
  int unaff_ESI;
  int local_c;
  int local_8;
  
  local_8 = in_EAX;
  FUN_008438c0(&local_8);
  if ((local_c != *(int *)(unaff_ESI + 0x1c)) && (*(int *)(local_c + 0x10) != 0)) {
    local_c = *(int *)(*(int *)(local_c + 0x10) + 4);
    FUN_0082ef00(&local_c);
    if (local_8 == *(int *)(unaff_ESI + 0xc)) {
      return 0;
    }
    return *(undefined4 *)(local_8 + 0x10);
  }
  return 0;
}

