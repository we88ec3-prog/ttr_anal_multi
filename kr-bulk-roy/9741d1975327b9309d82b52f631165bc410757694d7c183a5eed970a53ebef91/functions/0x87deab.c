
/* Library Function - Single Match
    _tidy_global
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

void __cdecl tidy_global(void)

{
  _Lockit local_8 [4];
  
  std::_Lockit::_Lockit(local_8,0);
  __Deletegloballocale(&DAT_00f8c840);
  DAT_00f8c840 = 0;
  FUN_0087dd6f();
  return;
}

