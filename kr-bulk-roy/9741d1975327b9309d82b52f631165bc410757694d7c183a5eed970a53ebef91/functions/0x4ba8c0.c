
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ba8c0(int param_1)

{
  uint uVar1;
  short sVar2;
  undefined2 uVar3;
  float fVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  int *in_ECX;
  int iVar9;
  float *pfVar10;
  float unaff_EDI;
  int iVar11;
  float fStack_94;
  int *piStack_90;
  float fStack_8c;
  int *local_88;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  undefined1 auStack_74 [8];
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined1 auStack_60 [68];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00944b52;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&fStack_94;
  fVar4 = (float)(DAT_00d61f20 ^ (uint)&stack0xffffff60);
  ExceptionList = &local_14;
  uVar1 = _DAT_00fd2cf0 & 1;
  in_ECX[0x17af] = param_1;
  local_88 = in_ECX;
  if (uVar1 == 0) {
    _DAT_00fd2cf0 = _DAT_00fd2cf0 | 1;
    FUN_00738090();
    _atexit((_func_4879 *)&DAT_00bce680);
  }
  if (DAT_00fd2bb8 != 0) {
    _DAT_00fd2bc4 = DAT_00fd2bbc;
    _DAT_00fd2bc8 = DAT_00fd2bc0;
    if (DAT_00fd2cd0 != (int *)0x0) {
      (**(code **)(*DAT_00fd2cd0 + 8))();
      DAT_00fd2cd0 = (int *)0x0;
    }
    _DAT_00fd2cd4 = 0;
    _DAT_00fd2bcc = 1;
    _DAT_00fd2ce8 = 1;
  }
  piVar5 = (int *)(**(code **)(*in_ECX + 0x30))();
  piStack_90 = piVar5;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    uStack_c = 0;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    uStack_c = 0xffffffff;
  }
  FUN_004dfe90(&DAT_00fab130);
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    uStack_c = 1;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    uStack_c = 0xffffffff;
  }
  uVar1 = DAT_00fab1c0;
  if ((DAT_00fe1a8c & 1) == 0) {
    DAT_00fe1a8c = DAT_00fe1a8c | 1;
    uStack_c = 2;
    FUN_004f9d80();
    _atexit((_func_4879 *)&LAB_00bce930);
    uStack_c = 0xffffffff;
  }
  puVar6 = DAT_00fe1a90;
  if (uVar1 < (uint)((DAT_00fe1a94 - (int)DAT_00fe1a90) / 0x14)) {
    puVar6 = DAT_00fe1a90 + uVar1 * 5;
  }
  fStack_84 = (float)*puVar6;
  fStack_80 = (float)puVar6[1];
  uStack_6c = puVar6[4];
  fStack_7c = (float)puVar6[2];
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    uStack_c = 3;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    uStack_c = 0xffffffff;
  }
  uVar1 = DAT_00fab1c0;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    uStack_c = 4;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    uStack_c = 0xffffffff;
  }
  FUN_004df510(&DAT_00fab130,uVar1 + 50000);
  iVar9 = 0;
  if (0 < (int)piVar5) {
    pfVar10 = (float *)(local_88 + 0x17b5);
    do {
      if (pfVar10[-1] != 0.0) {
        iVar11 = 0;
        uStack_68 = 0;
        uStack_64 = 0;
        D3DXMatrixAffineTransformation2D(auStack_60,0x3f800000,&uStack_68,uStack_6c);
        D3DXVec2TransformCoord(&local_88,pfVar10,auStack_74);
        uVar1 = DAT_00fb7c18 & 1;
        fStack_94 = fStack_94 + fVar4;
        *pfVar10 = fStack_94;
        piStack_90 = (int *)((float)piStack_90 + unaff_EDI);
        pfVar10[1] = (float)piStack_90;
        if (uVar1 == 0) {
          DAT_00fb7c18 = DAT_00fb7c18 | 1;
          FUN_004449d0();
        }
        *(char *)(pfVar10 + 2) = (char)(int)ROUND(_DAT_00fb8824 * fStack_8c);
        if (*(int *)(iVar11 + 0x5ebc) == 0) {
          iVar7 = FUN_0089289d();
          iVar7 = iVar7 % 3 + 0x18;
        }
        else {
          iVar7 = FUN_0089289d();
          iVar7 = iVar7 % 3 + 0x15;
        }
        piVar5 = (int *)FUN_004ba6e0(iVar11);
        (**(code **)(*piVar5 + 0x68))(iVar7,0x3f800000);
        piVar5 = piStack_90;
      }
      iVar9 = iVar9 + 1;
      pfVar10 = pfVar10 + 0xe;
    } while (iVar9 < (int)piVar5);
  }
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    uStack_c = 5;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    uStack_c = 0xffffffff;
  }
  iVar9 = DAT_00fb76e8;
  *(float *)(DAT_00fb76e8 + 0xc) = fStack_84;
  *(float *)(iVar9 + 0x10) = fStack_80;
  *(undefined4 *)(iVar9 + 0xcc) = 0;
  piVar5 = DAT_00fba7a4;
  *(float *)(iVar9 + 0x14) = fStack_7c;
  if (piVar5 != (int *)0x0) {
    if (DAT_00fba7ac == 0) {
      FUN_00544f50();
      goto LAB_004bad1d;
    }
    (**(code **)(*piVar5 + 0x28))();
    if (DAT_00fba7a4 != (int *)0x0) {
      (**(code **)*DAT_00fba7a4)(1);
    }
  }
  piVar5 = (int *)FUN_00891268(0xb4);
  uStack_c = 9;
  piStack_90 = piVar5;
  if (piVar5 == (int *)0x0) {
    DAT_00fba7a4 = (int *)0x0;
  }
  else {
    FUN_00544c40(piVar5);
    *piVar5 = (int)CEmptyController::vftable;
    DAT_00fba7ac = 0;
    DAT_00fba7a4 = piVar5;
  }
  uStack_c = 0xffffffff;
  (**(code **)(*DAT_00fba7a4 + 0x24))();
LAB_004bad1d:
  DAT_00fba7a4[1] = 1;
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    uStack_c = 0xd;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    uStack_c = 0xffffffff;
  }
  uVar8 = FUN_004f6e80();
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    uStack_c = 0xe;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    uStack_c = 0xffffffff;
  }
  sVar2 = DAT_00fb90ea;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    uStack_c = 0xf;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    uStack_c = 0xffffffff;
  }
  piStack_90 = (int *)DAT_00fb935c;
  if ((DAT_00fc0fc0 & 1) == 0) {
    DAT_00fc0fc0 = DAT_00fc0fc0 | 1;
    uStack_c = 0x10;
    FUN_006d8e50();
    _atexit((_func_4879 *)&LAB_00bcdbb0);
    uStack_c = 0xffffffff;
    if ((DAT_00fc0fc0 & 1) == 0) {
      DAT_00fc0fc0 = DAT_00fc0fc0 | 1;
      uStack_c = 0x11;
      FUN_006d8e50();
      _atexit((_func_4879 *)&LAB_00bcdbb0);
      uStack_c = 0xffffffff;
    }
  }
  piStack_90 = (int *)(int)sVar2;
  FUN_008fed10();
  FUN_006daa70();
  uVar3 = FUN_008fed10();
  FUN_006d9b30(&DAT_00fc0fc8,uVar8,0,uVar3);
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    uStack_c = 0x12;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    uStack_c = 0xffffffff;
  }
  fStack_84 = *(float *)(DAT_00fb76e8 + 0xc);
  fStack_80 = *(float *)(DAT_00fb76e8 + 0x10);
  fStack_7c = *(float *)(DAT_00fb76e8 + 0x14);
  if ((DAT_00fb761c & 1) == 0) {
    DAT_00fb761c = DAT_00fb761c | 1;
    uStack_c = 0x13;
    FUN_0054e750();
    _atexit((_func_4879 *)&LAB_00bcd260);
    uStack_c = 0xffffffff;
  }
  DAT_00fb7620 = &DAT_00fb7624;
  FUN_00796ee0();
  puVar6 = DAT_00fb762c;
  if (DAT_00fb762c != DAT_00fb7630) {
    do {
      pfVar10 = (float *)*puVar6;
      puVar6 = puVar6 + 1;
      *pfVar10 = *pfVar10 + fStack_84;
      pfVar10[1] = fStack_80 + pfVar10[1];
      pfVar10[2] = pfVar10[2] + fStack_7c;
    } while (puVar6 != DAT_00fb7630);
  }
  if ((DAT_00fb761c & 1) == 0) {
    DAT_00fb761c = DAT_00fb761c | 1;
    uStack_c = 0x14;
    FUN_0054e750();
    _atexit((_func_4879 *)&LAB_00bcd260);
    uStack_c = 0xffffffff;
  }
  if (DAT_00fb7620 != (int *)0x0) {
    (**(code **)(*DAT_00fb7620 + 8))();
  }
  FUN_006df020();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&fStack_94);
  return;
}

