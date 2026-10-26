
bool FUN_006eae10(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_006dfb80();
  iVar2 = (**(code **)(*piVar1 + 0x28))(piVar1,param_1[1],*param_1,param_2,0x80000,3,param_3);
  return -1 < iVar2;
}

