
bool FUN_0087b4b0(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 *puVar2;
  
  if ((param_5 != 0) && (*(int **)(param_5 + 0x3c) != (int *)0x0)) {
    iVar1 = (**(code **)(**(int **)(param_5 + 0x3c) + 4))();
    if (*(int *)(iVar1 + 4) == -0x5ece0000) {
      FUN_00843f60(param_1);
      puVar2 = (undefined4 *)FUN_0083b440();
      if (puVar2 != (undefined4 *)0x0) {
        iVar1 = (**(code **)(*param_2 + 0xd0))(param_2,param_3,*puVar2);
        return iVar1 == 0;
      }
    }
  }
  return false;
}

