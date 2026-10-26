
bool FUN_0083de20(undefined4 *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_0083ff20(in_ECX + 0x144,*param_1);
  if (iVar1 != 0) {
    return *(int *)(iVar1 + 4) != 0;
  }
  return false;
}

