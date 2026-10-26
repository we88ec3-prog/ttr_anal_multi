
void FUN_006d66b0(int *param_1,undefined4 param_2)

{
  code *pcVar1;
  int iVar2;
  wchar_t ****_Src;
  wchar_t *in_ECX;
  wchar_t *in_EDX;
  wchar_t local_336 [256];
  wchar_t local_136 [51];
  wchar_t local_d0 [62];
  uint local_54;
  wchar_t ***local_4c [4];
  undefined4 local_3c;
  uint local_38;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00942228;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*param_1 != 0) {
    iVar2 = FUN_00495610();
    if (iVar2 == 0) {
      FUN_006ded00();
      iVar2 = FUN_005854b0();
      FUN_005740f0();
      if (in_ECX == *(wchar_t **)(iVar2 + 4)) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      FUN_00404b10();
    }
    else {
      _memset(local_336,0,0x200);
      _memset(local_136,0,0x66);
      _memset(local_d0,0,0x66);
      _wcscpy_s(local_136,0x33,in_EDX);
      FUN_0047f540(param_2);
      local_1c = 0xf;
      local_20 = 0;
      local_30[0] = local_30[0] & 0xffffff00;
      local_8._0_1_ = 1;
      local_8._1_3_ = 0;
      FUN_00733dd0();
      FUN_00403040(local_30,0,0xffffffff);
      FUN_0046e3c0();
      local_8 = CONCAT31(local_8._1_3_,2);
      _Src = (wchar_t ****)local_4c[0];
      if (local_38 < 8) {
        _Src = local_4c;
      }
      _wcscpy_s(local_d0,0x33,(wchar_t *)_Src);
      _wcscpy_s(local_336,0x100,in_ECX);
      (**(code **)(*DAT_00fba854 + 0x10))();
      if (7 < local_38) {
        FUN_0089120c();
      }
      local_38 = 7;
      local_3c = 0;
      local_4c[0] = (wchar_t ***)((uint)local_4c[0] & 0xffff0000);
      if (0xf < local_1c) {
        FUN_0089120c();
      }
      local_1c = 0xf;
      local_20 = 0;
      local_30[0] = local_30[0] & 0xffffff00;
      if (0xf < local_54) {
        FUN_0089120c();
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

