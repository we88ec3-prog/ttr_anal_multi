
void FUN_006eb040(int *param_1)

{
  int iVar1;
  
  if ((int)param_1 < -0x22222222) {
    if (param_1 == (int *)0xdddddddd) {
      return;
    }
    if ((int)param_1 < -0x33333333) {
      if (param_1 == (int *)0xcccccccc) {
        return;
      }
      if (param_1 == (int *)0xabababab) {
        return;
      }
      if (param_1 == (int *)0xbaadf00d) {
        return;
      }
    }
    else if (param_1 == (int *)0xcdcdcdcd) {
      return;
    }
  }
  else {
    if (param_1 == (int *)0xfdfdfdfd) {
      return;
    }
    if (param_1 == (int *)0xfeeefeee) {
      return;
    }
    if (param_1 == (int *)0x0) {
      return;
    }
  }
  iVar1 = (**(code **)(*param_1 + 0x10))(param_1);
  if (iVar1 != 0) {
    FID_conflict__wprintf("Error from CFramework::OnDestroyDevice: %s\n",param_1 + 0x10);
  }
  return;
}

