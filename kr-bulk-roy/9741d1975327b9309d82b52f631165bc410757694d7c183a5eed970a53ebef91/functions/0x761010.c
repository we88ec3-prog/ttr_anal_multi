
int FUN_00761010(void)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int in_EAX;
  
  if (*(int *)(in_EAX + 0x68) != 0) {
    piVar1 = *(int **)(in_EAX + 100);
    piVar2 = (int *)*piVar1;
    while (piVar1 != piVar2) {
      piVar1 = (int *)piVar1[1];
      uVar3 = *(uint *)(piVar1[2] + 0x28);
      if ((((uVar3 >> 0x13 & 1) == 0) && ((uVar3 >> 8 & 1) != 0)) && ((uVar3 >> 0xc & 1) == 0)) {
        return piVar1[2];
      }
    }
  }
  return 0;
}

