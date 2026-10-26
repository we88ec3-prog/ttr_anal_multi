
void FUN_006f2f80(void)

{
  ushort uVar1;
  wint_t wVar2;
  BOOL BVar3;
  HIMC pHVar4;
  HWND in_ECX;
  int unaff_ESI;
  DWORD local_20;
  uint local_1c;
  HWND local_18;
  char local_14;
  char local_13;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  uVar1 = *(ushort *)(unaff_ESI + 0x72);
  switch(uVar1 & 0x3ff) {
  case 4:
    *(undefined1 *)(unaff_ESI + 0x7e) = 1;
    if (uVar1 >> 10 == 1) {
      *(undefined **)(unaff_ESI + 0x80) = &DAT_00d63d60;
      break;
    }
    if (uVar1 >> 10 == 2) {
      *(undefined **)(unaff_ESI + 0x80) = &DAT_00d63d5a;
      *(bool *)(unaff_ESI + 0x7e) = *(int *)(unaff_ESI + 0x84) == 0;
      break;
    }
  default:
    *(undefined **)(unaff_ESI + 0x80) = &DAT_00d63d54;
    break;
  case 0x11:
    *(undefined1 *)(unaff_ESI + 0x7e) = 1;
    *(undefined **)(unaff_ESI + 0x80) = &DAT_00d63d6c;
    break;
  case 0x12:
    *(undefined1 *)(unaff_ESI + 0x7e) = 0;
    *(undefined **)(unaff_ESI + 0x80) = &DAT_00d63d66;
    break;
  case 0x1e:
    *(undefined1 *)(unaff_ESI + 0x7e) = 1;
    *(undefined2 **)(unaff_ESI + 0x80) = &DAT_00d63d72;
  }
  local_18 = in_ECX;
  if (*(undefined **)(unaff_ESI + 0x80) == &DAT_00d63d54) {
    GetLocaleInfoA((uint)uVar1,3,&local_14,10);
    **(short **)(unaff_ESI + 0x80) = (short)local_14;
    wVar2 = _towlower((short)local_13);
    *(wint_t *)(*(int *)(unaff_ESI + 0x80) + 2) = wVar2;
  }
  BVar3 = ImmIsIME(*(HKL *)(unaff_ESI + 0x74));
  pHVar4 = ImmGetContext(in_ECX);
  if (pHVar4 != (HIMC)0x0) {
    if ((*(ushort *)(unaff_ESI + 0x72) & 0x3ff) == 4) {
      if (BVar3 != 0) {
        ImmGetConversionStatus(pHVar4,&local_1c,&local_20);
        *(uint *)(unaff_ESI + 0x78) = 2 - (uint)((local_1c & 1) != 0);
        ImmReleaseContext(local_18,pHVar4);
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
    }
    else if ((BVar3 != 0) && (BVar3 = ImmGetOpenStatus(pHVar4), BVar3 != 0)) {
      *(undefined4 *)(unaff_ESI + 0x78) = 1;
      ImmReleaseContext(local_18,pHVar4);
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    *(undefined4 *)(unaff_ESI + 0x78) = 0;
    ImmReleaseContext(local_18,pHVar4);
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *(undefined4 *)(unaff_ESI + 0x78) = 0;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

