
void FUN_008995ea(char *param_1)

{
  errno_t eVar1;
  char *pcVar2;
  DWORD _Val;
  char *_Size;
  char *_Dst;
  rsize_t _SizeInBytes;
  int _Radix;
  
  _SizeInBytes = 0;
  if (param_1 == (char *)0x0) {
    _Dst = &DAT_00f8cb30;
    _SizeInBytes = 0xe;
  }
  else {
    if (param_1 == (char *)0x1) {
      _Dst = &DAT_00f8cb40;
    }
    else {
      _Dst = param_1;
      if (param_1 != (char *)0x2) goto LAB_00899620;
      _Dst = &DAT_00f8cb54;
    }
    _SizeInBytes = 0x12;
  }
LAB_00899620:
  eVar1 = _strcpy_s(_Dst,_SizeInBytes,"\\");
  if (eVar1 == 0) {
    pcVar2 = _Dst + 1;
    if ((*_Dst != '\\') && (*_Dst != '/')) {
      *pcVar2 = '\\';
      pcVar2 = _Dst + 2;
    }
    if (param_1 == (char *)0x1) {
      *pcVar2 = 't';
    }
    else {
      *pcVar2 = 's';
    }
    pcVar2 = pcVar2 + 1;
    _Radix = 0x20;
    _Size = _Dst + (_SizeInBytes - (int)pcVar2);
    _Val = GetCurrentProcessId();
    eVar1 = __ultoa_s(_Val,pcVar2,(size_t)_Size,_Radix);
    if ((eVar1 == 0) && (eVar1 = _strcat_s(_Dst,_SizeInBytes,"."), eVar1 == 0)) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
}

