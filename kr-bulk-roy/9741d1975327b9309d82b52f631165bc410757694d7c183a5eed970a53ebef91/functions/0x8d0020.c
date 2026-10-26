
int FUN_008d0020(undefined4 *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = param_3;
  param_1[8] = param_3;
  uVar2 = FUN_008bc7d0(param_3,4,0,param_2,0,&param_3);
  param_1[6] = uVar2;
  if (param_3 == 0) {
    uVar2 = FUN_008bc7d0(iVar1,4,0,param_2,0,&param_3);
    param_1[7] = uVar2;
    if (param_3 == 0) {
      param_1[4] = param_2;
      param_1[3] = 0xdeadbeef;
      param_1[5] = 0;
      *param_1 = 0;
      param_1[2] = 0;
      param_1[1] = 0;
      param_1[9] = FUN_008d0020;
      param_1[10] = FUN_008d0210;
      param_1[0xb] = FUN_008d0160;
      param_1[0xc] = FUN_008d0270;
      return 0;
    }
  }
  FUN_008b9f80(iVar1,param_1[6]);
  param_1[6] = 0;
  return param_3;
}

