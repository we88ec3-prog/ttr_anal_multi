
void FUN_0083bdd0(LPCSTR param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  LPCSTR ***ppppCVar5;
  int *in_ECX;
  byte ****ppppbVar6;
  code *pcVar7;
  bool bVar8;
  undefined1 auStack_1ec [4];
  int *local_1e8;
  uint uStack_1e4;
  LPCSTR local_1e0;
  undefined4 uStack_1dc;
  LPCSTR **apppCStack_1d8 [4];
  undefined4 uStack_1c8;
  uint uStack_1c4;
  byte ***apppbStack_1bc [4];
  undefined4 uStack_1ac;
  uint uStack_1a8;
  undefined **local_1a0;
  undefined1 local_19c;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 local_174;
  int local_170;
  int local_16c;
  undefined4 local_168;
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_158;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined1 auStack_140 [292];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00918320;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_1ec;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffe08;
  ExceptionList = &local_14;
  local_1e0 = param_1;
  local_1a0 = GSArchive::vftable;
  local_188 = 0xf;
  local_18c = 0;
  local_19c = 0;
  local_17c = 0;
  local_178 = 0;
  local_174 = 0;
  local_170 = 0;
  local_16c = 0;
  local_168 = 0;
  local_160 = 0;
  local_15c = 0;
  local_158 = 0;
  local_180 = 0;
  local_148 = 0;
  local_144 = 0;
  local_150 = 0;
  local_14c = 0;
  local_c = 0;
  local_1e8 = in_ECX;
  iVar3 = FUN_00865ad0(param_1);
  if (iVar3 == 0) {
    OutputDebugStringA(&DAT_00c53ed8);
    OutputDebugStringA(local_1e0);
    OutputDebugStringA(&DAT_00c53ef8);
  }
  else {
    (**(code **)(*in_ECX + 0xb4))(uVar2);
    uStack_1e4 = (local_16c - local_170) / 0x11c;
    if (uStack_1e4 != 0) {
      uStack_1a8 = 0xf;
      uStack_1ac = 0;
      apppbStack_1bc[0] = (byte ***)((uint)apppbStack_1bc[0] & 0xffffff00);
      local_c = CONCAT31(local_c._1_3_,1);
      FUN_00865ca0(in_ECX + 0x6f,apppbStack_1bc);
      pcVar7 = OutputDebugStringA_exref;
      ppppbVar6 = (byte ****)apppbStack_1bc[0];
      if (uStack_1a8 < 0x10) {
        ppppbVar6 = apppbStack_1bc;
      }
      pcVar4 = "_gbDefaultStateBlock";
      do {
        bVar1 = *pcVar4;
        bVar8 = bVar1 < *(byte *)ppppbVar6;
        if (bVar1 != *(byte *)ppppbVar6) {
LAB_0083bf48:
          iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
          goto LAB_0083bf4d;
        }
        if (bVar1 == 0) break;
        bVar1 = pcVar4[1];
        bVar8 = bVar1 < *(byte *)((int)ppppbVar6 + 1);
        if (bVar1 != *(byte *)((int)ppppbVar6 + 1)) goto LAB_0083bf48;
        pcVar4 = pcVar4 + 2;
        ppppbVar6 = (byte ****)((int)ppppbVar6 + 2);
      } while (bVar1 != 0);
      iVar3 = 0;
LAB_0083bf4d:
      if (iVar3 != 0) {
        OutputDebugStringA("GBERROR: mismatch default state key\n");
      }
      if ((1 < uStack_1e4) && (uVar2 = 0, uStack_1e4 != 0)) {
        do {
          FUN_00842f30(auStack_140);
          uStack_1c4 = 0xf;
          uStack_1c8 = 0;
          apppCStack_1d8[0] = (LPCSTR **)((uint)apppCStack_1d8[0] & 0xffffff00);
          local_c = CONCAT31(local_c._1_3_,3);
          FUN_00865ca0(auStack_140,apppCStack_1d8);
          uStack_1dc = 0;
          ppppCVar5 = (LPCSTR ***)apppCStack_1d8[0];
          if (uStack_1c4 < 0x10) {
            ppppCVar5 = apppCStack_1d8;
          }
          iVar3 = (**(code **)(*local_1e8 + 0x124))(ppppCVar5,auStack_140,&uStack_1dc);
          if (iVar3 == 0) {
            OutputDebugStringA("IMPORT GMS ERROR: <REGISTER STATE BLOCK> : ");
            ppppCVar5 = (LPCSTR ***)apppCStack_1d8[0];
            if (uStack_1c4 < 0x10) {
              ppppCVar5 = apppCStack_1d8;
            }
            OutputDebugStringA((LPCSTR)ppppCVar5);
            OutputDebugStringA("\n");
          }
          if (0xf < uStack_1c4) {
            FUN_0089120c(apppCStack_1d8[0]);
          }
          uStack_1c4 = 0xf;
          uStack_1c8 = 0;
          apppCStack_1d8[0] = (LPCSTR **)((uint)apppCStack_1d8[0] & 0xffffff00);
          local_c = CONCAT31(local_c._1_3_,1);
          FUN_00843340(auStack_140);
          uVar2 = uVar2 + 1;
          pcVar7 = OutputDebugStringA_exref;
        } while (uVar2 < uStack_1e4);
      }
      (*pcVar7)(&DAT_00c53eb4);
      (*pcVar7)(uStack_1e4);
      (*pcVar7)(&DAT_00c411c0);
      FUN_008645b0(local_1e8 + 0x5e);
      if (0xf < uStack_1a8) {
        FUN_0089120c(apppbStack_1bc[0]);
      }
      uStack_1a8 = 0xf;
      uStack_1ac = 0;
      apppbStack_1bc[0] = (byte ***)((uint)apppbStack_1bc[0] & 0xffffff00);
      local_c = 0xffffffff;
      FUN_00865a00(&local_1a0);
      goto LAB_0083c0f5;
    }
  }
  local_c = 0xffffffff;
  FUN_00865a00(&local_1a0);
LAB_0083c0f5:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_1ec);
  return;
}

