
void FUN_0047bb80(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 4);
  if (piVar1 != (int *)0x0) {
    LOCK();
    iVar2 = piVar1[1] + -1;
    piVar1[1] = iVar2;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)*piVar1)();
      LOCK();
      iVar2 = piVar1[2] + -1;
      piVar1[2] = iVar2;
      UNLOCK();
      if (iVar2 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0047bbb0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(*piVar1 + 4))();
        return;
      }
    }
  }
  return;
}

