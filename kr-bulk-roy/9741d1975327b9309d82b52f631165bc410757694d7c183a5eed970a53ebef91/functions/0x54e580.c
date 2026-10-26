
void FUN_0054e580(void)

{
  code *pcVar1;
  int *in_ECX;
  int local_5c;
  int local_58;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093af26;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (in_ECX[0xe] == 0) {
    if ((DAT_00fb73b8 & 1) == 0) {
      DAT_00fb73b8 = DAT_00fb73b8 | 1;
      local_c = 0;
      FUN_00560170(DAT_00d61f20 ^ (uint)&stack0xffffff98);
      _atexit((_func_4879 *)&LAB_00bcd110);
    }
    local_c = 0xffffffff;
    local_5c = in_ECX[1];
    FUN_0082ef00(&local_5c);
    if ((local_58 != DAT_00fb73dc) && (*(int *)(local_58 + 0x10) != 0)) {
      FUN_0049c3d0();
      local_c = 1;
      if (local_58 != 0) {
        local_44 = 0;
        local_40 = 0;
        local_3c = 0;
        local_38 = 0;
        local_34 = 0;
        local_30 = 0;
        local_2c = 0x3f800000;
        local_28 = 0x3f800000;
        local_24 = 0x3f800000;
        local_20 = 0x3f800000;
        local_1c = 1;
        if (*(int *)(local_58 + 0x1c) != 0) {
          FUN_007d3340();
        }
        FUN_007cc3a0(&local_48,&local_50,&local_4c);
        in_ECX[3] = local_44;
        in_ECX[4] = local_40;
        in_ECX[5] = local_3c;
        in_ECX[6] = local_50;
        in_ECX[10] = 0;
        in_ECX[9] = 0;
        in_ECX[7] = local_4c;
        pcVar1 = *(code **)(*in_ECX + 4);
        in_ECX[8] = local_48;
        in_ECX[0xb] = 0x40a00000;
        in_ECX[0xd] = 0x3f490fdb;
        (*pcVar1)();
      }
      local_c = 0xffffffff;
      FUN_007a1050();
    }
  }
  ExceptionList = local_14;
  return;
}

