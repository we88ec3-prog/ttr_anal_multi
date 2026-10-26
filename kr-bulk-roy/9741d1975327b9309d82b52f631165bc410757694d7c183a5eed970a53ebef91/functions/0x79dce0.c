
undefined4 FUN_0079dce0(undefined4 *param_1,int *param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  HANDLE pvVar4;
  int in_ECX;
  int *unaff_FS_OFFSET;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009056b0;
  local_10 = *unaff_FS_OFFSET;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  lpCriticalSection = (LPCRITICAL_SECTION)(in_ECX + 0x70);
  local_8 = 0;
  EnterCriticalSection(lpCriticalSection);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (*(int *)(in_ECX + 0x68) != 0) {
    LeaveCriticalSection(lpCriticalSection);
    local_8 = 0xffffffff;
    if (param_2 != (int *)0x0) {
      LOCK();
      iVar2 = param_2[1] + -1;
      param_2[1] = iVar2;
      UNLOCK();
      if (iVar2 == 0) {
        (**(code **)*param_2)();
        LOCK();
        iVar2 = param_2[2] + -1;
        param_2[2] = iVar2;
        UNLOCK();
        if (iVar2 == 0) {
          (**(code **)(*param_2 + 4))();
        }
      }
    }
    *unaff_FS_OFFSET = local_10;
    return 0;
  }
  pvVar4 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  *param_1 = pvVar4;
  FUN_007a0da0(uVar3);
  uVar1 = *param_1;
  LeaveCriticalSection(lpCriticalSection);
  local_8 = 0xffffffff;
  if (param_2 != (int *)0x0) {
    LOCK();
    iVar2 = param_2[1] + -1;
    param_2[1] = iVar2;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)*param_2)();
      LOCK();
      iVar2 = param_2[2] + -1;
      param_2[2] = iVar2;
      UNLOCK();
      if (iVar2 == 0) {
        (**(code **)(*param_2 + 4))();
      }
    }
  }
  *unaff_FS_OFFSET = local_10;
  return uVar1;
}

