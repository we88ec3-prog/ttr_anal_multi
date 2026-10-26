
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006ecb70(void)

{
  int iVar1;
  
  if (DAT_00fe3660 != (void *)0x0) {
    _free(DAT_00fe3660);
    DAT_00fe3660 = (void *)0x0;
  }
  _DAT_00fe3668 = 0;
  DAT_00fe3664 = 0;
  iVar1 = FUN_006ed1c0();
  if (-1 < iVar1) {
    *(undefined4 *)((int)DAT_00fe3660 + DAT_00fe3664 * 4) = 0x50;
    DAT_00fe3664 = DAT_00fe3664 + 1;
  }
  iVar1 = FUN_006ed1c0();
  if (-1 < iVar1) {
    *(undefined4 *)((int)DAT_00fe3660 + DAT_00fe3664 * 4) = 0x49;
    DAT_00fe3664 = DAT_00fe3664 + 1;
  }
  iVar1 = FUN_006ed1c0();
  if (-1 < iVar1) {
    *(undefined4 *)((int)DAT_00fe3660 + DAT_00fe3664 * 4) = 0x4d;
    DAT_00fe3664 = DAT_00fe3664 + 1;
  }
  iVar1 = FUN_006ed1c0();
  if (-1 < iVar1) {
    *(undefined4 *)((int)DAT_00fe3660 + DAT_00fe3664 * 4) = 0x4b;
    DAT_00fe3664 = DAT_00fe3664 + 1;
  }
  iVar1 = FUN_006ed1c0();
  if (-1 < iVar1) {
    *(undefined4 *)((int)DAT_00fe3660 + DAT_00fe3664 * 4) = 0x4f;
    DAT_00fe3664 = DAT_00fe3664 + 1;
  }
  iVar1 = FUN_006ed1c0();
  if (-1 < iVar1) {
    *(undefined4 *)((int)DAT_00fe3660 + DAT_00fe3664 * 4) = 0x47;
    DAT_00fe3664 = DAT_00fe3664 + 1;
  }
  return;
}

