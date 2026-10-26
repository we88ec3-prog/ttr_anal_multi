
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00570ec0(void)

{
  uint uVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00927301;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  DAT_00fb1320 = 0;
  DAT_00fb1324 = 0;
  _DAT_00fb1328 = 0;
  DAT_00fb132c = 0;
  DAT_00fb1330 = 0;
  DAT_00fb1348 = 7;
  _DAT_00fb1344 = 0;
  DAT_00fb1334._0_2_ = 0;
  local_8 = 0;
  iVar2 = FUN_00891268(0x74,uVar1);
  local_8._0_1_ = 1;
  if (iVar2 == 0) {
    DAT_00fb1324 = 0;
  }
  else {
    DAT_00fb1324 = FUN_008fdaf0();
  }
  local_8._0_1_ = 0;
  iVar2 = FUN_00891268(0x128,uVar1);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (iVar2 == 0) {
    _DAT_00fb1328 = 0;
  }
  else {
    _DAT_00fb1328 = FUN_005763b0(iVar2);
  }
  ExceptionList = local_10;
  return &DAT_00fb1320;
}

