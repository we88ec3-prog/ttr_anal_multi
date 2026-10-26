
void FUN_00461e40(void)

{
  code *pcVar1;
  int in_ECX;
  undefined1 auStack_60 [4];
  int local_5c;
  undefined4 local_58;
  undefined1 local_54 [56];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00931598;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_60;
  ExceptionList = &local_14;
  FUN_00755e50(DAT_00d61f20 ^ (uint)&stack0xffffff98);
  FUN_0043c570(400);
  FUN_00635840();
  FUN_0043c570(100);
  FUN_00757200(local_54);
  local_c = 0;
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c._0_1_ = 1;
    local_c._1_3_ = 0;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_c = (uint)local_c._1_3_ << 8;
  }
  local_58 = 799;
  FUN_005740f0(&local_58);
  if (local_5c != DAT_00fe5ac8) {
    FUN_00757710();
    FUN_00757710();
    (**(code **)(**(int **)(in_ECX + 0xf4) + 200))();
    local_c = 0xffffffff;
    FUN_00757640(local_54);
    ExceptionList = local_14;
    __security_check_cookie(local_1c ^ (uint)auStack_60);
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

