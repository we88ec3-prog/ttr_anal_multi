
void FUN_008d02d0(void)

{
  char *pcVar1;
  undefined4 *in_EDX;
  char *unaff_ESI;
  
  for (pcVar1 = (char *)*in_EDX; ((pcVar1 < unaff_ESI && (*pcVar1 != '\r')) && (*pcVar1 != '\n'));
      pcVar1 = pcVar1 + 1) {
  }
  *in_EDX = pcVar1;
  return;
}

