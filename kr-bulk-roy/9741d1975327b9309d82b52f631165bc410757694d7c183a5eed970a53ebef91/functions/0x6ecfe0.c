
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006ecfe0(void)

{
  int iVar1;
  
  if (DAT_00fe3678 != (void *)0x0) {
    _free(DAT_00fe3678);
    DAT_00fe3678 = (void *)0x0;
  }
  _DAT_00fe3680 = 0;
  DAT_00fe367c = 0;
  iVar1 = FUN_006ed1c0();
  if (-1 < iVar1) {
    *(undefined4 *)((int)DAT_00fe3678 + DAT_00fe367c * 4) = 0x80000000;
    DAT_00fe367c = DAT_00fe367c + 1;
  }
  iVar1 = FUN_006ed1c0();
  if (-1 < iVar1) {
    *(undefined4 *)((int)DAT_00fe3678 + DAT_00fe367c * 4) = 0;
    DAT_00fe367c = DAT_00fe367c + 1;
  }
  iVar1 = FUN_006ed1c0();
  if (-1 < iVar1) {
    *(undefined4 *)((int)DAT_00fe3678 + DAT_00fe367c * 4) = 1;
    DAT_00fe367c = DAT_00fe367c + 1;
  }
  iVar1 = FUN_006ed1c0();
  if (-1 < iVar1) {
    *(undefined4 *)((int)DAT_00fe3678 + DAT_00fe367c * 4) = 2;
    DAT_00fe367c = DAT_00fe367c + 1;
  }
  iVar1 = FUN_006ed1c0();
  if (-1 < iVar1) {
    *(undefined4 *)((int)DAT_00fe3678 + DAT_00fe367c * 4) = 4;
    DAT_00fe367c = DAT_00fe367c + 1;
  }
  iVar1 = FUN_006ed1c0();
  if (-1 < iVar1) {
    *(undefined4 *)((int)DAT_00fe3678 + DAT_00fe367c * 4) = 8;
    DAT_00fe367c = DAT_00fe367c + 1;
  }
  return;
}

