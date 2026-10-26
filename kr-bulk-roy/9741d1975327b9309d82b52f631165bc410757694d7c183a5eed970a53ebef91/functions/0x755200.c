
void FUN_00755200(int *param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  
  iVar2 = (**(code **)(*param_1 + 8))();
  iVar3 = (**(code **)(*in_ECX + 8))();
  if (iVar2 == iVar3) {
    (**(code **)(*param_1 + 0x30))();
    FUN_00404de0(in_ECX);
    param_1[0x20] = in_ECX[0x20];
    param_1[0x21] = in_ECX[0x21];
    pcVar1 = *(code **)(*param_1 + 0x34);
    param_1[0x22] = in_ECX[0x22];
    (*pcVar1)();
  }
  return;
}

