
undefined4 FUN_006f23f0(undefined4 *param_1,HWND param_2)

{
  uint uVar1;
  undefined4 in_EAX;
  HIMC pHVar2;
  DWORD dwBufLen;
  int in_ECX;
  
  switch(in_EAX) {
  case 3:
  case 5:
    pHVar2 = ImmGetContext(param_2);
    if (pHVar2 != (HIMC)0x0) {
      FUN_00402400(0,0xffffffff);
      dwBufLen = ImmGetCandidateListW(pHVar2,0,(LPCANDIDATELIST)0x0,0);
      if (0 < (int)dwBufLen) {
        FUN_00407c90();
        ImmGetCandidateListW(pHVar2,0,(LPCANDIDATELIST)*param_1,dwBufLen);
      }
      ImmReleaseContext(param_2,pHVar2);
    }
    return 1;
  case 4:
    FUN_00407c90();
    break;
  case 6:
  case 8:
    FUN_006f2f80();
    return 0;
  default:
    return 0;
  case 0xe:
    FUN_006f2ac0(param_1,param_2);
    uVar1 = param_1[0x21];
    if (uVar1 < 0x5000405) {
      if (uVar1 != 0x5000404) {
        if (uVar1 < 0x4020805) {
          if (((uVar1 != 0x4020804) && (uVar1 != 0x4010804)) && (uVar1 != 0x4020404)) {
            return 0;
          }
        }
        else if ((uVar1 != 0x4030404) && (uVar1 != 0x4040404)) {
          return 0;
        }
        if ((in_ECX != 1) && (in_ECX != 2)) {
          return 0;
        }
        return 1;
      }
    }
    else if (uVar1 < 0x5030805) {
      if (((uVar1 != 0x5030804) && (uVar1 != 0x5010404)) && (uVar1 != 0x5020404)) {
        return 0;
      }
    }
    else if (uVar1 != 0x6000404) {
      return 0;
    }
    if ((((in_ECX != 0x10) && (in_ECX != 0x11)) && (in_ECX != 0x1a)) &&
       ((in_ECX != 0x1b && (in_ECX != 0x1c)))) {
      return 0;
    }
  }
  return 1;
}

