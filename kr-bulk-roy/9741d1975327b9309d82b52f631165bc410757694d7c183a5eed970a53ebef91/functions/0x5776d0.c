
void FUN_005776d0(int param_1,float param_2)

{
  float fVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  float10 fVar5;
  float10 extraout_ST0;
  undefined4 uVar6;
  undefined1 auStack_128 [20];
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined1 auStack_10c [20];
  undefined4 uStack_f8;
  undefined2 *puStack_f4;
  undefined1 auStack_f0 [16];
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  int iStack_d0;
  uint uStack_cc;
  undefined1 auStack_bc [4];
  float local_b8;
  undefined1 *local_b4;
  undefined1 *local_b0;
  undefined1 *local_ac;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092eb94;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_bc;
  uStack_cc = DAT_00d61f20 ^ (uint)&stack0xffffff38;
  ExceptionList = &local_14;
  switch(*(undefined4 *)(param_1 + 200)) {
  case 0:
    local_b8 = *(float *)(param_1 + 0xf4);
    if (local_b8 < 255.0 - param_2 * 500.0) {
      local_b8 = local_b8 + param_2 * 500.0;
      uVar4 = (int)local_b8 & 0xff;
      *(float *)(param_1 + 0xf4) = local_b8;
      *(uint *)(*(int *)(param_1 + 4) + 0x10) = ((uVar4 << 8 | uVar4) << 8 | uVar4) << 8 | uVar4;
      break;
    }
    *(undefined4 *)(*(int *)(param_1 + 4) + 0x10) = 0xffffffff;
    *(undefined4 *)(param_1 + 200) = 1;
    iStack_d0 = 0x5777a7;
    FUN_0040b3c0();
    local_c = 0;
    uStack_d4 = *(undefined4 *)(param_1 + 8);
    iStack_d0 = 2;
    uStack_d8 = 0x5777bf;
    FUN_00573170();
    iStack_d0 = 0x5777c4;
    FUN_007cf450();
    goto LAB_005777c4;
  case 2:
    if (*(float *)(param_1 + 0x1c) <= *(float *)(param_1 + 0xe4)) {
      local_b8 = *(float *)(param_1 + 0xec) * 150.0 * param_2;
      *(float *)(param_1 + 0x1c) = local_b8 + *(float *)(param_1 + 0x1c);
      *(float *)(param_1 + 0x38) = *(float *)(param_1 + 0x38) + local_b8;
      *(float *)(param_1 + 0x54) = local_b8 + *(float *)(param_1 + 0x54);
    }
    else {
      *(undefined4 *)(param_1 + 200) = 3;
      iStack_d0 = 0x5777ff;
      FUN_0040b3c0();
      local_c = 1;
      uStack_d4 = *(undefined4 *)(param_1 + 8);
      iStack_d0 = 1;
      uStack_d8 = 0x577817;
      FUN_00573170();
      local_c = 0xffffffff;
      iStack_d0 = 0x577827;
      FUN_007cf450();
      iStack_d0 = 0x577835;
      FUN_0040b3c0();
      local_c = 2;
      uStack_d4 = *(undefined4 *)(param_1 + 8);
      iStack_d0 = 0;
      uStack_d8 = 0x57784d;
      FUN_00573110();
      local_c = 0xffffffff;
      iStack_d0 = 0x57785d;
      FUN_007cf450();
      iStack_d0 = 0x57786b;
      FUN_0040b3c0();
      local_c = 3;
      uStack_d4 = *(undefined4 *)(param_1 + 8);
      iStack_d0 = 2;
      uStack_d8 = 0x577883;
      FUN_00573170();
      local_c = 0xffffffff;
      iStack_d0 = 0x577893;
      FUN_007cf450();
      iStack_d0 = 0x5778a4;
      FUN_0040b3c0();
      local_c = 4;
      uStack_d4 = *(undefined4 *)(param_1 + 8);
      iStack_d0 = 1;
      uStack_d8 = 0x5778bc;
      FUN_00573110();
      local_c = 0xffffffff;
      iStack_d0 = 0x5778cb;
      FUN_007cf450();
      iStack_d0 = 0x14;
      uStack_d4 = 0x5778d2;
      puVar3 = (undefined4 *)FUN_00891268();
      if (puVar3 == (undefined4 *)0x0) {
        iStack_d0 = 0x577908;
        FUN_004072a0();
      }
      else {
        *puVar3 = FoxUI::FXUIEvent::vftable;
        puVar3[1] = 0xffffffff;
        puVar3[2] = 0xffffffff;
        puVar3[3] = 0;
        puVar3[4] = 0xf42d8;
        iStack_d0 = 0x5778fa;
        FUN_004072a0();
      }
    }
    break;
  case 3:
    if (*(int *)(param_1 + 0x108) != 0) {
      *(undefined4 *)(param_1 + 200) = *(undefined4 *)(**(int **)(param_1 + 0x104) + 8);
      iStack_d0 = 0x57796c;
      FUN_0057e720();
      iStack_d0 = 0x577971;
      FUN_00414680();
      uStack_d4 = *(undefined4 *)(param_1 + 0xbc);
      uStack_d8 = *(undefined4 *)(param_1 + 0xb8);
      uStack_dc = *(undefined4 *)(param_1 + 0xb4);
      iStack_d0 = 0;
      uStack_e0 = 0x57798d;
      FUN_004a39f0();
      *(undefined4 *)(param_1 + 0x110) = 1;
    }
    break;
  case 5:
    iStack_d0 = 0;
    uStack_d4 = 0x5779a8;
    FUN_00577560();
    break;
  case 6:
    iStack_d0 = 1;
    uStack_d4 = 0x5779b9;
    FUN_00577560();
    break;
  case 7:
    iStack_d0 = 2;
    uStack_d4 = 0x5779ca;
    FUN_00577560();
    break;
  case 8:
    local_b8 = *(float *)(param_1 + 0xf4);
    if (local_b8 < 200.0 - param_2 * 250.0) {
      *(float *)(param_1 + 0xf4) = (param_2 + 0.0) * 250.0 + local_b8;
      break;
    }
    *(undefined4 *)(param_1 + 200) = 0xb;
LAB_005777c4:
    *(undefined4 *)(param_1 + 0xf4) = 0;
    break;
  case 9:
    local_b8 = *(float *)(param_1 + 0xf4);
    *(undefined4 *)(param_1 + 0xf8) = 0;
    if (local_b8 <= param_2 * 500.0) {
      *(undefined4 *)(*(int *)(param_1 + 4) + 0x10) = 0;
      iStack_d0 = param_1 + 0x118;
      *(undefined4 *)(param_1 + 200) = 10;
      *(undefined4 *)(param_1 + 0xf4) = 0;
      *(undefined4 *)(param_1 + 0x70) = 0;
      *(undefined4 *)(param_1 + 0x74) = 0;
      *(undefined4 *)(param_1 + 0x94) = 0;
      *(undefined4 *)(param_1 + 0x8c) = 0;
      *(undefined4 *)(param_1 + 0x114) = 0;
      uStack_d4 = 0x577c5b;
      FUN_0057e750();
      iStack_d0 = 0x577c65;
      FUN_0057d540();
    }
    else {
      local_b8 = local_b8 - param_2 * 500.0;
      uVar4 = (int)local_b8 & 0xff;
      *(float *)(param_1 + 0xf4) = local_b8;
      *(uint *)(*(int *)(param_1 + 4) + 0x10) = ((uVar4 << 8 | uVar4) << 8 | uVar4) << 8 | uVar4;
    }
    break;
  case 0xb:
    fVar1 = *(float *)(param_1 + 0xf8) + param_2;
    *(float *)(param_1 + 0xf8) = fVar1;
    local_b8 = fVar1 * 0.06 * 57.295776;
    iStack_d0 = 0x577a54;
    fVar5 = (float10)FUN_008ff0a0();
    local_b8 = ABS((float)fVar5 * 255.0);
    iStack_d0 = 0x577a85;
    iVar2 = FUN_008fed10();
    local_b8 = *(float *)(param_1 + 0xf4);
    *(uint *)(param_1 + 0x68) = iVar2 << 0x18 | 0xffffff;
    if (extraout_ST0 - (float10)param_2 * (float10)90.0 <= (float10)local_b8) {
      iStack_d0 = 0x14;
      *(undefined4 *)(param_1 + 200) = 9;
      uStack_d4 = 0x577adf;
      puVar3 = (undefined4 *)FUN_00891268();
      if (puVar3 != (undefined4 *)0x0) {
        *puVar3 = FoxUI::FXUIEvent::vftable;
        puVar3[1] = 0xffffffff;
        puVar3[2] = 0xffffffff;
        puVar3[3] = 0;
        puVar3[4] = 0xf42d8;
      }
      iStack_d0 = 0x577b11;
      FUN_004072a0();
      iStack_d0 = 0x577b16;
      FUN_004054c0();
      iStack_d0 = 0;
      uStack_d4 = 0;
      local_b0 = auStack_f0;
      puStack_f4 = &DAT_00bed1fc;
      uStack_f8 = 0x577b2d;
      FUN_00402250();
      local_b4 = auStack_10c;
      local_c = 5;
      local_b8 = *(float *)(param_1 + 0xc4);
      local_ac = auStack_128;
      FUN_00402110(param_1 + 0x98);
      uVar6 = 0x1b9;
      local_c._0_1_ = 6;
      FUN_005854b0(0x1b9);
      uVar6 = FUN_00585330(uVar6);
      local_c = CONCAT31(local_c._1_3_,5);
      FUN_00460780(uVar6);
      uStack_110 = 0xca;
      local_c = 0xffffffff;
      uStack_114 = 0x577ba7;
      FUN_0058b270();
      *(undefined4 *)(param_1 + 0xb4) = 0xffffffff;
      *(undefined4 *)(param_1 + 0xb8) = 0xffffffff;
      *(undefined4 *)(param_1 + 0xbc) = 0xffffffff;
    }
    else {
      *(float *)(param_1 + 0xf4) =
           (float)((float10)local_b8 +
                  ((float10)param_2 + (float10)0.004999999888241291) * (float10)90.0);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_bc);
  return;
}

