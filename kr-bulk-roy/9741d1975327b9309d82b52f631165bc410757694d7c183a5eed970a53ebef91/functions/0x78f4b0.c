
void FUN_0078f4b0(int param_1)

{
  int in_EAX;
  int iVar1;
  int in_ECX;
  
  while( true ) {
    iVar1 = in_ECX * 2 + 2;
    if (in_EAX <= iVar1) break;
    if (*(int *)(param_1 + 8 + iVar1 * 0x10) < *(int *)(param_1 + -8 + iVar1 * 0x10)) {
      iVar1 = in_ECX * 2 + 1;
    }
    *(undefined4 *)(param_1 + 4 + in_ECX * 0x10) = *(undefined4 *)(param_1 + 4 + iVar1 * 0x10);
    *(undefined4 *)(param_1 + 8 + in_ECX * 0x10) = *(undefined4 *)(param_1 + 8 + iVar1 * 0x10);
    *(undefined4 *)(param_1 + 0xc + in_ECX * 0x10) = *(undefined4 *)(param_1 + 0xc + iVar1 * 0x10);
    in_ECX = iVar1;
  }
  if (iVar1 == in_EAX) {
    iVar1 = param_1 + -0x10 + in_EAX * 0x10;
    *(undefined4 *)(param_1 + 4 + in_ECX * 0x10) = *(undefined4 *)(param_1 + -0xc + in_EAX * 0x10);
    *(undefined4 *)(param_1 + 8 + in_ECX * 0x10) = *(undefined4 *)(iVar1 + 8);
    *(undefined4 *)(param_1 + 0xc + in_ECX * 0x10) = *(undefined4 *)(iVar1 + 0xc);
  }
  FUN_007900a0();
  return;
}

