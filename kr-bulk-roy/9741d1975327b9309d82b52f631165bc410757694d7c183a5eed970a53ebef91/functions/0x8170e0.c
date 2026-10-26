
void FUN_008170e0(void)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  uint *puVar7;
  int *piVar8;
  undefined4 *puVar9;
  uint *puVar10;
  undefined **local_90 [19];
  uint local_44;
  undefined4 local_34;
  uint local_30;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00925deb;
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
    iVar4 = FUN_0072e360();
    while (iVar4 != 0) {
      for (iVar1 = *(int *)(iVar4 + 0x94); iVar1 != iVar4 + 0x44; iVar1 = *(int *)(iVar1 + 0x50)) {
        pcVar6 = (char *)(iVar1 + 0x14);
        if (0xf < *(uint *)(iVar1 + 0x28)) {
          pcVar6 = *(char **)pcVar6;
        }
        iVar5 = __stricmp(pcVar6,"GroupID");
        if (iVar5 == 0) {
          if (iVar1 != 0) {
            puVar9 = (undefined4 *)(iVar1 + 0x30);
            if (0xf < *(uint *)(iVar1 + 0x44)) {
              puVar9 = (undefined4 *)*puVar9;
            }
            if (puVar9 != (undefined4 *)0x0) {
              FUN_008917b4(puVar9);
            }
          }
          break;
        }
      }
      for (iVar1 = *(int *)(iVar4 + 0x94); iVar1 != iVar4 + 0x44; iVar1 = *(int *)(iVar1 + 0x50)) {
        pcVar6 = (char *)(iVar1 + 0x14);
        if (0xf < *(uint *)(iVar1 + 0x28)) {
          pcVar6 = *(char **)pcVar6;
        }
        iVar5 = __stricmp(pcVar6,"Limit");
        if (iVar5 == 0) {
          if (iVar1 != 0) {
            puVar9 = (undefined4 *)(iVar1 + 0x30);
            if (0xf < *(uint *)(iVar1 + 0x44)) {
              puVar9 = (undefined4 *)*puVar9;
            }
            if (puVar9 != (undefined4 *)0x0) {
              uVar3 = FUN_008917b4(puVar9);
              goto LAB_00817259;
            }
          }
          break;
        }
      }
      uVar3 = 0;
LAB_00817259:
      puVar7 = (uint *)FUN_00891268(0x14);
      puVar10 = (uint *)0x0;
      if (puVar7 != (uint *)0x0) {
        puVar7[1] = 0;
        puVar7[2] = 0;
        puVar7[3] = 0;
        puVar10 = puVar7;
      }
      *puVar10 = uVar3 & 0xff;
      piVar8 = (int *)FUN_00831f50();
      *piVar8 = (int)puVar10;
      iVar4 = FUN_0072e3c0();
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

