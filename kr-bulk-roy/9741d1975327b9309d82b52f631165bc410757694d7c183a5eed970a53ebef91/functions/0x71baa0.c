
int * FUN_0071baa0(char *param_1)

{
  int iVar1;
  int *in_EAX;
  int iVar2;
  int *unaff_EDI;
  
  if (*in_EAX == 0) {
    *unaff_EDI = 0;
    return unaff_EDI;
  }
  iVar1 = *(int *)(*in_EAX + 0x1c);
  while( true ) {
    if (iVar1 == 0) {
      *unaff_EDI = 0;
      return unaff_EDI;
    }
    if ((*(char **)(iVar1 + 4) != (char *)0x0) &&
       (iVar2 = __stricmp(param_1,*(char **)(iVar1 + 4)), iVar2 == 0)) break;
    iVar1 = *(int *)(iVar1 + 0x10);
  }
  *unaff_EDI = iVar1;
  return unaff_EDI;
}

