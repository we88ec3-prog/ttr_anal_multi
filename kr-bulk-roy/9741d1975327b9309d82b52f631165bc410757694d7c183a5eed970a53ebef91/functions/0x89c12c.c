
/* Library Function - Single Match
    __ecvt_s
   
   Library: Visual Studio 2010 Release */

errno_t __cdecl
__ecvt_s(char *_DstBuf,size_t _Size,double _Val,int _NumOfDights,int *_PtDec,int *_PtSign)

{
  int *piVar1;
  errno_t eVar2;
  int local_34 [4];
  _strflt *local_24;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_24 = (_strflt *)_PtSign;
  if ((((_DstBuf == (char *)0x0) || (_Size == 0)) || (*_DstBuf = '\0', _PtDec == (int *)0x0)) ||
     (_PtSign == (int *)0x0)) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_00893343();
  }
  else {
    piVar1 = local_34;
    FUN_008b0801();
    _fpcvt(_DstBuf,(uint)_PtDec,local_24,SUB84(_Val,0),(int *)((ulonglong)_Val >> 0x20),piVar1);
    if ((int)(_Size - 2) < _NumOfDights) {
      _NumOfDights = _Size - 2;
    }
    if ((-1 < _NumOfDights) && (_DstBuf[_NumOfDights] != '\0')) {
      _DstBuf[_NumOfDights] = '\0';
    }
  }
  eVar2 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return eVar2;
}

