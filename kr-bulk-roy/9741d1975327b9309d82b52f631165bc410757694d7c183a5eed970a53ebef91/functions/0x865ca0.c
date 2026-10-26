
undefined4 FUN_00865ca0(undefined4 param_1)

{
  int unaff_ESI;
  uint unaff_EDI;
  
  if ((unaff_EDI <= (uint)((*(int *)(unaff_ESI + 0x34) - *(int *)(unaff_ESI + 0x30)) / 0x11c)) &&
     (unaff_EDI <= (uint)((*(int *)(unaff_ESI + 0x44) - *(int *)(unaff_ESI + 0x40)) / 0x1c))) {
    FUN_00843240(param_1,unaff_EDI * 0x11c + *(int *)(unaff_ESI + 0x30));
    FUN_00403040(*(int *)(unaff_ESI + 0x40) + unaff_EDI * 0x1c,0,0xffffffff);
    return 1;
  }
  return 0;
}

