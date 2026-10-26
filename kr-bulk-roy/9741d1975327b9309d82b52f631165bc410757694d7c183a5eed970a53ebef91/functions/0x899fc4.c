
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __pclose
   
   Library: Visual Studio 2010 Release */

int __cdecl __pclose(FILE *_File)

{
  FILE *_File_00;
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  intptr_t iVar4;
  FILE *local_20;
  
  _File_00 = _File;
  local_20 = (FILE *)0xffffffff;
  if (_File == (FILE *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_00893343();
  }
  else {
    iVar2 = __mtinitlocknum(9);
    if (iVar2 != 0) {
      __lock(9);
      puVar3 = (undefined4 *)idtab();
      if (puVar3 == (undefined4 *)0x0) {
        piVar1 = __errno();
        *piVar1 = 9;
      }
      else {
        _fclose(_File_00);
        piVar1 = __errno();
        iVar2 = *piVar1;
        piVar1 = __errno();
        *piVar1 = 0;
        iVar4 = __cwait((int *)&_File,puVar3[1],1);
        if ((iVar4 != -1) || (piVar1 = __errno(), *piVar1 == 4)) {
          local_20 = _File;
        }
        piVar1 = __errno();
        *piVar1 = iVar2;
        *puVar3 = 0;
        puVar3[1] = 0;
      }
      FUN_0089a086();
      return (int)local_20;
    }
  }
  return -1;
}

