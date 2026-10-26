
int FUN_0071c2e0(int param_1)

{
  int iVar1;
  int *piVar2;
  int local_c;
  int local_8;
  
  iVar1 = 0;
  while (param_1 != 0) {
    iVar1 = iVar1 + 1;
    if (param_1 == 0) {
      local_c = 0;
      piVar2 = &local_c;
    }
    else {
      local_8 = *(int *)(param_1 + 4);
      piVar2 = &local_8;
    }
    param_1 = *piVar2;
  }
  return iVar1;
}

