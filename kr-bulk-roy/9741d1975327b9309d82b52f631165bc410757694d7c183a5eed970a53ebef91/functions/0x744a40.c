
void FUN_00744a40(int *param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  uint uVar4;
  
  piVar1 = param_1;
  FUN_00746ed0(param_1);
  iVar2 = *param_1;
  uVar4 = 0;
  if (param_1[1] - iVar2 >> 2 != 0) {
    do {
      iVar2 = (**(code **)(**(int **)(iVar2 + uVar4 * 4) + 4))();
      if (iVar2 == 0xf231) {
        piVar3 = (int *)(in_ECX + 0x94);
        param_1 = (int *)0x4;
        do {
          if (*piVar3 != 0) {
            (**(code **)(*(int *)*piVar3 + 0x50))(*(undefined4 *)(*piVar1 + uVar4 * 4));
          }
          piVar3 = piVar3 + 1;
          param_1 = (int *)((int)param_1 + -1);
        } while (param_1 != (int *)0x0);
      }
      iVar2 = *piVar1;
      uVar4 = uVar4 + 1;
    } while (uVar4 < (uint)(piVar1[1] - iVar2 >> 2));
  }
  return;
}

