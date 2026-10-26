
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Multiple Matches With Different Base Names
    _printf
    _wprintf
   
   Library: Visual Studio 2010 Release */

int __cdecl FID_conflict__wprintf(char *_Format,...)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (_Format == (char *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_00893343();
    iVar2 = -1;
  }
  else {
    iVar3 = FUN_00894fab();
    __lock_file2(1,(void *)(iVar3 + 0x20));
    iVar3 = FUN_00894fab();
    iVar3 = __stbuf((FILE *)(iVar3 + 0x20));
    iVar4 = FUN_00894fab(_Format,0,&stack0x00000008);
    iVar2 = FUN_008a3d54(iVar4 + 0x20);
    iVar4 = FUN_00894fab();
    __ftbuf(iVar3,(FILE *)(iVar4 + 0x20));
    FUN_008983db();
  }
  return iVar2;
}

