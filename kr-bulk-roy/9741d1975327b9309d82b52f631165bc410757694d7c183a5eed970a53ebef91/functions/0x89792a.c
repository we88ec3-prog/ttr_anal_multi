
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___inittime
   
   Library: Visual Studio 2010 Release */

undefined4 ___inittime(void)

{
  _FILETIME local_c;
  
  GetSystemTimeAsFileTime(&local_c);
  _DAT_00f8cb28 = local_c.dwLowDateTime;
  _DAT_00f8cb2c = local_c.dwHighDateTime;
  return 0;
}

