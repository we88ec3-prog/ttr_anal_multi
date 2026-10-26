
void FUN_0075af80(void)

{
  int in_ECX;
  
  if ((*(char *)(in_ECX + 200) != '\0') && (*(int *)(in_ECX + 0x44) != 0)) {
                    /* WARNING: Could not recover jumptable at 0x0075af9e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(in_ECX + 0x44) + 0x15c))();
    return;
  }
  return;
}

