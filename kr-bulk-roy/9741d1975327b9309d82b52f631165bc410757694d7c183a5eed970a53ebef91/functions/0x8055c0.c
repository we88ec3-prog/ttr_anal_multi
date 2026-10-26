
void FUN_008055c0(int *param_1)

{
  int iVar1;
  void *_Dst;
  LPCRITICAL_SECTION lpCriticalSection;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00909a59;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 3;
  piVar4 = (int *)*param_1;
  DAT_00fba858 = 0;
  DAT_00fba85c = 1;
  if (piVar4 != (int *)param_1[1]) {
    do {
      iVar1 = *piVar4;
      if (iVar1 != 0) {
        FUN_00805e70(iVar1);
        FUN_0089120c(iVar1,uVar2);
      }
      piVar4 = piVar4 + 1;
    } while (piVar4 != (int *)param_1[1]);
  }
  _Dst = (void *)*param_1;
  if (_Dst != (void *)param_1[1]) {
    FID_conflict__memcpy(_Dst,(void *)param_1[1],0);
    param_1[1] = (int)_Dst;
  }
  lpCriticalSection = (LPCRITICAL_SECTION)param_1[0xd];
  if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
    DeleteCriticalSection(lpCriticalSection);
    FUN_0089120c(lpCriticalSection,uVar2);
  }
  piVar4 = (int *)param_1[0x12];
  piVar3 = (int *)*piVar4;
  *piVar4 = (int)piVar4;
  *(int *)(param_1[0x12] + 4) = param_1[0x12];
  param_1[0x13] = 0;
  if (piVar3 != (int *)param_1[0x12]) {
    do {
      piVar4 = (int *)*piVar3;
      FUN_0089120c(piVar3,uVar2);
      piVar3 = piVar4;
    } while (piVar4 != (int *)param_1[0x12]);
  }
  FUN_0089120c(param_1[0x12],uVar2);
  piVar4 = (int *)param_1[10];
  piVar3 = (int *)*piVar4;
  *piVar4 = (int)piVar4;
  *(int *)(param_1[10] + 4) = param_1[10];
  param_1[0xb] = 0;
  if (piVar3 != (int *)param_1[10]) {
    do {
      piVar4 = (int *)*piVar3;
      FUN_0089120c(piVar3);
      piVar3 = piVar4;
    } while (piVar4 != (int *)param_1[10]);
  }
  FUN_0089120c(param_1[10]);
  FUN_007b6d70();
  FUN_0089120c(param_1[4]);
  param_1[4] = 0;
  if (*param_1 != 0) {
    FUN_0089120c(*param_1);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  ExceptionList = local_10;
  return;
}

