
void FUN_004edd50(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int local_14;
  int local_10;
  int local_c;
  
  iVar1 = param_2 - param_1;
  do {
    iVar1 = iVar1 / 0xc;
    if (iVar1 < 0x21) {
LAB_004ede3e:
      if ((1 < iVar1) && (param_1 != param_2)) {
        FUN_004ee3e0(param_2,param_4);
      }
      return;
    }
    if (param_3 < 1) {
      if (0x20 < iVar1) {
        if (1 < (param_2 - param_1) / 0xc) {
          FUN_004ee210(param_2);
        }
        FUN_004ee330(param_4);
        return;
      }
      goto LAB_004ede3e;
    }
    FUN_004edea0(&local_14,param_1,param_2,param_4);
    param_3 = param_3 / 2 + (param_3 / 2) / 2;
    local_c = (param_2 - local_10) / 0xc;
    if ((local_14 - param_1) / 0xc < local_c) {
      FUN_004edd50(param_1,local_14,param_3,param_4);
      param_1 = local_10;
    }
    else {
      FUN_004edd50(local_10,param_2,param_3,param_4);
      param_2 = local_14;
    }
    iVar1 = param_2 - param_1;
  } while( true );
}

