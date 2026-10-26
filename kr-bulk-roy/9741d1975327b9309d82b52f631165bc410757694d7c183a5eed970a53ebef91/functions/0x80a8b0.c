
void FUN_0080a8b0(int param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  int *piVar6;
  char *pcVar7;
  char ****ppppcVar9;
  uint uVar10;
  int iVar11;
  int local_58;
  int local_54;
  int local_50;
  uint local_4c [4];
  undefined4 local_3c;
  uint local_38;
  char ***local_30 [4];
  uint local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  char ****ppppcVar8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00918630;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_50 = param_1;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (char ***)((uint)local_30[0] & 0xffffff00);
  FUN_0040b0b0(param_2,0);
  iVar11 = local_50;
  local_8 = 0;
  uVar2 = 0;
  ppppcVar8 = (char ****)local_30[0];
  uVar10 = local_1c;
  if (local_20 != 0) {
    do {
      ppppcVar9 = ppppcVar8;
      if (uVar10 < 0x10) {
        ppppcVar9 = local_30;
      }
      if (*(char *)((int)ppppcVar9 + uVar2) == '\\') {
        if (uVar10 < 0x10) {
          ppppcVar8 = local_30;
        }
        *(char *)((int)ppppcVar8 + uVar2) = '/';
        ppppcVar8 = (char ****)local_30[0];
        uVar10 = local_1c;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < local_20);
  }
  pcVar4 = (char *)(local_50 + 4);
  if (0xf < *(uint *)(local_50 + 0x18)) {
    pcVar4 = *(char **)pcVar4;
  }
  if (uVar10 < 0x10) {
    ppppcVar8 = local_30;
  }
  iVar3 = __strnicmp((char *)ppppcVar8,pcVar4,*(size_t *)(local_50 + 0x14));
  if (iVar3 == 0) {
    ppppcVar8 = (char ****)local_30[0];
    if (local_1c < 0x10) {
      ppppcVar8 = local_30;
    }
    pcVar7 = (char *)((int)ppppcVar8 + *(int *)(iVar11 + 0x14));
    local_38 = 0xf;
    local_3c = 0;
    local_4c[0] = local_4c[0] & 0xffffff00;
    pcVar4 = pcVar7;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_0040b310(pcVar7);
    local_8._0_1_ = 1;
    FUN_0040b0b0(local_4c,0);
    local_8 = (uint)local_8._1_3_ << 8;
    iVar11 = local_50;
    if (0xf < local_38) {
      FUN_0089120c(local_4c[0]);
      iVar11 = local_50;
    }
  }
  local_58 = FUN_0080c1c0(param_2);
  if (local_58 == *(int *)(iVar11 + 0x3c)) {
LAB_0080aa26:
    local_54 = *(int *)(iVar11 + 0x3c);
    piVar6 = &local_54;
  }
  else {
    uVar10 = *(uint *)(local_58 + 0x1c);
    pcVar4 = (char *)(local_58 + 0xc);
    if (0xf < *(uint *)(local_58 + 0x20)) {
      pcVar4 = *(char **)pcVar4;
    }
    uVar2 = *(uint *)(param_2 + 0x10);
    uVar5 = uVar2;
    if (uVar10 <= uVar2) {
      uVar5 = uVar10;
    }
    if (0xf < *(uint *)(param_2 + 0x14)) {
      param_2 = *(char **)param_2;
    }
    uVar5 = __strnicmp(param_2,pcVar4,uVar5);
    iVar11 = local_50;
    if (uVar5 == 0) {
      if (uVar2 < uVar10) goto LAB_0080aa26;
      uVar5 = (uint)(uVar2 != uVar10);
    }
    if ((int)uVar5 < 0) goto LAB_0080aa26;
    piVar6 = &local_58;
  }
  if (*piVar6 == *(int *)(iVar11 + 0x3c)) {
    local_54 = FUN_0080c1c0(local_30);
    uVar10 = local_20;
    if (local_54 == *(int *)(iVar11 + 0x3c)) {
LAB_0080aab2:
      local_58 = *(int *)(iVar11 + 0x3c);
      piVar6 = &local_58;
    }
    else {
      uVar2 = *(uint *)(local_54 + 0x1c);
      pcVar4 = (char *)(local_54 + 0xc);
      if (0xf < *(uint *)(local_54 + 0x20)) {
        pcVar4 = *(char **)pcVar4;
      }
      uVar5 = local_20;
      if (uVar2 <= local_20) {
        uVar5 = uVar2;
      }
      ppppcVar8 = (char ****)local_30[0];
      if (local_1c < 0x10) {
        ppppcVar8 = local_30;
      }
      uVar5 = __strnicmp((char *)ppppcVar8,pcVar4,uVar5);
      iVar11 = local_50;
      if (uVar5 == 0) {
        if (uVar10 < uVar2) goto LAB_0080aab2;
        uVar5 = (uint)(uVar10 != uVar2);
      }
      if ((int)uVar5 < 0) goto LAB_0080aab2;
      piVar6 = &local_54;
    }
    if (*piVar6 == *(int *)(iVar11 + 0x3c)) {
      if (0xf < local_1c) {
        FUN_0089120c(local_30[0]);
      }
      goto LAB_0080aada;
    }
  }
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
LAB_0080aada:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

