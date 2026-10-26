
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __fseeki64
   
   Library: Visual Studio 2010 Release */

int __cdecl __fseeki64(FILE *_File,longlong _Offset,int _Origin)

{
  int *piVar1;
  int iVar2;
  int in_stack_ffffffd0;
  
  if ((_File == (FILE *)0x0) ||
     (((_Offset._4_4_ != 0 && (_Offset._4_4_ != 1)) && (_Offset._4_4_ != 2)))) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_00893343();
    iVar2 = -1;
  }
  else {
    __lock_file(_File);
    iVar2 = __fseeki64_nolock(_File,_Offset,in_stack_ffffffd0);
    FUN_0089bf9f();
  }
  return iVar2;
}

