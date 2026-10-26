
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006eb640(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090491b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 2;
  FUN_006eb8b0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (DAT_00fe36b0 != (void *)0x0) {
    _free(DAT_00fe36b0);
    DAT_00fe36b0 = (void *)0x0;
  }
  _DAT_00fe36b8 = 0;
  _DAT_00fe36b4 = 0;
  if (DAT_00fe36bc != (void *)0x0) {
    _free(DAT_00fe36bc);
    DAT_00fe36bc = (void *)0x0;
  }
  _DAT_00fe36c4 = 0;
  _DAT_00fe36c0 = 0;
  if (DAT_00fe36c8 != (void *)0x0) {
    _free(DAT_00fe36c8);
    DAT_00fe36c8 = (void *)0x0;
  }
  _DAT_00fe36d0 = 0;
  _DAT_00fe36cc = 0;
  if (DAT_00fe36c8 != (void *)0x0) {
    _free(DAT_00fe36c8);
    DAT_00fe36c8 = (void *)0x0;
  }
  _DAT_00fe36d0 = 0;
  _DAT_00fe36cc = 0;
  if (DAT_00fe36bc != (void *)0x0) {
    _free(DAT_00fe36bc);
    DAT_00fe36bc = (void *)0x0;
  }
  _DAT_00fe36c4 = 0;
  _DAT_00fe36c0 = 0;
  if (DAT_00fe36b0 != (void *)0x0) {
    _free(DAT_00fe36b0);
    DAT_00fe36b0 = (void *)0x0;
  }
  _DAT_00fe36b4 = 0;
  _DAT_00fe36b8 = 0;
  ExceptionList = local_10;
  return;
}

