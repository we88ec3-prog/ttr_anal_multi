
void FUN_008d02f0(void)

{
  char cVar1;
  char *in_EAX;
  char *pcVar2;
  undefined4 *unaff_EDI;
  
  for (pcVar2 = (char *)*unaff_EDI; pcVar2 < in_EAX; pcVar2 = pcVar2 + 1) {
    cVar1 = *pcVar2;
    if ((((cVar1 != ' ') && (cVar1 != '\r')) && (cVar1 != '\n')) &&
       (((cVar1 != '\t' && (cVar1 != '\f')) && (cVar1 != '\0')))) {
      if (cVar1 != '%') break;
      FUN_008d02d0();
    }
  }
  *unaff_EDI = pcVar2;
  return;
}

