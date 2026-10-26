
/* Library Function - Single Match
    private: static void __cdecl std::locale::_Setgloballocale(void *)
   
   Library: Visual Studio 2010 Release */

void __cdecl std::locale::_Setgloballocale(void *param_1)

{
  if (DAT_00f8c865 == '\0') {
    DAT_00f8c865 = '\x01';
    _Atexit(tidy_global);
  }
  DAT_00f8c840 = param_1;
  return;
}

