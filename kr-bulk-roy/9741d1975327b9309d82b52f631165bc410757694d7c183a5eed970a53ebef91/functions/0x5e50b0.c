
void FUN_005e50b0(undefined4 param_1,int param_2)

{
  wchar_t wVar1;
  short sVar2;
  wchar_t *pwVar3;
  wchar_t *_Str;
  undefined4 uVar4;
  short *psVar5;
  undefined4 *puVar6;
  undefined4 extraout_EDX;
  int iVar7;
  short *psVar8;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  int local_45c;
  wchar_t *local_458;
  undefined4 local_454;
  uint local_440;
  undefined4 local_438;
  undefined4 local_428;
  uint local_424;
  wchar_t local_41c [260];
  short local_214;
  undefined1 local_212 [510];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  iVar7 = DAT_00fc0e34;
  local_8 = -1;
  puStack_c = &LAB_00916616;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_005740f0(&local_458);
  uVar4 = extraout_EDX;
  if (local_45c != *(int *)(iVar7 + 0xc)) {
    _Str = (wchar_t *)(local_45c + 0x10);
    if (7 < *(uint *)(local_45c + 0x24)) {
      _Str = *(wchar_t **)_Str;
    }
    if (_Str != (wchar_t *)0x0) {
      local_214 = 0;
      _memset(local_212,0,0x1fe);
      pwVar3 = _wcsstr(_Str,L"%");
      _wcsstr(_Str,L"10x");
      iVar7 = (int)local_41c - (int)_Str;
      do {
        wVar1 = *_Str;
        *(wchar_t *)(iVar7 + (int)_Str) = wVar1;
        _Str = _Str + 1;
      } while (wVar1 != L'\0');
      local_458 = (wchar_t *)0x0;
      _wcstok_s(local_41c,L"(",&local_458);
      if (local_458 != (wchar_t *)0x0) {
        *local_458 = L'\0';
      }
      psVar8 = &DAT_00c02bac;
      if (param_2 < 0) {
        psVar8 = &DAT_00bed1fc;
      }
      local_438 = (undefined4 *)((uint)local_438._2_2_ << 0x10);
      local_428 = 0;
      local_424 = 7;
      psVar5 = psVar8;
      do {
        sVar2 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar2 != 0);
      FUN_00402160(psVar8,(int)psVar5 - (int)(psVar8 + 1) >> 1);
      local_8 = 0;
      uVar4 = FUN_0040ef80();
      local_8._0_1_ = 1;
      FUN_004041f0(uVar4,0,0xffffffff);
      local_8 = (uint)local_8._1_3_ << 8;
      if (7 < local_440) {
        FUN_0089120c(local_454);
      }
      psVar8 = &DAT_00c02ba8;
      if (pwVar3 == (wchar_t *)0x0) {
        psVar8 = &DAT_00bed1fc;
      }
      psVar5 = psVar8;
      do {
        sVar2 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar2 != 0);
      FUN_00404300(psVar8,(int)psVar5 - (int)(psVar8 + 1) >> 1);
      puVar6 = local_438;
      if (local_424 < 8) {
        puVar6 = &local_438;
      }
      FUN_0040aeb0(L"%s : %s",local_41c,puVar6);
      psVar8 = &local_214;
      do {
        sVar2 = *psVar8;
        psVar8 = psVar8 + 1;
      } while (sVar2 != 0);
      FUN_00404300(&local_214,(int)psVar8 - (int)local_212 >> 1);
      uVar4 = extraout_EDX_00;
      if (7 < local_424) {
        FUN_0089120c(local_438);
        uVar4 = extraout_EDX_01;
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc,uVar4,param_1);
  return;
}

