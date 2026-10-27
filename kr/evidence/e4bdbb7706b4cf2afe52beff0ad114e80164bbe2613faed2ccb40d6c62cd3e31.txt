
void FUN_004f5d50(void)

{
  int *piVar1;
  undefined4 *puVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  undefined **local_8c [6];
  undefined4 *local_74;
  undefined4 local_6c;
  uint local_58;
  uint local_40;
  undefined4 local_30;
  uint local_2c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009246ee;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar4;
  FUN_0072ee30(local_8c);
  local_8 = 0;
  cVar3 = FUN_0072f110(0);
  if (cVar3 != '\0') {
    FUN_0072e2e0("MAPTITLELIST");
    iVar5 = FUN_0072e2e0(&DAT_00c067ec);
    for (piVar1 = *(int **)(iVar5 + 0x18); puVar6 = local_74, piVar1 != (int *)0x0;
        piVar1 = (int *)piVar1[0x10]) {
      iVar5 = (**(code **)(*piVar1 + 0x14))();
      if (iVar5 != 0) {
        iVar5 = FUN_007300a0(&DAT_00bfb82c);
        if (iVar5 != 0) {
          puVar6 = (undefined4 *)(iVar5 + 0x30);
          if (0xf < *(uint *)(iVar5 + 0x44)) {
            puVar6 = (undefined4 *)*puVar6;
          }
          if (puVar6 != (undefined4 *)0x0) {
            FUN_008917b4(puVar6);
          }
        }
        iVar5 = FUN_007300a0(&DAT_00c0561c);
        if (iVar5 == 0) {
LAB_004f5e40:
          pcVar7 = "";
        }
        else {
          pcVar7 = (char *)(iVar5 + 0x30);
          if (0xf < *(uint *)(iVar5 + 0x44)) {
            pcVar7 = *(char **)pcVar7;
          }
          if (pcVar7 == (char *)0x0) goto LAB_004f5e40;
        }
        FUN_004f7df0();
        pcVar10 = pcVar7;
        do {
          cVar3 = *pcVar10;
          pcVar10 = pcVar10 + 1;
        } while (cVar3 != '\0');
        FUN_00402a70(pcVar7,(int)pcVar10 - (int)(pcVar7 + 1));
      }
    }
    for (; puVar6 != (undefined4 *)0x0; puVar6 = (undefined4 *)puVar6[0x10]) {
      pcVar7 = (char *)(puVar6 + 8);
      if (0xf < (uint)puVar6[0xd]) {
        pcVar7 = *(char **)pcVar7;
      }
      iVar5 = __stricmp(pcVar7,"MAPTITLELIST");
      if (iVar5 == 0) goto LAB_004f5eba;
    }
    puVar6 = (undefined4 *)0x0;
LAB_004f5eba:
    for (iVar5 = puVar6[6]; iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x40)) {
      pcVar7 = (char *)(iVar5 + 0x20);
      if (0xf < *(uint *)(iVar5 + 0x34)) {
        pcVar7 = *(char **)pcVar7;
      }
      iVar8 = __stricmp(pcVar7,"STAGE");
      if (iVar8 == 0) goto LAB_004f5ee6;
    }
    iVar5 = 0;
LAB_004f5ee6:
    for (piVar1 = *(int **)(iVar5 + 0x18); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[0x10]) {
      iVar5 = (**(code **)(*piVar1 + 0x14))();
      if (iVar5 != 0) {
        for (iVar8 = *(int *)(iVar5 + 0x94); iVar8 != iVar5 + 0x44; iVar8 = *(int *)(iVar8 + 0x50))
        {
          pcVar7 = (char *)(iVar8 + 0x14);
          if (0xf < *(uint *)(iVar8 + 0x28)) {
            pcVar7 = *(char **)pcVar7;
          }
          iVar9 = __stricmp(pcVar7,"ID");
          if (iVar9 == 0) {
            if (iVar8 != 0) {
              puVar6 = (undefined4 *)(iVar8 + 0x30);
              if (0xf < *(uint *)(iVar8 + 0x44)) {
                puVar6 = (undefined4 *)*puVar6;
              }
              if (puVar6 != (undefined4 *)0x0) {
                FUN_008917b4(puVar6);
              }
            }
            break;
          }
        }
        for (iVar8 = *(int *)(iVar5 + 0x94); iVar8 != iVar5 + 0x44; iVar8 = *(int *)(iVar8 + 0x50))
        {
          pcVar7 = (char *)(iVar8 + 0x14);
          if (0xf < *(uint *)(iVar8 + 0x28)) {
            pcVar7 = *(char **)pcVar7;
          }
          iVar9 = __stricmp(pcVar7,"FILE");
          if (iVar9 == 0) {
            if (iVar8 != 0) {
              pcVar7 = (char *)(iVar8 + 0x30);
              if (0xf < *(uint *)(iVar8 + 0x44)) {
                pcVar7 = *(char **)pcVar7;
              }
              if (pcVar7 != (char *)0x0) goto LAB_004f5fa0;
            }
            break;
          }
        }
        pcVar7 = "";
LAB_004f5fa0:
        FUN_004f7df0();
        pcVar10 = pcVar7;
        do {
          cVar3 = *pcVar10;
          pcVar10 = pcVar10 + 1;
        } while (cVar3 != '\0');
        FUN_00402a70(pcVar7,(int)pcVar10 - (int)(pcVar7 + 1));
      }
    }
  }
  local_8c[0] = TiXmlDocument::vftable;
  if (0xf < local_2c) {
    FUN_0089120c(local_40,uVar4);
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = local_40 & 0xffffff00;
  local_8c[0] = TiXmlNode::vftable;
  local_8 = 2;
  puVar6 = local_74;
  while (puVar6 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*puVar6;
    puVar6 = (undefined4 *)puVar6[0x10];
    (*(code *)*puVar2)(1);
  }
  if (0xf < local_58) {
    FUN_0089120c(local_6c);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

