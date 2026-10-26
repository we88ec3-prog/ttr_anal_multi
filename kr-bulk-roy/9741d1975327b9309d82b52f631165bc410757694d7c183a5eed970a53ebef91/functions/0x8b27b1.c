
/* Library Function - Single Match
    __ungetwc_nolock
   
   Library: Visual Studio 2010 Release */

wint_t __cdecl __ungetwc_nolock(wint_t _Ch,FILE *_File)

{
  wint_t *pwVar1;
  wint_t wVar2;
  int iVar3;
  uint uVar4;
  undefined *puVar5;
  errno_t eVar6;
  undefined4 local_14;
  char local_10;
  undefined1 local_f;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (_Ch != 0xffff) {
    uVar4 = _File->_flag;
    if (((uVar4 & 1) != 0) || (((char)uVar4 < '\0' && ((uVar4 & 2) == 0)))) {
      if (_File->_base == (char *)0x0) {
        __getbuf(_File);
      }
      if ((_File->_flag & 0x40) == 0) {
        iVar3 = __fileno(_File);
        if ((iVar3 == -1) || (iVar3 = __fileno(_File), iVar3 == -2)) {
          puVar5 = &DAT_00d61f50;
        }
        else {
          iVar3 = __fileno(_File);
          uVar4 = __fileno(_File);
          puVar5 = (undefined *)((uVar4 & 0x1f) * 0x40 + (&DAT_00fe72a0)[iVar3 >> 5]);
        }
        if ((puVar5[4] & 0x80) != 0) {
          iVar3 = __fileno(_File);
          if ((iVar3 == -1) || (iVar3 = __fileno(_File), iVar3 == -2)) {
            puVar5 = &DAT_00d61f50;
          }
          else {
            iVar3 = __fileno(_File);
            uVar4 = __fileno(_File);
            puVar5 = (undefined *)((uVar4 & 0x1f) * 0x40 + (&DAT_00fe72a0)[iVar3 >> 5]);
          }
          if ((puVar5[0x24] & 0x7f) == 0) {
            eVar6 = _wctomb_s(&local_14,&local_10,5,_Ch);
            if (eVar6 != 0) goto LAB_008b2944;
          }
          else {
            local_10 = (char)_Ch;
            local_f = (char)(_Ch >> 8);
            local_14 = 2;
          }
          iVar3 = local_14;
          if (_File->_ptr < _File->_base + local_14) {
            if ((_File->_cnt != 0) || (_File->_bufsiz < local_14)) goto LAB_008b2944;
            _File->_ptr = _File->_base + local_14;
          }
          while (iVar3 = iVar3 + -1, -1 < iVar3) {
            _File->_ptr = _File->_ptr + -1;
            *_File->_ptr = (&local_10)[iVar3];
          }
          _File->_cnt = _File->_cnt + local_14;
          _File->_flag = _File->_flag & 0xffffffefU | 1;
          goto LAB_008b2944;
        }
      }
      if (_File->_ptr < _File->_base + 2) {
        if ((_File->_cnt != 0) || ((uint)_File->_bufsiz < 2)) goto LAB_008b2944;
        _File->_ptr = _File->_base + 2;
      }
      _File->_ptr = _File->_ptr + -2;
      pwVar1 = (wint_t *)_File->_ptr;
      if ((_File->_flag & 0x40) == 0) {
        *pwVar1 = _Ch;
      }
      else if (*pwVar1 != _Ch) {
        _File->_ptr = (char *)(pwVar1 + 1);
        goto LAB_008b2944;
      }
      _File->_cnt = _File->_cnt + 2;
      _File->_flag = _File->_flag & 0xffffffefU | 1;
    }
  }
LAB_008b2944:
  wVar2 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return wVar2;
}

