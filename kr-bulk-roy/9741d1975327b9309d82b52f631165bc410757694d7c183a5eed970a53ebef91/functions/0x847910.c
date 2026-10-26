
undefined4 FUN_00847910(int param_1,undefined4 *param_2)

{
  float *pfVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  void *pvVar9;
  float10 fVar10;
  int local_68;
  void *local_64;
  void *local_60;
  uint local_5c;
  int local_58;
  void *local_54;
  uint local_50;
  uint local_4c;
  undefined8 local_48;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  
  local_48._0_4_ = (void *)0xa2500000;
  FUN_0082ef00(&local_48);
  if (local_4c != *(int *)(param_1 + 0x38)) {
    iVar7 = 0;
    if (((*(int *)(local_4c + 0x10) != 0) && (*(int *)(*(int *)(local_4c + 0x10) + 0x30) != 0)) &&
       (*(int *)(param_1 + 0x78) != 0)) {
      local_68 = 0;
      local_50 = 0;
      local_58 = 0;
      local_60 = (void *)0x0;
      local_48._0_4_ = (void *)0x0;
      iVar4 = FUN_00857520(0);
      if (iVar4 != 0) {
        local_60 = *(void **)(iVar4 + 0xc);
        iVar7 = *(int *)(iVar4 + 8);
      }
      local_5c = (uint)(iVar4 != 0);
      iVar4 = FUN_00857520(3);
      if (iVar4 == 0) {
        local_4c = 0;
      }
      else {
        local_68 = *(int *)(iVar4 + 8);
        local_48._0_4_ = *(void **)(iVar4 + 0xc);
        local_4c = 1;
        iVar4 = FUN_00857520(6);
        if (iVar4 != 0) {
          local_50 = *(undefined4 *)(iVar4 + 8);
        }
        iVar4 = FUN_00857520(7);
        if (iVar4 != 0) {
          local_58 = *(undefined4 *)(iVar4 + 8);
        }
      }
      iVar4 = local_68;
      local_54 = (void *)0x0;
      local_64 = (void *)0x0;
      FUN_00845670();
      pvVar9 = (void *)0x0;
      if (local_5c != 0) {
        local_54 = (void *)FUN_008456c0();
        FID_conflict__memcpy(local_54,local_60,iVar7 * 0xc);
        iVar4 = local_68;
        pvVar9 = local_54;
      }
      if (local_4c != 0) {
        local_64 = (void *)FUN_008456c0();
        FID_conflict__memcpy(local_64,(void *)local_48,iVar4 * 0xc);
      }
      local_48._0_4_ = (void *)0xa2500000;
      FUN_0082ef00(&local_48);
      if (((local_4c != *(int *)(param_1 + 0x38)) && (*(int *)(local_4c + 0x10) != 0)) &&
         (uVar6 = *(uint *)(*(int *)(local_4c + 0x10) + 0x30), uVar6 != 0)) {
        local_3c = 0.0;
        local_48 = (double)((ulonglong)local_48._4_4_ << 0x20);
        local_38 = 0.0;
        local_68 = 0;
        local_34 = 0.0;
        local_18 = 0.0;
        local_14 = 0.0;
        local_10 = 0.0;
        local_c = 1.0;
        local_4c = uVar6;
        iVar7 = FUN_008462f0(&local_48,&local_68);
        if ((iVar7 != 0) && (local_50 = 0, uVar6 != 0)) {
          puVar8 = (uint *)((int)(void *)local_48 + 0x1c);
          do {
            if (0.0 < *(float *)(local_68 + local_50 * 4)) {
              uVar6 = 0;
              if (*puVar8 != 0) {
                iVar7 = 0;
                do {
                  local_28 = *(float *)(local_68 + local_50 * 4);
                  uVar3 = puVar8[2];
                  local_48 = (double)CONCAT44(local_48._4_4_,local_28);
                  uVar6 = uVar6 + 1;
                  pfVar1 = (float *)(uVar3 + iVar7);
                  iVar7 = iVar7 + 0xc;
                  local_30 = local_28 * *pfVar1;
                  local_2c = *(float *)((uVar3 - 8) + iVar7) * local_28;
                  local_28 = local_28 * *(float *)((uVar3 - 4) + iVar7);
                  pfVar1 = (float *)((int)pvVar9 + *(int *)((puVar8[1] - 4) + uVar6 * 4) * 0xc);
                  *pfVar1 = local_30 + *pfVar1;
                  pfVar1[1] = pfVar1[1] + local_2c;
                  pfVar1[2] = pfVar1[2] + local_28;
                } while (uVar6 < *puVar8);
              }
              local_5c = 0;
              if (puVar8[3] != 0) {
                local_58 = 0;
                do {
                  FUN_00780b80(&local_60);
                  local_60 = (void *)(*(float *)(local_68 + local_50 * 4) * (float)local_60);
                  local_48 = (double)((float)local_60 * 0.5);
                  fVar10 = (float10)FUN_008ff0a0();
                  local_18 = (float)((float10)local_3c * fVar10);
                  local_14 = (float)((float10)local_38 * fVar10);
                  local_10 = (float)(fVar10 * (float10)local_34);
                  fVar10 = (float10)FUN_008fef70();
                  local_c = (float)fVar10;
                  puVar5 = (undefined4 *)FUN_0077e800();
                  local_58 = local_58 + 0x10;
                  puVar2 = (undefined4 *)((int)local_64 + *(int *)(puVar8[4] + local_5c * 4) * 0xc);
                  *puVar2 = *puVar5;
                  puVar2[1] = puVar5[1];
                  local_5c = local_5c + 1;
                  puVar2[2] = puVar5[2];
                  pvVar9 = local_54;
                } while (local_5c < puVar8[3]);
              }
            }
            local_50 = local_50 + 1;
            puVar8 = puVar8 + 0x16;
          } while (local_50 < local_4c);
        }
      }
      param_2[1] = local_64;
      *param_2 = pvVar9;
      param_2[3] = 0;
      param_2[2] = 0;
      return 1;
    }
  }
  return 0;
}

