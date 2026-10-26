
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00bc6ac0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00a05a0e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00402160(L"Logitech RumblePad 2 USB",0x18);
  local_8 = 0;
  DAT_00f743a8 = 7;
  _DAT_00f743a4 = 0;
  DAT_00f74394._0_2_ = 0;
  FUN_00402160(L"RumblePad",9);
  local_8 = CONCAT31(local_8._1_3_,1);
  DAT_00f743c4 = 0xf;
  _DAT_00f743c0 = 0;
  DAT_00f743b0._0_1_ = 0;
  FUN_00402a70("RumblePad2",10);
  local_8 = 2;
  _DAT_00f743cc = 0;
  _DAT_00f743e0 = 7;
  DAT_00f743dc = 0;
  FUN_00402160(L"Logitech Dual Action",0x14);
  local_8._0_1_ = 3;
  DAT_00f743fc = 7;
  _DAT_00f743f8 = 0;
  DAT_00f743e8._0_2_ = 0;
  FUN_00402160(L"Dual Action",0xb);
  local_8._0_1_ = 4;
  _DAT_00f74418 = 0xf;
  _DAT_00f74414 = 0;
  DAT_00f74404 = 0;
  FUN_00402a70("RumblePad2",10);
  local_8._0_1_ = 5;
  _DAT_00f74434 = 7;
  _DAT_00f74430 = 0;
  _DAT_00f74420 = 0;
  FUN_00402160(L"Hangame USB Gamepad",0x13);
  local_8._0_1_ = 6;
  _DAT_00f7443c = 0;
  _DAT_00f74450 = 7;
  _DAT_00f7444c = 0;
  FUN_00402160(L"Hangame",7);
  local_8._0_1_ = 7;
  _DAT_00f7446c = 0xf;
  _DAT_00f74468 = 0;
  DAT_00f74458 = 0;
  FUN_00402a70("HangamePad",10);
  local_8._0_1_ = 8;
  _DAT_00f74488 = 7;
  _DAT_00f74484 = 0;
  _DAT_00f74474 = 0;
  FUN_00402160(L"JOYTRON Super Dual Box PRO",0x1a);
  local_8._0_1_ = 9;
  _DAT_00f744a4 = 7;
  _DAT_00f744a0 = 0;
  _DAT_00f74490 = 0;
  FUN_00402160(L"JOYTRON",7);
  local_8 = CONCAT31(local_8._1_3_,10);
  _DAT_00f744c0 = 0xf;
  _DAT_00f744bc = 0;
  DAT_00f744ac = 0;
  FUN_00402a70("PS2JoyTron",10);
  _atexit((_func_4879 *)&LAB_00bd0620);
  ExceptionList = local_10;
  return;
}

