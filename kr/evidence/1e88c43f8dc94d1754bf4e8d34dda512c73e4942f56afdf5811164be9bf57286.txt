
void FUN_0053e3f0(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  char *pcVar7;
  char *pcVar8;
  undefined4 *puVar9;
  undefined **local_90 [19];
  uint local_44;
  undefined4 local_34;
  uint local_30;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092670b;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar2;
  FUN_0072ee30(local_90);
  local_8 = 0;
  cVar1 = FUN_0072f110(0);
  if ((cVar1 != '\0') && (iVar3 = FUN_0072e2e0("CASELIST"), iVar3 != 0)) {
    for (piVar4 = (int *)FUN_0072e2e0(&DAT_00c0f404); piVar4 != (int *)0x0;
        piVar4 = (int *)piVar4[0x10]) {
      iVar3 = (**(code **)(*piVar4 + 0x14))();
      if (iVar3 != 0) {
        puVar5 = (undefined4 *)FUN_00891268(0x4c);
        puVar9 = (undefined4 *)0x0;
        if (puVar5 != (undefined4 *)0x0) {
          *puVar5 = 0;
          puVar5[1] = 0;
          puVar5[6] = 0;
          puVar5[7] = 0xf;
          *(undefined1 *)(puVar5 + 2) = 0;
          puVar5[0xd] = 0;
          puVar5[0xe] = 0xf;
          *(undefined1 *)(puVar5 + 9) = 0;
          puVar5[0x10] = 0;
          puVar5[0x11] = 0;
          puVar5[0x12] = 0;
          puVar9 = puVar5;
        }
        iVar3 = FUN_007300a0(&DAT_00bfb82c);
        if (iVar3 == 0) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          puVar5 = (undefined4 *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            puVar5 = (undefined4 *)*puVar5;
          }
        }
        if (puVar9 != (undefined4 *)0x0) {
          if (puVar5 == (undefined4 *)0x0) {
            *puVar9 = 0;
          }
          else {
            uVar6 = FUN_008917b4(puVar5);
            *puVar9 = uVar6;
          }
        }
        puVar9 = puVar9 + 1;
        iVar3 = FUN_007300a0("STAGE");
        if (iVar3 == 0) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          puVar5 = (undefined4 *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            puVar5 = (undefined4 *)*puVar5;
          }
        }
        if (puVar9 != (undefined4 *)0x0) {
          if (puVar5 == (undefined4 *)0x0) {
            *puVar9 = 0;
          }
          else {
            uVar6 = FUN_008917b4(puVar5);
            *puVar9 = uVar6;
          }
        }
        iVar3 = FUN_007300a0("MAPFLOW");
        if (iVar3 == 0) {
          pcVar8 = (char *)0x0;
        }
        else {
          pcVar8 = (char *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            pcVar8 = *(char **)pcVar8;
          }
        }
        pcVar7 = pcVar8;
        do {
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        FUN_00402a70(pcVar8,(int)pcVar7 - (int)(pcVar8 + 1));
        iVar3 = FUN_007300a0("CLUSTER");
        if (iVar3 == 0) {
          pcVar8 = (char *)0x0;
        }
        else {
          pcVar8 = (char *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            pcVar8 = *(char **)pcVar8;
          }
        }
        pcVar7 = pcVar8;
        do {
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        FUN_00402a70(pcVar8,(int)pcVar7 - (int)(pcVar8 + 1));
        uVar6 = FUN_0057ef20();
        FUN_0057e850(param_1,uVar6);
      }
    }
  }
  local_8 = 0xffffffff;
  local_90[0] = TiXmlDocument::vftable;
  if (0xf < local_30) {
    FUN_0089120c(local_44,uVar2);
  }
  local_30 = 0xf;
  local_34 = 0;
  local_44 = local_44 & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

