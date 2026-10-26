
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00659770(undefined2 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int in_EDX;
  undefined4 uVar1;
  uint in_stack_00000024;
  undefined4 in_stack_0000002c;
  undefined4 **local_68 [5];
  uint local_54;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0091d1b0;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  uStack_7 = 0;
  FUN_00835c70();
  if (*(int *)(in_EDX + 0x14c) != 0) {
    FUN_005366c0();
    if (_DAT_00000014 != 0) {
      local_1c = 7;
      local_20 = 0;
      local_30 = local_30 & 0xffff0000;
      local_8 = 1;
      if (DAT_0000002c == '\0') {
        if (cRam0000002d == '\0') {
          FUN_004026e0();
        }
        else {
          FUN_0040e460();
          local_8 = 7;
          FUN_005f2840();
          local_8 = 8;
          FUN_00402800();
          FUN_004fa440();
          local_8 = 1;
          FUN_004fa440();
        }
      }
      else if (cRam0000002d == '\0') {
        FUN_00402110(&param_4);
        uVar1 = 0x10;
        if (7 < uRam00000024) {
          uVar1 = uRam00000010;
        }
        FUN_00424c80(uVar1);
        local_8 = 6;
        FUN_00402800();
        local_8 = 1;
        FUN_004fa440();
      }
      else {
        FUN_0040e460();
        local_8 = 2;
        FUN_005f2840();
        local_8 = 4;
        FUN_004fa440();
        FUN_00402110(&param_4);
        if (local_54 < 8) {
          local_68[0] = local_68;
        }
        FUN_00424c80(local_68[0]);
        local_8 = 5;
        FUN_00402800();
        FUN_004fa440();
        local_8 = 1;
        FUN_004fa440();
      }
      *(undefined4 *)(param_1 + 10) = 7;
      *(undefined4 *)(param_1 + 8) = 0;
      *param_1 = 0;
      FUN_00402800();
      if (7 < local_1c) {
        FUN_0089120c();
      }
      local_1c = 7;
      local_20 = 0;
      local_30 = local_30 & 0xffff0000;
      goto LAB_006599bd;
    }
  }
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
LAB_006599bd:
  if (7 < in_stack_00000024) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

