
void FUN_00735190(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090caba;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_00736480(&DAT_00fb7b94,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (DAT_00fb7b78 != (undefined4 *)0x0) {
    (**(code **)*DAT_00fb7b78)(1);
    DAT_00fb7b78 = (undefined4 *)0x0;
  }
  if (DAT_00fb7ba8 != 0) {
    FUN_0089120c(DAT_00fb7ba8);
    DAT_00fb7ba8 = 0;
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_004ca160(*DAT_00fb7b98,DAT_00fb7b98);
  FUN_0089120c(DAT_00fb7b98);
  local_8 = 3;
  FUN_00736310(*DAT_00fb7b80,DAT_00fb7b80);
  FUN_0089120c(DAT_00fb7b80);
  ExceptionList = local_10;
  return;
}

