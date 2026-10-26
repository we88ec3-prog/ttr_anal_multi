
void FUN_0075b990(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x60) != 0) {
                    /* WARNING: Could not recover jumptable at 0x0075b9a1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(in_ECX + 0x60) + 0xfc))();
    return;
  }
  return;
}

