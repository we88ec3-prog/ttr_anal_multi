
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00622fa0(int param_1)

{
  ushort uVar1;
  int *piVar2;
  char cVar3;
  ushort uVar4;
  short sVar5;
  uint uVar6;
  float *pfVar7;
  int iVar8;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  uint auStack_54 [4];
  undefined4 uStack_44;
  uint uStack_40;
  uint auStack_38 [4];
  undefined4 uStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0091a704;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_64;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xffffff90;
  ExceptionList = &local_14;
  local_5c = *(float *)(*(int *)(param_1 + 0xec) + 0xc4);
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0;
    FUN_0054f850(uVar6);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_64 = DAT_00fb9364;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 1;
    FUN_0054f850(uVar6);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_58 = DAT_00fb9360;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 2;
    FUN_0054f850(uVar6);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_60 = DAT_00fb9360;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 3;
    FUN_0054f850(uVar6);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_64 = ((float)(int)local_5c / 100.0) * (local_64 - local_58) + local_60;
  if (DAT_00fb9364 < local_64) {
    local_64 = DAT_00fb9364;
  }
  DAT_00fb935c = local_64;
  if (local_64 < DAT_00fb9360) {
    DAT_00fb935c = DAT_00fb9360;
  }
  local_5c = *(float *)(*(int *)(param_1 + 0xf8) + 0xc4);
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 4;
    FUN_0054f850(uVar6);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_64 = (float)CONCAT22(local_64._2_2_,DAT_00fb90ee);
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 5;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 6;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  uVar4 = DAT_00fb90ec;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 7;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  uVar1 = DAT_00fb90ec;
  local_c = 0xffffffff;
  local_60 = (float)(int)(short)uVar4;
  uVar4 = FUN_008fed10();
  DAT_00fb90ea = uVar4;
  if ((short)DAT_00fb90ee < (short)uVar4) {
    DAT_00fb90ea = DAT_00fb90ee;
  }
  if ((short)DAT_00fb90ea < (short)uVar1) {
    DAT_00fb90ea = uVar1;
    uVar4 = uVar1;
  }
  local_64 = (float)(uint)uVar4;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 8;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_c = 0xffffffff;
  }
  uVar4 = DAT_00fb90ea;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 9;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_c = 0xffffffff;
  }
  local_60 = DAT_00fb935c;
  if ((DAT_00fc0fc0 & 1) == 0) {
    DAT_00fc0fc0 = DAT_00fc0fc0 | 1;
    local_c = 10;
    FUN_006d8e50();
    _atexit((_func_4879 *)&LAB_00bcdbb0);
    local_c = 0xffffffff;
  }
  piVar2 = DAT_00fc0ffc;
  if (DAT_00fc0ffc != (int *)0x0) {
    local_60 = (float)(int)(short)uVar4;
    FUN_008fed10();
    FUN_006daa70();
    _DAT_00fc106c = FUN_008fed10();
    (**(code **)(*piVar2 + 0x48))(_DAT_00fc106c);
  }
  local_58 = *(float *)(*(int *)(param_1 + 0xfc) + 0xc4);
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0xb;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_c = 0xffffffff;
  }
  local_60 = DAT_00fb923c;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0xc;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_c = 0xffffffff;
  }
  local_5c = DAT_00fb9238;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0xd;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_c = 0xffffffff;
  }
  local_64 = DAT_00fb9238;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0xe;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_c = 0xffffffff;
  }
  local_64 = ((float)(int)local_58 / 100.0) * (local_60 - local_5c) + local_64;
  if (DAT_00fb923c < local_64) {
    local_64 = DAT_00fb923c;
  }
  DAT_00fb9234 = local_64;
  if (local_64 < DAT_00fb9238) {
    DAT_00fb9234 = DAT_00fb9238;
  }
  uStack_40 = 0xf;
  uStack_44 = 0;
  auStack_54[0] = auStack_54[0] & 0xffffff00;
  FUN_0040b310("Character");
  local_c._1_3_ = 0;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c._0_1_ = 0x10;
    local_c._1_3_ = 0;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_58 = DAT_00fb9234;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c._0_1_ = 0x11;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_64 = DAT_00fb935c;
  if ((DAT_00fab0d4 & 1) == 0) {
    DAT_00fab0d4 = DAT_00fab0d4 | 1;
    local_c._0_1_ = 0x12;
    FUN_0080a3a0();
    _atexit((_func_4879 *)&LAB_00bccdd0);
  }
  local_c._0_1_ = 0xf;
  local_60 = (float)FUN_0080c1c0(auStack_54);
  if ((local_60 == DAT_00fab054) || (cVar3 = FUN_005436a0(), cVar3 != '\0')) {
    local_5c = DAT_00fab054;
    pfVar7 = &local_5c;
  }
  else {
    pfVar7 = &local_60;
  }
  iVar8 = DAT_00fab04c;
  if (*pfVar7 != DAT_00fab054) {
    iVar8 = *(int *)((int)*pfVar7 + 0x28);
  }
  *(uint *)(iVar8 + 0x20) = *(uint *)(iVar8 + 0x20) | 1;
  uVar6 = DAT_00fab0d4 & 1;
  local_60 = local_58 * local_64;
  *(float *)(iVar8 + 0x24) = local_60;
  if (uVar6 == 0) {
    DAT_00fab0d4 = DAT_00fab0d4 | 1;
    local_c._0_1_ = 0x13;
    FUN_0080a3a0();
    _atexit((_func_4879 *)&LAB_00bccdd0);
    local_c._0_1_ = 0xf;
  }
  FUN_0080c0a0();
  local_c = 0xffffffff;
  if (0xf < uStack_40) {
    FUN_0089120c(auStack_54[0]);
  }
  uStack_40 = 0xf;
  uStack_44 = 0;
  auStack_54[0] = auStack_54[0] & 0xffffff00;
  FUN_0040b310("Battle");
  local_c._1_3_ = 0;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c._0_1_ = 0x15;
    local_c._1_3_ = 0;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_58 = DAT_00fb9234;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c._0_1_ = 0x16;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_64 = DAT_00fb935c;
  if ((DAT_00fab0d4 & 1) == 0) {
    DAT_00fab0d4 = DAT_00fab0d4 | 1;
    local_c._0_1_ = 0x17;
    FUN_0080a3a0();
    _atexit((_func_4879 *)&LAB_00bccdd0);
  }
  local_c._0_1_ = 0x14;
  local_60 = (float)FUN_0080c1c0(auStack_54);
  if ((local_60 == DAT_00fab054) || (cVar3 = FUN_005436a0(), cVar3 != '\0')) {
    local_5c = DAT_00fab054;
    pfVar7 = &local_5c;
  }
  else {
    pfVar7 = &local_60;
  }
  iVar8 = DAT_00fab04c;
  if (*pfVar7 != DAT_00fab054) {
    iVar8 = *(int *)((int)*pfVar7 + 0x28);
  }
  *(uint *)(iVar8 + 0x20) = *(uint *)(iVar8 + 0x20) | 1;
  uVar6 = DAT_00fab0d4 & 1;
  local_60 = local_58 * 0.57 * local_64;
  *(float *)(iVar8 + 0x24) = local_60;
  if (uVar6 == 0) {
    DAT_00fab0d4 = DAT_00fab0d4 | 1;
    local_c._0_1_ = 0x18;
    FUN_0080a3a0();
    _atexit((_func_4879 *)&LAB_00bccdd0);
    local_c._0_1_ = 0x14;
  }
  FUN_0080c0a0();
  local_c = 0xffffffff;
  if (0xf < uStack_40) {
    FUN_0089120c(auStack_54[0]);
  }
  uStack_40 = 0xf;
  uStack_44 = 0;
  auStack_54[0] = auStack_54[0] & 0xffffff00;
  FUN_0040b310("Damage");
  local_c._1_3_ = 0;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c._0_1_ = 0x1a;
    local_c._1_3_ = 0;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_58 = DAT_00fb9234;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c._0_1_ = 0x1b;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_64 = DAT_00fb935c;
  if ((DAT_00fab0d4 & 1) == 0) {
    DAT_00fab0d4 = DAT_00fab0d4 | 1;
    local_c._0_1_ = 0x1c;
    FUN_0080a3a0();
    _atexit((_func_4879 *)&LAB_00bccdd0);
  }
  local_c._0_1_ = 0x19;
  local_60 = (float)FUN_0080c1c0(auStack_54);
  if ((local_60 == DAT_00fab054) || (cVar3 = FUN_005436a0(), cVar3 != '\0')) {
    local_5c = DAT_00fab054;
    pfVar7 = &local_5c;
  }
  else {
    pfVar7 = &local_60;
  }
  iVar8 = DAT_00fab04c;
  if (*pfVar7 != DAT_00fab054) {
    iVar8 = *(int *)((int)*pfVar7 + 0x28);
  }
  *(uint *)(iVar8 + 0x20) = *(uint *)(iVar8 + 0x20) | 1;
  uVar6 = DAT_00fab0d4 & 1;
  local_60 = local_58 * 0.714 * local_64;
  *(float *)(iVar8 + 0x24) = local_60;
  if (uVar6 == 0) {
    DAT_00fab0d4 = DAT_00fab0d4 | 1;
    local_c._0_1_ = 0x1d;
    FUN_0080a3a0();
    _atexit((_func_4879 *)&LAB_00bccdd0);
    local_c._0_1_ = 0x19;
  }
  FUN_0080c0a0();
  local_c = 0xffffffff;
  if (0xf < uStack_40) {
    FUN_0089120c(auStack_54[0]);
  }
  local_58 = *(float *)(*(int *)(param_1 + 0x100) + 0xc4);
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0x1e;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_c = 0xffffffff;
  }
  local_60 = DAT_00fb9254;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0x1f;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_c = 0xffffffff;
  }
  local_5c = DAT_00fb9250;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0x20;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_c = 0xffffffff;
  }
  local_64 = DAT_00fb9250;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0x21;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_c = 0xffffffff;
  }
  local_64 = ((float)(int)local_58 / 100.0) * (local_60 - local_5c) + local_64;
  if (DAT_00fb9254 < local_64) {
    local_64 = DAT_00fb9254;
  }
  DAT_00fb924c = local_64;
  if (local_64 < DAT_00fb9250) {
    DAT_00fb924c = DAT_00fb9250;
  }
  uStack_40 = 0xf;
  uStack_44 = 0;
  auStack_54[0] = auStack_54[0] & 0xffffff00;
  FUN_0040b310(&DAT_00c05800);
  local_c._1_3_ = 0;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c._0_1_ = 0x23;
    local_c._1_3_ = 0;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_58 = DAT_00fb924c;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c._0_1_ = 0x24;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_64 = DAT_00fb935c;
  if ((DAT_00fab0d4 & 1) == 0) {
    DAT_00fab0d4 = DAT_00fab0d4 | 1;
    local_c._0_1_ = 0x25;
    FUN_0080a3a0();
    _atexit((_func_4879 *)&LAB_00bccdd0);
  }
  local_c._0_1_ = 0x22;
  local_60 = (float)FUN_0080c1c0(auStack_54);
  if ((local_60 == DAT_00fab054) || (cVar3 = FUN_005436a0(), cVar3 != '\0')) {
    local_5c = DAT_00fab054;
    pfVar7 = &local_5c;
  }
  else {
    pfVar7 = &local_60;
  }
  iVar8 = DAT_00fab04c;
  if (*pfVar7 != DAT_00fab054) {
    iVar8 = *(int *)((int)*pfVar7 + 0x28);
  }
  *(uint *)(iVar8 + 0x20) = *(uint *)(iVar8 + 0x20) | 1;
  uVar6 = DAT_00fab0d4 & 1;
  local_60 = local_58 * local_64;
  *(float *)(iVar8 + 0x24) = local_60;
  if (uVar6 == 0) {
    DAT_00fab0d4 = DAT_00fab0d4 | 1;
    local_c._0_1_ = 0x26;
    FUN_0080a3a0();
    _atexit((_func_4879 *)&LAB_00bccdd0);
    local_c._0_1_ = 0x22;
  }
  FUN_0080c0a0();
  local_c = 0xffffffff;
  if (0xf < uStack_40) {
    FUN_0089120c(auStack_54[0]);
  }
  local_58 = *(float *)(*(int *)(param_1 + 0x104) + 0xc4);
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0x27;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_c = 0xffffffff;
  }
  local_60 = DAT_00fb926c;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0x28;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_c = 0xffffffff;
  }
  local_5c = DAT_00fb9268;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0x29;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_c = 0xffffffff;
  }
  local_64 = DAT_00fb9268;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0x2a;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_c = 0xffffffff;
  }
  local_64 = ((float)(int)local_58 / 100.0) * (local_60 - local_5c) + local_64;
  if (DAT_00fb926c < local_64) {
    local_64 = DAT_00fb926c;
  }
  DAT_00fb9264 = local_64;
  if (local_64 < DAT_00fb9268) {
    DAT_00fb9264 = DAT_00fb9268;
  }
  uStack_24 = 0xf;
  uStack_28 = 0;
  auStack_38[0] = auStack_38[0] & 0xffffff00;
  FUN_0040b310("Voice");
  local_c._1_3_ = 0;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c._0_1_ = 0x2c;
    local_c._1_3_ = 0;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_58 = DAT_00fb9264;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c._0_1_ = 0x2d;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_64 = DAT_00fb935c;
  if ((DAT_00fab0d4 & 1) == 0) {
    DAT_00fab0d4 = DAT_00fab0d4 | 1;
    local_c._0_1_ = 0x2e;
    FUN_0080a3a0();
    _atexit((_func_4879 *)&LAB_00bccdd0);
  }
  local_c._0_1_ = 0x2b;
  local_60 = (float)FUN_0080c1c0(auStack_38);
  if ((local_60 == DAT_00fab054) || (cVar3 = FUN_005436a0(), cVar3 != '\0')) {
    local_5c = DAT_00fab054;
    pfVar7 = &local_5c;
  }
  else {
    pfVar7 = &local_60;
  }
  iVar8 = DAT_00fab04c;
  if (*pfVar7 != DAT_00fab054) {
    iVar8 = *(int *)((int)*pfVar7 + 0x28);
  }
  *(uint *)(iVar8 + 0x20) = *(uint *)(iVar8 + 0x20) | 1;
  uVar6 = DAT_00fab0d4 & 1;
  local_60 = local_58 * local_64;
  *(float *)(iVar8 + 0x24) = local_60;
  if (uVar6 == 0) {
    DAT_00fab0d4 = DAT_00fab0d4 | 1;
    local_c._0_1_ = 0x2f;
    FUN_0080a3a0();
    _atexit((_func_4879 *)&LAB_00bccdd0);
    local_c._0_1_ = 0x2b;
  }
  FUN_0080c0a0();
  local_c = 0xffffffff;
  if (0xf < uStack_24) {
    FUN_0089120c(auStack_38[0]);
  }
  local_5c = *(float *)(*(int *)(param_1 + 0x108) + 0xc4);
  uStack_24 = 0xf;
  uStack_28 = 0;
  auStack_38[0] = auStack_38[0] & 0xffffff00;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0x30;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_c = 0xffffffff;
  }
  local_64 = (float)CONCAT22(local_64._2_2_,DAT_00fb92da);
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0x31;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_c = 0xffffffff;
  }
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0x32;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_c = 0xffffffff;
  }
  uVar4 = DAT_00fb92d8;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0x33;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_c = 0xffffffff;
  }
  uVar1 = DAT_00fb92d8;
  local_60 = (float)(int)(short)uVar4;
  uVar4 = FUN_008fed10();
  DAT_00fb92d6 = uVar4;
  if ((short)DAT_00fb92da < (short)uVar4) {
    DAT_00fb92d6 = DAT_00fb92da;
  }
  if ((short)DAT_00fb92d6 < (short)uVar1) {
    DAT_00fb92d6 = uVar1;
    uVar4 = uVar1;
  }
  local_64 = (float)(uint)uVar4;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0x34;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_c = 0xffffffff;
  }
  uVar4 = DAT_00fb92d6;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0x35;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_c = 0xffffffff;
  }
  local_60 = DAT_00fb935c;
  if ((DAT_00fc0fc0 & 1) == 0) {
    DAT_00fc0fc0 = DAT_00fc0fc0 | 1;
    local_c = 0x36;
    FUN_006d8e50();
    _atexit((_func_4879 *)&LAB_00bcdbb0);
    local_c = 0xffffffff;
  }
  if (DAT_00fc1034 != (int *)0x0) {
    iVar8 = *DAT_00fc1034;
    local_60 = (float)(int)(short)uVar4;
    sVar5 = FUN_008fed10();
    (**(code **)(iVar8 + 0x48))((int)sVar5);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_64);
  return;
}

