
void FUN_0078e220(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (param_2 - in_ECX) / 0x18;
  if (0x28 < iVar1) {
    iVar1 = iVar1 + 1;
    iVar1 = (int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3;
    FUN_0078f8b0();
    FUN_0078f8b0(param_1 + iVar1 * -0x18,param_3);
    FUN_0078f8b0(param_2 + iVar1 * -0x30,param_3);
    FUN_0078f8b0(iVar1 * 0x18 + in_ECX,param_3);
    return;
  }
  FUN_0078f8b0();
  return;
}

