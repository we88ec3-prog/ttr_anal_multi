
void FUN_0078f410(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int in_EAX;
  int in_EDX;
  
  iVar2 = *(int *)(in_EAX + 8);
  if (iVar2 < *(int *)(param_1 + 8)) {
    uVar1 = *(undefined4 *)(in_EAX + 4);
    uVar3 = *(undefined4 *)(in_EAX + 0xc);
    *(undefined4 *)(in_EAX + 4) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(in_EAX + 8) = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(in_EAX + 0xc) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(param_1 + 4) = uVar1;
    *(int *)(param_1 + 8) = iVar2;
    *(undefined4 *)(param_1 + 0xc) = uVar3;
  }
  iVar2 = *(int *)(in_EDX + 8);
  if (iVar2 < *(int *)(in_EAX + 8)) {
    uVar1 = *(undefined4 *)(in_EDX + 4);
    uVar3 = *(undefined4 *)(in_EDX + 0xc);
    *(undefined4 *)(in_EDX + 4) = *(undefined4 *)(in_EAX + 4);
    *(undefined4 *)(in_EDX + 8) = *(undefined4 *)(in_EAX + 8);
    *(undefined4 *)(in_EDX + 0xc) = *(undefined4 *)(in_EAX + 0xc);
    *(undefined4 *)(in_EAX + 4) = uVar1;
    *(int *)(in_EAX + 8) = iVar2;
    *(undefined4 *)(in_EAX + 0xc) = uVar3;
  }
  iVar2 = *(int *)(in_EAX + 8);
  if (iVar2 < *(int *)(param_1 + 8)) {
    uVar1 = *(undefined4 *)(in_EAX + 4);
    uVar3 = *(undefined4 *)(in_EAX + 0xc);
    *(undefined4 *)(in_EAX + 4) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(in_EAX + 8) = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(in_EAX + 0xc) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(param_1 + 4) = uVar1;
    *(int *)(param_1 + 8) = iVar2;
    *(undefined4 *)(param_1 + 0xc) = uVar3;
  }
  return;
}

