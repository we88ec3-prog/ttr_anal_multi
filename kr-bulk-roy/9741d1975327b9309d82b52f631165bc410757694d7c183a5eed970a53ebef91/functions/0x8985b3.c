
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _ungetc
   
   Library: Visual Studio 2010 Release */

int __cdecl _ungetc(int _Ch,FILE *_File)

{
  int *piVar1;
  int iVar2;
  
  if (_File == (FILE *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_00893343();
    iVar2 = -1;
  }
  else {
    __lock_file(_File);
    iVar2 = __ungetc_nolock(_Ch,_File);
    FUN_00898612();
  }
  return iVar2;
}

