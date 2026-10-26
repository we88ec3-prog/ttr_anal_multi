
void FUN_007c5be0(void)

{
  uint uVar1;
  int in_ECX;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 ***local_54;
  undefined4 local_4c [5];
  uint local_38;
  undefined4 ***local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093997e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar3 = 0;
  local_14 = uVar1;
  if ((*(int *)(in_ECX + 0x5c) != 0) && (*(char *)(in_ECX + 0x60) == '\0')) {
    FUN_007c5670(local_4c);
    local_8 = 0;
    FUN_007c4310(in_ECX);
    local_8 = 0xffffffff;
    if (0xf < local_38) {
      FUN_0089120c(local_4c[0]);
    }
    FUN_007c3f40();
    iVar2 = *(int *)(in_ECX + 200) - *(int *)(in_ECX + 0xc4);
    iVar4 = iVar2 >> 0x1f;
    if (iVar2 / 0x38 + iVar4 != iVar4) {
      iVar4 = 0;
      do {
        local_1c = 0xf;
        local_20 = 0;
        local_30[0] = (undefined4 ***)((uint)local_30[0] & 0xffffff00);
        FUN_00403040(*(int *)(in_ECX + 0xc4) + iVar4,0,0xffffffff);
        local_8 = 1;
        FUN_00401ed0(iVar4 + 0x1c + *(int *)(in_ECX + 0xc4),0,0xffffffff);
        if (local_1c < 0x10) {
          local_54 = local_30;
        }
        else {
          local_54 = local_30[0];
        }
        if ((DAT_00fe324c & 1) == 0) {
          DAT_00fe324c = DAT_00fe324c | 1;
          local_8._0_1_ = 2;
          FUN_007cdeb0();
          _atexit((_func_4879 *)&LAB_00bd09b0);
          local_8 = CONCAT31(local_8._1_3_,1);
        }
        FUN_007ce2e0(&DAT_00fe3250,local_54);
        local_8 = 0xffffffff;
        if (0xf < local_1c) {
          FUN_0089120c(local_30[0]);
        }
        uVar3 = uVar3 + 1;
        iVar4 = iVar4 + 0x38;
        local_1c = 0xf;
        local_20 = 0;
        local_30[0] = (undefined4 ***)((uint)local_30[0] & 0xffffff00);
      } while (uVar3 < (uint)((*(int *)(in_ECX + 200) - *(int *)(in_ECX + 0xc4)) / 0x38));
    }
    *(undefined4 *)(in_ECX + 0x58) = 1;
  }
  FUN_007c4040(uVar1);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

