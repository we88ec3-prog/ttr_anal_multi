
void FUN_0078f8b0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int in_EAX;
  int in_EDX;
  
  iVar1 = *(int *)(in_EAX + 0x10);
  if (iVar1 < *(int *)(param_1 + 0x10)) {
    uVar2 = *(undefined4 *)(in_EAX + 8);
    uVar3 = *(undefined4 *)(in_EAX + 4);
    uVar4 = *(undefined4 *)(in_EAX + 0xc);
    uVar5 = *(undefined4 *)(in_EAX + 0x14);
    *(undefined4 *)(in_EAX + 4) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(in_EAX + 8) = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(in_EAX + 0xc) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(in_EAX + 0x10) = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)(in_EAX + 0x14) = *(undefined4 *)(param_1 + 0x14);
    *(undefined4 *)(param_1 + 4) = uVar3;
    *(undefined4 *)(param_1 + 8) = uVar2;
    *(int *)(param_1 + 0x10) = iVar1;
    *(undefined4 *)(param_1 + 0xc) = uVar4;
    *(undefined4 *)(param_1 + 0x14) = uVar5;
  }
  iVar1 = *(int *)(in_EDX + 0x10);
  if (iVar1 < *(int *)(in_EAX + 0x10)) {
    uVar2 = *(undefined4 *)(in_EDX + 0xc);
    uVar3 = *(undefined4 *)(in_EDX + 4);
    uVar4 = *(undefined4 *)(in_EDX + 8);
    uVar5 = *(undefined4 *)(in_EDX + 0x14);
    *(undefined4 *)(in_EDX + 4) = *(undefined4 *)(in_EAX + 4);
    *(undefined4 *)(in_EDX + 8) = *(undefined4 *)(in_EAX + 8);
    *(undefined4 *)(in_EDX + 0xc) = *(undefined4 *)(in_EAX + 0xc);
    *(undefined4 *)(in_EDX + 0x10) = *(undefined4 *)(in_EAX + 0x10);
    *(undefined4 *)(in_EDX + 0x14) = *(undefined4 *)(in_EAX + 0x14);
    *(undefined4 *)(in_EAX + 4) = uVar3;
    *(undefined4 *)(in_EAX + 8) = uVar4;
    *(undefined4 *)(in_EAX + 0xc) = uVar2;
    *(int *)(in_EAX + 0x10) = iVar1;
    *(undefined4 *)(in_EAX + 0x14) = uVar5;
  }
  iVar1 = *(int *)(in_EAX + 0x10);
  if (iVar1 < *(int *)(param_1 + 0x10)) {
    uVar2 = *(undefined4 *)(in_EAX + 0x14);
    uVar3 = *(undefined4 *)(in_EAX + 4);
    uVar4 = *(undefined4 *)(in_EAX + 8);
    uVar5 = *(undefined4 *)(in_EAX + 0xc);
    *(undefined4 *)(in_EAX + 4) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(in_EAX + 8) = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(in_EAX + 0xc) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(in_EAX + 0x10) = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)(in_EAX + 0x14) = *(undefined4 *)(param_1 + 0x14);
    *(undefined4 *)(param_1 + 4) = uVar3;
    *(undefined4 *)(param_1 + 8) = uVar4;
    *(undefined4 *)(param_1 + 0xc) = uVar5;
    *(int *)(param_1 + 0x10) = iVar1;
    *(undefined4 *)(param_1 + 0x14) = uVar2;
  }
  return;
}

