
void FUN_0074ef40(void)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int in_ECX;
  uint uVar4;
  int iVar5;
  
  iVar5 = *(int *)(in_ECX + 0x1454);
  while (iVar5 != 0) {
    piVar2 = (int *)FUN_00542210();
    if ((int *)*piVar2 == (int *)0x0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)*piVar2;
    }
    uVar3 = (uint)piVar2[2] >> 1;
    uVar4 = piVar2[2] & 1;
    if (*(uint *)(iVar5 + 8) <= uVar3) {
      uVar3 = uVar3 - *(uint *)(iVar5 + 8);
    }
    iVar5 = *(int *)(*(int *)(iVar5 + 4) + uVar3 * 4);
    piVar2 = *(int **)(iVar5 + 4 + uVar4 * 8);
    piVar1 = *(int **)(iVar5 + uVar4 * 8);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x15c))(piVar2);
    }
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x10))(1);
    }
    if (*(int *)(in_ECX + 0x1454) != 0) {
      *(int *)(in_ECX + 0x1450) = *(int *)(in_ECX + 0x1450) + 1;
      if ((uint)(*(int *)(in_ECX + 0x144c) * 2) <= *(uint *)(in_ECX + 0x1450)) {
        *(undefined4 *)(in_ECX + 0x1450) = 0;
      }
      iVar5 = *(int *)(in_ECX + 0x1454) + -1;
      *(int *)(in_ECX + 0x1454) = iVar5;
      if (iVar5 == 0) {
        *(undefined4 *)(in_ECX + 0x1450) = 0;
      }
    }
    iVar5 = *(int *)(in_ECX + 0x1454);
  }
  return;
}

