
void FUN_007c4de0(void)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  int iVar3;
  int iVar4;
  uint uStack_5c;
  undefined4 ***pppuStack_58;
  undefined4 ***apppuStack_54 [4];
  undefined4 uStack_44;
  uint uStack_40;
  undefined4 local_38 [5];
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009399ce;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&uStack_5c;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff98;
  ExceptionList = &local_14;
  iVar4 = 0;
  if ((*(int *)(in_ECX + 0x58) == 0) &&
     (((*(int *)(in_ECX + 0x4c) != 0 || (*(int *)(in_ECX + 0x14) != 0)) &&
      (0 < *(int *)(in_ECX + 0x5c))))) {
    FUN_007c5670(local_38);
    local_c = 0;
    FUN_007c4310(in_ECX);
    local_c = 0xffffffff;
    if (0xf < local_24) {
      FUN_0089120c(local_38[0],uVar2);
    }
    FUN_007c4040();
    FUN_007c3f40();
    FUN_007c4220(in_ECX);
    iVar3 = *(int *)(in_ECX + 200) - *(int *)(in_ECX + 0xc4);
    iVar1 = iVar3 >> 0x1f;
    uStack_5c = 0;
    if (iVar3 / 0x38 + iVar1 != iVar1) {
      do {
        uStack_40 = 0xf;
        uStack_44 = 0;
        apppuStack_54[0] = (undefined4 ***)((uint)apppuStack_54[0] & 0xffffff00);
        FUN_00403040(*(int *)(in_ECX + 0xc4) + iVar4,0,0xffffffff);
        local_c = 1;
        FUN_00401ed0(iVar4 + 0x1c + *(int *)(in_ECX + 0xc4),0,0xffffffff);
        if (uStack_40 < 0x10) {
          pppuStack_58 = apppuStack_54;
        }
        else {
          pppuStack_58 = apppuStack_54[0];
        }
        if ((DAT_00fe324c & 1) == 0) {
          DAT_00fe324c = DAT_00fe324c | 1;
          local_c._0_1_ = 2;
          FUN_007cdeb0();
          _atexit((_func_4879 *)&LAB_00bd09b0);
          local_c = CONCAT31(local_c._1_3_,1);
        }
        FUN_007ce2e0(&DAT_00fe3250,pppuStack_58);
        local_c = 0xffffffff;
        if (0xf < uStack_40) {
          FUN_0089120c(apppuStack_54[0]);
        }
        uStack_5c = uStack_5c + 1;
        iVar4 = iVar4 + 0x38;
      } while (uStack_5c < (uint)((*(int *)(in_ECX + 200) - *(int *)(in_ECX + 0xc4)) / 0x38));
    }
    *(undefined4 *)(in_ECX + 0x58) = 1;
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&uStack_5c);
  return;
}

