
undefined4 FUN_007226c0(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = FUN_00721aa0();
  *param_2 = iVar1;
  if (iVar1 == 0) {
    iVar1 = 1;
  }
  iVar1 = (*(code *)PTR_FUN_00d63d48)(iVar1);
  *param_1 = iVar1;
  if (iVar1 == 0) {
    return 0;
  }
  FUN_00721b80();
  return 1;
}

