
void FUN_00790100(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  int unaff_EDI;
  
  while (param_1 < in_EAX) {
    iVar3 = (in_EAX + -1) / 2;
    iVar1 = unaff_EDI + iVar3 * 0x18;
    if (*(int *)(param_2 + 8) <= *(int *)(unaff_EDI + 8 + iVar3 * 0x18)) break;
    iVar2 = unaff_EDI + in_EAX * 0x18;
    *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(iVar1 + 4);
    *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar1 + 8);
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar1 + 0xc);
    *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar1 + 0x10);
    *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar1 + 0x14);
    in_EAX = iVar3;
  }
  iVar1 = unaff_EDI + in_EAX * 0x18;
  *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
  *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(param_2 + 0x14);
  return;
}

