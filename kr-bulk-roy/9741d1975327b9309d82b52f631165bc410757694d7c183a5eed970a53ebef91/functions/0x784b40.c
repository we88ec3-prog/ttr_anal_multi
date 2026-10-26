
void FUN_00784b40(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if ((uint)((*(int *)(in_ECX + 0x1c) - *(int *)(in_ECX + 0x18)) / 0x60) <= param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
  puVar1 = (undefined4 *)(param_1 * 0x60 + 4 + *(int *)(in_ECX + 0x18));
  if (puVar1 != &param_2) {
    puVar1[3] = param_5;
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1[2] = param_4;
  }
  return;
}

