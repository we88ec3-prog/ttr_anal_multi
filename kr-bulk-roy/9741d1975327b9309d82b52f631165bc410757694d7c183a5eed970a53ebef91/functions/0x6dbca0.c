
void FUN_006dbca0(void)

{
  int *piVar1;
  int iVar2;
  int in_EAX;
  
  if (*(int *)(in_EAX + 0xb4) != 0) {
    FUN_0089120c(*(int *)(in_EAX + 0xb4));
  }
  *(undefined4 *)(in_EAX + 0xb4) = 0;
  *(undefined4 *)(in_EAX + 0xb8) = 0;
  *(undefined4 *)(in_EAX + 0xbc) = 0;
  piVar1 = *(int **)(in_EAX + 0x14);
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
                    /* WARNING: Could not recover jumptable at 0x006dbd03. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(*piVar1 + 4))();
        return;
      }
    }
  }
  return;
}

