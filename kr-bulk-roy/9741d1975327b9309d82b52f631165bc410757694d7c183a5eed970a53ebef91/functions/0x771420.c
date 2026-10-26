
undefined4 * FUN_00771420(undefined4 *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined **local_34 [3];
  char *local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091576a;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  *param_1 = FoxUI::FXUIManagerContainer<unsigned_int,FoxUI::FXUILocale>::vftable;
  puVar1 = param_1 + 1;
  param_1[3] = 0;
  iVar3 = FUN_00891268(0x18,uVar2);
  if (iVar3 != 0) {
    param_1[2] = iVar3;
    *(int *)iVar3 = iVar3;
    *(undefined4 *)(param_1[2] + 4) = param_1[2];
    *(undefined4 *)(param_1[2] + 8) = param_1[2];
    *(undefined1 *)(param_1[2] + 0x14) = 1;
    *(undefined1 *)(param_1[2] + 0x15) = 1;
    local_8 = 1;
    *param_1 = FoxUI::FXUILocaleManager::vftable;
    local_20 = FUN_00891268(0x3c,uVar2);
    local_8._0_1_ = 2;
    if (local_20 == 0) {
      local_18 = 0;
    }
    else {
      local_18 = FUN_00771340(local_20,&DAT_00c4dae4);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_1c = 0;
    FUN_0082ef00(&local_1c);
    if (local_20 == param_1[2]) {
      local_24 = 0;
      local_20 = local_18;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 3;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,&DAT_00c4db00);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 1;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 1;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 4;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,&DAT_00c4db18);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 2;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 2;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 5;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,&DAT_00c4db30);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 3;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 3;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 6;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,&DAT_00c4db50);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 4;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 4;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 7;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,&DAT_00c4db6c);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 5;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 5;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 8;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,L"ZH, ZH-CN");
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 6;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 6;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 9;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,L"ZH-TW");
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 7;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 7;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 10;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,&DAT_00c4dbe4);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 8;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 8;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0xb;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,&DAT_00c4dc00);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 9;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 9;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0xc;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,&DAT_00c4dc14);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 10;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 10;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0xd;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,&DAT_00c4dc2c);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0xb;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0xb;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0xe;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,L"EN-GB");
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0xc;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0xc;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0xf;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,L"EN, EN-US");
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0xd;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0xd;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0x10;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,&DAT_00c4dcc0);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0xe;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0xe;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0x11;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,&DAT_00c4dcdc);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0xf;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0xf;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0x12;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,&DAT_00c4dcf8);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0x10;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0x10;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0x13;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,L"FR, FR-FR");
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0x11;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0x11;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0x14;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,L"FR-CA");
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0x12;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0x12;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0x15;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,&DAT_00c4dd64);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0x13;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0x13;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0x16;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,&DAT_00c4dd7c);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0x14;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0x14;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0x17;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,L"HE, IW");
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0x15;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0x15;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0x18;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,&DAT_00c4ddb0);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0x16;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0x16;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0x19;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,&DAT_00c4ddcc);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0x17;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0x17;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0x1a;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,L"ID, IN");
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0x18;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0x18;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0x1b;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,&DAT_00c4de10);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0x19;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0x19;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0x1c;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,&DAT_00c4de28);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0x1a;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0x1a;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0x1d;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,&DAT_00c4de44);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0x1b;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0x1b;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0x1e;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,&DAT_00c4de5c);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0x1c;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0x1c;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0x1f;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,&DAT_00c4de74);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0x1d;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0x1d;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0x20;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,L"NEUTRAL");
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0x1e;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0x1e;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0x21;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,&DAT_00c4ded8);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0x1f;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0x1f;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0x22;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,&DAT_00c4def4);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0x20;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0x20;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0x23;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,&DAT_00c4df0c);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0x21;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0x21;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0x24;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,L"PT-BR");
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0x22;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0x22;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0x25;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,&DAT_00c4df60);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0x23;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0x23;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0x26;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,&DAT_00c4df7c);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0x24;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0x24;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0x27;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,&DAT_00c4df94);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0x25;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0x25;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0x28;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,&DAT_00c4dfac);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0x26;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0x26;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0x29;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,&DAT_00c4dfc4);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0x27;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0x27;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0x2a;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,L"ES, ES-ES");
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0x28;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0x28;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0x2b;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,&DAT_00c4e004);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0x29;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0x29;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0x2c;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,&DAT_00c4e01c);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0x2a;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0x2a;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0x2d;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,&DAT_00c4e030);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0x2b;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0x2b;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0x2e;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,&DAT_00c4e048);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0x2c;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0x2c;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    local_20 = FUN_00891268(0x3c);
    local_8._0_1_ = 0x2f;
    if (local_20 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00771340(local_20,&DAT_00c4e064);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    local_20 = 0x2d;
    FUN_0082ef00(&local_20);
    if (local_1c == param_1[2]) {
      local_24 = 0x2d;
      local_20 = iVar3;
      uVar4 = FUN_0057ef20();
      FUN_0082f200(puVar1,uVar4);
    }
    ExceptionList = local_10;
    return param_1;
  }
  local_28 = (char *)0x0;
  std::exception::exception((exception *)local_34,&local_28);
  local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_34,&DAT_00c857a8);
}

