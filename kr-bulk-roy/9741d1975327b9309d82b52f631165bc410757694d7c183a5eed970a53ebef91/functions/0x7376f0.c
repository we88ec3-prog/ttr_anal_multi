
void FUN_007376f0(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  char *pcVar6;
  undefined4 uVar7;
  int *piVar8;
  char *pcVar9;
  undefined4 *local_98;
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
  if ((cVar1 != '\0') && (iVar3 = FUN_0072e2e0("CURSORLIST"), iVar3 != 0)) {
    piVar4 = (int *)FUN_0072e2e0("Cursor");
joined_r0x00737785:
    if (piVar4 != (int *)0x0) {
      iVar3 = (**(code **)(*piVar4 + 0x14))();
      if (iVar3 != 0) {
        local_98 = (undefined4 *)FUN_00891268(0x34);
        if (local_98 == (undefined4 *)0x0) {
          local_98 = (undefined4 *)0x0;
        }
        else {
          *local_98 = 0;
          local_98[1] = 0;
          local_98[2] = 0;
          local_98[10] = 0xf;
          local_98[9] = 0;
          *(undefined1 *)(local_98 + 5) = 0;
          local_98[0xc] = 0;
          local_98[4] = 0;
          local_98[3] = 0;
        }
        iVar3 = FUN_007300a0(&DAT_00c071fc);
        if (iVar3 != 0) {
          puVar5 = (undefined4 *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            puVar5 = (undefined4 *)*puVar5;
          }
          if (puVar5 != (undefined4 *)0x0) {
            FUN_008917b4(puVar5);
          }
        }
        iVar3 = FUN_007300a0(&DAT_00c1a980);
        if (iVar3 == 0) {
          pcVar9 = (char *)0x0;
        }
        else {
          pcVar9 = (char *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            pcVar9 = *(char **)pcVar9;
          }
        }
        pcVar6 = pcVar9;
        do {
          cVar1 = *pcVar6;
          pcVar6 = pcVar6 + 1;
        } while (cVar1 != '\0');
        FUN_00402a70(pcVar9,(int)pcVar6 - (int)(pcVar9 + 1));
        iVar3 = FUN_007300a0("usage");
        if (iVar3 == 0) {
LAB_0073788d:
          uVar7 = 0;
        }
        else {
          puVar5 = (undefined4 *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            puVar5 = (undefined4 *)*puVar5;
          }
          if (puVar5 == (undefined4 *)0x0) goto LAB_0073788d;
          uVar7 = FUN_008917b4(puVar5);
        }
        *local_98 = uVar7;
        iVar3 = FUN_0072e2e0("FastCursor");
        if (iVar3 != 0) {
          local_98[1] = 1;
        }
        piVar8 = (int *)FUN_0072e2e0("Animated");
        if ((piVar8 != (int *)0x0) && (iVar3 = (**(code **)(*piVar8 + 0x14))(), iVar3 != 0)) {
          local_98[2] = 1;
        }
        piVar8 = (int *)FUN_0072e2e0("HotSpot");
        if ((piVar8 != (int *)0x0) && (iVar3 = (**(code **)(*piVar8 + 0x14))(), iVar3 != 0)) {
          iVar3 = FUN_007300a0(&DAT_00c06928);
          if (iVar3 == 0) {
LAB_00737920:
            uVar7 = 0;
          }
          else {
            puVar5 = (undefined4 *)(iVar3 + 0x30);
            if (0xf < *(uint *)(iVar3 + 0x44)) {
              puVar5 = (undefined4 *)*puVar5;
            }
            if (puVar5 == (undefined4 *)0x0) goto LAB_00737920;
            uVar7 = FUN_008917b4(puVar5);
          }
          local_98[3] = uVar7;
          iVar3 = FUN_007300a0(&DAT_00c0692c);
          if (iVar3 == 0) {
LAB_0073794d:
            uVar7 = 0;
          }
          else {
            puVar5 = (undefined4 *)(iVar3 + 0x30);
            if (0xf < *(uint *)(iVar3 + 0x44)) {
              puVar5 = (undefined4 *)*puVar5;
            }
            if (puVar5 == (undefined4 *)0x0) goto LAB_0073794d;
            uVar7 = FUN_008917b4(puVar5);
          }
          local_98[4] = uVar7;
        }
        uVar7 = FUN_0057ef20();
        FUN_0057e850(param_1 + 0xc,uVar7);
      }
      for (piVar4 = (int *)piVar4[0x10]; piVar4 != (int *)0x0; piVar4 = (int *)piVar4[0x10]) {
        piVar8 = piVar4 + 8;
        if (0xf < (uint)piVar4[0xd]) {
          piVar8 = (int *)*piVar8;
        }
        iVar3 = __stricmp((char *)piVar8,"Cursor");
        if (iVar3 == 0) goto joined_r0x00737785;
      }
      piVar4 = (int *)0x0;
      goto joined_r0x00737785;
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

