
void FUN_007caa30(int param_1)

{
  float *pfVar1;
  int *piVar2;
  int iVar3;
  undefined4 in_EDX;
  int iVar4;
  float10 fVar5;
  undefined1 local_a0 [4];
  uint local_9c;
  undefined4 local_98;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
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
  float local_40;
  uint local_38;
  ushort local_34;
  ushort local_32;
  ushort local_30 [2];
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
  iVar4 = *(int *)(param_1 + 0x78);
  if (iVar4 != 0) {
    piVar2 = *(int **)(iVar4 + 0x44);
    if ((piVar2 != (int *)0x0) && (*(int *)(iVar4 + 0x40) != 0)) {
      iVar4 = 0;
      local_98 = in_EDX;
      iVar3 = FUN_00857520(0);
      if (iVar3 != 0) {
        iVar4 = *(int *)(iVar3 + 0xc);
      }
      local_9c = (piVar2[1] - *piVar2) / 0x14;
      local_38 = 0;
      if (local_9c != 0) {
        do {
          fVar5 = (float10)FUN_00857b70(local_38,&local_34,&local_32,local_30,local_a0);
          local_2c = (float)fVar5;
          local_28 = (float)fVar5;
          local_24 = (float)fVar5;
          local_20 = (float)fVar5;
          local_1c = (float)fVar5;
          local_18 = (float)fVar5;
          local_14 = (float)fVar5;
          local_10 = (float)fVar5;
          local_c = (float)fVar5;
          FUN_007cd220();
          pfVar1 = (float *)(iVar4 + (uint)local_34 * 0xc);
          local_78 = pfVar1[2] * local_54 + pfVar1[1] * local_60 + *pfVar1 * local_6c + local_48;
          local_74 = pfVar1[2] * local_50 + pfVar1[1] * local_5c + *pfVar1 * local_68 + local_44;
          local_70 = local_4c * pfVar1[2] + local_64 * *pfVar1 + local_58 * pfVar1[1] + local_40;
          local_2c = local_78;
          local_28 = local_74;
          local_24 = local_70;
          FUN_007cd220();
          pfVar1 = (float *)(iVar4 + (uint)local_32 * 0xc);
          local_84 = local_54 * pfVar1[2] + local_60 * pfVar1[1] + local_6c * *pfVar1 + local_48;
          local_80 = local_50 * pfVar1[2] + local_5c * pfVar1[1] + local_68 * *pfVar1 + local_44;
          local_7c = local_4c * pfVar1[2] + local_58 * pfVar1[1] + local_64 * *pfVar1 + local_40;
          local_20 = local_84;
          local_1c = local_80;
          local_18 = local_7c;
          FUN_007cd220();
          pfVar1 = (float *)(iVar4 + (uint)local_30[0] * 0xc);
          local_90 = pfVar1[2] * local_54 + pfVar1[1] * local_60 + *pfVar1 * local_6c + local_48;
          local_8c = pfVar1[2] * local_50 + pfVar1[1] * local_5c + *pfVar1 * local_68 + local_44;
          local_88 = pfVar1[2] * local_4c + pfVar1[1] * local_58 + *pfVar1 * local_64 + local_40;
          local_14 = local_90;
          local_10 = local_8c;
          local_c = local_88;
          iVar3 = FUN_007c9f20(&local_2c,local_98);
          if (iVar3 != 0) {
            __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
            return;
          }
          local_38 = local_38 + 1;
        } while (local_38 < local_9c);
      }
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

