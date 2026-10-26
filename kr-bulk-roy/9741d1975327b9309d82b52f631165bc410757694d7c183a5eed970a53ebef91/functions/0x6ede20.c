
void FUN_006ede20(void)

{
  LPCSTR lpFileName;
  LPCSTR unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x1c) != 0) {
    lpFileName = unaff_ESI;
    if (0xf < *(uint *)(unaff_ESI + 0x14)) {
      lpFileName = *(LPCSTR *)unaff_ESI;
    }
    WritePrivateProfileStringA((LPCSTR)0x0,(LPCSTR)0x0,(LPCSTR)0x0,lpFileName);
  }
  if (0xf < *(uint *)(unaff_ESI + 0x14)) {
    FUN_0089120c(*(undefined4 *)unaff_ESI);
  }
  unaff_ESI[0x14] = '\x0f';
  unaff_ESI[0x15] = '\0';
  unaff_ESI[0x16] = '\0';
  unaff_ESI[0x17] = '\0';
  unaff_ESI[0x10] = '\0';
  unaff_ESI[0x11] = '\0';
  unaff_ESI[0x12] = '\0';
  unaff_ESI[0x13] = '\0';
  *unaff_ESI = '\0';
  return;
}

