
void FUN_00554b30(void)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  char *pcVar10;
  int *piVar11;
  undefined4 uVar12;
  char *pcVar13;
  undefined4 *local_50;
  undefined4 *local_4c;
  undefined4 local_48;
  undefined4 local_40;
  int *local_3c;
  int *local_38;
  uint local_34;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 *local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00929618;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar5;
  piVar6 = (int *)FUN_0072e2e0("Category");
joined_r0x00554b6f:
  do {
    local_38 = piVar6;
    if (piVar6 == (int *)0x0) {
      ExceptionList = local_10;
      __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
      return;
    }
    iVar7 = (**(code **)(*piVar6 + 0x14))(uVar5);
    if (iVar7 != 0) {
      for (iVar2 = *(int *)(iVar7 + 0x94); iVar2 != iVar7 + 0x44; iVar2 = *(int *)(iVar2 + 0x50)) {
        pcVar13 = (char *)(iVar2 + 0x14);
        if (0xf < *(uint *)(iVar2 + 0x28)) {
          pcVar13 = *(char **)pcVar13;
        }
        iVar8 = __stricmp(pcVar13,"Num");
        if (iVar8 == 0) {
          if (iVar2 != 0) {
            puVar9 = (undefined4 *)(iVar2 + 0x30);
            if (0xf < *(uint *)(iVar2 + 0x44)) {
              puVar9 = (undefined4 *)*puVar9;
            }
            if (puVar9 != (undefined4 *)0x0) {
              local_40 = FUN_008917b4(puVar9);
              goto LAB_00554bd0;
            }
          }
          break;
        }
      }
      local_40 = 0;
LAB_00554bd0:
      local_50 = (undefined4 *)0x0;
      local_4c = (undefined4 *)0x0;
      local_48 = 0;
      local_8 = 0;
      for (piVar6 = (int *)piVar6[6]; piVar6 != (int *)0x0; piVar6 = (int *)piVar6[0x10]) {
        piVar11 = piVar6 + 8;
        if (0xf < (uint)piVar6[0xd]) {
          piVar11 = (int *)*piVar11;
        }
        iVar7 = __stricmp((char *)piVar11,"Param");
        if (iVar7 == 0) goto joined_r0x00554c13;
      }
      piVar6 = (int *)0x0;
joined_r0x00554c13:
      local_3c = piVar6;
      if (local_3c != (int *)0x0) {
        iVar7 = (**(code **)(*local_3c + 0x14))();
        if (iVar7 != 0) {
          for (iVar2 = *(int *)(iVar7 + 0x94); iVar2 != iVar7 + 0x44; iVar2 = *(int *)(iVar2 + 0x50)
              ) {
            pcVar13 = (char *)(iVar2 + 0x14);
            if (0xf < *(uint *)(iVar2 + 0x28)) {
              pcVar13 = *(char **)pcVar13;
            }
            iVar8 = __stricmp(pcVar13,"Texture");
            if (iVar8 == 0) {
              if (iVar2 != 0) {
                pcVar13 = (char *)(iVar2 + 0x30);
                if (0xf < *(uint *)(iVar2 + 0x44)) {
                  pcVar13 = *(char **)pcVar13;
                }
                goto LAB_00554cba;
              }
              break;
            }
          }
          pcVar13 = (char *)0x0;
LAB_00554cba:
          local_20 = 0xf;
          local_24 = (undefined4 *)0x0;
          local_34 = local_34 & 0xffffff00;
          pcVar10 = pcVar13;
          do {
            cVar1 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          } while (cVar1 != '\0');
          FUN_00402a70(pcVar13,(int)pcVar10 - (int)(pcVar13 + 1));
          local_8._0_1_ = 1;
          FUN_00440c60();
          local_8 = (uint)local_8._1_3_ << 8;
          if (0xf < local_20) {
            FUN_0089120c(local_34);
          }
        }
        for (piVar6 = (int *)local_3c[0x10]; piVar6 != (int *)0x0; piVar6 = (int *)piVar6[0x10]) {
          piVar11 = piVar6 + 8;
          if (0xf < (uint)piVar6[0xd]) {
            piVar11 = (int *)*piVar11;
          }
          iVar7 = __stricmp((char *)piVar11,"Param");
          if (iVar7 == 0) goto joined_r0x00554c13;
        }
        piVar6 = (int *)0x0;
        goto joined_r0x00554c13;
      }
      local_2c = local_40;
      FUN_00555af0(&local_28,&local_50);
      local_8 = CONCAT31(local_8._1_3_,2);
      uVar12 = FUN_005565a0();
      FUN_00556200(&DAT_00fc1900,uVar12);
      puVar4 = local_24;
      puVar3 = local_28;
      puVar9 = local_28;
      if (local_28 != (undefined4 *)0x0) {
        for (; puVar9 != puVar4; puVar9 = puVar9 + 7) {
          if (0xf < (uint)puVar9[5]) {
            FUN_0089120c(*puVar9);
          }
          puVar9[5] = 0xf;
          puVar9[4] = 0;
          *(undefined1 *)puVar9 = 0;
        }
        FUN_0089120c(puVar3);
      }
      puVar4 = local_4c;
      puVar3 = local_50;
      local_8 = 0xffffffff;
      puVar9 = local_50;
      if (local_50 != (undefined4 *)0x0) {
        for (; puVar9 != puVar4; puVar9 = puVar9 + 7) {
          if (0xf < (uint)puVar9[5]) {
            FUN_0089120c(*puVar9);
          }
          puVar9[5] = 0xf;
          puVar9[4] = 0;
          *(undefined1 *)puVar9 = 0;
        }
        FUN_0089120c(puVar3);
      }
      local_50 = (undefined4 *)0x0;
      local_4c = (undefined4 *)0x0;
      local_48 = 0;
      piVar6 = local_38;
    }
    for (piVar6 = (int *)piVar6[0x10]; piVar6 != (int *)0x0; piVar6 = (int *)piVar6[0x10]) {
      piVar11 = piVar6 + 8;
      if (0xf < (uint)piVar6[0xd]) {
        piVar11 = (int *)*piVar11;
      }
      iVar7 = __stricmp((char *)piVar11,"Category");
      if (iVar7 == 0) goto joined_r0x00554b6f;
    }
    piVar6 = (int *)0x0;
  } while( true );
}

