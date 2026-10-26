
undefined4
FUN_006eb240(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            int *param_6)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  
  if ((int)param_6 < -0x22222222) {
    if (param_6 == (int *)0xdddddddd) {
      return 0x3e6;
    }
    if ((int)param_6 < -0x33333333) {
      if (param_6 == (int *)0xcccccccc) {
        return 0x3e6;
      }
      if (param_6 == (int *)0xabababab) {
        return 0x3e6;
      }
      bVar3 = param_6 == (int *)0xbaadf00d;
    }
    else {
      bVar3 = param_6 == (int *)0xcdcdcdcd;
    }
  }
  else {
    if (param_6 == (int *)0xfdfdfdfd) {
      return 0x3e6;
    }
    if (param_6 == (int *)0xfeeefeee) {
      return 0x3e6;
    }
    bVar3 = param_6 == (int *)0x0;
  }
  if (bVar3) {
    return 0x3e6;
  }
  param_6[2] = param_1;
  if ((param_2 == 2) && (iVar1 = (**(code **)(*param_6 + 0x2c))(param_6), iVar1 != 0)) {
    FID_conflict__wprintf("Error from CFramework::OnDestroyWindow: %s\n",param_6 + 0x10);
  }
  uVar2 = (**(code **)(*param_6 + 0x14))(param_6,param_1,param_2,param_3,param_4,param_5);
  return uVar2;
}

