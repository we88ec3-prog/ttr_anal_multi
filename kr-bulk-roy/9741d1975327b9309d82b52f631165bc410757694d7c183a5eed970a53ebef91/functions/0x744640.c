
void FUN_00744640(void)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = *(uint *)(in_ECX + 0x28);
  if ((((uVar1 >> 7 & 1) == 0) || (*(int *)(*(int *)(in_ECX + 0x24) + 0x13e8) != in_ECX)) &&
     ((uVar1 >> 9 & 1) == 0)) {
    if ((((uVar1 >> 7 & 1) == 0) || (*(int *)(*(int *)(in_ECX + 0x24) + 0x13cc) != in_ECX)) &&
       ((uVar1 >> 10 & 1) == 0)) {
      if ((((uVar1 >> 0xb & 1) != 0) && ((*(byte *)(in_ECX + 0x8c) & 0x10) != 0)) &&
         (*(int *)(in_ECX + 0xa0) != 0)) {
                    /* WARNING: Could not recover jumptable at 0x007446e7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(**(int **)(in_ECX + 0xa0) + 0x30))();
        return;
      }
    }
    else if (((*(byte *)(in_ECX + 0x8c) & 4) != 0) && (*(int *)(in_ECX + 0x98) != 0)) {
                    /* WARNING: Could not recover jumptable at 0x007446c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(**(int **)(in_ECX + 0x98) + 0x30))();
      return;
    }
  }
  else if (((*(byte *)(in_ECX + 0x8c) & 8) != 0) && (*(int *)(in_ECX + 0x9c) != 0)) {
                    /* WARNING: Could not recover jumptable at 0x00744687. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(in_ECX + 0x9c) + 0x30))();
    return;
  }
  if (((*(byte *)(in_ECX + 0x8c) & 2) != 0) && (*(int *)(in_ECX + 0x94) != 0)) {
                    /* WARNING: Could not recover jumptable at 0x00744707. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(in_ECX + 0x94) + 0x30))();
    return;
  }
  return;
}

