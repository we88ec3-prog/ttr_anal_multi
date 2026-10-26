
int FUN_008fcc90(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int local_8;
  
  uVar1 = *(undefined4 *)(param_2 + 0x1c);
  local_8 = FUN_008fc440();
  if (local_8 == 0) {
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
    uVar2 = FUN_008baee0(uVar1,0x10c4,&local_8);
    if (local_8 == 0) {
      local_8 = FUN_008fca00();
      if (local_8 != 0) {
        FUN_008b9f80(uVar1,uVar2);
        return local_8;
      }
      param_1[3] = uVar2;
      local_8 = 0;
    }
    param_1[1] = 0x7fffffff;
    param_1[2] = 0;
    *param_1 = 0;
    param_1[5] = FUN_008fcc70;
    param_1[6] = FUN_008fcc40;
  }
  return local_8;
}

