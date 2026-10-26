
void FUN_00787b30(int *param_1)

{
  uint in_EAX;
  uint uVar1;
  int iVar2;
  
  uVar1 = param_1[1] - *param_1 >> 4;
  if (in_EAX < uVar1) {
    if (*param_1 + in_EAX * 0x10 != param_1[1]) {
      iVar2 = FUN_008698b0();
      param_1[1] = iVar2;
      return;
    }
  }
  else if (uVar1 < in_EAX) {
    FUN_007880a0();
    FUN_00789830(param_1);
    param_1[1] = (in_EAX - (param_1[1] - *param_1 >> 4)) * 0x10 + param_1[1];
  }
  return;
}

