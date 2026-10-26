
void FUN_00559f30(void)

{
  uint uVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  undefined4 ****ppppuVar4;
  uint local_64;
  int *local_60;
  uint local_58;
  int local_54;
  int local_50;
  uint local_4c [4];
  int local_3c;
  uint local_38;
  undefined4 ***local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092af4c;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (undefined4 ***)((uint)local_30[0] & 0xffff0000);
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = local_4c[0] & 0xffff0000;
  local_8 = 1;
  local_14 = uVar1;
  FUN_004d7fe0((undefined4 *)(in_ECX + 0x28),&local_54,*(undefined4 *)(in_ECX + 0x28),
               *(undefined4 *)(in_ECX + 0x2c));
  *(undefined4 *)(in_ECX + 0x38) = 0;
  FUN_004d8460(uVar1);
  FUN_00542210();
  for (; local_58 != local_64; local_58 = local_58 + 1) {
    if (local_60 == (int *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *local_60;
    }
    uVar1 = local_58;
    if (*(uint *)(iVar2 + 8) <= local_58) {
      uVar1 = local_58 - *(uint *)(iVar2 + 8);
    }
    FUN_004026e0(*(undefined4 *)(*(int *)(iVar2 + 4) + uVar1 * 4),0,0xffffffff);
    local_50 = 0;
    iVar2 = local_3c;
    if (0x16 < local_3c) {
      iVar3 = (local_3c - 0x17U) / 0x16 + 1;
      local_54 = local_3c + iVar3 * -0x16;
      do {
        FUN_004026e0(local_4c,local_50,0x16);
        ppppuVar4 = (undefined4 ****)local_30[0];
        if (local_1c < 8) {
          ppppuVar4 = local_30;
        }
        if ((DAT_00fb7bc8 & 1) == 0) {
          DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
          local_8._0_1_ = 2;
          FUN_00734ef0();
          _atexit((_func_4879 *)&LAB_00bcd4f0);
          local_8 = CONCAT31(local_8._1_3_,1);
        }
        iVar2 = (**(code **)(*DAT_00fb7b78 + 0x50))(DAT_00e4b338,ppppuVar4,0xffffffff);
        if (iVar2 < *(int *)(in_ECX + 0x38)) {
          iVar2 = *(int *)(in_ECX + 0x38);
        }
        *(int *)(in_ECX + 0x38) = iVar2;
        FUN_0049c120();
        local_50 = local_50 + 0x16;
        iVar3 = iVar3 + -1;
        iVar2 = local_54;
      } while (iVar3 != 0);
    }
    if (iVar2 != 0) {
      FUN_004026e0(local_4c,local_50,iVar2);
      ppppuVar4 = (undefined4 ****)local_30[0];
      if (local_1c < 8) {
        ppppuVar4 = local_30;
      }
      if ((DAT_00fb7bc8 & 1) == 0) {
        DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
        local_8._0_1_ = 3;
        FUN_00734ef0();
        _atexit((_func_4879 *)&LAB_00bcd4f0);
        local_8 = CONCAT31(local_8._1_3_,1);
      }
      iVar2 = (**(code **)(*DAT_00fb7b78 + 0x50))(DAT_00e4b338,ppppuVar4,0xffffffff);
      if (iVar2 < *(int *)(in_ECX + 0x38)) {
        iVar2 = *(int *)(in_ECX + 0x38);
      }
      *(int *)(in_ECX + 0x38) = iVar2;
      FUN_0049c120();
    }
  }
  if (7 < local_38) {
    FUN_0089120c(local_4c[0]);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = local_4c[0] & 0xffff0000;
  if (7 < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

