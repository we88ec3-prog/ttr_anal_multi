
void FUN_008e2ff0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined4 param_5,char param_6)

{
  int iVar1;
  char cVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined1 *extraout_ECX_01;
  undefined4 extraout_EDX;
  int *piVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint local_64;
  byte *local_54;
  byte local_4d;
  undefined4 local_4c [7];
  undefined1 local_30 [20];
  undefined4 local_1c [4];
  int local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar1 = *param_1;
  if ((param_6 == '\0') && (cVar2 = FUN_008e0f70(), cVar2 == '\0')) {
    FUN_008e1cc0(*param_4);
    FUN_008e2ff0(param_1[1],extraout_EDX,param_3,local_4c,param_5,1);
  }
  cVar2 = FUN_008e1ce0();
  if (cVar2 == '\0') {
    FUN_008e0740();
    FUN_008e0740();
    FUN_008e1d50();
    cVar2 = FUN_008e1ce0();
    if (cVar2 == '\0') goto LAB_008e32ff;
  }
  param_1[5] = 0;
  param_1[6] = 0;
  puVar7 = local_4c;
  for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = *param_4;
    param_4 = param_4 + 1;
    puVar7 = puVar7 + 1;
  }
  pbVar3 = (byte *)FUN_008e1d10();
  uVar4 = FUN_008e0740();
  if (*(char *)(iVar1 + 0xcd) != '\0') {
    FUN_008e0e90();
    FUN_008e10a0(extraout_ECX);
    FUN_008e10a0(iVar1 + 0xe0);
  }
  uVar8 = 0;
  local_4d = 0x80;
  local_54 = pbVar3;
  if (uVar4 != 0) {
    do {
      if ((*local_54 & local_4d) != 0) {
        FUN_008e2c10(uVar8,iVar1,param_5,param_1[4]);
        FUN_008e2c10(uVar8,iVar1,param_5,param_1[4]);
        cVar2 = FUN_008e0f00();
        if (((cVar2 != '\0') || (cVar2 = FUN_008e0f00(), cVar2 != '\0')) ||
           (cVar2 = FUN_008e2830(local_1c,local_30), cVar2 != '\0')) {
          FUN_008e10a0(local_30);
          *local_54 = *local_54 & ~local_4d;
        }
      }
      if (((byte)uVar8 & 7) == 7) {
        local_54 = local_54 + 1;
        local_4d = 0x80;
      }
      else {
        local_4d = local_4d >> 1;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < uVar4);
  }
  if (param_6 == '\0') {
    local_64 = 0;
    local_4d = 0x80;
    local_54 = pbVar3;
    if (uVar4 != 0) {
      do {
        if ((*local_54 & local_4d) != 0) {
          FUN_008e2c10(local_64,iVar1,param_5,param_1[4]);
          FUN_008e2c10(local_64,iVar1,param_5,param_1[4]);
          FUN_008e10a0(local_1c);
        }
        if (((byte)local_64 & 7) == 7) {
          local_54 = local_54 + 1;
          local_4d = 0x80;
        }
        else {
          local_4d = local_4d >> 1;
        }
        local_64 = local_64 + 1;
      } while (local_64 < uVar4);
    }
  }
  else if (((param_1[5] == 0) || (0 < param_1[9])) || (param_1[param_1[5] * 5 + 4] < 0)) {
    FUN_008e0e90();
    local_c = param_1[4];
    local_1c[0] = 0x31;
    FUN_008e0e90();
    FUN_008e10a0(extraout_ECX_00);
  }
  FUN_008e2d30();
  if ((param_6 == '\0') && (uVar4 = 0, param_1[5] != 0)) {
    piVar6 = param_1 + 7;
    do {
      cVar2 = FUN_008e0f10();
      if (cVar2 == '\0') {
        FUN_008e22e0();
        cVar2 = FUN_008e0ee0();
        if (cVar2 == '\0') {
          *(int *)(extraout_ECX_01 + 0xc) = piVar6[3];
        }
        else {
          *(int *)(extraout_ECX_01 + 0x10) = piVar6[3];
        }
        *extraout_ECX_01 = 1;
      }
      uVar4 = uVar4 + 1;
      piVar6 = piVar6 + 5;
    } while (uVar4 < (uint)param_1[5]);
  }
  *(undefined1 *)(param_1 + 3) = 1;
  FUN_008e1d00();
LAB_008e32ff:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

