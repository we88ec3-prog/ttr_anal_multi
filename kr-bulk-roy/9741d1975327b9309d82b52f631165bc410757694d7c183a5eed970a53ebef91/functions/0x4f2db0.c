
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004f2db0(wchar_t *param_1)

{
  short sVar1;
  code *pcVar2;
  int iVar3;
  short *psVar4;
  short *psVar5;
  undefined2 local_a4 [8];
  undefined4 local_94;
  undefined2 *local_90;
  undefined2 local_88 [8];
  undefined4 local_78;
  undefined4 local_74;
  undefined1 *local_54;
  undefined4 local_50;
  undefined1 *local_4c;
  undefined2 local_48;
  wchar_t local_46 [21];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009403a0;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_54;
  ExceptionList = &local_14;
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_c = 0;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  iVar3 = FUN_004f6dc0();
  if (iVar3 == DAT_00f93930) {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 2;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_c = 0xffffffff;
    }
    local_4c = (undefined1 *)local_88;
    local_74 = 7;
    local_78 = 0;
    local_90 = &DAT_00bed1fc;
    local_88[0] = 0;
    local_94 = 0x4f2ebd;
    FUN_00402160();
    local_c = 3;
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c._0_1_ = 4;
      local_c._1_3_ = 0;
      local_90 = (undefined2 *)0x4f2ee8;
      FUN_00584c40();
      local_90 = (undefined2 *)0x4f2ef2;
      _atexit(FUN_00bcf370);
      local_c = CONCAT31(local_c._1_3_,3);
    }
    local_50 = 0x117;
    local_90 = (undefined2 *)0x4f2f14;
    FUN_005740f0();
    if (local_54 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar5 = (short *)(local_54 + 0x10);
    if (7 < *(uint *)(local_54 + 0x24)) {
      psVar5 = *(short **)psVar5;
    }
    local_54 = (undefined1 *)local_a4;
    local_90 = (undefined2 *)0x7;
    local_94 = 0;
    local_a4[0] = 0;
    psVar4 = psVar5;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar5,(int)psVar4 - (int)(psVar5 + 1) >> 1);
    local_c = 0xffffffff;
    FUN_0058b270(0xca);
  }
  else {
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    local_48 = 0xb2;
    local_74 = 0x4f2fb5;
    _wcscpy_s(local_46,0x15,param_1);
    if (DAT_00fba798 == 0) {
      local_74 = 0x4f2fd7;
      (**(code **)(*DAT_00fba854 + 0x10))();
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_54);
  return;
}

