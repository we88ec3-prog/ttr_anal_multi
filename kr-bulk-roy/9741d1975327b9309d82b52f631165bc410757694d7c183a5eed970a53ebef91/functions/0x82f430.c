
void FUN_0082f430(void)

{
  char *pcVar1;
  int iVar2;
  char *unaff_EDI;
  
  unaff_EDI[0x20] = '\x03';
  unaff_EDI[0x21] = '\0';
  unaff_EDI[0x22] = '\0';
  unaff_EDI[0x23] = '\0';
  iVar2 = 0x1f;
  pcVar1 = unaff_EDI + 0x54;
  do {
    pcVar1[-0xffffffff00000008] = -1;
    pcVar1[-0xffffffff00000007] = -1;
    pcVar1[-0xffffffff00000006] = -1;
    pcVar1[-0xffffffff00000005] = -1;
    pcVar1[-0xffffffff00000004] = '\0';
    pcVar1[-0xffffffff00000003] = '\0';
    pcVar1[-0xffffffff00000002] = '\0';
    pcVar1[-0xffffffff00000001] = '\0';
    pcVar1[0] = '\0';
    pcVar1[1] = '\0';
    pcVar1[2] = '\0';
    pcVar1[3] = '\0';
    pcVar1[4] = '\0';
    pcVar1[5] = '\0';
    pcVar1[6] = '\0';
    pcVar1[7] = '\0';
    pcVar1 = pcVar1 + 0x28;
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  _strcpy_s(unaff_EDI,0x20,"MapTool Reinforce 1.0");
  return;
}

