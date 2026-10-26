
void FUN_0078e990(int param_1,int param_2,undefined4 param_3)

{
  int in_EAX;
  int iVar1;
  
  iVar1 = (param_2 - in_EAX) / 0x44;
  if (0x28 < iVar1) {
    iVar1 = iVar1 + 1;
    iVar1 = (int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3;
    FUN_0078fc20(iVar1 * 0x88 + in_EAX,param_3);
    FUN_0078fc20(iVar1 * 0x44 + param_1,param_3);
    FUN_0078fc20(param_2,param_3);
    FUN_0078fc20(param_2 + iVar1 * -0x44,param_3);
    return;
  }
  FUN_0078fc20(param_2,param_3);
  return;
}

