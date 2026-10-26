
void FUN_006eb0c0(int param_1,int *param_2)

{
  code *pcVar1;
  int iVar2;
  
  if ((int)param_2 < -0x22222222) {
    if (param_2 == (int *)0xdddddddd) {
      return;
    }
    if ((int)param_2 < -0x33333333) {
      if (param_2 == (int *)0xcccccccc) {
        return;
      }
      if (param_2 == (int *)0xabababab) {
        return;
      }
      if (param_2 == (int *)0xbaadf00d) {
        return;
      }
    }
    else if (param_2 == (int *)0xcdcdcdcd) {
      return;
    }
  }
  else {
    if (param_2 == (int *)0xfdfdfdfd) {
      return;
    }
    if (param_2 == (int *)0xfeeefeee) {
      return;
    }
    if (param_2 == (int *)0x0) {
      return;
    }
  }
  pcVar1 = *(code **)(*param_2 + 0x30);
  param_2[4] = param_1;
  iVar2 = (*pcVar1)(param_2);
  if (iVar2 != 0) {
    FID_conflict__wprintf("Error from CFramework::FrameMove: %s\n",param_2 + 0x10);
  }
  return;
}

