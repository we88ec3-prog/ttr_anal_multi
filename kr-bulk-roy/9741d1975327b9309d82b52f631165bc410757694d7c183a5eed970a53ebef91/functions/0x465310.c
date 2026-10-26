
void FUN_00465310(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  undefined4 *unaff_EBX;
  uint uVar9;
  int *piVar10;
  int iVar11;
  int *local_2c;
  int local_28;
  undefined4 *local_24;
  undefined4 *local_20;
  undefined4 *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  int *local_c;
  
  local_1c = *(undefined4 **)(param_1 + 0x174);
  puVar2 = (undefined4 *)*local_1c;
  do {
    if (puVar2 == local_1c) {
      if (*(int *)(param_1 + 0xf4) == 0) {
        local_28 = 0;
      }
      else {
        local_28 = FUN_008fed10();
      }
      local_c = *(int **)(param_1 + 0x174);
      piVar10 = (int *)*local_c;
      if (piVar10 != local_c) {
        do {
          local_20 = *(undefined4 **)(*(int *)(param_1 + 0x110) + piVar10[0xe] * 4);
          piVar7 = (int *)FUN_004655f0(piVar10[4]);
          if ((local_20 != (undefined4 *)0x0) && (piVar7 != (int *)0x0)) {
            if ((piVar10[0xe] < *(int *)(param_1 + 0x134)) ||
               (iVar8 = piVar10[0xe] - *(int *)(param_1 + 0x134), *(int *)(param_1 + 0x138) <= iVar8
               )) {
              (**(code **)(*piVar7 + 0x94))(0);
            }
            else {
              iVar11 = *(int *)(param_1 + 0xa4);
              if (*(char *)(param_1 + 0x120) != '\0') {
                iVar11 = iVar11 + 0xf;
              }
              local_10 = iVar8 * local_28 + *(int *)(param_1 + 0xa8);
              local_2c = (int *)0x0;
              local_18 = 0;
              local_1c = (undefined4 *)0x0;
              local_14 = 0;
              if ((uint)local_20[5] < 8) {
                local_24 = local_20;
              }
              else {
                local_24 = (undefined4 *)*local_20;
              }
              (**(code **)(**(int **)(param_1 + 0xf4) + 0x30))
                        (&local_2c,&local_18,local_24,piVar10[0x11]);
              if (7 < (uint)unaff_EBX[5]) {
                unaff_EBX = (undefined4 *)*unaff_EBX;
              }
              iVar8 = piVar10[0x12];
              (**(code **)(**(int **)(param_1 + 0xf4) + 0x30))(&local_2c,&local_24,unaff_EBX);
              (**(code **)(*piVar7 + 0x94))(1);
              FUN_00749c50();
              FUN_00768150();
              FUN_00749d00();
              iVar8 = (iVar11 + iVar8) - piVar7[2];
              piVar7[2] = piVar7[2] + iVar8;
              piVar7[4] = piVar7[4] + iVar8;
              iVar8 = piVar7[3];
              piVar7[3] = piVar7[3] + (local_10 - iVar8);
              piVar7[5] = piVar7[5] + (local_10 - iVar8);
              FUN_00746f70();
              FUN_007444b0(0xbf6c);
              if (piVar7[0x26] != 0) {
                *(undefined4 *)(piVar7[0x26] + 0xc) = 0x32eeeeee;
              }
            }
          }
          if (*(char *)((int)piVar10 + 0x4d) == '\0') {
            piVar7 = (int *)piVar10[2];
            if (*(char *)((int)piVar7 + 0x4d) == '\0') {
              cVar1 = *(char *)(*piVar7 + 0x4d);
              piVar10 = piVar7;
              piVar7 = (int *)*piVar7;
              while (cVar1 == '\0') {
                cVar1 = *(char *)(*piVar7 + 0x4d);
                piVar10 = piVar7;
                piVar7 = (int *)*piVar7;
              }
            }
            else {
              cVar1 = *(char *)(piVar10[1] + 0x4d);
              piVar5 = (int *)piVar10[1];
              piVar7 = piVar10;
              while ((piVar10 = piVar5, cVar1 == '\0' && (piVar7 == (int *)piVar10[2]))) {
                cVar1 = *(char *)(piVar10[1] + 0x4d);
                piVar5 = (int *)piVar10[1];
                piVar7 = piVar10;
              }
            }
          }
        } while (piVar10 != local_c);
      }
      return;
    }
    piVar10 = *(int **)(param_1 + 0x110);
    uVar6 = *(int *)(param_1 + 0x114) - (int)piVar10 >> 2;
    uVar9 = 0;
    if (uVar6 != 0) {
      iVar8 = 0;
      do {
        iVar11 = *(int *)(*piVar10 + 0x10) + iVar8;
        if ((int)puVar2[0xf] < iVar11) {
          puVar2[0xe] = uVar9;
          puVar2[0x11] = puVar2[0xf] - iVar8;
          puVar2[0x12] = puVar2[0x10] - iVar8;
          local_2c = piVar10;
          break;
        }
        uVar9 = uVar9 + 1;
        piVar10 = piVar10 + 1;
        iVar8 = iVar11;
        local_2c = piVar10;
      } while (uVar9 < uVar6);
    }
    if (*(char *)((int)puVar2 + 0x4d) == '\0') {
      puVar3 = (undefined4 *)puVar2[2];
      if (*(char *)((int)puVar3 + 0x4d) == '\0') {
        cVar1 = *(char *)((int)*puVar3 + 0x4d);
        puVar2 = puVar3;
        puVar3 = (undefined4 *)*puVar3;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar3 + 0x4d);
          puVar2 = puVar3;
          puVar3 = (undefined4 *)*puVar3;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar2[1] + 0x4d);
        puVar4 = (undefined4 *)puVar2[1];
        puVar3 = puVar2;
        while ((puVar2 = puVar4, cVar1 == '\0' && (puVar3 == (undefined4 *)puVar2[2]))) {
          cVar1 = *(char *)((int)puVar2[1] + 0x4d);
          puVar4 = (undefined4 *)puVar2[1];
          puVar3 = puVar2;
        }
      }
    }
  } while( true );
}

