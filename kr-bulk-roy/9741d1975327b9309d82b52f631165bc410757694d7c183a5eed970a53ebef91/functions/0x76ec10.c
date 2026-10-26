
void FUN_0076ec10(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *in_EAX;
  int iVar6;
  int in_EDX;
  int iVar7;
  
  iVar1 = *(int *)(in_EDX + 0x10);
  iVar7 = *(int *)(in_EDX + 0x60);
  iVar2 = *(int *)(iVar7 + 0xc);
  iVar6 = *(int *)(iVar7 + 0x14);
  iVar3 = *(int *)(in_EDX + 8);
  iVar4 = *(int *)(in_EDX + 0xc);
  iVar5 = *(int *)(in_EDX + 0x14);
  switch(*(undefined4 *)(param_1 + 0x1c)) {
  case 0xc9:
    iVar7 = *(int *)(param_1 + 0xc);
    *in_EAX = iVar7;
    in_EAX[2] = (iVar7 - iVar3) + iVar1;
    iVar1 = *(int *)(param_1 + 0x10);
    in_EAX[1] = iVar1;
    in_EAX[3] = (iVar1 - iVar4) + iVar5;
    return;
  case 0xca:
    iVar7 = (*(int *)(param_1 + 0x14) - *(int *)(iVar7 + 8)) + *(int *)(iVar7 + 0x10);
    in_EAX[2] = iVar7;
    *in_EAX = (iVar7 - iVar1) + iVar3;
    iVar1 = *(int *)(param_1 + 0x10);
    in_EAX[1] = iVar1;
    in_EAX[3] = (iVar1 - iVar4) + iVar5;
    return;
  case 0xcb:
    iVar7 = *(int *)(param_1 + 0xc);
    *in_EAX = iVar7;
    in_EAX[2] = (iVar7 - iVar3) + iVar1;
    iVar6 = (*(int *)(param_1 + 0x18) - iVar2) + iVar6;
    in_EAX[3] = iVar6;
    in_EAX[1] = (iVar6 - iVar5) + iVar4;
    return;
  case 0xcc:
    iVar7 = (*(int *)(param_1 + 0x14) - *(int *)(iVar7 + 8)) + *(int *)(iVar7 + 0x10);
    in_EAX[2] = iVar7;
    *in_EAX = (iVar7 - iVar1) + iVar3;
    iVar6 = (*(int *)(param_1 + 0x18) - iVar2) + iVar6;
    in_EAX[3] = iVar6;
    in_EAX[1] = (iVar6 - iVar5) + iVar4;
    return;
  default:
    *in_EAX = iVar3;
    in_EAX[1] = iVar4;
    in_EAX[2] = iVar1;
    in_EAX[3] = iVar5;
    return;
  }
}

