
undefined4 FUN_008462f0(undefined4 *param_1,undefined4 *param_2)

{
  int unaff_ESI;
  int local_c;
  undefined4 local_8;
  
  local_8 = 0xa2500000;
  FUN_0082ef00(&local_8);
  if ((local_c != *(int *)(unaff_ESI + 0x38)) && (*(int *)(local_c + 0x10) != 0)) {
    *param_1 = *(undefined4 *)(*(int *)(local_c + 0x10) + 0x34);
    *param_2 = *(undefined4 *)(unaff_ESI + 0x9c);
    return 1;
  }
  return 0;
}

