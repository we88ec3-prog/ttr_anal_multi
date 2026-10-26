
undefined4 FUN_008ba9b0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 4) != 0)) {
    uVar1 = FUN_008ba8f0(*(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 0x60) + 4),param_1,param_2
                        );
    return uVar1;
  }
  return 6;
}

