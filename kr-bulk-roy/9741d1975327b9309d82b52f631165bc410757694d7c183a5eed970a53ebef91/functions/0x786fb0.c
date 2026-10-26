
void FUN_00786fb0(int param_1)

{
  int in_ECX;
  uint local_10;
  int local_c;
  
  if (param_1 != in_ECX) {
    *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(param_1 + 0x10);
    local_c = (*(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14)) / 0x18;
    if (0 < local_c) {
      do {
        FUN_00789120();
        local_10 = local_10 & 0xffffff00;
        FUN_0078a6b0(*(int *)(in_ECX + 0x14),*(int *)(in_ECX + 0x18),
                     (*(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14)) / 0x18,local_10);
        local_c = local_c + -1;
      } while (local_c != 0);
    }
  }
  return;
}

