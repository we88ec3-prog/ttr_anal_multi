
undefined4 FUN_008e1fc0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (*(int *)(*(int *)(param_1 + 0x290) + 0xb8c) == 0) {
    return 0xb;
  }
  iVar1 = FUN_008de030();
  if (iVar1 != 0) {
    FUN_008ba040(param_3,iVar1,param_4);
  }
  return 0;
}

