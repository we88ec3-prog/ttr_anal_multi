
void FUN_00840b70(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6)

{
  int iVar1;
  int local_c;
  int local_8;
  
  iVar1 = param_2 - param_1;
  do {
    iVar1 = iVar1 / 0x50;
    if (iVar1 < 0x21) {
LAB_00840c64:
      if (1 < iVar1) {
        FUN_008422a0(param_1,param_2,param_4,param_5,param_6);
      }
      return;
    }
    if (param_3 < 1) {
      if (0x20 < iVar1) {
        if (1 < (param_2 - param_1) / 0x50) {
          FUN_00841fc0(param_1,param_4,param_5,param_6);
        }
        FUN_00842210(param_1,param_2,param_4,param_5,param_6);
        return;
      }
      goto LAB_00840c64;
    }
    FUN_00841950(&local_c,param_1,param_2,param_4,param_5,param_6);
    param_3 = param_3 / 2 + (param_3 / 2) / 2;
    if ((local_c - param_1) / 0x50 < (param_2 - local_8) / 0x50) {
      FUN_00840b70(param_1,local_c,param_3,param_4,param_5,param_6);
      param_1 = local_8;
    }
    else {
      FUN_00840b70(local_8,param_2,param_3,param_4,param_5,param_6);
      param_2 = local_c;
    }
    iVar1 = param_2 - param_1;
  } while( true );
}

