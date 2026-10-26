
void FUN_00458dd0(void)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  int *piVar3;
  int iVar4;
  
  in_ECX[0x37] = 0;
  piVar3 = in_ECX + 0x20;
  iVar4 = 9;
  do {
    (**(code **)(*(int *)*piVar3 + 0x94))(0);
    piVar3 = piVar3 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  piVar3 = in_ECX + 0x34;
  iVar4 = 3;
  do {
    (**(code **)(*(int *)*piVar3 + 0x94))(0);
    (**(code **)(*(int *)*piVar3 + 200))();
    piVar3 = piVar3 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  (**(code **)(*(int *)in_ECX[0x29] + 0x94))(1);
  iVar4 = in_ECX[0x29];
  if ((*(char *)(iVar4 + 0xa4) != '\0') && (*(int *)(iVar4 + 0x94) != 0)) {
    iVar2 = (**(code **)(**(int **)(iVar4 + 0x94) + 4))();
    if (iVar2 == 0xbf6b) {
      iVar4 = *(int *)(iVar4 + 0x94);
      iVar2 = *(int *)(iVar4 + 0x10);
      if (iVar2 != 0) {
        piVar3 = *(int **)(iVar2 + 8);
        if (piVar3 != (int *)0x0) {
          piVar1 = piVar3 + 0x27;
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            (**(code **)(*piVar3 + 0x28))();
          }
        }
        *(undefined4 *)(iVar4 + 0x10) = 0;
      }
    }
  }
  (**(code **)(*(int *)in_ECX[0x29] + 200))();
  (**(code **)(*in_ECX + 0x94))(1);
  return;
}

