
/* Library Function - Single Match
    __wsplitpath_helper
   
   Library: Visual Studio 2010 Release */

undefined4
__wsplitpath_helper(wchar_t *param_1,wchar_t *param_2,uint param_3,wchar_t *param_4,uint param_5,
                   wchar_t *param_6,uint param_7,wchar_t *param_8,uint param_9)

{
  wchar_t wVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  wchar_t *_Src;
  wchar_t *pwVar6;
  wchar_t *pwVar7;
  undefined4 uVar8;
  
  bVar2 = false;
  if (param_1 != (wchar_t *)0x0) {
    if (param_2 == (wchar_t *)0x0) {
      if (param_3 == 0) {
LAB_0089c527:
        if (param_4 == (wchar_t *)0x0) {
          if (param_5 == 0) {
LAB_0089c538:
            if (param_6 == (wchar_t *)0x0) {
              if (param_7 == 0) {
LAB_0089c549:
                if (param_8 == (wchar_t *)0x0) {
                  if (param_9 == 0) {
LAB_0089c553:
                    iVar3 = 1;
                    pwVar7 = param_1;
                    do {
                      if (*pwVar7 == L'\0') break;
                      iVar3 = iVar3 + -1;
                      pwVar7 = pwVar7 + 1;
                    } while (iVar3 != 0);
                    if (*pwVar7 == L':') {
                      if (param_2 != (wchar_t *)0x0) {
                        if (param_3 < 3) goto LAB_0089c69a;
                        _wcsncpy_s(param_2,0xffffffff,param_1,2);
                      }
                      param_1 = pwVar7 + 1;
                    }
                    else if (param_2 != (wchar_t *)0x0) {
                      *param_2 = L'\0';
                    }
                    wVar1 = *param_1;
                    pwVar7 = (wchar_t *)0x0;
                    _Src = (wchar_t *)0x0;
                    pwVar6 = param_1;
                    if (wVar1 == L'\0') {
LAB_0089c60f:
                      pwVar7 = param_1;
                      if (param_4 != (wchar_t *)0x0) {
                        *param_4 = L'\0';
                      }
                    }
                    else {
                      do {
                        if ((wVar1 == L'/') || (wVar1 == L'\\')) {
                          pwVar7 = pwVar6 + 1;
                        }
                        else if (wVar1 == L'.') {
                          _Src = pwVar6;
                        }
                        pwVar6 = pwVar6 + 1;
                        wVar1 = *pwVar6;
                      } while (wVar1 != L'\0');
                      if (pwVar7 == (wchar_t *)0x0) goto LAB_0089c60f;
                      if (param_4 != (wchar_t *)0x0) {
                        uVar4 = (int)pwVar7 - (int)param_1 >> 1;
                        if (param_5 <= uVar4) goto LAB_0089c69a;
                        _wcsncpy_s(param_4,0xffffffff,param_1,uVar4);
                      }
                    }
                    param_1 = pwVar7;
                    if ((_Src == (wchar_t *)0x0) || (_Src < param_1)) {
                      if (param_6 != (wchar_t *)0x0) {
                        uVar4 = (int)pwVar6 - (int)param_1 >> 1;
                        if (param_7 <= uVar4) goto LAB_0089c69a;
                        _wcsncpy_s(param_6,0xffffffff,param_1,uVar4);
                      }
                      if (param_8 != (wchar_t *)0x0) {
                        *param_8 = L'\0';
                      }
                      return 0;
                    }
                    if (param_6 != (wchar_t *)0x0) {
                      uVar4 = (int)_Src - (int)param_1 >> 1;
                      if (param_7 <= uVar4) goto LAB_0089c69a;
                      _wcsncpy_s(param_6,0xffffffff,param_1,uVar4);
                    }
                    if (param_8 == (wchar_t *)0x0) {
                      return 0;
                    }
                    uVar4 = (int)pwVar6 - (int)_Src >> 1;
                    if (uVar4 < param_9) {
                      _wcsncpy_s(param_8,0xffffffff,_Src,uVar4);
                      return 0;
                    }
                    goto LAB_0089c69a;
                  }
                }
                else if (param_9 != 0) goto LAB_0089c553;
              }
            }
            else if (param_7 != 0) goto LAB_0089c549;
          }
        }
        else if (param_5 != 0) goto LAB_0089c538;
      }
    }
    else if (param_3 != 0) goto LAB_0089c527;
  }
  bVar2 = true;
LAB_0089c69a:
  if ((param_2 != (wchar_t *)0x0) && (param_3 != 0)) {
    *param_2 = L'\0';
  }
  if ((param_4 != (wchar_t *)0x0) && (param_5 != 0)) {
    *param_4 = L'\0';
  }
  if ((param_6 != (wchar_t *)0x0) && (param_7 != 0)) {
    *param_6 = L'\0';
  }
  if ((param_8 != (wchar_t *)0x0) && (param_9 != 0)) {
    *param_8 = L'\0';
  }
  if ((param_1 == (wchar_t *)0x0) || (bVar2)) {
    piVar5 = __errno();
    uVar8 = 0x16;
    *piVar5 = 0x16;
    FUN_00893343();
  }
  else {
    piVar5 = __errno();
    uVar8 = 0x22;
    *piVar5 = 0x22;
  }
  return uVar8;
}

