
undefined4 FUN_007eaa90(void)

{
  int in_EAX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int *in_ECX;
  
  if (in_ECX == (int *)0x0) {
    return 0;
  }
  iVar1 = (**(code **)(*in_ECX + 0x14))();
  if (iVar1 == 0) {
    return 1;
  }
  iVar1 = FUN_007300a0("Enable");
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)(iVar1 + 0x30);
    if (0xf < *(uint *)(iVar1 + 0x44)) {
      puVar2 = (undefined4 *)*puVar2;
    }
    if (puVar2 != (undefined4 *)0x0) {
      uVar3 = FUN_008917b4(puVar2);
      goto LAB_007eaae4;
    }
  }
  uVar3 = 0;
LAB_007eaae4:
  *(undefined4 *)(*(int *)(*(int *)(in_EAX + 4) + 0x40) + 0x194) = uVar3;
  iVar1 = FUN_0087dc3d(*(undefined4 *)(*(int *)(in_EAX + 0x28) + 0x50));
  (**(code **)(**(int **)(in_EAX + 0x24) + 0x34))(*(undefined4 *)(*(int *)(in_EAX + 0x28) + 0x40),0)
  ;
  if (*(int **)(in_EAX + 0x24) != (int *)0x0) {
    (**(code **)(**(int **)(in_EAX + 0x24) + 0x10))
              (iVar1,1,*(undefined4 *)(*(int *)(in_EAX + 0x28) + 0x50));
  }
  iVar4 = FUN_0087dc3d(*(undefined4 *)(*(int *)(in_EAX + 0x28) + 0x54));
  FUN_00727190(iVar4);
  FUN_007e5f20(iVar4);
  if (iVar1 != 0) {
    FUN_00891d3d(iVar1);
  }
  if (iVar4 != 0) {
    FUN_00891d3d(iVar4);
  }
  return 1;
}

