
void FUN_00444d80(int *param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 8))();
  iVar2 = (**(code **)(*in_ECX + 8))();
  if (iVar1 == iVar2) {
    (**(code **)(*param_1 + 0x30))();
    FUN_00408e60(param_1);
    *(short *)(param_1 + 0xa6) = (short)in_ECX[0xa6];
    param_1[0xa7] = in_ECX[0xa7];
    param_1[0xa8] = in_ECX[0xa8];
    param_1[0xa9] = in_ECX[0xa9];
    (**(code **)(*param_1 + 0x34))();
  }
  return;
}

