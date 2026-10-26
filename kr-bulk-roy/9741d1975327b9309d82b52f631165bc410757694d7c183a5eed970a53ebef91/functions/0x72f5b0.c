
bool FUN_0072f5b0(void)

{
  int iVar1;
  FILE *unaff_ESI;
  int *unaff_EDI;
  
  if ((char)unaff_EDI[0x1d] != '\0') {
    FID_conflict__fputc(0xef,unaff_ESI);
    FID_conflict__fputc(0xbb,unaff_ESI);
    FID_conflict__fputc(0xbf,unaff_ESI);
  }
  (**(code **)(*unaff_EDI + 4))();
  iVar1 = _ferror(unaff_ESI);
  _fclose(unaff_ESI);
  return iVar1 == 0;
}

