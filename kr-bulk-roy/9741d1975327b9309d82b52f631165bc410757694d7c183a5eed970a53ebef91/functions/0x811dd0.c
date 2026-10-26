
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_00811dd0(void)

{
  char cVar1;
  undefined4 uVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  bool bVar16;
  bool bVar17;
  bool bVar18;
  bool bVar19;
  bool bVar20;
  bool bVar21;
  bool bVar22;
  bool bVar23;
  bool bVar24;
  bool bVar25;
  bool bVar26;
  bool bVar27;
  bool bVar28;
  bool bVar29;
  bool bVar30;
  bool bVar31;
  bool bVar32;
  bool bVar33;
  
  bVar3 = true;
  uVar2 = alcGetCurrentContext();
  uVar2 = alcGetContextsDevice(uVar2);
  cVar1 = alcIsExtensionPresent(uVar2,"ALC_EXT_EFX");
  if (cVar1 != '\0') {
    _DAT_00fba86c = alGetProcAddress("alGenEffects");
    bVar3 = _DAT_00fba86c != 0;
    _DAT_00fba870 = alGetProcAddress("alDeleteEffects");
    bVar4 = _DAT_00fba870 != 0;
    _DAT_00fba874 = alGetProcAddress("alIsEffect");
    bVar5 = _DAT_00fba874 != 0;
    _DAT_00fba878 = alGetProcAddress("alEffecti");
    bVar6 = _DAT_00fba878 != 0;
    _DAT_00fba87c = alGetProcAddress("alEffectiv");
    bVar7 = _DAT_00fba87c != 0;
    _DAT_00fba880 = alGetProcAddress("alEffectf");
    bVar8 = _DAT_00fba880 != 0;
    _DAT_00fba884 = alGetProcAddress("alEffectfv");
    bVar9 = _DAT_00fba884 != 0;
    _DAT_00fba888 = alGetProcAddress("alGetEffecti");
    bVar10 = _DAT_00fba888 != 0;
    _DAT_00fba88c = alGetProcAddress("alGetEffectiv");
    bVar11 = _DAT_00fba88c != 0;
    _DAT_00fba890 = alGetProcAddress("alGetEffectf");
    bVar12 = _DAT_00fba890 != 0;
    _DAT_00fba894 = alGetProcAddress("alGetEffectfv");
    bVar13 = _DAT_00fba894 != 0;
    _DAT_00fba898 = alGetProcAddress("alGenFilters");
    bVar14 = _DAT_00fba898 != 0;
    _DAT_00fba89c = alGetProcAddress("alDeleteFilters");
    bVar15 = _DAT_00fba89c != 0;
    _DAT_00fba8a0 = alGetProcAddress("alIsFilter");
    bVar16 = _DAT_00fba8a0 != 0;
    _DAT_00fba8a4 = alGetProcAddress("alFilteri");
    bVar17 = _DAT_00fba8a4 != 0;
    _DAT_00fba8a8 = alGetProcAddress("alFilteriv");
    bVar18 = _DAT_00fba8a8 != 0;
    _DAT_00fba8ac = alGetProcAddress("alFilterf");
    bVar19 = _DAT_00fba8ac != 0;
    _DAT_00fba8b0 = alGetProcAddress("alFilterfv");
    bVar20 = _DAT_00fba8b0 != 0;
    _DAT_00fba8b4 = alGetProcAddress("alGetFilteri");
    bVar21 = _DAT_00fba8b4 != 0;
    _DAT_00fba8b8 = alGetProcAddress("alGetFilteriv");
    bVar22 = _DAT_00fba8b8 != 0;
    _DAT_00fba8bc = alGetProcAddress("alGetFilterf");
    bVar23 = _DAT_00fba8bc != 0;
    _DAT_00fba8c0 = alGetProcAddress("alGetFilterfv");
    bVar24 = _DAT_00fba8c0 != 0;
    _DAT_00fba8c4 = alGetProcAddress("alGenAuxiliaryEffectSlots");
    bVar25 = _DAT_00fba8c4 != 0;
    _DAT_00fba8c8 = alGetProcAddress("alDeleteAuxiliaryEffectSlots");
    bVar26 = _DAT_00fba8c8 != 0;
    _DAT_00fba8cc = alGetProcAddress("alIsAuxiliaryEffectSlot");
    bVar27 = _DAT_00fba8cc != 0;
    _DAT_00fba8d0 = alGetProcAddress("alAuxiliaryEffectSloti");
    bVar28 = _DAT_00fba8d0 != 0;
    _DAT_00fba8d4 = alGetProcAddress("alAuxiliaryEffectSlotiv");
    bVar29 = _DAT_00fba8d4 != 0;
    _DAT_00fba8d8 = alGetProcAddress("alAuxiliaryEffectSlotf");
    bVar30 = _DAT_00fba8d8 != 0;
    _DAT_00fba8dc = alGetProcAddress("alAuxiliaryEffectSlotfv");
    bVar31 = _DAT_00fba8dc != 0;
    _DAT_00fba8e0 = alGetProcAddress("alGetAuxiliaryEffectSloti");
    bVar32 = _DAT_00fba8e0 != 0;
    _DAT_00fba8e4 = alGetProcAddress("alGetAuxiliaryEffectSlotiv");
    bVar33 = _DAT_00fba8e4 != 0;
    _DAT_00fba8e8 = alGetProcAddress("alGetAuxiliaryEffectSlotf");
    bVar3 = _DAT_00fba8e8 != 0 &&
            (bVar33 &&
            (bVar32 &&
            (bVar31 &&
            (bVar30 &&
            (bVar29 &&
            (bVar28 &&
            (bVar27 &&
            (bVar26 &&
            (bVar25 &&
            (bVar24 &&
            (bVar23 &&
            (bVar22 &&
            (bVar21 &&
            (bVar20 &&
            (bVar19 &&
            (bVar18 &&
            (bVar17 &&
            (bVar16 &&
            (bVar15 &&
            (bVar14 &&
            (bVar13 &&
            (bVar12 &&
            (bVar11 &&
            (bVar10 && (bVar9 && (bVar8 && (bVar7 && (bVar6 && (bVar5 && (bVar4 && bVar3))))))))))))
            ))))))))))))))))));
    _DAT_00fba8ec = alGetProcAddress("alGetAuxiliaryEffectSlotfv");
    if (_DAT_00fba8ec == 0) {
      return false;
    }
  }
  return bVar3;
}

