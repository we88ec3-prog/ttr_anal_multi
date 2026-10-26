
void FUN_00430e90(void)

{
  int *piVar1;
  int *in_EAX;
  
  piVar1 = *(int **)(*(int *)(*(int *)*in_EAX + 4) + 0x38 + *in_EAX);
  if (piVar1 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00430ea6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar1 + 8))();
    return;
  }
  return;
}

