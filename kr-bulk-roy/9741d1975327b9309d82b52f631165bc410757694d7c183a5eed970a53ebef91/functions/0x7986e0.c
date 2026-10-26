
void FUN_007986e0(int param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  char ****ppppcVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  uint *puVar10;
  undefined4 *puVar11;
  char *pcVar12;
  undefined4 *puVar13;
  char ***local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00915538;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar2 = (*(int *)(param_1 + 0xa4) - *(int *)(param_1 + 0xa0)) / 0x48;
  if (iVar2 != 0) {
    iVar8 = iVar2 * 0x48;
    do {
      iVar2 = iVar2 + -1;
      iVar6 = iVar8 + -0x48;
      puVar3 = (undefined4 *)(*(int *)(param_1 + 0xa0) + iVar6);
      puVar9 = puVar3;
      puVar11 = (undefined4 *)(param_1 + 0xc);
      for (iVar7 = 0xb; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar11 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar11 = puVar11 + 1;
      }
      FUN_00403040(puVar3 + 0xb,0,0xffffffff);
      iVar7 = *(int *)(param_1 + 0xa0);
      if (*(uint *)(iVar7 + 0x40 + iVar6) < 0x10) {
        pcVar12 = (char *)(iVar7 + 0x2c + iVar6);
      }
      else {
        pcVar12 = *(char **)(iVar7 + 0x2c + iVar6);
      }
      local_1c = 0xf;
      local_20 = 0;
      local_30[0] = (char ***)((uint)local_30[0] & 0xffffff00);
      pcVar4 = pcVar12;
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(pcVar12,(int)pcVar4 - (int)(pcVar12 + 1));
      local_8 = 0;
      puVar11 = *(undefined4 **)(param_1 + 0xa4);
      for (puVar9 = (undefined4 *)(iVar8 + *(int *)(param_1 + 0xa0)); puVar9 != puVar11;
          puVar9 = puVar9 + 0x12) {
        puVar3 = puVar9;
        puVar13 = puVar9 + -0x12;
        for (iVar8 = 0xb; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar13 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar13 = puVar13 + 1;
        }
        FUN_00403040(puVar9 + 0xb,0,0xffffffff);
      }
      iVar7 = *(int *)(param_1 + 0xa4);
      iVar8 = iVar7 + -0x48;
      if (iVar8 != iVar7) {
        puVar10 = (uint *)(iVar7 + -8);
        do {
          if (0xf < *puVar10) {
            FUN_0089120c(puVar10[-5]);
          }
          *puVar10 = 0xf;
          puVar10[-1] = 0;
          *(undefined1 *)(puVar10 + -5) = 0;
          iVar8 = iVar8 + 0x48;
          puVar10 = puVar10 + 0x12;
        } while (iVar8 != iVar7);
      }
      *(int *)(param_1 + 0xa4) = *(int *)(param_1 + 0xa4) + -0x48;
      ppppcVar5 = (char ****)local_30[0];
      if (local_1c < 0x10) {
        ppppcVar5 = local_30;
      }
      iVar8 = __stricmp((char *)ppppcVar5,param_2);
      if (iVar8 == 0) {
        *(undefined4 *)(param_1 + 0xcc) = 0;
        if (0xf < local_1c) {
          FUN_0089120c(local_30[0]);
        }
        break;
      }
      ppppcVar5 = (char ****)local_30[0];
      if (local_1c < 0x10) {
        ppppcVar5 = local_30;
      }
      FID_conflict__wprintf("Popcamera Fault : Required %s, Popped %s\n",param_2,ppppcVar5);
      local_8 = 0xffffffff;
      if (0xf < local_1c) {
        FUN_0089120c(local_30[0]);
      }
      iVar8 = iVar6;
    } while (iVar2 != 0);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

