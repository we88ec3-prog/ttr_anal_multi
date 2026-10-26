
void FUN_005d5b80(undefined4 param_1)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  short *psVar4;
  undefined1 auStack_1f4 [12];
  float fStack_1e8;
  int iStack_1e4;
  undefined4 local_1e0;
  undefined4 uStack_1dc;
  undefined4 uStack_1cc;
  uint uStack_1c8;
  uint uStack_1c0;
  undefined4 uStack_1b0;
  uint uStack_1ac;
  uint uStack_190;
  short sStack_188;
  undefined1 auStack_186 [258];
  uint local_84;
  void *local_4c;
  undefined1 *puStack_48;
  undefined4 local_44;
  
  puStack_48 = &LAB_00935f8f;
  local_4c = ExceptionList;
  local_84 = DAT_00d61f20 ^ (uint)auStack_1f4;
  ExceptionList = &local_4c;
  local_1e0 = param_1;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_44 = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xfffffe00);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_44 = 0xffffffff;
  if ((DAT_00fba7a4 != (int *)0x0) && (iVar2 = (**(code **)(*DAT_00fba7a4 + 0x20))(), iVar2 != 0)) {
    iStack_1e4 = *(int *)(iVar2 + 0x3dc) - *(int *)(iVar2 + 0x3e0);
    fStack_1e8 = 0.0;
    if (iStack_1e4 != 0) {
      fStack_1e8 = (float)(*(int *)(iVar2 + 0x3d8) - *(int *)(iVar2 + 0x3e0)) / (float)iStack_1e4;
    }
    FUN_005d0d60(L"%.1f",(double)(fStack_1e8 * 100.0));
    psVar3 = (short *)FUN_00412df0();
    local_44 = 1;
    if (7 < *(uint *)(psVar3 + 10)) {
      psVar3 = *(short **)psVar3;
    }
    uStack_1c8 = 7;
    uStack_1cc = 0;
    uStack_1dc = (uint)uStack_1dc._2_2_ << 0x10;
    psVar4 = psVar3;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar3,(int)psVar4 - (int)(psVar3 + 1) >> 1);
    local_44._0_1_ = 3;
    if (7 < uStack_1ac) {
      FUN_0089120c();
    }
    uStack_1ac = 7;
    uStack_1b0 = 0;
    uStack_1c0 = uStack_1c0 & 0xffff0000;
    FUN_00404300(&DAT_00c22434,3);
    psVar3 = (short *)FUN_00412df0();
    local_44._0_1_ = 4;
    if (7 < *(uint *)(psVar3 + 10)) {
      psVar3 = *(short **)psVar3;
    }
    psVar4 = psVar3;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00404300(psVar3,(int)psVar4 - (int)(psVar3 + 1) >> 1);
    local_44 = CONCAT31(local_44._1_3_,3);
    if (7 < uStack_190) {
      FUN_0089120c();
    }
    FUN_00404300(&DAT_00c225d0,2);
    psVar3 = &sStack_188;
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
    FUN_00404300(&sStack_188,(int)psVar3 - (int)auStack_186 >> 1);
    FUN_00404300(&DAT_00c2243c,2);
    FUN_004026e0(&uStack_1dc,0,0xffffffff);
    if (7 < uStack_1c8) {
      FUN_0089120c();
    }
  }
  ExceptionList = local_4c;
  __security_check_cookie(local_84 ^ (uint)auStack_1f4);
  return;
}

