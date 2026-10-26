
void FUN_0059a3a0(void)

{
  int *piVar1;
  int in_EAX;
  
  piVar1 = *(int **)(in_EAX + 0x170);
  if (((uint)piVar1[10] >> 8 & 1) == 0) {
    FUN_00596e00(in_EAX,piVar1);
  }
  else if (((uint)piVar1[10] >> 8 & 1) != 0) {
                    /* WARNING: Could not recover jumptable at 0x0059a3c3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar1 + 0xd4))();
    return;
  }
  return;
}

