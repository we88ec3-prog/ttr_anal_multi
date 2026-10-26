
void FUN_006eb2e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  if ((int)param_4 < -0x22222222) {
    if (param_4 == (int *)0xdddddddd) {
      return;
    }
    if ((int)param_4 < -0x33333333) {
      if (param_4 == (int *)0xcccccccc) {
        return;
      }
      if (param_4 == (int *)0xabababab) {
        return;
      }
      if (param_4 == (int *)0xbaadf00d) {
        return;
      }
    }
    else if (param_4 == (int *)0xcdcdcdcd) {
      return;
    }
  }
  else {
    if (param_4 == (int *)0xfdfdfdfd) {
      return;
    }
    if (param_4 == (int *)0xfeeefeee) {
      return;
    }
    if (param_4 == (int *)0x0) {
      return;
    }
  }
  (**(code **)(*param_4 + 0x18))(param_4,param_1,param_2,param_3);
  return;
}

