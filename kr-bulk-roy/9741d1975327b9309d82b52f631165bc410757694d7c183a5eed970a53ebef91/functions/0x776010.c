
void FUN_00776010(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
                    /* WARNING: Could not recover jumptable at 0x00776022. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(in_ECX + 0xc) + 0xc))();
    return;
  }
  return;
}

