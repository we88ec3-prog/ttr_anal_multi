
int FUN_008d0b90(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x40) == 3) {
    return 0;
  }
  *(undefined4 *)(param_1 + 0x40) = 3;
  iVar1 = FUN_008d0b20(param_1);
  if (iVar1 == 0) {
    iVar1 = FUN_008d0ae0(param_1,param_2,param_3);
  }
  return iVar1;
}

