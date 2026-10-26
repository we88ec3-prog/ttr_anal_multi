
undefined4 FUN_0089843e(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if (-1 < param_1) {
    piVar1 = (int *)FUN_008ae1c3();
    if (param_1 < *piVar1) goto LAB_0089845b;
  }
  piVar1 = (int *)FUN_008ae1c3();
  param_1 = *piVar1;
LAB_0089845b:
  iVar2 = FUN_008ae1c9();
  return *(undefined4 *)(iVar2 + param_1 * 4);
}

