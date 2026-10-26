
/* WARNING: Removing unreachable block (ram,0x00612580) */

void FUN_00612190(undefined4 param_1,byte param_2)

{
  int iVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  undefined4 *in_ECX;
  int iVar5;
  undefined4 uVar6;
  int local_128;
  uint local_120;
  uint local_11c;
  uint local_54;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091d655;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  in_ECX[4] = 0;
  if (7 < (uint)in_ECX[5]) {
    in_ECX = (undefined4 *)*in_ECX;
  }
  uVar3 = DAT_00fb11a8 & 1;
  *(undefined2 *)in_ECX = 0;
  if (uVar3 == 0) {
    DAT_00fb11a8 = DAT_00fb11a8 | 1;
    local_8 = 0;
    FUN_00813890();
    _atexit((_func_4879 *)&LAB_00bccec0);
  }
  local_8 = 0xffffffff;
  FUN_0082ef00();
  if ((local_11c != DAT_00fb11b0) && (iVar1 = *(int *)(local_11c + 0x10), iVar1 != 0)) {
    uVar3 = (uint)param_2;
    if (uVar3 < (uint)(*(int *)(iVar1 + 0x18) - *(int *)(iVar1 + 0x14) >> 2)) {
      iVar5 = *(int *)(*(int *)(iVar1 + 0x14) + uVar3 * 4);
      local_11c = *(int *)(iVar5 + 8) - *(int *)(iVar5 + 4) >> 2;
    }
    else {
      local_11c = 0;
    }
    local_120 = 0;
    if (local_11c != 0) {
      do {
        iVar5 = *(int *)(*(int *)(iVar1 + 0x14) + uVar3 * 4);
        if (local_120 < (uint)(*(int *)(iVar5 + 8) - *(int *)(iVar5 + 4) >> 2)) {
          iVar5 = *(int *)(*(int *)(iVar5 + 4) + local_120 * 4);
        }
        else {
          iVar5 = 0;
        }
        switch(*(undefined4 *)(iVar5 + 4)) {
        case 0:
          iVar5 = FUN_00585620();
          FUN_005740f0();
          if (local_128 == *(int *)(iVar5 + 4)) {
            pcVar2 = (code *)swi(3);
            (*pcVar2)();
            return;
          }
          FUN_004068f0();
          local_8 = 1;
          FUN_004041f0();
          local_8 = 0xffffffff;
          if (7 < local_54) {
            FUN_0089120c();
          }
          local_54 = 7;
          break;
        case 1:
          local_8 = 2;
          FUN_00611aa0();
          local_1c = 7;
          local_20 = 0;
          local_30[0] = local_30[0] & 0xffff0000;
          local_8._0_1_ = 3;
          FUN_00611c70();
          if (*(int *)(iVar5 + 0xc) == 0) {
LAB_006124d4:
            if (*(int *)(iVar5 + 0x10) != 0) {
              FUN_00402110();
              local_8._0_1_ = 10;
              FUN_00402110(local_30);
              uVar6 = 0x2d0;
              local_8._0_1_ = 0xb;
              FUN_00585620(0x2d0);
              uVar6 = FUN_00585330(uVar6);
              local_8._0_1_ = 3;
              FUN_00613000(uVar6);
              local_8._0_1_ = 0xc;
              FUN_004041f0();
              goto LAB_00612546;
            }
          }
          else {
            if (*(int *)(iVar5 + 0x10) == 0) {
              if (*(int *)(iVar5 + 0xc) == 0) goto LAB_006124d4;
              FUN_004026e0();
              local_8._0_1_ = 7;
              FUN_004026e0(local_30,0,0xffffffff);
              uVar6 = 0x2cf;
              local_8._0_1_ = 8;
              FUN_00585620(0x2cf);
              uVar6 = FUN_00585330(uVar6);
              local_8._0_1_ = 3;
              FUN_00613000(uVar6);
              local_8._0_1_ = 9;
              FUN_004041f0();
            }
            else {
              FUN_00402110();
              local_8._0_1_ = 4;
              FUN_00402110(local_30);
              uVar6 = 0x2ce;
              local_8._0_1_ = 5;
              FUN_00585620(0x2ce);
              uVar6 = FUN_00585330(uVar6);
              local_8._0_1_ = 3;
              FUN_00612f20(uVar6);
              local_8._0_1_ = 6;
              FUN_004041f0();
            }
LAB_00612546:
            FUN_004fa440();
          }
          if (7 < local_1c) {
            FUN_0089120c();
          }
          local_30[0] = local_30[0] & 0xffff0000;
          local_8 = 0xffffffff;
          local_1c = 7;
          local_20 = 0;
          break;
        case 2:
          goto switchD_006122d5_caseD_2;
        case 3:
          if ((DAT_00fc1094 & 1) == 0) {
            DAT_00fc1094 = DAT_00fc1094 | 1;
            local_8 = 0xd;
            FUN_0052f7e0();
            _atexit((_func_4879 *)&LAB_00bcdc80);
            local_8 = 0xffffffff;
          }
          iVar4 = FUN_005300f0();
          if (iVar4 != 0) {
            if (*(int *)(iVar5 + 0xc) == 0) {
LAB_00612687:
              if (*(int *)(iVar5 + 0x10) == 0) break;
              FUN_00585620();
              FUN_00585330();
              FUN_00613110();
              local_8 = 0x10;
              FUN_004041f0();
            }
            else if (*(int *)(iVar5 + 0x10) == 0) {
              if (*(int *)(iVar5 + 0xc) == 0) goto LAB_00612687;
              FUN_00585620();
              FUN_00585330();
              FUN_00613110();
              local_8 = 0xf;
              FUN_004041f0();
            }
            else {
              FUN_00585620();
              FUN_00585330();
              FUN_006130e0();
              local_8 = 0xe;
              FUN_004041f0();
            }
            local_8 = 0xffffffff;
            FUN_004fa440();
          }
        }
        if (local_120 + 1 < local_11c) {
          FUN_00404300();
        }
switchD_006122d5_caseD_2:
        local_120 = local_120 + 1;
      } while (local_120 < local_11c);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

