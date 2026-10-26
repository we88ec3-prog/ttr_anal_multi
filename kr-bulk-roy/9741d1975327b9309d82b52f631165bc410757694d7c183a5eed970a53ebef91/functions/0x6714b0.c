
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006714b0(void)

{
  undefined4 *puVar1;
  short sVar2;
  void *_Src;
  void *_Dst;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  code *pcVar6;
  int iVar7;
  short *psVar8;
  undefined4 uVar9;
  int in_ECX;
  uint uVar10;
  short *psVar11;
  int iVar12;
  int local_50;
  undefined4 local_44;
  uint local_40;
  int local_3c;
  undefined4 local_38;
  uint local_34;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092cb1a;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_3c = in_ECX;
  if ((DAT_00fe6e78 & 1) == 0) {
    DAT_00fe6e78 = DAT_00fe6e78 | 1;
    local_8._1_3_ = 0;
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8._0_1_ = 1;
      local_8._1_3_ = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_8._0_1_ = 0;
    local_38 = 0x219;
    FUN_005740f0(&local_38);
    if (local_34 == DAT_00fe5ac8) {
      pcVar6 = (code *)swi(3);
      (*pcVar6)();
      return;
    }
    psVar11 = (short *)(local_34 + 0x10);
    if (7 < *(uint *)(local_34 + 0x24)) {
      psVar11 = *(short **)psVar11;
    }
    _DAT_00fe6de4 = 7;
    _DAT_00fe6de0 = 0;
    _DAT_00fe6dd0 = 0;
    psVar8 = psVar11;
    do {
      sVar2 = *psVar8;
      psVar8 = psVar8 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar11,(int)psVar8 - (int)(psVar11 + 1) >> 1);
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8._0_1_ = 3;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_8._0_1_ = 2;
    local_38 = 0x21a;
    FUN_005740f0(&local_38);
    if (local_34 == DAT_00fe5ac8) {
      pcVar6 = (code *)swi(3);
      (*pcVar6)();
      return;
    }
    psVar11 = (short *)(local_34 + 0x10);
    if (7 < *(uint *)(local_34 + 0x24)) {
      psVar11 = *(short **)psVar11;
    }
    _DAT_00fe6dec = 0;
    _DAT_00fe6e00 = 7;
    _DAT_00fe6dfc = 0;
    psVar8 = psVar11;
    do {
      sVar2 = *psVar8;
      psVar8 = psVar8 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar11,(int)psVar8 - (int)(psVar11 + 1) >> 1);
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8._0_1_ = 5;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_8._0_1_ = 4;
    local_38 = 0x21b;
    FUN_005740f0(&local_38);
    if (local_34 == DAT_00fe5ac8) {
      pcVar6 = (code *)swi(3);
      (*pcVar6)();
      return;
    }
    psVar11 = (short *)(local_34 + 0x10);
    if (7 < *(uint *)(local_34 + 0x24)) {
      psVar11 = *(short **)psVar11;
    }
    _DAT_00fe6e08 = 0;
    _DAT_00fe6e1c = 7;
    _DAT_00fe6e18 = 0;
    psVar8 = psVar11;
    do {
      sVar2 = *psVar8;
      psVar8 = psVar8 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar11,(int)psVar8 - (int)(psVar11 + 1) >> 1);
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8._0_1_ = 7;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_8._0_1_ = 6;
    local_38 = 0x21c;
    FUN_005740f0(&local_38);
    if (local_34 == DAT_00fe5ac8) {
      pcVar6 = (code *)swi(3);
      (*pcVar6)();
      return;
    }
    psVar11 = (short *)(local_34 + 0x10);
    if (7 < *(uint *)(local_34 + 0x24)) {
      psVar11 = *(short **)psVar11;
    }
    _DAT_00fe6e24 = 0;
    _DAT_00fe6e38 = 7;
    _DAT_00fe6e34 = 0;
    psVar8 = psVar11;
    do {
      sVar2 = *psVar8;
      psVar8 = psVar8 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar11,(int)psVar8 - (int)(psVar11 + 1) >> 1);
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8._0_1_ = 9;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_8._0_1_ = 8;
    local_38 = 0x21d;
    FUN_005740f0(&local_38);
    if (local_34 == DAT_00fe5ac8) {
      pcVar6 = (code *)swi(3);
      (*pcVar6)();
      return;
    }
    psVar11 = (short *)(local_34 + 0x10);
    if (7 < *(uint *)(local_34 + 0x24)) {
      psVar11 = *(short **)psVar11;
    }
    _DAT_00fe6e40 = 0;
    _DAT_00fe6e54 = 7;
    _DAT_00fe6e50 = 0;
    psVar8 = psVar11;
    do {
      sVar2 = *psVar8;
      psVar8 = psVar8 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar11,(int)psVar8 - (int)(psVar11 + 1) >> 1);
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8._0_1_ = 0xb;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_8 = CONCAT31(local_8._1_3_,10);
    local_38 = 0x21e;
    FUN_005740f0(&local_38);
    if (local_34 == DAT_00fe5ac8) {
      pcVar6 = (code *)swi(3);
      (*pcVar6)();
      return;
    }
    psVar11 = (short *)(local_34 + 0x10);
    if (7 < *(uint *)(local_34 + 0x24)) {
      psVar11 = *(short **)psVar11;
    }
    _DAT_00fe6e5c = 0;
    _DAT_00fe6e70 = 7;
    _DAT_00fe6e6c = 0;
    psVar8 = psVar11;
    do {
      sVar2 = *psVar8;
      psVar8 = psVar8 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar11,(int)psVar8 - (int)(psVar11 + 1) >> 1);
    _atexit((_func_4879 *)&LAB_00bcfe90);
  }
  iVar7 = local_3c;
  local_8 = 0xffffffff;
  iVar12 = *(int *)(*(int *)(local_3c + 0xf4) + 0xcc);
  if (iVar12 == 0) {
    local_38 = 0xffffffff;
  }
  else {
    iVar12 = *(int *)(iVar12 + 0xdc);
    if (iVar12 == 0) {
      local_38 = 0xffffffff;
    }
    else {
      local_38 = *(undefined4 *)(iVar12 + 0x20);
    }
  }
  iVar12 = *(int *)(*(int *)(local_3c + 0xf4) + 0xcc);
  if (iVar12 != 0) {
    FUN_006438f0(iVar12);
  }
  _Src = *(void **)(iVar7 + 0x100);
  _Dst = *(void **)(iVar7 + 0xfc);
  if (_Dst != _Src) {
    FID_conflict__memcpy(_Dst,_Src,0);
    *(void **)(local_3c + 0x100) = _Dst;
  }
  uVar10 = *(int *)(DAT_00fe1a88 + 0xc) - *(int *)(DAT_00fe1a88 + 8) >> 3;
  local_40 = 0;
  iVar12 = DAT_00fe1a88;
  local_34 = uVar10;
  if (uVar10 != 0) {
    do {
      if ((local_40 < (uint)(*(int *)(iVar12 + 0xc) - *(int *)(iVar12 + 8) >> 3)) &&
         (puVar1 = (undefined4 *)(*(int *)(iVar12 + 8) + local_40 * 8), puVar1 != (undefined4 *)0x0)
         ) {
        iVar12 = *(int *)(*(int *)(local_3c + 0xf4) + 0xcc);
        if (iVar12 != 0) {
          FUN_00412c70(*(undefined4 *)(iVar12 + 0xe4));
        }
        FUN_0043c570(0x44c);
        FUN_0043c570(0x4b0);
        if ((DAT_00fe5ae4 & 1) == 0) {
          DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
          local_8 = 0xc;
          FUN_00584c40(&DAT_00fe5ac4);
          _atexit((_func_4879 *)&LAB_00bcf390);
          local_8 = 0xffffffff;
        }
        local_44 = 0x13c;
        FUN_005740f0(&local_44);
        if (local_50 == DAT_00fe5ac8) {
          pcVar6 = (code *)swi(3);
          (*pcVar6)();
          return;
        }
        uVar9 = FUN_004068f0();
        local_8 = 0xd;
        FUN_00757800(uVar9);
        local_8 = 0xffffffff;
        if (7 < local_1c) {
          FUN_0089120c(local_30);
        }
        local_30 = local_30 & 0xffff0000;
        local_1c = 7;
        local_20 = 0;
        FUN_00757800(&DAT_00fe6dd0 + puVar1[1] * 0x1c);
        iVar12 = local_3c;
        puVar3 = *(undefined4 **)(local_3c + 0x100);
        if ((puVar1 < puVar3) && (puVar4 = *(undefined4 **)(local_3c + 0xfc), puVar4 <= puVar1)) {
          if (puVar3 == *(undefined4 **)(local_3c + 0x104)) {
            FUN_006d6240();
          }
          if (*(undefined4 **)(iVar12 + 0x100) != (undefined4 *)0x0) {
            **(undefined4 **)(iVar12 + 0x100) =
                 *(undefined4 *)(*(int *)(iVar12 + 0xfc) + ((int)puVar1 - (int)puVar4 >> 2) * 4);
          }
        }
        else {
          if (puVar3 == *(undefined4 **)(local_3c + 0x104)) {
            FUN_006d6240();
          }
          if (*(undefined4 **)(iVar12 + 0x100) != (undefined4 *)0x0) {
            **(undefined4 **)(iVar12 + 0x100) = *puVar1;
          }
        }
        *(int *)(iVar12 + 0x100) = *(int *)(iVar12 + 0x100) + 4;
        uVar10 = local_34;
        iVar12 = DAT_00fe1a88;
      }
      local_40 = local_40 + 1;
    } while (local_40 < uVar10);
  }
  piVar5 = *(int **)(local_3c + 0xf4);
  puVar1 = (undefined4 *)piVar5[0x19];
  for (puVar3 = (undefined4 *)*puVar1; puVar3 != puVar1; puVar3 = (undefined4 *)*puVar3) {
    iVar12 = puVar3[2];
    if ((*(int *)(iVar12 + 0x60) != 0) && ((*(int **)(iVar12 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar12 + 0x1c) + 0x30))(iVar12);
    }
  }
  (**(code **)(*piVar5 + 0x128))();
  if (*(int *)(*(int *)(local_3c + 0xf4) + 0xcc) != 0) {
    FUN_0042c8e0(local_38);
  }
  (**(code **)(**(int **)(local_3c + 0xf4) + 200))();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

