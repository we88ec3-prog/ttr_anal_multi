
undefined4 FUN_00785760(uint param_1)

{
  int in_ECX;
  
  if ((uint)((*(int *)(in_ECX + 0x1c) - *(int *)(in_ECX + 0x18)) / 0x2c) <= param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
  return *(undefined4 *)(param_1 * 0x2c + 8 + *(int *)(in_ECX + 0x18));
}

