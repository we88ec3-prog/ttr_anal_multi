
void FUN_005dd480(void)

{
  int in_ECX;
  uint uStack_14;
  uint local_c [2];
  
  local_c[0] = DAT_00d61f20 ^ (uint)local_c;
  uStack_14 = 0;
  FUN_005d7240(0xffffffff,0xffffffff,0);
  uStack_14 = 0;
  (**(code **)(**(int **)(in_ECX + 0x298) + 0x94))();
  *(undefined4 *)(in_ECX + 0x2b4) = 0;
  FUN_005dd050(0,0);
  (**(code **)(**(int **)(in_ECX + 0x2a4) + 0x94))(1);
  *(undefined1 *)(in_ECX + 0x2a1) = 1;
  if ((*(uint *)(in_ECX + 0x28) & 8) != 0) {
    *(uint *)(in_ECX + 0x28) = *(uint *)(in_ECX + 0x28) ^ 8;
  }
  __security_check_cookie(uStack_14 ^ (uint)&uStack_14);
  return;
}

