
void FUN_0076c3b0(int *param_1)

{
  void *_Dst;
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)param_1[1]) {
    do {
      if ((int *)*piVar1 != (int *)0x0) {
        (**(code **)(*(int *)*piVar1 + 0x1c))(1);
      }
      piVar1 = piVar1 + 1;
    } while (piVar1 != (int *)param_1[1]);
  }
  _Dst = (void *)*param_1;
  if (_Dst != (void *)param_1[1]) {
    FID_conflict__memcpy(_Dst,(void *)param_1[1],0);
    param_1[1] = (int)_Dst;
  }
  return;
}

