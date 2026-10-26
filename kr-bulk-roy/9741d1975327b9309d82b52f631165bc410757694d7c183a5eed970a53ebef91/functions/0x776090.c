
void FUN_00776090(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
                    /* WARNING: Could not recover jumptable at 0x007760a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(in_ECX + 0xc) + 0x18))();
    return;
  }
  return;
}

