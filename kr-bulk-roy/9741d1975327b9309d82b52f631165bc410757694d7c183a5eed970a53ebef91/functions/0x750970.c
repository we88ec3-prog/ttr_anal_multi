
void FUN_00750970(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  void *pvVar5;
  uint uVar6;
  int in_EAX;
  uint uVar7;
  undefined4 local_18;
  undefined4 local_14;
  uint local_10;
  int *local_c;
  int *local_8;
  
  local_14 = 5;
  local_18 = 6;
  (**(code **)(**(int **)(in_EAX + 0x1c) + 0xe8))(*(int **)(in_EAX + 0x1c),0x13,&local_14);
  (**(code **)(**(int **)(in_EAX + 0x1c) + 0xe8))(*(int **)(in_EAX + 0x1c),0x14,&local_18);
  (**(code **)(**(int **)(in_EAX + 0x1c) + 0xe4))(*(int **)(in_EAX + 0x1c),0x13,5);
  (**(code **)(**(int **)(in_EAX + 0x1c) + 0xe4))(*(int **)(in_EAX + 0x1c),0x14,6);
  local_8 = (int *)0x0;
  local_c = (int *)0x0;
  (**(code **)(**(int **)(in_EAX + 0x1c) + 0x98))(*(int **)(in_EAX + 0x1c),0,&local_8);
  (**(code **)(**(int **)(in_EAX + 0x1c) + 0xa0))(*(int **)(in_EAX + 0x1c),&local_c);
  if (*(int *)(in_EAX + 0x148c) != *(int *)(in_EAX + 0x1490)) {
    local_10 = 0;
    if (*(int *)(in_EAX + 0x1490) - *(int *)(in_EAX + 0x148c) >> 2 != 0) {
      do {
        piVar1 = *(int **)(*(int *)(in_EAX + 0x148c) + local_10 * 4);
        if (((uint)piVar1[10] >> 0xe & 1) != 0) {
          (**(code **)(*piVar1 + 0x134))(0,0);
        }
        puVar2 = (undefined4 *)piVar1[0x19];
        for (puVar3 = (undefined4 *)*puVar2; puVar3 != puVar2; puVar3 = (undefined4 *)*puVar3) {
          FUN_00745bd0(0,0);
        }
        iVar4 = *(int *)(*(int *)(in_EAX + 0x148c) + local_10 * 4);
        uVar7 = *(uint *)(iVar4 + 0x28);
        if ((uVar7 & 0x20000) != 0) {
          *(uint *)(iVar4 + 0x28) = uVar7 ^ 0x20000;
        }
        local_10 = local_10 + 1;
      } while (local_10 < (uint)(*(int *)(in_EAX + 0x1490) - *(int *)(in_EAX + 0x148c) >> 2));
    }
    pvVar5 = *(void **)(in_EAX + 0x148c);
    if (pvVar5 != *(void **)(in_EAX + 0x1490)) {
      FID_conflict__memcpy(pvVar5,*(void **)(in_EAX + 0x1490),0);
      *(void **)(in_EAX + 0x1490) = pvVar5;
    }
  }
  if (*(int *)(in_EAX + 0x149c) != *(int *)(in_EAX + 0x14a0)) {
    uVar7 = 0;
    if (*(int *)(in_EAX + 0x14a0) - *(int *)(in_EAX + 0x149c) >> 2 != 0) {
      do {
        piVar1 = *(int **)(*(int *)(in_EAX + 0x149c) + uVar7 * 4);
        if (((uint)piVar1[10] >> 0xe & 1) != 0) {
          (**(code **)(*piVar1 + 0x134))(0,0);
        }
        iVar4 = *(int *)(*(int *)(in_EAX + 0x149c) + uVar7 * 4);
        uVar6 = *(uint *)(iVar4 + 0x28);
        if ((uVar6 & 0x20000) != 0) {
          *(uint *)(iVar4 + 0x28) = uVar6 ^ 0x20000;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < (uint)(*(int *)(in_EAX + 0x14a0) - *(int *)(in_EAX + 0x149c) >> 2));
    }
    pvVar5 = *(void **)(in_EAX + 0x149c);
    if (pvVar5 != *(void **)(in_EAX + 0x14a0)) {
      FID_conflict__memcpy(pvVar5,*(void **)(in_EAX + 0x14a0),0);
      *(void **)(in_EAX + 0x14a0) = pvVar5;
    }
  }
  (**(code **)(**(int **)(in_EAX + 0x1c) + 0x94))(*(int **)(in_EAX + 0x1c),0,local_8);
  (**(code **)(**(int **)(in_EAX + 0x1c) + 0x9c))(*(int **)(in_EAX + 0x1c),local_c);
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
    local_8 = (int *)0x0;
  }
  if (local_c != (int *)0x0) {
    (**(code **)(*local_c + 8))(local_c);
    local_c = (int *)0x0;
  }
  (**(code **)(**(int **)(in_EAX + 0x1c) + 0xe4))(*(int **)(in_EAX + 0x1c),0x13,local_14);
  (**(code **)(**(int **)(in_EAX + 0x1c) + 0xe4))(*(int **)(in_EAX + 0x1c),0x14,local_18);
  return;
}

