
void FUN_00832d30(void)

{
  int iVar1;
  int *_Src;
  int *piVar2;
  
  _Src = DAT_00fe343c;
  piVar2 = DAT_00fe3438;
  if (DAT_00fe3438 != DAT_00fe343c) {
    do {
      iVar1 = *piVar2;
      if (iVar1 != 0) {
        FUN_00837ab0();
        FUN_0089120c(iVar1);
        _Src = DAT_00fe343c;
      }
      piVar2 = piVar2 + 1;
    } while (piVar2 != _Src);
  }
  piVar2 = DAT_00fe3438;
  if (DAT_00fe3438 != _Src) {
    FID_conflict__memcpy(DAT_00fe3438,_Src,0);
    DAT_00fe343c = piVar2;
  }
  return;
}

