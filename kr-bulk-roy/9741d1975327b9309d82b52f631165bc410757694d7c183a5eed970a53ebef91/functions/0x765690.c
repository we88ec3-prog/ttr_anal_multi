
void FUN_00765690(int *param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 8))();
  iVar2 = (**(code **)(*in_ECX + 8))();
  if (iVar1 == iVar2) {
    (**(code **)(*param_1 + 0x34))();
    param_1[1] = in_ECX[1];
    param_1[2] = in_ECX[2];
    param_1[3] = in_ECX[3];
    (**(code **)(*param_1 + 0x38))();
  }
  return;
}

