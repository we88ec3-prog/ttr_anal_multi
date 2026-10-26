
void FUN_007a37a0(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *in_EAX;
  int *piVar3;
  
  if (in_EAX != param_1) {
    piVar3 = in_EAX + 1;
    do {
      piVar1 = (int *)*piVar3;
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
            (**(code **)(*piVar1 + 4))();
          }
        }
      }
      piVar1 = piVar3 + 1;
      piVar3 = piVar3 + 2;
    } while (piVar1 != param_1);
  }
  return;
}

