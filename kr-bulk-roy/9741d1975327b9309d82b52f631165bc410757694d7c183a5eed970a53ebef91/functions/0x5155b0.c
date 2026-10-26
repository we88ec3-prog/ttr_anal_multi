
undefined4 FUN_005155b0(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  int in_ECX;
  
  if (((in_ECX == 2) || (in_ECX == 0x28)) || (in_ECX == 0x2b)) {
    FUN_00515a30();
    if (((in_ECX != *(int *)(param_1 + 0x34)) &&
        (iVar1 = *(int *)(in_ECX + 0x10), param_3 < (uint)(*(int *)(in_ECX + 0x14) - iVar1 >> 4)))
       && (param_2 < (uint)(*(int *)(iVar1 + 4 + param_3 * 0x10) - *(int *)(iVar1 + param_3 * 0x10)
                           >> 2))) {
      return *(undefined4 *)(*(int *)(iVar1 + param_3 * 0x10) + param_2 * 4);
    }
  }
  return 0;
}

