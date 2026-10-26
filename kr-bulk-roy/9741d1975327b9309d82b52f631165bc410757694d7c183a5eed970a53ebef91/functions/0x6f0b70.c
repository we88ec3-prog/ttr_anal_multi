
void FUN_006f0b70(char *param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00907f80;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  lpCriticalSection = (LPCRITICAL_SECTION)(in_ECX + 4);
  EnterCriticalSection(lpCriticalSection);
  local_8 = 0;
  if (*(char *)(in_ECX + 0x1d0) != '\0') {
    LeaveCriticalSection(lpCriticalSection);
    ExceptionList = local_10;
    return;
  }
  local_14 = (char *)FUN_00891268(0x800,uVar2);
  if (local_14 == (char *)0x0) {
    local_14 = (char *)0x0;
  }
  else {
    _memset(local_14,0,0x800);
  }
  if (param_1 != (char *)0x0) {
    _strncpy_s(local_14,0x800,param_1,0x7ff);
  }
  FUN_006f0650(param_1);
  EnterCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x1c));
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar1 = *(int *)(in_ECX + 0x4c);
  iVar3 = FUN_0074d700(iVar1,*(undefined4 *)(iVar1 + 4),&local_14);
  if (*(int *)(in_ECX + 0x50) == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  *(int *)(in_ECX + 0x50) = *(int *)(in_ECX + 0x50) + 1;
  *(int *)(iVar1 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  LeaveCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x1c));
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = local_10;
  return;
}

