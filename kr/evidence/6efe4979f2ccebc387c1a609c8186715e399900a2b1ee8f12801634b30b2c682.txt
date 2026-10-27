
void FUN_0066fed0(int param_1)

{
  int in_ECX;
  int iVar1;
  
  if (*(int *)(param_1 + 0x10) == 0x578) {
    iVar1 = *(int *)(param_1 + 8);
    if (iVar1 == *(int *)(*(int *)(in_ECX + 0x100) + 0x20)) {
      iVar1 = *(int *)(DAT_00fe1aa0 + 0x18) + -1;
      if (-1 < iVar1) {
        FUN_00508970(iVar1);
        return;
      }
    }
    else if (iVar1 == *(int *)(*(int *)(in_ECX + 0x104) + 0x20)) {
      iVar1 = *(int *)(DAT_00fe1aa0 + 0x18) + 1;
      if (iVar1 < *(int *)(DAT_00fe1aa0 + 0x1c)) {
        FUN_00508970(iVar1);
        return;
      }
    }
    else {
      if (iVar1 == *(int *)(*(int *)(in_ECX + 0x108) + 0x20)) {
        FUN_0066fcb0();
        return;
      }
      if (iVar1 == *(int *)(*(int *)(in_ECX + 0x10c) + 0x20)) {
        FUN_0066fd30();
        return;
      }
      if (iVar1 == *(int *)(*(int *)(in_ECX + 0x110) + 0x20)) {
        FUN_0066fde0();
      }
    }
  }
  return;
}

