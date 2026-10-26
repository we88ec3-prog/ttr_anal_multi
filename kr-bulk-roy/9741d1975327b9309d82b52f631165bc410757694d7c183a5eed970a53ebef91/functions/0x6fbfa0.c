
bool FUN_006fbfa0(double *param_1)

{
  int in_EAX;
  int iVar1;
  double *unaff_EDI;
  
  switch(*(undefined4 *)(unaff_EDI + 1)) {
  case 0:
    goto switchD_006fbfb6_caseD_0;
  case 1:
    return *(int *)unaff_EDI == *(int *)param_1;
  case 2:
    return *(int *)unaff_EDI == *(int *)param_1;
  case 3:
    if (*param_1 != *unaff_EDI) {
      return false;
    }
    return true;
  default:
    return *(int *)unaff_EDI == *(int *)param_1;
  case 5:
    if (*(int *)unaff_EDI == *(int *)param_1) {
      return true;
    }
    break;
  case 7:
    if (*(int *)unaff_EDI == *(int *)param_1) {
      return true;
    }
  }
  iVar1 = FUN_006fbc20();
  if (iVar1 != 0) {
    FUN_006fb700();
    iVar1 = (*(int **)(in_EAX + 8))[2];
    if (iVar1 != 0) {
      if (iVar1 != 1) {
switchD_006fbfb6_caseD_0:
        return true;
      }
      if (**(int **)(in_EAX + 8) != 0) {
        return true;
      }
    }
  }
  return false;
}

