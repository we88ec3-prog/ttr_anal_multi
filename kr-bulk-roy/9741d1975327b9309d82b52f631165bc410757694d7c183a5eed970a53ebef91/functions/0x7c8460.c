
void FUN_007c8460(void)

{
  float *pfVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int in_stack_0000001c;
  float in_stack_0000004c;
  int in_stack_00000050;
  undefined1 local_ac [4];
  undefined1 local_a8 [4];
  undefined1 local_a4 [4];
  uint local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float *local_84;
  float local_80;
  float local_7c;
  float local_78;
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
  float local_44;
  int local_3c;
  ushort local_38;
  ushort local_36;
  ushort local_34 [2];
  uint local_30;
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
  piVar2 = *(int **)(in_stack_0000001c + 0x44);
  iVar4 = 0;
  local_3c = 0;
  if ((piVar2 != (int *)0x0) && (*(int *)(in_stack_0000001c + 0x40) != 0)) {
    iVar3 = FUN_00857520(0);
    if (iVar3 != 0) {
      iVar4 = *(int *)(iVar3 + 0xc);
    }
    local_a0 = (piVar2[1] - *piVar2) / 0x14;
    local_30 = 0;
    if (local_a0 != 0) {
      do {
        FUN_00857b70(local_30,&local_38,&local_36,local_34,local_a8);
        FUN_007cd220();
        pfVar1 = (float *)(iVar4 + (uint)local_38 * 0xc);
        local_9c = pfVar1[2] * local_58 + pfVar1[1] * local_64 + *pfVar1 * local_70 + local_4c;
        local_98 = pfVar1[2] * local_54 + *pfVar1 * local_6c + pfVar1[1] * local_60 + local_48;
        local_94 = local_50 * pfVar1[2] + *pfVar1 * local_68 + local_5c * pfVar1[1] + local_44;
        local_2c = local_9c;
        local_28 = local_98;
        local_24 = local_94;
        FUN_007cd220();
        pfVar1 = (float *)(iVar4 + (uint)local_36 * 0xc);
        local_80 = local_58 * pfVar1[2] + local_64 * pfVar1[1] + local_70 * *pfVar1 + local_4c;
        local_7c = local_54 * pfVar1[2] + local_60 * pfVar1[1] + local_6c * *pfVar1 + local_48;
        local_78 = local_50 * pfVar1[2] + local_5c * pfVar1[1] + local_68 * *pfVar1 + local_44;
        local_20 = local_80;
        local_1c = local_7c;
        local_18 = local_78;
        FUN_007cd220();
        pfVar1 = (float *)(iVar4 + (uint)local_34[0] * 0xc);
        local_90 = pfVar1[2] * local_58 + pfVar1[1] * local_64 + *pfVar1 * local_70 + local_4c;
        local_8c = pfVar1[2] * local_54 + pfVar1[1] * local_60 + *pfVar1 * local_6c + local_48;
        local_88 = pfVar1[2] * local_50 + pfVar1[1] * local_5c + *pfVar1 * local_68 + local_44;
        local_14 = local_90;
        local_10 = local_8c;
        local_c = local_88;
        iVar3 = FUN_007c81e0(&stack0x00000010,&local_20,&local_74,local_ac,local_a4,0);
        if (((iVar3 != 0) && (local_74 < in_stack_0000004c)) &&
           (local_3c = local_3c + 1, local_84 != (float *)0x0)) {
          if (in_stack_00000050 == 1) {
            if (*local_84 < local_74) {
              *local_84 = local_74;
            }
          }
          else if (local_74 < *local_84) {
            *local_84 = local_74;
          }
        }
        local_30 = local_30 + 1;
      } while (local_30 < local_a0);
    }
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

