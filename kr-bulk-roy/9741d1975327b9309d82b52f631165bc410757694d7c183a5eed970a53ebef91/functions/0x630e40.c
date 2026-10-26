
void FUN_00630e40(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  int *piVar4;
  int iVar5;
  
  iVar5 = *(int *)(*(int *)(in_ECX + 0x124) + 0xcc);
  if (iVar5 != 0) {
    FUN_00408920(iVar5,6);
  }
  iVar5 = 0;
  do {
    iVar1 = *(int *)(*(int *)(in_ECX + 0x124) + 0xcc);
    if (((iVar1 == 0) || (iVar5 < 0)) ||
       (*(int *)(iVar1 + 0xac) - *(int *)(iVar1 + 0xa8) >> 2 <= iVar5)) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = *(int **)(*(int *)(iVar1 + 0xa8) + iVar5 * 4);
    }
    *(int **)(in_ECX + 0x128 + iVar5 * 4) = piVar4;
    (**(code **)(*piVar4 + 0x198))(0xc739);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 6);
  piVar4 = *(int **)(in_ECX + 0x124);
  puVar2 = (undefined4 *)piVar4[0x19];
  for (puVar3 = (undefined4 *)*puVar2; puVar3 != puVar2; puVar3 = (undefined4 *)*puVar3) {
    iVar5 = puVar3[2];
    if ((*(int *)(iVar5 + 0x60) != 0) && ((*(int **)(iVar5 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar5 + 0x1c) + 0x30))(iVar5);
    }
  }
  (**(code **)(*piVar4 + 0x128))();
  *(undefined1 *)(*(int *)(in_ECX + 0x104) + 0xc9) = 0;
  *(undefined1 *)(*(int *)(in_ECX + 0x108) + 0xc9) = 0;
  return;
}

