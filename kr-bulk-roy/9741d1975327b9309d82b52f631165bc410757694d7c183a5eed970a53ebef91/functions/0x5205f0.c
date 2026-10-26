
void FUN_005205f0(int *param_1)

{
  int *piVar1;
  undefined2 uVar2;
  int in_EAX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  iVar3 = FUN_007300a0("action");
  if (iVar3 == 0) {
LAB_00520626:
    uVar2 = 0;
  }
  else {
    puVar4 = (undefined4 *)(iVar3 + 0x30);
    if (0xf < *(uint *)(iVar3 + 0x44)) {
      puVar4 = (undefined4 *)*puVar4;
    }
    if (puVar4 == (undefined4 *)0x0) goto LAB_00520626;
    uVar2 = FUN_008917b4(puVar4);
  }
  *(undefined2 *)(param_1 + 2) = uVar2;
  iVar3 = FUN_007300a0("priority");
  if (iVar3 != 0) {
    puVar4 = (undefined4 *)(iVar3 + 0x30);
    if (0xf < *(uint *)(iVar3 + 0x44)) {
      puVar4 = (undefined4 *)*puVar4;
    }
    if (puVar4 != (undefined4 *)0x0) {
      uVar2 = FUN_008917b4(puVar4);
      goto LAB_00520656;
    }
  }
  uVar2 = 0;
LAB_00520656:
  *(undefined2 *)((int)param_1 + 10) = uVar2;
  piVar1 = *(int **)(in_EAX + 0x18);
  while( true ) {
    if (piVar1 == (int *)0x0) {
      (**(code **)(*param_1 + 4))(0);
      return;
    }
    iVar3 = (**(code **)(*piVar1 + 0x18))();
    if (iVar3 != 0) break;
    piVar1 = (int *)piVar1[0x10];
  }
  uVar5 = (**(code **)(*piVar1 + 0x18))();
  (**(code **)(*param_1 + 4))(uVar5);
  return;
}

