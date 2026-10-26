
errno_t FUN_00897163(tm *param_1,__time32_t *param_2)

{
  tm *_Tm;
  __time32_t *_Time;
  int *piVar1;
  errno_t eVar2;
  int iVar3;
  int iVar4;
  long local_10;
  long local_c;
  long local_8;
  
  _Tm = param_1;
  local_c = 0;
  local_10 = 0;
  local_8 = 0;
  if (param_1 == (tm *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_00893343();
    return 0x16;
  }
  _memset(param_1,0xff,0x24);
  _Time = param_2;
  if (param_2 == (__time32_t *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_00893343();
    return 0x16;
  }
  if (*param_2 < 0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    return 0x16;
  }
  ___tzset();
  eVar2 = FID_conflict___get_dstbias(&local_c);
  if (((eVar2 != 0) || (eVar2 = FID_conflict___get_dstbias(&local_10), eVar2 != 0)) ||
     (eVar2 = FID_conflict___get_dstbias(&local_8), eVar2 != 0)) {
                    /* WARNING: Subroutine does not return */
    __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  }
  iVar3 = *_Time;
  if ((iVar3 < 0x3f481) || (0x7ffc0b7e < iVar3)) {
    eVar2 = __gmtime32_s(_Tm,_Time);
    if (eVar2 != 0) {
      return eVar2;
    }
    if ((local_c == 0) || (iVar3 = __isindst(_Tm), iVar3 == 0)) {
      iVar3 = _Tm->tm_sec - local_8;
    }
    else {
      _Tm->tm_isdst = 1;
      iVar3 = (_Tm->tm_sec - local_8) - local_10;
    }
    iVar4 = iVar3 % 0x3c;
    _Tm->tm_sec = iVar4;
    if (iVar4 < 0) {
      _Tm->tm_sec = iVar4 + 0x3c;
      iVar3 = iVar3 + -0x3c;
    }
    iVar3 = iVar3 / 0x3c + _Tm->tm_min;
    iVar4 = iVar3 % 0x3c;
    _Tm->tm_min = iVar4;
    if (iVar4 < 0) {
      _Tm->tm_min = iVar4 + 0x3c;
      iVar3 = iVar3 + -0x3c;
    }
    iVar3 = iVar3 / 0x3c + _Tm->tm_hour;
    iVar4 = iVar3 % 0x18;
    _Tm->tm_hour = iVar4;
    if (iVar4 < 0) {
      _Tm->tm_hour = iVar4 + 0x18;
      iVar3 = iVar3 + -0x18;
    }
    iVar3 = iVar3 / 0x18;
    if (iVar3 < 1) {
      if (-1 < iVar3) {
        return 0;
      }
      _Tm->tm_mday = _Tm->tm_mday + iVar3;
      _Tm->tm_wday = (_Tm->tm_wday + 7 + iVar3) % 7;
      if (_Tm->tm_mday < 1) {
        _Tm->tm_yday = _Tm->tm_yday + iVar3 + 0x16d;
        _Tm->tm_year = _Tm->tm_year + -1;
        _Tm->tm_mday = _Tm->tm_mday + 0x1f;
        _Tm->tm_mon = 0xb;
        return 0;
      }
    }
    else {
      _Tm->tm_mday = _Tm->tm_mday + iVar3;
      _Tm->tm_wday = (_Tm->tm_wday + iVar3) % 7;
    }
    _Tm->tm_yday = _Tm->tm_yday + iVar3;
    return 0;
  }
  param_1 = (tm *)(iVar3 - local_8);
  eVar2 = __gmtime32_s(_Tm,(__time32_t *)&param_1);
  if (eVar2 != 0) {
    return eVar2;
  }
  if (local_c == 0) {
    return 0;
  }
  iVar3 = __isindst(_Tm);
  if (iVar3 == 0) {
    return 0;
  }
  param_1 = (tm *)((int)param_1 - local_10);
  eVar2 = __gmtime32_s(_Tm,(__time32_t *)&param_1);
  if (eVar2 == 0) {
    _Tm->tm_isdst = 1;
    return 0;
  }
  return eVar2;
}

