
/* Library Function - Single Match
    __i64tow_s
   
   Library: Visual Studio 2010 Release */

errno_t __cdecl __i64tow_s(longlong _Val,wchar_t *_DstBuf,size_t _SizeInWords,int _Radix)

{
  undefined4 uVar1;
  errno_t eVar2;
  undefined4 in_ECX;
  undefined4 in_EDX;
  
  uVar1 = 0;
  if (((_Radix == 10) && (_Val < 0x100000000)) && (_Val < 0)) {
    uVar1 = 1;
  }
  eVar2 = x64tow_s(in_ECX,in_EDX,_Val,_SizeInWords,_Radix,uVar1);
  return eVar2;
}

