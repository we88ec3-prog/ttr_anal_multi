
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054ba30(uint param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  uint *puVar9;
  float *pfVar10;
  int *piVar11;
  bool bVar12;
  float10 fVar13;
  float fVar14;
  float local_4c;
  int local_48;
  float fStack_3c;
  float local_38;
  float local_34;
  float local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  float local_20;
  float local_1c;
  float local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  uVar4 = param_1;
  puStack_c = &LAB_0093a222;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar5;
  if ((DAT_00fe7264 & 1) == 0) {
    DAT_00fe7264 = DAT_00fe7264 | 1;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8 = 1;
      FUN_0054f850(uVar5);
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    DAT_00fe7260 = DAT_00fb9084;
  }
  if ((DAT_00fe7264 & 2) == 0) {
    DAT_00fe7264 = DAT_00fe7264 | 2;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8 = 3;
      FUN_0054f850(uVar5);
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    DAT_00fe725c = DAT_00fb9074;
  }
  if ((DAT_00fe7264 & 4) == 0) {
    DAT_00fe7264 = DAT_00fe7264 | 4;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8 = 5;
      FUN_0054f850(uVar5);
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    DAT_00fe7258 = DAT_00fb909c;
  }
  if ((DAT_00fe7264 & 8) == 0) {
    DAT_00fe7264 = DAT_00fe7264 | 8;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8 = 7;
      FUN_0054f850(uVar5);
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    DAT_00fe7254 = DAT_00fb908c;
  }
  if ((DAT_00fe7264 & 0x10) == 0) {
    DAT_00fe7264 = DAT_00fe7264 | 0x10;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8 = 9;
      FUN_0054f850(uVar5);
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    _DAT_00fe7250 = DAT_00fb90ac;
  }
  if ((DAT_00fe7264 & 0x20) == 0) {
    DAT_00fe7264 = DAT_00fe7264 | 0x20;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8 = 0xb;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    _DAT_00fe724c = DAT_00fb90b4;
  }
  if ((DAT_00fb7c14 & 1) == 0) {
    DAT_00fb7c14 = DAT_00fb7c14 | 1;
    local_8 = 0xc;
    FUN_006d0750();
    _atexit((_func_4879 *)&LAB_00bcd530);
  }
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0xd;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  iVar3 = DAT_00fb76e8;
  local_8 = 0xffffffff;
  if (DAT_00fb8830 != 0) goto LAB_0054c3e7;
  if (DAT_00fbab34 == 0) {
    local_34 = DAT_00fbab30;
    iVar6 = FUN_0040f060();
    FUN_0082ef00(&local_34);
    if ((local_4c == (float)*(int *)(iVar6 + 0xc)) || (*(int *)((int)local_4c + 0x10) == 0))
    goto LAB_0054bce2;
  }
  else {
LAB_0054bce2:
    FUN_0054def0(0x3d088889);
    param_1 = 0;
  }
  local_4c = 0.0;
  local_38 = *(float *)(iVar3 + 0x24);
  iVar6 = 0;
  local_30 = *(float *)(iVar3 + 0x18);
  local_48 = 0;
  if (((param_1 & 8) != 0) && (DAT_00fb9010 == '\x01')) {
    FUN_0054c620();
  }
  if ((param_1 & 1) != 0) {
    if (DAT_00fb900c == '\0') {
      if (DAT_00fb900d == '\0') goto LAB_0054bd6b;
      local_4c = 0.0 - _DAT_00fe724c;
    }
    else {
      local_4c = _DAT_00fe724c + 0.0;
    }
    iVar6 = 10;
    local_48 = 10;
  }
LAB_0054bd6b:
  if ((param_1 & 2) != 0) {
    if (DAT_00fb900b == '\0') {
      if (DAT_00fb900a != '\0') {
        local_30 = _DAT_00fe724c + local_30;
        iVar6 = iVar6 + -1;
        local_48 = iVar6;
      }
    }
    else {
      local_30 = local_30 - _DAT_00fe724c;
      iVar6 = iVar6 + 1;
      local_48 = iVar6;
    }
    fVar14 = local_30;
    if (iVar6 != 0) {
      local_48 = 10;
    }
    local_34 = local_30;
    if (DAT_00fbab34 == 0) {
      if (local_30 <= DAT_00fe7254) {
        local_30 = DAT_00fe7254;
      }
      if (DAT_00fe7258 <= local_30) {
        local_30 = DAT_00fe7258;
      }
    }
    if (fVar14 != local_30) {
      local_48 = 10;
    }
  }
  if (DAT_00fba80c == 0) {
    iVar6 = FUN_00891268(0x57c);
    if (iVar6 == 0) {
      DAT_00fba80c = 0;
    }
    else {
      DAT_00fba80c = FUN_006f1370();
    }
  }
  iVar6 = DAT_00fba80c;
  if (((*(int *)(DAT_00fba80c + 0x20) != 0) && (*(char *)(DAT_00fba80c + 0x369) == '\x02')) &&
     ((*(uint *)(DAT_00fb1318 + 0xc01c) >> 2 & 1) == 0)) {
    if ((uVar4 & 2) != 0) {
      FUN_00443dc0();
      iVar7 = FUN_006f1bc0();
      iVar6 = DAT_00fba80c;
      iVar7 = *(int *)(iVar7 + 4);
      if (iVar7 < -0x1c) {
        iVar7 = -0x1c;
      }
      else if (0x1c < iVar7) {
        iVar7 = 0x1c;
      }
      bVar12 = false;
      if (iVar7 < 0) {
        iVar7 = iVar7 + -4;
        bVar12 = iVar7 < 0;
      }
      if (iVar7 != 0 && !bVar12) {
        iVar7 = iVar7 + 4;
      }
      local_34 = (float)-iVar7 / 20.0;
      local_30 = _DAT_00fe724c * local_34 + local_30;
      if (DAT_00fbab34 == 0) {
        if (local_30 <= DAT_00fe7254) {
          local_30 = DAT_00fe7254;
        }
        if (DAT_00fe7258 <= local_30) {
          local_30 = DAT_00fe7258;
        }
      }
      *(float *)(iVar3 + 0x18) = local_30;
      *(undefined4 *)(iVar3 + 0xcc) = 0;
    }
    if ((uVar4 & 1) != 0) {
      FUN_00443dc0();
      piVar8 = (int *)FUN_006f1bc0();
      iVar6 = *piVar8;
      if (iVar6 < -0x1d) {
        iVar6 = -0x1d;
      }
      else if (0x1d < iVar6) {
        iVar6 = 0x1d;
      }
      bVar12 = false;
      if (iVar6 < 0) {
        iVar6 = iVar6 + -3;
        bVar12 = iVar6 < 0;
      }
      if (iVar6 != 0 && !bVar12) {
        iVar6 = iVar6 + 3;
      }
      local_34 = (float)-iVar6 / 15.0;
      FUN_00443dc0();
      piVar8 = (int *)FUN_006f1bc0();
      iVar6 = DAT_00fba80c;
      if (*piVar8 != 0) {
        DAT_00fbab10 = 0;
      }
      fVar14 = _DAT_00fe724c * local_34;
      *(undefined4 *)(iVar3 + 0xcc) = 0;
      *(float *)(iVar3 + 0x20) = fVar14 + *(float *)(iVar3 + 0x20);
    }
  }
  if ((DAT_00fc1a70 & 1) == 0) {
    DAT_00fc1a70 = DAT_00fc1a70 | 1;
    local_8 = 0xe;
    FUN_006cfc50();
    local_8 = 0xffffffff;
    iVar6 = DAT_00fba80c;
  }
  if (DAT_00fc1a78 == 0) {
    if (iVar6 == 0) {
      iVar6 = FUN_00891268(0x57c);
      if (iVar6 == 0) {
        iVar6 = 0;
        DAT_00fba80c = iVar6;
      }
      else {
        iVar6 = FUN_006f1370();
        DAT_00fba80c = iVar6;
      }
    }
    iVar6 = FUN_006f1640(iVar6);
    if (iVar6 == 0) {
      uVar5 = 0;
    }
    else if (*(int *)(iVar6 + 0x112c) == 0) {
      iVar6 = FUN_006f1c60(0);
      uVar5 = *(uint *)(iVar6 + 8);
    }
    else {
      puVar9 = (uint *)FUN_006f1c60(1);
      uVar5 = *puVar9;
    }
    if (DAT_00fba80c == 0) {
      iVar6 = FUN_00891268(0x57c);
      if (iVar6 == 0) {
        DAT_00fba80c = 0;
      }
      else {
        DAT_00fba80c = FUN_006f1370();
      }
    }
    iVar6 = FUN_006f1640(DAT_00fba80c);
    if (iVar6 == 0) {
      local_34 = 0.0;
    }
    else if (*(int *)(iVar6 + 0x112c) == 0) {
      iVar6 = FUN_006f1c60(1);
      local_34 = *(float *)(iVar6 + 8);
    }
    else {
      iVar6 = FUN_006f1c60(1);
      local_34 = *(float *)(iVar6 + 4);
    }
    fVar14 = _DAT_00fe724c;
    if (((uVar4 & 1) != 0) &&
       (iVar6 = (uVar5 ^ (int)uVar5 >> 0x1f) - ((int)uVar5 >> 0x1f), 0x2000 < iVar6)) {
      fStack_3c = -(float)(int)uVar5;
      DAT_00fbab10 = 0;
      if (iVar6 < 0x5000) {
        fStack_3c = fStack_3c * 7.6293945e-06;
      }
      else if (iVar6 < 0x7000) {
        fStack_3c = fStack_3c * 1.5258789e-05 - 0.15625;
      }
      else {
        fStack_3c = fStack_3c * 3.0517578e-05 - 0.125;
      }
      *(undefined4 *)(iVar3 + 0xcc) = 0;
      *(float *)(iVar3 + 0x20) = fVar14 * fStack_3c + *(float *)(iVar3 + 0x20);
    }
    if (((uVar4 & 2) != 0) &&
       (0x2000 < (int)(((uint)local_34 ^ (int)local_34 >> 0x1f) - ((int)local_34 >> 0x1f)))) {
      local_34 = -(float)(int)local_34 / 49152.0;
      local_30 = fVar14 * local_34 + local_30;
      if (local_30 <= DAT_00fe7254) {
        local_30 = DAT_00fe7254;
      }
      if (DAT_00fe7258 <= local_30) {
        local_30 = DAT_00fe7258;
      }
      *(float *)(iVar3 + 0x18) = local_30;
      *(undefined4 *)(iVar3 + 0xcc) = 0;
    }
  }
  if (((*(uint *)(DAT_00fb1318 + 0xc01c) >> 3 & 1) == 0) && ((uVar4 & 4) != 0)) {
    FUN_00443dc0();
    iVar6 = FUN_006f1bc0();
    if ((*(int *)(iVar6 + 8) != 0) && ((*(byte *)(DAT_00fb1318 + 0xc01c) & 1) == 0)) {
      fVar14 = *(float *)(iVar3 + 0x24);
      FUN_00443dc0();
      iVar6 = FUN_006f1bc0();
      fVar14 = fVar14 - (float)*(int *)(iVar6 + 8) * 0.0333 * 1.6;
      if (fVar14 <= DAT_00fe725c) {
        fVar14 = DAT_00fe725c;
      }
      if (DAT_00fe7260 <= fVar14) {
        fVar14 = DAT_00fe7260;
      }
      *(float *)(iVar3 + 0x24) = fVar14;
      *(undefined4 *)(iVar3 + 0xcc) = 0;
    }
    if (DAT_00fb900f != '\0') {
      local_48 = local_48 + 1;
      local_38 = _DAT_00fe7250 + local_38;
    }
    if (DAT_00fb900e != '\0') {
      local_38 = local_38 - _DAT_00fe7250;
      local_48 = local_48 + -1;
    }
    fVar14 = local_38;
    bVar12 = local_48 != 0;
    local_48 = 0;
    if (bVar12) {
      local_48 = 10;
    }
    local_34 = local_38;
    if (local_38 <= DAT_00fe725c) {
      local_38 = DAT_00fe725c;
    }
    if (DAT_00fe7260 <= local_38) {
      local_38 = DAT_00fe7260;
    }
    if (fVar14 == local_38) goto LAB_0054c2d1;
  }
  else {
LAB_0054c2d1:
    if (local_48 == 0) goto LAB_0054c3e7;
  }
  if ((uVar4 & 4) != 0) {
    *(float *)(iVar3 + 0x24) = local_38;
    *(undefined4 *)(iVar3 + 0xcc) = 0;
  }
  if ((uVar4 & 2) != 0) {
    *(float *)(iVar3 + 0x18) = local_30;
    *(undefined4 *)(iVar3 + 0xcc) = 0;
  }
  if ((uVar4 & 1) != 0) {
    fVar13 = (float10)FUN_004ff540(local_4c);
    if ((float10)0.005 < fVar13) {
      DAT_00fbab10 = 0;
    }
    *(undefined4 *)(iVar3 + 0xcc) = 0;
    *(float *)(iVar3 + 0x20) = local_4c + *(float *)(iVar3 + 0x20);
  }
  if ((uVar4 & 0x10) != 0) {
    fVar14 = *(float *)(iVar3 + 0xc);
    fVar1 = *(float *)(iVar3 + 0x10);
    fVar2 = *(float *)(iVar3 + 0x14);
    pfVar10 = (float *)FUN_00797e10();
    local_34 = fVar1 - pfVar10[1];
    local_18 = fVar2 - pfVar10[2];
    local_20 = fVar14 - *pfVar10;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0x3f800000;
    local_1c = local_34;
    D3DXVec3Normalize(&local_20,&local_20);
    piVar8 = (int *)FUN_0040b3f0();
    if ((piVar8[0x1a] == 0) && ((int *)*piVar8 != (int *)0x0)) {
      piVar11 = (int *)(**(code **)(*(int *)*piVar8 + 0x20))();
      piVar8[0x1a] = (int)piVar11;
      (**(code **)(*piVar11 + 0x18))(3);
    }
    (**(code **)(*(int *)piVar8[0x1a] + 0x10))(&local_20,&local_2c);
  }
LAB_0054c3e7:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

