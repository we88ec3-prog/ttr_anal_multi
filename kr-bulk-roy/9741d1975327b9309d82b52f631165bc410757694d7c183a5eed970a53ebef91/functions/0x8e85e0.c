
undefined4 FUN_008e85e0(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_008e8520();
  FUN_008b8800(*param_1,param_2);
  if (iVar1 != 0) {
    (**(code **)(iVar1 + 4))(param_1[10],param_1[4],param_1[5],0,0);
  }
  return 0;
}

