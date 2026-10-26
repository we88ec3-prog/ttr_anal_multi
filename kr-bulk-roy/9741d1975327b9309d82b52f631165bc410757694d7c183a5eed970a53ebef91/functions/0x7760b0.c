
void FUN_007760b0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
                    /* WARNING: Could not recover jumptable at 0x007760c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(in_ECX + 0xc) + 0x1c))();
    return;
  }
  return;
}

