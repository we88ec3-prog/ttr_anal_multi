
void FUN_00802410(int param_1,float param_2)

{
  float fVar1;
  undefined4 *in_ECX;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  float10 fVar6;
  float fVar7;
  float fVar8;
  int local_13c;
  int local_138;
  int local_134;
  undefined1 local_124 [64];
  undefined1 local_e4 [64];
  undefined1 local_a4 [64];
  undefined4 local_64 [12];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (0.0 < *(float *)(param_1 + 0x1c)) {
    *(float *)(param_1 + 0x1c) = *(float *)(param_1 + 0x1c) - param_2;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  fVar1 = *(float *)(param_1 + 0x7c) / *(float *)(param_1 + 0x84);
  fVar6 = (float10)FUN_00801230(fVar1);
  *(float *)(param_1 + 0x1c) = (float)(fVar6 + (float10)*(float *)(param_1 + 0x1c));
  fVar6 = (float10)FUN_00801230(fVar1);
  local_14 = (float)fVar6;
  fVar6 = (float10)FUN_00801230(fVar1);
  local_10 = (float)fVar6;
  fVar6 = (float10)FUN_00801230(fVar1);
  local_c = (float)fVar6;
  D3DXMatrixTranslation(local_124,local_14,local_10,local_c);
  puVar4 = in_ECX;
  puVar5 = local_64;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  local_2c = 0;
  local_30 = 0;
  local_34 = 0;
  if (*(uint *)(param_1 + 0x88) < *(uint *)(param_1 + 0x8c)) {
    local_138 = 0;
    FUN_00801230(fVar1);
    iVar2 = FUN_008fed10();
    local_13c = 0;
    if (*(int *)(param_1 + 0x8c) != 0) {
      local_134 = 0;
      do {
        if (iVar2 <= local_138) break;
        piVar3 = (int *)(*(int *)(param_1 + 0xe8) + local_134);
        if (*piVar3 == 0) {
          local_20 = 0.0;
          local_1c = 0.0;
          local_18 = 1.0;
          (**(code **)(**(int **)(param_1 + 0xc) + 4))
                    (*(undefined4 *)(param_1 + 0x7c),&local_14,&local_20);
          D3DXMatrixMultiply(local_e4,local_124,in_ECX);
          D3DXVec3TransformCoord(&local_14,&local_14,local_e4);
          piVar3[0x14] = 0;
          piVar3[1] = (int)local_14;
          piVar3[2] = (int)local_10;
          piVar3[3] = (int)local_c;
          *piVar3 = 1;
          fVar6 = (float10)FUN_00801230(fVar1);
          piVar3[0x13] = (int)(float)fVar6;
          if (0.0 < (float)fVar6) {
            piVar3[1] = (int)local_14;
            piVar3[2] = (int)local_10;
            piVar3[3] = (int)local_c;
            FUN_008012a0();
            FUN_008012a0();
            FUN_008012a0();
            FUN_00801320();
            FUN_008012a0();
            fVar6 = (float10)FUN_00801230(fVar1);
            piVar3[0x21] = (int)(float)fVar6;
            FUN_008012a0();
            fVar6 = (float10)FUN_00801230(fVar1);
            fVar8 = (float)fVar6;
            fVar6 = (float10)FUN_00801230(fVar1);
            fVar7 = (float)fVar6;
            fVar6 = (float10)FUN_00801230(fVar1);
            D3DXMatrixRotationYawPitchRoll(local_a4,(float)fVar6,fVar7,fVar8);
            D3DXVec3TransformCoord(&local_20,&local_20,local_64);
            D3DXVec3TransformCoord(&local_20,&local_20,local_a4);
            fVar6 = (float10)FUN_00801230(fVar1);
            fVar8 = (float)fVar6;
            piVar3[4] = (int)(fVar8 * local_20);
            piVar3[5] = (int)(local_1c * fVar8);
            piVar3[6] = (int)(fVar8 * local_18);
            FUN_00801450();
            local_138 = local_138 + 1;
          }
        }
        local_134 = local_134 + 0x94;
        local_13c = local_13c + 1;
      } while (local_13c != *(int *)(param_1 + 0x8c));
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

