
void FUN_005448e0(int param_1)

{
  void *_Dst;
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 != *(int **)(param_1 + 8)) {
    do {
      if ((undefined4 *)*piVar1 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar1)(1);
      }
      piVar1 = piVar1 + 1;
    } while (piVar1 != *(int **)(param_1 + 8));
  }
  _Dst = *(void **)(param_1 + 4);
  if (_Dst != *(void **)(param_1 + 8)) {
    FID_conflict__memcpy(_Dst,*(void **)(param_1 + 8),0);
    *(void **)(param_1 + 8) = _Dst;
  }
  return;
}

