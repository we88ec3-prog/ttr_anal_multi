
void FUN_0051f670(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int local_c;
  int local_8;
  
  iVar1 = param_2 - param_1;
  do {
    iVar1 = iVar1 / 0x14;
    if (iVar1 < 0x21) {
LAB_0051f745:
      if ((1 < iVar1) && (param_1 != param_2)) {
        FUN_005202b0(param_1,param_2,param_4);
      }
      return;
    }
    if (param_3 < 1) {
      if (0x20 < iVar1) {
        if (1 < (param_2 - param_1) / 0x14) {
          FUN_005200f0(param_1,param_2,param_4);
        }
        FUN_005201b0(param_4);
        return;
      }
      goto LAB_0051f745;
    }
    FUN_0051f9e0(&local_c,param_1,param_2,param_4);
    param_3 = param_3 / 2 + (param_3 / 2) / 2;
    if ((local_c - param_1) / 0x14 < (param_2 - local_8) / 0x14) {
      FUN_0051f670(param_1,local_c,param_3,param_4);
      param_1 = local_8;
    }
    else {
      FUN_0051f670(local_8,param_2,param_3,param_4);
      param_2 = local_c;
    }
    iVar1 = param_2 - param_1;
  } while( true );
}

