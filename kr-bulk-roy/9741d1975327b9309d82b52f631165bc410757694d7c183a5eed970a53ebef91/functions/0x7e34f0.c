
void FUN_007e34f0(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint local_3c;
  int local_38;
  undefined4 local_34 [4];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar3 = *(int *)(in_ECX + 0x2c) - *(int *)(in_ECX + 0x28);
  iVar1 = iVar3 >> 0x1f;
  local_3c = 0;
  if (iVar3 / 0x44 + iVar1 != iVar1) {
    local_38 = 0;
    do {
      local_34[0] = *(undefined4 *)(local_38 + *(int *)(in_ECX + 0x28));
      iVar1 = local_38 + *(int *)(in_ECX + 0x28);
      local_34[1] = *(undefined4 *)(iVar1 + 4);
      local_34[2] = *(undefined4 *)(iVar1 + 8);
      local_34[3] = *(undefined4 *)(iVar1 + 0xc);
      local_24 = *(undefined4 *)(iVar1 + 0x10);
      local_20 = *(undefined4 *)(iVar1 + 0x14);
      local_1c = *(undefined4 *)(iVar1 + 0x18);
      local_18 = *(undefined4 *)(iVar1 + 0x1c);
      local_14 = *(undefined4 *)(iVar1 + 0x20);
      local_10 = *(undefined4 *)(local_38 + 0x24 + *(int *)(in_ECX + 0x28));
      piVar2 = (int *)FUN_007e25f0();
      local_c = (**(code **)(*piVar2 + 0x14))();
      if (local_c != 0) {
        iVar1 = *param_1;
        puVar5 = *(undefined4 **)(iVar1 + 0x5c);
        if ((local_34 < puVar5) && (puVar4 = *(undefined4 **)(iVar1 + 0x58), puVar4 <= local_34)) {
          if (puVar5 == *(undefined4 **)(iVar1 + 0x60)) {
            FUN_007e4a00();
          }
          puVar5 = *(undefined4 **)(iVar1 + 0x5c);
          puVar4 = (undefined4 *)
                   ((((int)local_34 - (int)puVar4) / 0x2c) * 0x2c + *(int *)(iVar1 + 0x58));
          if (puVar5 != (undefined4 *)0x0) {
LAB_007e35ff:
            for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
              *puVar5 = *puVar4;
              puVar4 = puVar4 + 1;
              puVar5 = puVar5 + 1;
            }
          }
        }
        else {
          if (puVar5 == *(undefined4 **)(iVar1 + 0x60)) {
            FUN_007e4a00();
          }
          puVar5 = *(undefined4 **)(iVar1 + 0x5c);
          if (puVar5 != (undefined4 *)0x0) {
            puVar4 = local_34;
            goto LAB_007e35ff;
          }
        }
        *(int *)(iVar1 + 0x5c) = *(int *)(iVar1 + 0x5c) + 0x2c;
      }
      local_3c = local_3c + 1;
      local_38 = local_38 + 0x44;
    } while (local_3c < (uint)((*(int *)(in_ECX + 0x2c) - *(int *)(in_ECX + 0x28)) / 0x44));
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

