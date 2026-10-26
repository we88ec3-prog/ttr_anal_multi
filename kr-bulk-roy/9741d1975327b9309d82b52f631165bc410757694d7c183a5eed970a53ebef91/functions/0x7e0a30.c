
void FUN_007e0a30(int param_1)

{
  int iVar1;
  int *piVar2;
  int local_8;
  
  piVar2 = (int *)(param_1 + 0xc);
  local_8 = 8;
  do {
    iVar1 = *piVar2;
    if (iVar1 != 0) {
      if (0xf < *(uint *)(iVar1 + 0x28)) {
        FUN_0089120c(*(undefined4 *)(iVar1 + 0x14));
      }
      *(undefined4 *)(iVar1 + 0x28) = 0xf;
      *(undefined4 *)(iVar1 + 0x24) = 0;
      *(undefined1 *)(iVar1 + 0x14) = 0;
      FUN_0089120c(iVar1);
      *piVar2 = 0;
    }
    piVar2 = piVar2 + 1;
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  if (*(int *)(param_1 + 0x34) != 0) {
    FUN_0089120c(*(int *)(param_1 + 0x34));
  }
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  return;
}

