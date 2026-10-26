
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00862e60(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00908dab;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 2;
  FUN_00823850(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  pvVar1 = DAT_00fe34a0;
  if (DAT_00fe34a0 != DAT_00fe34a4) {
    FID_conflict__memcpy(DAT_00fe34a0,DAT_00fe34a4,0);
    DAT_00fe34a4 = pvVar1;
  }
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_005540c0(*DAT_00fe34cc,DAT_00fe34cc);
  FUN_0089120c(DAT_00fe34cc);
  FUN_008632f0();
  FUN_0089120c(DAT_00fe34b0);
  DAT_00fe34b0 = 0;
  if (DAT_00fe34a0 != (void *)0x0) {
    FUN_0089120c(DAT_00fe34a0);
  }
  DAT_00fe34a0 = (void *)0x0;
  DAT_00fe34a4 = (void *)0x0;
  _DAT_00fe34a8 = 0;
  ExceptionList = local_10;
  return;
}

