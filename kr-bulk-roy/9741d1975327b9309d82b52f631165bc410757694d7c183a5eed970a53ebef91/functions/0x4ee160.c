
void FUN_004ee160(int param_1,int param_2,undefined4 param_3)

{
  int in_EAX;
  int iVar1;
  
  iVar1 = (param_2 - in_EAX) / 0xc;
  if (0x28 < iVar1) {
    iVar1 = iVar1 + 1;
    iVar1 = (int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3;
    FUN_004ee4e0(iVar1 * 0x18 + in_EAX,param_3);
    FUN_004ee4e0(iVar1 * 0xc + param_1,param_3);
    FUN_004ee4e0(param_2,param_3);
    FUN_004ee4e0(param_2 + iVar1 * -0xc,param_3);
    return;
  }
  FUN_004ee4e0(param_2,param_3);
  return;
}

