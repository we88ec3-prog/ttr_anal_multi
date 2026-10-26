
void FUN_008d1aa0(int *param_1,int param_2,int param_3,int *param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  void *pvVar7;
  int *piVar8;
  undefined4 *puVar9;
  size_t _Size;
  void *local_5c;
  void *local_58;
  int local_54;
  int local_50;
  int *local_4c;
  int local_48;
  int local_44;
  undefined4 *local_40;
  int *local_3c;
  int *local_38;
  undefined4 *local_34;
  int *local_30;
  undefined4 *local_2c;
  void *local_28;
  undefined4 *local_24;
  int *local_20;
  void *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_44 = param_2;
  local_4c = param_1;
  local_48 = param_3;
  local_30 = param_4;
  FUN_008d06f0(param_1,&local_5c);
  if (local_54 == 0) goto switchD_008d1bb4_default;
  local_38 = *(int **)(local_44 + 8);
  local_3c = (int *)0x1;
  local_34 = (undefined4 *)0x0;
  local_1c = local_5c;
  local_28 = local_58;
  pvVar7 = local_58;
  if (local_38 == (int *)0x7) {
    local_24 = (undefined4 *)param_1[2];
    local_20 = (int *)*param_1;
    *param_1 = (int)local_5c + 1;
    param_1[2] = (int)local_58 - 1;
    FUN_008d06f0(param_1,&local_14);
    *param_1 = (int)local_20;
    param_1[2] = (int)local_24;
    if (local_c == 3) {
      local_38 = (int *)0x8;
LAB_008d1b53:
      if (local_30 == (int *)0x0) {
switchD_008d1bb4_default:
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
      local_1c = (void *)((int)local_5c + 1);
      local_28 = (void *)((int)local_58 - 1);
      local_34 = (undefined4 *)0x1;
      pvVar7 = local_28;
      if (local_3c == (int *)0x0) {
LAB_008d1e14:
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
    }
  }
  else if (local_54 == 3) {
    local_3c = local_30;
    goto LAB_008d1b53;
  }
  local_50 = (int)local_38 + -1;
  local_38 = (int *)(local_48 + (int)local_34 * 4);
LAB_008d1b90:
  piVar8 = (int *)(*local_38 + *(int *)(local_44 + 0x10));
  local_20 = piVar8;
  FUN_008d02f0();
  piVar2 = local_30;
  switch(local_50) {
  case 0:
    iVar3 = FUN_008d08d0();
    pvVar7 = local_28;
    piVar8 = local_20;
    break;
  case 1:
    iVar3 = FUN_008d14e0();
    pvVar7 = local_28;
    break;
  case 2:
    iVar3 = FUN_008d1540(&local_1c,pvVar7,0);
    break;
  case 3:
    iVar3 = FUN_008d1540(&local_1c,pvVar7,3);
    break;
  case 4:
  case 5:
    local_20 = (int *)local_4c[4];
    if (pvVar7 <= local_1c) goto LAB_008d1e01;
    if (local_54 == 4) {
      iVar3 = -1;
    }
    else {
      if (local_54 != 2) goto switchD_008d1bb4_default;
      iVar3 = -2;
    }
    _Size = (int)pvVar7 + (iVar3 - (int)local_1c);
    local_1c = (void *)((int)local_1c + 1);
    if (*piVar8 != 0) {
      FUN_008b9f80(local_20,*piVar8);
      *piVar8 = 0;
    }
    local_20 = (int *)FUN_008baee0(local_20,_Size + 1,&local_40);
    if (local_40 != (undefined4 *)0x0) goto LAB_008d1e3d;
    FID_conflict__memcpy(local_20,local_1c,_Size);
    *(undefined1 *)((int)local_20 + _Size) = 0;
    *piVar8 = (int)local_20;
    goto LAB_008d1e01;
  case 6:
    iVar3 = FUN_008d19c0(&local_1c,4,&local_18,0);
    if (3 < iVar3) {
      iVar3 = FUN_008b7c80(local_18);
      *piVar8 = iVar3;
      iVar3 = FUN_008b7c80(local_14);
      piVar8[1] = iVar3;
      iVar3 = FUN_008b7c80(local_10);
      piVar8[2] = iVar3;
      iVar3 = FUN_008b7c80(local_c);
      piVar8[3] = iVar3;
      pvVar7 = local_28;
      goto LAB_008d1e01;
    }
    goto switchD_008d1bb4_default;
  case 7:
    iVar3 = local_4c[4];
    local_34 = (undefined4 *)FUN_008bc7d0(iVar3,4,0,(int)local_30 * 4,0,&local_40);
    if (local_40 != (undefined4 *)0x0) {
LAB_008d1e3d:
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    local_24 = local_40;
    local_2c = local_34;
    do {
      piVar8 = (int *)FUN_008d19c0(&local_1c,local_30,local_2c,0);
      if (((int)piVar8 < 0) || (piVar8 < local_30)) goto switchD_008d1bb4_default;
      FUN_008d02f0();
      local_2c = local_2c + (int)piVar2;
      local_24 = (undefined4 *)((int)local_24 + 1);
    } while (local_24 < (undefined4 *)0x4);
    if (local_30 != (int *)0x0) {
      local_24 = local_34 + (int)local_30 * 3;
      local_2c = local_34 + (int)local_30 * 2;
      puVar9 = local_34 + (int)piVar2;
      iVar4 = local_48 - (int)local_34;
      local_20 = local_30;
      puVar6 = local_34;
      do {
        puVar1 = *(undefined4 **)(iVar4 + (int)puVar6);
        uVar5 = FUN_008b7c80(*puVar6);
        *puVar1 = uVar5;
        uVar5 = FUN_008b7c80(*puVar9);
        puVar1[1] = uVar5;
        uVar5 = FUN_008b7c80(*local_2c);
        puVar1[2] = uVar5;
        uVar5 = FUN_008b7c80(*local_24);
        puVar1[3] = uVar5;
        local_2c = local_2c + 1;
        local_24 = local_24 + 1;
        puVar6 = puVar6 + 1;
        puVar9 = puVar9 + 1;
        local_20 = (int *)((int)local_20 + -1);
      } while (local_20 != (int *)0x0);
    }
    FUN_008b9f80(iVar3,local_34);
    pvVar7 = local_28;
    goto LAB_008d1e01;
  default:
    goto switchD_008d1bb4_default;
  }
  if (*(char *)(local_44 + 0x14) == '\x01') {
    *(char *)piVar8 = (char)iVar3;
  }
  else if (*(char *)(local_44 + 0x14) == '\x02') {
    *(short *)piVar8 = (short)iVar3;
  }
  else {
    *piVar8 = iVar3;
  }
LAB_008d1e01:
  local_38 = local_38 + 1;
  local_3c = (int *)((int)local_3c + -1);
  if (local_3c == (int *)0x0) goto LAB_008d1e14;
  goto LAB_008d1b90;
}

