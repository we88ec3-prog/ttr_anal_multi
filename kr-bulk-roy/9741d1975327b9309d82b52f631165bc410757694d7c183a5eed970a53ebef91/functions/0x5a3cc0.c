
/* WARNING: Removing unreachable block (ram,0x005a3de8) */

void FUN_005a3cc0(void)

{
  uint uVar1;
  undefined4 extraout_EDX;
  undefined4 local_30;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920f66;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_005960b0(uVar1);
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8 = 0;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_8 = 0xffffffff;
  }
  FUN_008fed10();
  FUN_0040ef80();
  local_8 = 1;
  FUN_0058ec10(&DAT_00faaf80,L"ChatTransparency");
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 3;
  FUN_004095e0(0x92);
  FUN_004095e0(0x93);
  FUN_004095e0(0x94);
  FUN_004095e0(0x95);
  FUN_004095e0(0xd8);
  ExceptionList = local_10;
  __security_check_cookie
            (uVar1 ^ (uint)&stack0xfffffffc,extraout_EDX,FoxUI::FXUIBinderBase::vftable);
  return;
}

