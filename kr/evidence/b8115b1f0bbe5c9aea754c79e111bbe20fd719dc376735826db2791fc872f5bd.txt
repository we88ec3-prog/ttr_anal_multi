
void FUN_004a7ae0(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  char *pcVar8;
  undefined4 *puVar9;
  bool bVar10;
  undefined1 auStack_a4 [4];
  int *local_a0;
  int *local_9c;
  undefined **local_98 [19];
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00925079;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_a4;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff50;
  ExceptionList = &local_14;
  FUN_0072ee30(local_98);
  local_c = 0;
  cVar1 = FUN_0072f110(0);
  if (cVar1 == '\0') {
    local_c = 0xffffffff;
    local_98[0] = TiXmlDocument::vftable;
    if (0xf < local_38) {
      FUN_0089120c(local_4c);
    }
  }
  else {
    iVar3 = FUN_0072e2e0("TOWNWORLDLISTTABLE");
    if (iVar3 == 0) {
      local_c = 0xffffffff;
      local_98[0] = TiXmlDocument::vftable;
      if (0xf < local_38) {
        FUN_0089120c(local_4c);
      }
    }
    else {
      local_a0 = (int *)FUN_0072e360(uVar2);
      if (local_a0 != (int *)0x0) {
        do {
          piVar4 = (int *)FUN_00891268(0xc);
          if (piVar4 == (int *)0x0) {
            piVar4 = (int *)0x0;
          }
          else {
            *piVar4 = 0;
            piVar4[1] = 0;
            piVar4[2] = 0;
          }
          local_9c = piVar4;
          piVar5 = (int *)FUN_0072e360();
          (**(code **)(*local_a0 + 0x14))();
          iVar3 = FUN_007300a0(&DAT_00bfb82c);
          if (iVar3 == 0) {
LAB_004a7c4d:
            iVar3 = 0;
          }
          else {
            puVar6 = (undefined4 *)(iVar3 + 0x30);
            if (0xf < *(uint *)(iVar3 + 0x44)) {
              puVar6 = (undefined4 *)*puVar6;
            }
            if (puVar6 == (undefined4 *)0x0) goto LAB_004a7c4d;
            iVar3 = FUN_008917b4(puVar6);
          }
          *piVar4 = iVar3;
          (**(code **)(*piVar5 + 0x14))();
          iVar3 = FUN_007300a0("bindno");
          if (iVar3 == 0) {
LAB_004a7c85:
            iVar3 = 0;
          }
          else {
            puVar6 = (undefined4 *)(iVar3 + 0x30);
            if (0xf < *(uint *)(iVar3 + 0x44)) {
              puVar6 = (undefined4 *)*puVar6;
            }
            if (puVar6 == (undefined4 *)0x0) goto LAB_004a7c85;
            iVar3 = FUN_008917b4(puVar6);
          }
          uVar2 = DAT_00fb9390 & 1;
          piVar4[1] = iVar3;
          if (uVar2 == 0) {
            DAT_00fb9390 = DAT_00fb9390 | 1;
            local_c._0_1_ = 1;
            FUN_0044ad70();
            _atexit((_func_4879 *)&LAB_00bcd610);
            local_c = (uint)local_c._1_3_ << 8;
          }
          puVar6 = (undefined4 *)DAT_00fb9398[1];
          cVar1 = *(char *)((int)puVar6 + 0x15);
          puVar9 = puVar6;
          while (cVar1 == '\0') {
            if ((int)puVar9[3] < 5) {
              puVar9 = (undefined4 *)puVar9[2];
            }
            else {
              puVar9 = (undefined4 *)*puVar9;
            }
            cVar1 = *(char *)((int)puVar9 + 0x15);
          }
          puVar9 = DAT_00fb9398;
          if (*(char *)((int)puVar6 + 0x15) == '\0') {
            do {
              if ((int)puVar6[3] < 4) {
                puVar7 = (undefined4 *)puVar6[2];
              }
              else {
                puVar7 = (undefined4 *)*puVar6;
                puVar9 = puVar6;
              }
              puVar6 = puVar7;
            } while (*(char *)((int)puVar7 + 0x15) == '\0');
            if ((puVar9 == DAT_00fb9398) || (*piVar4 <= (int)(uint)*(byte *)(puVar9[4] + 1)))
            goto LAB_004a7d1e;
            *(undefined1 *)(piVar4 + 2) = 0;
          }
          else {
LAB_004a7d1e:
            iVar3 = FUN_007300a0("visible");
            if (iVar3 == 0) {
LAB_004a7d50:
              bVar10 = false;
            }
            else {
              pcVar8 = (char *)(iVar3 + 0x30);
              if (0xf < *(uint *)(iVar3 + 0x44)) {
                pcVar8 = *(char **)pcVar8;
              }
              if (pcVar8 == (char *)0x0) goto LAB_004a7d50;
              iVar3 = __stricmp(pcVar8,"true");
              bVar10 = iVar3 == 0;
            }
            *(bool *)(piVar4 + 2) = bVar10;
          }
          iVar3 = FUN_007300a0(&DAT_00bed1dc);
          if (iVar3 == 0) {
LAB_004a7d87:
            bVar10 = false;
          }
          else {
            pcVar8 = (char *)(iVar3 + 0x30);
            if (0xf < *(uint *)(iVar3 + 0x44)) {
              pcVar8 = *(char **)pcVar8;
            }
            if (pcVar8 == (char *)0x0) goto LAB_004a7d87;
            iVar3 = __stricmp(pcVar8,"true");
            bVar10 = iVar3 == 0;
          }
          *(bool *)((int)piVar4 + 9) = bVar10;
          FUN_004a8680();
          local_a0 = (int *)local_a0[0x10];
        } while (local_a0 != (int *)0x0);
        local_a0 = (int *)0x0;
      }
      FUN_004a7e20();
      local_c = 0xffffffff;
      local_98[0] = TiXmlDocument::vftable;
      if (0xf < local_38) {
        FUN_0089120c(local_4c);
      }
    }
  }
  local_3c = 0;
  local_38 = 0xf;
  local_4c = local_4c & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_a4);
  return;
}

