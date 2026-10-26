
int FUN_00768bb0(undefined4 *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_007680b0(param_1);
  if (0 < iVar1) {
    if (7 < (uint)param_1[5]) {
      param_1 = (undefined4 *)*param_1;
    }
    FUN_007660d0(in_ECX,param_1,*(undefined4 *)(in_ECX + 0x13c));
    FUN_00767a80();
  }
  return iVar1;
}

