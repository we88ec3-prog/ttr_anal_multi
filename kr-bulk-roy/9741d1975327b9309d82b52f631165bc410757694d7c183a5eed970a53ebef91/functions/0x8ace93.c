
/* Library Function - Single Match
    __fgetwc_nolock
   
   Library: Visual Studio 2010 Release */

wint_t __cdecl __fgetwc_nolock(FILE *_File)

{
  FILE *_File_00;
  wint_t wVar1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  int *piVar5;
  size_t _SrcSizeInBytes;
  undefined4 local_8;
  
  _File_00 = _File;
  if ((_File->_flag & 0x40) == 0) {
    iVar2 = __fileno(_File);
    if ((iVar2 == -1) || (iVar2 = __fileno(_File_00), iVar2 == -2)) {
      puVar4 = &DAT_00d61f50;
    }
    else {
      iVar2 = __fileno(_File_00);
      uVar3 = __fileno(_File_00);
      puVar4 = (undefined *)((uVar3 & 0x1f) * 0x40 + (&DAT_00fe72a0)[iVar2 >> 5]);
    }
    if ((puVar4[0x24] & 0x7f) != 0) {
      piVar5 = &_File_00->_cnt;
      *piVar5 = *piVar5 + -1;
      if (*piVar5 < 0) {
        uVar3 = __filbuf(_File_00);
      }
      else {
        uVar3 = (uint)(byte)*_File_00->_ptr;
        _File_00->_ptr = _File_00->_ptr + 1;
      }
      if (uVar3 != 0xffffffff) {
        piVar5 = &_File_00->_cnt;
        *piVar5 = *piVar5 + -1;
        _File = (FILE *)CONCAT31(_File._1_3_,(char)uVar3);
        if (*piVar5 < 0) {
          uVar3 = __filbuf(_File_00);
        }
        else {
          uVar3 = (uint)(byte)*_File_00->_ptr;
          _File_00->_ptr = _File_00->_ptr + 1;
        }
        if (uVar3 != 0xffffffff) {
          _File._0_2_ = CONCAT11((char)uVar3,_File._0_1_);
          _File = (FILE *)(uint)(ushort)_File;
          goto LAB_008acf36;
        }
      }
      return 0xffff;
    }
    if ((_File_00->_flag & 0x40) == 0) {
      iVar2 = __fileno(_File_00);
      if ((iVar2 == -1) || (iVar2 = __fileno(_File_00), iVar2 == -2)) {
        puVar4 = &DAT_00d61f50;
      }
      else {
        iVar2 = __fileno(_File_00);
        uVar3 = __fileno(_File_00);
        puVar4 = (undefined *)((uVar3 & 0x1f) * 0x40 + (&DAT_00fe72a0)[iVar2 >> 5]);
      }
      if ((puVar4[4] & 0x80) != 0) {
        _SrcSizeInBytes = 1;
        piVar5 = &_File_00->_cnt;
        *piVar5 = *piVar5 + -1;
        if (*piVar5 < 0) {
          uVar3 = __filbuf(_File_00);
        }
        else {
          uVar3 = (uint)(byte)*_File_00->_ptr;
          _File_00->_ptr = _File_00->_ptr + 1;
        }
        if (uVar3 == 0xffffffff) {
          return 0xffff;
        }
        local_8 = CONCAT31(local_8._1_3_,(char)uVar3);
        iVar2 = _isleadbyte(uVar3 & 0xff);
        if (iVar2 != 0) {
          piVar5 = &_File_00->_cnt;
          *piVar5 = *piVar5 + -1;
          if (*piVar5 < 0) {
            uVar3 = __filbuf(_File_00);
          }
          else {
            uVar3 = (uint)(byte)*_File_00->_ptr;
            _File_00->_ptr = _File_00->_ptr + 1;
          }
          if (uVar3 == 0xffffffff) {
            _ungetc((int)(char)local_8,_File_00);
            return 0xffff;
          }
          local_8._0_2_ = CONCAT11((char)uVar3,(char)local_8);
          _SrcSizeInBytes = 2;
        }
        iVar2 = _mbtowc((wchar_t *)&_File,(char *)&local_8,_SrcSizeInBytes);
        if (iVar2 == -1) {
          piVar5 = __errno();
          *piVar5 = 0x2a;
          return 0xffff;
        }
LAB_008acf36:
        return (ushort)_File;
      }
    }
  }
  piVar5 = &_File_00->_cnt;
  *piVar5 = *piVar5 + -2;
  if (*piVar5 < 0) {
    iVar2 = __filwbuf(_File_00);
    wVar1 = (wint_t)iVar2;
  }
  else {
    wVar1 = *(wint_t *)_File_00->_ptr;
    _File_00->_ptr = (char *)((int)_File_00->_ptr + 2);
  }
  return wVar1;
}

