
void FUN_008eb3b0(undefined4 param_1)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  longlong lVar6;
  short sVar7;
  byte *pbVar8;
  int iVar9;
  int *unaff_ESI;
  int local_38;
  int local_34;
  uint local_30;
  undefined4 local_28;
  int local_24;
  uint local_20;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar9 = *unaff_ESI;
  iVar3 = unaff_ESI[1];
  iVar4 = unaff_ESI[2];
  local_34 = 0x10000;
  if ((*(byte *)(unaff_ESI + 4) & 1) == 0) {
    local_34 = *(int *)(iVar3 + 0x14);
  }
  if (*(int *)(iVar4 + 0x48) == 0x636f6d70) {
    local_18 = unaff_ESI[9];
    local_14 = unaff_ESI[10];
    local_10 = unaff_ESI[0xb];
    local_c = unaff_ESI[0xc];
  }
  else {
    FUN_008b9440(iVar4 + 0x6c,&local_18);
  }
  *(int *)(iVar4 + 0x38) = unaff_ESI[0xf];
  *(int *)(iVar4 + 0x20) = local_18;
  *(int *)(iVar4 + 0x24) = local_c;
  *(int *)(iVar4 + 0x28) = unaff_ESI[0x13] - unaff_ESI[0x11];
  if ((*(int *)(iVar9 + 0x1e0) == 0) && ((*(byte *)(unaff_ESI + 4) & 2) == 0)) {
    pbVar8 = (byte *)FUN_008eabd0(*(undefined2 *)(iVar3 + 0xc),param_1);
    if (pbVar8 != (byte *)0x0) {
      *(uint *)(iVar4 + 0x28) = (uint)*pbVar8 << 6;
    }
  }
  *(int *)(iVar4 + 0x18) = local_10 - local_18;
  *(int *)(iVar4 + 0x1c) = local_c - local_14;
  if ((*(char *)(iVar9 + 0x124) == '\0') || (*(short *)(iVar9 + 0x14a) == 0)) {
    sVar7 = FUN_008b7f40(local_c - local_14,local_34);
    if (*(short *)(iVar9 + 0x16c) == -1) {
      sVar1 = *(short *)(iVar9 + 0xde);
      sVar2 = *(short *)(iVar9 + 0xdc);
    }
    else {
      sVar1 = *(short *)(iVar9 + 0x1b4);
      sVar2 = *(short *)(iVar9 + 0x1b2);
    }
    local_30 = (int)sVar2 - (int)sVar1;
    local_38 = (int)(local_30 - (int)sVar7) / 2;
  }
  else {
    sVar7 = FUN_008b7f40(unaff_ESI[0x2f] - local_c,local_34);
    local_38 = (int)sVar7;
    if (unaff_ESI[0x31] < unaff_ESI[0x2f]) {
      local_30 = FUN_008b7f40(unaff_ESI[0x2f] - unaff_ESI[0x31],local_34);
      local_30 = local_30 & 0xffff;
    }
    else {
      local_30 = 0;
    }
  }
  piVar5 = *(int **)(*(int *)(iVar9 + 0x80) + 0x30);
  if ((piVar5 != (int *)0x0) && (*(int *)(*piVar5 + 8) != 0)) {
    local_24 = local_38;
    local_28 = 0;
    local_20 = local_30;
    iVar9 = (**(code **)(*piVar5 + 8))(piVar5[1],param_1,1,&local_28);
    if (iVar9 != 0) goto LAB_008eb5e2;
    local_38 = local_24;
    local_30 = local_20;
  }
  *(uint *)(iVar4 + 0x3c) = local_30;
  if ((*(byte *)(unaff_ESI + 4) & 1) == 0) {
    lVar6 = (longlong)local_38 * (longlong)local_34 +
            (ulonglong)((int)((longlong)local_38 * (longlong)local_34 >> 0x3f) + 0x8000);
    local_38 = ((uint)lVar6 >> 0x10) + (int)((ulonglong)lVar6 >> 0x20) * 0x10000;
    lVar6 = (longlong)(int)local_30 * (longlong)local_34 +
            (ulonglong)((int)((longlong)(int)local_30 * (longlong)local_34 >> 0x3f) + 0x8000);
    local_30 = ((uint)lVar6 >> 0x10) + (int)((ulonglong)lVar6 >> 0x20) * 0x10000;
  }
  *(int *)(iVar4 + 0x30) = local_38;
  *(int *)(iVar4 + 0x2c) = *(int *)(iVar4 + 0x20) - *(int *)(iVar4 + 0x28) / 2;
  *(uint *)(iVar4 + 0x34) = local_30;
LAB_008eb5e2:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

