
void FUN_00523e40(int *param_1)

{
  void *_Dst;
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)param_1[1]) {
    do {
      if ((undefined4 *)*piVar1 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar1)(1);
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

