
void FUN_007fc360(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x34) != 0) {
                    /* WARNING: Could not recover jumptable at 0x007fc36e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(in_ECX + 0x34) + 8))();
    return;
  }
  return;
}

