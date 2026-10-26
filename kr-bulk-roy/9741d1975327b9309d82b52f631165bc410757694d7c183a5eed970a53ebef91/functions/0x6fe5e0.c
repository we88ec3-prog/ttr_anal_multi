
void FUN_006fe5e0(int param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    iVar1 = FUN_006fe1c0(0xffffffff);
    if (iVar1 != 0) {
      return;
    }
  }
  else {
    *(undefined1 *)(param_1 + 6) = 0;
    if (*(char *)(*(int *)(*(undefined4 **)(param_1 + 0x14))[1] + 6) == '\0') {
      *(undefined4 *)(param_1 + 0xc) = **(undefined4 **)(param_1 + 0x14);
    }
    else {
      iVar1 = FUN_006fe4c0(param_1);
      if (iVar1 != 0) {
        *(undefined4 *)(param_1 + 8) = *(undefined4 *)(*(int *)(param_1 + 0x14) + 8);
      }
    }
  }
  FUN_006fc550(param_1,(*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x28)) / 0x18);
  return;
}

