
/* WARNING: Removing unreachable block (ram,0x0058ea47) */
/* WARNING: Removing unreachable block (ram,0x0058e892) */
/* WARNING: Removing unreachable block (ram,0x0058e98a) */
/* WARNING: Removing unreachable block (ram,0x0058e8e8) */
/* WARNING: Removing unreachable block (ram,0x0058e939) */

void FUN_0058e790(int param_1)

{
  char cVar1;
  short sVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  void **ppvVar6;
  uint uVar7;
  short *psVar8;
  int iVar9;
  undefined4 *puVar10;
  short *psVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  uint uVar14;
  uint local_4c;
  uint local_38;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091f9e0;
  uVar7 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  puVar3 = *(undefined4 **)(param_1 + 0x1c);
  puVar12 = (undefined4 *)*puVar3;
  uVar14 = uVar7;
  ppvVar6 = &local_10;
  puVar5 = puVar12;
  local_10 = ExceptionList;
  do {
    do {
      while( true ) {
        do {
          ExceptionList = ppvVar6;
          local_8 = 0xffffffff;
          if (puVar12 == puVar3) {
            ExceptionList = local_10;
            __security_check_cookie(uVar7 ^ (uint)&stack0xfffffffc);
            return;
          }
          psVar11 = (short *)(puVar12 + 3);
          if (7 < (uint)puVar12[8]) {
            psVar11 = *(short **)psVar11;
          }
          psVar8 = psVar11;
          do {
            sVar2 = *psVar8;
            psVar8 = psVar8 + 1;
          } while (sVar2 != 0);
          FUN_00402160(psVar11,(int)psVar8 - (int)(psVar11 + 1) >> 1);
          local_8 = 0;
          if (((*(int *)(puVar12[10] + 4) != 0) &&
              (piVar4 = *(int **)(*(int *)(puVar12[10] + 4) + 0x1c), piVar4 != (int *)0x0)) &&
             (iVar9 = (**(code **)(*piVar4 + 8))(uVar14), iVar9 == 0x103c8)) {
            FUN_00590230();
            local_8._0_1_ = 1;
            FUN_0058ec10(param_1,L"DockSideMode");
            local_8._0_1_ = 0;
            if (7 < local_38) {
              FUN_0089120c(local_4c);
            }
            FUN_0040ef80();
            local_8._0_1_ = 2;
            FUN_0058ec10(param_1,L"DockSideLockL");
            local_8._0_1_ = 0;
            if (7 < local_38) {
              FUN_0089120c(local_4c);
            }
            FUN_0040ef80();
            local_8._0_1_ = 3;
            FUN_0058ec10(param_1,L"DockSideLockR");
            local_8._0_1_ = 0;
            if (7 < local_38) {
              FUN_0089120c(local_4c);
            }
            FUN_0040ef80();
            local_8._0_1_ = 4;
            FUN_0058ec10(param_1,L"DockSideLockT");
            local_8._0_1_ = 0;
            if (7 < local_38) {
              FUN_0089120c(local_4c);
            }
            FUN_0040ef80();
            local_8 = CONCAT31(local_8._1_3_,5);
            FUN_0058ec10(param_1,L"DockSideLockB");
            if (7 < local_38) {
              FUN_0089120c(local_4c);
            }
            local_38 = 7;
            local_4c = local_4c & 0xffff0000;
            puVar12 = puVar5;
          }
          ppvVar6 = ExceptionList;
        } while (*(char *)((int)puVar12 + 0x2d) != '\0');
        puVar5 = (undefined4 *)puVar12[2];
        if (*(char *)((int)puVar5 + 0x2d) != '\0') break;
        cVar1 = *(char *)((int)*puVar5 + 0x2d);
        puVar12 = puVar5;
        puVar13 = (undefined4 *)*puVar5;
        while (puVar5 = puVar12, cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar13 + 0x2d);
          puVar12 = puVar13;
          puVar13 = (undefined4 *)*puVar13;
        }
      }
      puVar5 = (undefined4 *)puVar12[1];
      puVar13 = puVar12;
      puVar12 = puVar5;
    } while (*(char *)((int)puVar5 + 0x2d) != '\0');
    do {
      puVar10 = puVar5;
      puVar12 = puVar10;
      puVar5 = puVar10;
      if (puVar13 != (undefined4 *)puVar10[2]) break;
      puVar12 = (undefined4 *)puVar10[1];
      puVar5 = puVar12;
      puVar13 = puVar10;
    } while (*(char *)((int)puVar12 + 0x2d) == '\0');
  } while( true );
}

