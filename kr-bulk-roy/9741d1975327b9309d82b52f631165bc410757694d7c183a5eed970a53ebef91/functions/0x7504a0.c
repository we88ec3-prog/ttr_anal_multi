
void FUN_007504a0(void)

{
  int *piVar1;
  bool bVar2;
  int in_EAX;
  int *piVar3;
  int *piVar4;
  
  piVar1 = *(int **)(in_EAX + 0x1420);
  piVar3 = (int *)*piVar1;
  bVar2 = false;
  if (piVar3 != piVar1) {
    do {
      if ((char)((int *)piVar3[2])[0x3c] == '\0') {
        piVar4 = (int *)*piVar3;
      }
      else {
        bVar2 = true;
        if (*(int *)(in_EAX + 0x13c4) != 0) {
          (**(code **)(*(int *)piVar3[2] + 0xd4))();
          (**(code **)(**(int **)(in_EAX + 0x13c4) + 0x74))(piVar3[2]);
        }
        if ((int *)piVar3[2] != (int *)0x0) {
          (**(code **)(*(int *)piVar3[2] + 0x1c))(1);
          piVar3[2] = 0;
        }
        piVar4 = (int *)*piVar3;
        if (piVar3 != *(int **)(in_EAX + 0x1420)) {
          *(int *)piVar3[1] = *piVar3;
          *(int *)(*piVar3 + 4) = piVar3[1];
          FUN_0089120c(piVar3);
          *(int *)(in_EAX + 0x1424) = *(int *)(in_EAX + 0x1424) + -1;
        }
      }
      piVar3 = piVar4;
    } while (piVar4 != piVar1);
    if (bVar2) {
      FUN_00750350();
    }
  }
  return;
}

