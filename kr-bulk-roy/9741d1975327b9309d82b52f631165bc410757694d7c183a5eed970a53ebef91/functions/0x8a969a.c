
/* Library Function - Single Match
    __whiteout
   
   Library: Visual Studio 2010 Release */

wint_t __whiteout(FILE *param_1)

{
  wint_t _C;
  int iVar1;
  int *unaff_ESI;
  
  do {
    *unaff_ESI = *unaff_ESI + 1;
    _C = __fgetwc_nolock(param_1);
    if (_C == 0xffff) {
      return 0xffff;
    }
    iVar1 = _iswctype(_C,8);
  } while (iVar1 != 0);
  return _C;
}

