
void FUN_0040ba20(int *param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  
  iVar2 = (**(code **)(*param_1 + 8))();
  iVar3 = (**(code **)(*in_ECX + 8))();
  if (iVar2 == iVar3) {
    (**(code **)(*param_1 + 0x30))();
    FUN_00408e60(param_1);
    param_1[0xa6] = in_ECX[0xa6];
    pcVar1 = *(code **)(*param_1 + 0x34);
    param_1[0xa7] = in_ECX[0xa7];
    (*pcVar1)();
  }
  return;
}

