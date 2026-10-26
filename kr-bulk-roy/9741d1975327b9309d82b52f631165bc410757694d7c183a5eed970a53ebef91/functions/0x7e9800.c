
void FUN_007e9800(undefined4 param_1,undefined4 param_2,float *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  ushort *puVar2;
  float *pfVar3;
  int iVar4;
  int in_ECX;
  ushort *puVar5;
  float *local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 *local_40;
  undefined4 local_3c;
  undefined4 local_38;
  float *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_54;
  puVar2 = *(ushort **)(in_ECX + 0x38);
  local_34 = (float *)0x0;
  puVar5 = *(ushort **)(in_ECX + 0x34);
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_3c = param_1;
  local_38 = param_2;
  local_54 = param_3;
  local_40 = param_4;
  while( true ) {
    if (puVar5 == puVar2) {
      __security_check_cookie(local_c ^ (uint)&local_54);
      return;
    }
    local_50 = 0;
    iVar4 = *(int *)(in_ECX + 0x14);
    local_4c = 0;
    local_48 = 0;
    puVar1 = (undefined4 *)(iVar4 + (uint)*puVar5 * 0xc);
    local_30 = *puVar1;
    local_44 = 0x3f800000;
    local_2c = puVar1[1];
    local_28 = puVar1[2];
    puVar1 = (undefined4 *)(iVar4 + (uint)puVar5[1] * 0xc);
    local_24 = *puVar1;
    local_20 = puVar1[1];
    local_1c = puVar1[2];
    local_18 = *(undefined4 *)(iVar4 + (uint)puVar5[2] * 0xc);
    iVar4 = iVar4 + (uint)puVar5[2] * 0xc;
    local_14 = *(undefined4 *)(iVar4 + 4);
    local_10 = *(undefined4 *)(iVar4 + 8);
    iVar4 = FUN_007c8720(&local_3c,&local_50);
    pfVar3 = local_54;
    if (iVar4 != 0) break;
    puVar5 = puVar5 + 3;
  }
  if (*local_54 <= (float)local_34) {
    local_54 = local_34;
  }
  else {
    local_54 = (float *)*local_54;
  }
  *pfVar3 = (float)local_54;
  if ((((float)local_54 < (float)local_34 != ((float)local_54 == (float)local_34)) &&
      (local_40 != (undefined4 *)0x0)) && (local_40 != &local_50)) {
    local_40[3] = local_44;
    *local_40 = local_50;
    local_40[1] = local_4c;
    local_40[2] = local_48;
  }
  __security_check_cookie(local_c ^ (uint)&local_54);
  return;
}

