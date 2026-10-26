
/* Library Function - Single Match
    __heap_init
   
   Library: Visual Studio 2010 Release */

int __cdecl __heap_init(void)

{
  DAT_00f8d4dc = HeapCreate(0,0x1000,0);
  return (uint)(DAT_00f8d4dc != (HANDLE)0x0);
}

