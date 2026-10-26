
int * FUN_00833280(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int local_18 [2];
  int *local_10;
  int *local_c;
  
  local_10 = (int *)FUN_00891268(0x14);
  if (local_10 == (int *)0x0) {
    local_10 = (int *)0x0;
  }
  else {
    *local_10 = param_1;
    local_10[1] = 0;
    local_10[2] = 0;
    local_10[3] = 0;
  }
  piVar5 = local_10;
  local_c = *(int **)(param_1 + 0x1c);
  if (*(int **)(param_1 + 0x20) != local_c) {
    do {
      local_18[1] = *local_c;
      iVar8 = *(int *)(local_18[1] + 0x14);
      piVar1 = (int *)piVar5[2];
      local_18[0] = iVar8;
      if ((local_18 < piVar1) && (piVar2 = (int *)piVar5[1], piVar2 <= local_18)) {
        iVar8 = (int)local_18 - (int)piVar2 >> 3;
        if (piVar1 == (int *)piVar5[3]) {
          uVar6 = (int)piVar1 - (int)piVar2 >> 3;
          if (0x1ffffffe < uVar6) {
LAB_008333bf:
                    /* WARNING: Subroutine does not return */
            FUN_0087db30("vector<T> too long");
          }
          uVar6 = uVar6 + 1;
          uVar7 = piVar5[3] - (int)piVar2 >> 3;
          if (uVar7 < uVar6) {
            if (0x1fffffff - (uVar7 >> 1) < uVar7) {
              uVar7 = 0;
            }
            else {
              uVar7 = uVar7 + (uVar7 >> 1);
            }
            if (uVar7 < uVar6) {
              uVar7 = uVar6;
            }
            FUN_004e7330(uVar7);
          }
        }
        puVar3 = (undefined4 *)piVar5[2];
        if (puVar3 != (undefined4 *)0x0) {
          iVar4 = piVar5[1];
          *puVar3 = *(undefined4 *)(iVar4 + iVar8 * 8);
          puVar3[1] = *(undefined4 *)(iVar4 + 4 + iVar8 * 8);
        }
      }
      else {
        if (piVar1 == (int *)piVar5[3]) {
          uVar6 = (int)piVar1 - piVar5[1] >> 3;
          if (0x1ffffffe < uVar6) goto LAB_008333bf;
          uVar6 = uVar6 + 1;
          uVar7 = piVar5[3] - piVar5[1] >> 3;
          if (uVar7 < uVar6) {
            if (0x1fffffff - (uVar7 >> 1) < uVar7) {
              uVar7 = 0;
            }
            else {
              uVar7 = uVar7 + (uVar7 >> 1);
            }
            if (uVar7 < uVar6) {
              uVar7 = uVar6;
            }
            FUN_004e7330(uVar7);
          }
        }
        piVar1 = (int *)piVar5[2];
        if (piVar1 != (int *)0x0) {
          *piVar1 = iVar8;
          piVar1[1] = local_18[1];
        }
      }
      piVar5[2] = piVar5[2] + 8;
      local_c = local_c + 1;
    } while (*(int **)(param_1 + 0x20) != local_c);
  }
  return local_10;
}

