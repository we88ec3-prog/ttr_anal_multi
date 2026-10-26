
void FUN_0059c430(void)

{
  int *piVar1;
  int in_EAX;
  
  piVar1 = *(int **)(in_EAX + 0x1a4);
  if (((uint)piVar1[10] >> 8 & 1) == 0) {
    FUN_00596e00(in_EAX,piVar1);
  }
  else if (((uint)piVar1[10] >> 8 & 1) != 0) {
                    /* WARNING: Could not recover jumptable at 0x0059c453. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar1 + 0xd4))();
    return;
  }
  return;
}

