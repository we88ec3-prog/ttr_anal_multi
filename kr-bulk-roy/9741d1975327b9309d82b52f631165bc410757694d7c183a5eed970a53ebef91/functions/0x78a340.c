
void FUN_0078a340(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int local_10;
  int local_c;
  
  iVar1 = param_2 - param_1;
  do {
    iVar1 = iVar1 >> 4;
    if (iVar1 < 0x21) {
LAB_0078a3d9:
      if (1 < iVar1) {
        FUN_0078d9d0(param_2,param_4);
      }
      return;
    }
    if (param_3 < 1) {
      if (0x20 < iVar1) {
        if (0x10 < (int)(param_2 - param_1 & 0xfffffff0U)) {
          FUN_0078d840(param_2,param_4);
        }
        FUN_0078d940(param_4);
        return;
      }
      goto LAB_0078a3d9;
    }
    FUN_0078b120(&local_10,param_1,param_2,param_4);
    param_3 = param_3 / 2 + (param_3 / 2) / 2;
    if ((int)(local_10 - param_1 & 0xfffffff0U) < (int)(param_2 - local_c & 0xfffffff0U)) {
      FUN_0078a340(param_1,local_10,param_3,param_4);
      param_1 = local_c;
    }
    else {
      FUN_0078a340(local_c,param_2,param_3,param_4);
      param_2 = local_10;
    }
    iVar1 = param_2 - param_1;
  } while( true );
}

