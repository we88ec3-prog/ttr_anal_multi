
void FUN_0054b6b0(void)

{
  uint *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int in_ECX;
  undefined4 *puVar6;
  int local_24;
  uint *local_20;
  undefined4 local_1c [4];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_24;
  iVar2 = FUN_0072e2e0("AILINK");
  if ((iVar2 != 0) && (local_24 = FUN_0072e360(), local_24 != 0)) {
    local_20 = (uint *)(in_ECX + 0x2c);
    do {
      iVar2 = FUN_007300a0(&DAT_00c0e98c);
      if (iVar2 == 0) {
LAB_0054b733:
        local_1c[0] = 0;
      }
      else {
        puVar3 = (undefined4 *)(iVar2 + 0x30);
        if (0xf < *(uint *)(iVar2 + 0x44)) {
          puVar3 = (undefined4 *)*puVar3;
        }
        if (puVar3 == (undefined4 *)0x0) goto LAB_0054b733;
        local_1c[0] = FUN_008917b4(puVar3);
      }
      iVar2 = FUN_007300a0("formation");
      if (iVar2 == 0) {
LAB_0054b760:
        local_1c[1] = 0;
      }
      else {
        puVar3 = (undefined4 *)(iVar2 + 0x30);
        if (0xf < *(uint *)(iVar2 + 0x44)) {
          puVar3 = (undefined4 *)*puVar3;
        }
        if (puVar3 == (undefined4 *)0x0) goto LAB_0054b760;
        local_1c[1] = FUN_008917b4(puVar3);
      }
      iVar2 = FUN_007300a0(&DAT_00c0fc40);
      if (iVar2 == 0) {
LAB_0054b78d:
        uVar4 = 0;
      }
      else {
        puVar3 = (undefined4 *)(iVar2 + 0x30);
        if (0xf < *(uint *)(iVar2 + 0x44)) {
          puVar3 = (undefined4 *)*puVar3;
        }
        if (puVar3 == (undefined4 *)0x0) goto LAB_0054b78d;
        uVar4 = FUN_008917b4(puVar3);
      }
      local_1c[2] = uVar4;
      iVar2 = FUN_007300a0(&DAT_00bfaf5c);
      if (iVar2 == 0) {
LAB_0054b7bc:
        uVar5 = 0;
      }
      else {
        puVar3 = (undefined4 *)(iVar2 + 0x30);
        if (0xf < *(uint *)(iVar2 + 0x44)) {
          puVar3 = (undefined4 *)*puVar3;
        }
        if (puVar3 == (undefined4 *)0x0) goto LAB_0054b7bc;
        uVar5 = FUN_008917b4(puVar3);
      }
      puVar1 = local_20;
      puVar3 = (undefined4 *)local_20[1];
      local_1c[3] = uVar5;
      if (local_1c < puVar3) {
        puVar6 = (undefined4 *)*local_20;
        if (local_1c < puVar6) goto LAB_0054b811;
        if (puVar3 == (undefined4 *)local_20[2]) {
          FUN_0053ec00();
        }
        puVar3 = (undefined4 *)puVar1[1];
        puVar6 = (undefined4 *)(((int)local_1c - (int)puVar6 & 0xfffffff0U) + *puVar1);
        if (puVar3 != (undefined4 *)0x0) {
          *puVar3 = *puVar6;
          puVar3[1] = puVar6[1];
          puVar3[2] = puVar6[2];
          puVar3[3] = puVar6[3];
        }
      }
      else {
LAB_0054b811:
        if (puVar3 == (undefined4 *)local_20[2]) {
          FUN_0053ec00();
        }
        puVar3 = (undefined4 *)puVar1[1];
        if (puVar3 != (undefined4 *)0x0) {
          *puVar3 = local_1c[0];
          puVar3[1] = local_1c[1];
          puVar3[2] = uVar4;
          puVar3[3] = uVar5;
        }
      }
      puVar1[1] = puVar1[1] + 0x10;
      local_24 = FUN_0072e3c0();
    } while (local_24 != 0);
  }
  __security_check_cookie(local_c ^ (uint)&local_24);
  return;
}

