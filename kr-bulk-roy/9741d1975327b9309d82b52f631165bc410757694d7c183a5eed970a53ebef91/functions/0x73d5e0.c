
void FUN_0073d5e0(void)

{
  int iVar1;
  int in_ECX;
  float10 fVar2;
  undefined1 auStack_f8 [48];
  float local_c8;
  undefined4 local_c4;
  uint local_c0;
  undefined4 local_b0;
  uint local_ac;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined1 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  uint local_84;
  void *local_4c;
  undefined1 *puStack_48;
  undefined4 local_44;
  
  local_44 = 0xffffffff;
  puStack_48 = &LAB_00920ba8;
  local_4c = ExceptionList;
  local_84 = DAT_00d61f20 ^ (uint)auStack_f8;
  ExceptionList = &local_4c;
  if (in_ECX == 0) {
    local_c4 = 0;
    FUN_008438c0();
  }
  else {
    local_ac = 0xf;
    local_b0 = 0;
    local_c0 = local_c0 & 0xffffff00;
    local_a4 = 0;
    local_a0 = 0;
    local_9c = 0;
    local_98 = 0;
    local_94 = 0;
    local_90 = 0;
    local_8c = 0;
    local_88 = 0;
    local_44 = 0;
    FUN_00402a70("Gulim",5);
    local_c8 = (float)*(int *)(*(int *)(in_ECX + 8) + 0x5c) * 0.015625;
    fVar2 = (float10)FUN_00892d30((double)local_c8);
    local_c8 = (float)fVar2;
    local_a4 = FUN_008fed10();
    local_c8 = (float)*(int *)(*(int *)(in_ECX + 8) + 0x60) * 0.015625;
    fVar2 = (float10)FUN_00892d30((double)local_c8);
    local_c8 = (float)fVar2;
    local_a0 = FUN_008fed10();
    local_8c = *(undefined4 *)(in_ECX + 0x14);
    iVar1 = FUN_0073d360();
    if (iVar1 == 0) {
      local_c8 = (float)FUN_0073d530();
      FUN_008438c0();
    }
    if (0xf < local_ac) {
      FUN_0089120c();
    }
  }
  ExceptionList = local_4c;
  __security_check_cookie(local_84 ^ (uint)auStack_f8);
  return;
}

