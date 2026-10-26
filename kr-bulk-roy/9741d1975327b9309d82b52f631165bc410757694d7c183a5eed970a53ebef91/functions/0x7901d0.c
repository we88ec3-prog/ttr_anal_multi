
void FUN_007901d0(int param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  int unaff_EDI;
  
  while (param_2 < in_EAX) {
    iVar1 = (in_EAX + -1) / 2;
    iVar2 = iVar1 * 0x2c;
    iVar3 = iVar2 + param_1;
    if (*(int *)(unaff_EDI + 8) <= *(int *)(iVar2 + 8 + param_1)) break;
    *(undefined4 *)(in_EAX * 0x2c + 4 + param_1) = *(undefined4 *)(iVar3 + 4);
    iVar2 = in_EAX * 0x2c + param_1;
    *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar3 + 8);
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar3 + 0xc);
    *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar3 + 0x10);
    *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar3 + 0x14);
    *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(iVar3 + 0x18);
    *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar3 + 0x1c);
    *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(iVar3 + 0x20);
    *(undefined4 *)(iVar2 + 0x24) = *(undefined4 *)(iVar3 + 0x24);
    *(undefined4 *)(iVar2 + 0x28) = *(undefined4 *)(iVar3 + 0x28);
    in_EAX = iVar1;
  }
  *(undefined4 *)(in_EAX * 0x2c + 4 + param_1) = *(undefined4 *)(unaff_EDI + 4);
  param_1 = in_EAX * 0x2c + param_1;
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(unaff_EDI + 8);
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(unaff_EDI + 0xc);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(unaff_EDI + 0x10);
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(unaff_EDI + 0x14);
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(unaff_EDI + 0x18);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(unaff_EDI + 0x1c);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(unaff_EDI + 0x20);
  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(unaff_EDI + 0x24);
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(unaff_EDI + 0x28);
  return;
}

