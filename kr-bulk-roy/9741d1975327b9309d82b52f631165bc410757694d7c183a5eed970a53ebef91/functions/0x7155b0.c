
int FUN_007155b0(void)

{
  int *in_EAX;
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(**(code **)(*in_EAX + 4))();
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0xc))();
    if (iVar2 == 0) {
      iVar2 = *(int *)(in_EAX[0x4e] + 0x2c);
      if (iVar2 != 0) {
        do {
          if (piVar1[0x47] == *(int *)(iVar2 + 0x44)) {
            if (*(int *)(iVar2 + 8) == 0) {
              FUN_007186a0();
            }
            return iVar2;
          }
          iVar2 = *(int *)(iVar2 + 0x28);
        } while (iVar2 != 0);
      }
      return 0;
    }
  }
  return 0;
}

