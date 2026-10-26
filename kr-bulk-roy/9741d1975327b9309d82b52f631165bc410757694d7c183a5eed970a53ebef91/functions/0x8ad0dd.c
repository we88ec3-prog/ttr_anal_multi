
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

void FUN_008ad0dd(void)

{
  char cVar1;
  char cVar2;
  long lVar3;
  errno_t eVar4;
  UINT CodePage;
  char *_Str1;
  int iVar5;
  size_t sVar6;
  DWORD DVar7;
  int *piVar8;
  long lVar9;
  char *pcVar10;
  int local_34;
  int local_30;
  long local_2c;
  long local_28;
  int *local_24;
  long local_20 [5];
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_00c85618;
  uStack_c = 0x8ad0e9;
  local_30 = 0;
  local_20[0] = 0;
  local_28 = 0;
  local_2c = 0;
  local_24 = (int *)0x0;
  __lock(7);
  local_8 = (undefined *)0x0;
  local_24 = (int *)FUN_008ad0d7();
  eVar4 = FID_conflict___get_dstbias(local_20);
  if (((eVar4 != 0) || (eVar4 = FID_conflict___get_dstbias(&local_28), eVar4 != 0)) ||
     (eVar4 = FID_conflict___get_dstbias(&local_2c), eVar4 != 0)) goto LAB_008ad1e1;
  CodePage = ____lc_codepage_func();
  DAT_00f8d734 = 0;
  DAT_00d62a84 = 0xffffffff;
  DAT_00d62a78 = 0xffffffff;
  _Str1 = __getenv_helper_nolock("TZ");
  if ((_Str1 == (char *)0x0) || (*_Str1 == '\0')) {
    if (DAT_00f8d738 != (char *)0x0) {
      _free(DAT_00f8d738);
      DAT_00f8d738 = (char *)0x0;
    }
    DVar7 = GetTimeZoneInformation((LPTIME_ZONE_INFORMATION)&DAT_00f8d688);
    if (DVar7 != 0xffffffff) {
      DAT_00f8d734 = 1;
      local_20[0] = DAT_00f8d688 * 0x3c;
      if (DAT_00f8d6ce != 0) {
        local_20[0] = local_20[0] + DAT_00f8d6dc * 0x3c;
      }
      if ((DAT_00f8d722 == 0) || (DAT_00f8d730 == 0)) {
        local_28 = 0;
        local_2c = 0;
      }
      else {
        local_28 = 1;
        local_2c = (DAT_00f8d730 - DAT_00f8d6dc) * 0x3c;
      }
      iVar5 = WideCharToMultiByte(CodePage,0,(LPCWSTR)&DAT_00f8d68c,-1,(LPSTR)*local_24,0x3f,
                                  (LPCSTR)0x0,&local_34);
      if ((iVar5 == 0) || (local_34 != 0)) {
        *(undefined1 *)*local_24 = 0;
      }
      else {
        *(undefined1 *)(*local_24 + 0x3f) = 0;
      }
      iVar5 = WideCharToMultiByte(CodePage,0,(LPCWSTR)&DAT_00f8d6e0,-1,(LPSTR)local_24[1],0x3f,
                                  (LPCSTR)0x0,&local_34);
      if ((iVar5 == 0) || (local_34 != 0)) {
        *(undefined1 *)local_24[1] = 0;
      }
      else {
        *(undefined1 *)(local_24[1] + 0x3f) = 0;
      }
    }
LAB_008ad2d6:
    local_30 = 1;
  }
  else {
    if (DAT_00f8d738 != (char *)0x0) {
      iVar5 = _strcmp(_Str1,DAT_00f8d738);
      if (iVar5 == 0) goto LAB_008ad2d6;
      if (DAT_00f8d738 != (char *)0x0) {
        _free(DAT_00f8d738);
      }
    }
    sVar6 = _strlen(_Str1);
    DAT_00f8d738 = __malloc_crt(sVar6 + 1);
    if (DAT_00f8d738 == (char *)0x0) goto LAB_008ad2d6;
    pcVar10 = _Str1;
    sVar6 = _strlen(_Str1);
    eVar4 = _strcpy_s(DAT_00f8d738,sVar6 + 1,pcVar10);
    if (eVar4 != 0) goto LAB_008ad1e1;
  }
  lVar9 = local_20[0];
  piVar8 = (int *)FUN_008ad0d1();
  lVar3 = local_28;
  *piVar8 = lVar9;
  piVar8 = (int *)FUN_008ad0c5();
  lVar9 = local_2c;
  *piVar8 = lVar3;
  piVar8 = (int *)FUN_008ad0cb();
  *piVar8 = lVar9;
  local_8 = (undefined *)0xfffffffe;
  FUN_008ad360();
  piVar8 = local_24;
  if (local_30 == 0) {
    eVar4 = _strncpy_s((char *)*local_24,0x40,_Str1,3);
    if (eVar4 != 0) {
LAB_008ad1e1:
                    /* WARNING: Subroutine does not return */
      __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    pcVar10 = _Str1 + 3;
    cVar1 = *pcVar10;
    if (cVar1 == '-') {
      pcVar10 = _Str1 + 4;
    }
    lVar9 = _atol(pcVar10);
    local_20[0] = lVar9 * 0xe10;
    for (; (cVar2 = *pcVar10, cVar2 == '+' || (('/' < cVar2 && (cVar2 < ':'))));
        pcVar10 = pcVar10 + 1) {
    }
    if (*pcVar10 == ':') {
      pcVar10 = pcVar10 + 1;
      lVar9 = _atol(pcVar10);
      local_20[0] = local_20[0] + lVar9 * 0x3c;
      for (; ('/' < *pcVar10 && (*pcVar10 < ':')); pcVar10 = pcVar10 + 1) {
      }
      if (*pcVar10 == ':') {
        pcVar10 = pcVar10 + 1;
        lVar9 = _atol(pcVar10);
        local_20[0] = local_20[0] + lVar9;
        for (; ('/' < *pcVar10 && (*pcVar10 < ':')); pcVar10 = pcVar10 + 1) {
        }
      }
    }
    if (cVar1 == '-') {
      local_20[0] = -local_20[0];
    }
    local_28 = (long)*pcVar10;
    if (local_28 == 0) {
      *(undefined1 *)piVar8[1] = 0;
    }
    else {
      eVar4 = _strncpy_s((char *)piVar8[1],0x40,pcVar10,3);
      if (eVar4 != 0) goto LAB_008ad1e1;
    }
    lVar3 = local_20[0];
    piVar8 = (int *)FUN_008ad0d1();
    lVar9 = local_28;
    *piVar8 = lVar3;
    piVar8 = (int *)FUN_008ad0c5();
    *piVar8 = lVar9;
  }
  return;
}

