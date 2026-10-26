
void FUN_007628f0(void)

{
  int in_EAX;
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  int *local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  uVar1 = *(uint *)(*(int *)(in_EAX + 0x24) + 0xbc);
  local_14 = (int *)(*(int *)(in_EAX + 0x24) + 0xa8);
  uVar4 = (int)uVar1 >> 0x1f;
  uVar1 = uVar1 ^ uVar4;
  if (uVar1 != uVar4 && -1 < (int)(uVar1 - uVar4)) {
    uVar1 = *(uint *)(in_EAX + 0x118);
    uVar4 = *(uint *)(in_EAX + 0x168);
    local_10 = 0;
    local_8 = uVar4;
    if (uVar1 < uVar4) {
      local_8 = uVar1 - 1;
    }
    uVar2 = (*local_14 - *(int *)(in_EAX + 0x2c)) - *(int *)(in_EAX + 0xa4);
    local_c = *(int *)(in_EAX + 0xac) - *(int *)(in_EAX + 0xa4);
    if ((int)(((int)uVar2 < 1) - 1 & uVar2) < (int)local_c) {
      local_c = ((int)uVar2 < 1) - 1 & uVar2;
    }
    puVar3 = (undefined4 *)(in_EAX + 0x108);
    if (7 < *(uint *)(in_EAX + 0x11c)) {
      puVar3 = (undefined4 *)*puVar3;
    }
    (**(code **)(**(int **)(in_EAX + 0xf4) + 0x38))
              (&local_10,local_c,(int)puVar3 + local_8 * 2,uVar1 - uVar4);
    if ((*local_14 < *(int *)(in_EAX + 0x2c)) && (0 < *(int *)(in_EAX + 0x168))) {
      *(int *)(in_EAX + 0x168) = *(int *)(in_EAX + 0x168) + -1;
    }
    else if (*(int *)(in_EAX + 0x34) < *local_14) {
      uVar1 = *(uint *)(in_EAX + 0x168);
      uVar4 = *(uint *)(in_EAX + 0x118);
      local_8 = uVar1;
      if (uVar4 < uVar1) {
        local_8 = uVar4 - 1;
      }
      puVar3 = (undefined4 *)(in_EAX + 0x108);
      if (7 < *(uint *)(in_EAX + 0x11c)) {
        puVar3 = (undefined4 *)*puVar3;
      }
      (**(code **)(**(int **)(in_EAX + 0xf4) + 0x30))
                (&local_14,&local_c,(int)puVar3 + local_8 * 2,uVar4 - uVar1);
      if (*(int *)(in_EAX + 0xac) - *(int *)(in_EAX + 0xa4) < (int)local_14) {
        *(int *)(in_EAX + 0x168) = *(int *)(in_EAX + 0x168) + 1;
      }
    }
    uVar1 = *(int *)(in_EAX + 0x168) + local_10;
    if (uVar1 <= *(uint *)(in_EAX + 0x118)) {
      if (*(char *)(in_EAX + 0x150) != '\0') {
        *(uint *)(in_EAX + 0x164) = uVar1;
        FUN_00761800();
        return;
      }
      *(undefined4 *)(in_EAX + 0x164) = *(undefined4 *)(in_EAX + 0x160);
    }
    FUN_00761800();
  }
  return;
}

