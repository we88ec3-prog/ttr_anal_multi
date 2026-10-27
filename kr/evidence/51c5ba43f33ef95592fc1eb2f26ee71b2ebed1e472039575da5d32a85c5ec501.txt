
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0053fbb0(void)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  char *_String;
  int iVar6;
  undefined4 uVar7;
  double dVar8;
  undefined1 auStack_bc [4];
  undefined4 *puStack_b8;
  float fStack_b4;
  int iStack_b0;
  int iStack_ac;
  float fStack_a8;
  undefined4 *puStack_a4;
  undefined **local_98 [19];
  uint local_4c;
  undefined4 uStack_3c;
  uint local_38;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009231cb;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_bc;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff38;
  ExceptionList = &local_14;
  FUN_0072ee30(local_98);
  local_c = 0;
  cVar1 = FUN_0072f110(0);
  if (cVar1 == '\0') goto LAB_0053fe2e;
  piVar3 = (int *)FUN_0072e2e0("ShoutTable");
  iVar4 = (**(code **)(*piVar3 + 0x14))(uVar2);
  if (iVar4 != 0) {
    iVar4 = FUN_007300a0(&DAT_00c0f4c8);
    if (iVar4 == 0) {
LAB_0053fc79:
      DAT_00fe18ec = 0;
    }
    else {
      puVar5 = (undefined4 *)(iVar4 + 0x30);
      if (0xf < *(uint *)(iVar4 + 0x44)) {
        puVar5 = (undefined4 *)*puVar5;
      }
      if (puVar5 == (undefined4 *)0x0) goto LAB_0053fc79;
      DAT_00fe18ec = FUN_008917b4(puVar5);
    }
    iVar4 = FUN_007300a0("freqdisp");
    if (iVar4 == 0) {
LAB_0053fca7:
      _DAT_00fe18f0 = 0;
    }
    else {
      puVar5 = (undefined4 *)(iVar4 + 0x30);
      if (0xf < *(uint *)(iVar4 + 0x44)) {
        puVar5 = (undefined4 *)*puVar5;
      }
      if (puVar5 == (undefined4 *)0x0) goto LAB_0053fca7;
      _DAT_00fe18f0 = FUN_008917b4(puVar5);
    }
    iVar4 = FUN_007300a0("slience");
    if (iVar4 != 0) {
      _String = (char *)(iVar4 + 0x30);
      if (0xf < *(uint *)(iVar4 + 0x44)) {
        _String = *(char **)_String;
      }
      if (_String != (char *)0x0) {
        dVar8 = _atof(_String);
        _DAT_00fe18f4 = (float)dVar8;
        fStack_b4 = _DAT_00fe18f4;
        goto LAB_0053fcea;
      }
    }
    _DAT_00fe18f4 = 0.0;
  }
LAB_0053fcea:
  for (piVar3 = (int *)piVar3[6]; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[0x10]) {
    iVar4 = (**(code **)(*piVar3 + 0x14))();
    if (iVar4 != 0) {
      iVar4 = FUN_007300a0(&DAT_00bed1d0);
      if (iVar4 == 0) {
LAB_0053fd37:
        fStack_b4 = 0.0;
      }
      else {
        puVar5 = (undefined4 *)(iVar4 + 0x30);
        if (0xf < *(uint *)(iVar4 + 0x44)) {
          puVar5 = (undefined4 *)*puVar5;
        }
        if (puVar5 == (undefined4 *)0x0) goto LAB_0053fd37;
        fStack_b4 = (float)FUN_008917b4(puVar5);
      }
      puStack_b8 = (undefined4 *)FUN_00891268(0x40);
      if (puStack_b8 == (undefined4 *)0x0) {
        puStack_b8 = (undefined4 *)0x0;
      }
      else {
        *puStack_b8 = 0;
        puStack_b8[1] = 0;
        puStack_b8[2] = 0;
        puStack_b8[4] = 0;
        puStack_b8[5] = 0;
        puStack_b8[6] = 0;
        puStack_b8[8] = 0;
        puStack_b8[9] = 0;
        puStack_b8[10] = 0;
        puStack_b8[0xc] = 0;
        puStack_b8[0xd] = 0;
        puStack_b8[0xe] = 0;
      }
      iVar4 = FUN_0072e2e0("Normal");
      iVar6 = FUN_0072e2e0("HasQuest");
      iStack_ac = FUN_0072e2e0("HasCompletableQuest");
      iStack_b0 = FUN_0072e2e0("HasScenario");
      if (iVar4 != 0) {
        FUN_0053feb0(puStack_b8);
      }
      puVar5 = puStack_b8;
      if (iVar6 != 0) {
        FUN_0053feb0(puStack_b8 + 4);
      }
      if (iStack_ac != 0) {
        FUN_0053feb0(puVar5 + 8);
      }
      if (iStack_b0 != 0) {
        FUN_0053feb0(puVar5 + 0xc);
      }
      puStack_a4 = puVar5;
      fStack_a8 = fStack_b4;
      uVar7 = FUN_0057ef20();
      FUN_0057e850(&DAT_00fe18dc,uVar7);
    }
  }
LAB_0053fe2e:
  local_c = 0xffffffff;
  local_98[0] = TiXmlDocument::vftable;
  if (0xf < local_38) {
    FUN_0089120c(local_4c);
  }
  local_38 = 0xf;
  uStack_3c = 0;
  local_4c = local_4c & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_bc);
  return;
}

