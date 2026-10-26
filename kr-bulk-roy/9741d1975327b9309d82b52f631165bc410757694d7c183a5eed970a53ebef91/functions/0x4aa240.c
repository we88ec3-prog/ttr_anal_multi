
undefined4 FUN_004aa240(void)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  float *pfVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 extraout_ECX;
  float10 fVar7;
  undefined4 local_60;
  float local_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  undefined1 auStack_44 [48];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00936eca;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  local_60 = CONCAT22((short)(local_60 >> 0x10),0xf000);
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffff98);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  local_60 = local_60 & 0xffff;
  FUN_0082ef00(&local_60);
  if ((local_5c != (float)DAT_00fab13c) && (*(int **)((int)local_5c + 0x10) != (int *)0x0)) {
    pfVar2 = (float *)(**(code **)(**(int **)((int)local_5c + 0x10) + 0x4c))();
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c = 1;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_c = 0xffffffff;
    }
    if ((DAT_00fb76e4 == 0) || (iVar3 = FUN_00838800(*pfVar2,pfVar2[1],pfVar2[2]), iVar3 != 0)) {
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_c = 2;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_c = 0xffffffff;
      }
      pfVar4 = (float *)(**(code **)(**(int **)(DAT_00fb76e8 + 4) + 0x24))(auStack_44);
      fStack_58 = pfVar4[1];
      fStack_54 = pfVar4[2];
      fStack_50 = *pfVar4 - *pfVar2;
      fStack_4c = fStack_58 - pfVar2[1];
      fStack_48 = fStack_54 - pfVar2[2];
      local_5c = fStack_48 * fStack_48 + fStack_50 * fStack_50 + fStack_4c * fStack_4c;
      fVar7 = (float10)FUN_008ff870();
      local_5c = (float)fVar7;
      if (local_5c < 150.0) {
        uVar5 = FUN_00434740(extraout_ECX,pfVar2);
        FUN_0079a6b0(uVar5,pfVar2);
        iVar3 = FUN_006dfc40();
        iVar3 = *(int *)(iVar3 + 0x18);
        iVar6 = FUN_006dfc40();
        if ((100.0 < local_5c) && (100.0 < fStack_58)) {
          iVar3 = iVar3 + -100;
          fVar1 = (float)iVar3;
          if (iVar3 < 0) {
            fVar1 = fVar1 + 4.2949673e+09;
          }
          if (local_5c < fVar1) {
            iVar3 = *(int *)(iVar6 + 0x1c) + -100;
            fVar1 = (float)iVar3;
            if (iVar3 < 0) {
              fVar1 = fVar1 + 4.2949673e+09;
            }
            if (fStack_58 < fVar1) {
              ExceptionList = local_14;
              return 1;
            }
          }
        }
      }
    }
  }
  ExceptionList = local_14;
  return 0;
}

