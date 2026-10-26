
void FUN_00557d80(int *param_1)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int unaff_EDI;
  
  if (in_EAX < 1) {
    *(int *)(unaff_EDI + in_EAX * 4) = *param_1;
    return;
  }
  do {
    iVar2 = (in_EAX + -1) / 2;
    iVar1 = *(int *)(unaff_EDI + iVar2 * 4);
    if (*(float *)(iVar1 + 0xc) <= *(float *)(*param_1 + 0xc)) {
      *(int *)(unaff_EDI + in_EAX * 4) = *param_1;
      return;
    }
    *(int *)(unaff_EDI + in_EAX * 4) = iVar1;
    in_EAX = iVar2;
  } while (0 < iVar2);
  *(int *)(unaff_EDI + iVar2 * 4) = *param_1;
  return;
}

