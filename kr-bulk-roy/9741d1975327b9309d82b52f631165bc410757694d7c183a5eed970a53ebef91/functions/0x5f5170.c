
void FUN_005f5170(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(*(int *)(in_ECX + 0x104) + *(int *)(in_ECX + 0x118) * 4) + 0x19c))();
                    /* WARNING: Could not recover jumptable at 0x005f519b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xf8) + 200))();
  return;
}

