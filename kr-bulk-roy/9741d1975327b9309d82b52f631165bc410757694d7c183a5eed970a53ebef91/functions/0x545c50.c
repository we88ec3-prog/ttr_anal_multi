
void FUN_00545c50(int param_1,undefined4 param_2,short param_3)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  uint *puVar4;
  undefined4 *puVar5;
  undefined4 local_4c [5];
  uint local_38;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092efee;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  if (param_3 == 0xf) {
    if (*(char *)(param_1 + 7) != '\0') {
      local_1c = 0xf;
      local_20 = 0;
      local_30[0] = local_30[0] & 0xffffff00;
      FUN_0040b310("CANNOT_USE_SKILL");
      local_8 = 0;
      if ((DAT_00fab0d4 & 1) == 0) {
        DAT_00fab0d4 = DAT_00fab0d4 | 1;
        local_8._0_1_ = 1;
        local_8._1_3_ = 0;
        FUN_0080a3a0();
        _atexit((_func_4879 *)&LAB_00bccdd0);
        local_8 = (uint)local_8._1_3_ << 8;
      }
      piVar2 = (int *)FUN_0080ab00(&DAT_00fab028);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0x14))();
      }
      local_8 = 0xffffffff;
      if (0xf < local_1c) {
        FUN_0089120c(local_30[0]);
      }
    }
    if (*(char *)(param_1 + 7) == '\x01') {
      if ((*(byte *)(param_1 + 8) & 1) != 0) {
        uVar3 = 0;
        FUN_005855b0(0,uVar1);
        uVar3 = FUN_00585330(uVar3);
        FUN_00402250(uVar3);
        puVar4 = local_30;
        local_8 = 2;
        FUN_0040f8c0(puVar4);
        FUN_004d6b30(puVar4);
        local_8 = 0xffffffff;
        if (7 < local_1c) {
          FUN_0089120c(local_30[0]);
        }
      }
      if ((*(byte *)(param_1 + 8) & 4) != 0) {
        uVar3 = 1;
        FUN_005855b0(1,uVar1);
        uVar3 = FUN_00585330(uVar3);
        FUN_00402250(uVar3);
        puVar4 = local_30;
        local_8 = 3;
        FUN_0040f8c0(puVar4);
        FUN_004d6b30(puVar4);
        local_8 = 0xffffffff;
        if (7 < local_1c) {
          FUN_0089120c(local_30[0]);
        }
      }
      if ((*(byte *)(param_1 + 8) & 2) != 0) {
        uVar3 = 2;
        FUN_005855b0(2,uVar1);
        uVar3 = FUN_00585330(uVar3);
        FUN_00402250(uVar3);
        puVar5 = local_4c;
        local_8 = 4;
        FUN_0040f8c0(puVar5);
        FUN_004d6b30(puVar5);
        if (7 < local_38) {
          FUN_0089120c(local_4c[0]);
        }
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

