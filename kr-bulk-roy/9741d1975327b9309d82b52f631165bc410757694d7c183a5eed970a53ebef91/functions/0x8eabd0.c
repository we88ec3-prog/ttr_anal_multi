
int FUN_008eabd0(uint param_1,int param_2)

{
  uint uVar1;
  int in_EDX;
  
  uVar1 = 0;
  if (*(uint *)(in_EDX + 0x2c8) != 0) {
    do {
      if (*(byte *)(*(int *)(in_EDX + 0x2d0) + uVar1) == param_1) {
        if (*(uint *)(in_EDX + 0x2cc) <= param_2 + 2U) {
          return 0;
        }
        return param_2 + 2U + uVar1 * *(uint *)(in_EDX + 0x2cc) + *(int *)(in_EDX + 0x2c0) + 8;
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)(in_EDX + 0x2c8));
  }
  return 0;
}

