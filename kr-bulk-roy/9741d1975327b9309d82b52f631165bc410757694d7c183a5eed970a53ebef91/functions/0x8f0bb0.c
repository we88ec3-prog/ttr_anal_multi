
void FUN_008f0bb0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int iVar8;
  int *piVar9;
  uint local_44;
  undefined4 *local_40;
  int local_3c;
  undefined4 local_38;
  int local_34;
  int local_30;
  int local_2c;
  ushort local_28;
  short local_26;
  ushort local_24;
  short local_22;
  ushort local_20;
  ushort local_1e;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  ushort local_a;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_38 = *(undefined4 *)(param_1 + 100);
  uVar1 = *(undefined4 *)(param_1 + 0x68);
  local_40 = param_2;
  local_3c = param_1;
  local_30 = 0;
  if (*(int *)(param_1 + 0x2a4) == 0) {
    local_30 = (**(code **)(param_1 + 0x1fc))(param_1,0x67766172,uVar1,&local_44);
    if ((local_30 != 0) ||
       (local_30 = (**(code **)(param_1 + 0x1fc))(param_1,0x66766172,uVar1,&local_44), local_30 != 0
       )) goto LAB_008f0fcc;
    local_34 = FUN_008b9850(uVar1);
    local_30 = FUN_008bacd0(uVar1,&DAT_00beab84,&local_2c);
    if (local_30 != 0) goto LAB_008f0fcc;
    if ((((local_2c != 0x10000) || (local_26 != 2)) || (local_22 != 0x14)) || (0x3ffe < local_24)) {
LAB_008f0f75:
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    if ((((uint)local_1e != (uint)local_24 * 4 + 4) || (0x7eff < local_20)) ||
       (local_44 < (uint)local_20 * (uint)local_1e + (uint)local_24 * 0x14 + (uint)local_28))
    goto LAB_008f0f75;
    iVar2 = FUN_008baee0(local_38,0x28,&local_30);
    *(int *)(param_1 + 0x2a4) = iVar2;
    if (local_30 != 0) goto LAB_008f0fcc;
    *(uint *)(iVar2 + 0xc) =
         ((uint)local_20 * 4 + 0x1d) * (uint)local_24 + 0x14 + (uint)local_20 * 8;
    puVar3 = (uint *)FUN_008baee0(local_38,*(undefined4 *)(*(int *)(param_1 + 0x2a4) + 0xc),
                                  &local_30);
    if (local_30 != 0) goto LAB_008f0fcc;
    *(uint **)(*(int *)(local_3c + 0x2a4) + 8) = puVar3;
    *puVar3 = (uint)local_24;
    puVar3[1] = 0xffffffff;
    puVar4 = puVar3 + 5;
    puVar3[3] = (uint)puVar4;
    puVar3[2] = (uint)local_20;
    puVar3[4] = (uint)(puVar4 + (uint)local_24 * 6);
    iVar2 = 0;
    puVar4 = puVar4 + (uint)local_24 * 6 + (uint)local_20 * 2;
    if (local_20 != 0) {
      do {
        *(uint **)(puVar3[4] + iVar2 * 8) = puVar4;
        puVar4 = puVar4 + local_24;
        iVar2 = iVar2 + 1;
      } while (iVar2 < (int)(uint)local_20);
    }
    iVar8 = 0;
    iVar2 = 0;
    if (local_24 != 0) {
      do {
        *(uint **)(iVar8 + puVar3[3]) = puVar4;
        iVar2 = iVar2 + 1;
        puVar4 = (uint *)((int)puVar4 + 5);
        iVar8 = iVar8 + 0x18;
      } while (iVar2 < (int)(uint)local_24);
    }
    local_30 = FUN_008b97e0(uVar1,(uint)local_28 + local_34);
    if (local_30 != 0) goto LAB_008f0fcc;
    piVar9 = (int *)puVar3[3];
    local_34 = 0;
    if (local_24 != 0) {
      do {
        local_30 = 0;
        local_30 = FUN_008bacd0(uVar1,&DAT_00beaf88,&local_1c);
        if (local_30 != 0) goto LAB_008f0fcc;
        piVar9[4] = local_1c;
        piVar9[1] = local_18;
        piVar9[2] = local_14;
        piVar9[3] = local_10;
        piVar9[5] = (uint)local_a;
        *(char *)*piVar9 = (char)((uint)local_1c >> 0x18);
        *(undefined1 *)(*piVar9 + 1) = *(undefined1 *)((int)piVar9 + 0x12);
        *(undefined1 *)(*piVar9 + 2) = *(undefined1 *)((int)piVar9 + 0x11);
        *(char *)(*piVar9 + 3) = (char)piVar9[4];
        *(undefined1 *)(*piVar9 + 4) = 0;
        local_34 = local_34 + 1;
        piVar9 = piVar9 + 6;
      } while (local_34 < (int)(uint)local_24);
    }
    piVar9 = (int *)puVar3[4];
    local_34 = 0;
    if (local_20 != 0) {
      do {
        local_30 = FUN_008babe0(uVar1,(uint)local_24 * 4 + 4);
        if (local_30 != 0) goto LAB_008f0fcc;
        uVar5 = FUN_008b9960(uVar1);
        piVar9[1] = uVar5 & 0xffff;
        FUN_008b9960(uVar1);
        iVar2 = 0;
        if (local_24 != 0) {
          do {
            uVar6 = FUN_008b99c0(uVar1);
            *(undefined4 *)(*piVar9 + iVar2 * 4) = uVar6;
            iVar2 = iVar2 + 1;
          } while (iVar2 < (int)(uint)local_24);
        }
        FUN_008baca0(uVar1);
        local_34 = local_34 + 1;
        piVar9 = piVar9 + 2;
      } while (local_34 < (int)(uint)local_20);
    }
  }
  iVar2 = local_3c;
  if ((local_40 != (undefined4 *)0x0) &&
     (puVar3 = (uint *)FUN_008baee0(local_38,*(undefined4 *)(*(int *)(local_3c + 0x2a4) + 0xc),
                                    &local_30), local_30 == 0)) {
    FID_conflict__memcpy
              (puVar3,*(void **)(*(int *)(iVar2 + 0x2a4) + 8),
               *(size_t *)(*(int *)(iVar2 + 0x2a4) + 0xc));
    puVar4 = puVar3 + 5;
    puVar3[3] = (uint)puVar4;
    puVar3[4] = (uint)(puVar4 + *puVar3 * 6);
    puVar4 = puVar4 + *puVar3 * 6 + puVar3[2] * 2;
    uVar5 = 0;
    if (puVar3[2] != 0) {
      do {
        *(uint **)(puVar3[4] + uVar5 * 8) = puVar4;
        uVar5 = uVar5 + 1;
        puVar4 = puVar4 + *puVar3;
      } while (uVar5 < puVar3[2]);
    }
    puVar7 = (undefined4 *)puVar3[3];
    uVar5 = 0;
    if (*puVar3 != 0) {
      do {
        iVar2 = puVar7[4];
        *puVar7 = puVar4;
        if (iVar2 == 0x77676874) {
          *puVar7 = "Weight";
        }
        else if (iVar2 == 0x77647468) {
          *puVar7 = "Width";
        }
        else if (iVar2 == 0x6f70737a) {
          *puVar7 = "OpticalSize";
        }
        else if (iVar2 == 0x736c6e74) {
          *puVar7 = "Slant";
        }
        uVar5 = uVar5 + 1;
        puVar4 = (uint *)((int)puVar4 + 5);
        puVar7 = puVar7 + 6;
      } while (uVar5 < *puVar3);
    }
    *local_40 = puVar3;
  }
LAB_008f0fcc:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

