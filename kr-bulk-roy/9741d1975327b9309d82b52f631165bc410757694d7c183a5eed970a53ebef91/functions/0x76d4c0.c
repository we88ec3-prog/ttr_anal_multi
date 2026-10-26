
void FUN_0076d4c0(int *param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 8))();
  iVar2 = (**(code **)(*in_ECX + 8))();
  if (iVar1 == iVar2) {
    (**(code **)(*param_1 + 0x30))();
    FUN_0075a980();
    param_1[0x40] = in_ECX[0x40];
    param_1[0x41] = in_ECX[0x41];
    param_1[0x42] = in_ECX[0x42];
    param_1[0x43] = in_ECX[0x43];
    (**(code **)(*param_1 + 0x34))();
  }
  return;
}

