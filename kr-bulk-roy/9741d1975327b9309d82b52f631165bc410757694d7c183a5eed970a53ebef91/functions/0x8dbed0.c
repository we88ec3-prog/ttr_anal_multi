
undefined4 FUN_008dbed0(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  
  FUN_008b8800(*param_1,param_2);
  iVar1 = FUN_008dbe10();
  if (iVar1 != 0) {
    (**(code **)(iVar1 + 4))(param_1[10],param_1[4],param_1[5],0,0);
  }
  return 0;
}

