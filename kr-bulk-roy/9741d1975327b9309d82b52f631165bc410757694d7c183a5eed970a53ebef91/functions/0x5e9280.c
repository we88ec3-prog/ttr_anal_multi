
void FUN_005e9280(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x15c) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x15c) + 0xb0))();
  }
  if (*(int *)(in_ECX + 0x160) != 0) {
                    /* WARNING: Could not recover jumptable at 0x005e92b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(in_ECX + 0x160) + 0xb0))();
    return;
  }
  return;
}

