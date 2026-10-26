
void FUN_006c16d0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 in_EAX;
  uint uVar6;
  int iVar7;
  int *piVar8;
  uint local_14;
  int local_10;
  
  *(undefined4 *)(param_1 + 0xb4) = in_EAX;
  *(undefined4 *)(param_1 + 0xac) = 2;
  switch(*(undefined4 *)(param_1 + 0xb0)) {
  case 0:
    FUN_006c18e0(param_1);
    break;
  case 1:
    FUN_006c2680(param_1);
    break;
  case 2:
    FUN_006c68c0();
    FUN_006c7880();
    break;
  case 3:
    FUN_006c2950(param_1);
    break;
  case 4:
    FUN_006c2d30(param_1);
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0xa8) + 0xcc);
  uVar5 = (*(int *)(param_1 + 0xbc) - *(int *)(param_1 + 0xb8)) / 0x28;
  if (iVar1 != 0) {
    FUN_00408920(iVar1,uVar5);
  }
  local_14 = 0;
  if (uVar5 != 0) {
    local_10 = 0;
    do {
      piVar8 = (int *)(*(int *)(param_1 + 0xb8) + local_10);
      iVar1 = *(int *)(*(int *)(param_1 + 0xa8) + 0xcc);
      iVar2 = *piVar8;
      if ((((iVar1 == 0) || ((int)local_14 < 0)) ||
          (*(int *)(iVar1 + 0xac) - *(int *)(iVar1 + 0xa8) >> 2 <= (int)local_14)) ||
         (iVar7 = *(int *)(*(int *)(iVar1 + 0xa8) + local_14 * 4), iVar7 == 0)) {
        iVar7 = 0;
      }
      else {
        *(int *)(iVar7 + 0x20) = iVar2;
        uVar6 = iVar2 + 1;
        if (uVar6 <= *(uint *)(iVar1 + 0xe4)) {
          uVar6 = *(uint *)(iVar1 + 0xe4);
        }
        *(uint *)(iVar1 + 0xe4) = uVar6;
      }
      FUN_00757800(piVar8 + 1);
      *(int *)(iVar7 + 0x154) = piVar8[9];
      if ((char)piVar8[8] == '\0') {
        *(uint *)(iVar7 + 0x28) = *(uint *)(iVar7 + 0x28) | 4;
      }
      else if ((*(uint *)(iVar7 + 0x28) & 4) != 0) {
        *(uint *)(iVar7 + 0x28) = *(uint *)(iVar7 + 0x28) ^ 4;
      }
      local_10 = local_10 + 0x28;
      local_14 = local_14 + 1;
    } while (local_14 < uVar5);
  }
  piVar8 = *(int **)(param_1 + 0xa8);
  puVar3 = (undefined4 *)piVar8[0x19];
  for (puVar4 = (undefined4 *)*puVar3; puVar4 != puVar3; puVar4 = (undefined4 *)*puVar4) {
    iVar1 = puVar4[2];
    if ((*(int *)(iVar1 + 0x60) != 0) && ((*(int **)(iVar1 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar1 + 0x1c) + 0x30))(iVar1);
    }
  }
  (**(code **)(*piVar8 + 0x128))();
  if (*(int *)(*(int *)(param_1 + 0xa8) + 0xcc) != 0) {
    FUN_00749d00();
    return;
  }
  FUN_00749d00();
  return;
}

