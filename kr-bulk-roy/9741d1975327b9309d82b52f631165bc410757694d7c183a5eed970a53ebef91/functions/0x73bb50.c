
void FUN_0073bb50(int *param_1,wchar_t *param_2)

{
  int *piVar1;
  int iVar2;
  HFONT pHVar3;
  DWORD DVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int in_ECX;
  LOGFONTW *pLVar7;
  LONG *pLVar8;
  LOGFONTW local_64;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar2 = FUN_0073bac0(param_2);
  if (iVar2 < 0) {
    _memset(&local_64,0,0x5c);
    _wcsncpy_s(local_64.lfFaceName,0x20,param_2,0x1f);
    local_64.lfHeight = *(LONG *)(param_2 + 0x22);
    local_64.lfWidth = *(LONG *)(param_2 + 0x20);
    local_64.lfWeight = FUN_0073ba50();
    if (*(int *)(param_2 + 0x26) == 0) {
      local_64.lfQuality = '\x03';
    }
    else {
      local_64.lfQuality = '\x04';
    }
    pHVar3 = CreateFontIndirectW(&local_64);
    if (pHVar3 == (HFONT)0x0) {
      DVar4 = GetLastError();
      FID_conflict__wprintf("RegisterFont failed (ERR %u)",DVar4);
    }
    puVar5 = (undefined4 *)FUN_00891268(0xb4);
    puVar6 = (undefined4 *)0x0;
    if (puVar5 != (undefined4 *)0x0) {
      puVar5[0x10] = 0;
      puVar5[0x11] = 0;
      puVar5[0x12] = 0;
      puVar5[0x13] = 0;
      _memset(puVar5,0,0x40);
      puVar6 = puVar5;
    }
    puVar5 = puVar6;
    for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *(undefined4 *)param_2;
      param_2 = param_2 + 2;
      puVar5 = puVar5 + 1;
    }
    pLVar7 = &local_64;
    pLVar8 = puVar6 + 0x14;
    for (iVar2 = 0x17; iVar2 != 0; iVar2 = iVar2 + -1) {
      *pLVar8 = pLVar7->lfHeight;
      pLVar7 = (LOGFONTW *)&pLVar7->lfWidth;
      pLVar8 = pLVar8 + 1;
    }
    puVar6[0x2b] = pHVar3;
    puVar6[0x2c] = 1;
    FUN_007bb350();
    *param_1 = (*(int *)(in_ECX + 0x1c) - *(int *)(in_ECX + 0x18) >> 2) + -1;
  }
  else {
    piVar1 = (int *)(*(int *)(*(int *)(in_ECX + 0x18) + iVar2 * 4) + 0xb0);
    *piVar1 = *piVar1 + 1;
    FUN_005719b0();
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

