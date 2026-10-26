
int FUN_006eaea0(int param_1,int param_2,int *param_3)

{
  code *pcVar1;
  int iVar2;
  bool bVar3;
  
  if ((int)param_3 < -0x22222222) {
    if (param_3 == (int *)0xdddddddd) {
      return -0x7fffbffb;
    }
    if ((int)param_3 < -0x33333333) {
      if (param_3 == (int *)0xcccccccc) {
        return -0x7fffbffb;
      }
      if (param_3 == (int *)0xabababab) {
        return -0x7fffbffb;
      }
      bVar3 = param_3 == (int *)0xbaadf00d;
    }
    else {
      bVar3 = param_3 == (int *)0xcdcdcdcd;
    }
  }
  else {
    if (param_3 == (int *)0xfdfdfdfd) {
      return -0x7fffbffb;
    }
    if (param_3 == (int *)0xfeeefeee) {
      return -0x7fffbffb;
    }
    bVar3 = param_3 == (int *)0x0;
  }
  if (bVar3) {
    return -0x7fffbffb;
  }
  param_3[4] = param_1;
  pcVar1 = *(code **)(*param_3 + 4);
  param_3[5] = param_2;
  iVar2 = (*pcVar1)(param_3);
  if (iVar2 != 0) {
    FID_conflict__wprintf("Error from CFramework::OnCreateDevice: %s\n",param_3 + 0x10);
  }
  return iVar2;
}

