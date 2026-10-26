
void FUN_00418440(int *param_1)

{
  int iVar1;
  void *_Dst;
  int *piVar2;
  
  piVar2 = (int *)*param_1;
  if (piVar2 != (int *)param_1[1]) {
    do {
      iVar1 = *piVar2;
      if (iVar1 != 0) {
        if (7 < *(uint *)(iVar1 + 0x18)) {
          FUN_0089120c(*(undefined4 *)(iVar1 + 4));
        }
        *(undefined4 *)(iVar1 + 0x18) = 7;
        *(undefined4 *)(iVar1 + 0x14) = 0;
        *(undefined2 *)(iVar1 + 4) = 0;
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

