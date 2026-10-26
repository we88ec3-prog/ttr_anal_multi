
void FUN_006647d0(int param_1)

{
  wchar_t wVar1;
  short sVar2;
  int iVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  undefined4 uVar6;
  short *psVar7;
  int in_ECX;
  wchar_t *in_EDX;
  short *psVar8;
  wchar_t *local_258;
  undefined4 local_254;
  undefined4 local_244;
  uint local_240;
  undefined4 local_238;
  undefined4 local_228;
  uint local_224;
  wchar_t local_21c;
  undefined1 local_21a [518];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092a9cc;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pwVar4 = _wcsstr(in_EDX,L"%");
  pwVar5 = _wcsstr(in_EDX,L"+");
  iVar3 = -2 - (int)in_EDX;
  do {
    wVar1 = *in_EDX;
    *(wchar_t *)((int)in_EDX + (int)(local_21a + iVar3)) = wVar1;
    in_EDX = in_EDX + 1;
  } while (wVar1 != L'\0');
  local_258 = (wchar_t *)0x0;
  _wcstok_s(&local_21c,L"(",&local_258);
  if (local_258 != (wchar_t *)0x0) {
    *local_258 = L'\0';
  }
  if ((pwVar5 == (wchar_t *)0x0) || (psVar8 = &DAT_00c02bac, in_ECX < 0)) {
    psVar8 = &DAT_00bed1fc;
  }
  local_254 = (uint)local_254._2_2_ << 0x10;
  local_240 = 7;
  local_244 = 0;
  psVar7 = psVar8;
  do {
    sVar2 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar2 != 0);
  FUN_00402160(psVar8,(int)psVar7 - (int)(psVar8 + 1) >> 1);
  local_8 = 0;
  uVar6 = FUN_0040ef80();
  local_8._0_1_ = 1;
  FUN_004041f0(uVar6,0,0xffffffff);
  local_8._0_1_ = 0;
  if (7 < local_224) {
    FUN_0089120c(local_238);
  }
  psVar8 = &DAT_00c02ba8;
  if (pwVar4 == (wchar_t *)0x0) {
    psVar8 = &DAT_00bed1fc;
  }
  psVar7 = psVar8;
  do {
    sVar2 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar2 != 0);
  FUN_00404300(psVar8,(int)psVar7 - (int)(psVar8 + 1) >> 1);
  pwVar4 = &local_21c;
  local_238 = (uint)local_238._2_2_ << 0x10;
  local_224 = 7;
  local_228 = 0;
  do {
    wVar1 = *pwVar4;
    pwVar4 = pwVar4 + 1;
  } while (wVar1 != L'\0');
  FUN_00402160(&local_21c,(int)pwVar4 - (int)local_21a >> 1);
  iVar3 = *(int *)(param_1 + 0x248);
  local_8._0_1_ = 2;
  FUN_007578f0();
  FUN_00759ed0(iVar3 + 0xe8,&local_238,0x7b,0x7d);
  local_8._0_1_ = 0;
  if (7 < local_224) {
    FUN_0089120c(local_238);
  }
  local_224 = 7;
  local_228 = 0;
  local_238 = local_238 & 0xffff0000;
  FUN_004026e0(&local_254,0,0xffffffff);
  iVar3 = *(int *)(param_1 + 0x24c);
  local_8._0_1_ = 3;
  FUN_007578f0();
  FUN_00759ed0(iVar3 + 0xe8,&local_238,0x7b,0x7d);
  local_8 = (uint)local_8._1_3_ << 8;
  if (7 < local_224) {
    FUN_0089120c(local_238);
  }
  (**(code **)(**(int **)(param_1 + 0x248) + 200))();
  (**(code **)(**(int **)(param_1 + 0x24c) + 200))();
  if (7 < local_240) {
    FUN_0089120c(local_254);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

