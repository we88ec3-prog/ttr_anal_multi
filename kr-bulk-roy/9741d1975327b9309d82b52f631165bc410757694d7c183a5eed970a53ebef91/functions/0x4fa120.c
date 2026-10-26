
void FUN_004fa120(uint param_1)

{
  int iVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00904b00;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0xccccccc < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  if ((uint)((DAT_00fe1a98 - DAT_00fe1a90) / 0x14) < param_1) {
    iVar1 = FUN_007e0110();
    local_8 = 0;
    FUN_004fa2b0(DAT_00fe1a90,param_1);
    iVar2 = DAT_00fe1a94 - DAT_00fe1a90;
    if (DAT_00fe1a90 != 0) {
      FUN_0089120c(DAT_00fe1a90);
    }
    DAT_00fe1a98 = iVar1 + param_1 * 0x14;
    DAT_00fe1a94 = iVar1 + (iVar2 / 0x14) * 0x14;
    DAT_00fe1a90 = iVar1;
  }
  ExceptionList = local_10;
  return;
}

