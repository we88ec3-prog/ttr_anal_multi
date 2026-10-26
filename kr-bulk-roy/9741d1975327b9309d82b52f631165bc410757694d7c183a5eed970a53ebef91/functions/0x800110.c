
undefined4 FUN_00800110(float param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  char *pcVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  int *piVar7;
  undefined4 *puVar8;
  int unaff_ESI;
  ushort in_FPUControlWord;
  float10 fVar9;
  double dVar10;
  undefined1 local_44 [16];
  undefined8 local_34;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  undefined4 *local_c;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)0x0;
  local_c = (undefined4 *)(**(code **)(*param_2 + 0x14))();
  iVar2 = FUN_007300a0(&DAT_00c408b8);
  if (iVar2 == 0) {
    pcVar3 = (char *)0x0;
  }
  else {
    pcVar3 = (char *)(iVar2 + 0x30);
    if (0xf < *(uint *)(iVar2 + 0x44)) {
      pcVar3 = *(char **)pcVar3;
    }
  }
  iVar2 = __stricmp(pcVar3,"Point");
  if (iVar2 == 0) {
    local_8 = (undefined4 *)FUN_00891268(4);
    if (local_8 == (undefined4 *)0x0) {
      local_8 = (undefined4 *)0x0;
    }
    else {
      *local_8 = IS3D::CPointEmitter::vftable;
    }
  }
  else {
    iVar2 = FUN_007300a0(&DAT_00c408b8);
    if (iVar2 == 0) {
      pcVar3 = (char *)0x0;
    }
    else {
      pcVar3 = (char *)(iVar2 + 0x30);
      if (0xf < *(uint *)(iVar2 + 0x44)) {
        pcVar3 = *(char **)pcVar3;
      }
    }
    iVar2 = __stricmp(pcVar3,"Plane");
    if (iVar2 == 0) {
      local_c = (undefined4 *)FUN_00891268(8);
      if (local_c == (undefined4 *)0x0) {
        local_c = (undefined4 *)0x0;
      }
      else {
        *local_c = IS3D::CPlaneEmitter::vftable;
      }
      iVar2 = FUN_007300a0(&DAT_00c506ac);
      if (iVar2 != 0) {
        pcVar3 = (char *)(iVar2 + 0x30);
        if (0xf < *(uint *)(iVar2 + 0x44)) {
          pcVar3 = *(char **)pcVar3;
        }
        if (pcVar3 != (char *)0x0) {
          dVar10 = _atof(pcVar3);
          local_10 = (float)dVar10;
          local_c[1] = local_10;
          local_8 = local_c;
          goto LAB_00800383;
        }
      }
      local_10 = 0.0;
      local_8 = local_c;
      local_c[1] = 0;
    }
    else {
      iVar2 = FUN_007300a0(&DAT_00c408b8);
      if (iVar2 == 0) {
        pcVar3 = (char *)0x0;
      }
      else {
        pcVar3 = (char *)(iVar2 + 0x30);
        if (0xf < *(uint *)(iVar2 + 0x44)) {
          pcVar3 = *(char **)pcVar3;
        }
      }
      iVar2 = __stricmp(pcVar3,"Circle");
      if (iVar2 == 0) {
        puVar4 = (undefined4 *)FUN_00891268(0xc);
        puVar8 = (undefined4 *)0x0;
        if (puVar4 != (undefined4 *)0x0) {
          puVar4[1] = 0;
          *puVar4 = IS3D::CCircleEmitter::vftable;
          puVar8 = puVar4;
        }
        fVar9 = (float10)FUN_0072e690(0);
        puVar8[2] = (float)fVar9;
        uVar5 = FUN_0072e6d0(0);
        puVar8[1] = uVar5 & 0xff;
        local_8 = puVar8;
      }
      else {
        iVar2 = FUN_007300a0(&DAT_00c408b8);
        if (iVar2 == 0) {
          pcVar3 = (char *)0x0;
        }
        else {
          pcVar3 = (char *)(iVar2 + 0x30);
          if (0xf < *(uint *)(iVar2 + 0x44)) {
            pcVar3 = *(char **)pcVar3;
          }
        }
        iVar2 = __stricmp(pcVar3,"Sphere");
        if (iVar2 == 0) {
          puVar8 = (undefined4 *)FUN_00891268(8);
          if (puVar8 == (undefined4 *)0x0) {
            puVar8 = (undefined4 *)0x0;
          }
          else {
            *puVar8 = IS3D::CSphereEmitter::vftable;
          }
          fVar9 = (float10)FUN_0072e690(0);
          puVar8[1] = (float)fVar9;
          local_8 = puVar8;
        }
        else {
          iVar2 = FUN_007300a0(&DAT_00c408b8);
          if (iVar2 == 0) {
            pcVar3 = (char *)0x0;
          }
          else {
            pcVar3 = (char *)(iVar2 + 0x30);
            if (0xf < *(uint *)(iVar2 + 0x44)) {
              pcVar3 = *(char **)pcVar3;
            }
          }
          iVar2 = __stricmp(pcVar3,"Spiral");
          if (iVar2 == 0) {
            puVar8 = (undefined4 *)FUN_00891268(0xc);
            if (puVar8 == (undefined4 *)0x0) {
              puVar8 = (undefined4 *)0x0;
            }
            else {
              *puVar8 = IS3D::CSpiralEmitter::vftable;
              puVar8[2] = 0x3f800000;
            }
            fVar9 = (float10)FUN_0072e690(0);
            puVar8[1] = (float)fVar9;
            fVar9 = (float10)FUN_0072e690(0x3f800000);
            puVar8[2] = (float)fVar9;
            local_8 = puVar8;
          }
        }
      }
    }
  }
LAB_00800383:
  iVar2 = FUN_007300a0("MaxParticles");
  if (iVar2 == 0) {
LAB_008003b1:
    param_2 = (int *)0x0;
  }
  else {
    pcVar3 = (char *)(iVar2 + 0x30);
    if (0xf < *(uint *)(iVar2 + 0x44)) {
      pcVar3 = *(char **)pcVar3;
    }
    if (pcVar3 == (char *)0x0) goto LAB_008003b1;
    dVar10 = _atof(pcVar3);
    param_2 = (int *)(float)dVar10;
  }
  local_10 = (float)(in_FPUControlWord | 0xc00);
  local_34 = (longlong)ROUND((float)param_2);
  *(undefined4 *)((int)param_1 + 0x34) = (undefined4)local_34;
  if (*(undefined4 **)((int)param_1 + 0xc) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)((int)param_1 + 0xc))(1);
    *(undefined4 *)((int)param_1 + 0xc) = 0;
  }
  *(undefined4 **)((int)param_1 + 0xc) = local_8;
  FUN_0072e2e0("Center");
  local_1c = FUN_0072e2e0("EmitRate");
  local_20 = FUN_0072e2e0("EmitAmount");
  local_24 = FUN_0072e2e0(&DAT_00c512a8);
  local_28 = FUN_0072e2e0("Speed");
  local_c = (undefined4 *)FUN_0072e2e0("Theta");
  local_8 = (undefined4 *)FUN_0072e2e0("Gravity");
  uVar6 = FUN_0072e2e0("Accel");
  local_34 = CONCAT44(uVar6,(undefined4)local_34);
  local_10 = (float)FUN_0072e2e0(&DAT_00c512c8);
  FUN_0072e2e0("Color");
  piVar7 = (int *)FUN_0072e2e0("TerminalVelocity");
  local_14 = FUN_0072e2e0(&DAT_00c0ecb8);
  local_18 = FUN_0072e2e0(&DAT_00c0ecbc);
  FUN_0072e2e0(&DAT_00c50174);
  puVar8 = (undefined4 *)FUN_00800000(local_44);
  *(undefined4 *)(unaff_ESI + 4) = *puVar8;
  *(undefined4 *)(unaff_ESI + 8) = puVar8[1];
  *(undefined4 *)(unaff_ESI + 0xc) = puVar8[2];
  *(undefined4 *)(unaff_ESI + 0x10) = puVar8[3];
  puVar8 = (undefined4 *)FUN_00800000(local_44);
  *(undefined4 *)(unaff_ESI + 0x14) = *puVar8;
  *(undefined4 *)(unaff_ESI + 0x18) = puVar8[1];
  *(undefined4 *)(unaff_ESI + 0x1c) = puVar8[2];
  *(undefined4 *)(unaff_ESI + 0x20) = puVar8[3];
  puVar8 = (undefined4 *)FUN_00800000(local_44);
  *(undefined4 *)(unaff_ESI + 0x24) = *puVar8;
  *(undefined4 *)(unaff_ESI + 0x28) = puVar8[1];
  *(undefined4 *)(unaff_ESI + 0x2c) = puVar8[2];
  *(undefined4 *)(unaff_ESI + 0x30) = puVar8[3];
  puVar8 = (undefined4 *)FUN_00800000(local_44);
  *(undefined4 *)(unaff_ESI + 0x34) = *puVar8;
  *(undefined4 *)(unaff_ESI + 0x38) = puVar8[1];
  *(undefined4 *)(unaff_ESI + 0x3c) = puVar8[2];
  *(undefined4 *)(unaff_ESI + 0x40) = puVar8[3];
  fVar1 = 1.0 / *(float *)((int)param_1 + 0x40);
  *(float *)(unaff_ESI + 0x34) = fVar1 * *(float *)(unaff_ESI + 0x34);
  *(float *)(unaff_ESI + 0x38) = *(float *)(unaff_ESI + 0x38) * fVar1;
  *(float *)(unaff_ESI + 0x3c) = *(float *)(unaff_ESI + 0x3c) * fVar1;
  *(float *)(unaff_ESI + 0x40) = fVar1 * *(float *)(unaff_ESI + 0x40);
  puVar8 = (undefined4 *)FUN_00800000(local_44);
  *(undefined4 *)(unaff_ESI + 0x44) = *puVar8;
  *(undefined4 *)(unaff_ESI + 0x48) = puVar8[1];
  *(undefined4 *)(unaff_ESI + 0x4c) = puVar8[2];
  *(undefined4 *)(unaff_ESI + 0x50) = puVar8[3];
  puVar8 = (undefined4 *)FUN_00800000(local_44);
  *(undefined4 *)(unaff_ESI + 0x54) = *puVar8;
  *(undefined4 *)(unaff_ESI + 0x58) = puVar8[1];
  *(undefined4 *)(unaff_ESI + 0x5c) = puVar8[2];
  *(undefined4 *)(unaff_ESI + 0x60) = puVar8[3];
  fVar1 = 1.0 / *(float *)((int)param_1 + 0x40);
  *(float *)(unaff_ESI + 0x54) = fVar1 * *(float *)(unaff_ESI + 0x54);
  *(float *)(unaff_ESI + 0x58) = *(float *)(unaff_ESI + 0x58) * fVar1;
  *(float *)(unaff_ESI + 0x5c) = *(float *)(unaff_ESI + 0x5c) * fVar1;
  *(float *)(unaff_ESI + 0x60) = fVar1 * *(float *)(unaff_ESI + 0x60);
  puVar8 = (undefined4 *)FUN_00800000(local_44);
  *(undefined4 *)(unaff_ESI + 100) = *puVar8;
  *(undefined4 *)(unaff_ESI + 0x68) = puVar8[1];
  *(undefined4 *)(unaff_ESI + 0x6c) = puVar8[2];
  *(undefined4 *)(unaff_ESI + 0x70) = puVar8[3];
  FUN_0072e2e0(&DAT_00c0ecb8);
  FUN_0072e2e0(&DAT_00c0ecbc);
  local_28 = FUN_0072e2e0(&DAT_00c50174);
  puVar8 = (undefined4 *)FUN_00800000(local_44);
  *(undefined4 *)(unaff_ESI + 0x74) = *puVar8;
  *(undefined4 *)(unaff_ESI + 0x78) = puVar8[1];
  *(undefined4 *)(unaff_ESI + 0x7c) = puVar8[2];
  *(undefined4 *)(unaff_ESI + 0x80) = puVar8[3];
  puVar8 = (undefined4 *)FUN_00800000(local_44);
  *(undefined4 *)(unaff_ESI + 0x84) = *puVar8;
  *(undefined4 *)(unaff_ESI + 0x88) = puVar8[1];
  *(undefined4 *)(unaff_ESI + 0x8c) = puVar8[2];
  *(undefined4 *)(unaff_ESI + 0x90) = puVar8[3];
  puVar8 = (undefined4 *)FUN_00800000(local_44);
  *(undefined4 *)(unaff_ESI + 0x94) = *puVar8;
  *(undefined4 *)(unaff_ESI + 0x98) = puVar8[1];
  *(undefined4 *)(unaff_ESI + 0x9c) = puVar8[2];
  *(undefined4 *)(unaff_ESI + 0xa0) = puVar8[3];
  FUN_0072e2e0(&DAT_00c0ecb8);
  FUN_0072e2e0(&DAT_00c0ecbc);
  local_28 = FUN_0072e2e0(&DAT_00c50174);
  puVar8 = (undefined4 *)FUN_00800000(local_44);
  *(undefined4 *)(unaff_ESI + 0xa4) = *puVar8;
  *(undefined4 *)(unaff_ESI + 0xa8) = puVar8[1];
  *(undefined4 *)(unaff_ESI + 0xac) = puVar8[2];
  *(undefined4 *)(unaff_ESI + 0xb0) = puVar8[3];
  puVar8 = (undefined4 *)FUN_00800000(local_44);
  *(undefined4 *)(unaff_ESI + 0xb4) = *puVar8;
  *(undefined4 *)(unaff_ESI + 0xb8) = puVar8[1];
  *(undefined4 *)(unaff_ESI + 0xbc) = puVar8[2];
  *(undefined4 *)(unaff_ESI + 0xc0) = puVar8[3];
  puVar8 = (undefined4 *)FUN_00800000(local_44);
  *(undefined4 *)(unaff_ESI + 0xc4) = *puVar8;
  *(undefined4 *)(unaff_ESI + 200) = puVar8[1];
  *(undefined4 *)(unaff_ESI + 0xcc) = puVar8[2];
  *(undefined4 *)(unaff_ESI + 0xd0) = puVar8[3];
  puVar8 = (undefined4 *)FUN_00800000(local_44);
  *(undefined4 *)(unaff_ESI + 0x104) = *puVar8;
  *(undefined4 *)(unaff_ESI + 0x108) = puVar8[1];
  *(undefined4 *)(unaff_ESI + 0x10c) = puVar8[2];
  *(undefined4 *)(unaff_ESI + 0x110) = puVar8[3];
  FUN_0072e2e0(&DAT_00c0ecb8);
  FUN_0072e2e0(&DAT_00c0ecbc);
  uVar6 = FUN_0072e2e0(&DAT_00c50174);
  local_34 = CONCAT44(uVar6,(undefined4)local_34);
  puVar8 = (undefined4 *)FUN_00800000(local_44);
  *(undefined4 *)(unaff_ESI + 0xd4) = *puVar8;
  *(undefined4 *)(unaff_ESI + 0xd8) = puVar8[1];
  *(undefined4 *)(unaff_ESI + 0xdc) = puVar8[2];
  *(undefined4 *)(unaff_ESI + 0xe0) = puVar8[3];
  puVar8 = (undefined4 *)FUN_00800000(local_44);
  *(undefined4 *)(unaff_ESI + 0xe4) = *puVar8;
  *(undefined4 *)(unaff_ESI + 0xe8) = puVar8[1];
  *(undefined4 *)(unaff_ESI + 0xec) = puVar8[2];
  *(undefined4 *)(unaff_ESI + 0xf0) = puVar8[3];
  puVar8 = (undefined4 *)FUN_00800000(local_44);
  *(undefined4 *)(unaff_ESI + 0xf4) = *puVar8;
  *(undefined4 *)(unaff_ESI + 0xf8) = puVar8[1];
  *(undefined4 *)(unaff_ESI + 0xfc) = puVar8[2];
  *(undefined4 *)(unaff_ESI + 0x100) = puVar8[3];
  FUN_0072e2e0(&DAT_00c50a34);
  FUN_0072e2e0(&DAT_00c50a28);
  uVar6 = FUN_0072e2e0(&DAT_00c50a2c);
  local_34 = CONCAT44(uVar6,(undefined4)local_34);
  FUN_0072e2e0(&DAT_00c50a30);
  puVar8 = (undefined4 *)FUN_00800000(local_44);
  *(undefined4 *)(unaff_ESI + 0x114) = *puVar8;
  *(undefined4 *)(unaff_ESI + 0x118) = puVar8[1];
  *(undefined4 *)(unaff_ESI + 0x11c) = puVar8[2];
  *(undefined4 *)(unaff_ESI + 0x120) = puVar8[3];
  puVar8 = (undefined4 *)FUN_00800000(local_44);
  *(undefined4 *)(unaff_ESI + 0x124) = *puVar8;
  *(undefined4 *)(unaff_ESI + 0x128) = puVar8[1];
  *(undefined4 *)(unaff_ESI + 300) = puVar8[2];
  *(undefined4 *)(unaff_ESI + 0x130) = puVar8[3];
  puVar8 = (undefined4 *)FUN_00800000(local_44);
  *(undefined4 *)(unaff_ESI + 0x134) = *puVar8;
  *(undefined4 *)(unaff_ESI + 0x138) = puVar8[1];
  *(undefined4 *)(unaff_ESI + 0x13c) = puVar8[2];
  *(undefined4 *)(unaff_ESI + 0x140) = puVar8[3];
  puVar8 = (undefined4 *)FUN_00800000(local_44);
  *(undefined4 *)(unaff_ESI + 0x144) = *puVar8;
  *(undefined4 *)(unaff_ESI + 0x148) = puVar8[1];
  *(undefined4 *)(unaff_ESI + 0x14c) = puVar8[2];
  *(undefined4 *)(unaff_ESI + 0x150) = puVar8[3];
  (**(code **)(*piVar7 + 0x14))();
  iVar2 = FUN_007300a0("Value");
  if (iVar2 != 0) {
    pcVar3 = (char *)(iVar2 + 0x30);
    if (0xf < *(uint *)(iVar2 + 0x44)) {
      pcVar3 = *(char **)pcVar3;
    }
    if (pcVar3 != (char *)0x0) {
      dVar10 = _atof(pcVar3);
      param_1 = (float)dVar10;
      goto LAB_008009bc;
    }
  }
  param_1 = 0.0;
LAB_008009bc:
  *(float *)(unaff_ESI + 0x154) = param_1;
  return 1;
}

