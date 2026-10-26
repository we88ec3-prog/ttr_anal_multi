
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _fputs
   
   Library: Visual Studio 2010 Release */

int __cdecl _fputs(char *_Str,FILE *_File)

{
  int *piVar1;
  uint uVar2;
  size_t _Count;
  int _Flag;
  size_t sVar3;
  undefined *puVar4;
  
  if ((_Str != (char *)0x0) && (_File != (FILE *)0x0)) {
    if ((_File->_flag & 0x40) != 0) {
LAB_00898231:
      _Count = _strlen(_Str);
      __lock_file(_File);
      _Flag = __stbuf(_File);
      sVar3 = __fwrite_nolock(_Str,1,_Count,_File);
      __ftbuf(_Flag,_File);
      FUN_0089828c();
      return (sVar3 == _Count) - 1;
    }
    uVar2 = __fileno(_File);
    if ((uVar2 == 0xffffffff) || (uVar2 == 0xfffffffe)) {
      puVar4 = &DAT_00d61f50;
    }
    else {
      puVar4 = (undefined *)((uVar2 & 0x1f) * 0x40 + (&DAT_00fe72a0)[(int)uVar2 >> 5]);
    }
    if ((puVar4[0x24] & 0x7f) == 0) {
      if ((uVar2 == 0xffffffff) || (uVar2 == 0xfffffffe)) {
        puVar4 = &DAT_00d61f50;
      }
      else {
        puVar4 = (undefined *)((uVar2 & 0x1f) * 0x40 + (&DAT_00fe72a0)[(int)uVar2 >> 5]);
      }
      if ((puVar4[0x24] & 0x80) == 0) goto LAB_00898231;
    }
  }
  piVar1 = __errno();
  *piVar1 = 0x16;
  FUN_00893343();
  return -1;
}

