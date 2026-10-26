
void FUN_007445a0(void)

{
  int in_ECX;
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(in_ECX + 0x94);
  iVar2 = 4;
  do {
    if (*piVar1 != 0) {
      (**(code **)(*(int *)*piVar1 + 0x48))();
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

