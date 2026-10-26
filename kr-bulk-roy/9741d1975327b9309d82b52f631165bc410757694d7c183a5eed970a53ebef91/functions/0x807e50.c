
undefined4 FUN_00807e50(void *param_1)

{
  uint unaff_ESI;
  int unaff_EDI;
  
  if (0x1000 < unaff_ESI) {
    return 0;
  }
  FID_conflict__memcpy((void *)(unaff_EDI + 8),param_1,unaff_ESI);
  *(uint *)(unaff_EDI + 4) = unaff_ESI;
  return 1;
}

