
void FUN_0077ac20(int *param_1)

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
    FUN_00776790(in_ECX + 3);
    *(char *)(param_1 + 0x13) = (char)in_ECX[0x13];
    pcVar1 = *(code **)(*param_1 + 0x38);
    param_1[0x14] = in_ECX[0x14];
    (*pcVar1)();
  }
  return;
}

