
void FUN_0075a830(void)

{
  int in_ECX;
  undefined2 *in_EDX;
  uint uStack_50;
  uint local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0091ef09;
  local_10 = ExceptionList;
  uStack_50 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_50;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_50;
  for (; in_ECX != 0; in_ECX = in_ECX + -1) {
    local_20 = 7;
    local_24 = 0;
    local_34[0] = local_34[0] & 0xffff0000;
    local_8._0_1_ = 2;
    if (in_EDX != (undefined2 *)0x0) {
      *(undefined4 *)(in_EDX + 10) = 7;
      *(undefined4 *)(in_EDX + 8) = 0;
      *in_EDX = 0;
      FUN_00402800(local_34);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    if (7 < local_20) {
      FUN_0089120c(local_34[0]);
    }
    in_EDX = in_EDX + 0xe;
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

