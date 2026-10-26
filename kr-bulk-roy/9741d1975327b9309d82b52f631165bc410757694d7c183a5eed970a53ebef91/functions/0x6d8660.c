
void FUN_006d8660(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 **ppuVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *in_ECX;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 *puVar8;
  uint uVar9;
  ushort *puVar10;
  uint uVar11;
  uint uVar12;
  undefined4 *puVar13;
  undefined2 in_FPUControlWord;
  undefined4 local_64;
  undefined8 local_60;
  undefined4 *local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  undefined4 local_44;
  ushort *local_40;
  undefined4 *local_3c;
  undefined4 *local_38;
  undefined1 local_34 [8];
  undefined1 auStack_2c [16];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009356cc;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_64;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffff90);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 1;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_c = 0xffffffff;
  local_44 = FUN_0079a5f0(&DAT_00fb76a8);
  puVar10 = (ushort *)*in_ECX;
  local_40 = (ushort *)in_ECX[1];
  puVar13 = DAT_00fab13c;
  if (puVar10 != (ushort *)in_ECX[1]) {
    do {
      puVar2 = (undefined4 *)puVar13[1];
      cVar1 = *(char *)((int)puVar2 + 0x15);
      puVar6 = puVar2;
      local_58 = puVar13;
      while (puVar8 = puVar6, cVar1 == '\0') {
        if ((uint)puVar8[3] < (uint)*puVar10) {
          puVar6 = (undefined4 *)puVar8[2];
          puVar8 = local_58;
        }
        else {
          puVar6 = (undefined4 *)*puVar8;
        }
        cVar1 = *(char *)((int)puVar6 + 0x15);
        local_58 = puVar8;
      }
      if ((local_58 == puVar13) || ((uint)*puVar10 < (uint)local_58[3])) {
        local_38 = puVar13;
        ppuVar3 = &local_38;
      }
      else {
        ppuVar3 = &local_58;
      }
      if (*ppuVar3 == puVar13) {
        local_58 = (undefined4 *)0x0;
      }
      else {
        local_58 = (undefined4 *)(*ppuVar3)[4];
      }
      cVar1 = *(char *)((int)puVar2 + 0x15);
      local_64 = puVar13;
      while (puVar6 = puVar2, cVar1 == '\0') {
        if ((uint)puVar6[3] < (uint)puVar10[1]) {
          puVar2 = (undefined4 *)puVar6[2];
          puVar6 = local_64;
        }
        else {
          puVar2 = (undefined4 *)*puVar6;
        }
        cVar1 = *(char *)((int)puVar2 + 0x15);
        local_64 = puVar6;
      }
      if ((local_64 == puVar13) || ((uint)puVar10[1] < (uint)local_64[3])) {
        local_3c = puVar13;
        ppuVar3 = &local_3c;
      }
      else {
        ppuVar3 = (undefined4 **)&local_64;
      }
      if (*ppuVar3 == puVar13) {
        piVar7 = (int *)0x0;
      }
      else {
        piVar7 = (int *)(*ppuVar3)[4];
      }
      if ((local_58 != (undefined4 *)0x0) && (piVar7 != (int *)0x0)) {
        local_64 = (undefined4 *)(*(float *)(puVar10 + 0xc) / *(float *)(puVar10 + 10));
        local_54 = (float)local_64 * *(float *)(puVar10 + 2);
        local_50 = *(float *)(puVar10 + 4) * (float)local_64;
        local_4c = *(float *)(puVar10 + 6) * (float)local_64;
        local_48 = (float)local_64 * *(float *)(puVar10 + 8);
        if (local_54 < 1.0) {
          if (0.0 < local_54) {
            local_64._2_2_ = (undefined2)((uint)local_64 >> 0x10);
            local_64 = (undefined4 *)CONCAT22(local_64._2_2_,in_FPUControlWord);
            local_60 = (longlong)ROUND(local_54 * 255.0 + 0.5);
            uVar11 = (uint)local_60;
          }
          else {
            uVar11 = 0;
          }
        }
        else {
          uVar11 = 0xff;
        }
        if (local_50 < 1.0) {
          if (0.0 < local_50) {
            local_64 = (undefined4 *)CONCAT22(local_64._2_2_,in_FPUControlWord);
            local_60 = (longlong)ROUND(local_50 * 255.0 + 0.5);
            uVar12 = (uint)local_60;
          }
          else {
            uVar12 = 0;
          }
        }
        else {
          uVar12 = 0xff;
        }
        if (local_4c < 1.0) {
          if (0.0 < local_4c) {
            local_64 = (undefined4 *)CONCAT22(local_64._2_2_,in_FPUControlWord);
            local_60 = (longlong)ROUND(local_4c * 255.0 + 0.5);
            uVar9 = (uint)local_60;
          }
          else {
            uVar9 = 0;
          }
        }
        else {
          uVar9 = 0xff;
        }
        if (local_48 < 1.0) {
          if (0.0 < local_48) {
            local_64 = (undefined4 *)CONCAT22(local_64._2_2_,in_FPUControlWord);
            local_60 = (longlong)ROUND(local_48 * 255.0 + 0.5);
            iVar4 = (uint)local_60;
          }
          else {
            iVar4 = 0;
          }
        }
        else {
          iVar4 = 0xff;
        }
        uVar5 = (**(code **)(*piVar7 + 0x50))
                          (local_34,((iVar4 << 8 | uVar11) << 8 | uVar12) << 8 | uVar9);
        (**(code **)(*local_60._4_4_ + 0x50))(auStack_2c,uVar5);
        FUN_007ccc00();
        puVar13 = DAT_00fab13c;
      }
      puVar10 = puVar10 + 0xe;
    } while (puVar10 != local_40);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_64);
  return;
}

