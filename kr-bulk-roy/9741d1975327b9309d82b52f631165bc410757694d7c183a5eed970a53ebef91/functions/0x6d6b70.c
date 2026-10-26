
void FUN_006d6b70(wchar_t *param_1)

{
  undefined4 in_ECX;
  wchar_t *in_EDX;
  undefined2 *unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 1) = in_ECX;
  *unaff_ESI = 0x81;
  *(undefined4 *)(unaff_ESI + 3) = 0;
  *(undefined4 *)(unaff_ESI + 5) = 0;
  *(undefined4 *)(unaff_ESI + 7) = 0;
  *(undefined4 *)(unaff_ESI + 9) = 0;
  *(undefined4 *)(unaff_ESI + 0xb) = 0;
  *(undefined4 *)(unaff_ESI + 0xd) = 0;
  *(undefined4 *)(unaff_ESI + 0xf) = 0;
  *(undefined4 *)(unaff_ESI + 0x11) = 0;
  *(undefined4 *)(unaff_ESI + 0x13) = 0;
  *(undefined4 *)(unaff_ESI + 0x15) = 0;
  *(undefined1 *)(unaff_ESI + 0x17) = 0;
  *(undefined4 *)((int)unaff_ESI + 0x2f) = 0;
  *(undefined1 *)((int)unaff_ESI + 0x33) = 0;
  *(undefined4 *)(unaff_ESI + 0x1a) = 0;
  if (in_EDX != (wchar_t *)0x0) {
    _wcsncpy_s(unaff_ESI + 3,10,in_EDX,10);
  }
  if (param_1 != (wchar_t *)0x0) {
    _wcsncpy_s(unaff_ESI + 0xd,10,param_1,10);
  }
  return;
}

