
/* WARNING: Removing unreachable block (ram,0x0049eab6) */
/* WARNING: Removing unreachable block (ram,0x0049e9b6) */
/* WARNING: Removing unreachable block (ram,0x0049ea36) */
/* WARNING: Removing unreachable block (ram,0x0049eaf0) */

void FUN_0049e8b0(void)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 local_4c;
  uint local_38;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_00929ff8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  local_14 = uVar1;
  FUN_00402a70("UnDotumBold.ttf",0xf);
  local_8._0_1_ = 1;
  uVar2 = FUN_0049ec80(local_30,uVar1);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_00402bb0(uVar2);
  if (0xf < local_38) {
    FUN_0089120c(local_4c);
  }
  local_8 = local_8 & 0xffffff00;
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  FUN_00440c60();
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  FUN_00402a70("UnGraphic.ttf",0xd);
  local_8._0_1_ = 3;
  uVar2 = FUN_0049ec80(local_30);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_00402bb0(uVar2);
  local_8 = local_8 & 0xffffff00;
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  FUN_00440c60();
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  FUN_00402a70("UnGraphicBold.ttf",0x11);
  local_8._0_1_ = 5;
  uVar2 = FUN_0049ec80(local_30);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_00402bb0(uVar2);
  local_8 = local_8 & 0xffffff00;
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  FUN_00440c60();
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  FUN_00402a70("UnJamoDotum.ttf",0xf);
  local_8._0_1_ = 7;
  uVar2 = FUN_0049ec80(local_30);
  local_8 = CONCAT31(local_8._1_3_,8);
  FUN_00402bb0(uVar2);
  local_8 = local_8 & 0xffffff00;
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  FUN_00440c60();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

