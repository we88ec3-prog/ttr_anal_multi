
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ecef0(void)

{
  short sVar1;
  code *pcVar2;
  uint uVar3;
  short *psVar4;
  int in_ECX;
  wchar_t ****_Src;
  short *in_EDX;
  wchar_t ****ppppwVar5;
  short *psVar6;
  uint uVar7;
  undefined2 local_22c [8];
  undefined4 local_21c;
  undefined2 *local_218;
  undefined2 local_210 [8];
  undefined4 local_200;
  undefined4 local_1fc;
  undefined1 *local_1e0;
  undefined4 local_1dc;
  undefined1 *local_1d8;
  wchar_t ***local_1d4 [4];
  uint local_1c4;
  uint local_1c0;
  undefined2 local_1b8;
  wchar_t local_1b6 [205];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00940460;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_1e0;
  ExceptionList = &local_14;
  if (*(int *)(in_ECX + 0x5ec0) != 0) {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    local_c = 0xffffffff;
    if (*(int *)(in_ECX + 0x5ec8) == DAT_00f93930) {
      local_1c0 = 7;
      local_1c4 = 0;
      local_1d4[0] = (wchar_t ***)((uint)local_1d4[0] & 0xffff0000);
      do {
        sVar1 = *in_EDX;
        in_EDX = in_EDX + 1;
      } while (sVar1 != 0);
      FUN_00402160();
      local_c = 4;
      uVar3 = 0;
      _Src = (wchar_t ****)local_1d4[0];
      uVar7 = local_1c0;
      if (local_1c4 != 0) {
        do {
          ppppwVar5 = _Src;
          if (uVar7 < 8) {
            ppppwVar5 = local_1d4;
          }
          if (*(short *)((int)ppppwVar5 + uVar3 * 2) == 0x27) {
            if (uVar7 < 8) {
              _Src = local_1d4;
            }
            *(undefined2 *)((int)_Src + uVar3 * 2) = 0xb4;
            _Src = (wchar_t ****)local_1d4[0];
            uVar7 = local_1c0;
          }
          uVar3 = uVar3 + 1;
        } while (uVar3 < local_1c4);
      }
      if (uVar7 < 8) {
        _Src = local_1d4;
      }
      if ((_DAT_00fb1314 & 1) == 0) {
        _DAT_00fb1314 = _DAT_00fb1314 | 1;
        _atexit((_func_4879 *)&DAT_00bccf10);
      }
      local_1b8 = 0xbc0;
      local_1fc = 0x4ed055;
      _wcscpy_s(local_1b6,0xc9,(wchar_t *)_Src);
      if (DAT_00fba798 == 0) {
        local_1fc = 0x4ed07a;
        (**(code **)(*DAT_00fba854 + 0x10))();
      }
      if (7 < local_1c0) {
        FUN_0089120c();
      }
      goto LAB_004ed1c4;
    }
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 1;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_c = 0xffffffff;
  local_1d8 = (undefined1 *)local_210;
  local_1fc = 7;
  local_200 = 0;
  local_218 = &DAT_00bed1fc;
  local_210[0] = 0;
  local_21c = 0x4ed0fc;
  FUN_00402160();
  local_c = 2;
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_c._0_1_ = 3;
    local_c._1_3_ = 0;
    local_218 = (undefined2 *)0x4ed128;
    FUN_00584c40();
    local_218 = (undefined2 *)0x4ed132;
    _atexit(FUN_00bcf370);
    local_c = CONCAT31(local_c._1_3_,2);
  }
  local_1dc = 4;
  local_218 = (undefined2 *)0x4ed158;
  FUN_005740f0();
  if (local_1e0 == DAT_00fe5b10) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  psVar6 = (short *)(local_1e0 + 0x10);
  if (7 < *(uint *)(local_1e0 + 0x24)) {
    psVar6 = *(short **)psVar6;
  }
  local_1e0 = (undefined1 *)local_22c;
  local_218 = (undefined2 *)0x7;
  local_21c = 0;
  local_22c[0] = 0;
  psVar4 = psVar6;
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar6,(int)psVar4 - (int)(psVar6 + 1) >> 1);
  local_c = 0xffffffff;
  FUN_0058b270(0xca);
LAB_004ed1c4:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_1e0);
  return;
}

