
void FUN_00746640(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int in_ECX;
  undefined4 *extraout_EDX;
  
  iVar1 = *(int *)(param_1 + 0x60);
  if (iVar1 != 0) {
    piVar2 = *(int **)(iVar1 + 100);
    for (piVar3 = (int *)*piVar2; piVar3 != piVar2; piVar3 = (int *)*piVar3) {
      if (piVar3[2] == param_1) {
        if (piVar3 != piVar2) {
          *(int *)piVar3[1] = *piVar3;
          *(int *)(*piVar3 + 4) = piVar3[1];
          FUN_0089120c(piVar3);
          *(int *)(iVar1 + 0x68) = *(int *)(iVar1 + 0x68) + -1;
        }
        break;
      }
    }
  }
  *(int *)(param_1 + 0x60) = in_ECX;
  uVar4 = *(undefined4 *)(in_ECX + 0x24);
  *(undefined4 *)(param_1 + 0x24) = uVar4;
  if ((*(int *)(param_1 + 0x3c) != 0) && ((*(uint *)(param_1 + 0x28) & 0x40000) == 0)) {
    FUN_007486f0(uVar4);
  }
  puVar5 = *(undefined4 **)(param_1 + 100);
  puVar6 = (undefined4 *)*puVar5;
  while (puVar6 != puVar5) {
    FUN_007486f0(*(undefined4 *)(param_1 + 0x24));
    puVar6 = (undefined4 *)*extraout_EDX;
  }
  FUN_00746f70();
  if ((*(int *)(param_1 + 0x60) != 0) && ((*(int **)(param_1 + 0x1c))[2] != 6)) {
    (**(code **)(**(int **)(param_1 + 0x1c) + 0x30))(param_1);
  }
  FUN_007464b0(param_1);
  return;
}

