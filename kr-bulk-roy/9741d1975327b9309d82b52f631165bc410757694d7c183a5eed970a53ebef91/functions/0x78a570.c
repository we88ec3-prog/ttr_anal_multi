
void FUN_0078a570(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int local_10;
  int local_c;
  
  iVar1 = param_2 - param_1;
  do {
    iVar1 = iVar1 / 0x2c;
    if (iVar1 < 0x21) {
LAB_0078a651:
      if (1 < iVar1) {
        FUN_0078e0c0(param_2,param_4);
      }
      return;
    }
    if (param_3 < 1) {
      if (0x20 < iVar1) {
        if (1 < (param_2 - param_1) / 0x2c) {
          FUN_0078df00(param_4);
        }
        FUN_0078dfb0(param_4);
        return;
      }
      goto LAB_0078a651;
    }
    FUN_0078baa0(&local_10,param_1,param_2,param_4);
    param_3 = param_3 / 2 + (param_3 / 2) / 2;
    if ((local_10 - param_1) / 0x2c < (param_2 - local_c) / 0x2c) {
      FUN_0078a570(param_1,local_10,param_3,param_4);
      param_1 = local_c;
    }
    else {
      FUN_0078a570(local_c,param_2,param_3,param_4);
      param_2 = local_10;
    }
    iVar1 = param_2 - param_1;
  } while( true );
}

