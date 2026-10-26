
void FUN_004a8730(int *param_1)

{
  int iVar1;
  void *_Dst;
  int *piVar2;
  
  piVar2 = (int *)*param_1;
  if (piVar2 != (int *)param_1[1]) {
    do {
      iVar1 = *piVar2;
      if (iVar1 != 0) {
        if (*(int *)(iVar1 + 0x2c) != 0) {
          FUN_0089120c(*(int *)(iVar1 + 0x2c));
        }
        *(undefined4 *)(iVar1 + 0x2c) = 0;
        *(undefined4 *)(iVar1 + 0x30) = 0;
        *(undefined4 *)(iVar1 + 0x34) = 0;
        if (7 < *(uint *)(iVar1 + 0x20)) {
          FUN_0089120c(*(undefined4 *)(iVar1 + 0xc));
        }
        *(undefined4 *)(iVar1 + 0x20) = 7;
        *(undefined4 *)(iVar1 + 0x1c) = 0;
        *(undefined2 *)(iVar1 + 0xc) = 0;
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

