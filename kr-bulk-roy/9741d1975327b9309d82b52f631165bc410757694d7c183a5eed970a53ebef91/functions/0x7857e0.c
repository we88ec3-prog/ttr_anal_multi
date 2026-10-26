
void FUN_007857e0(uint param_1,undefined4 param_2)

{
  int in_ECX;
  
  if ((uint)((*(int *)(in_ECX + 0x1c) - *(int *)(in_ECX + 0x18)) / 0x2c) <= param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
  *(undefined4 *)(param_1 * 0x2c + 4 + *(int *)(in_ECX + 0x18)) = param_2;
  return;
}

