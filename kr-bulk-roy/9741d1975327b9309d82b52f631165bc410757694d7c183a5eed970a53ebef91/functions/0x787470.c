
void FUN_00787470(int param_1)

{
  int in_ECX;
  uint local_10;
  int local_c;
  
  if (param_1 != in_ECX) {
    *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(param_1 + 0x10);
    *(undefined1 *)(in_ECX + 0x14) = *(undefined1 *)(param_1 + 0x14);
    local_c = (*(int *)(param_1 + 0x1c) - *(int *)(param_1 + 0x18)) / 0x44;
    if (0 < local_c) {
      do {
        FUN_00789250();
        local_10 = local_10 & 0xffffff00;
        FUN_0078a930(*(int *)(in_ECX + 0x18),*(int *)(in_ECX + 0x1c),
                     (*(int *)(in_ECX + 0x1c) - *(int *)(in_ECX + 0x18)) / 0x44,local_10);
        local_c = local_c + -1;
      } while (local_c != 0);
    }
  }
  return;
}

