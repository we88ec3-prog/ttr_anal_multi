
void FUN_007825d0(int *param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 **ppuVar3;
  undefined4 **ppuVar4;
  uint uVar5;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  char *pcVar9;
  int in_ECX;
  uint uVar10;
  int *piVar11;
  char ****ppppcVar12;
  undefined4 *puVar13;
  uint *puVar14;
  int local_78;
  int local_70;
  int local_60 [2];
  int local_58;
  undefined4 local_50;
  undefined4 *local_44;
  undefined4 *local_40;
  undefined4 *local_3c;
  int local_38;
  char ***local_34 [4];
  int local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009153b8;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_20 = 0xf;
  local_24 = 0;
  local_34[0] = (char ***)((uint)local_34[0] & 0xffffff00);
  local_8 = 0;
  local_78 = 0;
  puVar13 = (undefined4 *)(*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4) >> 2);
  local_70 = 0;
  *(undefined4 **)(in_ECX + 0x60) = puVar13;
  local_3c = (undefined4 *)0x0;
  local_44 = puVar13;
  local_38 = in_ECX;
  local_18 = uVar5;
  if (puVar13 != (undefined4 *)0x0) {
    do {
      if ((*(byte *)((int)param_1 + *(int *)(*param_1 + 4) + 0xc) & 6) == 0) {
        (**(code **)(**(int **)((int)param_1 + *(int *)(*param_1 + 4) + 0x38) + 0x28))
                  (local_60,0,0,1,2,uVar5);
      }
      else {
        local_60[0] = -1;
        local_58 = 0;
      }
      local_70 = local_58;
      local_78 = local_60[0];
      if ((undefined4 *)(*(int *)(local_38 + 8) - *(int *)(local_38 + 4) >> 2) <= local_3c) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db7d("invalid vector<T> subscript");
      }
      piVar2 = *(int **)(*(int *)(local_38 + 4) + (int)local_3c * 4);
      if ((uint)piVar2[7] < 0x10) {
        piVar11 = piVar2 + 2;
      }
      else {
        piVar11 = (int *)piVar2[2];
      }
      piVar6 = piVar11;
      do {
        iVar8 = *piVar6;
        piVar6 = (int *)((int)piVar6 + 1);
      } while ((char)iVar8 != '\0');
      FUN_00402a70(piVar11,(int)piVar6 - (int)((int)piVar11 + 1));
      puVar7 = (undefined4 *)FUN_00891268(0x18);
      if (puVar7 == (undefined4 *)0x0) {
        puVar7 = (undefined4 *)0x0;
      }
      else {
        *puVar7 = 0;
        puVar7[1] = 0;
        puVar7[2] = 0;
        puVar7[3] = 0;
        puVar7[4] = 0;
        puVar7[5] = 0;
      }
      local_40 = puVar7;
      iVar8 = (**(code **)(*piVar2 + 4))();
      *puVar7 = *(undefined4 *)(iVar8 + 4);
      puVar7[4] = local_24 + 1;
      pcVar9 = (char *)FUN_0087dc3d(local_24 + 1);
      puVar7[5] = pcVar9;
      ppppcVar12 = (char ****)local_34[0];
      if (local_20 < 0x10) {
        ppppcVar12 = local_34;
      }
      do {
        cVar1 = *(char *)ppppcVar12;
        *pcVar9 = cVar1;
        pcVar9 = pcVar9 + 1;
        ppppcVar12 = (char ****)((int)ppppcVar12 + 1);
      } while (cVar1 != '\0');
      puVar7[2] = local_58 + local_60[0];
      iVar8 = (**(code **)(*piVar2 + 0x14))(local_38);
      if (iVar8 == 0) {
        if (puVar7[5] != 0) {
          FUN_00891d3d(puVar7[5]);
        }
        FUN_0089120c(puVar7);
      }
      else {
        if ((*(byte *)((int)param_1 + *(int *)(*param_1 + 4) + 0xc) & 6) == 0) {
          (**(code **)(**(int **)((int)param_1 + *(int *)(*param_1 + 4) + 0x38) + 0x28))
                    (local_60,0,0,1,2);
          local_70 = local_58;
          local_78 = local_60[0];
        }
        else {
          local_78 = -1;
          local_70 = 0;
          local_50 = 0;
        }
        iVar8 = local_38;
        puVar7[3] = (local_70 - puVar7[2]) + local_78;
        ppuVar3 = *(undefined4 ***)(local_38 + 0x78);
        if (&local_40 < ppuVar3) {
          ppuVar4 = *(undefined4 ***)(local_38 + 0x74);
          if (ppuVar4 <= &local_40) {
            if (ppuVar3 == *(undefined4 ***)(local_38 + 0x7c)) {
              FUN_00797930();
            }
            if (*(undefined4 **)(iVar8 + 0x78) != (undefined4 *)0x0) {
              **(undefined4 **)(iVar8 + 0x78) =
                   *(undefined4 *)
                    (*(int *)(iVar8 + 0x74) + ((int)&local_40 - (int)ppuVar4 >> 2) * 4);
            }
            *(int *)(iVar8 + 0x78) = *(int *)(iVar8 + 0x78) + 4;
            puVar13 = local_44;
            goto LAB_0078284a;
          }
        }
        if (ppuVar3 == *(undefined4 ***)(local_38 + 0x7c)) {
          FUN_00797930();
        }
        if (*(undefined4 **)(iVar8 + 0x78) != (undefined4 *)0x0) {
          **(undefined4 **)(iVar8 + 0x78) = puVar7;
        }
        *(int *)(iVar8 + 0x78) = *(int *)(iVar8 + 0x78) + 4;
        puVar13 = local_44;
      }
LAB_0078284a:
      local_3c = (undefined4 *)((int)local_3c + 1);
    } while (local_3c < puVar13);
  }
  local_40 = (undefined4 *)0x0;
  local_44 = (undefined4 *)(*(int *)(local_38 + 0x18) - *(int *)(local_38 + 0x14) >> 2);
  puVar13 = local_44;
  if (local_44 != (undefined4 *)0x0) {
    do {
      local_44 = puVar13;
      if ((*(byte *)((int)param_1 + *(int *)(*param_1 + 4) + 0xc) & 6) == 0) {
        (**(code **)(**(int **)((int)param_1 + *(int *)(*param_1 + 4) + 0x38) + 0x28))
                  (local_60,0,0,1,2);
        local_78 = local_60[0];
      }
      else {
        local_78 = -1;
        local_58 = 0;
      }
      local_70 = local_58;
      piVar2 = *(int **)(*(int *)(local_38 + 0x14) + (int)local_40 * 4);
      if ((uint)piVar2[7] < 0x10) {
        piVar11 = piVar2 + 2;
      }
      else {
        piVar11 = (int *)piVar2[2];
      }
      piVar6 = piVar11;
      do {
        iVar8 = *piVar6;
        piVar6 = (int *)((int)piVar6 + 1);
      } while ((char)iVar8 != '\0');
      FUN_00402a70(piVar11,(int)piVar6 - (int)((int)piVar11 + 1));
      puVar13 = (undefined4 *)FUN_00891268(0x18);
      if (puVar13 == (undefined4 *)0x0) {
        puVar13 = (undefined4 *)0x0;
      }
      else {
        *puVar13 = 0;
        puVar13[1] = 0;
        puVar13[2] = 0;
        puVar13[3] = 0;
        puVar13[4] = 0;
        puVar13[5] = 0;
      }
      local_3c = puVar13;
      iVar8 = (**(code **)(*piVar2 + 4))();
      *puVar13 = *(undefined4 *)(iVar8 + 4);
      puVar13[4] = local_24 + 1;
      pcVar9 = (char *)FUN_0087dc3d(local_24 + 1);
      puVar13[5] = pcVar9;
      ppppcVar12 = (char ****)local_34[0];
      if (local_20 < 0x10) {
        ppppcVar12 = local_34;
      }
      do {
        cVar1 = *(char *)ppppcVar12;
        *pcVar9 = cVar1;
        pcVar9 = pcVar9 + 1;
        ppppcVar12 = (char ****)((int)ppppcVar12 + 1);
      } while (cVar1 != '\0');
      puVar13[2] = local_58 + local_78;
      puVar13[1] = piVar2;
      iVar8 = (**(code **)(*piVar2 + 0x14))(local_38);
      if (iVar8 == 0) {
        if (puVar13[5] != 0) {
          FUN_00891d3d(puVar13[5]);
        }
        FUN_0089120c(puVar13);
      }
      else {
        if ((*(byte *)((int)param_1 + *(int *)(*param_1 + 4) + 0xc) & 6) == 0) {
          (**(code **)(**(int **)((int)param_1 + *(int *)(*param_1 + 4) + 0x38) + 0x28))
                    (local_60,0,0,1,2);
          local_70 = local_58;
          local_78 = local_60[0];
        }
        else {
          local_78 = -1;
          local_70 = 0;
          local_50 = 0;
        }
        iVar8 = local_38;
        puVar14 = (uint *)(local_38 + 0x74);
        puVar13[3] = (local_70 - puVar13[2]) + local_78;
        ppuVar3 = *(undefined4 ***)(local_38 + 0x78);
        if ((&local_3c < ppuVar3) && (ppuVar4 = (undefined4 **)*puVar14, ppuVar4 <= &local_3c)) {
          if (ppuVar3 == *(undefined4 ***)(local_38 + 0x7c)) {
            uVar5 = (int)ppuVar3 - (int)ppuVar4 >> 2;
            if (0x3ffffffe < uVar5) {
LAB_00782b15:
                    /* WARNING: Subroutine does not return */
              FUN_0087db30("vector<T> too long");
            }
            uVar5 = uVar5 + 1;
            uVar10 = (int)*(undefined4 ***)(local_38 + 0x7c) - (int)ppuVar4 >> 2;
            if (uVar10 < uVar5) {
              if (0x3fffffff - (uVar10 >> 1) < uVar10) {
                uVar10 = 0;
              }
              else {
                uVar10 = uVar10 + (uVar10 >> 1);
              }
              if (uVar10 < uVar5) {
                uVar10 = uVar5;
              }
              FUN_00797980(uVar10);
            }
          }
          if (*(undefined4 **)(iVar8 + 0x78) != (undefined4 *)0x0) {
            **(undefined4 **)(iVar8 + 0x78) =
                 *(undefined4 *)(*puVar14 + ((int)&local_3c - (int)ppuVar4 >> 2) * 4);
            *(int *)(iVar8 + 0x78) = *(int *)(iVar8 + 0x78) + 4;
            *(int *)(local_38 + 0x60) = *(int *)(local_38 + 0x60) + 1;
            goto LAB_00782aec;
          }
        }
        else {
          if (ppuVar3 == *(undefined4 ***)(local_38 + 0x7c)) {
            uVar5 = (int)((int)ppuVar3 - *puVar14) >> 2;
            if (0x3ffffffe < uVar5) goto LAB_00782b15;
            uVar5 = uVar5 + 1;
            uVar10 = (int)((int)*(undefined4 ***)(local_38 + 0x7c) - *puVar14) >> 2;
            if (uVar10 < uVar5) {
              if (0x3fffffff - (uVar10 >> 1) < uVar10) {
                uVar10 = 0;
              }
              else {
                uVar10 = uVar10 + (uVar10 >> 1);
              }
              if (uVar10 < uVar5) {
                uVar10 = uVar5;
              }
              FUN_00797980(uVar10);
            }
          }
          if (*(undefined4 **)(iVar8 + 0x78) != (undefined4 *)0x0) {
            **(undefined4 **)(iVar8 + 0x78) = puVar13;
          }
        }
        *(int *)(iVar8 + 0x78) = *(int *)(iVar8 + 0x78) + 4;
        *(int *)(local_38 + 0x60) = *(int *)(local_38 + 0x60) + 1;
      }
LAB_00782aec:
      local_40 = (undefined4 *)((int)local_40 + 1);
      puVar13 = local_44;
    } while ((local_40 != local_44) ||
            (puVar13 = (undefined4 *)(*(int *)(local_38 + 0x18) - *(int *)(local_38 + 0x14) >> 2),
            puVar13 != local_44));
  }
  *(int *)(local_38 + 100) = local_78 + local_70;
  if (0xf < local_20) {
    FUN_0089120c(local_34[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

