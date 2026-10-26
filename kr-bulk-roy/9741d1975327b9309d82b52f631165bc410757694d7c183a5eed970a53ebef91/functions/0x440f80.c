
void FUN_00440f80(int param_1)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(param_1 + 0x10) == 0x579) {
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(*(int *)(in_ECX + 0xfc) + 0x20) == iVar1) {
      *(float *)(*(int *)(DAT_00fb1318 + 0xbfe8) + 0x24) =
           *(float *)(*(int *)(DAT_00fb1318 + 0xbfe8) + 0x24) - 3.0;
      FUN_006dd6f0();
      return;
    }
    if (*(int *)(*(int *)(in_ECX + 0x100) + 0x20) == iVar1) {
      *(float *)(*(int *)(DAT_00fb1318 + 0xbfe8) + 0x24) =
           *(float *)(*(int *)(DAT_00fb1318 + 0xbfe8) + 0x24) + 3.0;
      FUN_006dd6f0();
      return;
    }
    if (*(int *)(*(int *)(in_ECX + 0x104) + 0x20) == iVar1) {
      *(float *)(*(int *)(DAT_00fb1318 + 0xbfe8) + 0x18) =
           *(float *)(*(int *)(DAT_00fb1318 + 0xbfe8) + 0x18) - 0.2;
      return;
    }
    if (*(int *)(*(int *)(in_ECX + 0x108) + 0x20) == iVar1) {
      *(float *)(*(int *)(DAT_00fb1318 + 0xbfe8) + 0x18) =
           *(float *)(*(int *)(DAT_00fb1318 + 0xbfe8) + 0x18) + 0.2;
    }
  }
  else if ((*(int *)(param_1 + 0x10) == 0x641) &&
          (*(int *)(*(int *)(in_ECX + 0xf8) + 0x20) == *(int *)(param_1 + 8))) {
    FUN_00441060(in_ECX);
    return;
  }
  return;
}

