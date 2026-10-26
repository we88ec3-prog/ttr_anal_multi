
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054d930(float *param_1)

{
  float fVar1;
  float fVar2;
  ushort uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  float *pfVar7;
  float10 fVar8;
  undefined4 uVar9;
  float *local_9c;
  float fStack_98;
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  char cStack_85;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
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
  float fStack_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00939c38;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_9c;
  ExceptionList = &local_14;
  local_9c = param_1;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xffffff58);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  iVar4 = DAT_00fb76e8;
  if ((DAT_00fe7248 & 1) == 0) {
    DAT_00fe7248 = DAT_00fe7248 | 1;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 2;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    _DAT_00fe7244 = DAT_00fb90ac * 3.0;
  }
  local_c = 0xffffffff;
  piVar5 = (int *)(**(code **)(*DAT_00fba7a4 + 0x20))();
  if (piVar5 != (int *)0x0) {
    uVar3 = *(ushort *)(piVar5 + 1);
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 3;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
      local_c = 0xffffffff;
    }
    fStack_60 = (float)(uint)uVar3;
    FUN_0082ef00(&fStack_60);
    if (((fStack_8c != DAT_00fab13c) && (*(int *)((int)fStack_8c + 0x10) != 0)) &&
       (*(int *)(*(int *)((int)fStack_8c + 0x10) + 0xb8) != 0)) {
      if (DAT_00fbab38 == 0) {
        uVar9 = 0xc9;
        FUN_00443dc0(0xc9);
        iVar6 = FUN_006f1b90(uVar9);
        if (iVar6 == 3) {
          _DAT_00fe7244 = _DAT_00fe7244 + 0.5;
        }
        else {
          uVar9 = 0xd1;
          FUN_00443dc0(0xd1);
          iVar6 = FUN_006f1b90(uVar9);
          if (iVar6 == 3) {
            _DAT_00fe7244 = _DAT_00fe7244 - 0.5;
          }
        }
      }
      pfVar7 = (float *)(**(code **)(*piVar5 + 0x4c))();
      fStack_58 = *pfVar7;
      fStack_54 = pfVar7[1];
      fStack_50 = pfVar7[2];
      FUN_007982e0(&fStack_34);
      FUN_00798250(&fStack_28);
      FUN_007981c0(&fStack_40);
      iVar6 = FUN_00443dc0();
      if ((*(int *)(iVar6 + 0x20) == 0) || (*(char *)(iVar6 + 0x18a) == '\0')) {
        fStack_2c = 0.0;
        fStack_20 = 0.0;
        fStack_3c = 0.0;
        fStack_40 = 0.0;
      }
      D3DXVec3Normalize(&fStack_34,&fStack_34);
      D3DXVec3Normalize(&fStack_30,&fStack_30);
      D3DXVec3Normalize(&fStack_50,&fStack_50);
      FUN_00797e10();
      local_9c = *(float **)(iVar4 + 0xc);
      fStack_98 = *(float *)(iVar4 + 0x10);
      fStack_94 = *(float *)(iVar4 + 0x14);
      if ((piVar5[0x57] != 0) && (piVar5[0xdc] != 0)) {
        FUN_007a7100();
      }
      fStack_74 = fStack_94;
      iVar6 = (**(code **)*DAT_00fba838)(local_9c,fStack_98,&fStack_74,0);
      if (iVar6 != 0) {
        fVar1 = local_9c[2];
        fVar2 = local_9c[1];
        local_9c = (float *)*local_9c;
        fStack_4c = (float)local_9c * fStack_34;
        fStack_48 = fStack_30 * (float)local_9c;
        fStack_44 = (float)local_9c * fStack_2c;
        fStack_78 = fStack_4c + fVar2 * fStack_28 + fVar1 * fStack_40;
        fStack_74 = fStack_48 + fStack_24 * fVar2 + fVar1 * fStack_3c;
        fStack_70 = fStack_44 + fVar2 * fStack_20 + fVar1 * fStack_38;
        fStack_84 = fStack_78 + fStack_84;
        fStack_80 = fStack_74 + fStack_80;
        fStack_7c = fStack_70 + fStack_7c;
        fStack_6c = *(float *)(iVar4 + 0xc);
        fStack_68 = *(float *)(iVar4 + 0x10);
        fStack_64 = *(float *)(iVar4 + 0x14);
        fStack_98 = fStack_84 - fStack_6c;
        fStack_94 = fStack_80 - fStack_68;
        fStack_90 = fStack_7c - fStack_64;
        pfVar7 = (float *)FUN_00797e10();
        fStack_6c = *pfVar7 + fStack_98;
        fStack_68 = pfVar7[1] + fStack_94;
        fStack_64 = pfVar7[2] + fStack_90;
        fStack_78 = fStack_6c - fStack_58;
        fStack_74 = fStack_68 - fStack_54;
        fStack_70 = fStack_64 - fStack_50;
        local_9c = (float *)(fStack_70 * fStack_70 + fStack_78 * fStack_78 + fStack_74 * fStack_74);
        fVar8 = (float10)FUN_008ff870();
        local_9c = (float *)(float)fVar8;
        if ((DAT_00fbab38 != 0) &&
           ((_DAT_00fbab3c < (float)local_9c || ((float)local_9c < fStack_8c)))) {
          cStack_85 = '\0';
        }
        fStack_8c = 0.0;
        if (DAT_00fbab38 == 0) {
          fStack_8c = 5.0;
        }
        fStack_60 = fStack_7c;
        if (DAT_00fbab38 == 0) {
          fStack_60 = fStack_90;
        }
        if (fStack_60 < fStack_8c + fStack_5c) {
          fStack_7c = fStack_8c + fStack_5c;
        }
        if (cStack_85 != '\0') {
          *(float *)(iVar4 + 0xc) = fStack_84;
          *(float *)(iVar4 + 0x10) = fStack_80;
          *(float *)(iVar4 + 0x14) = fStack_7c;
          *(undefined4 *)(iVar4 + 0xcc) = 0;
        }
      }
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_9c);
  return;
}

