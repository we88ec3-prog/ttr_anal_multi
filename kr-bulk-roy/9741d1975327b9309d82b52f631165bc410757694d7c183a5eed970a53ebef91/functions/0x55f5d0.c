
void FUN_0055f5d0(void)

{
  undefined4 *puVar1;
  int in_EAX;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int *local_14;
  uint local_c;
  
  iVar2 = *(int *)(in_EAX + 4);
  *(undefined4 *)(iVar2 + 0x28) = 0;
  if (*(int *)(iVar2 + 0x44) != 0) {
    FUN_0089120c(*(int *)(iVar2 + 0x44));
    *(undefined4 *)(iVar2 + 0x44) = 0;
  }
  if (*(int **)(in_EAX + 8) != (int *)0x0) {
    (**(code **)(**(int **)(in_EAX + 8) + 8))();
    *(undefined4 *)(in_EAX + 8) = 0;
  }
  puVar1 = *(undefined4 **)(in_EAX + 0x24);
  if (puVar1 != (undefined4 *)0x0) {
    if (0xf < (uint)puVar1[0xc]) {
      FUN_0089120c(puVar1[7]);
    }
    puVar1[0xc] = 0xf;
    puVar1[0xb] = 0;
    *(undefined1 *)(puVar1 + 7) = 0;
    if (7 < (uint)puVar1[5]) {
      FUN_0089120c(*puVar1);
    }
    puVar1[5] = 7;
    puVar1[4] = 0;
    *(undefined2 *)puVar1 = 0;
    FUN_0089120c(puVar1);
    *(undefined4 *)(in_EAX + 0x24) = 0;
  }
  FUN_00542210();
  iVar2 = FUN_004d8460();
  if (local_c != *(uint *)(iVar2 + 8)) {
    do {
      if (local_14 == (int *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *local_14;
      }
      uVar5 = local_c >> 2;
      uVar4 = local_c & 3;
      uVar3 = uVar5;
      if (*(uint *)(iVar2 + 8) <= uVar5) {
        uVar3 = uVar5 - *(uint *)(iVar2 + 8);
      }
      if (*(int *)(*(int *)(*(int *)(iVar2 + 4) + uVar3 * 4) + uVar4 * 4) != 0) {
        if (local_14 == (int *)0x0) {
          iVar2 = 0;
        }
        else {
          iVar2 = *local_14;
        }
        uVar3 = uVar5;
        if (*(uint *)(iVar2 + 8) <= uVar5) {
          uVar3 = uVar5 - *(uint *)(iVar2 + 8);
        }
        puVar1 = *(undefined4 **)(*(int *)(*(int *)(iVar2 + 4) + uVar3 * 4) + uVar4 * 4);
        if (puVar1 != (undefined4 *)0x0) {
          if (0xf < (uint)puVar1[0xc]) {
            FUN_0089120c(puVar1[7]);
          }
          puVar1[0xc] = 0xf;
          puVar1[0xb] = 0;
          *(undefined1 *)(puVar1 + 7) = 0;
          if (7 < (uint)puVar1[5]) {
            FUN_0089120c(*puVar1);
          }
          puVar1[5] = 7;
          puVar1[4] = 0;
          *(undefined2 *)puVar1 = 0;
          FUN_0089120c(puVar1);
        }
        if (local_14 == (int *)0x0) {
          iVar2 = 0;
        }
        else {
          iVar2 = *local_14;
        }
        if (*(uint *)(iVar2 + 8) <= uVar5) {
          uVar5 = uVar5 - *(uint *)(iVar2 + 8);
        }
        *(undefined4 *)(*(int *)(*(int *)(iVar2 + 4) + uVar5 * 4) + uVar4 * 4) = 0;
      }
      local_c = local_c + 1;
      iVar2 = FUN_004d8460();
    } while (local_c != *(uint *)(iVar2 + 8));
  }
  FUN_007b6d70();
  return;
}

