
bool FUN_0083de50(undefined4 *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_00840100(in_ECX + 0x188,*param_1);
  if (iVar1 != 0) {
    return *(int *)(iVar1 + 0x110) != 0;
  }
  return false;
}

