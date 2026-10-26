
void FUN_006eb140(int param_1,undefined4 param_2,int *param_3)

{
  code *pcVar1;
  int iVar2;
  
  if ((int)param_3 < -0x22222222) {
    if (param_3 == (int *)0xdddddddd) {
      return;
    }
    if ((int)param_3 < -0x33333333) {
      if (param_3 == (int *)0xcccccccc) {
        return;
      }
      if (param_3 == (int *)0xabababab) {
        return;
      }
      if (param_3 == (int *)0xbaadf00d) {
        return;
      }
    }
    else if (param_3 == (int *)0xcdcdcdcd) {
      return;
    }
  }
  else {
    if (param_3 == (int *)0xfdfdfdfd) {
      return;
    }
    if (param_3 == (int *)0xfeeefeee) {
      return;
    }
    if (param_3 == (int *)0x0) {
      return;
    }
  }
  pcVar1 = *(code **)(*param_3 + 0x34);
  param_3[4] = param_1;
  iVar2 = (*pcVar1)(param_3,param_2);
  if (iVar2 != 0) {
    FID_conflict__wprintf("Error from CFramework::AnimateFrame: %s\n",param_3 + 0x10);
  }
  return;
}

