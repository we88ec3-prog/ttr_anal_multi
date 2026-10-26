
void FUN_0079da70(undefined4 param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090a270;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x70));
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_007a0f60(in_ECX + 0x28);
  LeaveCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x70));
  local_8 = 0xffffffff;
  if (param_2 != (int *)0x0) {
    LOCK();
    iVar1 = param_2[1] + -1;
    param_2[1] = iVar1;
    UNLOCK();
    if (iVar1 == 0) {
      (**(code **)*param_2)(uVar2);
      LOCK();
      iVar1 = param_2[2] + -1;
      param_2[2] = iVar1;
      UNLOCK();
      if (iVar1 == 0) {
        (**(code **)(*param_2 + 4))();
      }
    }
  }
  ExceptionList = local_10;
  return;
}

