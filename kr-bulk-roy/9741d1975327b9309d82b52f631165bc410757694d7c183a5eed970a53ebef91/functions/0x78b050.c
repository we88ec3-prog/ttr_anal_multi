
void FUN_0078b050(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int in_ECX;
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = in_ECX;
  while( true ) {
    iVar2 = iVar1 * 2 + 2;
    if (param_2 <= iVar2) break;
    if (*(int *)(iVar2 * 0x60 + 0x14 + param_1) < *(int *)(iVar2 * 0x60 + -0x4c + param_1)) {
      iVar2 = iVar1 * 2 + 1;
    }
    iVar3 = iVar2 * 0x60 + param_1;
    iVar1 = iVar1 * 0x60 + param_1;
    FUN_00788f50();
    *(undefined4 *)(iVar1 + 0x50) = *(undefined4 *)(iVar3 + 0x50);
    *(undefined4 *)(iVar1 + 0x54) = *(undefined4 *)(iVar3 + 0x54);
    *(undefined4 *)(iVar1 + 0x58) = *(undefined4 *)(iVar3 + 0x58);
    *(undefined4 *)(iVar1 + 0x5c) = *(undefined4 *)(iVar3 + 0x5c);
    iVar1 = iVar2;
  }
  if (iVar2 == param_2) {
    iVar2 = param_2 * 0x60 + -0x60 + param_1;
    iVar1 = iVar1 * 0x60 + param_1;
    FUN_00788f50();
    *(undefined4 *)(iVar1 + 0x50) = *(undefined4 *)(iVar2 + 0x50);
    *(undefined4 *)(iVar1 + 0x54) = *(undefined4 *)(iVar2 + 0x54);
    *(undefined4 *)(iVar1 + 0x58) = *(undefined4 *)(iVar2 + 0x58);
    *(undefined4 *)(iVar1 + 0x5c) = *(undefined4 *)(iVar2 + 0x5c);
  }
  FUN_0078d620(param_1,in_ECX,param_3,param_4);
  return;
}

