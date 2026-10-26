
void FUN_00829640(undefined4 param_1)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  char *pcVar8;
  undefined4 uVar9;
  double dVar10;
  undefined4 local_a0;
  float local_9c;
  int local_98;
  int local_94;
  undefined **local_90 [19];
  uint local_44;
  undefined4 local_34;
  uint local_30;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00925c9b;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar3;
  FUN_0072ee30(local_90);
  local_8 = 0;
  cVar2 = FUN_0072f110(0);
  if (cVar2 == '\0') {
    local_8 = 0xffffffff;
    local_90[0] = TiXmlDocument::vftable;
    if (0xf < local_30) {
      FUN_0089120c(local_44);
    }
    local_30 = 0xf;
    local_34 = 0;
    local_44 = local_44 & 0xffffff00;
    FUN_0072e040();
  }
  else {
    FUN_0072e360(uVar3);
    local_94 = FUN_0072e360();
    while (local_94 != 0) {
      iVar5 = local_94 + 0x44;
      for (iVar1 = *(int *)(local_94 + 0x94); iVar1 != iVar5; iVar1 = *(int *)(iVar1 + 0x50)) {
        pcVar8 = (char *)(iVar1 + 0x14);
        if (0xf < *(uint *)(iVar1 + 0x28)) {
          pcVar8 = *(char **)pcVar8;
        }
        iVar4 = __stricmp(pcVar8,"ID");
        if (iVar4 == 0) {
          if (iVar1 != 0) {
            puVar7 = (undefined4 *)(iVar1 + 0x30);
            if (0xf < *(uint *)(iVar1 + 0x44)) {
              puVar7 = (undefined4 *)*puVar7;
            }
            if (puVar7 != (undefined4 *)0x0) {
              uVar9 = FUN_008917b4(puVar7);
              goto LAB_00829759;
            }
          }
          break;
        }
      }
      uVar9 = 0;
LAB_00829759:
      iVar5 = FUN_0072e360();
      local_98 = iVar5;
      if (iVar5 != 0) {
        do {
          local_a0 = uVar9;
          local_98 = iVar5;
          for (iVar1 = *(int *)(iVar5 + 0x94); iVar1 != iVar5 + 0x44; iVar1 = *(int *)(iVar1 + 0x50)
              ) {
            pcVar8 = (char *)(iVar1 + 0x14);
            if (0xf < *(uint *)(iVar1 + 0x28)) {
              pcVar8 = *(char **)pcVar8;
            }
            iVar4 = __stricmp(pcVar8,"Level");
            if (iVar4 == 0) {
              if (iVar1 != 0) {
                puVar7 = (undefined4 *)(iVar1 + 0x30);
                if (0xf < *(uint *)(iVar1 + 0x44)) {
                  puVar7 = (undefined4 *)*puVar7;
                }
                if (puVar7 != (undefined4 *)0x0) {
                  FUN_008917b4(puVar7);
                }
              }
              break;
            }
          }
          for (iVar1 = *(int *)(iVar5 + 0x94); iVar1 != iVar5 + 0x44; iVar1 = *(int *)(iVar1 + 0x50)
              ) {
            pcVar8 = (char *)(iVar1 + 0x14);
            if (0xf < *(uint *)(iVar1 + 0x28)) {
              pcVar8 = *(char **)pcVar8;
            }
            iVar4 = __stricmp(pcVar8,"Ratio");
            if (iVar4 == 0) {
              if (iVar1 != 0) {
                pcVar8 = (char *)(iVar1 + 0x30);
                if (0xf < *(uint *)(iVar1 + 0x44)) {
                  pcVar8 = *(char **)pcVar8;
                }
                if (pcVar8 != (char *)0x0) {
                  dVar10 = _atof(pcVar8);
                  local_9c = (float)dVar10;
                  goto LAB_00829820;
                }
              }
              break;
            }
          }
          local_9c = 0.0;
LAB_00829820:
          uVar9 = FUN_00829960(param_1,&local_a0);
          uVar6 = FUN_0082a230();
          FUN_0057e850(uVar9,uVar6);
          iVar5 = FUN_0072e3c0();
          uVar9 = local_a0;
        } while (iVar5 != 0);
        local_98 = 0;
      }
      local_94 = FUN_0072e3c0();
    }
    local_8 = 0xffffffff;
    local_90[0] = TiXmlDocument::vftable;
    if (0xf < local_30) {
      FUN_0089120c(local_44);
    }
    local_30 = 0xf;
    local_34 = 0;
    local_44 = local_44 & 0xffffff00;
    FUN_0072e040();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

