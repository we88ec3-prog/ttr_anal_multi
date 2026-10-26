
uint FUN_00857b00(int param_1,int param_2)

{
  int in_EAX;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  
  if (*(int *)(in_EAX + 0x10) == *(int *)(in_EAX + 0x14)) {
    return 0xffffffff;
  }
  uVar3 = *(int *)(in_EAX + 0x14) - *(int *)(in_EAX + 0x10) >> 4;
  uVar1 = 0;
  if (uVar3 != 0) {
    piVar6 = *(int **)(in_EAX + 0x10);
    do {
      uVar5 = 0;
      uVar2 = piVar6[1] - *piVar6 >> 3;
      if (uVar2 != 0) {
        piVar4 = (int *)*piVar6;
        do {
          if ((*piVar4 == param_1) && (piVar4[1] == param_2)) {
            return uVar1;
          }
          uVar5 = uVar5 + 1;
          piVar4 = piVar4 + 2;
        } while (uVar5 < uVar2);
      }
      uVar1 = uVar1 + 1;
      piVar6 = piVar6 + 4;
    } while (uVar1 < uVar3);
  }
  return 0xffffffff;
}

