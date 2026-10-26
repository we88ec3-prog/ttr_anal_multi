
void FUN_00807e80(int param_1,void *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uintptr_t uVar3;
  int iVar4;
  uint uStack_30;
  _SYSTEM_INFO local_2c;
  
  GetSystemInfo(&local_2c);
  uVar1 = local_2c.dwNumberOfProcessors * 2 + 2;
  *(uint *)(param_1 + 4) = uVar1;
  uVar2 = FUN_0087dc3d(-(uint)((int)((ulonglong)uVar1 * 4 >> 0x20) != 0) |
                       (uint)((ulonglong)uVar1 * 4));
  iVar4 = 0;
  *(undefined4 *)(param_1 + 8) = uVar2;
  if (0 < (int)uVar1) {
    do {
      uStack_30 = 0;
      uVar3 = __beginthreadex((void *)0x0,0,FUN_00807f90,param_2,0,&uStack_30);
      *(uintptr_t *)(*(int *)(param_1 + 8) + iVar4 * 4) = uVar3;
      *(uint *)((int)param_2 + 4) = uStack_30;
      FUN_006d8c40(uStack_30);
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)uVar1);
  }
  return;
}

