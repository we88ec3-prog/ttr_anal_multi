
void FUN_007586b0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,uint param_4,int param_5
                 ,int param_6,int param_7,int param_8,int param_9,int param_10)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 **ppuVar5;
  int *unaff_ESI;
  int iVar6;
  int local_e8 [4];
  uint local_d8;
  int *local_d4;
  int local_d0;
  undefined4 local_cc;
  int local_c4;
  int local_c0;
  undefined4 *local_bc;
  int local_b8;
  undefined4 *local_b4;
  int local_b0;
  float local_ac;
  undefined4 local_a8;
  int local_a4;
  int local_a0;
  int *local_9c;
  int local_98;
  int local_94;
  int local_90;
  float local_8c;
  undefined4 *local_88;
  undefined4 *local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  undefined4 *local_70;
  int local_6c;
  int local_68;
  undefined4 *local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  undefined4 *local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090a6d6;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  if (unaff_ESI != (int *)0x0) {
    if (unaff_ESI[2] == 0) {
      local_8c = 1.33;
    }
    else {
      local_8c = *(float *)(unaff_ESI[2] + 0x80);
    }
    local_ac = (float)unaff_ESI[4];
    if (unaff_ESI[4] < 0) {
      local_ac = local_ac + 4.2949673e+09;
    }
    local_ac = local_ac * local_8c;
    local_d4 = (int *)0x0;
    local_d0 = 0;
    local_cc = 0;
    local_e8[0] = 0;
    local_e8[1] = 0;
    local_e8[2] = 0;
    local_8 = 1;
    FUN_00758180(param_1,&local_d4,local_e8,unaff_ESI,&param_7,param_3,param_4);
    local_c4 = param_9 - param_7;
    local_8c = (float)(param_10 - param_8);
    iVar6 = local_d0 - (int)local_d4 >> 2;
    local_b0 = param_5;
    local_a4 = iVar6;
    if ((param_4 & 4) == 0) {
      if ((param_4 & 8) == 0) {
        local_90 = 0;
      }
      else {
        local_90 = FUN_008fed10(uVar1);
      }
    }
    else {
      local_90 = FUN_008fed10(uVar1);
    }
    local_bc = (undefined4 *)param_1[7];
    local_b4 = (undefined4 *)*local_bc;
    if (0 < iVar6) {
      local_d8 = param_4 & 1;
      local_c0 = FUN_008fed10(uVar1);
      local_a4 = local_e8[0] - (int)local_d4;
      local_9c = local_d4;
      local_ac = (float)iVar6;
      do {
        iVar6 = *local_9c;
        local_a8 = *(undefined4 *)(local_a4 + (int)local_9c);
        local_98 = 0;
        local_8c = 0.0;
        puVar4 = param_1;
        if (7 < (uint)param_1[5]) {
          puVar4 = (undefined4 *)*param_1;
        }
        (**(code **)(*unaff_ESI + 0x30))(&local_98,&local_8c,(int)puVar4 + iVar6 * 2,local_a8);
        if (local_d8 == 0) {
          if ((param_4 & 2) == 0) {
            local_a0 = 0;
          }
          else {
            local_a0 = local_c4 - local_98;
          }
        }
        else {
          local_a0 = (local_c4 - local_98) / 2;
        }
        puVar4 = param_1;
        if (param_6 == 2) {
          local_88 = (undefined4 *)(local_a0 + param_7);
          local_b8 = local_90 + param_8;
          if (((int)local_88 < param_9) && (local_b8 < param_10)) {
            local_54 = (int)local_88 + 1;
            local_4c = param_9 + 1;
            local_94 = local_b8 + -1;
            local_48 = param_10 + -1;
            puVar2 = param_1;
            if (7 < (uint)param_1[5]) {
              puVar2 = (undefined4 *)*param_1;
            }
            local_50 = local_94;
            (**(code **)(*unaff_ESI + 0x28))
                      ((int)puVar2 + iVar6 * 2,&local_54,local_a8,0,0xff000000,0);
            local_24 = (int)local_88 + 1;
            local_1c = param_9 + 1;
            local_b8 = local_b8 + 1;
            local_18 = param_10 + 1;
            puVar2 = param_1;
            if (7 < (uint)param_1[5]) {
              puVar2 = (undefined4 *)*param_1;
            }
            local_20 = local_b8;
            (**(code **)(*unaff_ESI + 0x28))
                      ((int)puVar2 + iVar6 * 2,&local_24,local_a8,0,0xff000000,0);
            local_88 = (undefined4 *)((int)local_88 + -1);
            local_3c = param_9 + -1;
            local_38 = param_10 + 1;
            local_40 = local_b8;
            puVar2 = param_1;
            if (7 < (uint)param_1[5]) {
              puVar2 = (undefined4 *)*param_1;
            }
            local_44 = local_88;
            (**(code **)(*unaff_ESI + 0x28))
                      ((int)puVar2 + iVar6 * 2,&local_44,local_a8,0,0xff000000,0);
            local_64 = local_88;
            local_5c = param_9 + -1;
            local_58 = param_10 + -1;
            local_60 = local_94;
            if (7 < (uint)param_1[5]) {
              puVar4 = (undefined4 *)*param_1;
            }
            ppuVar5 = &local_64;
LAB_00758ab2:
            (**(code **)(*unaff_ESI + 0x28))
                      ((int)puVar4 + iVar6 * 2,ppuVar5,local_a8,0,0xff000000,0);
          }
        }
        else if (param_6 == 1) {
          if ((local_a0 + param_7 < param_9) && (local_90 + param_8 < param_10)) {
            local_84 = (undefined4 *)(local_a0 + param_7 + 1);
            local_7c = param_9 + 1;
            local_80 = local_90 + param_8 + 1;
            local_78 = param_10 + 1;
            if (7 < (uint)param_1[5]) {
              puVar4 = (undefined4 *)*param_1;
            }
            ppuVar5 = &local_84;
            goto LAB_00758ab2;
          }
        }
        if (local_b4 != local_bc) {
          do {
            local_94 = local_b4[2];
            iVar3 = *local_9c;
            if ((local_94 < iVar3) || (*(int *)(local_a4 + (int)local_9c) + iVar3 < local_94))
            break;
            local_94 = local_94 - iVar6;
            if (0 < local_94) {
              if ((uint)param_1[5] < 8) {
                local_88 = param_1;
              }
              else {
                local_88 = (undefined4 *)*param_1;
              }
              (**(code **)(*unaff_ESI + 0x30))
                        (&local_98,&local_8c,(int)local_88 + iVar3 * 2,iVar6 - iVar3);
              iVar3 = local_98 + param_7 + local_a0;
              if ((iVar3 < param_9) && (local_90 + param_8 < param_10)) {
                local_2c = param_9;
                local_28 = param_10;
                puVar4 = param_1;
                if (7 < (uint)param_1[5]) {
                  puVar4 = (undefined4 *)*param_1;
                }
                local_34 = iVar3;
                local_30 = local_90 + param_8;
                (**(code **)(*unaff_ESI + 0x28))
                          ((int)puVar4 + iVar6 * 2,&local_34,local_94,0,local_b0,1);
              }
            }
            iVar6 = local_b4[2];
            local_b0 = local_b4[3];
            if (local_b4[3] == 0xffffff) {
              local_b0 = param_5;
            }
            local_b4 = (undefined4 *)*local_b4;
          } while (local_b4 != local_bc);
        }
        local_94 = (*local_9c - iVar6) + *(int *)(local_a4 + (int)local_9c);
        if (0 < local_94) {
          if ((uint)param_1[5] < 8) {
            local_88 = param_1;
          }
          else {
            local_88 = (undefined4 *)*param_1;
          }
          (**(code **)(*unaff_ESI + 0x30))
                    (&local_98,&local_8c,(int)local_88 + *local_9c * 2,iVar6 - *local_9c);
          iVar3 = local_98 + param_7 + local_a0;
          local_88 = (undefined4 *)(param_8 + local_90);
          if ((iVar3 < param_9) && ((int)local_88 < param_10)) {
            local_6c = param_9;
            local_68 = param_10;
            puVar4 = param_1;
            if (7 < (uint)param_1[5]) {
              puVar4 = (undefined4 *)*param_1;
            }
            local_74 = iVar3;
            local_70 = local_88;
            (**(code **)(*unaff_ESI + 0x28))
                      ((int)puVar4 + iVar6 * 2,&local_74,local_94,0,local_b0,1);
          }
        }
        local_90 = local_90 + local_c0;
        local_9c = local_9c + 1;
        local_ac = (float)((int)local_ac + -1);
      } while (local_ac != 0.0);
      local_ac = 0.0;
    }
    if (local_e8[0] != 0) {
      FUN_0089120c(local_e8[0]);
    }
    if (local_d4 != (int *)0x0) {
      FUN_0089120c(local_d4);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

