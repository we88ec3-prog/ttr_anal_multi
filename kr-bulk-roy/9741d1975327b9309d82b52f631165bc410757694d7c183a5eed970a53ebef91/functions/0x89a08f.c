
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _setvbuf
   
   Library: Visual Studio 2010 Release */

int __cdecl _setvbuf(FILE *_File,char *_Buf,int _Mode,size_t _Size)

{
  int *piVar1;
  uint uVar2;
  uint _Size_00;
  int local_20;
  
  local_20 = 0;
  if (_File == (FILE *)0x0) goto LAB_0089a0ad;
  if (_Mode == 4) {
LAB_0089a0d6:
    if ((_Mode == 0) || (_Mode == 0x40)) goto LAB_0089a0df;
  }
  else {
    if (_Mode != 0) {
      if (_Mode != 0x40) goto LAB_0089a0ad;
      goto LAB_0089a0d6;
    }
LAB_0089a0df:
    if (0x7ffffffd < _Size - 2) {
LAB_0089a0ad:
      piVar1 = __errno();
      *piVar1 = 0x16;
      FUN_00893343();
      return -1;
    }
  }
  _Size_00 = _Size & 0xfffffffe;
  __lock_file(_File);
  __flush(_File);
  __freebuf(_File);
  _File->_flag = _File->_flag & 0xffffc2f3;
  if ((_Mode & 4U) == 0) {
    if (_Buf != (char *)0x0) {
      uVar2 = _File->_flag | 0x500;
      goto LAB_0089a157;
    }
    _Buf = __malloc_crt(_Size_00);
    if ((int *)_Buf == (int *)0x0) {
      _DAT_00f8cb14 = _DAT_00f8cb14 + 1;
      local_20 = -1;
      goto LAB_0089a166;
    }
    _File->_flag = _File->_flag | 0x408;
  }
  else {
    uVar2 = _File->_flag | 4;
    _Buf = (char *)&_File->_charbuf;
    _Size_00 = 2;
LAB_0089a157:
    _File->_flag = uVar2;
  }
  _File->_bufsiz = _Size_00;
  _File->_base = _Buf;
  _File->_ptr = _Buf;
  _File->_cnt = 0;
LAB_0089a166:
  FUN_0089a17b();
  return local_20;
}

