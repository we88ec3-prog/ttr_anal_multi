
void FUN_00777ba0(int *param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  
  iVar2 = (**(code **)(*param_1 + 8))();
  iVar3 = (**(code **)(*in_ECX + 8))();
  if (iVar2 == iVar3) {
    (**(code **)(*param_1 + 0x34))();
    param_1[1] = in_ECX[1];
    param_1[2] = in_ECX[2];
    param_1[3] = in_ECX[3];
    param_1[4] = in_ECX[4];
    pcVar1 = *(code **)(*param_1 + 0x38);
    param_1[5] = in_ECX[5];
    (*pcVar1)();
  }
  return;
}

