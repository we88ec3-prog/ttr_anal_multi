
void FUN_007d4180(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  char *pcVar7;
  char *pcVar8;
  undefined1 auStack_f4 [4];
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  uint local_c4;
  undefined4 local_c0;
  undefined1 local_bc [44];
  undefined1 local_90 [40];
  undefined1 auStack_68 [48];
  uint uStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00914a78;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_f4;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffff00;
  ExceptionList = &local_14;
  local_c0 = param_2;
  local_c4 = 0;
  if (*(int *)(param_1 + 0x68) - *(int *)(param_1 + 100) >> 2 != 0) {
    do {
      local_f0 = 0;
      iVar3 = local_c4 * 4;
      piVar2 = *(int **)(iVar3 + *(int *)(param_1 + 100));
      local_ec = 0;
      local_e8 = 0;
      local_e4 = 0;
      local_e0 = 0;
      local_c8 = 1;
      local_dc = 0;
      local_d8 = 0x3f800000;
      local_d4 = 0x3f800000;
      local_d0 = 0x3f800000;
      local_cc = 0x3f800000;
      if (*piVar2 == 0) {
        puVar6 = (undefined4 *)(**(code **)(*(int *)piVar2[1] + 0x24))(local_bc,uVar4);
      }
      else {
        puVar6 = *(undefined4 **)(iVar3 + *(int *)(param_1 + 100));
        piVar2 = (int *)puVar6[1];
        uVar5 = (**(code **)(*(int *)*puVar6 + 0x24))(local_90);
        uVar5 = (**(code **)(*piVar2 + 0x24))(auStack_68,uVar5);
        puVar6 = (undefined4 *)FUN_0077e910(local_bc,uVar5);
      }
      if (&local_f0 != puVar6) {
        local_f0 = *puVar6;
        local_ec = puVar6[1];
        local_e8 = puVar6[2];
        if (&local_e4 != puVar6 + 3) {
          local_d8 = puVar6[6];
          local_e4 = puVar6[3];
          local_e0 = puVar6[4];
          local_dc = puVar6[5];
        }
        local_d0 = puVar6[8];
        local_d4 = puVar6[7];
        local_c8 = puVar6[10];
        local_cc = puVar6[9];
      }
      iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 100) + iVar3) + 4);
      if (*(uint *)(iVar3 + 0x1c) < 0x10) {
        pcVar8 = (char *)(iVar3 + 8);
      }
      else {
        pcVar8 = *(char **)(iVar3 + 8);
      }
      uStack_24 = 0xf;
      uStack_28 = 0;
      uStack_38 = uStack_38 & 0xffffff00;
      pcVar7 = pcVar8;
      do {
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(pcVar8,(int)pcVar7 - (int)(pcVar8 + 1));
      uStack_c = 0;
      puVar6 = (undefined4 *)FUN_007d4630(local_c0);
      *puVar6 = param_3;
      if (puVar6 + 1 != &local_f0) {
        puVar6[1] = local_f0;
        puVar6[2] = local_ec;
        puVar6[3] = local_e8;
        if (puVar6 + 4 != &local_e4) {
          puVar6[7] = local_d8;
          puVar6[4] = local_e4;
          puVar6[5] = local_e0;
          puVar6[6] = local_dc;
        }
        puVar6[8] = local_d4;
        puVar6[9] = local_d0;
        puVar6[10] = local_cc;
        puVar6[0xb] = local_c8;
      }
      uStack_c = 0xffffffff;
      if (0xf < uStack_24) {
        FUN_0089120c(uStack_38);
      }
      local_c4 = local_c4 + 1;
      uStack_24 = 0xf;
      uStack_28 = 0;
      uStack_38 = uStack_38 & 0xffffff00;
    } while (local_c4 < (uint)(*(int *)(param_1 + 0x68) - *(int *)(param_1 + 100) >> 2));
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_f4);
  return;
}

