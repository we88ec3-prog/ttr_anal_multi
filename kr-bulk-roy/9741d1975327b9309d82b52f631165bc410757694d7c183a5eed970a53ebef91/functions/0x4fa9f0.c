
void FUN_004fa9f0(void)

{
  undefined4 uVar1;
  uint uVar2;
  int *piVar3;
  HRESULT HVar4;
  int in_ECX;
  int *piVar5;
  undefined1 auStack_43c [4];
  FILE *local_438;
  LPCRITICAL_SECTION local_434;
  WCHAR local_430;
  undefined1 local_42e [518];
  WCHAR local_228;
  undefined1 local_226 [522];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009402c9;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_43c;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffbb8;
  ExceptionList = &local_14;
  local_434 = (LPCRITICAL_SECTION)(in_ECX + 0x170);
  EnterCriticalSection(local_434);
  local_c = 0;
  local_228 = L'\0';
  _memset(local_226,0,0x206);
  local_430 = L'\0';
  _memset(local_42e,0,0x206);
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c._0_1_ = 1;
    FUN_004e1590(uVar2);
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = (uint)local_c._1_3_ << 8;
  }
  uVar1 = DAT_00f94208;
  piVar5 = (int *)(in_ECX + 0x150);
  piVar3 = piVar5;
  if (7 < *(uint *)(in_ECX + 0x164)) {
    piVar3 = (int *)*piVar5;
  }
  FUN_00498ed0(L"%s/CR_%d.txt",piVar3,DAT_00f94208);
  FUN_00498ed0(L"./Rank/CR_%d",uVar1);
  DeleteFileW(&local_430);
  HVar4 = URLDownloadToFileW((LPUNKNOWN)0x0,&local_228,&local_430,0,(LPBINDSTATUSCALLBACK)0x0);
  if (-1 < HVar4) {
    FUN_004fa550(in_ECX,&local_430);
  }
  if (7 < *(uint *)(in_ECX + 0x164)) {
    piVar5 = (int *)*piVar5;
  }
  FUN_00498ed0(L"%s/BR_%d.txt",piVar5,uVar1);
  FUN_00498ed0(L"./Rank/BR_%d",uVar1);
  DeleteFileW(&local_430);
  HVar4 = URLDownloadToFileW((LPUNKNOWN)0x0,&local_228,&local_430,0,(LPBINDSTATUSCALLBACK)0x0);
  if (-1 < HVar4) {
    local_438 = (FILE *)0x0;
    __wfopen_s(&local_438,&local_430,L"r, ccs=UTF-16LE");
    if (local_438 != (FILE *)0x0) {
      FUN_004fa8e0(&local_438);
    }
  }
  LeaveCriticalSection(local_434);
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_43c);
  return;
}

