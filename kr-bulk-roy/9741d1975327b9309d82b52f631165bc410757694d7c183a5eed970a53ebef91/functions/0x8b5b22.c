
/* Library Function - Single Match
    ___initconout
   
   Library: Visual Studio 2010 Release */

void __cdecl ___initconout(void)

{
  DAT_00d62fb0 = CreateFileW(L"CONOUT$",0x40000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
  return;
}

