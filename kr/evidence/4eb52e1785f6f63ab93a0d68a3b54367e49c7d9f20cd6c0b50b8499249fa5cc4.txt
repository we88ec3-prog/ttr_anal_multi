
void FUN_004f7730(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int *_Str1;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  int *piVar10;
  uint uVar11;
  int local_f0;
  undefined **local_e4 [19];
  uint local_98;
  undefined4 local_88;
  uint local_84;
  uint local_6c [4];
  undefined4 local_5c;
  uint local_58;
  uint local_50;
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00924553;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  FUN_0072ee30(local_e4);
  local_8 = 0;
  cVar1 = FUN_0072f110(0);
  if (cVar1 != '\0') {
    for (iVar3 = FUN_0072e2e0("PORTALLIST"); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x40)) {
      for (piVar10 = *(int **)(iVar3 + 0x18); piVar10 != (int *)0x0; piVar10 = (int *)piVar10[0x10])
      {
        _Str1 = piVar10 + 8;
        if (0xf < (uint)piVar10[0xd]) {
          _Str1 = (int *)*_Str1;
        }
        iVar4 = __stricmp((char *)_Str1,"PORTAL");
        if (iVar4 == 0) goto joined_r0x004f7800;
      }
      piVar10 = (int *)0x0;
joined_r0x004f7800:
      while (piVar10 != (int *)0x0) {
        iVar5 = (**(code **)(*piVar10 + 0x14))();
        for (iVar4 = *(int *)(iVar5 + 0x94); iVar4 != iVar5 + 0x44; iVar4 = *(int *)(iVar4 + 0x50))
        {
          pcVar7 = (char *)(iVar4 + 0x14);
          if (0xf < *(uint *)(iVar4 + 0x28)) {
            pcVar7 = *(char **)pcVar7;
          }
          iVar6 = __stricmp(pcVar7,"ID");
          if (iVar6 == 0) {
            if (iVar4 != 0) {
              puVar9 = (undefined4 *)(iVar4 + 0x30);
              if (0xf < *(uint *)(iVar4 + 0x44)) {
                puVar9 = (undefined4 *)*puVar9;
              }
              if (puVar9 != (undefined4 *)0x0) {
                local_f0 = FUN_008917b4(puVar9);
                goto LAB_004f785e;
              }
            }
            break;
          }
        }
        local_f0 = 0;
LAB_004f785e:
        for (iVar4 = *(int *)(iVar5 + 0x94); iVar4 != iVar5 + 0x44; iVar4 = *(int *)(iVar4 + 0x50))
        {
          pcVar7 = (char *)(iVar4 + 0x14);
          if (0xf < *(uint *)(iVar4 + 0x28)) {
            pcVar7 = *(char **)pcVar7;
          }
          iVar6 = __stricmp(pcVar7,"STATE");
          if (iVar6 == 0) {
            if (iVar4 != 0) {
              puVar9 = (undefined4 *)(iVar4 + 0x30);
              if (0xf < *(uint *)(iVar4 + 0x44)) {
                puVar9 = (undefined4 *)*puVar9;
              }
              if (puVar9 != (undefined4 *)0x0) {
                uVar11 = FUN_008917b4(puVar9);
                goto LAB_004f788f;
              }
            }
            break;
          }
        }
        uVar11 = 0;
LAB_004f788f:
        local_1c = 0xf;
        local_20 = 0;
        local_30 = local_30 & 0xffffff00;
        FUN_00402a70(&DAT_00c0561c,4);
        local_8._0_1_ = 1;
        FUN_0072ecf0(&DAT_00bf2375);
        local_8._0_1_ = 3;
        if (0xf < local_1c) {
          FUN_0089120c(local_30);
        }
        local_50 = local_f0 << 0x10 | uVar11 & 0xffff;
        local_1c = 0xf;
        local_20 = 0;
        local_30 = local_30 & 0xffffff00;
        local_38 = 0xf;
        local_3c = 0;
        local_4c = local_4c & 0xffffff00;
        FUN_00403040(local_6c,0,0xffffffff);
        local_8 = CONCAT31(local_8._1_3_,4);
        uVar8 = FUN_004f9b40(&local_50);
        FUN_004f8eb0(&DAT_00fb7530,uVar8);
        if (0xf < local_38) {
          FUN_0089120c(local_4c);
        }
        piVar10 = (int *)piVar10[0x10];
        local_8 = local_8 & 0xffffff00;
        local_38 = 0xf;
        local_3c = 0;
        local_4c = local_4c & 0xffffff00;
        if (0xf < local_58) {
          FUN_0089120c(local_6c[0]);
        }
        local_58 = 0xf;
        local_5c = 0;
        local_6c[0] = local_6c[0] & 0xffffff00;
      }
    }
  }
  local_8 = 0xffffffff;
  local_e4[0] = TiXmlDocument::vftable;
  if (0xf < local_84) {
    FUN_0089120c(local_98,uVar2);
  }
  local_84 = 0xf;
  local_88 = 0;
  local_98 = local_98 & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

