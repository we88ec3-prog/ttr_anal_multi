
void FUN_00580090(int *param_1)

{
  int iVar1;
  void *_Dst;
  int *piVar2;
  
  piVar2 = (int *)*param_1;
  if (piVar2 != (int *)param_1[1]) {
    do {
      iVar1 = *piVar2;
      if (iVar1 != 0) {
        FUN_0057fd00(iVar1);
        FUN_0089120c(iVar1);
      }
      piVar2 = piVar2 + 1;
    } while (piVar2 != (int *)param_1[1]);
  }
  _Dst = (void *)*param_1;
  if (_Dst != (void *)param_1[1]) {
    FID_conflict__memcpy(_Dst,(void *)param_1[1],0);
    param_1[1] = (int)_Dst;
  }
  return;
}

