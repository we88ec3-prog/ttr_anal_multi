
void FUN_00bce1d0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00a081dd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  DAT_00fc7f20 = CUnionPartyMgr::vftable;
  local_8 = 1;
  FUN_0044e720(&DAT_00fcddcc,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_005540c0(*DAT_00fcddd0,DAT_00fcddd0);
  FUN_0089120c(DAT_00fcddd0);
  DAT_00fc7f20 = CPacketProcessor::vftable;
  ExceptionList = local_10;
  return;
}

