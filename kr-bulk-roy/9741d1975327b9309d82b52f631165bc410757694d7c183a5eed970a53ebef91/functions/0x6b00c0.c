
void FUN_006b00c0(int param_1,int param_2,undefined4 *param_3,code *param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int unaff_EDI;
  
  iVar2 = param_1;
  while( true ) {
    iVar3 = iVar2 * 2 + 2;
    if (param_2 <= iVar3) break;
    cVar1 = (*param_4)(*(undefined4 *)(unaff_EDI + iVar3 * 4),
                       *(undefined4 *)(unaff_EDI + -4 + iVar3 * 4));
    if (cVar1 != '\0') {
      iVar3 = iVar2 * 2 + 1;
    }
    *(undefined4 *)(unaff_EDI + iVar2 * 4) = *(undefined4 *)(unaff_EDI + iVar3 * 4);
    iVar2 = iVar3;
  }
  if (iVar3 == param_2) {
    *(undefined4 *)(unaff_EDI + iVar2 * 4) = *(undefined4 *)(unaff_EDI + -4 + param_2 * 4);
    iVar2 = param_2 + -1;
  }
  if (param_1 < iVar2) {
    do {
      iVar3 = (iVar2 + -1) / 2;
      cVar1 = (*param_4)(*(undefined4 *)(unaff_EDI + iVar3 * 4),*param_3);
      if (cVar1 == '\0') {
        *(undefined4 *)(unaff_EDI + iVar2 * 4) = *param_3;
        return;
      }
      *(undefined4 *)(unaff_EDI + iVar2 * 4) = *(undefined4 *)(unaff_EDI + iVar3 * 4);
      iVar2 = iVar3;
    } while (param_1 < iVar3);
    *(undefined4 *)(unaff_EDI + iVar3 * 4) = *param_3;
    return;
  }
  *(undefined4 *)(unaff_EDI + iVar2 * 4) = *param_3;
  return;
}

