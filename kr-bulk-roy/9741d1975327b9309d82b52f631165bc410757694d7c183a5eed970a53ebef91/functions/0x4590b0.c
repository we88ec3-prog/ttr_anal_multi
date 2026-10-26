
void FUN_004590b0(int *param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 8))();
  iVar2 = (**(code **)(*in_ECX + 8))();
  if (iVar1 == iVar2) {
    (**(code **)(*param_1 + 0x30))();
    FUN_00408e60(param_1);
    param_1[0xa6] = in_ECX[0xa6];
    FUN_0045d560();
    (**(code **)(*param_1 + 0x34))(in_ECX);
  }
  return;
}

