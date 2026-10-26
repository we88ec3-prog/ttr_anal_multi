
void FUN_00781cc0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  void *pvVar3;
  int iVar4;
  int in_EAX;
  int *piVar5;
  
  piVar1 = *(int **)(in_EAX + 0x84);
  if (piVar1 != (int *)0x0) {
    (*(code *)**(undefined4 **)((int)piVar1 + *(int *)(*piVar1 + 4)))(1);
    *(undefined4 *)(in_EAX + 0x84) = 0;
  }
  piVar1 = *(int **)(in_EAX + 0x88);
  if (piVar1 != (int *)0x0) {
    (*(code *)**(undefined4 **)((int)piVar1 + *(int *)(*piVar1 + 4)))(1);
    *(undefined4 *)(in_EAX + 0x88) = 0;
  }
  *(undefined2 *)(in_EAX + 0x8c) = 0;
  if (*(int *)(in_EAX + 0x50) == 0) {
    piVar1 = *(int **)(in_EAX + 8);
    piVar5 = *(int **)(in_EAX + 4);
    while (piVar5 != piVar1) {
      puVar2 = (undefined4 *)*piVar5;
      piVar5 = piVar5 + 1;
      if (puVar2 != (undefined4 *)0x0) {
        (**(code **)*puVar2)(1);
      }
    }
  }
  pvVar3 = *(void **)(in_EAX + 4);
  if (pvVar3 != *(void **)(in_EAX + 8)) {
    FID_conflict__memcpy(pvVar3,*(void **)(in_EAX + 8),0);
    *(void **)(in_EAX + 8) = pvVar3;
  }
  FUN_00783920(*(undefined4 *)(*(int *)(in_EAX + 0x28) + 4));
  *(int *)(*(int *)(in_EAX + 0x28) + 4) = *(int *)(in_EAX + 0x28);
  *(undefined4 *)*(undefined4 *)(in_EAX + 0x28) = *(undefined4 *)(in_EAX + 0x28);
  *(int *)(*(int *)(in_EAX + 0x28) + 8) = *(int *)(in_EAX + 0x28);
  *(undefined4 *)(in_EAX + 0x2c) = 0;
  piVar1 = *(int **)(in_EAX + 0x78);
  for (piVar5 = *(int **)(in_EAX + 0x74); piVar5 != piVar1; piVar5 = piVar5 + 1) {
    iVar4 = *piVar5;
    if (iVar4 != 0) {
      if (*(int *)(iVar4 + 0x14) != 0) {
        FUN_00891d3d(*(int *)(iVar4 + 0x14));
      }
      FUN_0089120c(iVar4);
      *piVar5 = 0;
    }
  }
  pvVar3 = *(void **)(in_EAX + 0x74);
  if (pvVar3 != *(void **)(in_EAX + 0x78)) {
    FID_conflict__memcpy(pvVar3,*(void **)(in_EAX + 0x78),0);
    *(void **)(in_EAX + 0x78) = pvVar3;
  }
  *(undefined4 *)(in_EAX + 0x54) = 0;
  *(undefined4 *)(in_EAX + 0x58) = 0;
  *(undefined4 *)(in_EAX + 0x5c) = 0x641;
  *(undefined4 *)(in_EAX + 0x60) = 0;
  *(undefined4 *)(in_EAX + 100) = 0;
  *(undefined4 *)(in_EAX + 0x68) = 0;
  *(undefined4 *)(in_EAX + 0x6c) = 0;
  if (*(int *)(in_EAX + 0x70) != 0) {
    FUN_00891d3d(*(int *)(in_EAX + 0x70));
  }
  *(undefined4 *)(in_EAX + 0x70) = 0;
  *(undefined4 *)(in_EAX + 0x50) = 2;
  *(undefined4 *)(in_EAX + 0x44) = 0;
  if (*(uint *)(in_EAX + 0x48) < 0x10) {
    *(undefined1 *)(in_EAX + 0x34) = 0;
    return;
  }
  **(undefined1 **)(in_EAX + 0x34) = 0;
  return;
}

