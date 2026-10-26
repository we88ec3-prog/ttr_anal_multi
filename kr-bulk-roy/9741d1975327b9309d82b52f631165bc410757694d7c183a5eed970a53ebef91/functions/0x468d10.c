
/* WARNING: Type propagation algorithm not settling */

void FUN_00468d10(void)

{
  code *pcVar1;
  int local_5c [2];
  undefined1 local_54 [56];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00931408;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)local_5c;
  ExceptionList = &local_14;
  FUN_00755e50(DAT_00d61f20 ^ (uint)&stack0xffffff98);
  FUN_00458240(110000);
  FUN_00458240(210000);
  FUN_00458240(310000);
  FUN_00458240(410000);
  FUN_00458240(510000);
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
  local_5c[1] = 800;
  FUN_005740f0(local_5c + 1);
  if (local_5c[0] != DAT_00fe5ac8) {
    FUN_00757710();
    FUN_00757710();
    local_c = 0xffffffff;
    FUN_00757640(local_54);
    ExceptionList = local_14;
    __security_check_cookie(local_1c ^ (uint)local_5c);
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

