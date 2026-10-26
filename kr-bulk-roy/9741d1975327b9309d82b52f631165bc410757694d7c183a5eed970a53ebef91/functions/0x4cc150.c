
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004cc150(void)

{
  byte bVar1;
  int iVar2;
  float *pfVar3;
  int *in_ECX;
  undefined4 unaff_ESI;
  float10 fVar4;
  uint uStack_74;
  undefined1 auStack_68 [4];
  float local_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float local_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  void *pvStack_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_009369de;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_68;
  uStack_74 = DAT_00d61f20 ^ (uint)&stack0xffffff90;
  ExceptionList = &local_14;
  if (in_ECX[0x3d] == 0) {
    if (in_ECX[0x2b] != 0) {
      (**(code **)(*in_ECX + 0x38))();
    }
    if (DAT_00fba7cc == 0) {
      iVar2 = FUN_00891268(0x1380);
      if (iVar2 == 0) {
        DAT_00fba7cc = 0;
      }
      else {
        DAT_00fba7cc = FUN_006df3d0();
      }
    }
    local_64 = 1.0 / (float)*(int *)(DAT_00fba7cc + 0x1360);
    fVar4 = (float10)(**(code **)(*in_ECX + 0x60))();
    bVar1 = *(byte *)(in_ECX + 0x39);
    fStack_5c = (float)(fVar4 * (float10)local_64);
    if ((DAT_00fb7c18 & 1) == 0) {
      DAT_00fb7c18 = DAT_00fb7c18 | 1;
      FUN_004449d0();
    }
    fStack_58 = fStack_5c * (float)(&DAT_00fb8024)[(uint)bVar1 * 2];
    local_54 = (float)in_ECX[0x28] + fStack_5c * (float)(&DAT_00fb8020)[(uint)bVar1 * 2];
    fStack_50 = (float)in_ECX[0x29] + fStack_58;
    fStack_5c = fStack_5c * (float)(&DAT_00fb8020)[(uint)bVar1 * 2];
    (**(code **)(*in_ECX + 0x44))(&local_54,1);
    FUN_004cad60(unaff_ESI,0x40000000,0);
  }
  else {
    if (in_ECX[0x2b] != 0) {
      (**(code **)(*in_ECX + 0x38))();
    }
    local_54 = (float)in_ECX[0x4d] / (float)in_ECX[0x4c];
    local_64 = local_54;
    if (in_ECX[0x48] != 0) {
      iVar2 = in_ECX[0x48];
      do {
        iVar2 = iVar2 + -1;
        local_64 = local_64 * local_54;
      } while (iVar2 != 0);
    }
    local_54 = local_54 * 3.14;
    fVar4 = (float10)FUN_008ff0a0();
    local_54 = (float)fVar4;
    fStack_5c = (float)in_ECX[0x47] * local_54;
    if (in_ECX[0x3e] == 0) {
      if ((DAT_00fab22c & 1) == 0) {
        DAT_00fab22c = DAT_00fab22c | 1;
        uStack_c = 0;
        FUN_004dec90();
        _atexit((_func_4879 *)&LAB_00bcce30);
        uStack_c = 0xffffffff;
      }
      local_54 = (float)(uint)*(ushort *)(in_ECX + 0x4a);
      FUN_0082ef00(&local_54);
      if ((fStack_60 == DAT_00fab13c) || (*(int **)((int)fStack_60 + 0x10) == (int *)0x0)) {
        fStack_34 = (float)in_ECX[0x44];
        fStack_30 = (float)in_ECX[0x45];
        fStack_2c = (float)in_ECX[0x46];
      }
      else {
        pfVar3 = (float *)(**(code **)(**(int **)((int)fStack_60 + 0x10) + 0x4c))();
        fStack_34 = *pfVar3;
        fStack_30 = pfVar3[1];
        fStack_2c = pfVar3[2];
        in_ECX[0x44] = (int)fStack_34;
        in_ECX[0x45] = (int)fStack_30;
        in_ECX[0x46] = (int)fStack_2c;
      }
    }
    else {
      fStack_34 = (float)in_ECX[0x4a];
      fStack_30 = (float)in_ECX[0x4b];
      fStack_2c = 0.0;
      (**(code **)*DAT_00fba838)(fStack_34,fStack_30,&fStack_2c,0);
    }
    fStack_4c = fStack_34 - (float)in_ECX[0x40];
    fStack_48 = fStack_30 - (float)in_ECX[0x41];
    fStack_44 = fStack_2c - (float)in_ECX[0x42];
    fStack_40 = local_64 * fStack_4c;
    fStack_3c = fStack_48 * local_64;
    fStack_38 = local_64 * fStack_44;
    fStack_28 = fStack_40 + (float)in_ECX[0x40];
    fStack_24 = (float)in_ECX[0x41] + fStack_3c;
    fStack_60 = (float)in_ECX[0x42] + fStack_38;
    pvStack_20 = (void *)(fStack_60 + fStack_5c);
    (**(code **)(*in_ECX + 0x48))(&fStack_28,0);
    fVar4 = (float10)FUN_008fedca();
    local_64 = (float)fVar4 + 1.5707964;
    if ((DAT_00fb7c18 & 1) == 0) {
      DAT_00fb7c18 = DAT_00fb7c18 | 1;
      FUN_004449d0();
    }
    local_64 = (float)(int)ROUND(_DAT_00fb8824 * local_64);
    (**(code **)(*in_ECX + 0x58))((uint)local_64 & 0xff);
  }
  if (in_ECX[0x3c] != 0) {
    FUN_00550780();
  }
  ExceptionList = pvStack_20;
  __security_check_cookie((uint)fStack_28 ^ (uint)&uStack_74);
  return;
}

