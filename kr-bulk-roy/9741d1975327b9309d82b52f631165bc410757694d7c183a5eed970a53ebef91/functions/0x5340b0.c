
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005340b0(void)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090ff48;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  if (DAT_00fe1c3c != 0) {
    FUN_0089120c(DAT_00fe1c3c,uVar2);
  }
  DAT_00fe1c3c = 0;
  DAT_00fe1c40 = 0;
  _DAT_00fe1c44 = 0;
  if (DAT_00fe1c2c != 0) {
    FUN_0089120c(DAT_00fe1c2c,uVar2);
  }
  DAT_00fe1c2c = 0;
  DAT_00fe1c30 = 0;
  _DAT_00fe1c34 = 0;
  piVar3 = (int *)*DAT_00fe1c10;
  *DAT_00fe1c10 = (int)DAT_00fe1c10;
  DAT_00fe1c10[1] = (int)DAT_00fe1c10;
  _DAT_00fe1c14 = 0;
  if (piVar3 != DAT_00fe1c10) {
    do {
      piVar1 = (int *)*piVar3;
      FUN_0089120c(piVar3,uVar2);
      piVar3 = piVar1;
    } while (piVar1 != DAT_00fe1c10);
  }
  FUN_0089120c(DAT_00fe1c10,uVar2);
  FUN_00537240(&DAT_00fe1bec);
  piVar3 = (int *)*DAT_00fe1be0;
  *DAT_00fe1be0 = (int)DAT_00fe1be0;
  DAT_00fe1be0[1] = (int)DAT_00fe1be0;
  DAT_00fe1be4 = 0;
  if (piVar3 != DAT_00fe1be0) {
    do {
      piVar1 = (int *)*piVar3;
      FUN_0089120c(piVar3);
      piVar3 = piVar1;
    } while (piVar1 != DAT_00fe1be0);
  }
  FUN_0089120c(DAT_00fe1be0);
  ExceptionList = local_10;
  return;
}

