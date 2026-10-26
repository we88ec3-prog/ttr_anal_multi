
void FUN_0082f3f0(void)

{
  char *pcVar1;
  int iVar2;
  char *unaff_ESI;
  
  unaff_ESI[0x20] = '\x02';
  unaff_ESI[0x21] = '\0';
  unaff_ESI[0x22] = '\0';
  unaff_ESI[0x23] = '\0';
  pcVar1 = unaff_ESI + 0x34;
  iVar2 = 0x1f;
  do {
    pcVar1[0] = -1;
    pcVar1[1] = -1;
    pcVar1[2] = -1;
    pcVar1[3] = -1;
    pcVar1[4] = '\0';
    pcVar1[5] = '\0';
    pcVar1[6] = '\0';
    pcVar1[7] = '\0';
    pcVar1[8] = '\0';
    pcVar1[9] = '\0';
    pcVar1[10] = '\0';
    pcVar1[0xb] = '\0';
    pcVar1[0xc] = '\0';
    pcVar1[0xd] = '\0';
    pcVar1[0xe] = '\0';
    pcVar1[0xf] = '\0';
    pcVar1 = pcVar1 + 0x10;
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  _strcpy_s(unaff_ESI,0x20,"MapTool Reinforce 1.0");
  return;
}

