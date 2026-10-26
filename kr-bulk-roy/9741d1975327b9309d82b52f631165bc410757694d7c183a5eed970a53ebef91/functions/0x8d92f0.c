
undefined4 FUN_008d92f0(int param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  
  FUN_008d90e0(param_1,param_2,param_3,param_4);
  if (*(int *)(param_1 + 300) != *(int *)(param_1 + 0x130)) {
    if (*param_4 != 0) {
      iVar1 = FUN_008b7dc0(*param_4,*(int *)(param_1 + 300),*(int *)(param_1 + 0x130));
      *param_4 = iVar1;
    }
    if (param_4[1] != 0) {
      iVar1 = FUN_008b7dc0(*param_4,*(undefined4 *)(param_1 + 300),*(undefined4 *)(param_1 + 0x130))
      ;
      param_4[1] = iVar1;
    }
  }
  return 0;
}

