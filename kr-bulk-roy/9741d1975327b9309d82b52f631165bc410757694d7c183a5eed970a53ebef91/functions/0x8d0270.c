
void FUN_008d0270(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = param_1[8];
  if (param_1[3] == -0x21524111) {
    FUN_008b9f80(uVar1,*param_1);
    *param_1 = 0;
    FUN_008b9f80(uVar1,param_1[6]);
    param_1[6] = 0;
    FUN_008b9f80(uVar1,param_1[7]);
    param_1[7] = 0;
    param_1[3] = 0;
  }
  return;
}

