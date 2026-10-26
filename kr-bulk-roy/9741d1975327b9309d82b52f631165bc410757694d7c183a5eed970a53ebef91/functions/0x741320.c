
void FUN_00741320(short *param_1,short *param_2,undefined4 param_3,undefined1 *param_4)

{
  short sVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  short *psVar5;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 ****ppppuVar9;
  int in_ECX;
  int *unaff_FS_OFFSET;
  int local_7c;
  int local_78;
  undefined4 local_74;
  undefined1 *local_70;
  short *local_6c;
  undefined4 ***local_68 [4];
  undefined4 local_58;
  uint local_54;
  uint local_4c [4];
  undefined4 local_3c;
  uint local_38;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00911e88;
  local_10 = *unaff_FS_OFFSET;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  local_6c = param_2;
  local_4c[0] = local_4c[0] & 0xffff0000;
  local_70 = param_4;
  local_74 = param_3;
  local_38 = 7;
  local_3c = 0;
  psVar5 = param_1;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  local_14 = uVar4;
  FUN_00741900(param_1,(int)psVar5 - (int)(param_1 + 1) >> 1);
  local_8 = 0;
  local_7c = FUN_00741a90(local_4c);
  if ((local_7c == *(int *)(in_ECX + 4)) || (cVar3 = FUN_007418b0(uVar4), cVar3 != '\0')) {
    local_78 = *(int *)(in_ECX + 4);
    piVar6 = &local_78;
  }
  else {
    piVar6 = &local_7c;
  }
  iVar8 = *piVar6;
  local_8 = 0xffffffff;
  if (7 < local_38) {
    FUN_0089120c(local_4c[0]);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = local_4c[0] & 0xffff0000;
  if (iVar8 == *(int *)(in_ECX + 4)) {
    psVar5 = param_1;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    uVar4 = (int)psVar5 - (int)(param_1 + 1) >> 1;
    if ((4 < uVar4) && (iVar8 = __wcsicmp(param_1 + (uVar4 - 4),L"Bold"), iVar8 == 0)) {
      iVar8 = uVar4 - 5;
      if (param_1[uVar4 - 5] != 0x20) {
        iVar8 = uVar4 - 4;
      }
      local_54 = 7;
      local_58 = 0;
      local_68[0] = (undefined4 ***)((uint)local_68[0] & 0xffff0000);
      local_8 = 4;
      FUN_00402160(param_1,iVar8);
      ppppuVar9 = (undefined4 ****)local_68[0];
      if (local_54 < 8) {
        ppppuVar9 = local_68;
      }
      FUN_00741320(ppppuVar9,L"Bold",local_74,local_70);
      if (7 < local_54) {
        FUN_0089120c(local_68[0]);
      }
    }
    goto LAB_007415e1;
  }
  if (*(int *)(iVar8 + 0x30) == 0) goto LAB_007415e1;
  local_1c = 7;
  local_30 = local_30 & 0xffff0000;
  local_20 = 0;
  psVar5 = local_6c;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00741900(local_6c,(int)psVar5 - (int)(local_6c + 1) >> 1);
  local_8 = 1;
  FUN_007417b0(&local_6c);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  if (local_6c == *(short **)(iVar8 + 0x2c)) {
    *local_70 = 0;
    local_1c = 7;
    local_20 = 0;
    local_30 = local_30 & 0xffff0000;
    FUN_00741900(L"Regular",7);
    local_8 = 2;
    piVar6 = (int *)FUN_007417b0(&local_6c);
    iVar2 = *piVar6;
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    if (iVar2 == *(int *)(iVar8 + 0x2c)) {
      FUN_00740680();
      local_8 = 3;
      puVar7 = (undefined4 *)FUN_007417b0(&local_6c);
      psVar5 = (short *)*puVar7;
      local_8 = 0xffffffff;
      FUN_0046fc40();
      if (psVar5 == *(short **)(iVar8 + 0x2c)) {
        psVar5 = *(short **)*(short **)(iVar8 + 0x2c);
      }
      goto LAB_00741519;
    }
  }
  else {
    *local_70 = 1;
    psVar5 = local_6c;
LAB_00741519:
    if (psVar5 == *(short **)(iVar8 + 0x2c)) goto LAB_007415e1;
  }
  FUN_00741600();
LAB_007415e1:
  *unaff_FS_OFFSET = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

