
void FUN_007696b0(int *param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 8))();
  iVar2 = (**(code **)(*in_ECX + 8))();
  if (iVar1 == iVar2) {
    (**(code **)(*param_1 + 0x30))();
    FUN_00404f50();
    *(char *)(param_1 + 0x32) = (char)in_ECX[0x32];
    param_1[0x33] = in_ECX[0x33];
    param_1[0x34] = in_ECX[0x34];
    param_1[0x35] = in_ECX[0x35];
    (**(code **)(*param_1 + 0x34))();
  }
  return;
}

