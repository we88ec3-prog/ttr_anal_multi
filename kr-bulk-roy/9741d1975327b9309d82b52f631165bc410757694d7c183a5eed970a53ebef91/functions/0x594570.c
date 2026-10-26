
void FUN_00594570(uint param_1)

{
  int unaff_EDI;
  
  if ((char)(param_1 >> 0x10) == '\0') {
    if ((char)param_1 != '\0') {
      FUN_004026e0(unaff_EDI + 4 + (param_1 & 0xff) * 0x1c,0,0xffffffff);
      return;
    }
    FUN_00402160(&DAT_00bed1fc,0);
  }
  else {
    FUN_004026e0(unaff_EDI + 4 + (param_1 >> 0x10 & 0xff) * 0x1c,0,0xffffffff);
    if ((char)param_1 != '\0') {
      FUN_00404300(&DAT_00c1b354,3);
      FUN_004041f0(unaff_EDI + 4 + (param_1 & 0xff) * 0x1c,0,0xffffffff);
      return;
    }
  }
  return;
}

