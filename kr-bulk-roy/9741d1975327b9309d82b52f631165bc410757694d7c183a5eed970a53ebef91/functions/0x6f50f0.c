
undefined4 * FUN_006f50f0(void)

{
  undefined4 *puVar1;
  int iVar2;
  int in_EAX;
  int in_ECX;
  
  if (in_EAX < 1) {
    if (-10000 < in_EAX) {
      return (undefined4 *)(in_EAX * 0x10 + *(int *)(in_ECX + 8));
    }
    if (in_EAX == -0x2712) {
      return (undefined4 *)(in_ECX + 0x48);
    }
    if (in_EAX == -0x2711) {
      *(undefined4 *)(in_ECX + 0x58) =
           *(undefined4 *)(**(int **)(*(int *)(in_ECX + 0x14) + 4) + 0xc);
      *(undefined4 *)(in_ECX + 0x60) = 5;
      return (undefined4 *)(in_ECX + 0x58);
    }
    if (in_EAX == -10000) {
      return (undefined4 *)(*(int *)(in_ECX + 0x10) + 0x60);
    }
    iVar2 = **(int **)(*(int *)(in_ECX + 0x14) + 4);
    if (-0x2712 - in_EAX <= (int)(uint)*(byte *)(iVar2 + 7)) {
      return (undefined4 *)(iVar2 + 8 + (-0x2712 - in_EAX) * 0x10);
    }
  }
  else {
    puVar1 = (undefined4 *)(*(int *)(in_ECX + 0xc) + -0x10 + in_EAX * 0x10);
    if (puVar1 < *(undefined4 **)(in_ECX + 8)) {
      return puVar1;
    }
  }
  return &DAT_00c0bfc8;
}

