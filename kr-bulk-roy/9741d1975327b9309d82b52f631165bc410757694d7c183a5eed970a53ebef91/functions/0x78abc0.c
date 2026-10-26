
void FUN_0078abc0(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int local_10;
  int local_c;
  
  iVar1 = param_2 - param_1;
  do {
    iVar1 = iVar1 / 0x3c;
    if (iVar1 < 0x21) {
LAB_0078acad:
      if (1 < iVar1) {
        FUN_0078f370(param_1,param_2,param_4);
      }
      return;
    }
    if (param_3 < 1) {
      if (0x20 < iVar1) {
        if (1 < (param_2 - param_1) / 0x3c) {
          FUN_0078f270(param_4);
        }
        FUN_0078f2e0(param_4);
        return;
      }
      goto LAB_0078acad;
    }
    FUN_0078cf80(&local_10,param_1,param_2,param_4);
    param_3 = param_3 / 2 + (param_3 / 2) / 2;
    if ((local_10 - param_1) / 0x3c < (param_2 - local_c) / 0x3c) {
      FUN_0078abc0(param_1,local_10,param_3,param_4);
      param_1 = local_c;
    }
    else {
      FUN_0078abc0(local_c,param_2,param_3,param_4);
      param_2 = local_10;
    }
    iVar1 = param_2 - param_1;
  } while( true );
}

