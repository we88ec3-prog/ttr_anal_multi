
void FUN_0083f6d0(uint param_1)

{
  int iVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00904f80;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0x1fffffff < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  if ((uint)(DAT_00fbac94 - DAT_00fbac8c >> 3) < param_1) {
    iVar1 = FUN_0071a0c0();
    local_8 = 0;
    FUN_006d1d70(DAT_00fbac8c,iVar1);
    iVar2 = DAT_00fbac90 - DAT_00fbac8c;
    if (DAT_00fbac8c != 0) {
      FUN_0089120c(DAT_00fbac8c);
    }
    DAT_00fbac94 = iVar1 + param_1 * 8;
    DAT_00fbac90 = iVar1 + (iVar2 >> 3) * 8;
    DAT_00fbac8c = iVar1;
  }
  ExceptionList = local_10;
  return;
}

