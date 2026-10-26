
void FUN_00754430(void)

{
  int *in_ECX;
  int *piVar1;
  int iVar2;
  
  piVar1 = in_ECX + 0x25;
  iVar2 = 4;
  do {
    if (*piVar1 != 0) {
      (**(code **)(*(int *)*piVar1 + 0x48))();
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
                    /* WARNING: Could not recover jumptable at 0x00754461. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0x180))();
  return;
}

