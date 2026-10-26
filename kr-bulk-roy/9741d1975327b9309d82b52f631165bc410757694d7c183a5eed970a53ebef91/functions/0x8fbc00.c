
int FUN_008fbc00(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  uVar1 = *(undefined4 *)(param_2 + 0x1c);
  param_2 = FUN_008fb610();
  if (param_2 == 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[8] = 0;
    param_1[9] = 0;
    param_1[7] = uVar1;
    uVar2 = FUN_008b9f30(uVar1,0x2054,&param_2);
    if (param_2 == 0) {
      param_2 = FUN_008fbb60();
      if (param_2 != 0) {
        FUN_008b9f80(uVar1,uVar2);
        return param_2;
      }
      param_1[3] = uVar2;
      param_2 = 0;
    }
    uVar3 = FUN_008fba10();
    if ((uVar3 != 0) && (uVar3 < 0xa000)) {
      uVar4 = FUN_008baee0(uVar1,uVar3,&param_2);
      if (param_2 == 0) {
        uVar5 = FUN_008fb910(0,uVar4);
        if (uVar5 == uVar3) {
          FUN_008fb750();
          FUN_008b9f80(uVar1,uVar2);
          param_1[3] = 0;
          param_1[1] = uVar3;
          param_1[2] = 0;
          param_1[5] = 0;
          *param_1 = uVar4;
          param_1[6] = FUN_008fb9c0;
          return param_2;
        }
        FUN_008fb910(0,0);
        FUN_008b9f80(uVar1,uVar4);
      }
      param_2 = 0;
    }
    param_1[1] = 0x7fffffff;
    param_1[2] = 0;
    *param_1 = 0;
    param_1[5] = FUN_008fb9f0;
    param_1[6] = FUN_008fb9c0;
  }
  return param_2;
}

