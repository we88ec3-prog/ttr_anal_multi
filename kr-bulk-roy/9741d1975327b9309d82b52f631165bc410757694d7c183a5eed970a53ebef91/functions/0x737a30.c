
void FUN_00737a30(int param_1)

{
  int in_ECX;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x1c) != param_1) {
    *(int *)(unaff_ESI + 0x1c) = param_1;
    if (param_1 != -1) {
      *(undefined4 *)(unaff_ESI + 0x24) = 1;
      FUN_008438c0(&param_1);
      if (in_ECX != *(int *)(unaff_ESI + 0x10)) {
        *(undefined4 *)(unaff_ESI + 0x20) = *(undefined4 *)(in_ECX + 0x10);
        FUN_00737450();
        return;
      }
    }
    *(undefined4 *)(unaff_ESI + 0x20) = 0;
    *(undefined4 *)(unaff_ESI + 0x24) = 0;
    FUN_00737450();
  }
  return;
}

