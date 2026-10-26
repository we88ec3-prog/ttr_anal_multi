
void FUN_00666440(int param_1)

{
  undefined4 *unaff_EDI;
  undefined1 auStack_50 [4];
  undefined4 local_4c;
  int local_48;
  int local_44;
  undefined1 local_40 [12];
  undefined4 local_34;
  int local_30;
  uint uStack_24;
  void *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093d2fe;
  local_14 = ExceptionList;
  local_1c = (void *)(DAT_00d61f20 ^ (uint)auStack_50);
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffa8);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  local_44 = DAT_00f93950 >> 0x1f;
  local_48 = DAT_00f93950;
  FUN_00897369(local_40,&local_48);
  local_4c = FUN_004eefb0(local_30 + 1,local_34);
  *(undefined4 *)(param_1 + 0x260) = *unaff_EDI;
  *(undefined4 *)(param_1 + 0x264) = unaff_EDI[1];
  FUN_00759ac0(0);
  FUN_00757800(unaff_EDI + 10);
  (**(code **)(**(int **)(param_1 + 0x254) + 0x94))(*(char *)(unaff_EDI + 9) == '\0');
  (**(code **)(**(int **)(param_1 + 600) + 0x94))(*(undefined1 *)(unaff_EDI + 9));
  FUN_004eefb0(*(undefined1 *)((int)unaff_EDI + 0x62),*(undefined1 *)((int)unaff_EDI + 99));
  FUN_007597b0(0);
  ExceptionList = local_1c;
  __security_check_cookie(uStack_24 ^ (uint)&stack0xffffffa8);
  return;
}

