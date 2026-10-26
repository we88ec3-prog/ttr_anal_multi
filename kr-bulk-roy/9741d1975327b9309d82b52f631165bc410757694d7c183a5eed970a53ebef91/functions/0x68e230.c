
void FUN_0068e230(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 uVar4;
  undefined4 *puVar5;
  int local_8;
  
  (**(code **)(**(int **)(in_ECX + 0xf8) + 0x94))(1);
  iVar1 = *(int *)(*(int *)(in_ECX + 0x124) + 0xcc);
  if (iVar1 != 0) {
    FUN_00408920(iVar1,9);
  }
  local_8 = 0;
  puVar5 = (undefined4 *)(in_ECX + 0x13c);
  do {
    iVar1 = *(int *)(*(int *)(in_ECX + 0x124) + 0xcc);
    if (((iVar1 == 0) || (local_8 < 0)) ||
       (*(int *)(iVar1 + 0xac) - *(int *)(iVar1 + 0xa8) >> 2 <= local_8)) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(undefined4 *)((int)puVar5 + *(int *)(iVar1 + 0xa8) + (-0x13c - in_ECX));
    }
    *puVar5 = uVar4;
    FUN_0043c570(31000);
    FUN_0043c570(32000);
    FUN_0043c570(33000);
    FUN_0043c570(34000);
    local_8 = local_8 + 1;
    puVar5 = puVar5 + 1;
  } while (local_8 < 9);
  piVar2 = *(int **)(in_ECX + 0x124);
  puVar5 = (undefined4 *)piVar2[0x19];
  for (puVar3 = (undefined4 *)*puVar5; puVar3 != puVar5; puVar3 = (undefined4 *)*puVar3) {
    iVar1 = puVar3[2];
    if ((*(int *)(iVar1 + 0x60) != 0) && ((*(int **)(iVar1 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar1 + 0x1c) + 0x30))(iVar1);
    }
  }
  (**(code **)(*piVar2 + 0x128))();
  (**(code **)(**(int **)(in_ECX + 0xf8) + 0xa0))(1);
  (**(code **)(**(int **)(in_ECX + 0xfc) + 0x94))(0);
  (**(code **)(**(int **)(in_ECX + 0xfc) + 0x90))(0);
  return;
}

