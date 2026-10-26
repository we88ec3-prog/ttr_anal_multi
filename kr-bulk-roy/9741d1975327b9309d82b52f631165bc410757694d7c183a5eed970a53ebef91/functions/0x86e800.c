
/* WARNING: Removing unreachable block (ram,0x0086e913) */
/* WARNING: Removing unreachable block (ram,0x0086e917) */
/* WARNING: Removing unreachable block (ram,0x0086e91b) */
/* WARNING: Removing unreachable block (ram,0x0086e921) */
/* WARNING: Removing unreachable block (ram,0x0086e92f) */
/* WARNING: Removing unreachable block (ram,0x0086e95b) */
/* WARNING: Removing unreachable block (ram,0x0086e947) */
/* WARNING: Removing unreachable block (ram,0x0086e965) */
/* WARNING: Removing unreachable block (ram,0x0086e984) */
/* WARNING: Removing unreachable block (ram,0x0086e98e) */

void FUN_0086e800(int *param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  int in_ECX;
  undefined4 *puVar9;
  int *piVar10;
  char *local_50 [3];
  int local_44 [2];
  int *local_3c;
  int local_38;
  undefined4 *local_34;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00927ef8;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_34 = (undefined4 *)((*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 0xc)) / 0x1c);
  local_3c = param_1;
  local_38 = in_ECX;
  local_14 = uVar4;
  if (local_34 != (undefined4 *)0x0) {
    local_44[1] = 0;
    do {
      puVar5 = (undefined4 *)(*(int *)(in_ECX + 0xc) + local_44[1]);
      if (0xf < (uint)puVar5[5]) {
        puVar5 = (undefined4 *)*puVar5;
      }
      iVar6 = (**(code **)(*local_3c + 0x34))(local_3c,puVar5,uVar4);
      local_44[0] = iVar6;
      if ((iVar6 != 0) && (iVar7 = (**(code **)(*local_3c + 0xf0))(local_3c,iVar6), iVar7 == 0)) {
        piVar10 = *(int **)(in_ECX + 0x48);
        if (local_44 < piVar10) {
          piVar2 = *(int **)(in_ECX + 0x44);
          if (local_44 < piVar2) goto LAB_0086e8ce;
          if (piVar10 == *(int **)(in_ECX + 0x4c)) {
            FUN_00797930();
          }
          if (*(undefined4 **)(in_ECX + 0x48) != (undefined4 *)0x0) {
            **(undefined4 **)(in_ECX + 0x48) =
                 *(undefined4 *)(*(int *)(in_ECX + 0x44) + ((int)local_44 - (int)piVar2 >> 2) * 4);
          }
        }
        else {
LAB_0086e8ce:
          if (piVar10 == *(int **)(in_ECX + 0x4c)) {
            FUN_00797930();
          }
          if (*(int **)(in_ECX + 0x48) != (int *)0x0) {
            **(int **)(in_ECX + 0x48) = iVar6;
          }
        }
        *(int *)(in_ECX + 0x48) = *(int *)(in_ECX + 0x48) + 4;
      }
      local_44[1] = local_44[1] + 0x1c;
      local_34 = (undefined4 *)((int)local_34 + -1);
    } while (local_34 != (undefined4 *)0x0);
  }
  local_34 = *(undefined4 **)(in_ECX + 0x10);
  puVar5 = *(undefined4 **)(in_ECX + 0xc);
  if (puVar5 != local_34) {
    puVar3 = *(undefined4 **)(in_ECX + 0x10);
    in_ECX = local_38;
    for (puVar9 = puVar5; local_38 = in_ECX, puVar9 != puVar3; puVar9 = puVar9 + 7) {
      if (0xf < (uint)puVar9[5]) {
        FUN_0089120c(*puVar9);
      }
      puVar9[5] = 0xf;
      puVar9[4] = 0;
      *(undefined1 *)puVar9 = 0;
      in_ECX = local_38;
    }
    *(undefined4 **)(in_ECX + 0x10) = puVar5;
  }
  uVar4 = *(int *)(in_ECX + 0x48) - *(int *)(local_38 + 0x44) >> 2;
  local_34 = (undefined4 *)0x0;
  iVar6 = local_38;
  piVar10 = local_3c;
  if (uVar4 != 0) {
    do {
      if (*(int *)(*(int *)(iVar6 + 0x44) + (int)local_34 * 4) != 0) {
        (**(code **)(*piVar10 + 0x14))
                  (piVar10,*(undefined4 *)(*(int *)(iVar6 + 0x44) + (int)local_34 * 4),local_50);
        local_1c = 0xf;
        local_20 = 0;
        local_30 = local_30 & 0xffffff00;
        pcVar8 = local_50[0];
        do {
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        FUN_00402a70(local_50[0],(int)pcVar8 - (int)(local_50[0] + 1));
        local_8 = 0;
        FUN_00440c60();
        local_8 = 0xffffffff;
        if (0xf < local_1c) {
          FUN_0089120c(local_30);
        }
        local_1c = 0xf;
        local_20 = 0;
        local_30 = local_30 & 0xffffff00;
        iVar6 = local_38;
        piVar10 = local_3c;
      }
      local_34 = (undefined4 *)((int)local_34 + 1);
    } while (local_34 < uVar4);
  }
  if (*(int *)(iVar6 + 0xc) != *(int *)(iVar6 + 0x10)) {
    FUN_00403040(*(int *)(iVar6 + 0xc),0,0xffffffff);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

