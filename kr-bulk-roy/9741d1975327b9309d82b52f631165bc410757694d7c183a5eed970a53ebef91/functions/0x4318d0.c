
int * FUN_004318d0(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  piVar2 = param_1;
  iVar1 = **(int **)(in_ECX + 0x30);
  *param_1 = iVar1;
  std::_Lockit::_Lockit((_Lockit *)&param_1,0);
  if (*(int *)(iVar1 + 4) != -1) {
    *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
  }
  FUN_0087dd6f();
  return piVar2;
}

