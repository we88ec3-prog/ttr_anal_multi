
void FUN_0053aaa0(undefined2 param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int *in_EDX;
  undefined4 uVar5;
  uint *puVar6;
  undefined4 local_68 [5];
  uint local_54;
  uint local_4c;
  uint local_38;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093ff60;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  iVar2 = FUN_0053a9d0(param_1);
  if ((iVar2 != 0) && (*(char *)((int)in_EDX + 6) == '\0')) {
    iVar3 = FUN_00404ba0(uVar1);
    iVar2 = *in_EDX;
    if (iVar2 == *(int *)(iVar3 + 0x5f50)) {
      uVar5 = 0x1c;
      FUN_005855b0(0x1c);
      uVar5 = FUN_00585330(uVar5);
      FUN_00402250(uVar5);
      puVar6 = local_30;
      local_8 = 0;
      FUN_0040f8c0(puVar6);
      FUN_004d6b30(puVar6);
      local_4c = local_30[0];
      local_38 = local_1c;
    }
    else {
      FUN_00425330(iVar2);
      FUN_004f6a30(iVar2);
      uVar5 = 0x1d;
      FUN_005855b0(0x1d);
      FUN_00585330(uVar5);
      puVar4 = (undefined4 *)FUN_004ed610();
      local_8 = 1;
      if (7 < (uint)puVar4[5]) {
        puVar4 = (undefined4 *)*puVar4;
      }
      FUN_00402250(puVar4);
      puVar6 = local_30;
      local_8 = CONCAT31(local_8._1_3_,2);
      FUN_0040f8c0(puVar6);
      FUN_004d6b30(puVar6);
      if (7 < local_1c) {
        FUN_0089120c(local_30[0]);
      }
      local_8 = 0xffffffff;
      local_1c = 7;
      local_20 = 0;
      local_30[0] = local_30[0] & 0xffff0000;
      if (7 < local_38) {
        FUN_0089120c(local_4c);
      }
      FUN_00539a70();
      uVar5 = 0x1e;
      FUN_005855b0(0x1e);
      FUN_00585330(uVar5);
      puVar4 = (undefined4 *)FUN_00420070();
      local_8 = 3;
      if (7 < (uint)puVar4[5]) {
        puVar4 = (undefined4 *)*puVar4;
      }
      FUN_00402250(puVar4);
      puVar6 = local_30;
      local_8 = CONCAT31(local_8._1_3_,4);
      FUN_0040f8c0(puVar6);
      FUN_004d6b30(puVar6);
      if (7 < local_1c) {
        FUN_0089120c(local_30[0]);
      }
      local_1c = 7;
      local_20 = 0;
      local_30[0] = local_30[0] & 0xffff0000;
    }
    local_8 = 0xffffffff;
    if (7 < local_38) {
      local_8 = 0xffffffff;
      FUN_0089120c(local_4c);
    }
    iVar2 = FUN_00404ba0();
    if (*(int *)(iVar2 + 0x5f4c) == 3) {
      uVar5 = 10;
      FUN_005855b0(10);
      uVar5 = FUN_00585330(uVar5);
      FUN_00402250(uVar5);
      puVar4 = local_68;
      local_8 = 5;
      FUN_0040f8c0(puVar4);
      FUN_004d6b30(puVar4);
      if (7 < local_54) {
        FUN_0089120c(local_68[0]);
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

