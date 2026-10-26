
void FUN_0047e750(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 in_ECX;
  int unaff_EDI;
  uint uVar3;
  undefined4 local_4c;
  uint local_38;
  undefined4 local_30;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009200ec;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar1 = DAT_00faaf7c & 1;
  *(undefined4 *)(unaff_EDI + 0x10) = param_1;
  *(undefined4 *)(unaff_EDI + 0x14) = in_ECX;
  uVar3 = uVar2;
  if (uVar1 == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8 = 0;
    FUN_0058d410(uVar2);
    _atexit((_func_4879 *)&LAB_00bccdc0);
  }
  local_8 = 0xffffffff;
  FUN_0040ef80();
  local_8 = 1;
  FUN_0058ec10(&DAT_00faaf80,L"HistoryChapter");
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8 = 2;
    FUN_0058d410(uVar3);
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_8 = 0xffffffff;
  }
  FUN_0040ef80();
  local_8 = 3;
  FUN_0058ec10(&DAT_00faaf80,L"HistoryQuest");
  if (7 < local_38) {
    FUN_0089120c(local_4c);
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

