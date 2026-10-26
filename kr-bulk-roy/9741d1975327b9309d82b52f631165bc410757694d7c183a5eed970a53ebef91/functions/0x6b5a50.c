
void FUN_006b5a50(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  int *local_6c;
  uint local_68 [4];
  undefined4 local_58;
  uint local_54;
  uint local_4c [4];
  undefined4 local_3c;
  uint local_38;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00919cf8;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar3 = 0;
  local_6c = (int *)(in_ECX + 0x144);
  local_14 = uVar2;
  do {
    iVar1 = local_6c[-0x14];
    iVar3 = iVar3 + 1;
    FUN_0040ef80(uVar2);
    local_8 = 0;
    FUN_00759d70(local_68);
    local_38 = 7;
    local_3c = 0;
    local_4c[0] = local_4c[0] & 0xffff0000;
    FUN_00402160(&DAT_00bfb894,1);
    local_8._0_1_ = 1;
    local_30[0] = local_30[0] & 0xffff0000;
    local_1c = 7;
    local_20 = 0;
    FUN_00402160(&DAT_00c059b8,2);
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_00759330(iVar1 + 0xe8,local_30,local_4c);
    if (7 < local_1c) {
      FUN_0089120c(local_30[0]);
    }
    local_1c = 7;
    local_20 = 0;
    local_30[0] = local_30[0] & 0xffff0000;
    if (7 < local_38) {
      FUN_0089120c(local_4c[0]);
    }
    local_8 = 0xffffffff;
    local_38 = 7;
    local_3c = 0;
    local_4c[0] = local_4c[0] & 0xffff0000;
    if (7 < local_54) {
      FUN_0089120c(local_68[0]);
    }
    local_58 = 0;
    iVar1 = *local_6c;
    local_68[0] = local_68[0] & 0xffff0000;
    local_54 = 7;
    FUN_007444b0(0xbf6b);
    local_6c = local_6c + 1;
    *(undefined1 *)(iVar1 + 0xa4) = 1;
  } while (iVar3 < 10);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

