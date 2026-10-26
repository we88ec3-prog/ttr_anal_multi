
int * FUN_007151f0(int *param_1,int *param_2)

{
  int iVar1;
  int *unaff_EDI;
  
  iVar1 = *param_2;
  if (param_2 != (int *)*unaff_EDI) {
    *(int *)param_2[1] = *param_2;
    *(int *)(*param_2 + 4) = param_2[1];
    FUN_00714fe0();
    FUN_0089120c(param_2);
    unaff_EDI[1] = unaff_EDI[1] + -1;
    *param_1 = iVar1;
    return param_1;
  }
  *param_1 = iVar1;
  return param_1;
}

