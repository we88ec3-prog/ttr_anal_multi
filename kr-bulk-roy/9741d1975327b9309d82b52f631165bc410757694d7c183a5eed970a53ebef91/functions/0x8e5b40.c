
int FUN_008e5b40(int param_1)

{
  byte bVar1;
  byte *pbVar2;
  bool bVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  void *pvVar8;
  void *pvVar9;
  uint uVar10;
  char *pcVar11;
  char *_Str1;
  size_t _Size;
  byte *_Buf;
  int *unaff_EDI;
  int local_10;
  int local_c;
  short local_8 [2];
  
  iVar5 = unaff_EDI[4];
  iVar7 = unaff_EDI[0x12];
  local_c = 0;
  if ((char)unaff_EDI[0x17] != '\0') {
    uVar4 = FUN_008b9850(iVar7);
    unaff_EDI[0x16] = 0;
    local_c = FUN_008e5850(local_8);
    if (local_c != 0) {
      return local_c;
    }
    while (local_8[0] == -0x7ffe) {
      unaff_EDI[0x16] = unaff_EDI[0x16] + local_10;
      local_c = FUN_008b9820(iVar7,local_10);
      if (local_c != 0) {
        return local_c;
      }
      local_c = FUN_008e5850(local_8);
      if (local_c != 0) {
        return local_c;
      }
    }
    if (unaff_EDI[0x16] != 0) {
      local_c = FUN_008b97e0(iVar7,uVar4);
      if (local_c != 0) {
        return local_c;
      }
      iVar5 = FUN_008baee0(iVar5,unaff_EDI[0x16],&local_c);
      unaff_EDI[0x15] = iVar5;
      if (local_c != 0) {
        return local_c;
      }
      unaff_EDI[0x16] = 0;
      local_c = FUN_008e5850(local_8);
      while ((local_c == 0 && (local_8[0] == -0x7ffe))) {
        local_c = FUN_008bab70(iVar7,unaff_EDI[0x16] + unaff_EDI[0x15],local_10);
        if (local_c != 0) {
          return local_c;
        }
        unaff_EDI[0x16] = unaff_EDI[0x16] + local_10;
        local_c = FUN_008e5850(local_8);
      }
      local_c = 0;
LAB_008e5e7e:
      (**(code **)(param_1 + 0x10))(unaff_EDI[0x15],unaff_EDI[0x16],0xd971);
      if (3 < (uint)unaff_EDI[0x16]) {
        *(undefined1 *)unaff_EDI[0x15] = 0x20;
        *(undefined1 *)(unaff_EDI[0x15] + 1) = 0x20;
        *(undefined1 *)(unaff_EDI[0x15] + 2) = 0x20;
        *(undefined1 *)(unaff_EDI[0x15] + 3) = 0x20;
        iVar5 = unaff_EDI[0x15];
        unaff_EDI[1] = iVar5;
        *unaff_EDI = iVar5;
        unaff_EDI[2] = unaff_EDI[0x16] + iVar5;
        return local_c;
      }
    }
    return 3;
  }
  pcVar6 = (char *)unaff_EDI[0x13];
  pcVar11 = pcVar6 + unaff_EDI[0x14];
  _Str1 = pcVar6;
  do {
    while ((((*pcVar6 != 'e' || (pcVar11 <= pcVar6 + 9)) || (pcVar6[1] != 'e')) ||
           (((pcVar6[2] != 'x' || (pcVar6[3] != 'e')) || (pcVar6[4] != 'c'))))) {
      pcVar6 = pcVar6 + 1;
      if (pcVar11 <= pcVar6) {
        return 3;
      }
    }
    unaff_EDI[2] = (int)(pcVar6 + 10);
    pcVar6 = (char *)unaff_EDI[2];
    *unaff_EDI = (int)_Str1;
    while (_Str1 < pcVar6) {
      if ((*_Str1 == 'e') && (iVar7 = _strncmp(_Str1,"eexec",5), iVar7 == 0)) {
        unaff_EDI[2] = unaff_EDI[0x13] + unaff_EDI[0x14];
        (*(code *)unaff_EDI[8])();
        pbVar2 = (byte *)unaff_EDI[2];
        _Buf = (byte *)*unaff_EDI;
        pvVar8 = _memchr(_Buf,10,(int)pbVar2 - (int)_Buf);
        if ((pvVar8 == (void *)0x0) ||
           (pvVar9 = _memchr(_Buf,0xd,(int)pbVar2 - (int)_Buf), pvVar9 < pvVar8)) {
          bVar3 = true;
        }
        else {
          bVar3 = false;
        }
        if (pbVar2 <= _Buf) {
          return 3;
        }
        while (((bVar1 = *_Buf, bVar1 == 0x20 || (bVar1 == 9)) ||
               (((bVar3 && (bVar1 == 0xd)) || (bVar1 == 10))))) {
          _Buf = _Buf + 1;
          if (pbVar2 <= _Buf) {
            return 3;
          }
        }
        if (pbVar2 <= _Buf) {
          return 3;
        }
        _Size = (unaff_EDI[0x13] - (int)_Buf) + unaff_EDI[0x14];
        if (*(char *)((int)unaff_EDI + 0x5d) == '\0') {
          unaff_EDI[0x15] = unaff_EDI[0x13];
          *(undefined1 *)((int)unaff_EDI + 0x5e) = 1;
          unaff_EDI[0x13] = 0;
          unaff_EDI[0x14] = 0;
        }
        else {
          iVar5 = FUN_008baee0(iVar5,_Size + 1,&local_c);
          unaff_EDI[0x15] = iVar5;
          if (local_c != 0) {
            return local_c;
          }
        }
        unaff_EDI[0x16] = _Size;
        if (((((_Buf + 3 < pbVar2) &&
              (((uVar10 = (uint)*_Buf, uVar10 - 0x30 < 10 || (uVar10 - 0x61 < 6)) ||
               (uVar10 - 0x41 < 6)))) &&
             (((uVar10 = (uint)_Buf[1], uVar10 - 0x30 < 10 || (uVar10 - 0x61 < 6)) ||
              (uVar10 - 0x41 < 6)))) &&
            (((uVar10 = (uint)_Buf[2], uVar10 - 0x30 < 10 || (uVar10 - 0x61 < 6)) ||
             (uVar10 - 0x41 < 6)))) &&
           (((uVar10 = (uint)_Buf[3], uVar10 - 0x30 < 10 || (uVar10 - 0x61 < 6)) ||
            (uVar10 - 0x41 < 6)))) {
          *unaff_EDI = (int)_Buf;
          (**(code **)(*(int *)(param_1 + 4) + 0x18))();
          unaff_EDI[0x16] = (int)pvVar8;
          *(undefined1 *)((int)pvVar8 + unaff_EDI[0x15]) = 0;
        }
        else {
          FID_conflict__memcpy((void *)unaff_EDI[0x15],_Buf,_Size);
        }
        goto LAB_008e5e7e;
      }
      (*(code *)unaff_EDI[8])();
      if (unaff_EDI[3] != 0) break;
      (*(code *)unaff_EDI[7])();
      _Str1 = (char *)*unaff_EDI;
    }
    _Str1 = (char *)unaff_EDI[0x13];
    pcVar11 = _Str1 + unaff_EDI[0x14];
  } while( true );
}

