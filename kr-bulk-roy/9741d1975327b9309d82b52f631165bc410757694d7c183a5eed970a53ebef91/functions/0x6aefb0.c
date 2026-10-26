
void FUN_006aefb0(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *local_58;
  undefined4 local_54;
  uint local_40;
  undefined4 uStack_38;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00935944;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_58;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffa0;
  ExceptionList = &local_14;
  if (in_ECX == 0) {
    FUN_00757710(uVar1);
    FUN_00757710();
    FUN_00757710();
    FUN_00757710();
  }
  else {
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 0;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
    }
    uVar4 = 0;
    uVar2 = *(int *)(DAT_00fab130 + 0x5f00) - *(int *)(DAT_00fab130 + 0x5efc) >> 2;
    if (uVar2 != 0) {
      local_58 = *(undefined4 **)(DAT_00fab130 + 0x5efc);
      puVar5 = local_58;
      do {
        if (*(int *)*puVar5 == in_ECX) break;
        uVar4 = uVar4 + 1;
        puVar5 = puVar5 + 1;
      } while (uVar4 < uVar2);
    }
    if ((DAT_00fb75b0 & 1) == 0) {
      DAT_00fb75b0 = DAT_00fb75b0 | 1;
      local_c = 1;
      FUN_004f3d80();
      _atexit((_func_4879 *)&LAB_00bcd1e0);
    }
    local_c = 0xffffffff;
    FUN_004f6a30(in_ECX);
    FUN_00757710(uVar1);
    uVar3 = FUN_00665560();
    local_c = 2;
    FUN_00757800(uVar3);
    local_c = 0xffffffff;
    if (7 < local_40) {
      FUN_0089120c(local_54);
    }
    uVar3 = FUN_00665560();
    local_c = 3;
    FUN_00757800(uVar3);
    local_c = 0xffffffff;
    if (7 < local_40) {
      FUN_0089120c(local_54);
    }
    uVar3 = FUN_00665560();
    local_c = 4;
    FUN_00757800(uVar3);
    if (7 < uStack_24) {
      FUN_0089120c(uStack_38);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_58);
  return;
}

