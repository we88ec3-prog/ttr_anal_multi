
void FUN_005b8b40(void)

{
  int *piVar1;
  int in_EAX;
  
  piVar1 = *(int **)(in_EAX + 0x244);
  if (((uint)piVar1[10] >> 8 & 1) == 0) {
    FUN_00596e00(in_EAX,piVar1);
  }
  else if (((uint)piVar1[10] >> 8 & 1) != 0) {
                    /* WARNING: Could not recover jumptable at 0x005b8b63. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar1 + 0xd4))();
    return;
  }
  return;
}

