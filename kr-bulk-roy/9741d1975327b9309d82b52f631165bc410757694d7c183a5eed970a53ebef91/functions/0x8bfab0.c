
int FUN_008bfab0(void)

{
  char *in_EAX;
  int iVar1;
  int unaff_ESI;
  
  if ((((unaff_ESI != 0) && (*(int *)(unaff_ESI + 0x48) != 0)) && (in_EAX != (char *)0x0)) &&
     (*in_EAX != '\0')) {
    iVar1 = FUN_008bdf60(*(undefined4 *)(unaff_ESI + 0x80));
    if (iVar1 != 0) {
      return *(int *)(iVar1 + 4) * 0x10 + *(int *)(unaff_ESI + 0x50);
    }
  }
  return 0;
}

