
void FUN_007d1e20(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  undefined1 auStack_c4 [12];
  float local_b8;
  int local_b4;
  float local_b0;
  undefined4 local_ac;
  int local_a8;
  undefined4 local_a4;
  undefined4 local_a0 [2];
  float local_98;
  float local_94 [5];
  undefined1 local_80 [64];
  undefined4 uStack_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  uint local_24;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  puStack_18 = &LAB_009055bb;
  local_1c = ExceptionList;
  local_24 = DAT_00d61f20 ^ (uint)auStack_c4;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffff30;
  ExceptionList = &local_1c;
  local_ac = param_1;
  if (*(int *)(in_ECX + 0x18) < 4) {
    *(undefined4 *)(in_ECX + 0x18) = 4;
  }
  puVar1 = (undefined4 *)DAT_00fba838[0x10];
  local_b0 = 6.2831855 / (float)*(int *)(in_ECX + 0x18);
  local_a8 = 0;
  local_a4 = 0;
  local_a0[0] = 0;
  local_98 = 0.0;
  local_94[0] = -1.0;
  local_94[2] = 0.0;
  local_94[3] = -1.0;
  local_94[1] = 0.0;
  local_94[4] = 0.0;
  local_30 = *(float *)(in_ECX + 0x10) * 0.0 + *(float *)(in_ECX + 4);
  local_2c = *(float *)(in_ECX + 8) - *(float *)(in_ECX + 0x10) * 1.0;
  local_28 = *(float *)(in_ECX + 0xc) + 0.1;
  local_14 = 0;
  local_b4 = 1;
  if (1 < *(int *)(in_ECX + 0x18) + 2) {
    do {
      local_3c = local_30;
      local_38 = local_2c;
      local_34 = local_28;
      local_b8 = (float)local_b4 * local_b0;
      D3DXMatrixRotationZ(local_80,local_b8,uVar3);
      D3DXVec3TransformCoord(local_a0,local_94,local_94 + 3);
      D3DXVec3Normalize(&local_ac,&local_ac);
      local_30 = *(float *)(in_ECX + 0x10) * local_98 + *(float *)(in_ECX + 4);
      local_2c = *(float *)(in_ECX + 0x10) * local_94[0] + *(float *)(in_ECX + 8);
      local_28 = *(float *)(in_ECX + 0xc) + 0.15;
      if (*(int *)(in_ECX + 0x1c) == 0) {
        if (puVar1 == (undefined4 *)0x0) goto LAB_007d20ca;
        (**(code **)*DAT_00fba838)(local_3c,local_38,&local_34,0);
        (**(code **)*DAT_00fba838)(uStack_40,local_3c,&local_38,0);
        local_34 = local_34 + 0.15;
        local_28 = local_28 + 0.15;
      }
      else if (puVar1 == (undefined4 *)0x0) {
LAB_007d20ca:
        local_28 = *(float *)(in_ECX + 0xc) + 0.01;
        local_b8 = local_28;
        local_34 = local_28;
      }
      else {
        (**(code **)*puVar1)(local_3c,local_38,&local_34,0);
        (**(code **)*puVar1)(uStack_40,local_3c,&local_38,0);
        local_28 = local_28 + 0.15;
        local_34 = local_34 + 0.15;
      }
      FUN_0085df00();
      FUN_0085df00();
      local_b4 = local_b4 + 1;
    } while (local_b4 < *(int *)(in_ECX + 0x18) + 2);
  }
  iVar2 = local_a8;
  FUN_007cbd20(local_a8,*(int *)(in_ECX + 0x18) + 2);
  if (iVar2 != 0) {
    FUN_0089120c(iVar2);
  }
  ExceptionList = local_1c;
  __security_check_cookie(local_24 ^ (uint)auStack_c4);
  return;
}

