
void FUN_0078f1b0(int param_1,int param_2,undefined4 param_3)

{
  int in_EAX;
  int iVar1;
  
  iVar1 = (param_2 - in_EAX) / 0x3c;
  if (0x28 < iVar1) {
    iVar1 = iVar1 + 1;
    iVar1 = (int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3;
    FUN_0078ff90(iVar1 * 0x78 + in_EAX,param_3);
    FUN_0078ff90(iVar1 * 0x3c + param_1,param_3);
    FUN_0078ff90(param_2,param_3);
    FUN_0078ff90(param_2 + iVar1 * -0x3c,param_3);
    return;
  }
  FUN_0078ff90(param_2,param_3);
  return;
}

