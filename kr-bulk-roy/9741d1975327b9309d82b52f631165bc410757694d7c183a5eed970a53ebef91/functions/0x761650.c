
void FUN_00761650(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  undefined1 auStack_bc [4];
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a4;
  undefined1 local_a0 [120];
  undefined4 local_28;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0090ed9d;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_bc;
  ExceptionList = &local_14;
  FUN_00744640(param_1,param_2);
  local_b8 = *(int *)(*(int *)(in_ECX + 0x24) + 0x1c);
  if ((local_b8 != 0) && (*(int *)(in_ECX + 0xf4) != 0)) {
    local_ac = *(int *)(in_ECX + 0xa8) + param_2;
    local_a4 = *(int *)(in_ECX + 0xb0) + param_2;
    local_b0 = *(int *)(in_ECX + 0xa4) + param_1;
    param_1 = *(int *)(in_ECX + 0xac) + param_1;
    local_b4 = *(int *)(in_ECX + 0x118);
    if (local_b4 != 0) {
      FUN_007586b0(in_ECX + 0x108,*(undefined4 *)(in_ECX + 0x168),local_b4,4,
                   *(undefined4 *)(in_ECX + 0xf8),*(undefined4 *)(in_ECX + 0x100),local_b0,local_ac,
                   param_1,local_a4);
    }
    iVar3 = local_b0;
    if (*(int *)(in_ECX + 0x15c) != 0) {
      _eh_vector_constructor_iterator_
                (local_a0,0x14,6,(_func_void_void_ptr *)&LAB_0074d950,FUN_005f5d10);
      local_28 = 0;
      local_c = 0;
      iVar3 = *(int *)(in_ECX + 0x154) + iVar3;
      iVar1 = *(int *)(in_ECX + 0x158) + iVar3;
      if (iVar1 <= param_1) {
        param_1 = iVar1;
      }
      uVar2 = FUN_0077bc10(iVar3,local_ac,param_1,local_a4);
      FUN_0077bcf0(uVar2);
      local_c = 0xffffffff;
      FUN_0077bba0(local_a0);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_bc);
  return;
}

