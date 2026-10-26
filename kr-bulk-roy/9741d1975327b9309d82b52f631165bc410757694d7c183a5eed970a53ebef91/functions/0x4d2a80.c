
void FUN_004d2a80(void)

{
  int iVar1;
  int in_ECX;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined1 auStack_5c [4];
  uint local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  int local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093a2a6;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_5c;
  ExceptionList = &local_14;
  local_48 = FUN_004c88f0(DAT_00d61f20 ^ (uint)&stack0xffffff98);
  if (*(int *)(in_ECX + 0x370) != 0) {
    if (*(int *)(in_ECX + 0x15c) == 0) {
      local_50 = *(undefined4 *)(in_ECX + 0xa4);
      uVar3 = *(undefined4 *)(in_ECX + 0xa0);
      local_4c = *(undefined4 *)(in_ECX + 0xa8);
    }
    else {
      FUN_007a8630(0x3f800000);
      uVar3 = local_54;
    }
    local_40 = 0;
    local_3c = 0xffffffec;
    if ((DAT_00fb75b0 & 1) == 0) {
      DAT_00fb75b0 = DAT_00fb75b0 | 1;
      local_c = 0;
      FUN_004f3d80();
      _atexit((_func_4879 *)&LAB_00bcd1e0);
      local_c = 0xffffffff;
    }
    local_58 = *(uint *)(in_ECX + 0x88);
    iVar1 = FUN_004f7a70();
    if (*(uint *)(iVar1 + 0x30) < 8) {
      iVar1 = iVar1 + 0x1c;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0x1c);
    }
    FUN_004c9b60(iVar1,uVar3,local_50,local_4c,0xff00ffaa,0xff000000,0);
    iVar1 = DAT_00fe1bd0;
    local_24 = 7;
    local_28 = 0;
    local_38 = (undefined4 *)((uint)local_38._2_2_ << 0x10);
    local_c = 1;
    local_58 = (uint)*(ushort *)(in_ECX + 0x88);
    FUN_008438c0(&local_58);
    if ((local_44 != *(int *)(iVar1 + 0xc)) && (*(int *)(local_44 + 0x10) != 0)) {
      FUN_004026e0(*(int *)(local_44 + 0x10) + 0x24,0,0xffffffff);
      if (local_28 != 0) {
        puVar2 = local_38;
        if (local_24 < 8) {
          puVar2 = &local_38;
        }
        FUN_004c9b60(puVar2,uVar3,local_50,local_4c,0xffaaffff,0xff000000,&local_40);
      }
    }
    local_c = 0xffffffff;
    if (7 < local_24) {
      FUN_0089120c(local_38);
    }
    local_24 = 7;
    local_28 = 0;
    local_38 = (undefined4 *)((uint)local_38 & 0xffff0000);
  }
  if ((*(int *)(in_ECX + 0x420) != 0) &&
     (iVar1 = *(int *)(*(int *)(in_ECX + 0x420) + 0x24), iVar1 != 0)) {
    FUN_007bdf40(iVar1);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_5c);
  return;
}

