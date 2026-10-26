
void FUN_00725490(int param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  
  iVar1 = param_2 - in_EAX >> 3;
  if (iVar1 < 0x29) {
    FUN_00727040(param_2);
    return;
  }
  iVar1 = iVar1 + 1;
  iVar1 = (int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3;
  FUN_00727040(iVar1 * 0x10 + in_EAX);
  FUN_00727040(iVar1 * 8 + param_1);
  FUN_00727040(param_2);
  FUN_00727040(param_2 + iVar1 * -8);
  return;
}

