
void FUN_0083e5b0(void)

{
  int *piVar1;
  int *piVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  int unaff_EDI;
  float *local_a8;
  undefined1 local_a4 [24];
  int local_8c;
  int local_88;
  float local_84;
  float local_80;
  float local_70;
  float *local_6c;
  float local_5c;
  float *local_58;
  float local_48;
  float local_44;
  float local_34;
  float local_30;
  float local_20;
  float *local_1c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  piVar2 = *(int **)(unaff_EDI + 0x454);
  piVar1 = (int *)(unaff_EDI + 0x454);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    *piVar1 = 0;
  }
  (**(code **)(**(int **)(unaff_EDI + 0x42c) + 0x30))(*(int **)(unaff_EDI + 0x42c),local_a4);
  fVar3 = (float)local_8c;
  if (local_8c < 0) {
    fVar3 = fVar3 + 4.2949673e+09;
  }
  fVar4 = (float)local_88;
  if (local_88 < 0) {
    fVar4 = fVar4 + 4.2949673e+09;
  }
  iVar7 = FUN_008fed10();
  iVar8 = FUN_008fed10();
  local_84 = 0.0;
  local_80 = 0.0;
  fVar5 = (float)iVar7;
  local_a8 = (float *)(float)iVar8;
  local_5c = 0.0;
  local_48 = 0.0;
  local_44 = 0.0;
  local_30 = 0.0;
  local_70 = fVar5;
  local_6c = local_a8;
  local_58 = local_a8;
  local_34 = fVar5;
  local_20 = fVar5;
  local_1c = local_a8;
  (**(code **)(**(int **)(unaff_EDI + 0xec) + 0x68))
            (*(int **)(unaff_EDI + 0xec),0x78,8,0,0,piVar1,0);
  piVar2 = (int *)*piVar1;
  if (piVar2 != (int *)0x0) {
    local_a8 = (float *)0x0;
    (**(code **)(*piVar2 + 0x2c))(piVar2,0,0,&local_a8,0);
    fVar6 = 0.0 / fVar3;
    local_84 = (fVar6 - 0.5) * 2.0;
    *local_a8 = local_84;
    local_80 = ((1.0 - local_80 / fVar4) - 0.5) * 2.0;
    local_a8[1] = local_80;
    fVar5 = fVar5 / fVar3;
    local_a8[2] = 1.0;
    local_a8[3] = 0.0;
    local_a8[4] = 0.0;
    local_70 = (fVar5 - 0.5) * 2.0;
    local_6c = (float *)(((1.0 - (float)local_6c / fVar4) - 0.5) * 2.0);
    local_a8[5] = local_70;
    local_a8[6] = (float)local_6c;
    local_a8[7] = 1.0;
    local_a8[8] = 1.0;
    local_a8[9] = 1.0;
    local_5c = (fVar6 - 0.5) * 2.0;
    local_a8[10] = local_5c;
    local_58 = (float *)(((1.0 - (float)local_58 / fVar4) - 0.5) * 2.0);
    local_a8[0xb] = (float)local_58;
    local_a8[0xc] = 1.0;
    local_a8[0xd] = 0.0;
    local_a8[0xe] = 1.0;
    local_48 = (fVar6 - 0.5) * 2.0;
    local_a8[0xf] = local_48;
    local_44 = ((1.0 - local_44 / fVar4) - 0.5) * 2.0;
    local_a8[0x10] = local_44;
    local_a8[0x11] = 1.0;
    local_a8[0x12] = 0.0;
    local_a8[0x13] = 0.0;
    local_34 = (fVar5 - 0.5) * 2.0;
    local_a8[0x14] = local_34;
    local_30 = ((1.0 - local_30 / fVar4) - 0.5) * 2.0;
    local_a8[0x15] = local_30;
    local_a8[0x16] = 1.0;
    local_a8[0x17] = 1.0;
    local_a8[0x18] = 0.0;
    local_20 = (fVar5 - 0.5) * 2.0;
    local_a8[0x19] = local_20;
    local_1c = (float *)(((1.0 - (float)local_1c / fVar4) - 0.5) * 2.0);
    local_a8[0x1a] = (float)local_1c;
    local_a8[0x1b] = 1.0;
    local_a8[0x1c] = 1.0;
    local_a8[0x1d] = 1.0;
    (**(code **)(*(int *)*piVar1 + 0x30))((int *)*piVar1);
    *(undefined4 *)(unaff_EDI + 0x458) = 0x14;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

