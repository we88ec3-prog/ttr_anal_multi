
void FUN_00790700(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  while (param_2 < in_ECX) {
    iVar3 = (in_ECX + -1) / 2;
    iVar1 = param_1 + iVar3 * 0x1c;
    if (*(int *)(param_3 + 0x14) <= *(int *)(param_1 + 0x14 + iVar3 * 0x1c)) break;
    iVar2 = param_1 + in_ECX * 0x1c;
    if ((undefined4 *)(iVar2 + 4) != (undefined4 *)(iVar1 + 4)) {
      *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar1 + 0x10);
      *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(iVar1 + 4);
      *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar1 + 8);
      *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar1 + 0xc);
    }
    *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar1 + 0x14);
    *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(iVar1 + 0x18);
    in_ECX = iVar3;
  }
  param_1 = param_1 + in_ECX * 0x1c;
  if ((undefined4 *)(param_1 + 4) != (undefined4 *)(param_3 + 4)) {
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_3 + 0x10);
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_3 + 4);
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_3 + 8);
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_3 + 0xc);
  }
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_3 + 0x14);
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_3 + 0x18);
  return;
}

