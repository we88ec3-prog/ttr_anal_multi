
/* Library Function - Single Match
    __gmtime64
   
   Library: Visual Studio 2010 Release */

tm * __cdecl __gmtime64(__time64_t *_Time)

{
  tm *_Tm;
  errno_t eVar1;
  tm *ptVar2;
  
  _Tm = ___getgmtimebuf();
  ptVar2 = (tm *)0x0;
  if (_Tm != (tm *)0x0) {
    eVar1 = __gmtime64_s(_Tm,_Time);
    ptVar2 = (tm *)(~-(uint)(eVar1 != 0) & (uint)_Tm);
  }
  return ptVar2;
}

