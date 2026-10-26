
void FUN_0080ab00(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 *in_ECX;
  char *pcVar8;
  char ****ppppcVar10;
  undefined4 *local_64;
  int local_60 [2];
  char ***local_58 [4];
  uint local_48;
  uint local_44;
  uint local_3c [4];
  undefined4 local_2c;
  uint local_28;
  undefined4 local_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined1 local_c;
  undefined3 uStack_b;
  char ****ppppcVar9;
  
  local_c = 0xff;
  uStack_b = 0xffffff;
  puStack_10 = &LAB_0091c44b;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_64;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff90;
  ExceptionList = &local_14;
  local_60[0] = param_1;
  local_64 = in_ECX;
  iVar3 = FUN_006ddac0(&DAT_00c517e8);
  if (iVar3 != 0) {
    puVar4 = in_ECX;
    if (0xf < (uint)in_ECX[5]) {
      puVar4 = (undefined4 *)*in_ECX;
    }
    FUN_006edab0(5,"Requested sound %s\n",puVar4,uVar2);
    local_44 = 0xf;
    local_48 = 0;
    local_58[0] = (char ***)((uint)local_58[0] & 0xffffff00);
    FUN_0040b0b0(in_ECX,0);
    local_c = 0;
    uStack_b = 0;
    uVar5 = 0;
    ppppcVar9 = (char ****)local_58[0];
    uVar2 = local_44;
    if (local_48 != 0) {
      do {
        ppppcVar10 = ppppcVar9;
        if (uVar2 < 0x10) {
          ppppcVar10 = local_58;
        }
        if (*(char *)((int)ppppcVar10 + uVar5) == '\\') {
          if (uVar2 < 0x10) {
            ppppcVar9 = local_58;
          }
          *(char *)((int)ppppcVar9 + uVar5) = '/';
          ppppcVar9 = (char ****)local_58[0];
          uVar2 = local_44;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < local_48);
    }
    pcVar6 = (char *)(param_1 + 4);
    if (0xf < *(uint *)(param_1 + 0x18)) {
      pcVar6 = *(char **)pcVar6;
    }
    if (uVar2 < 0x10) {
      ppppcVar9 = local_58;
    }
    iVar3 = __strnicmp((char *)ppppcVar9,pcVar6,*(size_t *)(param_1 + 0x14));
    if (iVar3 == 0) {
      ppppcVar9 = (char ****)local_58[0];
      if (local_44 < 0x10) {
        ppppcVar9 = local_58;
      }
      pcVar8 = (char *)((int)ppppcVar9 + *(int *)(param_1 + 0x14));
      local_28 = 0xf;
      local_2c = 0;
      local_3c[0] = local_3c[0] & 0xffffff00;
      pcVar6 = pcVar8;
      do {
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      FUN_0040b310(pcVar8);
      local_c = 1;
      FUN_0040b0b0(local_3c,0);
      local_c = 0;
      if (0xf < local_28) {
        FUN_0089120c(local_3c[0]);
      }
    }
    iVar3 = FUN_0080a8b0(param_1,local_64);
    if ((iVar3 == 0) && (iVar3 = FUN_0080a8b0(param_1,local_58), iVar3 == 0)) {
      local_64 = (undefined4 *)FUN_00891268(0x5c);
      local_c = 3;
      if (local_64 == (undefined4 *)0x0) {
        local_20 = 0;
      }
      else {
        local_20 = FUN_0080dbe0(local_64);
      }
      local_c = 0;
      FUN_0080d760();
      local_28 = 0xf;
      local_2c = 0;
      local_3c[0] = local_3c[0] & 0xffffff00;
      FUN_0040b0b0(local_58,0);
      local_c = 4;
      iVar3 = local_60[0] + 0x38;
      uVar7 = FUN_005435c0(local_3c);
      FUN_00574b80(iVar3,local_60,uVar7);
      if (0xf < local_28) {
        FUN_0089120c(local_3c[0]);
      }
      if (0xf < local_44) {
        FUN_0089120c(local_58[0]);
      }
    }
    else if (*(int *)(iVar3 + 0xc) == 0) {
      FUN_0080d760();
      local_28 = 0xf;
      local_2c = 0;
      local_3c[0] = local_3c[0] & 0xffffff00;
      FUN_0040b0b0(iVar3 + 0x18,0);
      local_20 = 0;
      local_c = 2;
      uVar7 = FUN_005435c0(local_3c);
      FUN_0080c560(param_1 + 0x48,local_60,uVar7);
      if (0xf < local_28) {
        FUN_0089120c(local_3c[0]);
      }
      if (0xf < local_44) {
        FUN_0089120c(local_58[0]);
      }
    }
    else if (0xf < local_44) {
      FUN_0089120c(local_58[0]);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_64);
  return;
}

