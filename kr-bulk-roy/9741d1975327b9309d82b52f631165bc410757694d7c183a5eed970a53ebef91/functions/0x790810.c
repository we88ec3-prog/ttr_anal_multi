
void FUN_00790810(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  int in_ECX;
  
  while (param_1 < in_EAX) {
    iVar3 = (in_EAX + -1) / 2;
    iVar1 = in_ECX + iVar3 * 0x3c;
    if (*(int *)(param_2 + 0x14) <= *(int *)(in_ECX + 0x14 + iVar3 * 0x3c)) break;
    iVar2 = in_ECX + in_EAX * 0x3c;
    if ((undefined4 *)(iVar2 + 4) != (undefined4 *)(iVar1 + 4)) {
      *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar1 + 0x10);
      *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(iVar1 + 4);
      *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar1 + 8);
      *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar1 + 0xc);
    }
    *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar1 + 0x14);
    *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(iVar1 + 0x18);
    if ((undefined4 *)(iVar2 + 0x1c) != (undefined4 *)(iVar1 + 0x1c)) {
      *(undefined4 *)(iVar2 + 0x28) = *(undefined4 *)(iVar1 + 0x28);
      *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar1 + 0x1c);
      *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(iVar1 + 0x20);
      *(undefined4 *)(iVar2 + 0x24) = *(undefined4 *)(iVar1 + 0x24);
    }
    in_EAX = iVar3;
    if ((undefined4 *)(iVar2 + 0x2c) != (undefined4 *)(iVar1 + 0x2c)) {
      *(undefined4 *)(iVar2 + 0x38) = *(undefined4 *)(iVar1 + 0x38);
      *(undefined4 *)(iVar2 + 0x2c) = *(undefined4 *)(iVar1 + 0x2c);
      *(undefined4 *)(iVar2 + 0x30) = *(undefined4 *)(iVar1 + 0x30);
      *(undefined4 *)(iVar2 + 0x34) = *(undefined4 *)(iVar1 + 0x34);
    }
  }
  FUN_00789f20();
  return;
}

