
/* Library Function - Single Match
    __difftime64
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release */

double __cdecl __difftime64(__time64_t _Time1,__time64_t _Time2)

{
  int *piVar1;
  
  if ((-1 < _Time2) && (-1 < _Time1)) {
    return (double)(_Time1 - _Time2);
  }
  piVar1 = __errno();
  *piVar1 = 0x16;
  return 0.0;
}

