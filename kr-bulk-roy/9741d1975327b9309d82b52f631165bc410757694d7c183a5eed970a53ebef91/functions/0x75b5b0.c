
void FUN_0075b5b0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x44) != 0) {
                    /* WARNING: Could not recover jumptable at 0x0075b5c1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(in_ECX + 0x44) + 0xfc))();
    return;
  }
  return;
}

