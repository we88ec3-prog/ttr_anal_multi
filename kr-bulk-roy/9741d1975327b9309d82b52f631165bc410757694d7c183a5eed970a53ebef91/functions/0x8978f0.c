
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _clock
   
   Library: Visual Studio 2010 Release */

clock_t __cdecl _clock(void)

{
  clock_t cVar1;
  _FILETIME local_c;
  
  GetSystemTimeAsFileTime(&local_c);
  cVar1 = __aulldiv(-_DAT_00f8cb28 + local_c.dwLowDateTime,
                    ((local_c.dwHighDateTime - _DAT_00f8cb2c) - (uint)(_DAT_00f8cb28 != 0)) +
                    (uint)CARRY4(-_DAT_00f8cb28,local_c.dwLowDateTime),10000,0);
  return cVar1;
}

