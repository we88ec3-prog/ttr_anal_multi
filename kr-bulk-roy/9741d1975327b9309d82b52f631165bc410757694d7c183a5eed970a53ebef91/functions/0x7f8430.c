
void FUN_007f8430(void)

{
  int *piVar1;
  void *_Dst;
  int unaff_ESI;
  uint uVar2;
  
  uVar2 = 0;
  if (*(int *)(unaff_ESI + 0x98) - *(int *)(unaff_ESI + 0x94) >> 2 != 0) {
    do {
      if (*(int *)(*(int *)(unaff_ESI + 0x94) + uVar2 * 4) != 0) {
        piVar1 = *(int **)(*(int *)(unaff_ESI + 0x94) + uVar2 * 4);
        (**(code **)(*piVar1 + 8))(piVar1);
        *(undefined4 *)(*(int *)(unaff_ESI + 0x94) + uVar2 * 4) = 0;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)(*(int *)(unaff_ESI + 0x98) - *(int *)(unaff_ESI + 0x94) >> 2));
  }
  _Dst = *(void **)(unaff_ESI + 0x94);
  if (_Dst != *(void **)(unaff_ESI + 0x98)) {
    FID_conflict__memcpy(_Dst,*(void **)(unaff_ESI + 0x98),0);
    *(void **)(unaff_ESI + 0x98) = _Dst;
  }
  piVar1 = *(int **)(unaff_ESI + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(unaff_ESI + 4) = 0;
  }
  return;
}

