
void FUN_0040b670(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int *unaff_ESI;
  uint local_8;
  
  local_8 = 0;
  if (unaff_ESI[2] - unaff_ESI[1] >> 2 != 0) {
    do {
      if (*(int *)(unaff_ESI[1] + local_8 * 4) != 0) {
        piVar1 = *(int **)(unaff_ESI[1] + local_8 * 4);
        uVar4 = piVar1[10];
        if ((uVar4 >> 0x15 & 1) == 0) {
          if ((uVar4 >> 0x16 & 1) == 0) {
            iVar3 = *piVar1;
            uVar2 = (**(code **)(*unaff_ESI + 0x10))();
            (**(code **)(iVar3 + 0xc0))(uVar2);
          }
          FUN_00745590();
          FUN_00745600();
        }
      }
      local_8 = local_8 + 1;
    } while (local_8 < (uint)(unaff_ESI[2] - unaff_ESI[1] >> 2));
  }
  if (param_1 != (int *)0x0) {
    iVar3 = (**(code **)(*param_1 + 4))();
    uVar4 = 0;
    if (iVar3 == 55000) {
      if (unaff_ESI[2] - unaff_ESI[1] >> 2 != 0) {
        do {
          if (*(int *)(unaff_ESI[1] + uVar4 * 4) != 0) {
            iVar3 = *(int *)(unaff_ESI[1] + uVar4 * 4);
            *(uint *)(iVar3 + 0x28) = *(uint *)(iVar3 + 0x28) | 0x10;
            if ((*(uint *)(iVar3 + 0x28) & 0x20) != 0) {
              *(uint *)(iVar3 + 0x28) = *(uint *)(iVar3 + 0x28) ^ 0x20;
            }
            if ((*(uint *)(iVar3 + 0x28) & 0x40) != 0) {
              *(uint *)(iVar3 + 0x28) = *(uint *)(iVar3 + 0x28) ^ 0x40;
            }
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < (uint)(unaff_ESI[2] - unaff_ESI[1] >> 2));
      }
      iVar3 = unaff_ESI[1];
      uVar4 = 0;
      if (unaff_ESI[2] - iVar3 >> 2 != 0) {
        do {
          (**(code **)(*param_1 + 0x70))(*(undefined4 *)(iVar3 + uVar4 * 4));
          iVar3 = unaff_ESI[1];
          uVar4 = uVar4 + 1;
        } while (uVar4 < (uint)(unaff_ESI[2] - iVar3 >> 2));
        return;
      }
    }
    else {
      if (unaff_ESI[2] - unaff_ESI[1] >> 2 != 0) {
        do {
          if (*(int *)(unaff_ESI[1] + uVar4 * 4) != 0) {
            iVar3 = *(int *)(unaff_ESI[1] + uVar4 * 4);
            *(uint *)(iVar3 + 0x28) = *(uint *)(iVar3 + 0x28) | 0x20;
            if ((*(uint *)(iVar3 + 0x28) & 0x10) != 0) {
              *(uint *)(iVar3 + 0x28) = *(uint *)(iVar3 + 0x28) ^ 0x10;
            }
            if ((*(uint *)(iVar3 + 0x28) & 0x40) != 0) {
              *(uint *)(iVar3 + 0x28) = *(uint *)(iVar3 + 0x28) ^ 0x40;
            }
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < (uint)(unaff_ESI[2] - unaff_ESI[1] >> 2));
      }
      iVar3 = unaff_ESI[1];
      uVar4 = 0;
      if (unaff_ESI[2] - iVar3 >> 2 != 0) {
        do {
          (**(code **)(*param_1 + 0x70))(*(undefined4 *)(iVar3 + uVar4 * 4));
          iVar3 = unaff_ESI[1];
          uVar4 = uVar4 + 1;
        } while (uVar4 < (uint)(unaff_ESI[2] - iVar3 >> 2));
      }
    }
  }
  return;
}

