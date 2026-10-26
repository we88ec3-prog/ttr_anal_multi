
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0058b8c0(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_280;
  int local_27c;
  int local_278;
  int local_274;
  int local_264;
  int local_260;
  int local_25c;
  int local_250;
  uint local_220;
  undefined1 local_216 [510];
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009218e5;
  local_10 = ExceptionList;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((*(int *)(*(int *)(param_1 + 0x38) + 0x24) != 0) &&
     (*(int *)(*(int *)(param_1 + 0x38) + 0x14) != 0)) {
    if ((_DAT_00fc183c & 1) == 0) {
      _DAT_00fc183c = _DAT_00fc183c | 1;
      FUN_006f1ff0();
      DAT_00fc18d8 = 1;
      _atexit((_func_4879 *)&LAB_00bce3a0);
    }
    if ((DAT_00fc1840 != DAT_00fc1844) && (*(int *)(DAT_00fc1840 + 8) != 0)) {
      FUN_005cb430();
      piVar2 = (int *)FUN_0048a650();
      if (*piVar2 == piVar2[1]) {
        local_260 = 0;
      }
      else {
        local_260 = *(int *)(*piVar2 + 0x14);
      }
      piVar2 = (int *)FUN_0048a650();
      if (*piVar2 == piVar2[1]) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(*piVar2 + 0xc);
      }
      piVar2 = (int *)FUN_0048a650();
      if (*piVar2 == piVar2[1]) {
        local_264 = 0;
      }
      else {
        local_264 = *(int *)(*piVar2 + 0x10);
      }
      if ((local_260 <= iVar4) && (local_264 == 0)) {
        local_264 = iVar4 - iVar4 % local_260;
      }
      piVar2 = (int *)FUN_0048a650();
      if (*piVar2 == piVar2[1]) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(*piVar2 + 8);
      }
      local_260 = local_264 + local_260;
      if (iVar3 < local_260) {
        piVar2 = (int *)FUN_0048a650();
        if (*piVar2 == piVar2[1]) {
          local_260 = 0;
        }
        else {
          local_260 = *(int *)(*piVar2 + 8);
        }
      }
      iVar5 = local_260 - local_264;
      iVar3 = FUN_006dfc40();
      local_25c = *(int *)(iVar3 + 0x18);
      iVar3 = FUN_006dfc40();
      iVar3 = *(int *)(iVar3 + 0x1c);
      if (local_25c < local_278) {
        local_25c = local_25c - local_280;
      }
      else if (local_25c - local_278 < 200) {
        local_25c = local_280 + -200;
      }
      else {
        local_25c = local_278;
      }
      if (iVar3 < local_274) {
        local_250 = iVar3 + iVar5 * -0x10 + -8;
      }
      else if (iVar3 - local_274 < iVar5 * 0x10) {
        local_250 = local_27c + iVar5 * -0x10 + -8;
      }
      else {
        local_250 = local_274 + 8;
      }
      iVar3 = FUN_0043ffa0();
      uVar1 = *(undefined4 *)(iVar3 + 0x20);
      FUN_0043ffa0();
      FUN_007358b0();
      (**(code **)(**(int **)(param_1 + 0x154) + 0xc))();
      (**(code **)(**(int **)(param_1 + 0x154) + 0xc))();
      (**(code **)(**(int **)(param_1 + 0x154) + 0xc))();
      (**(code **)(**(int **)(param_1 + 0x154) + 0xc))();
      (**(code **)(**(int **)(param_1 + 0x154) + 0xc))();
      (**(code **)(**(int **)(param_1 + 0x154) + 0xc))();
      (**(code **)(**(int **)(param_1 + 0x154) + 0xc))();
      (**(code **)(**(int **)(param_1 + 0x154) + 0xc))();
      (**(code **)(**(int **)(param_1 + 0x154) + 0xc))
                ((float)(local_25c + 200),(float)(iVar5 * 0x10 + local_250),0,0x3f800000,0x3f800000,
                 0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,8,0);
      for (; local_264 < local_260; local_264 = local_264 + 1) {
        _memset(local_216,0,0x1fe);
        if ((_DAT_00fc183c & 1) == 0) {
          _DAT_00fc183c = _DAT_00fc183c | 1;
          FUN_006f1ff0();
          DAT_00fc18d8 = 1;
          _atexit((_func_4879 *)&LAB_00bce3a0);
        }
        FUN_006f2560();
        FUN_0040ef80();
        local_8 = 0;
        if ((DAT_00fb7bc8 & 1) == 0) {
          DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
          local_8._0_1_ = 1;
          local_8._1_3_ = 0;
          FUN_00734ef0();
          _atexit((_func_4879 *)&LAB_00bcd4f0);
          local_8 = (uint)local_8._1_3_ << 8;
        }
        FUN_00735ba0();
        local_8 = 0xffffffff;
        if (7 < local_220) {
          FUN_0089120c();
        }
        if ((DAT_00fb7bc8 & 1) == 0) {
          DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
          local_8 = 2;
          FUN_00734ef0();
          _atexit((_func_4879 *)&LAB_00bcd4f0);
          local_8 = 0xffffffff;
        }
        FUN_00735ba0();
        if (local_264 == iVar4) {
          (**(code **)(**(int **)(param_1 + 0x154) + 0xc))();
          (**(code **)(**(int **)(param_1 + 0x154) + 0xc))();
          (**(code **)(**(int **)(param_1 + 0x154) + 0xc))();
        }
      }
      if ((DAT_00fb7bc8 & 1) == 0) {
        DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
        local_8 = 3;
        FUN_00734ef0();
        _atexit((_func_4879 *)&LAB_00bcd4f0);
      }
      FUN_00736180();
      if ((iVar4 == DAT_00fb7b80) || (DAT_00fb7b90 = uVar1, iVar4 == -0x10)) {
        DAT_00fb7b90 = DAT_00fb7b8c;
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

