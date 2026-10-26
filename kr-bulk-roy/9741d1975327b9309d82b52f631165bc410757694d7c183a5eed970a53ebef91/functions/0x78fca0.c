
void FUN_0078fca0(int param_1)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int in_ECX;
  int iVar3;
  
  while( true ) {
    iVar3 = in_ECX * 2 + 2;
    if (in_EAX <= iVar3) break;
    if (*(int *)(param_1 + 0x10 + iVar3 * 0x44) < *(int *)(param_1 + -0x34 + iVar3 * 0x44)) {
      iVar3 = in_ECX * 2 + 1;
    }
    iVar1 = param_1 + in_ECX * 0x44;
    iVar2 = param_1 + iVar3 * 0x44;
    *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(param_1 + 4 + iVar3 * 0x44);
    *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar2 + 8);
    *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar2 + 0xc);
    *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar2 + 0x10);
    *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar2 + 0x14);
    *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(iVar2 + 0x18);
    *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(iVar2 + 0x1c);
    *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(iVar2 + 0x20);
    *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(iVar2 + 0x24);
    *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(iVar2 + 0x28);
    *(undefined4 *)(iVar1 + 0x2c) = *(undefined4 *)(iVar2 + 0x2c);
    *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(iVar2 + 0x30);
    *(undefined4 *)(iVar1 + 0x34) = *(undefined4 *)(iVar2 + 0x34);
    *(undefined4 *)(iVar1 + 0x38) = *(undefined4 *)(iVar2 + 0x38);
    *(undefined4 *)(iVar1 + 0x3c) = *(undefined4 *)(iVar2 + 0x3c);
    *(undefined4 *)(iVar1 + 0x40) = *(undefined4 *)(iVar2 + 0x40);
    in_ECX = iVar3;
  }
  if (iVar3 == in_EAX) {
    iVar3 = param_1 + -0x44 + in_EAX * 0x44;
    param_1 = param_1 + in_ECX * 0x44;
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(iVar3 + 4);
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(iVar3 + 8);
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar3 + 0xc);
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(iVar3 + 0x10);
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(iVar3 + 0x14);
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(iVar3 + 0x18);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar3 + 0x1c);
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar3 + 0x20);
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(iVar3 + 0x24);
    *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(iVar3 + 0x28);
    *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(iVar3 + 0x2c);
    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(iVar3 + 0x30);
    *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(iVar3 + 0x34);
    *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(iVar3 + 0x38);
    *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(iVar3 + 0x3c);
    *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(iVar3 + 0x40);
  }
  FUN_00790570();
  return;
}

