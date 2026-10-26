
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00672180(int *param_1)

{
  ushort uVar1;
  short sVar2;
  code *pcVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  short *psVar7;
  short *psVar8;
  wchar_t *_Src;
  ushort *puVar9;
  undefined2 auStack_ac [8];
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined1 auStack_90 [20];
  undefined4 uStack_7c;
  undefined1 *puStack_5c;
  undefined1 *puStack_58;
  int *local_54;
  undefined1 *puStack_50;
  undefined2 uStack_4c;
  wchar_t awStack_46 [21];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00932fa0;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&puStack_5c;
  ExceptionList = &local_14;
  iVar6 = param_1[0x3c];
  local_54 = param_1;
  if (*(char *)(iVar6 + 0x141) != '\0') {
    FUN_006edb10();
  }
  if (*(uint *)(iVar6 + 0x11c) < 8) {
    puVar9 = (ushort *)(iVar6 + 0x108);
  }
  else {
    puVar9 = *(ushort **)(iVar6 + 0x108);
  }
  if ((DAT_00fb75c0 & 1) == 0) {
    DAT_00fb75c0 = DAT_00fb75c0 | 1;
    local_c = 0;
    FUN_0081e5f0();
    _atexit((_func_4879 *)&LAB_00bcd250);
    local_c = 0xffffffff;
  }
  if (puVar9 != (ushort *)0x0) {
    uVar1 = *puVar9;
    while (uVar1 != 0) {
      uVar5 = (uint)*puVar9;
      if (*puVar9 < 0x80) {
        if (((9 < uVar5 - 0x30) && (0x19 < uVar5 - 0x41)) && (0x19 < uVar5 - 0x61))
        goto LAB_006722c5;
      }
      else {
        iVar6 = (**(code **)(*DAT_00fb7608 + 8))();
        if (iVar6 == 0) goto LAB_006722c5;
      }
      puVar9 = puVar9 + 1;
      uVar1 = *puVar9;
    }
    uStack_7c = 0x672279;
    iVar6 = FUN_0081eb80();
    if (iVar6 == 0) {
      uStack_7c = 0x67228d;
      iVar6 = FUN_0081eb80();
      if (iVar6 == 0) {
        uStack_7c = 0x6722a1;
        iVar6 = FUN_0081eb80();
        if (iVar6 == 0) {
          uStack_7c = 0x6722b5;
          iVar6 = FUN_0081eb80();
          piVar4 = local_54;
          if (iVar6 == 0) {
            iVar6 = local_54[0x3c];
            if (*(char *)(iVar6 + 0x141) != '\0') {
              FUN_006edb10();
            }
            if (*(uint *)(iVar6 + 0x11c) < 8) {
              _Src = (wchar_t *)(iVar6 + 0x108);
            }
            else {
              _Src = *(wchar_t **)(iVar6 + 0x108);
            }
            if ((_DAT_00fb1314 & 1) == 0) {
              _DAT_00fb1314 = _DAT_00fb1314 | 1;
              _atexit((_func_4879 *)&DAT_00bccf10);
            }
            uStack_4c = 0x3e;
            uStack_7c = 0x67251c;
            _wcscpy_s(awStack_46,0x15,_Src);
            if (DAT_00fba798 == 0) {
              uStack_7c = 0x67253e;
              (**(code **)(*DAT_00fba854 + 0x10))();
            }
            (**(code **)(*piVar4 + 0x90))();
            goto LAB_0067254c;
          }
        }
      }
    }
  }
LAB_006722c5:
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 1;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_c = 2;
    uStack_7c = 0x672313;
    FUN_00584c40();
    uStack_7c = 0x67231d;
    _atexit(FUN_00bcf370);
    local_c = 0xffffffff;
  }
  puStack_58 = &DAT_000001ba;
  uStack_7c = 0x67233f;
  FUN_005740f0();
  if (puStack_5c == DAT_00fe5b10) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  puStack_50 = auStack_90;
  FUN_004068f0();
  local_c = 3;
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_c._0_1_ = 4;
    local_c._1_3_ = 0;
    uStack_98 = 0x6723c8;
    FUN_00584c40();
    uStack_98 = 0x6723d2;
    _atexit(FUN_00bcf370);
    local_c = CONCAT31(local_c._1_3_,3);
  }
  puStack_5c = (undefined1 *)0x2;
  uStack_98 = 0x6723f7;
  FUN_005740f0();
  if (puStack_58 == DAT_00fe5b10) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  psVar8 = (short *)(puStack_58 + 0x10);
  if (7 < *(uint *)(puStack_58 + 0x24)) {
    psVar8 = *(short **)psVar8;
  }
  puStack_5c = (undefined1 *)auStack_ac;
  uStack_98 = 7;
  uStack_9c = 0;
  auStack_ac[0] = 0;
  psVar7 = psVar8;
  do {
    sVar2 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar2 != 0);
  FUN_00402160(psVar8,(int)psVar7 - (int)(psVar8 + 1) >> 1);
  local_c = 0xffffffff;
  FUN_0058b270(0xca);
  iVar6 = local_54[0x3c];
  if (*(char *)(iVar6 + 0x141) == '\0') {
    FUN_00757710();
  }
  else {
    FUN_006edb10();
  }
  *(undefined4 *)(iVar6 + 0x168) = 0;
  *(undefined4 *)(iVar6 + 0x160) = 0;
  *(undefined4 *)(iVar6 + 0x164) = 0;
  *(undefined4 *)(iVar6 + 0x14c) = 0;
LAB_0067254c:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&puStack_5c);
  return;
}

