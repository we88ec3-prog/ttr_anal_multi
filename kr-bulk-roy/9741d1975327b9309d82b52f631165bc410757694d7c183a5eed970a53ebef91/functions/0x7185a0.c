
void FUN_007185a0(undefined4 *param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  int iVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009059cb;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  lpCriticalSection = (LPCRITICAL_SECTION)*param_1;
  if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
    DeleteCriticalSection(lpCriticalSection);
    FUN_0089120c(lpCriticalSection);
    *param_1 = 0;
  }
  if ((undefined4 *)param_1[9] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[9])(0,uVar3);
  }
  iVar2 = param_1[0xb];
  while (iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 0x28);
    *(undefined4 *)(iVar2 + 0x28) = 0;
    if ((*(int *)(iVar2 + 0xc) != 0) && (*(int *)(iVar2 + 0x48) != 0)) {
      FUN_00891d3d(*(int *)(iVar2 + 0x48));
      *(undefined4 *)(iVar2 + 0x48) = 0;
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x2c));
    FUN_0089120c(iVar2);
    iVar2 = iVar1;
  }
  if ((int *)param_1[9] != (int *)0x0) {
    (**(code **)(*(int *)param_1[9] + 0x14))(1);
    param_1[9] = 0;
  }
  if (param_1[0xe] != 0) {
    FUN_00891d3d(param_1[0xe]);
    param_1[0xe] = 0;
  }
  if (0xf < (uint)param_1[6]) {
    FUN_0089120c(param_1[1]);
  }
  param_1[6] = 0xf;
  param_1[5] = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  ExceptionList = local_10;
  return;
}

