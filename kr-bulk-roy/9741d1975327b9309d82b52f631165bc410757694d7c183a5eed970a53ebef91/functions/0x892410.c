
/* Library Function - Single Match
    __itow_s
   
   Library: Visual Studio 2010 Release */

errno_t __cdecl __itow_s(int _Val,wchar_t *_DstBuf,size_t _SizeInWords,int _Radix)

{
  errno_t eVar1;
  undefined4 uVar2;
  
  if ((_Radix == 10) && (_Val < 0)) {
    uVar2 = 1;
    _Radix = 10;
  }
  else {
    uVar2 = 0;
  }
  eVar1 = xtow_s(_SizeInWords,_Radix,uVar2);
  return eVar1;
}

