
void FUN_0075d470(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *in_ECX;
  int iVar6;
  
  FUN_0082ef00(&stack0x00000008);
  if (in_ECX != *(int **)(param_1 + 4)) {
    uVar2 = *(undefined4 *)(in_ECX[4] + 0xc);
    iVar6 = *(int *)(in_ECX[4] + 8);
    do {
      if ((*(uint *)(in_ECX[4] + 0x28) >> 8 & 1) != 0) {
        FUN_00749a00(iVar6,uVar2);
        iVar3 = ((int *)in_ECX[4])[7];
        if (iVar3 != 0) {
          (**(code **)(*(int *)in_ECX[4] + 0xb4))(*(undefined4 *)(iVar3 + 8));
        }
        iVar6 = iVar6 + ((*(int *)(in_ECX[4] + 0x10) + *(int *)(param_1 + 0x14)) -
                        *(int *)(in_ECX[4] + 8));
      }
      if (*(char *)((int)in_ECX + 0x15) == '\0') {
        piVar4 = (int *)in_ECX[2];
        if (*(char *)((int)piVar4 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar4 + 0x15);
          in_ECX = piVar4;
          piVar4 = (int *)*piVar4;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar4 + 0x15);
            in_ECX = piVar4;
            piVar4 = (int *)*piVar4;
          }
        }
        else {
          cVar1 = *(char *)(in_ECX[1] + 0x15);
          piVar5 = (int *)in_ECX[1];
          piVar4 = in_ECX;
          while ((in_ECX = piVar5, cVar1 == '\0' && (piVar4 == (int *)in_ECX[2]))) {
            cVar1 = *(char *)(in_ECX[1] + 0x15);
            piVar5 = (int *)in_ECX[1];
            piVar4 = in_ECX;
          }
        }
      }
    } while (in_ECX != *(int **)(param_1 + 4));
  }
  return;
}

