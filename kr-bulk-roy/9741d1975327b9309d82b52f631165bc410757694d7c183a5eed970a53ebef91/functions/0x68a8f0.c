
void FUN_0068a8f0(int *param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  
  iVar2 = (**(code **)(*param_1 + 8))();
  iVar3 = (**(code **)(*in_ECX + 8))();
  if (iVar2 == iVar3) {
    (**(code **)(*param_1 + 0x30))();
    FUN_00643e20();
    param_1[0x5b] = in_ECX[0x5b];
    pcVar1 = *(code **)(*param_1 + 0x34);
    param_1[0x5c] = in_ECX[0x5c];
    (*pcVar1)();
  }
  return;
}

