
void FUN_004d1b90(void)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  int iVar4;
  int *in_ECX;
  int iVar5;
  float10 fVar6;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float afStack_74 [4];
  undefined1 local_64 [40];
  undefined4 **appuStack_3c [5];
  uint uStack_28;
  uint uStack_20;
  uint local_1c;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093a2e6;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&fStack_84;
  ExceptionList = &local_14;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xffffff70);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_c = 0xffffffff;
  pfVar3 = (float *)(**(code **)(**(int **)(DAT_00fb76e8 + 4) + 0x24))(local_64);
  fStack_7c = pfVar3[1];
  fStack_80 = *pfVar3;
  fStack_78 = pfVar3[2];
  pfVar3 = (float *)(**(code **)(*in_ECX + 0x4c))();
  afStack_74[0] = fStack_80 - *pfVar3;
  afStack_74[2] = fStack_7c - pfVar3[1];
  fStack_84 = (fStack_78 - pfVar3[2]) * (fStack_78 - pfVar3[2]) +
              afStack_74[0] * afStack_74[0] + afStack_74[2] * afStack_74[2];
  fVar6 = (float10)FUN_008ff870();
  fStack_84 = (float)fVar6;
  if (((fStack_84 <= 300.0) && (fStack_84 = (float)FUN_004c88f0(), in_ECX[0xdc] != 0)) &&
     (in_ECX[0x107] != 0)) {
    FUN_004c97f0(&fStack_80,0x3f800000);
    iVar5 = -0x444401;
    iVar4 = FUN_004c9580(in_ECX);
    fVar2 = fStack_7c;
    fVar1 = fStack_80;
    if (iVar4 == 0x10) {
      iVar5 = -0xff0094;
    }
    else if (iVar4 == 0x11) {
      iVar5 = -0xff0094;
    }
    else if (iVar4 == 0x12) {
      if (in_ECX[0x10a] == 0) {
        iVar5 = (-(uint)(in_ECX[0x109] != 3) & 0x8033) - 0xe667;
      }
      else {
        iVar5 = -0xffab;
      }
    }
    FUN_004c9b60((int)in_ECX + 6,fStack_80,fStack_7c,fStack_78,iVar5,0xff000000,0);
    if (in_ECX[0x10c] != 0) {
      afStack_74[0] = 0.0;
      afStack_74[1] = -NAN;
      FUN_0040e460(L"{0} / {1}");
      puStack_10 = (undefined1 *)0x1;
      if (uStack_28 < 8) {
        appuStack_3c[0] = appuStack_3c;
      }
      FUN_004c9b60(appuStack_3c[0],fVar1,fVar2,fStack_78,0xffffffff,0xff000000,afStack_74);
      FUN_004fa440();
    }
  }
  ExceptionList = pvStack_18;
  __security_check_cookie(uStack_20 ^ (uint)&stack0xffffff78);
  return;
}

