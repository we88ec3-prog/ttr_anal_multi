
void FUN_0078d620(int param_1,int param_2,int param_3)

{
  int in_ECX;
  int iVar1;
  int iVar2;
  int iVar3;
  
  while (param_2 < in_ECX) {
    iVar3 = (in_ECX + -1) / 2;
    iVar1 = iVar3 * 0x60;
    iVar2 = iVar1 + param_1;
    if (*(int *)(param_3 + 0x14) <= *(int *)(iVar1 + 0x14 + param_1)) break;
    iVar1 = in_ECX * 0x60 + param_1;
    FUN_00788f50();
    *(undefined4 *)(iVar1 + 0x50) = *(undefined4 *)(iVar2 + 0x50);
    *(undefined4 *)(iVar1 + 0x54) = *(undefined4 *)(iVar2 + 0x54);
    *(undefined4 *)(iVar1 + 0x58) = *(undefined4 *)(iVar2 + 0x58);
    *(undefined4 *)(iVar1 + 0x5c) = *(undefined4 *)(iVar2 + 0x5c);
    in_ECX = iVar3;
  }
  param_1 = in_ECX * 0x60 + param_1;
  FUN_00788f50();
  *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_3 + 0x50);
  *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_3 + 0x54);
  *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_3 + 0x58);
  *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(param_3 + 0x5c);
  return;
}

