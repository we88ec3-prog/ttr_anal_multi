
/* Library Function - Single Match
    __mbsnicmp_l
   
   Library: Visual Studio 2010 Release */

int __cdecl __mbsnicmp_l(uchar *_Str1,uchar *_Str2,size_t _MaxCount,_locale_t _Locale)

{
  int iVar1;
  int *piVar2;
  ushort uVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  _LocaleUpdate local_18 [4];
  int local_14;
  int local_10;
  char local_c;
  ushort local_8;
  
  if (_MaxCount == 0) {
    return 0;
  }
  _LocaleUpdate::_LocaleUpdate(local_18,_Locale);
  if (*(int *)(local_14 + 8) == 0) {
    iVar1 = __strnicmp((char *)_Str1,(char *)_Str2,_MaxCount);
    if (local_c != '\0') {
      *(uint *)(local_10 + 0x70) = *(uint *)(local_10 + 0x70) & 0xfffffffd;
      return iVar1;
    }
  }
  else if (_Str1 == (uchar *)0x0) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_00893343();
    if (local_c != '\0') {
      *(uint *)(local_10 + 0x70) = *(uint *)(local_10 + 0x70) & 0xfffffffd;
    }
    iVar1 = 0x7fffffff;
  }
  else if (_Str2 == (uchar *)0x0) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_00893343();
    if (local_c != '\0') {
      *(uint *)(local_10 + 0x70) = *(uint *)(local_10 + 0x70) & 0xfffffffd;
    }
    iVar1 = 0x7fffffff;
  }
  else {
    do {
      uVar4 = (uint)*_Str1;
      _MaxCount = _MaxCount - 1;
      pbVar6 = _Str1 + 1;
      if ((*(byte *)(uVar4 + 0x1d + local_14) & 4) == 0) {
        if ((*(byte *)(uVar4 + local_14 + 0x1d) & 0x10) != 0) {
          uVar4 = (uint)*(byte *)(uVar4 + local_14 + 0x11d);
        }
        local_8 = (ushort)uVar4;
        uVar3 = local_8;
      }
      else if (*pbVar6 == 0) {
        local_8 = 0;
        uVar3 = local_8;
      }
      else {
        uVar3 = CONCAT11(*_Str1,*pbVar6);
        pbVar6 = _Str1 + 2;
        if ((uVar3 < *(ushort *)(local_14 + 0x10)) || (*(ushort *)(local_14 + 0x12) < uVar3)) {
          if ((*(ushort *)(local_14 + 0x16) <= uVar3) && (uVar3 <= *(ushort *)(local_14 + 0x18))) {
            uVar3 = uVar3 + *(short *)(local_14 + 0x1a);
          }
        }
        else {
          uVar3 = uVar3 + *(short *)(local_14 + 0x14);
        }
      }
      uVar4 = (uint)*_Str2;
      pbVar5 = _Str2 + 1;
      if ((*(byte *)(uVar4 + 0x1d + local_14) & 4) == 0) {
        if ((*(byte *)(uVar4 + local_14 + 0x1d) & 0x10) != 0) {
          uVar4 = (uint)*(byte *)(uVar4 + local_14 + 0x11d);
        }
        local_8 = (ushort)uVar4;
      }
      else if (*pbVar5 == 0) {
        local_8 = 0;
      }
      else {
        local_8 = CONCAT11(*_Str2,*pbVar5);
        pbVar5 = _Str2 + 2;
        if ((local_8 < *(ushort *)(local_14 + 0x10)) || (*(ushort *)(local_14 + 0x12) < local_8)) {
          if ((*(ushort *)(local_14 + 0x16) <= local_8) && (local_8 <= *(ushort *)(local_14 + 0x18))
             ) {
            local_8 = local_8 + *(short *)(local_14 + 0x1a);
          }
        }
        else {
          local_8 = local_8 + *(short *)(local_14 + 0x14);
        }
      }
      if (local_8 != uVar3) {
        iVar1 = (-(uint)(local_8 < uVar3) & 2) - 1;
        if (local_c == '\0') {
          return iVar1;
        }
        *(uint *)(local_10 + 0x70) = *(uint *)(local_10 + 0x70) & 0xfffffffd;
        return iVar1;
      }
    } while ((uVar3 != 0) && (_Str2 = pbVar5, _Str1 = pbVar6, _MaxCount != 0));
    if (local_c != '\0') {
      *(uint *)(local_10 + 0x70) = *(uint *)(local_10 + 0x70) & 0xfffffffd;
    }
    iVar1 = 0;
  }
  return iVar1;
}

