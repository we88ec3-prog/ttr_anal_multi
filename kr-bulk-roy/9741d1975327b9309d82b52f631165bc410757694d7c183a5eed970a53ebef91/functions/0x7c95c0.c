
void FUN_007c95c0(int param_1,int param_2)

{
  float *pfVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  float in_stack_00000038;
  undefined1 local_b4 [4];
  undefined1 local_b0 [4];
  undefined1 local_ac [4];
  float local_a8;
  int local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float *local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  uint local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  int local_40;
  uint local_3c;
  ushort local_38;
  ushort local_36;
  ushort local_34 [2];
  int local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_40 = param_1;
  piVar2 = *(int **)(param_2 + 0x44);
  iVar4 = 0;
  local_30 = 0;
  if ((piVar2 != (int *)0x0) && (*(int *)(param_2 + 0x40) != 0)) {
    iVar3 = FUN_00857520(0);
    if (iVar3 != 0) {
      iVar4 = *(int *)(iVar3 + 0xc);
    }
    local_78 = (piVar2[1] - *piVar2) / 0x14;
    local_3c = 0;
    if (local_78 != 0) {
      do {
        FUN_00857b70(local_3c,&local_38,&local_36,local_34,local_ac);
        FUN_007cd220();
        pfVar1 = (float *)(iVar4 + (uint)local_38 * 0xc);
        local_84 = pfVar1[2] * local_5c + *pfVar1 * local_74 + pfVar1[1] * local_68 + local_50;
        local_80 = local_58 * pfVar1[2] + *pfVar1 * local_70 + pfVar1[1] * local_64 + local_4c;
        local_7c = local_54 * pfVar1[2] + *pfVar1 * local_6c + local_60 * pfVar1[1] + local_48;
        local_2c = local_84;
        local_28 = local_80;
        local_24 = local_7c;
        FUN_007cd220();
        pfVar1 = (float *)(iVar4 + (uint)local_36 * 0xc);
        local_90 = local_5c * pfVar1[2] + local_74 * *pfVar1 + local_68 * pfVar1[1] + local_50;
        local_8c = local_58 * pfVar1[2] + local_70 * *pfVar1 + local_64 * pfVar1[1] + local_4c;
        local_88 = local_54 * pfVar1[2] + local_6c * *pfVar1 + local_60 * pfVar1[1] + local_48;
        local_20 = local_90;
        local_1c = local_8c;
        local_18 = local_88;
        FUN_007cd220();
        pfVar1 = (float *)(iVar4 + (uint)local_34[0] * 0xc);
        local_a0 = pfVar1[2] * local_5c + local_74 * *pfVar1 + pfVar1[1] * local_68 + local_50;
        local_9c = pfVar1[2] * local_58 + local_70 * *pfVar1 + pfVar1[1] * local_64 + local_4c;
        local_98 = pfVar1[2] * local_54 + local_6c * *pfVar1 + pfVar1[1] * local_60 + local_48;
        local_14 = local_a0;
        local_10 = local_9c;
        local_c = local_98;
        iVar3 = FUN_007c81e0(local_40 + 0xc,&local_20,&local_a8,local_b4,local_b0,&local_a4);
        if ((((iVar3 != 0) && (local_a8 < in_stack_00000038)) && (local_a4 == 1)) &&
           ((local_30 = local_30 + 1, local_94 != (float *)0x0 && (*local_94 < local_a8)))) {
          *local_94 = local_a8;
        }
        local_3c = local_3c + 1;
      } while (local_3c < local_78);
    }
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

