
void FUN_00581060(void)

{
  int *piVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0xc) != 0) &&
     (piVar1 = *(int **)(*(int *)(in_ECX + 0xc) + 4), piVar1 != (int *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00581075. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar1 + 8))();
    return;
  }
  return;
}

