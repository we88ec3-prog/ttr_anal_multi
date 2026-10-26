
void FUN_00647a00(void)

{
  uint uVar1;
  int in_ECX;
  undefined4 local_4c;
  uint local_38;
  undefined4 local_30;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920e22;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00745930(uVar1);
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_00647a66;
    in_ECX = FUN_00745c20();
  }
  if (((in_ECX != 0) && ((*(uint *)(in_ECX + 0x28) >> 0xc & 1) == 0)) &&
     (*(int *)(in_ECX + 0x60) != 0)) {
    FUN_00749f40(in_ECX);
  }
LAB_00647a66:
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8 = 0;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_8 = 0xffffffff;
  }
  FUN_0040ef80();
  local_8 = 1;
  FUN_0058ec10(&DAT_00faaf80,L"left");
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8 = 2;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_8 = 0xffffffff;
  }
  FUN_0040ef80();
  local_8 = 3;
  FUN_0058ec10(&DAT_00faaf80,&DAT_00c30704);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8 = 4;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_8 = 0xffffffff;
  }
  FUN_00590230();
  local_8 = 5;
  FUN_0058ec10(&DAT_00faaf80,L"ChatFontSize");
  if (7 < local_38) {
    FUN_0089120c(local_4c);
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}

