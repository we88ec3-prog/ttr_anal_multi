
void FUN_00841eb0(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int in_EAX;
  int iVar1;
  
  iVar1 = (param_2 - in_EAX) / 0x50;
  if (0x28 < iVar1) {
    iVar1 = iVar1 + 1;
    iVar1 = (int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3;
    FUN_00842600(iVar1 * 0xa0 + in_EAX,param_3,param_4,param_5);
    FUN_00842600(iVar1 * 0x50 + param_1,param_3,param_4,param_5);
    FUN_00842600(param_2,param_3,param_4,param_5);
    FUN_00842600(param_2 + iVar1 * -0x50,param_3,param_4,param_5);
    return;
  }
  FUN_00842600(param_2,param_3,param_4,param_5);
  return;
}

