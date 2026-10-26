
void FUN_00778020(int *param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 8))();
  iVar2 = (**(code **)(*in_ECX + 8))();
  if (iVar1 == iVar2) {
    (**(code **)(*param_1 + 0x34))();
    FUN_007780c0();
    (**(code **)(*param_1 + 0x38))();
  }
  return;
}

