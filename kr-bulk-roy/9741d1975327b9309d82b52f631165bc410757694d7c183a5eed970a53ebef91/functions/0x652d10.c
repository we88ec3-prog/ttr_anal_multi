
void FUN_00652d10(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  FUN_00754430();
  uVar6 = 0;
  uVar7 = 0;
  (**(code **)(**(int **)(in_ECX + 0xcc) + 0xbc))
            (0,0,*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 8),
             *(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0xc));
  puVar4 = (undefined4 *)(in_ECX + 0xe8);
  iVar3 = 0x10;
  do {
    (**(code **)(*(int *)*puVar4 + 0x94))(1);
    puVar4 = puVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar3 = *(int *)(in_ECX + 0xe0);
  if (iVar3 < 0x10) {
    piVar5 = (int *)(in_ECX + 0xe8 + iVar3 * 4);
    iVar3 = 0x10 - iVar3;
    do {
      if (((uint)((int *)*piVar5)[10] >> 8 & 1) != 0) {
        (**(code **)(*(int *)*piVar5 + 0x94))(0);
      }
      piVar5 = piVar5 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  if (*(int *)(in_ECX + 0xd8) == 0) {
    iVar3 = *(int *)(in_ECX + 0xa4);
    iVar2 = *(int *)(in_ECX + 0xac) - iVar3;
    iVar1 = FUN_008fed10();
    (**(code **)(**(int **)(in_ECX + 0xe4 + *(int *)(in_ECX + 0xe0) * 4) + 0xbc))(0,0,0,0);
    (**(code **)(**(int **)(in_ECX + 0xe4 + *(int *)(in_ECX + 0xe0) * 4) + 200))();
    if (-1 < *(int *)(in_ECX + 0xe0) + -2) {
      (**(code **)(**(int **)(in_ECX + 0xe0 + *(int *)(in_ECX + 0xe0) * 4) + 0xbc))
                (*(undefined4 *)(in_ECX + 0xa4),*(undefined4 *)(in_ECX + 0xa8),
                 *(undefined4 *)(in_ECX + 0xac),*(undefined4 *)(in_ECX + 0xb0));
      (**(code **)(**(int **)(in_ECX + 0xe0 + *(int *)(in_ECX + 0xe0) * 4) + 200))();
    }
    (**(code **)(**(int **)(in_ECX + 0xe4 + *(int *)(in_ECX + 0xe0) * 4) + 0xbc))
              (uVar6,uVar7,iVar3 + iVar1,iVar2);
    (**(code **)(**(int **)(in_ECX + 0xe4 + *(int *)(in_ECX + 0xe0) * 4) + 200))();
  }
  else if (*(int *)(in_ECX + 0xd8) == 1) {
    uVar6 = *(undefined4 *)(in_ECX + 0xa8);
    iVar3 = FUN_008fed10();
    (**(code **)(**(int **)(in_ECX + 0xe8 + *(int *)(in_ECX + 0xe0) * 4) + 0xbc))
              (*(int *)(in_ECX + 0xac) - iVar3,uVar6,*(undefined4 *)(in_ECX + 0xac),
               *(undefined4 *)(in_ECX + 0xb0));
  }
  if (*(char *)(in_ECX + 0xd4) != '\0') {
    FUN_00759be0(*(float *)(in_ECX + 0xd0) * 100.0);
  }
  return;
}

