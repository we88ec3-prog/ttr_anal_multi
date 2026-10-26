
bool FUN_0087b580(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  if ((param_5 != 0) && (*(int **)(param_5 + 0x3c) != (int *)0x0)) {
    iVar1 = (**(code **)(**(int **)(param_5 + 0x3c) + 4))();
    if (*(int *)(iVar1 + 4) == -0x5ece0000) {
      iVar1 = FUN_00843f60(param_1);
      local_c = *(undefined4 *)(iVar1 + 0x5c);
      local_8 = *(undefined4 *)(iVar1 + 0x60);
      iVar1 = (**(code **)(*param_2 + 0x80))(param_2,param_3,&local_c,2);
      return iVar1 == 0;
    }
  }
  return false;
}

