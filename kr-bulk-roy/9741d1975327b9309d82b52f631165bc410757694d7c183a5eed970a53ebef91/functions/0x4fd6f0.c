
void FUN_004fd6f0(uint param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00910600;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 < 0x2e8ba2f) {
    if ((uint)((DAT_00fe1ab4 - DAT_00fe1aac) / 0x58) < param_1) {
      iVar3 = FUN_004fd860();
      local_8 = 0;
      FUN_004fd960(DAT_00fe1ab0,iVar3,param_1);
      iVar2 = DAT_00fe1ab0;
      iVar4 = DAT_00fe1ab0 - DAT_00fe1aac;
      iVar1 = DAT_00fe1aac;
      if (DAT_00fe1aac != 0) {
        for (; iVar1 != iVar2; iVar1 = iVar1 + 0x58) {
          FUN_004c0590();
        }
        FUN_0089120c(DAT_00fe1aac);
      }
      DAT_00fe1ab4 = param_1 * 0x58 + iVar3;
      DAT_00fe1ab0 = (iVar4 / 0x58) * 0x58 + iVar3;
      DAT_00fe1aac = iVar3;
    }
    ExceptionList = local_10;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0087db30("vector<T> too long");
}

