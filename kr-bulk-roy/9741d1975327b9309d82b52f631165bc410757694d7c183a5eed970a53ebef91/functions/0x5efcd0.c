
void FUN_005efcd0(void)

{
  int iVar1;
  code *pcVar2;
  uint uVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined4 local_54;
  undefined4 local_44;
  uint local_40;
  undefined4 local_38;
  int local_34;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0092acae;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffff0000;
  local_8 = 0;
  local_14 = uVar3;
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = (uint)local_8._1_3_ << 8;
  }
  local_38 = 0x1a7;
  FUN_005740f0(&local_38);
  if (local_34 != DAT_00fe5ac8) {
    puVar4 = (undefined4 *)(local_34 + 0x10);
    if (7 < *(uint *)(local_34 + 0x24)) {
      puVar4 = (undefined4 *)*puVar4;
    }
    if (0 < *(int *)(*(int *)(in_ECX + 0x184) + 0x5c)) {
      FUN_005e2060(puVar4);
    }
    local_40 = 7;
    local_44 = 0;
    local_54 = (uint)local_54._2_2_ << 0x10;
    FUN_004026e0(local_30,0,0xffffffff);
    iVar1 = *(int *)(in_ECX + 0x194);
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_007578f0(uVar3);
    FUN_00759ed0(iVar1 + 0xe8,&local_54,0x7b,0x7d);
    if (7 < local_40) {
      FUN_0089120c(local_54);
    }
    *(undefined4 *)(*(int *)(in_ECX + 0x194) + 0x154) = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30[0]);
    }
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}

