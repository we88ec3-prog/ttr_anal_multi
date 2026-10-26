
void FUN_00571ac0(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 in_EAX;
  undefined4 in_ECX;
  
  param_1[1] = in_ECX;
  *param_1 = in_EAX;
  FUN_004026e0(param_2,0,0xffffffff);
  param_1[9] = param_3;
  if (7 < (uint)param_2[5]) {
    param_2 = (undefined4 *)*param_2;
  }
  FUN_004d4620(param_3,param_2,0x65,param_1 + 10);
  return;
}

