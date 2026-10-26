
undefined4 FUN_008f7580(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    return 6;
  }
  uVar1 = FUN_008b8ce0(**(undefined4 **)(param_1 + 0x24),param_2);
  *param_3 = uVar1;
  *param_4 = 0;
  return 0;
}

