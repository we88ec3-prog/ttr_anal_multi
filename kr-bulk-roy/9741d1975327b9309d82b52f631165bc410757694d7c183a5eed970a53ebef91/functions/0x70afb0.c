
undefined4 FUN_0070afb0(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 local_18 [2];
  undefined4 local_10;
  
  pcVar4 = (char *)FUN_006f6210(param_1);
  iVar2 = *(int *)(param_1 + 8);
  iVar3 = *(int *)(param_1 + 0xc);
  iVar8 = *(int *)(param_1 + 0x10);
  local_18[0] = FUN_006fec70(param_1,"_LOADED",7);
  local_10 = 4;
  FUN_006fb850(param_1,iVar8 + 0x60,local_18,*(undefined4 *)(param_1 + 8));
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  uVar5 = FUN_006f50f0();
  pcVar6 = pcVar4;
  do {
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  local_18[0] = FUN_006fec70(param_1,pcVar4,(int)pcVar6 - (int)(pcVar4 + 1));
  local_10 = 4;
  FUN_006fb850(param_1,uVar5,local_18,*(undefined4 *)(param_1 + 8));
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  puVar7 = (undefined4 *)(*(int *)(param_1 + 8) + -0x10);
  if ((puVar7 == &DAT_00c0bfc8) || (*(int *)(*(int *)(param_1 + 8) + -8) != 5)) {
    *(undefined4 **)(param_1 + 8) = puVar7;
    iVar8 = FUN_006f68a0(pcVar4,1);
    if (iVar8 != 0) {
      uVar5 = FUN_006f5f30(param_1,"name conflict for module \'%s\'",pcVar4);
      return uVar5;
    }
    puVar7 = *(undefined4 **)(param_1 + 8);
    *puVar7 = puVar7[-4];
    puVar7[1] = puVar7[-3];
    puVar7[2] = puVar7[-2];
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    FUN_006f5790();
  }
  iVar8 = *(int *)(param_1 + 8);
  local_18[0] = FUN_006fec70(param_1,"_NAME",5);
  local_10 = 4;
  FUN_006fb850(param_1,iVar8 + -0x10,local_18,*(undefined4 *)(param_1 + 8));
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  puVar7 = (undefined4 *)(*(int *)(param_1 + 8) + -0x10);
  if ((puVar7 == &DAT_00c0bfc8) || (*(int *)(*(int *)(param_1 + 8) + -8) != 0)) {
    *(undefined4 **)(param_1 + 8) = puVar7;
  }
  else {
    *(undefined4 **)(param_1 + 8) = puVar7;
    FUN_0070ae70(pcVar4);
  }
  puVar7 = *(undefined4 **)(param_1 + 8);
  *puVar7 = puVar7[-4];
  puVar7[1] = puVar7[-3];
  puVar7[2] = puVar7[-2];
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  FUN_0070ad90();
  FUN_0070ae00(iVar2 - iVar3 >> 4);
  return 0;
}

