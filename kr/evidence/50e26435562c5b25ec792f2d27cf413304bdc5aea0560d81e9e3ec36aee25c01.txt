
void FUN_00595ec0(void)

{
  uint uVar1;
  undefined4 *puVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00922d2c;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8 = 0;
    FUN_0058d410(uVar1);
    _atexit((_func_4879 *)&LAB_00bccdc0);
  }
  local_8 = 0xffffffff;
  puVar2 = DAT_00faafa8;
  if (DAT_00faafbc < 8) {
    puVar2 = &DAT_00faafa8;
  }
  FUN_0058de20(puVar2);
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8 = 1;
    FUN_0058d410(uVar1);
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_8 = 0xffffffff;
  }
  FUN_0058e350(&DAT_00faaf80);
  ExceptionList = local_10;
  return;
}

