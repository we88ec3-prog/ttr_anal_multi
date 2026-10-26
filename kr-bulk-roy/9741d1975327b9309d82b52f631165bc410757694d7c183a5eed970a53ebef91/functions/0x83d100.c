
undefined4 FUN_0083d100(undefined4 param_1,size_t param_2,void *param_3)

{
  int iVar1;
  int *piVar2;
  void *_Dst;
  int in_ECX;
  
  if (param_3 != (void *)0x0) {
    _Dst = (void *)FUN_00838f30(param_2,param_1);
    if (_Dst != (void *)0x0) {
      FID_conflict__memcpy(_Dst,param_3,param_2);
      iVar1 = *(int *)(*(int *)(in_ECX + 0x354) + *(int *)(in_ECX + 0x364) * 4);
      if ((*(int *)(iVar1 + 0x14) != 0) && (piVar2 = *(int **)(iVar1 + 8), piVar2 != (int *)0x0)) {
        (**(code **)(*piVar2 + 0x30))(piVar2);
        *(undefined4 *)(iVar1 + 0x14) = 0;
      }
      return 1;
    }
    iVar1 = *(int *)(*(int *)(in_ECX + 0x354) + *(int *)(in_ECX + 0x364) * 4);
    if ((*(int *)(iVar1 + 0x14) != 0) && (piVar2 = *(int **)(iVar1 + 8), piVar2 != (int *)0x0)) {
      (**(code **)(*piVar2 + 0x30))(piVar2);
      *(undefined4 *)(iVar1 + 0x14) = 0;
    }
  }
  return 0;
}

