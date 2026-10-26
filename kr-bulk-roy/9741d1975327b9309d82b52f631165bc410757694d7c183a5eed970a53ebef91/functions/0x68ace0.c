
void FUN_0068ace0(void)

{
  undefined4 *puVar1;
  int unaff_EDI;
  undefined1 auStack_90 [4];
  undefined4 local_8c;
  undefined4 local_7c;
  uint local_78;
  undefined4 local_70;
  undefined4 local_60;
  uint local_5c;
  undefined4 local_54;
  undefined4 local_44;
  uint local_40;
  undefined1 local_38 [12];
  undefined1 local_2c [16];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009217dd;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_90;
  ExceptionList = &local_14;
  if (*(char *)(unaff_EDI + 0x141) != '\0') {
    FUN_006edb10("Not supported operation",DAT_00d61f20 ^ (uint)&stack0xffffff68);
  }
  local_40 = 7;
  local_44 = 0;
  local_54 = (undefined4 *)((uint)local_54._2_2_ << 0x10);
  FUN_004026e0(unaff_EDI + 0x108,0,0xffffffff);
  local_c = 0;
  FUN_00527300(local_38,unaff_EDI + 0x124);
  local_c = CONCAT31(local_c._1_3_,1);
  FUN_00527570(local_2c,unaff_EDI + 0x130);
  local_c = 2;
  local_78 = 7;
  local_7c = 0;
  local_8c = (uint)local_8c._2_2_ << 0x10;
  FUN_00402160(&DAT_00bed1fc,0);
  local_c._0_1_ = 3;
  local_5c = 7;
  local_60 = 0;
  local_70 = (uint)local_70._2_2_ << 0x10;
  FUN_00402160(&DAT_00c1ae14,1);
  local_c = CONCAT31(local_c._1_3_,4);
  FUN_00759330(&local_54,&local_70,&local_8c);
  if (7 < local_5c) {
    FUN_0089120c(local_70);
  }
  local_c = CONCAT31(local_c._1_3_,2);
  local_5c = 7;
  local_60 = 0;
  local_70 = local_70 & 0xffff0000;
  if (7 < local_78) {
    FUN_0089120c(local_8c);
  }
  local_78 = 7;
  local_7c = 0;
  local_8c = local_8c & 0xffff0000;
  if (*(char *)(unaff_EDI + 0x141) != '\0') {
    FUN_006edb10("Not supported operation");
  }
  FUN_00405300(unaff_EDI + 0x108);
  *(undefined4 *)(unaff_EDI + 0x168) = 0;
  *(undefined4 *)(unaff_EDI + 0x160) = 0;
  *(undefined4 *)(unaff_EDI + 0x164) = 0;
  puVar1 = local_54;
  if (local_40 < 8) {
    puVar1 = &local_54;
  }
  FUN_008935e3(puVar1);
  local_c = 0xffffffff;
  FUN_00757640(&local_54);
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_90);
  return;
}

