
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Multiple Matches With Different Base Names
    _vprintf_helper
    _vwprintf_helper
   
   Library: Visual Studio 2010 Release */

undefined4
FID_conflict__vprintf_helper(code *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  FILE *_File;
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_00894fab();
  _File = (FILE *)(iVar1 + 0x20);
  if (param_2 == 0) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_00893343();
    uVar3 = 0xffffffff;
  }
  else {
    __lock_file(_File);
    iVar1 = __stbuf(_File);
    uVar3 = (*param_1)(_File,param_2,param_3,param_4);
    __ftbuf(iVar1,_File);
    FUN_008a73d7();
  }
  return uVar3;
}

