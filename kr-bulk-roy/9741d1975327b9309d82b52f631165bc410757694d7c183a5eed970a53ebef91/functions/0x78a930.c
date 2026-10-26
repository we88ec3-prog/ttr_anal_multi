
void FUN_0078a930(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int local_10;
  int local_c;
  
  iVar1 = param_2 - param_1;
  do {
    iVar1 = iVar1 / 0x44;
    if (iVar1 < 0x21) {
LAB_0078aa11:
      if (1 < iVar1) {
        FUN_0078ebc0(param_1,param_2,param_4);
      }
      return;
    }
    if (param_3 < 1) {
      if (0x20 < iVar1) {
        if (1 < (param_2 - param_1) / 0x44) {
          FUN_0078ea50(param_1,param_4);
        }
        FUN_0078eac0(param_4);
        return;
      }
      goto LAB_0078aa11;
    }
    FUN_0078c380(&local_10,param_1,param_2,param_4);
    param_3 = param_3 / 2 + (param_3 / 2) / 2;
    if ((local_10 - param_1) / 0x44 < (param_2 - local_c) / 0x44) {
      FUN_0078a930(param_1,local_10,param_3,param_4);
      param_1 = local_c;
    }
    else {
      FUN_0078a930(local_c,param_2,param_3,param_4);
      param_2 = local_10;
    }
    iVar1 = param_2 - param_1;
  } while( true );
}

