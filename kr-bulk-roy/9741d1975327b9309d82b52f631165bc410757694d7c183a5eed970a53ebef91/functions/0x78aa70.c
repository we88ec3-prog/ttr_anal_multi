
void FUN_0078aa70(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int local_10;
  int local_c;
  
  iVar1 = param_2 - param_1;
  do {
    iVar1 = iVar1 / 0x1c;
    if (iVar1 < 0x21) {
LAB_0078ab5d:
      if (1 < iVar1) {
        FUN_0078f060(param_1,param_2,param_4);
      }
      return;
    }
    if (param_3 < 1) {
      if (0x20 < iVar1) {
        if (1 < (param_2 - param_1) / 0x1c) {
          FUN_0078eea0(param_1,param_4);
        }
        FUN_0078ef50(param_4);
        return;
      }
      goto LAB_0078ab5d;
    }
    FUN_0078ce00(&local_10,param_1,param_2,param_4);
    param_3 = param_3 / 2 + (param_3 / 2) / 2;
    if ((local_10 - param_1) / 0x1c < (param_2 - local_c) / 0x1c) {
      FUN_0078aa70(param_1,local_10,param_3,param_4);
      param_1 = local_c;
    }
    else {
      FUN_0078aa70(local_c,param_2,param_3,param_4);
      param_2 = local_10;
    }
    iVar1 = param_2 - param_1;
  } while( true );
}

