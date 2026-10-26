
void FUN_007c5840(undefined4 param_1,undefined4 param_2)

{
  uint *puVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  char *pcVar10;
  int iVar11;
  int iVar12;
  uint in_ECX;
  char *pcVar13;
  uint uVar14;
  int iVar15;
  undefined4 uVar16;
  int local_68;
  int local_64;
  undefined4 local_60;
  int local_58;
  int local_54 [6];
  undefined4 local_3c;
  uint local_38;
  undefined4 local_30;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8._0_1_ = 0xff;
  local_8._1_3_ = 0xffffff;
  puStack_c = &LAB_009323c8;
  local_10 = ExceptionList;
  uVar7 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar7;
  iVar8 = FUN_007c4af0(param_2);
  if (((iVar8 != 0) && (in_ECX < (uint)(*(int *)(iVar8 + 0x24) - *(int *)(iVar8 + 0x20) >> 2))) &&
     (iVar3 = *(int *)(*(int *)(iVar8 + 0x20) + in_ECX * 4), *(int *)(iVar3 + 0x58) == 0)) {
    puVar1 = (uint *)(iVar3 + 0x44);
    puVar9 = (undefined4 *)FUN_007c5590(local_54 + 2);
    local_8 = 0;
    if (0xf < (uint)puVar9[5]) {
      puVar9 = (undefined4 *)*puVar9;
    }
    FUN_00402b70(puVar9);
    local_8._0_1_ = 2;
    if (0xf < local_38) {
      FUN_0089120c(local_54[2],uVar7);
    }
    iVar11 = *(int *)(*(int *)(iVar8 + 0x20) + in_ECX * 4);
    pcVar13 = (char *)(iVar11 + 1);
    local_3c = 0;
    local_38 = 0xf;
    local_54[2] = local_54[2] & 0xffffff00;
    pcVar10 = pcVar13;
    do {
      cVar2 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar2 != '\0');
    FUN_00401fc0(pcVar13,(int)pcVar10 - (iVar11 + 2));
    uVar16 = 0;
    FUN_00798d70(0);
    puVar9 = (undefined4 *)FUN_007d0920(uVar16);
    if (puVar9 == (undefined4 *)0x0) {
      FUN_00402c50();
    }
    else {
      local_68 = 0;
      local_64 = 0;
      local_60 = 0;
      local_8._0_1_ = 3;
      FUN_007c6c20(puVar9,&local_68);
      local_58 = 0;
      iVar11 = local_68;
      if ((local_64 - local_68 & 0xfffffffcU) != 0) {
        do {
          iVar4 = *(int *)(iVar11 + local_58 * 4);
          local_54[1] = 0;
          if (*(int *)(iVar4 + 0x7c) - *(int *)(iVar4 + 0x78) >> 2 != 0) {
            do {
              iVar11 = (**(code **)(**(int **)(*(int *)(iVar4 + 0x78) + local_54[1] * 4) + 0xc))();
              iVar15 = 0;
              local_54[0] = iVar11;
              if (0 < *(int *)(*(int *)(iVar11 + 0x74) + 0x178)) {
                do {
                  iVar12 = FUN_00843ef0();
                  *(undefined4 *)(iVar12 + 0x24) = 0;
                  iVar15 = iVar15 + 1;
                } while (iVar15 < *(int *)(*(int *)(iVar11 + 0x74) + 0x178));
              }
              piVar5 = *(int **)(iVar3 + 0x48);
              if ((local_54 < piVar5) && (piVar6 = (int *)*puVar1, piVar6 <= local_54)) {
                if (piVar5 == *(int **)(iVar3 + 0x4c)) {
                  uVar7 = (int)piVar5 - (int)piVar6 >> 2;
                  if (0x3ffffffe < uVar7) {
LAB_007c5b37:
                    /* WARNING: Subroutine does not return */
                    FUN_0087db30("vector<T> too long");
                  }
                  uVar7 = uVar7 + 1;
                  uVar14 = (int)*(int **)(iVar3 + 0x4c) - (int)piVar6 >> 2;
                  if (uVar14 < uVar7) {
                    if (0x3fffffff - (uVar14 >> 1) < uVar14) {
                      uVar14 = 0;
                    }
                    else {
                      uVar14 = uVar14 + (uVar14 >> 1);
                    }
                    if (uVar14 < uVar7) {
                      uVar14 = uVar7;
                    }
                    FUN_00797980(uVar14);
                  }
                }
                if (*(undefined4 **)(iVar3 + 0x48) != (undefined4 *)0x0) {
                  **(undefined4 **)(iVar3 + 0x48) =
                       *(undefined4 *)(*puVar1 + ((int)local_54 - (int)piVar6 >> 2) * 4);
                }
              }
              else {
                if (piVar5 == *(int **)(iVar3 + 0x4c)) {
                  uVar7 = (int)((int)piVar5 - *puVar1) >> 2;
                  if (0x3ffffffe < uVar7) goto LAB_007c5b37;
                  uVar7 = uVar7 + 1;
                  uVar14 = (int)((int)*(int **)(iVar3 + 0x4c) - *puVar1) >> 2;
                  if (uVar14 < uVar7) {
                    if (0x3fffffff - (uVar14 >> 1) < uVar14) {
                      uVar14 = 0;
                    }
                    else {
                      uVar14 = uVar14 + (uVar14 >> 1);
                    }
                    if (uVar14 < uVar7) {
                      uVar14 = uVar7;
                    }
                    FUN_00797980(uVar14);
                  }
                }
                if (*(int **)(iVar3 + 0x48) != (int *)0x0) {
                  **(int **)(iVar3 + 0x48) = iVar11;
                }
              }
              *(int *)(iVar3 + 0x48) = *(int *)(iVar3 + 0x48) + 4;
              local_54[1] = local_54[1] + 1;
              iVar11 = local_68;
            } while ((uint)local_54[1] <
                     (uint)(*(int *)(iVar4 + 0x7c) - *(int *)(iVar4 + 0x78) >> 2));
          }
          local_58 = local_58 + 1;
        } while (local_58 != local_64 - iVar11 >> 2);
      }
      (**(code **)*puVar9)(1);
      *(undefined4 *)(*(int *)(*(int *)(iVar8 + 0x20) + in_ECX * 4) + 0x58) = 1;
      if (local_68 != 0) {
        FUN_0089120c(local_68);
      }
      local_68 = 0;
      local_64 = 0;
      local_60 = 0;
      if (0xf < local_1c) {
        FUN_0089120c(local_30);
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

