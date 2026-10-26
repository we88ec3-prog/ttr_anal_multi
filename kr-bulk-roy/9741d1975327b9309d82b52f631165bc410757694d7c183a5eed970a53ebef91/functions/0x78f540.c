
void FUN_0078f540(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int in_EAX;
  int in_EDX;
  
  iVar4 = *(int *)(in_EAX + 8);
  if (iVar4 < *(int *)(param_1 + 8)) {
    uVar1 = *(undefined4 *)(in_EAX + 4);
    uVar2 = *(undefined4 *)(in_EAX + 0x10);
    uVar3 = *(undefined4 *)(in_EAX + 0x14);
    *(undefined4 *)(in_EAX + 4) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(in_EAX + 8) = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(in_EAX + 0xc) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(in_EAX + 0x10) = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)(in_EAX + 0x14) = *(undefined4 *)(param_1 + 0x14);
    *(int *)(param_1 + 8) = iVar4;
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 4) = uVar1;
    *(undefined4 *)(param_1 + 0x10) = uVar2;
    *(undefined4 *)(param_1 + 0x14) = uVar3;
  }
  iVar4 = *(int *)(in_EDX + 8);
  if (iVar4 < *(int *)(in_EAX + 8)) {
    uVar1 = *(undefined4 *)(in_EDX + 4);
    uVar2 = *(undefined4 *)(in_EDX + 0x10);
    uVar3 = *(undefined4 *)(in_EDX + 0x14);
    *(undefined4 *)(in_EDX + 4) = *(undefined4 *)(in_EAX + 4);
    *(undefined4 *)(in_EDX + 8) = *(undefined4 *)(in_EAX + 8);
    *(undefined4 *)(in_EDX + 0xc) = *(undefined4 *)(in_EAX + 0xc);
    *(undefined4 *)(in_EDX + 0x10) = *(undefined4 *)(in_EAX + 0x10);
    *(undefined4 *)(in_EDX + 0x14) = *(undefined4 *)(in_EAX + 0x14);
    *(int *)(in_EAX + 8) = iVar4;
    *(undefined4 *)(in_EAX + 0xc) = 0;
    *(undefined4 *)(in_EAX + 4) = uVar1;
    *(undefined4 *)(in_EAX + 0x10) = uVar2;
    *(undefined4 *)(in_EAX + 0x14) = uVar3;
  }
  iVar4 = *(int *)(in_EAX + 8);
  if (iVar4 < *(int *)(param_1 + 8)) {
    uVar1 = *(undefined4 *)(in_EAX + 4);
    uVar2 = *(undefined4 *)(in_EAX + 0x10);
    uVar3 = *(undefined4 *)(in_EAX + 0x14);
    *(undefined4 *)(in_EAX + 4) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(in_EAX + 8) = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(in_EAX + 0xc) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(in_EAX + 0x10) = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)(in_EAX + 0x14) = *(undefined4 *)(param_1 + 0x14);
    *(int *)(param_1 + 8) = iVar4;
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 4) = uVar1;
    *(undefined4 *)(param_1 + 0x10) = uVar2;
    *(undefined4 *)(param_1 + 0x14) = uVar3;
  }
  return;
}

