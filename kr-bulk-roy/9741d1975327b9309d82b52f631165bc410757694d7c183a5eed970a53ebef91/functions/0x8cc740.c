
void FUN_008cc740(int param_1,int param_2,uint param_3,undefined4 *param_4)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int local_4c;
  uint *local_48;
  int local_44;
  uint local_40;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (*(int *)(param_2 + 0x48) != *(int *)(param_1 + 0x10)) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if (param_3 == 2) {
    if (*(undefined **)(param_1 + 0xc) == &DAT_00bd8478) {
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  else if (*(undefined **)(param_1 + 0xc) == &DAT_00bd843c) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  iVar6 = param_2 + 0x6c;
  if (param_4 != (undefined4 *)0x0) {
    FUN_008b94d0(iVar6,*param_4,param_4[1]);
  }
  FUN_008b9440(iVar6,&local_18);
  local_10 = local_10 + 0x20 & 0xffffffc0;
  local_18 = local_18 + 0x20 & 0xffffffc0;
  local_c = local_c + 0x20 & 0xffffffc0;
  local_14 = local_14 + 0x20 & 0xffffffc0;
  uVar2 = (int)(local_10 - local_18) >> 6;
  uVar5 = (int)(local_c - local_14) >> 6;
  if ((uVar2 < 0x10000) && (uVar5 < 0x10000)) {
    uVar4 = *(undefined4 *)(param_1 + 8);
    if ((*(byte *)(*(int *)(param_2 + 0x9c) + 4) & 1) != 0) {
      FUN_008b9f80(uVar4,*(undefined4 *)(param_2 + 0x58));
      *(undefined4 *)(param_2 + 0x58) = 0;
      puVar1 = (uint *)(*(int *)(param_2 + 0x9c) + 4);
      *puVar1 = *puVar1 & 0xfffffffe;
    }
    if ((param_3 & 2) == 0) {
      uVar3 = uVar2 + 3 & 0xfffffffc;
      *(undefined1 *)(param_2 + 0x5e) = 2;
      *(undefined2 *)(param_2 + 0x5c) = 0x100;
    }
    else {
      uVar3 = uVar2 + 0xf >> 3 & 0x1ffffffe;
      *(undefined1 *)(param_2 + 0x5e) = 1;
    }
    *(uint *)(param_2 + 0x54) = uVar3;
    *(uint *)(param_2 + 0x50) = uVar2;
    *(uint *)(param_2 + 0x4c) = uVar5;
    uVar4 = FUN_008bc7d0(uVar4,uVar5,0,uVar3,0,&local_4c);
    *(undefined4 *)(param_2 + 0x58) = uVar4;
    if (local_4c == 0) {
      puVar1 = (uint *)(*(int *)(param_2 + 0x9c) + 4);
      *puVar1 = *puVar1 | 1;
      FUN_008b94d0(iVar6,-local_18,-local_14);
      local_40 = (uint)(*(char *)(param_2 + 0x5e) == '\x02');
      local_48 = (uint *)(param_2 + 0x4c);
      local_44 = iVar6;
      local_4c = (**(code **)(param_1 + 0x38))(*(undefined4 *)(param_1 + 0x34),&local_48);
      FUN_008b94d0(iVar6,local_18,local_14);
      if (local_4c == 0) {
        *(undefined4 *)(param_2 + 0x48) = 0x62697473;
        *(int *)(param_2 + 100) = (int)local_18 >> 6;
        *(int *)(param_2 + 0x68) = (int)local_c >> 6;
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

