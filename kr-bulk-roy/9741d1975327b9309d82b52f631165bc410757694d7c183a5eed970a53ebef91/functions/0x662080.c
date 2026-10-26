
/* WARNING: Type propagation algorithm not settling */

void FUN_00662080(int param_1)

{
  wchar_t wVar1;
  short sVar2;
  ushort uVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  undefined4 uVar6;
  short *psVar7;
  int iVar8;
  ushort *puVar9;
  ushort *puVar10;
  wchar_t *in_EDX;
  short *psVar11;
  bool bVar12;
  wchar_t *local_280 [2];
  uint local_278;
  undefined4 local_268;
  uint local_264;
  undefined4 local_25c;
  undefined4 local_24c;
  uint local_248;
  uint local_240 [4];
  undefined4 local_230;
  uint local_22c;
  wchar_t local_220 [260];
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092aa97;
  local_10 = ExceptionList;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pwVar4 = _wcsstr(in_EDX,L"%");
  pwVar5 = _wcsstr(in_EDX,L"+");
  iVar8 = (int)local_220 - (int)in_EDX;
  do {
    wVar1 = *in_EDX;
    *(wchar_t *)(iVar8 + (int)in_EDX) = wVar1;
    in_EDX = in_EDX + 1;
  } while (wVar1 != L'\0');
  local_280[0] = (wchar_t *)0x0;
  _wcstok_s(local_220,L"(",local_280);
  if (local_280[0] != (wchar_t *)0x0) {
    *local_280[0] = L'\0';
  }
  psVar11 = &DAT_00c02bac;
  if (pwVar5 == (wchar_t *)0x0) {
    psVar11 = &DAT_00bed1fc;
  }
  local_25c = (ushort *)((uint)local_25c._2_2_ << 0x10);
  local_248 = 7;
  local_24c = 0;
  psVar7 = psVar11;
  do {
    sVar2 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar2 != 0);
  FUN_00402160(psVar11,(int)psVar7 - (int)(psVar11 + 1) >> 1);
  local_8 = 0;
  uVar6 = FUN_00662800();
  local_8._0_1_ = 1;
  FUN_004041f0(uVar6,0,0xffffffff);
  local_8._0_1_ = 0;
  if (7 < local_22c) {
    FUN_0089120c(local_240[0]);
  }
  psVar11 = &DAT_00c02ba8;
  if (pwVar4 == (wchar_t *)0x0) {
    psVar11 = &DAT_00bed1fc;
  }
  psVar7 = psVar11;
  do {
    sVar2 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar2 != 0);
  FUN_00404300(psVar11,(int)psVar7 - (int)(psVar11 + 1) >> 1);
  pwVar4 = (wchar_t *)(*(int *)(param_1 + 0x248) + 0xe8);
  if (7 < *(uint *)(*(int *)(param_1 + 0x248) + 0xfc)) {
    pwVar4 = *(wchar_t **)pwVar4;
  }
  pwVar5 = local_220;
  do {
    wVar1 = *pwVar4;
    bVar12 = (ushort)wVar1 < (ushort)*pwVar5;
    if (wVar1 != *pwVar5) {
LAB_00662236:
      iVar8 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
      goto LAB_0066223b;
    }
    if (wVar1 == L'\0') break;
    wVar1 = pwVar4[1];
    bVar12 = (ushort)wVar1 < (ushort)pwVar5[1];
    if (wVar1 != pwVar5[1]) goto LAB_00662236;
    pwVar4 = pwVar4 + 2;
    pwVar5 = pwVar5 + 2;
  } while (wVar1 != L'\0');
  iVar8 = 0;
LAB_0066223b:
  if (iVar8 != 0) {
    pwVar4 = local_220;
    local_240[0] = local_240[0] & 0xffff0000;
    local_22c = 7;
    local_230 = 0;
    do {
      wVar1 = *pwVar4;
      pwVar4 = pwVar4 + 1;
    } while (wVar1 != L'\0');
    FUN_00402160(local_220,(int)pwVar4 - (int)(local_220 + 1) >> 1);
    iVar8 = *(int *)(param_1 + 0x248);
    local_8._0_1_ = 2;
    FUN_007578f0();
    FUN_00759ed0(iVar8 + 0xe8,local_240,0x7b,0x7d);
    local_8._0_1_ = 0;
    if (7 < local_22c) {
      FUN_0089120c(local_240[0]);
    }
    (**(code **)(**(int **)(param_1 + 0x248) + 200))();
  }
  FUN_00662800();
  local_8._0_1_ = 3;
  puVar10 = local_25c;
  if (local_248 < 8) {
    puVar10 = (ushort *)&local_25c;
  }
  puVar9 = (ushort *)(*(int *)(param_1 + 0x24c) + 0xe8);
  if (7 < *(uint *)(*(int *)(param_1 + 0x24c) + 0xfc)) {
    puVar9 = *(ushort **)puVar9;
  }
  do {
    uVar3 = *puVar9;
    bVar12 = uVar3 < *puVar10;
    if (uVar3 != *puVar10) {
LAB_00662346:
      iVar8 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
      goto LAB_0066234b;
    }
    if (uVar3 == 0) break;
    uVar3 = puVar9[1];
    bVar12 = uVar3 < puVar10[1];
    if (uVar3 != puVar10[1]) goto LAB_00662346;
    puVar9 = puVar9 + 2;
    puVar10 = puVar10 + 2;
  } while (uVar3 != 0);
  iVar8 = 0;
LAB_0066234b:
  if (iVar8 != 0) {
    local_22c = 7;
    local_230 = 0;
    local_240[0] = local_240[0] & 0xffff0000;
    FUN_004026e0(&local_25c,0,0xffffffff);
    iVar8 = *(int *)(param_1 + 0x24c);
    local_8._0_1_ = 4;
    FUN_007578f0();
    FUN_00759ed0(iVar8 + 0xe8,local_240,0x7b,0x7d);
    local_8._0_1_ = 3;
    if (7 < local_22c) {
      FUN_0089120c(local_240[0]);
    }
    (**(code **)(**(int **)(param_1 + 0x24c) + 200))();
  }
  if (7 < local_264) {
    FUN_0089120c(local_278);
  }
  local_264 = 7;
  local_268 = 0;
  local_278 = local_278 & 0xffff0000;
  if (7 < local_248) {
    FUN_0089120c(local_25c);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

