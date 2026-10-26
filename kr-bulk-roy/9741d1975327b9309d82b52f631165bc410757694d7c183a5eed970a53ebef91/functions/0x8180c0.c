
void FUN_008180c0(void)

{
  char cVar1;
  int iVar2;
  undefined4 in_ECX;
  uint in_stack_00000018;
  uint local_68;
  undefined1 local_50 [20];
  uint local_3c;
  uint local_34;
  undefined4 local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_009262c3;
  local_10 = ExceptionList;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_0072ef00();
  local_8._0_1_ = 1;
  cVar1 = FUN_0072f110();
  if (cVar1 == '\0') {
    local_8 = (uint)local_8._1_3_ << 8;
    if (0xf < local_68) {
      FUN_0089120c();
    }
    FUN_0072e040();
    if (0xf < in_stack_00000018) {
      FUN_0089120c();
    }
  }
  else {
    iVar2 = FUN_0072e360();
    if (iVar2 == 0) {
      local_8 = (uint)local_8._1_3_ << 8;
      if (0xf < local_68) {
        FUN_0089120c();
      }
      FUN_0072e040();
      if (0xf < in_stack_00000018) {
        FUN_0089120c();
      }
    }
    else {
      iVar2 = FUN_0072e360();
      while (iVar2 != 0) {
        local_20 = 0xf;
        local_24 = 0;
        local_34 = local_34 & 0xffffff00;
        FUN_00402a70();
        local_8._0_1_ = 2;
        FUN_0072ecf0();
        local_8._0_1_ = 4;
        if (0xf < local_20) {
          FUN_0089120c();
        }
        local_20 = 0xf;
        local_24 = 0;
        local_34 = local_34 & 0xffffff00;
        FUN_00403040(local_50,0,0xffffffff);
        FUN_008180c0();
        iVar2 = FUN_0072e3c0();
        local_8._0_1_ = 1;
        if (0xf < local_3c) {
          FUN_0089120c();
        }
      }
      iVar2 = FUN_0072e360();
      while (iVar2 != 0) {
        local_20 = 0xf;
        local_24 = 0;
        local_34 = local_34 & 0xffffff00;
        FUN_00402a70();
        local_8._0_1_ = 5;
        FUN_0072ecf0();
        local_8._0_1_ = 7;
        if (0xf < local_20) {
          FUN_0089120c();
        }
        local_20 = 0xf;
        local_24 = 0;
        local_34 = local_34 & 0xffffff00;
        FUN_00403040(local_50,0,0xffffffff);
        FUN_00818430(in_ECX);
        iVar2 = FUN_0072e3c0();
        local_8._0_1_ = 1;
        if (0xf < local_3c) {
          FUN_0089120c();
        }
      }
      local_8 = (uint)local_8._1_3_ << 8;
      if (0xf < local_68) {
        FUN_0089120c();
      }
      FUN_0072e040();
      if (0xf < in_stack_00000018) {
        FUN_0089120c();
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

