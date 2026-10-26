
void FUN_00404c80(int *param_1)

{
  int iVar1;
  int *unaff_ESI;
  int *unaff_EDI;
  
  iVar1 = *param_1;
  if (param_1 != (int *)*unaff_ESI) {
    *(int *)param_1[1] = *param_1;
    *(int *)(*param_1 + 4) = param_1[1];
    FUN_0089120c(param_1);
    unaff_ESI[1] = unaff_ESI[1] + -1;
    *unaff_EDI = iVar1;
    return;
  }
  *unaff_EDI = iVar1;
  return;
}

