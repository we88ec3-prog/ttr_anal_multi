
void FUN_007358b0(undefined4 param_1)

{
  int unaff_ESI;
  undefined4 *unaff_EDI;
  int local_c;
  undefined4 local_8;
  
  *unaff_EDI = *(undefined4 *)(unaff_ESI + 0x20);
  local_8 = param_1;
  FUN_00736180(&local_8);
  if ((local_c != *(int *)(unaff_ESI + 0x10)) && (local_c != -0x10)) {
    *(undefined4 *)(unaff_ESI + 0x20) = param_1;
    return;
  }
  *(undefined4 *)(unaff_ESI + 0x20) = *(undefined4 *)(unaff_ESI + 0x1c);
  return;
}

