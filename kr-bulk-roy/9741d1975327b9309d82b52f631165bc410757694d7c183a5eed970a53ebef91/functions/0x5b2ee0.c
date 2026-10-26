
void FUN_005b2ee0(int param_1)

{
  int in_ECX;
  
  FUN_005b7f80(param_1);
  if ((*(int *)(param_1 + 0x10) == 0xf43b6) &&
     ((*(uint *)(*(int *)(in_ECX + 0x30c) + 0x28) >> 8 & 1) != 0)) {
    FUN_006a2ca0(*(int *)(in_ECX + 0x30c),*(undefined4 *)(param_1 + 0x14),
                 *(undefined4 *)(param_1 + 0x18));
  }
  return;
}

