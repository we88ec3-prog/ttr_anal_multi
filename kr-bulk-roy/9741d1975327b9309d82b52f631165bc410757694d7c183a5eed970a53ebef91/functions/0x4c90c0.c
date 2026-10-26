
void FUN_004c90c0(int param_1)

{
  int iVar1;
  int unaff_ESI;
  undefined4 in_XMM0_Da;
  
  if (param_1 == 0) {
    if (*(int *)(unaff_ESI + 0x3a8) != 0) {
      *(undefined4 *)(unaff_ESI + 0x3a8) = 0;
    }
  }
  else if (*(int *)(unaff_ESI + 0x3a8) == 0) {
    *(undefined1 *)(unaff_ESI + 0x3a4) = *(undefined1 *)(unaff_ESI + 0xb0);
    if ((*(int *)(unaff_ESI + 0x370) != 0) && (*(int *)(unaff_ESI + 0x15c) != 0)) {
      iVar1 = *(int *)(*(int *)(unaff_ESI + 0x15c) + 4);
      FUN_00444a90(*(undefined1 *)(unaff_ESI + 0xb0));
      (**(code **)(iVar1 + 0xc))(in_XMM0_Da);
    }
    *(int *)(unaff_ESI + 0x3a8) = param_1;
    return;
  }
  return;
}

