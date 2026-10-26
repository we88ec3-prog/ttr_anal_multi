
void FUN_007ee410(void)

{
  undefined4 *puVar1;
  void *_Dst;
  int unaff_ESI;
  uint uVar2;
  
  uVar2 = 0;
  if (*(int *)(unaff_ESI + 0x10) - *(int *)(unaff_ESI + 0xc) >> 2 != 0) {
    do {
      if (*(int *)(*(int *)(unaff_ESI + 0xc) + uVar2 * 4) != 0) {
        puVar1 = *(undefined4 **)(*(int *)(unaff_ESI + 0xc) + uVar2 * 4);
        if (puVar1 != (undefined4 *)0x0) {
          (**(code **)*puVar1)(1);
        }
        *(undefined4 *)(*(int *)(unaff_ESI + 0xc) + uVar2 * 4) = 0;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)(*(int *)(unaff_ESI + 0x10) - *(int *)(unaff_ESI + 0xc) >> 2));
  }
  _Dst = *(void **)(unaff_ESI + 0xc);
  if (_Dst != *(void **)(unaff_ESI + 0x10)) {
    FID_conflict__memcpy(_Dst,*(void **)(unaff_ESI + 0x10),0);
    *(void **)(unaff_ESI + 0x10) = _Dst;
  }
  return;
}

