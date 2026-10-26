
void FUN_008cd1a0(int param_1)

{
  int iVar1;
  undefined4 *in_ECX;
  undefined4 *unaff_EBX;
  
  if (((unaff_EBX[1] == 0) && (unaff_EBX[3] - 1 < 2)) && (param_1 != 0)) {
    while (iVar1 = FUN_008ccf90(*in_ECX,*unaff_EBX,0), iVar1 == 0) {
      param_1 = param_1 + -1;
      in_ECX = in_ECX + 2;
      if (param_1 == 0) {
        return;
      }
    }
    unaff_EBX[1] = iVar1;
  }
  return;
}

