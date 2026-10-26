
void FUN_00762800(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int in_EAX;
  undefined4 uVar4;
  undefined4 *puVar5;
  int local_10;
  uint local_c;
  
  uVar1 = *(uint *)(in_EAX + 0x168);
  uVar2 = *(uint *)(in_EAX + 0x118);
  iVar3 = *(int *)(in_EAX + 0x24);
  local_10 = 0;
  local_c = uVar1;
  if (uVar2 < uVar1) {
    local_c = uVar2 - 1;
  }
  puVar5 = (undefined4 *)(in_EAX + 0x108);
  if (7 < *(uint *)(in_EAX + 0x11c)) {
    puVar5 = (undefined4 *)*puVar5;
  }
  (**(code **)(**(int **)(in_EAX + 0xf4) + 0x38))
            (&local_10,(*(int *)(iVar3 + 0xa8) - *(int *)(in_EAX + 0xa4)) - *(int *)(in_EAX + 0x2c),
             (int)puVar5 + local_c * 2,uVar2 - uVar1);
  *(int *)(in_EAX + 0x14c) = *(int *)(in_EAX + 0x168) + local_10;
  FUN_007619a0();
  if ((((*(int *)(iVar3 + 0x3d4) == 1) || (*(int *)(iVar3 + 0x3d4) == 2)) ||
      (*(int *)(iVar3 + 0x404) == 1)) || (*(int *)(iVar3 + 0x404) == 2)) {
    uVar4 = *(undefined4 *)(in_EAX + 0x160);
    if (*(char *)(in_EAX + 0x150) != '\0') {
      *(undefined4 *)(in_EAX + 0x164) = *(undefined4 *)(in_EAX + 0x14c);
      FUN_00761800();
      return;
    }
  }
  else {
    uVar4 = *(undefined4 *)(in_EAX + 0x14c);
    *(undefined4 *)(in_EAX + 0x160) = uVar4;
  }
  *(undefined4 *)(in_EAX + 0x164) = uVar4;
  FUN_00761800();
  return;
}

