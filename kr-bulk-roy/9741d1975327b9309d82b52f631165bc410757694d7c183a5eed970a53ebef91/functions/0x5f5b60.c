
void FUN_005f5b60(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int *in_ECX;
  int iVar6;
  int local_c;
  undefined4 local_8;
  
  local_8 = 0xb;
  FUN_0082ef00(&local_8);
  if (local_c == in_ECX[0x14]) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(local_c + 0x10);
  }
  piVar1 = in_ECX + 0x3b;
  in_ECX[0x20] = iVar5;
  FUN_006ad0e0();
  uVar4 = (**(code **)(*in_ECX + 0x198))();
  FUN_005f7e40(uVar4);
  uVar4 = (**(code **)(*in_ECX + 0x198))();
  if (*(int *)(*piVar1 + 0xcc) != 0) {
    FUN_00408920(*(int *)(*piVar1 + 0xcc),uVar4);
  }
  iVar6 = 0;
  iVar5 = (**(code **)(*in_ECX + 0x198))();
  if (0 < iVar5) {
    do {
      iVar5 = *(int *)(*piVar1 + 0xcc);
      if (((iVar5 == 0) || (iVar6 < 0)) ||
         (*(int *)(iVar5 + 0xac) - *(int *)(iVar5 + 0xa8) >> 2 <= iVar6)) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(undefined4 *)(*(int *)(iVar5 + 0xa8) + iVar6 * 4);
      }
      *(undefined4 *)(in_ECX[0x3d] + iVar6 * 4) = uVar4;
      (**(code **)(**(int **)(in_ECX[0x3d] + iVar6 * 4) + 0x198))(0x96);
      iVar6 = iVar6 + 1;
      iVar5 = (**(code **)(*in_ECX + 0x198))();
    } while (iVar6 < iVar5);
  }
  piVar1 = (int *)*piVar1;
  puVar2 = (undefined4 *)piVar1[0x19];
  for (puVar3 = (undefined4 *)*puVar2; puVar3 != puVar2; puVar3 = (undefined4 *)*puVar3) {
    iVar5 = puVar3[2];
    if ((*(int *)(iVar5 + 0x60) != 0) && ((*(int **)(iVar5 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar5 + 0x1c) + 0x30))(iVar5);
    }
  }
  (**(code **)(*piVar1 + 0x128))();
  return;
}

