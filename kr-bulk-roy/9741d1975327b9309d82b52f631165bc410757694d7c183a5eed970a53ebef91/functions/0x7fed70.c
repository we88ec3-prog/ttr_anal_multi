
void FUN_007fed70(void)

{
  int unaff_ESI;
  float10 fVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  float fStack_dc;
  float local_d8;
  float fStack_d4;
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  undefined4 local_ac;
  float local_a8;
  float local_a4;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined1 local_34 [48];
  
  local_bc = 0.0;
  local_b8 = 0.0;
  local_b4 = 0.0;
  local_b0 = 0.0;
  local_d8 = 1.4013e-45;
  local_ac = 0;
  local_38 = 1;
  local_a8 = 0.0;
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0x3f800000;
  local_a4 = 4.2039e-45;
  local_44 = 0x3f800000;
  local_40 = 0x3f800000;
  local_3c = 0x3f800000;
  FUN_007c75c0(*(undefined4 *)(unaff_ESI + 0x28),&local_bc,&local_60,&local_d8,1,1);
  puVar3 = local_34;
  (**(code **)(**(int **)(unaff_ESI + 0x28) + 0x24))(puVar3);
  FUN_007cd220();
  local_d8 = local_bc * fStack_98 + fStack_c0 * local_a4 + local_b8 * fStack_8c + fStack_80;
  fStack_d4 = fStack_88 * local_b8 + fStack_a0 * fStack_c0 + fStack_94 * local_bc + fStack_7c;
  fStack_d0 = local_b8 * fStack_84 + fStack_90 * local_bc + fStack_9c * fStack_c0 + fStack_78;
  puVar2 = &local_38;
  (**(code **)(**(int **)(unaff_ESI + 0x28) + 0x24))(puVar2);
  FUN_007cd220();
  fStack_74 = local_b4 * fStack_9c + local_b8 * local_a8 + local_b0 * fStack_90 + fStack_84;
  fStack_70 = fStack_8c * local_b0 + local_a4 * local_b8 + fStack_98 * local_b4 + fStack_80;
  fStack_6c = local_b0 * fStack_88 + fStack_94 * local_b4 + fStack_a0 * local_b8 + fStack_7c;
  fStack_d0 = fStack_dc - fStack_74;
  *(float *)(unaff_ESI + 0x34) = (fStack_dc + fStack_74) * 0.5;
  *(float *)(unaff_ESI + 0x38) = (local_d8 + fStack_70) * 0.5;
  *(float *)(unaff_ESI + 0x3c) = (fStack_d4 + fStack_6c) * 0.5;
  fStack_cc = local_d8 - fStack_70;
  fStack_c8 = fStack_d4 - fStack_6c;
  local_d8 = fStack_cc * 0.5;
  fStack_d4 = fStack_c8 * 0.5;
  fVar1 = (float10)FUN_008ff870(puVar2,puVar3,
                                fStack_d4 * fStack_d4 +
                                fStack_d0 * 0.5 * fStack_d0 * 0.5 + local_d8 * local_d8);
  *(undefined4 *)(unaff_ESI + 0x44) = 0;
  *(float *)(unaff_ESI + 0x40) = (float)fVar1;
  return;
}

