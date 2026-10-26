
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007d2170(void)

{
  float fVar1;
  uint uVar2;
  UINT UVar3;
  uint local_4c [4];
  undefined4 local_3c;
  uint local_38;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00914b08;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  local_14 = uVar2;
  FUN_00402a70("LightMelee",10);
  local_8 = 0;
  FUN_00402bb0(local_30);
  local_8 = 0xffffffff;
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0],uVar2);
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  FUN_00402a70("MediumMelee",0xb);
  local_8 = 1;
  FUN_00402bb0(local_30);
  local_8 = 0xffffffff;
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  FUN_00402a70("HeavyMelee",10);
  local_8 = 2;
  FUN_00402bb0(local_30);
  local_8 = 0xffffffff;
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  FUN_00402a70("Ranged",6);
  local_8 = 3;
  FUN_00402bb0(local_30);
  local_8 = 0xffffffff;
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  local_38 = 0xf;
  local_3c = 0;
  local_4c[0] = local_4c[0] & 0xffffff00;
  FUN_00402a70("Unused",6);
  local_8 = 4;
  FUN_00402bb0(local_4c);
  if (0xf < local_38) {
    FUN_0089120c(local_4c[0]);
  }
  UVar3 = GetPrivateProfileIntA("LIGHT_MELEE","NORMAL-VALUE",2000,"./FrameControl.ini");
  fVar1 = (float)(int)UVar3;
  if ((int)UVar3 < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  DAT_00fbab80 = fVar1 * 0.001;
  UVar3 = GetPrivateProfileIntA("LIGHT_MELEE","NORMAL-RATIO",0x2ee,"./FrameControl.ini");
  fVar1 = (float)(int)UVar3;
  if ((int)UVar3 < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  DAT_00fbab8c = fVar1 * 0.001;
  UVar3 = GetPrivateProfileIntA("LIGHT_MELEE","CRITICAL-VALUE",3000,"./FrameControl.ini");
  fVar1 = (float)(int)UVar3;
  if ((int)UVar3 < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  DAT_00fbab88 = fVar1 * 0.001;
  UVar3 = GetPrivateProfileIntA("LIGHT_MELEE","CRITICAL-RATIO",0x352,"./FrameControl.ini");
  fVar1 = (float)(int)UVar3;
  if ((int)UVar3 < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  DAT_00fbab94 = fVar1 * 0.001;
  UVar3 = GetPrivateProfileIntA("LIGHT_MELEE","BLOCKED-VALUE",1000,"./FrameControl.ini");
  fVar1 = (float)(int)UVar3;
  if ((int)UVar3 < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  DAT_00fbab84 = fVar1 * 0.001;
  UVar3 = GetPrivateProfileIntA("LIGHT_MELEE","BLOCKED-RATIO",0x2ee,"./FrameControl.ini");
  fVar1 = (float)(int)UVar3;
  if ((int)UVar3 < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  DAT_00fbab90 = fVar1 * 0.001;
  UVar3 = GetPrivateProfileIntA("MEDIUM_MELEE","NORMAL-VALUE",2000,"./FrameControl.ini");
  fVar1 = (float)(int)UVar3;
  if ((int)UVar3 < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  DAT_00fbab98 = fVar1 * 0.001;
  UVar3 = GetPrivateProfileIntA("MEDIUM_MELEE","NORMAL-RATIO",0x352,"./FrameControl.ini");
  fVar1 = (float)(int)UVar3;
  if ((int)UVar3 < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  DAT_00fbaba4 = fVar1 * 0.001;
  UVar3 = GetPrivateProfileIntA("MEDIUM_MELEE","CRITICAL-VALUE",3000,"./FrameControl.ini");
  fVar1 = (float)(int)UVar3;
  if ((int)UVar3 < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  DAT_00fbaba0 = fVar1 * 0.001;
  UVar3 = GetPrivateProfileIntA("MEDIUM_MELEE","CRITICAL-RATIO",900,"./FrameControl.ini");
  fVar1 = (float)(int)UVar3;
  if ((int)UVar3 < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  DAT_00fbabac = fVar1 * 0.001;
  UVar3 = GetPrivateProfileIntA("MEDIUM_MELEE","BLOCKED-VALUE",2000,"./FrameControl.ini");
  fVar1 = (float)(int)UVar3;
  if ((int)UVar3 < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  DAT_00fbab9c = fVar1 * 0.001;
  UVar3 = GetPrivateProfileIntA("MEDIUM_MELEE","BLOCKED-RATIO",900,"./FrameControl.ini");
  fVar1 = (float)(int)UVar3;
  if ((int)UVar3 < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  DAT_00fbaba8 = fVar1 * 0.001;
  UVar3 = GetPrivateProfileIntA("HEAVY_MELEE","NORMAL-VALUE",2000,"./FrameControl.ini");
  _DAT_00fbabb0 = (float)(int)UVar3;
  if ((int)UVar3 < 0) {
    _DAT_00fbabb0 = _DAT_00fbabb0 + 4.2949673e+09;
  }
  _DAT_00fbabb0 = _DAT_00fbabb0 * 0.001;
  UVar3 = GetPrivateProfileIntA("HEAVY_MELEE","NORMAL-RATIO",900,"./FrameControl.ini");
  _DAT_00fbabbc = (float)(int)UVar3;
  if ((int)UVar3 < 0) {
    _DAT_00fbabbc = _DAT_00fbabbc + 4.2949673e+09;
  }
  _DAT_00fbabbc = _DAT_00fbabbc * 0.001;
  UVar3 = GetPrivateProfileIntA("HEAVY_MELEE","CRITICAL-VALUE",3000,"./FrameControl.ini");
  _DAT_00fbabb8 = (float)(int)UVar3;
  if ((int)UVar3 < 0) {
    _DAT_00fbabb8 = _DAT_00fbabb8 + 4.2949673e+09;
  }
  _DAT_00fbabb8 = _DAT_00fbabb8 * 0.001;
  UVar3 = GetPrivateProfileIntA("HEAVY_MELEE","CRITICAL-RATIO",0x3d4,"./FrameControl.ini");
  _DAT_00fbabc4 = (float)(int)UVar3;
  if ((int)UVar3 < 0) {
    _DAT_00fbabc4 = _DAT_00fbabc4 + 4.2949673e+09;
  }
  _DAT_00fbabc4 = _DAT_00fbabc4 * 0.001;
  UVar3 = GetPrivateProfileIntA("HEAVY_MELEE","BLOCKED-VALUE",1000,"./FrameControl.ini");
  _DAT_00fbabb4 = (float)(int)UVar3;
  if ((int)UVar3 < 0) {
    _DAT_00fbabb4 = _DAT_00fbabb4 + 4.2949673e+09;
  }
  _DAT_00fbabb4 = _DAT_00fbabb4 * 0.001;
  UVar3 = GetPrivateProfileIntA("HEAVY_MELEE","BLOCKED-RATIO",0x3d4,"./FrameControl.ini");
  _DAT_00fbabc0 = (float)(int)UVar3;
  if ((int)UVar3 < 0) {
    _DAT_00fbabc0 = _DAT_00fbabc0 + 4.2949673e+09;
  }
  _DAT_00fbabc0 = _DAT_00fbabc0 * 0.001;
  UVar3 = GetPrivateProfileIntA("RANGED","NORMAL-VALUE",1000,"./FrameControl.ini");
  _DAT_00fbabc8 = (float)(int)UVar3;
  if ((int)UVar3 < 0) {
    _DAT_00fbabc8 = _DAT_00fbabc8 + 4.2949673e+09;
  }
  _DAT_00fbabc8 = _DAT_00fbabc8 * 0.001;
  UVar3 = GetPrivateProfileIntA("RANGED","NORMAL-RATIO",0,"./FrameControl.ini");
  _DAT_00fbabd4 = (float)(int)UVar3;
  if ((int)UVar3 < 0) {
    _DAT_00fbabd4 = _DAT_00fbabd4 + 4.2949673e+09;
  }
  _DAT_00fbabd4 = _DAT_00fbabd4 * 0.001;
  UVar3 = GetPrivateProfileIntA("RANGED","CRITICAL-VALUE",1000,"./FrameControl.ini");
  _DAT_00fbabd0 = (float)(int)UVar3;
  if ((int)UVar3 < 0) {
    _DAT_00fbabd0 = _DAT_00fbabd0 + 4.2949673e+09;
  }
  _DAT_00fbabd0 = _DAT_00fbabd0 * 0.001;
  UVar3 = GetPrivateProfileIntA("RANGED","CRITICAL-RATIO",500,"./FrameControl.ini");
  _DAT_00fbabdc = (float)(int)UVar3;
  if ((int)UVar3 < 0) {
    _DAT_00fbabdc = _DAT_00fbabdc + 4.2949673e+09;
  }
  _DAT_00fbabdc = _DAT_00fbabdc * 0.001;
  UVar3 = GetPrivateProfileIntA("RANGED","BLOCKED-VALUE",0,"./FrameControl.ini");
  _DAT_00fbabcc = (float)(int)UVar3;
  if ((int)UVar3 < 0) {
    _DAT_00fbabcc = _DAT_00fbabcc + 4.2949673e+09;
  }
  _DAT_00fbabcc = _DAT_00fbabcc * 0.001;
  UVar3 = GetPrivateProfileIntA("RANGED","BLOCKED-RATIO",0,"./FrameControl.ini");
  _DAT_00fbabd8 = (float)(int)UVar3;
  if ((int)UVar3 < 0) {
    _DAT_00fbabd8 = _DAT_00fbabd8 + 4.2949673e+09;
  }
  _DAT_00fbabd8 = _DAT_00fbabd8 * 0.001;
  UVar3 = GetPrivateProfileIntA("ATTACKED","NORMAL-VALUE",1000,"./FrameControl.ini");
  _DAT_00fbabe0 = (float)(int)UVar3;
  if ((int)UVar3 < 0) {
    _DAT_00fbabe0 = _DAT_00fbabe0 + 4.2949673e+09;
  }
  _DAT_00fbabe0 = _DAT_00fbabe0 * 0.001;
  UVar3 = GetPrivateProfileIntA("ATTACKED","NORMAL-RATIO",0x3d4,"./FrameControl.ini");
  _DAT_00fbabec = (float)(int)UVar3;
  if ((int)UVar3 < 0) {
    _DAT_00fbabec = _DAT_00fbabec + 4.2949673e+09;
  }
  _DAT_00fbabec = _DAT_00fbabec * 0.001;
  UVar3 = GetPrivateProfileIntA("ATTACKED","CRITICAL-VALUE",2000,"./FrameControl.ini");
  _DAT_00fbabe8 = (float)(int)UVar3;
  if ((int)UVar3 < 0) {
    _DAT_00fbabe8 = _DAT_00fbabe8 + 4.2949673e+09;
  }
  _DAT_00fbabe8 = _DAT_00fbabe8 * 0.001;
  UVar3 = GetPrivateProfileIntA("ATTACKED","CRITICAL-RATIO",0x3d4,"./FrameControl.ini");
  _DAT_00fbabf4 = (float)(int)UVar3;
  if ((int)UVar3 < 0) {
    _DAT_00fbabf4 = _DAT_00fbabf4 + 4.2949673e+09;
  }
  _DAT_00fbabf4 = _DAT_00fbabf4 * 0.001;
  UVar3 = GetPrivateProfileIntA("ATTACKED","BLOCKED-VALUE",0,"./FrameControl.ini");
  _DAT_00fbabe4 = (float)(int)UVar3;
  if ((int)UVar3 < 0) {
    _DAT_00fbabe4 = _DAT_00fbabe4 + 4.2949673e+09;
  }
  _DAT_00fbabe4 = _DAT_00fbabe4 * 0.001;
  UVar3 = GetPrivateProfileIntA("ATTACKED","BLOCKED-RATIO",0,"./FrameControl.ini");
  _DAT_00fbabf0 = (float)(int)UVar3;
  if ((int)UVar3 < 0) {
    _DAT_00fbabf0 = _DAT_00fbabf0 + 4.2949673e+09;
  }
  _DAT_00fbabf0 = _DAT_00fbabf0 * 0.001;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

