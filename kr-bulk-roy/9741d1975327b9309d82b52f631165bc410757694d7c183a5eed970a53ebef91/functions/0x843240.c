
int FUN_00843240(int param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int local_8;
  
  if (param_1 != param_2) {
    FUN_00843650(param_1);
    FUN_005540c0(**(undefined4 **)(param_1 + 4),*(undefined4 **)(param_1 + 4));
    FUN_005c7580(param_2);
    puVar2 = (undefined4 *)(param_2 + 0x90);
    puVar3 = (undefined4 *)(param_1 + 0x94);
    local_8 = 8;
    do {
      if (puVar3 + -0x21 != puVar2 + -0x20) {
        FUN_005540c0(*(undefined4 *)puVar3[-0x20],(undefined4 *)puVar3[-0x20]);
        FUN_005c7580(puVar2 + -0x20);
      }
      if (puVar3 + -1 != puVar2) {
        FUN_005540c0(*(undefined4 *)*puVar3,(undefined4 *)*puVar3);
        FUN_005c7580(puVar2);
      }
      puVar2 = puVar2 + 4;
      puVar3 = puVar3 + 4;
      local_8 = local_8 + -1;
    } while (local_8 != 0);
    piVar1 = *(int **)(param_2 + 0x110);
    *(int **)(param_1 + 0x110) = piVar1;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1);
    }
    *(undefined4 *)(param_1 + 0x114) = *(undefined4 *)(param_2 + 0x114);
    *(undefined4 *)(param_1 + 0x118) = *(undefined4 *)(param_2 + 0x118);
    return param_1;
  }
  return param_1;
}

