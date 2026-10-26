
undefined4 * FUN_007ee240(int param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  char cVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  char *pcVar9;
  uint uVar10;
  char *pcVar11;
  undefined4 *local_10;
  uint local_c;
  undefined4 local_8;
  
  local_10 = (undefined4 *)FUN_00891268(0x9c);
  if (local_10 == (undefined4 *)0x0) {
    local_10 = (undefined4 *)0x0;
  }
  else {
    uVar7 = *(undefined4 *)(param_1 + 0x1c);
    uVar2 = *(undefined4 *)(param_1 + 0x20);
    local_8 = *(undefined4 *)(param_1 + 0x48);
    local_10[0x17] = 0;
    local_10[0x18] = 0;
    local_10[0x19] = 0;
    *local_10 = 0;
    local_10[1] = 0;
    local_10[2] = 0;
    local_10[3] = 0;
    local_10[4] = 0;
    local_10[5] = 0;
    local_10[6] = 0x3f800000;
    local_10[0x1b] = 0;
    local_10[0x1c] = uVar7;
    local_10[0x1d] = uVar2;
    local_10[0x24] = 0xf;
    local_10[0x23] = 0;
    *(undefined1 *)(local_10 + 0x1f) = 0;
    local_10[0x26] = local_8;
  }
  iVar6 = *(int *)(param_1 + 0xc);
  local_c = 0;
  if (*(int *)(param_1 + 0x10) - iVar6 >> 2 != 0) {
    puVar1 = local_10 + 0x17;
    do {
      uVar7 = (**(code **)(**(int **)(iVar6 + local_c * 4) + 4))();
      puVar4 = (undefined4 *)local_10[0x18];
      local_8 = uVar7;
      if ((&local_8 < puVar4) && (puVar5 = (undefined4 *)*puVar1, puVar5 <= &local_8)) {
        if (puVar4 == (undefined4 *)local_10[0x19]) {
          uVar8 = (int)puVar4 - (int)puVar5 >> 2;
          if (0x3ffffffe < uVar8) {
LAB_007ee405:
                    /* WARNING: Subroutine does not return */
            FUN_0087db30("vector<T> too long");
          }
          uVar8 = uVar8 + 1;
          uVar10 = (int)local_10[0x19] - (int)puVar5 >> 2;
          if (uVar10 < uVar8) {
            if (0x3fffffff - (uVar10 >> 1) < uVar10) {
              uVar10 = 0;
            }
            else {
              uVar10 = uVar10 + (uVar10 >> 1);
            }
            if (uVar10 < uVar8) {
              uVar10 = uVar8;
            }
            FUN_00797980(uVar10);
          }
        }
        if ((undefined4 *)local_10[0x18] != (undefined4 *)0x0) {
          *(undefined4 *)local_10[0x18] =
               *(undefined4 *)(*puVar1 + ((int)&local_8 - (int)puVar5 >> 2) * 4);
        }
      }
      else {
        if (puVar4 == (undefined4 *)local_10[0x19]) {
          uVar8 = (int)((int)puVar4 - *puVar1) >> 2;
          if (0x3ffffffe < uVar8) goto LAB_007ee405;
          uVar8 = uVar8 + 1;
          uVar10 = (int)((int)local_10[0x19] - *puVar1) >> 2;
          if (uVar10 < uVar8) {
            if (0x3fffffff - (uVar10 >> 1) < uVar10) {
              uVar10 = 0;
            }
            else {
              uVar10 = uVar10 + (uVar10 >> 1);
            }
            if (uVar10 < uVar8) {
              uVar10 = uVar8;
            }
            FUN_00797980(uVar10);
          }
        }
        if ((undefined4 *)local_10[0x18] != (undefined4 *)0x0) {
          *(undefined4 *)local_10[0x18] = uVar7;
        }
      }
      local_10[0x18] = local_10[0x18] + 4;
      iVar6 = *(int *)(param_1 + 0xc);
      local_c = local_c + 1;
    } while (local_c < (uint)(*(int *)(param_1 + 0x10) - iVar6 >> 2));
  }
  pcVar11 = (char *)(param_1 + 0x28);
  if (0xf < *(uint *)(param_1 + 0x3c)) {
    pcVar11 = *(char **)pcVar11;
  }
  local_10[0x1e] = *(undefined4 *)(param_1 + 0x24);
  pcVar9 = pcVar11;
  do {
    cVar3 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar3 != '\0');
  FUN_00402a70(pcVar11,(int)pcVar9 - (int)(pcVar11 + 1));
  return local_10;
}

