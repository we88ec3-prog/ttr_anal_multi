
void FUN_0073cce0(undefined4 param_1,short *param_2,int param_3)

{
  short sVar1;
  int iVar2;
  int in_ECX;
  
  if (param_3 < 0) {
    do {
      sVar1 = *param_2;
      param_2 = param_2 + 1;
    } while (sVar1 != 0);
  }
  param_3 = param_1;
  FUN_008438c0(&param_3);
  if (((in_ECX == *(int *)(in_ECX + 0x3c)) || (iVar2 = *(int *)(in_ECX + 0x10), iVar2 == 0)) &&
     (iVar2 = FUN_0073d5e0(), iVar2 == 0)) {
    return;
  }
  FUN_0073d9b0(in_ECX + 0xc,iVar2);
  return;
}

