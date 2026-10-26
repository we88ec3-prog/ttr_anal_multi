
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004fdcd0(undefined4 *param_1)

{
  void *_Dst;
  HWND hWnd;
  undefined4 *puVar1;
  int in_ECX;
  uint uVar2;
  uint uVar3;
  tagRECT *lpRect;
  undefined1 auStack_5c [4];
  undefined4 *local_58;
  uint local_54;
  tagRECT local_50;
  undefined **local_3c;
  int local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = -1;
  puStack_10 = &LAB_00936776;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_5c;
  ExceptionList = &local_14;
  if (*(int *)(in_ECX + 0x5eac) == 0) {
    local_28 = *param_1;
    local_24 = param_1[1];
    local_20 = param_1[2];
    local_3c = `public:_int___thiscall_CTradeMgr::ScanNearChars(D3DXVECTOR3_const&)'::__l4::Scanner
               ::vftable;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_c = 0;
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c._0_1_ = 1;
      local_c._1_3_ = 0;
      FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffff98);
      _atexit((_func_4879 *)&LAB_00bcce30);
      local_c = (uint)local_c._1_3_ << 8;
    }
    FUN_004e0650(&DAT_00fab130);
    uVar3 = local_34 - local_38 >> 2;
    local_54 = uVar3;
    if (uVar3 == 0) {
      if (local_38 != 0) {
        FUN_0089120c(local_38);
      }
    }
    else {
      local_58 = (undefined4 *)FUN_00464f70();
      _Dst = (void *)*local_58;
      if (_Dst != (void *)local_58[1]) {
        FID_conflict__memcpy(_Dst,(void *)local_58[1],0);
        local_58[1] = _Dst;
        uVar3 = local_54;
      }
      uVar2 = 0;
      if (uVar3 != 0) {
        do {
          puVar1 = *(undefined4 **)(*(int *)(local_38 + uVar2 * 4) + 0x9c);
          if ((_DAT_00fc0d5c & 1) == 0) {
            _DAT_00fc0d5c = _DAT_00fc0d5c | 1;
            DAT_00fc0d60 = 0;
            DAT_00fc0d64 = 0;
            _DAT_00fc0d68 = 0;
            _atexit((_func_4879 *)&LAB_00bcd8c0);
          }
          local_58 = puVar1;
          FUN_004a8680();
          uVar2 = uVar2 + 1;
        } while (uVar2 < local_54);
      }
      lpRect = &local_50;
      hWnd = (HWND)FUN_006dfd60();
      GetClientRect(hWnd,lpRect);
      if ((_DAT_00fc0d5c & 1) == 0) {
        _DAT_00fc0d5c = _DAT_00fc0d5c | 1;
        DAT_00fc0d60 = 0;
        DAT_00fc0d64 = 0;
        _DAT_00fc0d68 = 0;
        _atexit((_func_4879 *)&LAB_00bcd8c0);
      }
      if (DAT_00fc0d60 != DAT_00fc0d64) {
        puVar1 = (undefined4 *)FUN_00891268(0x20);
        if (puVar1 != (undefined4 *)0x0) {
          puVar1[1] = 0xffffffff;
          puVar1[2] = 0xffffffff;
          puVar1[5] = (local_50.right - local_50.left) / 2;
          puVar1[3] = 0;
          puVar1[4] = 0xf431d;
          *puVar1 = FoxUI::FXUIEventI3::vftable;
          puVar1[6] = (local_50.bottom - local_50.top) / 2;
          puVar1[7] = 0;
        }
        FUN_004072a0();
      }
      if (local_38 != 0) {
        FUN_0089120c(local_38);
      }
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_5c);
  return;
}

