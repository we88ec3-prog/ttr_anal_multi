
void FUN_006820d0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  int *piVar4;
  int iVar5;
  
  iVar5 = *(int *)(*(int *)(in_ECX + 0x110) + 0xcc);
  if (iVar5 != 0) {
    FUN_00408920(iVar5,10);
  }
  iVar5 = 0;
  do {
    iVar1 = *(int *)(*(int *)(in_ECX + 0x110) + 0xcc);
    if (((iVar1 == 0) || (iVar5 < 0)) ||
       (*(int *)(iVar1 + 0xac) - *(int *)(iVar1 + 0xa8) >> 2 <= iVar5)) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = *(int **)(*(int *)(iVar1 + 0xa8) + iVar5 * 4);
    }
    *(int **)(in_ECX + 0xd8 + iVar5 * 4) = piVar4;
    (**(code **)(*piVar4 + 0x198))(0x3ec);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 10);
  piVar4 = *(int **)(in_ECX + 0x110);
  puVar2 = (undefined4 *)piVar4[0x19];
  for (puVar3 = (undefined4 *)*puVar2; puVar3 != puVar2; puVar3 = (undefined4 *)*puVar3) {
    iVar5 = puVar3[2];
    if ((*(int *)(iVar5 + 0x60) != 0) && ((*(int **)(iVar5 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar5 + 0x1c) + 0x30))(iVar5);
    }
  }
                    /* WARNING: Could not recover jumptable at 0x0068217d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar4 + 0x128))();
  return;
}

