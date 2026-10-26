
void FUN_00445ee0(void)

{
  int iVar1;
  int *_Src;
  int *piVar2;
  
  _Src = DAT_00fb93d4;
  piVar2 = DAT_00fb93d0;
  if (DAT_00fb93d0 != DAT_00fb93d4) {
    do {
      iVar1 = *piVar2;
      if (iVar1 != 0) {
        if (*(int *)(iVar1 + 0xc) != 0) {
          FUN_0089120c(*(int *)(iVar1 + 0xc));
        }
        *(undefined4 *)(iVar1 + 0xc) = 0;
        *(undefined4 *)(iVar1 + 0x10) = 0;
        *(undefined4 *)(iVar1 + 0x14) = 0;
        FUN_0089120c(iVar1);
        _Src = DAT_00fb93d4;
      }
      piVar2 = piVar2 + 1;
    } while (piVar2 != _Src);
  }
  piVar2 = DAT_00fb93d0;
  if (DAT_00fb93d0 != _Src) {
    FID_conflict__memcpy(DAT_00fb93d0,_Src,0);
    DAT_00fb93d4 = piVar2;
  }
  return;
}

