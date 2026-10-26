
void FUN_0075ab70(int *param_1)

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
    (**(code **)(*param_1 + 0x34))();
  }
  return;
}

