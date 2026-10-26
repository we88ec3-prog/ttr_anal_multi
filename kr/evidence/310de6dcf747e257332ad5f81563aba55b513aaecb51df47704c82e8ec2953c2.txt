
void FUN_005877f0(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 *local_1c;
  int local_18 [2];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar2 = (int)param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091fb66;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1 = _malloc(0x168);
  local_8 = 0;
  if (param_1 == (void *)0x0) {
    param_1 = (undefined4 *)0x0;
  }
  else {
    param_1 = (undefined4 *)FUN_005a7090(uVar4);
  }
  local_8 = 0xffffffff;
  iVar1 = *(int *)(iVar2 + 0x2c);
  local_18[0] = 0;
  FUN_0082ef00(local_18);
  if (local_1c == *(undefined4 **)(iVar1 + 8)) {
    local_1c = param_1;
    uVar5 = FUN_0057ef20();
    FUN_0082f200(iVar1 + 4,uVar5);
  }
  puVar6 = _malloc(0x148);
  local_8 = 1;
  if (puVar6 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)0x0;
  }
  else {
    param_1 = puVar6;
    FUN_00595a60(puVar6);
    *puVar6 = FUI::CExpeditionPage::vftable;
    puVar6[0x4d] = 0;
    puVar6[0x4e] = 0;
    puVar6[0x4f] = 0;
    puVar6[0x50] = 0;
    puVar6[0x51] = 0;
    param_1 = puVar6;
  }
  local_8 = 0xffffffff;
  iVar1 = *(int *)(iVar2 + 0x2c);
  local_1c = (undefined4 *)0x1;
  FUN_0082ef00(&local_1c);
  if (local_18[0] == *(int *)(iVar1 + 8)) {
    local_1c = param_1;
    uVar5 = FUN_0057ef20();
    FUN_0082f200(iVar1 + 4,uVar5);
  }
  param_1 = _malloc(800);
  local_8 = 2;
  if (param_1 == (void *)0x0) {
    param_1 = (undefined4 *)0x0;
  }
  else {
    param_1 = (undefined4 *)FUN_005b2670();
  }
  local_8 = 0xffffffff;
  iVar1 = *(int *)(iVar2 + 0x2c);
  local_1c = (undefined4 *)0x2;
  FUN_0082ef00(&local_1c);
  if (local_18[0] == *(int *)(iVar1 + 8)) {
    local_1c = param_1;
    uVar5 = FUN_0057ef20();
    FUN_0082f200(iVar1 + 4,uVar5);
  }
  puVar6 = _malloc(0x314);
  local_8 = 3;
  if (puVar6 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)0x0;
  }
  else {
    param_1 = puVar6;
    FUN_005b5020(puVar6);
    puVar6[0xbe] = 0;
    *puVar6 = FUI::CDuelSquarePage::vftable;
    puVar6[0xbf] = 0;
    puVar6[0xc0] = 0;
    puVar6[0xc1] = 0;
    puVar6[0xc3] = 0;
    puVar6[0xc4] = 0;
    param_1 = puVar6;
  }
  local_8 = 0xffffffff;
  iVar1 = *(int *)(iVar2 + 0x2c);
  local_1c = (undefined4 *)0x3;
  FUN_0082ef00(&local_1c);
  if (local_18[0] == *(int *)(iVar1 + 8)) {
    local_1c = param_1;
    uVar5 = FUN_0057ef20();
    FUN_0082f200(iVar1 + 4,uVar5);
  }
  puVar6 = _malloc(0x30c);
  local_8 = 4;
  if (puVar6 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)0x0;
  }
  else {
    param_1 = puVar6;
    FUN_005b5020(puVar6);
    puVar6[0xbe] = 0;
    *puVar6 = FUI::CMissionLobbyPage::vftable;
    puVar6[0xbf] = 0;
    puVar6[0xc0] = 0;
    puVar6[0xc1] = 0;
    puVar6[0xc2] = 0;
    param_1 = puVar6;
  }
  local_8 = 0xffffffff;
  iVar1 = *(int *)(iVar2 + 0x2c);
  local_1c = (undefined4 *)0x4;
  FUN_0082ef00(&local_1c);
  if (local_18[0] == *(int *)(iVar1 + 8)) {
    local_1c = param_1;
    uVar5 = FUN_0057ef20();
    FUN_0082f200(iVar1 + 4,uVar5);
  }
  param_1 = _malloc(0x25c);
  local_8 = 5;
  if (param_1 == (void *)0x0) {
    param_1 = (undefined4 *)0x0;
  }
  else {
    param_1 = (undefined4 *)FUN_005accf0(param_1);
  }
  local_8 = 0xffffffff;
  iVar1 = *(int *)(iVar2 + 0x2c);
  local_1c = (undefined4 *)0x5;
  FUN_0082ef00(&local_1c);
  if (local_18[0] == *(int *)(iVar1 + 8)) {
    local_1c = param_1;
    uVar5 = FUN_0057ef20();
    FUN_0082f200(iVar1 + 4,uVar5);
  }
  puVar6 = _malloc(0x170);
  local_8 = 6;
  if (puVar6 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)0x0;
  }
  else {
    param_1 = puVar6;
    FUN_005a38f0();
    *puVar6 = FUI::CMissionResultPage::vftable;
    puVar6[0x5b] = 0;
    puVar6[0x59] = 0;
    puVar6[0x5a] = 0;
    param_1 = puVar6;
  }
  local_8 = 0xffffffff;
  iVar1 = *(int *)(iVar2 + 0x2c);
  local_1c = (undefined4 *)0x6;
  FUN_0082ef00(&local_1c);
  if (local_18[0] == *(int *)(iVar1 + 8)) {
    local_1c = param_1;
    uVar5 = FUN_0057ef20();
    FUN_0082f200(iVar1 + 4,uVar5);
  }
  puVar6 = _malloc(0x240);
  local_8 = 7;
  if (puVar6 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)0x0;
  }
  else {
    param_1 = puVar6;
    FUN_00598760();
    puVar6[0x87] = 0;
    puVar6[0x88] = 0;
    *puVar6 = FUI::CDuelFieldPage::vftable;
    puVar6[0x8a] = 0;
    puVar6[0x8b] = 0;
    *(undefined1 *)(puVar6 + 0x8c) = 0;
    puVar6[0x8d] = 0;
    puVar6[0x8e] = 0;
    param_1 = puVar6;
  }
  local_8 = 0xffffffff;
  iVar1 = *(int *)(iVar2 + 0x2c);
  local_1c = (undefined4 *)0xa;
  FUN_0082ef00(&local_1c);
  if (local_18[0] == *(int *)(iVar1 + 8)) {
    local_1c = param_1;
    uVar5 = FUN_0057ef20();
    FUN_0082f200(iVar1 + 4,uVar5);
  }
  puVar6 = _malloc(0x168);
  local_8 = 8;
  if (puVar6 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)0x0;
  }
  else {
    param_1 = puVar6;
    FUN_005a38f0();
    *puVar6 = FUI::CDuelResultPage::vftable;
    puVar6[0x59] = 0;
    param_1 = puVar6;
  }
  local_8 = 0xffffffff;
  iVar1 = *(int *)(iVar2 + 0x2c);
  local_1c = (undefined4 *)0xb;
  FUN_0082ef00(&local_1c);
  if (local_18[0] == *(int *)(iVar1 + 8)) {
    local_1c = param_1;
    uVar5 = FUN_0057ef20();
    FUN_0082f200(iVar1 + 4,uVar5);
  }
  puVar6 = _malloc(0x16c);
  local_8 = 9;
  if (puVar6 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)0x0;
  }
  else {
    param_1 = puVar6;
    FUN_005a38f0();
    *puVar6 = FUI::CGvGDuelResultPage::vftable;
    puVar6[0x59] = 0;
    param_1 = puVar6;
  }
  local_8 = 0xffffffff;
  iVar1 = *(int *)(iVar2 + 0x2c);
  local_1c = (undefined4 *)0xc;
  FUN_0082ef00(&local_1c);
  if (local_18[0] == *(int *)(iVar1 + 8)) {
    local_1c = param_1;
    uVar5 = FUN_0057ef20();
    FUN_0082f200(iVar1 + 4,uVar5);
  }
  puVar6 = _malloc(0x314);
  local_8 = 10;
  if (puVar6 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)0x0;
  }
  else {
    param_1 = puVar6;
    FUN_005b5020(puVar6);
    puVar6[0xbe] = 0;
    *puVar6 = FUI::CDuelLobbyPage::vftable;
    puVar6[0xbf] = 0;
    puVar6[0xc0] = 0;
    puVar6[0xc1] = 0;
    puVar6[0xc3] = 0;
    *(undefined1 *)(puVar6 + 0xc4) = 0;
    param_1 = puVar6;
  }
  local_8 = 0xffffffff;
  iVar1 = *(int *)(iVar2 + 0x2c);
  local_1c = (undefined4 *)0x9;
  FUN_0082ef00(&local_1c);
  if (local_18[0] == *(int *)(iVar1 + 8)) {
    local_1c = param_1;
    uVar5 = FUN_0057ef20();
    FUN_0082f200(iVar1 + 4,uVar5);
  }
  puVar6 = _malloc(0x308);
  local_8 = 0xb;
  if (puVar6 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)0x0;
  }
  else {
    param_1 = puVar6;
    FUN_005b5020(puVar6);
    puVar6[0xbe] = 0;
    *puVar6 = FUI::CRaidLobbyPage::vftable;
    puVar6[0xbf] = 0;
    puVar6[0xc0] = 0;
    puVar6[0xc1] = 0;
    param_1 = puVar6;
  }
  local_8 = 0xffffffff;
  iVar1 = *(int *)(iVar2 + 0x2c);
  local_1c = (undefined4 *)0xd;
  FUN_0082ef00(&local_1c);
  if (local_18[0] == *(int *)(iVar1 + 8)) {
    local_1c = param_1;
    uVar5 = FUN_0057ef20();
    FUN_0082f200(iVar1 + 4,uVar5);
  }
  puVar6 = _malloc(0x170);
  local_8 = 0xc;
  if (puVar6 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)0x0;
  }
  else {
    param_1 = puVar6;
    FUN_005a38f0();
    *puVar6 = FUI::CRaidResultPage::vftable;
    puVar6[0x5b] = 0;
    param_1 = puVar6;
  }
  local_8 = 0xffffffff;
  iVar1 = *(int *)(iVar2 + 0x2c);
  local_1c = (undefined4 *)0xe;
  FUN_0082ef00(&local_1c);
  if (local_18[0] == *(int *)(iVar1 + 8)) {
    local_1c = param_1;
    uVar5 = FUN_0057ef20();
    FUN_0082f200(iVar1 + 4,uVar5);
  }
  puVar6 = _malloc(0x230);
  local_8 = 0xd;
  if (puVar6 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)0x0;
  }
  else {
    param_1 = puVar6;
    FUN_00598760();
    puVar6[0x87] = 0;
    puVar6[0x88] = 0;
    *puVar6 = FUI::CScenarioFieldPage::vftable;
    puVar6[0x89] = 0;
    puVar6[0x8a] = 0;
    param_1 = puVar6;
  }
  local_8 = 0xffffffff;
  iVar1 = *(int *)(iVar2 + 0x2c);
  local_1c = (undefined4 *)0x7;
  FUN_0082ef00(&local_1c);
  if (local_18[0] == *(int *)(iVar1 + 8)) {
    local_1c = param_1;
    uVar5 = FUN_0057ef20();
    FUN_0082f200(iVar1 + 4,uVar5);
  }
  puVar6 = _malloc(0x16c);
  local_8 = 0xe;
  if (puVar6 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)0x0;
  }
  else {
    param_1 = puVar6;
    FUN_005a38f0();
    *puVar6 = FUI::CScenarioResultPage::vftable;
    puVar6[0x59] = 0;
    puVar6[0x5a] = 0;
    param_1 = puVar6;
  }
  local_8 = 0xffffffff;
  iVar1 = *(int *)(iVar2 + 0x2c);
  local_1c = (undefined4 *)0x8;
  FUN_0082ef00(&local_1c);
  if (local_18[0] == *(int *)(iVar1 + 8)) {
    local_1c = param_1;
    uVar5 = FUN_0057ef20();
    FUN_0082f200(iVar1 + 4,uVar5);
  }
  puVar6 = _malloc(0x234);
  local_8 = 0xf;
  if (puVar6 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)0x0;
  }
  else {
    param_1 = puVar6;
    FUN_00598760();
    *puVar6 = FUI::CTutorialPage::vftable;
    puVar6[0x87] = 0;
    puVar6[0x88] = 0;
    puVar6[0x89] = 0;
    puVar6[0x8a] = 0;
    puVar6[0x8b] = 0;
    puVar6[0x8c] = 0;
    param_1 = puVar6;
  }
  local_8 = 0xffffffff;
  iVar1 = *(int *)(iVar2 + 0x2c);
  local_1c = (undefined4 *)0xf;
  FUN_0082ef00(&local_1c);
  if (local_18[0] == *(int *)(iVar1 + 8)) {
    local_1c = param_1;
    uVar5 = FUN_0057ef20();
    FUN_0082f200(iVar1 + 4,uVar5);
  }
  puVar6 = _malloc(0x22c);
  local_8 = 0x10;
  if (puVar6 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)0x0;
  }
  else {
    param_1 = puVar6;
    FUN_00598760();
    puVar6[0x87] = 0;
    puVar6[0x88] = 0;
    *puVar6 = FUI::CTutorialFieldPage::vftable;
    puVar6[0x89] = 0;
    puVar6[0x8a] = 0;
    param_1 = puVar6;
  }
  local_8 = 0xffffffff;
  iVar1 = *(int *)(iVar2 + 0x2c);
  local_1c = (undefined4 *)0x10;
  FUN_0082ef00(&local_1c);
  if (local_18[0] == *(int *)(iVar1 + 8)) {
    local_1c = param_1;
    uVar5 = FUN_0057ef20();
    FUN_0082f200(iVar1 + 4,uVar5);
  }
  puVar6 = _malloc(0x234);
  local_8 = 0x11;
  if (puVar6 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)0x0;
  }
  else {
    param_1 = puVar6;
    FUN_00598760();
    puVar6[0x87] = 0;
    puVar6[0x88] = 0;
    *puVar6 = FUI::CInfiniteDungeonFieldPage::vftable;
    puVar6[0x89] = 0;
    puVar6[0x8a] = 0;
    puVar6[0x8b] = 0;
    param_1 = puVar6;
  }
  local_8 = 0xffffffff;
  iVar1 = *(int *)(iVar2 + 0x2c);
  local_1c = (undefined4 *)&DAT_00000011;
  FUN_0082ef00(&local_1c);
  if (local_18[0] == *(int *)(iVar1 + 8)) {
    local_1c = param_1;
    uVar5 = FUN_0057ef20();
    FUN_0082f200(iVar1 + 4,uVar5);
  }
  puVar6 = _malloc(0x168);
  local_8 = 0x12;
  if (puVar6 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)0x0;
  }
  else {
    param_1 = puVar6;
    FUN_005a38f0();
    *puVar6 = FUI::CInfiniteDungeonResultPage::vftable;
    puVar6[0x59] = 0;
    param_1 = puVar6;
  }
  local_8 = 0xffffffff;
  iVar1 = *(int *)(iVar2 + 0x2c);
  local_1c = (undefined4 *)0x12;
  FUN_0082ef00(&local_1c);
  if (local_18[0] == *(int *)(iVar1 + 8)) {
    local_1c = param_1;
    uVar5 = FUN_0057ef20();
    FUN_0082f200(iVar1 + 4,uVar5);
  }
  puVar6 = _malloc(0x230);
  local_8 = 0x13;
  if (puVar6 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)0x0;
  }
  else {
    param_1 = puVar6;
    FUN_00598760();
    puVar6[0x87] = 0;
    puVar6[0x88] = 0;
    *puVar6 = FUI::CEternalTowerFieldPage::vftable;
    puVar6[0x89] = 0;
    puVar6[0x8a] = 0;
    puVar6[0x8b] = 0;
    param_1 = puVar6;
  }
  local_8 = 0xffffffff;
  iVar1 = *(int *)(iVar2 + 0x2c);
  local_1c = (undefined4 *)0x13;
  FUN_0082ef00(&local_1c);
  if (local_18[0] == *(int *)(iVar1 + 8)) {
    local_1c = param_1;
    uVar5 = FUN_0057ef20();
    FUN_0082f200(iVar1 + 4,uVar5);
  }
  puVar6 = _malloc(0x168);
  local_8 = 0x14;
  if (puVar6 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)0x0;
  }
  else {
    param_1 = puVar6;
    FUN_005a38f0();
    *puVar6 = FUI::CEternalTowerResultPage::vftable;
    puVar6[0x59] = 0;
    param_1 = puVar6;
  }
  local_8 = 0xffffffff;
  iVar1 = *(int *)(iVar2 + 0x2c);
  local_1c = (undefined4 *)&DAT_00000014;
  FUN_0082ef00(&local_1c);
  if (local_18[0] == *(int *)(iVar1 + 8)) {
    local_1c = param_1;
    uVar5 = FUN_0057ef20();
    FUN_0082f200(iVar1 + 4,uVar5);
  }
  puVar6 = _malloc(0x304);
  local_8 = 0x15;
  if (puVar6 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)0x0;
  }
  else {
    param_1 = puVar6;
    FUN_005b5020(puVar6);
    puVar6[0xbe] = 0;
    *puVar6 = FUI::CDailyDungeonLobbyPage::vftable;
    puVar6[0xbf] = 0;
    puVar6[0xc0] = 0;
    param_1 = puVar6;
  }
  local_8 = 0xffffffff;
  iVar1 = *(int *)(iVar2 + 0x2c);
  local_1c = (undefined4 *)0x15;
  FUN_0082ef00(&local_1c);
  if (local_18[0] == *(int *)(iVar1 + 8)) {
    local_1c = param_1;
    uVar5 = FUN_0057ef20();
    FUN_0082f200(iVar1 + 4,uVar5);
  }
  puVar6 = _malloc(0x168);
  local_8 = 0x16;
  if (puVar6 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)0x0;
  }
  else {
    param_1 = puVar6;
    FUN_005a38f0();
    *puVar6 = FUI::CDailyDungeonResultPage::vftable;
    puVar6[0x59] = 0;
    param_1 = puVar6;
  }
  local_8 = 0xffffffff;
  iVar1 = *(int *)(iVar2 + 0x2c);
  local_1c = (undefined4 *)0x16;
  FUN_0082ef00(&local_1c);
  if (local_18[0] == *(int *)(iVar1 + 8)) {
    local_1c = param_1;
    uVar5 = FUN_0057ef20();
    FUN_0082f200(iVar1 + 4,uVar5);
  }
  iVar1 = *(int *)(iVar2 + 0x2c);
  *(undefined4 *)(iVar2 + 0x14) = 0;
  param_1 = (undefined4 *)0x0;
  FUN_0082ef00(&param_1);
  if (local_1c == *(undefined4 **)(iVar1 + 8)) {
    piVar7 = (int *)0x0;
  }
  else {
    piVar7 = (int *)local_1c[4];
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 0x17;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = 0xffffffff;
  }
  piVar3 = DAT_00f95bd4;
  if (DAT_00f95bd4 != piVar7) {
    if (DAT_00f95bd4 != (int *)0x0) {
      FUN_007486f0(0);
    }
    piVar3 = piVar7;
    if (piVar7 != (int *)0x0) {
      FUN_007486f0(&DAT_00f94810);
    }
  }
  DAT_00f95bd4 = piVar3;
  (**(code **)(*piVar7 + 0x108))();
  local_1c = *(undefined4 **)(*(int *)(iVar2 + 0x24) + 0xa4);
  (**(code **)(*piVar7 + 0xbc))(0,0,*(undefined4 *)(*(int *)(iVar2 + 0x24) + 0xa0),local_1c);
  (**(code **)(*piVar7 + 200))();
  ExceptionList = local_10;
  return;
}

