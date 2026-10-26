
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffff90 : 0x00501b25 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_005018b0(void)

{
  short sVar1;
  code *pcVar2;
  short *psVar3;
  int iVar4;
  undefined4 *****pppppuVar5;
  int in_ECX;
  undefined2 local_80 [8];
  undefined4 ****local_70;
  short *local_6c;
  uint in_stack_ffffffa4;
  undefined1 *local_50 [6];
  uint local_38;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009299d6;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffff0000;
  local_8 = 0;
  switch(*(undefined4 *)(in_ECX + 0x84)) {
  case 0:
    local_6c = (short *)0x501912;
    FUN_00585620();
    local_6c = (short *)0x501919;
    local_6c = (short *)FUN_00585330();
    psVar3 = local_6c;
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
    break;
  case 1:
    local_6c = (short *)0x501937;
    FUN_00585620();
    local_6c = (short *)0x50193e;
    local_6c = (short *)FUN_00585330();
    psVar3 = local_6c;
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
    break;
  case 2:
    local_6c = (short *)0x50195a;
    FUN_00585620();
    local_6c = (short *)0x501961;
    local_6c = (short *)FUN_00585330();
    psVar3 = local_6c;
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
    break;
  default:
    goto switchD_00501901_caseD_3;
  case 4:
    local_6c = (short *)0x50197d;
    FUN_00585620();
    local_6c = (short *)0x501984;
    local_6c = (short *)FUN_00585330();
    psVar3 = local_6c;
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
  }
  local_70 = (undefined4 ****)0x5019a9;
  FUN_00402160();
  *(undefined4 *)(in_ECX + 0xc0) = 0xffffffff;
switchD_00501901_caseD_3:
  if (*(int *)(in_ECX + 0x84) == 3) {
    local_50[0] = (undefined1 *)local_80;
    *(undefined4 *)(in_ECX + 0xc0) = 0xffffffff;
    local_6c = (short *)0x7;
    local_70 = (undefined4 ****)0x0;
    local_80[0] = 0;
    FUN_004026e0(in_ECX + 0x68,0,0xffffffff);
    FUN_00424c80(L"\'{0}\'");
    local_8._0_1_ = 1;
    local_6c = (short *)0x501a0f;
    FUN_00402800();
    local_8._0_1_ = 0;
    if (7 < local_38) {
      local_6c = (short *)0x501a25;
      FUN_0089120c();
    }
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8._0_1_ = 2;
      local_6c = (short *)0x501a46;
      FUN_00584c40();
      local_6c = (short *)0x501a50;
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8._0_1_ = 0;
    }
    local_6c = (short *)0x501a6e;
    FUN_005740f0();
    if (local_50[0] == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    if (*(uint *)(local_50[0] + 0x24) < 8) {
      psVar3 = (short *)(local_50[0] + 0x10);
      local_6c = psVar3;
    }
    else {
      psVar3 = *(short **)(local_50[0] + 0x10);
      local_6c = psVar3;
    }
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
    local_70 = (undefined4 *****)0x501aaf;
    FUN_00402160();
  }
  else {
    if (*(int *)(in_ECX + 0x84) == 4) {
      local_6c = (short *)&DAT_00bf3a70;
      local_70 = (undefined4 ****)0x501acf;
      FUN_00402160();
      local_6c = (short *)0x7;
      local_70 = (undefined4 *****)0x0;
      local_80[0] = 0;
      FUN_004026e0(local_30,0,0xffffffff);
      local_8._0_1_ = 3;
      local_50[0] = (undefined1 *)0x283;
      iVar4 = FUN_00585620();
      FUN_005740f0(local_50);
      if (local_80 == (undefined2 *)*(undefined1 **)(iVar4 + 4)) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      pppppuVar5 = &local_70;
      if (7 < in_stack_ffffffa4) {
        pppppuVar5 = (undefined4 *****)local_70;
      }
      local_8._0_1_ = 0;
      FUN_00424c80(pppppuVar5);
      local_8._0_1_ = 4;
      local_6c = (short *)0x501b4e;
      FUN_00402800();
    }
    else {
      local_50[0] = (undefined1 *)local_80;
      local_6c = (short *)0x7;
      local_70 = (undefined4 ****)0x0;
      local_80[0] = 0;
      FUN_004026e0(in_ECX + 0x68,0,0xffffffff);
      FUN_00424c80(L"\'{0}\'");
      local_8._0_1_ = 5;
      local_6c = (short *)0x501ba7;
      FUN_00402800();
      local_8._0_1_ = 0;
      if (7 < local_38) {
        local_6c = (short *)0x501bb9;
        FUN_0089120c();
      }
      local_6c = (short *)0x7;
      local_70 = (undefined4 *****)0x0;
      local_80[0] = 0;
      FUN_004026e0(local_30,0,0xffffffff);
      local_8._0_1_ = 6;
      local_50[0] = (undefined1 *)0x283;
      iVar4 = FUN_00585620();
      FUN_005740f0(local_50);
      if (local_80 == (undefined2 *)*(undefined1 **)(iVar4 + 4)) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      pppppuVar5 = &local_70;
      if (7 < in_stack_ffffffa4) {
        pppppuVar5 = (undefined4 *****)local_70;
      }
      local_8._0_1_ = 0;
      FUN_00424c80(pppppuVar5);
      local_8._0_1_ = 7;
      local_6c = (short *)0x501c3b;
      FUN_00402800();
    }
    local_8._0_1_ = 0;
    if (7 < local_38) {
      local_8._0_1_ = 0;
      local_6c = (short *)0x501c4d;
      FUN_0089120c();
    }
  }
  FUN_00553ff0();
  if (7 < local_1c) {
    local_6c = (short *)0x501c66;
    FUN_0089120c();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

