
void FUN_008b8480(char param_1)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (param_1 == '\0') {
    iVar1 = *(int *)(in_EAX + 0x24);
    *(uint *)(in_EAX + 0x2c) = *(uint *)(in_EAX + 0x2c) & 0xffffffc0;
    *(uint *)(in_EAX + 0x30) = *(uint *)(in_EAX + 0x30) & 0xffffffc0;
    uVar3 = *(uint *)(in_EAX + 0x20) & 0xffffffc0;
    uVar4 = iVar1 + 0x3fU & 0xffffffc0;
    *(uint *)(in_EAX + 0x24) = uVar4;
    iVar2 = (*(int *)(in_EAX + 0x18) + 0x3f + *(uint *)(in_EAX + 0x20) & 0xffffffc0) - uVar3;
    *(uint *)(in_EAX + 0x20) = uVar3;
    *(uint *)(in_EAX + 0x1c) = uVar4 - (iVar1 - *(int *)(in_EAX + 0x1c) & 0xffffffc0U);
  }
  else {
    uVar4 = *(uint *)(in_EAX + 0x30);
    *(uint *)(in_EAX + 0x20) = *(uint *)(in_EAX + 0x20) & 0xffffffc0;
    *(uint *)(in_EAX + 0x24) = *(int *)(in_EAX + 0x24) + 0x3fU & 0xffffffc0;
    uVar3 = *(uint *)(in_EAX + 0x2c) & 0xffffffc0;
    uVar5 = uVar4 & 0xffffffc0;
    iVar2 = (*(int *)(in_EAX + 0x18) + 0x3f + *(uint *)(in_EAX + 0x2c) & 0xffffffc0) - uVar3;
    *(uint *)(in_EAX + 0x2c) = uVar3;
    *(uint *)(in_EAX + 0x30) = uVar5;
    *(uint *)(in_EAX + 0x1c) = (uVar4 + 0x3f + *(int *)(in_EAX + 0x1c) & 0xffffffc0) - uVar5;
  }
  *(int *)(in_EAX + 0x18) = iVar2;
  *(uint *)(in_EAX + 0x28) = *(int *)(in_EAX + 0x28) + 0x20U & 0xffffffc0;
  *(uint *)(in_EAX + 0x34) = *(int *)(in_EAX + 0x34) + 0x20U & 0xffffffc0;
  return;
}

