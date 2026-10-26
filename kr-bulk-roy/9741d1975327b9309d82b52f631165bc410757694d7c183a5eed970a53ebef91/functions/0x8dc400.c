
void FUN_008dc400(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  void *local_28;
  size_t local_24;
  int local_1c;
  int local_18 [3];
  uint local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar8 = *(int *)(param_1 + 4);
  uVar1 = *(undefined4 *)(iVar8 + 0x148);
  local_1c = 0;
  uVar2 = *(undefined4 *)(iVar8 + 100);
  iVar3 = *(int *)(iVar8 + 0x88);
  piVar4 = *(int **)(*(int *)(iVar8 + 0x80) + 0x30);
  local_28 = (void *)0x0;
  local_24 = 0;
  if (piVar4 == (int *)0x0) {
    iVar7 = *(int *)(iVar8 + 0x124) + *(int *)(iVar8 + 0x120);
    local_1c = FUN_008b97e0(uVar1,iVar7 * param_2 + *(int *)(iVar8 + 0x11c) +
                                  *(int *)(iVar8 + 0x134));
    if ((local_1c != 0) || (local_1c = FUN_008babe0(uVar1,iVar7 * 2), local_1c != 0))
    goto LAB_008dc75b;
    local_c = FUN_008db320();
    iVar7 = FUN_008db320();
    iVar6 = FUN_008db320();
    local_24 = iVar6 - iVar7;
    FUN_008baca0(uVar1);
    if (*(uint *)(iVar8 + 300) <= local_c) {
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    if (((local_24 == 0) ||
        (local_28 = (void *)FUN_008baee0(uVar2,local_24,&local_1c), local_1c != 0)) ||
       (local_1c = FUN_008b9860(uVar1,*(int *)(iVar8 + 0x134) + iVar7,local_28,local_24),
       local_1c != 0)) goto LAB_008dc75b;
    local_1c = 0;
    uVar5 = local_c;
  }
  else {
    local_1c = (**(code **)*piVar4)(piVar4[1],param_2,local_18 + 2);
    if (local_1c != 0) goto LAB_008dc75b;
    uVar5 = FUN_008db320();
    if (local_c != 0) {
      local_24 = local_c - *(int *)(iVar8 + 0x120);
      local_28 = (void *)FUN_008baee0(uVar2,local_24,&local_1c);
      if (local_1c == 0) {
        FID_conflict__memcpy(local_28,(void *)(*(int *)(iVar8 + 0x120) + local_18[2]),local_24);
      }
    }
    (**(code **)(*piVar4 + 4))(piVar4[1],local_18 + 2);
    if (local_1c != 0) goto LAB_008dc75b;
  }
  iVar7 = *(int *)(iVar8 + 0x13c);
  *(undefined4 *)(param_1 + 0x554) = *(undefined4 *)(iVar7 + uVar5 * 8);
  *(undefined4 *)(param_1 + 0x558) = *(undefined4 *)(iVar7 + uVar5 * 8 + 4);
  *(undefined4 *)(param_1 + 0x55c) = 0;
  iVar8 = uVar5 * 0xfc + *(int *)(iVar8 + 0x130);
  *(undefined4 *)(param_1 + 0x560) = *(undefined4 *)(iVar8 + 0xd8);
  *(undefined4 *)(param_1 + 0x564) = *(undefined4 *)(iVar8 + 0xdc);
  *(undefined4 *)(param_1 + 0x568) = *(undefined4 *)(iVar8 + 0xe0);
  *(undefined4 *)(param_1 + 0x56c) = *(undefined4 *)(iVar8 + 0xe4);
  *(undefined4 *)(param_1 + 0x570) = *(undefined4 *)(iVar8 + 0xe8);
  *(undefined4 *)(param_1 + 0x574) = *(undefined4 *)(iVar8 + 0xec);
  uVar5 = *(uint *)(iVar8 + 4);
  *(uint *)(param_1 + 0x550) = uVar5;
  uVar9 = ((int)uVar5 < 0) - 1 & uVar5;
  if (-1 < (int)uVar5) {
    (**(code **)(iVar3 + 0x10))(local_28,local_24,0x10ea);
  }
  local_1c = (**(code **)(param_1 + 0x5cc))(param_1,uVar9 + (int)local_28,local_24 - uVar9);
  FUN_008b9f80(uVar2,local_28);
  if (((local_1c == 0) && (piVar4 != (int *)0x0)) && (*(int *)(*piVar4 + 8) != 0)) {
    local_18[0] = FUN_008b7c80(*(undefined4 *)(param_1 + 0x20));
    local_18[0] = local_18[0] >> 0x10;
    local_18[1] = 0;
    local_18[2] = FUN_008b7c80(*(undefined4 *)(param_1 + 0x28));
    local_18[2] = local_18[2] >> 0x10;
    iVar8 = FUN_008b7c80(*(undefined4 *)(param_1 + 0x2c));
    local_c = iVar8 >> 0x10;
    (**(code **)(*piVar4 + 8))(piVar4[1],param_2,0,local_18);
    *(int *)(param_1 + 0x20) = local_18[0] << 0x10;
    *(int *)(param_1 + 0x28) = local_18[2] << 0x10;
    *(uint *)(param_1 + 0x2c) = local_c << 0x10;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
LAB_008dc75b:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

