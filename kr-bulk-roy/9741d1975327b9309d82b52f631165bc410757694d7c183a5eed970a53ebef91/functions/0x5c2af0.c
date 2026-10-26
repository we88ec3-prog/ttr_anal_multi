
void FUN_005c2af0(void)

{
  int in_ECX;
  
  FUN_005b87b0();
  if (((uint)(*(int **)(in_ECX + 0x2f8))[10] >> 8 & 1) != 0) {
                    /* WARNING: Could not recover jumptable at 0x005c2b14. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(in_ECX + 0x2f8) + 0x16c))();
    return;
  }
  return;
}

