
void FUN_00775540(void)

{
  int *piVar1;
  int *piVar2;
  int in_EAX;
  
  if (*(int *)(in_EAX + 0x74) != 0) {
    piVar2 = *(int **)(in_EAX + 0x7c);
    piVar1 = (int *)(in_EAX + 0x7c);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *piVar1 = 0;
    }
    (**(code **)(**(int **)(in_EAX + 0x74) + 0x5c))
              (*(int **)(in_EAX + 0x74),9,1,1,0,0x15,1,piVar1,0);
    if (*piVar1 != 0) {
      switch(*(undefined4 *)(in_EAX + 0x80)) {
      case 0:
        FUN_007755d0();
        break;
      case 1:
        FUN_00775630();
        return;
      case 2:
        FUN_00775690();
        return;
      case 3:
        FUN_007756f0();
        return;
      }
    }
  }
  return;
}

