
void FUN_0050b610(undefined4 param_1,int param_2,undefined4 param_3,int param_4,int param_5,
                 undefined4 param_6)

{
  int iVar1;
  int iVar2;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  int local_c;
  
  while( true ) {
    if (param_4 - param_2 < 0x21) {
      if (1 < param_4 - param_2) {
        FUN_0050bee0(param_6,param_1,param_2,param_3,param_4);
      }
      return;
    }
    if (param_5 < 1) break;
    FUN_0050b890(&local_18,param_6,param_1,param_2,param_3,param_4);
    iVar1 = local_14;
    iVar2 = local_c;
    param_5 = param_5 / 2 + (param_5 / 2) / 2;
    if (local_14 - param_2 < param_4 - local_c) {
      FUN_0050b610(param_1,param_2,local_18,local_14,param_5,param_6);
      param_1 = local_10;
      param_2 = iVar2;
    }
    else {
      FUN_0050b610(local_10,local_c,param_3,param_4,param_5,param_6);
      param_3 = local_18;
      param_4 = iVar1;
    }
  }
  if (1 < param_4 - param_2) {
    FUN_0050bd60(param_6,param_1,param_2,param_3,param_4);
  }
  FUN_0050bdf0(param_6,param_1,param_2,param_3,param_4);
  return;
}

