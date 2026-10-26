
void FUN_00457f50(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int in_EAX;
  int *piVar6;
  int *piVar7;
  uint local_10;
  
  iVar5 = DAT_00fc0c68;
  piVar6 = (int *)(DAT_00fc0c68 + 0x4c);
  *(undefined4 *)(in_EAX + 0x15c) = 0;
  *(undefined4 *)(in_EAX + 0x158) = 0;
  iVar1 = *(int *)(*(int *)(in_EAX + 0x110) + 0xcc);
  uVar4 = (*(int *)(iVar5 + 0x50) - *piVar6) / 0x43;
  if (iVar1 != 0) {
    FUN_00408920(iVar1,uVar4);
  }
  local_10 = 0;
  if (uVar4 != 0) {
    do {
      iVar1 = *(int *)(*(int *)(in_EAX + 0x110) + 0xcc);
      if (((iVar1 == 0) || ((int)local_10 < 0)) ||
         (*(int *)(iVar1 + 0xac) - *(int *)(iVar1 + 0xa8) >> 2 <= (int)local_10)) {
        piVar7 = (int *)0x0;
      }
      else {
        piVar7 = *(int **)(*(int *)(iVar1 + 0xa8) + local_10 * 4);
      }
      FUN_00457150(piVar7,*(undefined4 *)
                           (in_EAX + 0x160 + (uint)*(byte *)(*piVar6 + 0x42 + local_10 * 0x43) * 4))
      ;
      (**(code **)(*piVar7 + 200))();
      if (local_10 == 0) {
        *(uint *)(in_EAX + 0x158) = (uint)*(ushort *)(*piVar6 + 0x2e);
      }
      if (local_10 == uVar4 - 1) {
        *(uint *)(in_EAX + 0x15c) = (uint)*(ushort *)(local_10 * 0x43 + 0x2e + *piVar6);
      }
      local_10 = local_10 + 1;
    } while (local_10 < uVar4);
  }
  piVar6 = *(int **)(in_EAX + 0x110);
  puVar2 = (undefined4 *)piVar6[0x19];
  for (puVar3 = (undefined4 *)*puVar2; puVar3 != puVar2; puVar3 = (undefined4 *)*puVar3) {
    iVar1 = puVar3[2];
    if ((*(int *)(iVar1 + 0x60) != 0) && ((*(int **)(iVar1 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar1 + 0x1c) + 0x30))(iVar1);
    }
  }
  (**(code **)(*piVar6 + 0x128))();
  (**(code **)(**(int **)(in_EAX + 0x110) + 200))();
  FUN_007597b0(0);
  FUN_007597b0(1);
  (**(code **)(**(int **)(in_EAX + 0x10c) + 200))();
  return;
}

