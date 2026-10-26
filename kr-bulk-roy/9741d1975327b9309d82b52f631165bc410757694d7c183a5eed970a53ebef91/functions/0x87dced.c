
/* Library Function - Single Match
    public: __thiscall std::_Init_locks::_Init_locks(void)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

_Init_locks * __thiscall std::_Init_locks::_Init_locks(_Init_locks *this)

{
  LONG LVar1;
  _Rmtx *p_Var2;
  
  LVar1 = InterlockedIncrement((LONG *)&DAT_00d61084);
  if (LVar1 == 0) {
    p_Var2 = (_Rmtx *)&DAT_00f8c7a0;
    do {
      __Mtxinit(p_Var2);
      p_Var2 = p_Var2 + 1;
    } while ((int)p_Var2 < 0xf8c800);
  }
  return this;
}

