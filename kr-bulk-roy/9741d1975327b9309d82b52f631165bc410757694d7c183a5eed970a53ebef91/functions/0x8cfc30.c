
void FUN_008cfc30(undefined4 param_1,int param_2,uint param_3,code *param_4,code *param_5,
                 undefined4 param_6)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 extraout_EDX;
  uint local_60;
  int local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  *(undefined4 *)(param_2 + 0x10) = 0;
  *(undefined4 *)(param_2 + 0x14) = 0;
  puVar1 = (undefined4 *)FUN_008bc7d0(param_1,8,0,param_3 + 10,0,&local_5c);
  *(undefined4 **)(param_2 + 0x14) = puVar1;
  if (local_5c != 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_60 = 0;
  if (param_3 != 0) {
    do {
      iVar2 = (*param_4)(param_6,local_60);
      if (iVar2 != 0) {
        FUN_008cfb90(local_60,&local_58);
        uVar3 = FUN_008cfa40(iVar2);
        if ((uVar3 & 0x7fffffff) != 0) {
          FUN_008cfc00(&local_30);
          *puVar1 = extraout_EDX;
          puVar1[1] = local_60;
          puVar1 = puVar1 + 2;
        }
        if (param_5 != (code *)0x0) {
          (*param_5)(param_6,iVar2);
        }
      }
      local_60 = local_60 + 1;
    } while (local_60 < param_3);
    if (local_30 == 1) {
      *puVar1 = 0x394;
      puVar1[1] = local_58;
      puVar1 = puVar1 + 2;
    }
    if (local_2c == 1) {
      *puVar1 = 0x3a9;
      puVar1[1] = local_54;
      puVar1 = puVar1 + 2;
    }
    if (local_28 == 1) {
      *puVar1 = 0x2215;
      puVar1[1] = local_50;
      puVar1 = puVar1 + 2;
    }
    if (local_24 == 1) {
      *puVar1 = 0xad;
      puVar1[1] = local_4c;
      puVar1 = puVar1 + 2;
    }
    if (local_20 == 1) {
      *puVar1 = 0x2c9;
      puVar1[1] = local_48;
      puVar1 = puVar1 + 2;
    }
    if (local_1c == 1) {
      *puVar1 = 0x3bc;
      puVar1[1] = local_44;
      puVar1 = puVar1 + 2;
    }
    if (local_18 == 1) {
      *puVar1 = 0x2219;
      puVar1[1] = local_40;
      puVar1 = puVar1 + 2;
    }
    if (local_14 == 1) {
      *puVar1 = 0xa0;
      puVar1[1] = local_3c;
      puVar1 = puVar1 + 2;
    }
    if (local_10 == 1) {
      *puVar1 = 0x21a;
      puVar1[1] = local_38;
      puVar1 = puVar1 + 2;
    }
    if (local_c == 1) {
      *puVar1 = 0x21b;
      puVar1[1] = local_34;
      puVar1 = puVar1 + 2;
    }
  }
  iVar2 = *(int *)(param_2 + 0x14);
  uVar3 = (int)puVar1 - iVar2 >> 3;
  if (uVar3 == 0) {
    FUN_008b9f80(param_1,iVar2);
    *(undefined4 *)(param_2 + 0x14) = 0;
    if (local_5c == 0) {
      *(undefined4 *)(param_2 + 0x10) = 0;
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  else {
    if (uVar3 < param_3 >> 1) {
      uVar4 = FUN_008bc7d0(param_1,8,param_3,uVar3,iVar2,&local_5c);
      *(undefined4 *)(param_2 + 0x14) = uVar4;
      local_5c = 0;
    }
    _qsort(*(void **)(param_2 + 0x14),uVar3,8,FUN_008cfb50);
  }
  *(uint *)(param_2 + 0x10) = uVar3;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

