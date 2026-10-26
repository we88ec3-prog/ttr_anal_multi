
undefined4 FUN_00722760(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = FUN_00721b30();
  *param_2 = iVar1;
  if (iVar1 == 0) {
    iVar1 = 1;
  }
  iVar1 = (*(code *)PTR_FUN_00d63d48)(iVar1);
  *param_1 = iVar1;
  if (iVar1 == 0) {
    return 0;
  }
  FUN_00721cb0();
  return 1;
}

