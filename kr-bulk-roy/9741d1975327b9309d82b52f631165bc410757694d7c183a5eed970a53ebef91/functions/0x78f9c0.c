
void FUN_0078f9c0(int param_1)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  int in_ECX;
  
  while( true ) {
    iVar3 = in_ECX * 2 + 2;
    if (in_EAX <= iVar3) break;
    if (*(int *)(param_1 + 0x10 + iVar3 * 0x18) < *(int *)(param_1 + -8 + iVar3 * 0x18)) {
      iVar3 = in_ECX * 2 + 1;
    }
    iVar1 = param_1 + iVar3 * 0x18;
    iVar2 = param_1 + in_ECX * 0x18;
    *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(param_1 + 4 + iVar3 * 0x18);
    *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar1 + 8);
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar1 + 0xc);
    *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar1 + 0x10);
    *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar1 + 0x14);
    in_ECX = iVar3;
  }
  if (iVar3 == in_EAX) {
    iVar1 = param_1 + -0x18 + in_EAX * 0x18;
    iVar3 = param_1 + in_ECX * 0x18;
    *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(param_1 + -0x14 + in_EAX * 0x18);
    *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar1 + 8);
    *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar1 + 0xc);
    *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(iVar1 + 0x10);
    *(undefined4 *)(iVar3 + 0x14) = *(undefined4 *)(iVar1 + 0x14);
  }
  FUN_007902f0();
  return;
}

