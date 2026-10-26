
/* Library Function - Single Match
    unsigned long __cdecl wcstoxl(wchar_t const *,wchar_t const * *,int,int)
   
   Library: Visual Studio 2010 Release */

ulong __cdecl wcstoxl(wchar_t *param_1,wchar_t **param_2,int param_3,int param_4)

{
  wchar_t _C;
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  ushort uVar5;
  uint uVar6;
  wchar_t *pwVar7;
  wchar_t *pwVar8;
  uint local_8;
  
  if (param_2 != (wchar_t **)0x0) {
    *param_2 = param_1;
  }
  if ((param_1 == (wchar_t *)0x0) || ((param_3 != 0 && ((param_3 < 2 || (0x24 < param_3)))))) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_00893343();
    return 0;
  }
  local_8 = 0;
  pwVar8 = param_1;
  do {
    pwVar7 = pwVar8;
    _C = *pwVar7;
    pwVar8 = pwVar7 + 1;
    iVar2 = _iswctype(_C,8);
  } while (iVar2 != 0);
  if (_C == L'-') {
    param_4 = param_4 | 2;
LAB_00896e4e:
    _C = *pwVar8;
    pwVar8 = pwVar7 + 2;
  }
  else if (_C == L'+') goto LAB_00896e4e;
  uVar6 = (uint)(ushort)_C;
  if (param_3 == 0) {
    iVar2 = __wchartodigit(uVar6);
    if (iVar2 != 0) {
      param_3 = 10;
      goto LAB_00896eac;
    }
    if ((*pwVar8 != L'x') && (*pwVar8 != L'X')) {
      param_3 = 8;
      goto LAB_00896eac;
    }
    param_3 = 0x10;
  }
  if (((param_3 == 0x10) && (iVar2 = __wchartodigit(uVar6), iVar2 == 0)) &&
     ((*pwVar8 == L'x' || (*pwVar8 == L'X')))) {
    uVar6 = (uint)(ushort)pwVar8[1];
    pwVar8 = pwVar8 + 2;
  }
LAB_00896eac:
  uVar3 = (uint)(0xffffffff / (ulonglong)(uint)param_3);
  do {
    uVar4 = __wchartodigit(uVar6);
    if (uVar4 == 0xffffffff) {
      uVar5 = (ushort)uVar6;
      if (((uVar5 < 0x41) || (0x5a < uVar5)) && (0x19 < (ushort)(uVar5 - 0x61))) {
LAB_00896f0d:
        pwVar8 = pwVar8 + -1;
        if ((param_4 & 8U) == 0) {
          if (param_2 != (wchar_t **)0x0) {
            pwVar8 = param_1;
          }
          local_8 = 0;
        }
        else if (((param_4 & 4U) != 0) ||
                (((param_4 & 1U) == 0 &&
                 ((((param_4 & 2U) != 0 && (0x80000000 < local_8)) ||
                  (((param_4 & 2U) == 0 && (0x7fffffff < local_8)))))))) {
          piVar1 = __errno();
          *piVar1 = 0x22;
          if ((param_4 & 1U) == 0) {
            local_8 = ((param_4 & 2U) != 0) + 0x7fffffff;
          }
          else {
            local_8 = 0xffffffff;
          }
        }
        if (param_2 != (wchar_t **)0x0) {
          *param_2 = pwVar8;
        }
        if ((param_4 & 2U) != 0) {
          local_8 = -local_8;
        }
        return local_8;
      }
      if ((ushort)(uVar5 - 0x61) < 0x1a) {
        uVar6 = uVar6 - 0x20;
      }
      uVar4 = uVar6 - 0x37;
    }
    if ((uint)param_3 <= uVar4) goto LAB_00896f0d;
    if ((local_8 < uVar3) ||
       ((local_8 == uVar3 && (uVar4 <= (uint)(0xffffffff % (ulonglong)(uint)param_3))))) {
      local_8 = local_8 * param_3 + uVar4;
      param_4 = param_4 | 8;
    }
    else {
      param_4 = param_4 | 0xc;
      if (param_2 == (wchar_t **)0x0) goto LAB_00896f0d;
    }
    uVar6 = (uint)(ushort)*pwVar8;
    pwVar8 = pwVar8 + 1;
  } while( true );
}

