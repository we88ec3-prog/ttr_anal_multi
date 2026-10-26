
int * FUN_007df190(int *param_1)

{
  char cVar1;
  int iVar2;
  int unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar2 = FUN_007b6f30(unaff_EDI);
  if (iVar2 != *(int *)(unaff_ESI + 4)) {
    cVar1 = FUN_0049ae30();
    if (cVar1 == '\0') {
      *param_1 = iVar2;
      return param_1;
    }
  }
  *param_1 = *(int *)(unaff_ESI + 4);
  return param_1;
}

