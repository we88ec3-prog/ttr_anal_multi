
bool FUN_0087b740(undefined4 param_1,int *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  if ((param_4 != 0) && (param_2 != (int *)0x0)) {
    iVar1 = (**(code **)(*param_2 + 0x78))
                      (param_2,param_3,
                       (float)((*(int *)(param_4 + 8) - *(int *)(param_4 + 4)) / 0x38));
    return iVar1 == 0;
  }
  return false;
}

