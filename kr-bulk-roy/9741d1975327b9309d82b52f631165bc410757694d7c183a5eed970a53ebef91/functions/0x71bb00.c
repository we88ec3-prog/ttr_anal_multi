
int * FUN_0071bb00(char *param_1)

{
  int iVar1;
  int *in_EAX;
  int iVar2;
  int *unaff_EDI;
  
  if (*in_EAX == 0) {
    *unaff_EDI = 0;
    return unaff_EDI;
  }
  iVar1 = *(int *)(*in_EAX + 0x18);
  while( true ) {
    if (iVar1 == 0) {
      *unaff_EDI = 0;
      return unaff_EDI;
    }
    if ((*(char **)(iVar1 + 8) != (char *)0x0) &&
       (iVar2 = __stricmp(param_1,*(char **)(iVar1 + 8)), iVar2 == 0)) break;
    iVar1 = *(int *)(iVar1 + 0x18);
  }
  *unaff_EDI = iVar1;
  return unaff_EDI;
}

