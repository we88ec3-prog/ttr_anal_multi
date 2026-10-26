
void FUN_0078fe90(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  while( true ) {
    iVar3 = in_ECX * 2 + 2;
    if (param_2 <= iVar3) break;
    if (*(int *)(param_1 + 0x14 + iVar3 * 0x1c) < *(int *)(param_1 + -8 + iVar3 * 0x1c)) {
      iVar3 = in_ECX * 2 + 1;
    }
    iVar1 = param_1 + in_ECX * 0x1c;
    iVar2 = param_1 + iVar3 * 0x1c;
    if ((undefined4 *)(iVar1 + 4) != (undefined4 *)(iVar2 + 4)) {
      *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar2 + 0x10);
      *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(iVar2 + 4);
      *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar2 + 8);
      *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar2 + 0xc);
    }
    *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar2 + 0x14);
    *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(iVar2 + 0x18);
    in_ECX = iVar3;
  }
  if (iVar3 == param_2) {
    iVar1 = param_1 + -0x1c + param_2 * 0x1c;
    iVar3 = param_1 + in_ECX * 0x1c;
    if ((undefined4 *)(iVar3 + 4) != (undefined4 *)(iVar1 + 4)) {
      *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(iVar1 + 0x10);
      *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(iVar1 + 4);
      *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar1 + 8);
      *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar1 + 0xc);
    }
    *(undefined4 *)(iVar3 + 0x14) = *(undefined4 *)(iVar1 + 0x14);
    *(undefined4 *)(iVar3 + 0x18) = *(undefined4 *)(iVar1 + 0x18);
  }
  FUN_00790700(param_1);
  return;
}

