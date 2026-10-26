
void FUN_006d9280(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  undefined4 *in_EDX;
  undefined1 auStack_7c [4];
  LPCRITICAL_SECTION local_78;
  undefined4 *local_74;
  undefined4 local_70;
  uint local_6c;
  undefined4 local_5c;
  uint local_58;
  undefined4 local_50;
  undefined2 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_38 [4];
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00915fa8;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_7c;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff78;
  ExceptionList = &local_14;
  local_78 = (LPCRITICAL_SECTION)(in_ECX + 0xb4);
  local_74 = in_EDX;
  EnterCriticalSection(local_78);
  local_c = 0;
  local_24 = 0xf;
  local_28 = 0;
  local_38[0] = local_38[0] & 0xffffff00;
  FUN_00402a70(&DAT_00bf2375,0);
  local_c._0_1_ = 1;
  local_70 = *in_EDX;
  local_58 = 0xf;
  local_5c = 0;
  local_6c = local_6c & 0xffffff00;
  FUN_00403040(local_38,0,0xffffffff);
  local_44 = 0x3f800000;
  local_40 = param_1;
  local_50 = 1;
  local_4c = 10000;
  local_48 = 1;
  local_3c = 0;
  local_c = CONCAT31(local_c._1_3_,2);
  iVar1 = *(int *)(in_ECX + 0x28);
  iVar3 = FUN_006daba0(iVar1,*(undefined4 *)(iVar1 + 4),&local_70);
  if (*(int *)(in_ECX + 0x2c) == 0x4924923) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  *(int *)(in_ECX + 0x2c) = *(int *)(in_ECX + 0x2c) + 1;
  *(int *)(iVar1 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  if (0xf < local_58) {
    FUN_0089120c(local_6c,uVar2);
  }
  local_58 = 0xf;
  local_5c = 0;
  local_6c = local_6c & 0xffffff00;
  if (0xf < local_24) {
    FUN_0089120c(local_38[0]);
  }
  *local_74 = 0;
  iVar1 = *(int *)(in_ECX + 0xac);
  *(undefined4 *)(iVar1 + 0x10) = 1;
  SetEvent(*(HANDLE *)(iVar1 + 0xc));
  LeaveCriticalSection(local_78);
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_7c);
  return;
}

