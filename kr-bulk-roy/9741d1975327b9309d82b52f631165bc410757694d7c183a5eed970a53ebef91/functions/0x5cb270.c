
uint FUN_005cb270(void)

{
  uint in_EAX;
  uint uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x24) != 0) {
                    /* WARNING: Could not recover jumptable at 0x005cb27e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(**(int **)(in_ECX + 0x24) + 0x2c))();
    return uVar1;
  }
  return in_EAX & 0xffffff00;
}

