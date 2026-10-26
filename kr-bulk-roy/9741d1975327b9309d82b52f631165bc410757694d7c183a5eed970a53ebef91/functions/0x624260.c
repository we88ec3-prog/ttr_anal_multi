
void FUN_00624260(void)

{
  int *piVar1;
  code *pcVar2;
  float fVar3;
  short sVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int unaff_EDI;
  undefined1 auStack_90 [4];
  float local_8c;
  float local_88;
  float local_84;
  double local_80;
  double local_78;
  double local_70;
  double local_68;
  double local_60;
  undefined4 uStack_54;
  uint uStack_40;
  uint uStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0092d5d0;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_90;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xffffff68;
  ExceptionList = &local_14;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0;
    FUN_0054f850(uVar5);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_84 = (float)CONCAT22(local_84._2_2_,DAT_00fb90ea);
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 1;
    FUN_0054f850(uVar5);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_88 = (float)(uint)DAT_00fb90ec;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 2;
    FUN_0054f850(uVar5);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  sVar4 = DAT_00fb90ee;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 3;
    FUN_0054f850(uVar5);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  iVar7 = (int)local_88._0_2_;
  local_88 = (float)((int)sVar4 - (int)(short)DAT_00fb90ec);
  local_80 = ((double)(local_84._0_2_ - iVar7) / (double)(int)local_88) * 100.0;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 4;
    FUN_0054f850(uVar5);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_88 = DAT_00fb9234;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 5;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_84 = DAT_00fb9238;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 6;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_8c = DAT_00fb923c;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 7;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_8c = local_8c - DAT_00fb9238;
  local_78 = (double)(((local_88 - local_84) / local_8c) * 100.0);
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 8;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_8c = DAT_00fb924c;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 9;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_88 = DAT_00fb9250;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 10;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_84 = DAT_00fb9254;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0xb;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  fVar3 = local_8c - local_88;
  local_8c = local_84 - DAT_00fb9250;
  local_68 = (double)((fVar3 / local_8c) * 100.0);
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0xc;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_8c = DAT_00fb9264;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0xd;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_88 = DAT_00fb9268;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0xe;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_84 = DAT_00fb926c;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0xf;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  fVar3 = local_8c - local_88;
  local_8c = local_84 - DAT_00fb9268;
  local_60 = (double)((fVar3 / local_8c) * 100.0);
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0x10;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_84 = (float)CONCAT22(local_84._2_2_,DAT_00fb92d6);
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0x11;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_8c = (float)(uint)DAT_00fb92d8;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0x12;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  sVar4 = DAT_00fb92da;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0x13;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  iVar7 = (int)local_8c._0_2_;
  local_8c = (float)((int)sVar4 - (int)(short)DAT_00fb92d8);
  local_70 = ((double)(local_84._0_2_ - iVar7) / (double)(int)local_8c) * 100.0;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0x14;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_8c = (float)DAT_00fb935c;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0x15;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_88 = DAT_00fb9360;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0x16;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_84 = DAT_00fb9364;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0x17;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_c = 0xffffffff;
  piVar1 = *(int **)(unaff_EDI + 0xec);
  local_8c = local_84 - DAT_00fb9360;
  iVar7 = FUN_008fed10();
  pcVar2 = *(code **)(*piVar1 + 0x128);
  piVar1[0x31] = iVar7;
  (*pcVar2)();
  (**(code **)(*piVar1 + 200))();
  (**(code **)(**(int **)(unaff_EDI + 0xec) + 200))();
  uVar6 = FUN_0040ef80();
  local_c = 0x18;
  FUN_00757800(uVar6);
  local_c = 0xffffffff;
  if (7 < uStack_40) {
    FUN_0089120c(uStack_54);
  }
  (**(code **)(**(int **)(unaff_EDI + 0xf0) + 200))();
  piVar1 = *(int **)(unaff_EDI + 0xf8);
  iVar7 = FUN_008fed10();
  pcVar2 = *(code **)(*piVar1 + 0x128);
  piVar1[0x31] = iVar7;
  (*pcVar2)();
  (**(code **)(*piVar1 + 200))();
  (**(code **)(**(int **)(unaff_EDI + 0xf8) + 200))();
  piVar1 = *(int **)(unaff_EDI + 0xfc);
  local_8c = (float)FUN_008fed10();
  piVar1[0x31] = (int)local_8c;
  (**(code **)(*piVar1 + 0x128))();
  (**(code **)(*piVar1 + 200))();
  (**(code **)(**(int **)(unaff_EDI + 0xfc) + 200))();
  piVar1 = *(int **)(unaff_EDI + 0x100);
  local_88 = (float)FUN_008fed10();
  piVar1[0x31] = (int)local_88;
  (**(code **)(*piVar1 + 0x128))();
  (**(code **)(*piVar1 + 200))();
  (**(code **)(**(int **)(unaff_EDI + 0x100) + 200))();
  piVar1 = *(int **)(unaff_EDI + 0x104);
  local_84 = (float)FUN_008fed10();
  piVar1[0x31] = (int)local_84;
  (**(code **)(*piVar1 + 0x128))();
  (**(code **)(*piVar1 + 200))();
  (**(code **)(**(int **)(unaff_EDI + 0x104) + 200))();
  piVar1 = *(int **)(unaff_EDI + 0x108);
  iVar7 = FUN_008fed10();
  local_80 = (double)CONCAT44(local_80._4_4_,iVar7);
  piVar1[0x31] = iVar7;
  (**(code **)(*piVar1 + 0x128))();
  (**(code **)(*piVar1 + 200))();
  (**(code **)(**(int **)(unaff_EDI + 0x108) + 200))();
  uVar6 = FUN_0040ef80();
  local_c = 0x19;
  FUN_00757800(uVar6);
  local_c = 0xffffffff;
  if (7 < uStack_40) {
    FUN_0089120c(uStack_54);
  }
  (**(code **)(**(int **)(unaff_EDI + 0x10c) + 200))();
  uVar6 = FUN_0040ef80();
  local_c = 0x1a;
  FUN_00757800(uVar6);
  local_c = 0xffffffff;
  if (7 < uStack_40) {
    FUN_0089120c(uStack_54);
  }
  (**(code **)(**(int **)(unaff_EDI + 0x110) + 200))();
  uVar6 = FUN_0040ef80();
  local_c = 0x1b;
  FUN_00757800(uVar6);
  local_c = 0xffffffff;
  if (7 < uStack_40) {
    FUN_0089120c(uStack_54);
  }
  (**(code **)(**(int **)(unaff_EDI + 0x114) + 200))();
  uVar6 = FUN_0040ef80();
  local_c = 0x1c;
  FUN_00757800(uVar6);
  local_c = 0xffffffff;
  if (7 < uStack_40) {
    FUN_0089120c(uStack_54);
  }
  (**(code **)(**(int **)(unaff_EDI + 0x118) + 200))();
  uVar6 = FUN_0040ef80();
  local_c = 0x1d;
  FUN_00757800(uVar6);
  local_c = 0xffffffff;
  if (7 < uStack_24) {
    FUN_0089120c(uStack_38);
  }
  uStack_38 = uStack_38 & 0xffff0000;
  uStack_24 = 7;
  uStack_28 = 0;
  (**(code **)(**(int **)(unaff_EDI + 0x11c) + 200))();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_90);
  return;
}

