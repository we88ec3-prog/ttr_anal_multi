
void FUN_00407780(void)

{
  int iVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  undefined4 *puVar9;
  int local_14c;
  uint local_148;
  undefined4 local_138;
  uint local_134;
  uint local_12c;
  uint local_11c;
  uint local_118;
  undefined **local_110 [19];
  uint uStack_c4;
  undefined4 uStack_b4;
  uint uStack_b0;
  undefined **local_98 [19];
  uint uStack_4c;
  undefined4 uStack_3c;
  uint uStack_38;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00925a82;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_14c;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffea8;
  ExceptionList = &local_14;
  FUN_0072ee30(local_98);
  local_c = 0;
  cVar2 = FUN_0072f110(0);
  if ((cVar2 != '\0') && (iVar5 = FUN_0072e2e0("UIXMLIMAGELIST"), iVar5 != 0)) {
    local_14c = FUN_0072e360(uVar4);
    while (local_14c != 0) {
      local_134 = 0xf;
      local_138 = 0;
      local_148 = local_148 & 0xffffff00;
      FUN_00402a70(&DAT_00bed1d4,4);
      local_c._0_1_ = 1;
      FUN_0072ecf0(&DAT_00bf2375);
      local_c = CONCAT31(local_c._1_3_,3);
      if (0xf < local_134) {
        FUN_0089120c(local_148);
      }
      uVar4 = local_11c;
      local_134 = 0xf;
      local_138 = 0;
      local_148 = local_148 & 0xffffff00;
      uVar6 = local_11c;
      if (0x11 < local_11c) {
        uVar6 = 0x12;
      }
      iVar5 = FUN_00407e70(uVar6);
      if (((iVar5 == 0) && (0x11 < uVar4)) && (uVar4 == 0x12)) {
        iVar5 = FUN_0072e360();
        while (iVar5 != 0) {
          for (iVar1 = *(int *)(iVar5 + 0x94); iVar1 != iVar5 + 0x44; iVar1 = *(int *)(iVar1 + 0x50)
              ) {
            pcVar8 = (char *)(iVar1 + 0x14);
            if (0xf < *(uint *)(iVar1 + 0x28)) {
              pcVar8 = *(char **)pcVar8;
            }
            iVar7 = __stricmp(pcVar8,"name");
            if (iVar7 == 0) {
              if (iVar1 != 0) {
                puVar9 = (undefined4 *)(iVar1 + 0x30);
                if (0xf < *(uint *)(iVar1 + 0x44)) {
                  puVar9 = (undefined4 *)*puVar9;
                }
                if (puVar9 != (undefined4 *)0x0) {
                  bVar3 = FUN_008917b4(puVar9);
                  goto LAB_0040793c;
                }
              }
              break;
            }
          }
          bVar3 = 0;
LAB_0040793c:
          *(byte *)((uint)bVar3 + DAT_00faaf5c) = bVar3;
          iVar5 = FUN_0072e3c0();
        }
      }
      local_c = local_c & 0xffffff00;
      if (0xf < local_118) {
        FUN_0089120c(local_12c);
      }
      local_14c = FUN_0072e3c0();
    }
  }
  FUN_0072ee30(local_110);
  local_c = CONCAT31(local_c._1_3_,4);
  cVar2 = FUN_0072f110(0);
  if ((cVar2 != '\0') && (iVar5 = FUN_0072e2e0("UIXMLIMAGELIST"), iVar5 != 0)) {
    local_14c = FUN_0072e360();
    while (local_14c != 0) {
      local_134 = 0xf;
      local_138 = 0;
      local_148 = local_148 & 0xffffff00;
      FUN_00402a70(&DAT_00bed1d4,4);
      local_c._0_1_ = 5;
      FUN_0072ecf0(&DAT_00bf2375);
      local_c = CONCAT31(local_c._1_3_,7);
      if (0xf < local_134) {
        FUN_0089120c(local_148);
      }
      uVar4 = local_11c;
      local_134 = 0xf;
      local_138 = 0;
      local_148 = local_148 & 0xffffff00;
      uVar6 = local_11c;
      if (0x13 < local_11c) {
        uVar6 = 0x14;
      }
      iVar5 = FUN_00407e70(uVar6);
      if (((iVar5 == 0) && (0x13 < uVar4)) && (uVar4 == 0x14)) {
        iVar5 = FUN_0072e360();
        while (iVar5 != 0) {
          for (iVar1 = *(int *)(iVar5 + 0x94); iVar1 != iVar5 + 0x44; iVar1 = *(int *)(iVar1 + 0x50)
              ) {
            pcVar8 = (char *)(iVar1 + 0x14);
            if (0xf < *(uint *)(iVar1 + 0x28)) {
              pcVar8 = *(char **)pcVar8;
            }
            iVar7 = __stricmp(pcVar8,"name");
            if (iVar7 == 0) {
              if (iVar1 != 0) {
                puVar9 = (undefined4 *)(iVar1 + 0x30);
                if (0xf < *(uint *)(iVar1 + 0x44)) {
                  puVar9 = (undefined4 *)*puVar9;
                }
                if (puVar9 != (undefined4 *)0x0) {
                  bVar3 = FUN_008917b4(puVar9);
                  goto LAB_00407b21;
                }
              }
              break;
            }
          }
          bVar3 = 0;
LAB_00407b21:
          *(byte *)((uint)bVar3 + DAT_00faaf6c) = bVar3;
          iVar5 = FUN_0072e3c0();
        }
      }
      local_c = CONCAT31(local_c._1_3_,4);
      if (0xf < local_118) {
        FUN_0089120c(local_12c);
      }
      local_118 = 0xf;
      local_11c = 0;
      local_12c = local_12c & 0xffffff00;
      local_14c = FUN_0072e3c0();
    }
  }
  local_c = local_c & 0xffffff00;
  local_110[0] = TiXmlDocument::vftable;
  if (0xf < uStack_b0) {
    FUN_0089120c(uStack_c4);
  }
  uStack_b0 = 0xf;
  uStack_b4 = 0;
  uStack_c4 = uStack_c4 & 0xffffff00;
  FUN_0072e040();
  local_c = 0xffffffff;
  local_98[0] = TiXmlDocument::vftable;
  if (0xf < uStack_38) {
    FUN_0089120c(uStack_4c);
  }
  uStack_38 = 0xf;
  uStack_3c = 0;
  uStack_4c = uStack_4c & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_14c);
  return;
}

