
void FUN_00745a20(void)

{
  int *piVar1;
  int *in_ECX;
  
  piVar1 = (int *)in_ECX[0x18];
  if (in_ECX[0x11] != 0) {
    FUN_00749db0();
  }
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x74))();
  }
                    /* WARNING: Could not recover jumptable at 0x00745a4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0x30))();
  return;
}

