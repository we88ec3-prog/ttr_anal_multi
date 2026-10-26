
void FUN_00843650(int param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int local_8;
  
  piVar2 = *(int **)(param_1 + 0x110);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    *(undefined4 *)(param_1 + 0x110) = 0;
  }
  FUN_00823850();
  *(undefined4 *)(param_1 + 0x114) = 1;
  local_8 = 8;
  iVar4 = param_1;
  do {
    piVar2 = *(int **)(*(int *)(iVar4 + 0x14) + 4);
    cVar1 = *(char *)((int)piVar2 + 0x15);
    while (cVar1 == '\0') {
      FUN_0073eba0(piVar2[2]);
      piVar3 = (int *)*piVar2;
      FUN_0089120c(piVar2);
      piVar2 = piVar3;
      cVar1 = *(char *)((int)piVar3 + 0x15);
    }
    *(int *)(*(int *)(iVar4 + 0x14) + 4) = *(int *)(iVar4 + 0x14);
    *(undefined4 *)*(undefined4 *)(iVar4 + 0x14) = *(undefined4 *)(iVar4 + 0x14);
    *(int *)(*(int *)(iVar4 + 0x14) + 8) = *(int *)(iVar4 + 0x14);
    *(undefined4 *)(iVar4 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x114) = 1;
    piVar2 = *(int **)(*(int *)(iVar4 + 0x94) + 4);
    cVar1 = *(char *)((int)piVar2 + 0x15);
    while (cVar1 == '\0') {
      FUN_0073eba0(piVar2[2]);
      piVar3 = (int *)*piVar2;
      FUN_0089120c(piVar2);
      piVar2 = piVar3;
      cVar1 = *(char *)((int)piVar3 + 0x15);
    }
    *(int *)(*(int *)(iVar4 + 0x94) + 4) = *(int *)(iVar4 + 0x94);
    *(undefined4 *)*(undefined4 *)(iVar4 + 0x94) = *(undefined4 *)(iVar4 + 0x94);
    *(int *)(*(int *)(iVar4 + 0x94) + 8) = *(int *)(iVar4 + 0x94);
    *(undefined4 *)(iVar4 + 0x98) = 0;
    local_8 = local_8 + -1;
    *(undefined4 *)(param_1 + 0x114) = 1;
    iVar4 = iVar4 + 0x10;
  } while (local_8 != 0);
  *(undefined4 *)(param_1 + 0x114) = 1;
  return;
}

