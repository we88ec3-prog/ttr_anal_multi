
void FUN_00604660(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  undefined1 auStack_44 [4];
  int local_40;
  int local_3c;
  uint local_38;
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00943404;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_44;
  ExceptionList = &local_14;
  if ((*(uint *)(in_ECX + 0x28) >> 8 & 1) != 0) {
    local_40 = in_ECX;
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffb0);
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    iVar1 = DAT_00f94244;
    local_c = 0xffffffff;
    iVar2 = FUN_0068ace0();
    if (iVar1 < iVar2) {
      local_3c = iVar1;
      FUN_0040ef80();
      local_c = 1;
      iVar1 = *(int *)(local_40 + 0x18c);
      if (*(char *)(iVar1 + 0x141) == '\0') {
        FUN_00757710();
      }
      else {
        FUN_006edb10("Not supported operation");
      }
      *(undefined4 *)(iVar1 + 0x168) = 0;
      *(undefined4 *)(iVar1 + 0x160) = 0;
      *(undefined4 *)(iVar1 + 0x164) = 0;
      *(undefined4 *)(iVar1 + 0x14c) = 0;
      local_c = 0xffffffff;
      if (7 < local_24) {
        FUN_0089120c(local_38);
      }
      local_38 = local_38 & 0xffff0000;
      local_24 = 7;
      local_28 = 0;
      (**(code **)(**(int **)(local_40 + 0x18c) + 200))();
      iVar2 = local_3c;
    }
    if ((DAT_00fc1cbc & 1) == 0) {
      DAT_00fc1cbc = DAT_00fc1cbc | 1;
      local_c = 2;
      FUN_004fdac0();
      _atexit(FUN_00bce150);
      local_c = 0xffffffff;
    }
    FUN_004ff480(iVar2);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_44);
  return;
}

