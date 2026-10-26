
void FUN_0078fb20(int param_1)

{
  int in_EAX;
  int iVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  
  while( true ) {
    iVar1 = in_ECX * 2 + 2;
    if (in_EAX <= iVar1) break;
    if (*(int *)(param_1 + 0x10 + iVar1 * 0x30) < *(int *)(param_1 + -0x20 + iVar1 * 0x30)) {
      iVar1 = in_ECX * 2 + 1;
    }
    iVar3 = iVar1 * 0x30 + param_1;
    iVar2 = in_ECX * 0x30 + param_1;
    *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(iVar1 * 0x30 + 4 + param_1);
    *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar3 + 8);
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar3 + 0xc);
    *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar3 + 0x10);
    *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar3 + 0x14);
    *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(iVar3 + 0x18);
    *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar3 + 0x1c);
    *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(iVar3 + 0x20);
    *(undefined4 *)(iVar2 + 0x24) = *(undefined4 *)(iVar3 + 0x24);
    *(undefined4 *)(iVar2 + 0x28) = *(undefined4 *)(iVar3 + 0x28);
    *(undefined4 *)(iVar2 + 0x2c) = *(undefined4 *)(iVar3 + 0x2c);
    in_ECX = iVar1;
  }
  if (iVar1 == in_EAX) {
    iVar1 = param_1 + -0x30 + in_EAX * 0x30;
    iVar2 = in_ECX * 0x30 + param_1;
    *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(param_1 + -0x2c + in_EAX * 0x30);
    *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar1 + 8);
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar1 + 0xc);
    *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar1 + 0x10);
    *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar1 + 0x14);
    *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(iVar1 + 0x18);
    *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar1 + 0x1c);
    *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(iVar1 + 0x20);
    *(undefined4 *)(iVar2 + 0x24) = *(undefined4 *)(iVar1 + 0x24);
    *(undefined4 *)(iVar2 + 0x28) = *(undefined4 *)(iVar1 + 0x28);
    *(undefined4 *)(iVar2 + 0x2c) = *(undefined4 *)(iVar1 + 0x2c);
  }
  FUN_00790430();
  return;
}

