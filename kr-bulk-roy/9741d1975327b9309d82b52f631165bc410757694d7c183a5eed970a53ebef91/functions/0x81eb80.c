
undefined4 FUN_0081eb80(int *param_1,wchar_t *param_2,int param_3)

{
  int iVar1;
  wchar_t *pwVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  if (param_3 == 0) {
    if (*param_2 != L'\0') {
      do {
        iVar1 = param_1[1] - *param_1 >> 0x1f;
        iVar4 = (param_1[1] - *param_1) / 0x1c + iVar1;
        uVar6 = 0;
        if (iVar4 != iVar1) {
          iVar5 = 0;
          do {
            pwVar2 = (wchar_t *)(*param_1 + iVar5);
            if (7 < *(uint *)(pwVar2 + 10)) {
              pwVar2 = *(wchar_t **)pwVar2;
            }
            iVar3 = __wcsnicmp(param_2,pwVar2,*(size_t *)(*param_1 + 0x10 + iVar5));
            if (iVar3 == 0) {
              return 1;
            }
            uVar6 = uVar6 + 1;
            iVar5 = iVar5 + 0x1c;
          } while (uVar6 < (uint)(iVar4 - iVar1));
        }
        param_2 = param_2 + 1;
        if (*param_2 == L'\0') {
          return 0;
        }
      } while( true );
    }
  }
  else {
    iVar1 = param_1[1] - *param_1 >> 0x1f;
    iVar4 = (param_1[1] - *param_1) / 0x1c + iVar1;
    uVar6 = 0;
    if (iVar4 != iVar1) {
      iVar5 = 0;
      do {
        pwVar2 = (wchar_t *)(*param_1 + iVar5);
        if (7 < *(uint *)(pwVar2 + 10)) {
          pwVar2 = *(wchar_t **)pwVar2;
        }
        iVar3 = __wcsicmp(param_2,pwVar2);
        if (iVar3 == 0) {
          return 1;
        }
        uVar6 = uVar6 + 1;
        iVar5 = iVar5 + 0x1c;
      } while (uVar6 < (uint)(iVar4 - iVar1));
    }
  }
  return 0;
}

