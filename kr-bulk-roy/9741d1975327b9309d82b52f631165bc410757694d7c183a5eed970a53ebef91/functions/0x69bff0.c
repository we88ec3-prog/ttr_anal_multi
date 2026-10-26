
void FUN_0069bff0(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int in_ECX;
  int *piVar5;
  int iVar6;
  
  FUN_00755e50();
  piVar1 = (int *)(in_ECX + 0xf8);
  FUN_0069cc30();
  FUN_006b57d0();
  FUN_00643ce0(3000);
  FUN_00643ce0(4000);
  if (*(int *)(*piVar1 + 0xcc) != 0) {
    FUN_00408920(*(int *)(*piVar1 + 0xcc),0xf);
  }
  iVar6 = 0;
  do {
    iVar2 = *(int *)(*piVar1 + 0xcc);
    if (((iVar2 == 0) || (iVar6 < 0)) ||
       (*(int *)(iVar2 + 0xac) - *(int *)(iVar2 + 0xa8) >> 2 <= iVar6)) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = *(int **)(*(int *)(iVar2 + 0xa8) + iVar6 * 4);
    }
    *(int **)(in_ECX + 0xfc + iVar6 * 4) = piVar5;
    (**(code **)(*piVar5 + 0x198))(0x7d3);
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0xf);
  piVar5 = (int *)*piVar1;
  puVar3 = (undefined4 *)piVar5[0x19];
  for (puVar4 = (undefined4 *)*puVar3; puVar4 != puVar3; puVar4 = (undefined4 *)*puVar4) {
    iVar6 = puVar4[2];
    if ((*(int *)(iVar6 + 0x60) != 0) && ((*(int **)(iVar6 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar6 + 0x1c) + 0x30))(iVar6);
    }
  }
  (**(code **)(*piVar5 + 0x128))();
  (**(code **)(*(int *)*piVar1 + 200))();
  return;
}

