
void FUN_00584d40(int param_1,int param_2)

{
  char cVar1;
  short sVar2;
  short *psVar3;
  char *pcVar4;
  short *psVar5;
  undefined4 uVar6;
  char *pcVar7;
  int in_ECX;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined1 local_74 [8];
  int local_6c;
  int local_60;
  undefined4 *local_5c;
  int local_58;
  undefined4 local_54;
  uint local_50;
  undefined4 local_40;
  uint local_3c;
  uint local_34 [4];
  undefined4 local_24;
  uint local_20;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00922dd0;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_58 = in_ECX;
  if (0 < param_2) {
    puVar10 = (undefined4 *)(param_1 + 4);
    local_60 = param_2;
    do {
      local_54 = puVar10[-1];
      psVar3 = (short *)puVar10[1];
      local_3c = 7;
      local_40 = 0;
      local_50 = local_50 & 0xffff0000;
      psVar5 = psVar3;
      do {
        sVar2 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar2 != 0);
      local_5c = puVar10;
      FUN_00402160(psVar3,(int)psVar5 - (int)(psVar3 + 1) >> 1);
      iVar8 = local_58;
      local_8 = 0;
      uVar6 = FUN_005063f0(&local_54);
      FUN_00506030(iVar8,uVar6);
      local_8 = 0xffffffff;
      if (7 < local_3c) {
        FUN_0089120c(local_50);
      }
      pcVar4 = (char *)*puVar10;
      iVar8 = local_6c + 0x10;
      local_20 = 0xf;
      local_24 = 0;
      local_34[0] = local_34[0] & 0xffffff00;
      pcVar7 = pcVar4;
      do {
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(pcVar4,(int)pcVar7 - (int)(pcVar4 + 1));
      iVar9 = local_58 + 0x10;
      local_8 = 1;
      local_18 = iVar8;
      uVar6 = FUN_0077e100(local_34);
      FUN_00552980(iVar9,local_74,uVar6);
      local_8 = 0xffffffff;
      if (0xf < local_20) {
        FUN_0089120c(local_34[0]);
      }
      puVar10 = local_5c + 3;
      local_60 = local_60 + -1;
      local_20 = 0xf;
      local_24 = 0;
      local_34[0] = local_34[0] & 0xffffff00;
      local_5c = puVar10;
    } while (local_60 != 0);
  }
  FUN_00584eb0(local_58);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

