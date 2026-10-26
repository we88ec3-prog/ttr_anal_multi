
void FUN_00537a40(int param_1,int param_2)

{
  char cVar1;
  short sVar2;
  int iVar3;
  char *pcVar4;
  short *psVar5;
  short *psVar6;
  int iVar7;
  undefined4 uVar8;
  char *pcVar9;
  undefined4 *puVar10;
  int local_50;
  undefined4 local_4c;
  uint local_38;
  uint local_30 [3];
  int local_24;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091dfb3;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar3 = FUN_00891268(0x3c,local_14);
    local_8 = 0;
    if (iVar3 == 0) {
      local_50 = 0;
    }
    else {
      local_50 = FUN_00537cd0(iVar3);
    }
    local_8 = 0xffffffff;
    iVar3 = FUN_007300a0(&DAT_00c0ce30);
    if (iVar3 == 0) {
      pcVar9 = (char *)0x0;
    }
    else if (*(uint *)(iVar3 + 0x44) < 0x10) {
      pcVar9 = (char *)(iVar3 + 0x30);
    }
    else {
      pcVar9 = *(char **)(iVar3 + 0x30);
    }
    local_20 = 0;
    local_1c = 0xf;
    local_30[0] = local_30[0] & 0xffffff00;
    pcVar4 = pcVar9;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(pcVar9,(int)pcVar4 - (int)(pcVar9 + 1));
    local_8 = 1;
    psVar5 = (short *)FUN_004028b0(local_30);
    local_8 = CONCAT31(local_8._1_3_,2);
    if (7 < *(uint *)(psVar5 + 10)) {
      psVar5 = *(short **)psVar5;
    }
    psVar6 = psVar5;
    do {
      sVar2 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar5,(int)psVar6 - (int)(psVar5 + 1) >> 1);
    if (7 < local_38) {
      FUN_0089120c(local_4c);
    }
    local_8 = 0xffffffff;
    if (0xf < local_1c) {
      FUN_0089120c(local_30[0]);
    }
    iVar3 = FUN_0072e360();
    while (iVar3 != 0) {
      FUN_00537640(&local_24,iVar3);
      local_8 = 3;
      FUN_00539060();
      local_8 = 0xffffffff;
      if (local_24 != 0) {
        FUN_0089120c(local_24);
      }
      local_24 = 0;
      local_20 = 0;
      local_1c = 0;
      iVar3 = FUN_0072e3c0();
    }
    iVar3 = FUN_0072e360();
    if (iVar3 != 0) {
      do {
        FUN_00537a40(iVar3,local_50 + 0x2c);
        iVar3 = FUN_0072e3c0();
      } while (iVar3 != 0);
    }
    for (iVar3 = *(int *)(param_1 + 0x94); iVar3 != param_1 + 0x44; iVar3 = *(int *)(iVar3 + 0x50))
    {
      pcVar9 = (char *)(iVar3 + 0x14);
      if (0xf < *(uint *)(iVar3 + 0x28)) {
        pcVar9 = *(char **)pcVar9;
      }
      iVar7 = __stricmp(pcVar9,"ID");
      if (iVar7 == 0) {
        if (iVar3 != 0) {
          puVar10 = (undefined4 *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            puVar10 = (undefined4 *)*puVar10;
          }
          if (puVar10 != (undefined4 *)0x0) {
            FUN_008917b4(puVar10);
          }
        }
        break;
      }
    }
    uVar8 = FUN_0057ef20();
    FUN_0057e850(param_2,uVar8);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

