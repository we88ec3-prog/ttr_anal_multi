
undefined4 FUN_007d6730(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  int *unaff_EDI;
  
  piVar2 = param_2;
  iVar1 = *unaff_EDI;
  param_2 = (int *)param_1;
  FUN_0082ef00(&param_2);
  if ((in_ECX != *(int *)(iVar1 + 0x38)) && (*(int *)(in_ECX + 0x10) != 0)) {
    if (piVar2 == (int *)0x0) {
      iVar1 = *(int *)(*(int *)(in_ECX + 0x10) + 4);
    }
    else {
      iVar1 = *piVar2;
    }
    unaff_EDI[1] = iVar1;
    unaff_EDI[2] = 0;
    unaff_EDI[4] = param_1;
    return 1;
  }
  return 0;
}

