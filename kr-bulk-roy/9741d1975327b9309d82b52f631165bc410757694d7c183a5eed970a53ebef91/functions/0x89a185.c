
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _clearerr_s
   
   Library: Visual Studio 2010 Release */

errno_t __cdecl _clearerr_s(FILE *_File)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  
  if (_File != (FILE *)0x0) {
    __lock_file(_File);
    _File->_flag = _File->_flag & 0xffffffcf;
    iVar2 = __fileno(_File);
    if ((iVar2 == -1) || (iVar2 = __fileno(_File), iVar2 == -2)) {
      puVar4 = &DAT_00d61f50;
    }
    else {
      iVar2 = __fileno(_File);
      uVar3 = __fileno(_File);
      puVar4 = (undefined *)((uVar3 & 0x1f) * 0x40 + (&DAT_00fe72a0)[iVar2 >> 5]);
    }
    puVar4[4] = puVar4[4] & 0xfd;
    FUN_0089a221();
    return 0;
  }
  piVar1 = __errno();
  *piVar1 = 0x16;
  FUN_00893343();
  return 0x16;
}

