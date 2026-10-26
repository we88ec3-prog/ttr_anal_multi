
char * FUN_00703620(void)

{
  char *in_EAX;
  char *pcVar1;
  char *pcVar2;
  int unaff_EDI;
  
  pcVar1 = in_EAX + 1;
  if (*in_EAX == '%') {
    if (*pcVar1 == '\0') {
      FUN_006f5f30(*(undefined4 *)(unaff_EDI + 8),"malformed pattern (ends with \'%%\')");
    }
    return in_EAX + 2;
  }
  if (*in_EAX != '[') {
    return pcVar1;
  }
  if (*pcVar1 == '^') {
    pcVar1 = in_EAX + 2;
  }
  do {
    if (*pcVar1 == '\0') {
      FUN_006f5f30(*(undefined4 *)(unaff_EDI + 8),"malformed pattern (missing \']\')");
    }
    pcVar2 = pcVar1 + 1;
    if ((*pcVar1 == '%') && (*pcVar2 != '\0')) {
      pcVar2 = pcVar1 + 2;
    }
    pcVar1 = pcVar2;
  } while (*pcVar2 != ']');
  return pcVar2 + 1;
}

