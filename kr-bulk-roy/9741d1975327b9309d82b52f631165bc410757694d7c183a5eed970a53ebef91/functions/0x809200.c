
void FUN_00809200(int *param_1)

{
  int *piVar1;
  int iVar2;
  void *_Dst;
  void **ppvVar3;
  uint uVar4;
  int *piVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00905218;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_8 = 0;
  piVar1 = (int *)param_1[1];
  ppvVar3 = &local_10;
  local_10 = ExceptionList;
  for (piVar5 = (int *)*param_1; ExceptionList = ppvVar3, piVar5 != piVar1; piVar5 = piVar5 + 1) {
    iVar2 = *piVar5;
    if (iVar2 != 0) {
      FUN_008097e0(iVar2);
      FUN_0089120c(iVar2,uVar4);
      *piVar5 = 0;
    }
    ppvVar3 = ExceptionList;
  }
  _Dst = (void *)*param_1;
  if (_Dst != (void *)param_1[1]) {
    FID_conflict__memcpy(_Dst,(void *)param_1[1],0);
    param_1[1] = (int)_Dst;
  }
  if (*param_1 != 0) {
    FUN_0089120c(*param_1,uVar4);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  ExceptionList = local_10;
  return;
}

