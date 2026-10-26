
void FUN_007bb920(undefined4 param_1)

{
  char cVar1;
  char *pcVar2;
  char *in_EDX;
  undefined1 *unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 0x14) = 0xf;
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  *unaff_ESI = 0;
  pcVar2 = in_EDX;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(in_EDX,(int)pcVar2 - (int)(in_EDX + 1));
  *(undefined4 *)(unaff_ESI + 0x20) = param_1;
  *(undefined4 *)(unaff_ESI + 0x1c) = 0;
  *(undefined4 *)(unaff_ESI + 0x24) = 0;
  return;
}

