
void FUN_004076b0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090b9ab;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 2;
  FUN_00844c60(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (DAT_00faaf6c != 0) {
    FUN_0089120c(DAT_00faaf6c);
  }
  DAT_00faaf6c = 0;
  DAT_00faaf70 = 0;
  DAT_00faaf74 = 0;
  if (DAT_00faaf5c != 0) {
    FUN_0089120c(DAT_00faaf5c);
  }
  DAT_00faaf5c = 0;
  DAT_00faaf60 = 0;
  DAT_00faaf64 = 0;
  local_8 = 3;
  FUN_00535ac0(*DAT_00faaf50,DAT_00faaf50);
  FUN_0089120c(DAT_00faaf50);
  ExceptionList = local_10;
  return;
}

