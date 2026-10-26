
void FUN_004f6070(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int *_Str1;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  char *****pppppcVar8;
  undefined4 *puVar9;
  char *pcVar10;
  char *****pppppcVar11;
  undefined4 uVar12;
  int *piVar13;
  undefined **local_cc [19];
  uint local_80;
  undefined4 local_70;
  uint local_6c;
  undefined4 local_50;
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  char ****local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092469b;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  FUN_0072ee30(local_cc);
  local_8 = 0;
  cVar1 = FUN_0072f110(0);
  if (cVar1 != '\0') {
    for (iVar3 = FUN_0072e2e0("BUFFLIST"); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x40)) {
      for (piVar13 = *(int **)(iVar3 + 0x18); piVar13 != (int *)0x0; piVar13 = (int *)piVar13[0x10])
      {
        _Str1 = piVar13 + 8;
        if (0xf < (uint)piVar13[0xd]) {
          _Str1 = (int *)*_Str1;
        }
        iVar4 = __stricmp((char *)_Str1,"BUFF");
        if (iVar4 == 0) goto joined_r0x004f613f;
      }
      piVar13 = (int *)0x0;
joined_r0x004f613f:
      while (piVar13 != (int *)0x0) {
        iVar5 = (**(code **)(*piVar13 + 0x14))();
        for (iVar4 = *(int *)(iVar5 + 0x94); iVar4 != iVar5 + 0x44; iVar4 = *(int *)(iVar4 + 0x50))
        {
          pcVar10 = (char *)(iVar4 + 0x14);
          if (0xf < *(uint *)(iVar4 + 0x28)) {
            pcVar10 = *(char **)pcVar10;
          }
          iVar6 = __stricmp(pcVar10,"ID");
          if (iVar6 == 0) {
            if (iVar4 != 0) {
              puVar9 = (undefined4 *)(iVar4 + 0x30);
              if (0xf < *(uint *)(iVar4 + 0x44)) {
                puVar9 = (undefined4 *)*puVar9;
              }
              if (puVar9 != (undefined4 *)0x0) {
                uVar12 = FUN_008917b4(puVar9);
                goto LAB_004f6199;
              }
            }
            break;
          }
        }
        uVar12 = 0;
LAB_004f6199:
        for (iVar4 = *(int *)(iVar5 + 0x94); iVar4 != iVar5 + 0x44; iVar4 = *(int *)(iVar4 + 0x50))
        {
          pcVar10 = (char *)(iVar4 + 0x14);
          if (0xf < *(uint *)(iVar4 + 0x28)) {
            pcVar10 = *(char **)pcVar10;
          }
          iVar6 = __stricmp(pcVar10,"FILE");
          if (iVar6 == 0) {
            if (iVar4 != 0) {
              pcVar10 = (char *)(iVar4 + 0x30);
              if (0xf < *(uint *)(iVar4 + 0x44)) {
                pcVar10 = *(char **)pcVar10;
              }
              goto LAB_004f61ca;
            }
            break;
          }
        }
        pcVar10 = (char *)0x0;
LAB_004f61ca:
        local_1c = 0xf;
        local_20 = 0;
        local_30[0] = (char ****)((uint)local_30[0] & 0xffffff00);
        pcVar7 = pcVar10;
        do {
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar1 != '\0');
        FUN_00402a70(pcVar10,(int)pcVar7 - (int)(pcVar10 + 1));
        local_8._0_1_ = 1;
        pppppcVar11 = (char *****)local_30[0];
        if (local_1c < 0x10) {
          pppppcVar11 = local_30;
        }
        local_38 = 0xf;
        local_3c = 0;
        local_4c = local_4c & 0xffffff00;
        pppppcVar8 = pppppcVar11;
        do {
          cVar1 = *(char *)pppppcVar8;
          pppppcVar8 = (char *****)((int)pppppcVar8 + 1);
        } while (cVar1 != '\0');
        local_50 = uVar12;
        FUN_00402a70(pppppcVar11,(int)pppppcVar8 - (int)((int)pppppcVar11 + 1));
        local_8 = CONCAT31(local_8._1_3_,2);
        uVar12 = FUN_004f98b0(&local_50);
        FUN_004f8eb0(&DAT_00fb7500,uVar12);
        piVar13 = (int *)piVar13[0x10];
        if (0xf < local_38) {
          FUN_0089120c(local_4c);
        }
        local_8 = local_8 & 0xffffff00;
        local_38 = 0xf;
        local_3c = 0;
        local_4c = local_4c & 0xffffff00;
        if (0xf < local_1c) {
          FUN_0089120c(local_30[0]);
        }
        local_1c = 0xf;
        local_20 = 0;
        local_30[0] = (char ****)((uint)local_30[0] & 0xffffff00);
      }
    }
  }
  local_8 = 0xffffffff;
  local_cc[0] = TiXmlDocument::vftable;
  if (0xf < local_6c) {
    FUN_0089120c(local_80,uVar2);
  }
  local_6c = 0xf;
  local_70 = 0;
  local_80 = local_80 & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

