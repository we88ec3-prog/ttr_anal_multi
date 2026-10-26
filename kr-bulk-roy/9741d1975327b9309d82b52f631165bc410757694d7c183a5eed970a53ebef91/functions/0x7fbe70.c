
undefined4 FUN_007fbe70(float param_1)

{
  int iVar1;
  int *in_EAX;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  bool bVar6;
  double dVar7;
  
  iVar1 = (int)param_1;
  if (in_EAX == (int *)0x0) {
    return 0;
  }
  FUN_0072e2e0("Texture");
  uVar2 = FUN_0072e2e0("Emitter");
  uVar3 = FUN_0072e2e0("Manipulators");
  (**(code **)(*in_EAX + 0x14))();
  iVar4 = FUN_007300a0("Material");
  if (iVar4 == 0) {
    pcVar5 = (char *)0x0;
  }
  else {
    pcVar5 = (char *)(iVar4 + 0x30);
    if (0xf < *(uint *)(iVar4 + 0x44)) {
      pcVar5 = *(char **)pcVar5;
    }
  }
  iVar4 = __stricmp(pcVar5,"AlphaAdd");
  if (iVar4 == 0) {
    *(undefined4 *)((int)param_1 + 8) = 3;
  }
  else {
    iVar4 = FUN_007300a0("Material");
    if (iVar4 == 0) {
      pcVar5 = (char *)0x0;
    }
    else {
      pcVar5 = (char *)(iVar4 + 0x30);
      if (0xf < *(uint *)(iVar4 + 0x44)) {
        pcVar5 = *(char **)pcVar5;
      }
    }
    iVar4 = __stricmp(pcVar5,"AlphaTest");
    if (iVar4 == 0) {
      *(undefined4 *)((int)param_1 + 8) = 0;
    }
    else {
      iVar4 = FUN_007300a0("Material");
      if (iVar4 == 0) {
        pcVar5 = (char *)0x0;
      }
      else {
        pcVar5 = (char *)(iVar4 + 0x30);
        if (0xf < *(uint *)(iVar4 + 0x44)) {
          pcVar5 = *(char **)pcVar5;
        }
      }
      iVar4 = __stricmp(pcVar5,"AlphaBlend");
      if (iVar4 == 0) {
        *(undefined4 *)((int)param_1 + 8) = 1;
      }
      else {
        iVar4 = FUN_007300a0("Material");
        if (iVar4 == 0) {
          pcVar5 = (char *)0x0;
        }
        else {
          pcVar5 = (char *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            pcVar5 = *(char **)pcVar5;
          }
        }
        iVar4 = __stricmp(pcVar5,"AlphaSub");
        if (iVar4 == 0) {
          *(undefined4 *)((int)param_1 + 8) = 4;
        }
      }
    }
  }
  iVar4 = FUN_007300a0("StartFrame");
  if (iVar4 == 0) {
LAB_007fbfca:
    param_1 = 0.0;
  }
  else {
    pcVar5 = (char *)(iVar4 + 0x30);
    if (0xf < *(uint *)(iVar4 + 0x44)) {
      pcVar5 = *(char **)pcVar5;
    }
    if (pcVar5 == (char *)0x0) goto LAB_007fbfca;
    dVar7 = _atof(pcVar5);
    param_1 = (float)dVar7;
  }
  *(float *)(iVar1 + 0x38) = (1.0 / *(float *)(iVar1 + 0x40)) * param_1;
  iVar4 = FUN_007300a0("MaxFrame");
  if (iVar4 == 0) {
LAB_007fc006:
    param_1 = 0.0;
  }
  else {
    pcVar5 = (char *)(iVar4 + 0x30);
    if (0xf < *(uint *)(iVar4 + 0x44)) {
      pcVar5 = *(char **)pcVar5;
    }
    if (pcVar5 == (char *)0x0) goto LAB_007fc006;
    dVar7 = _atof(pcVar5);
    param_1 = (float)dVar7;
  }
  *(float *)(iVar1 + 0x3c) = (1.0 / *(float *)(iVar1 + 0x40)) * param_1;
  iVar4 = FUN_007300a0("Boundsphere");
  if (iVar4 == 0) {
LAB_007fc042:
    param_1 = 512.0;
  }
  else {
    pcVar5 = (char *)(iVar4 + 0x30);
    if (0xf < *(uint *)(iVar4 + 0x44)) {
      pcVar5 = *(char **)pcVar5;
    }
    if (pcVar5 == (char *)0x0) goto LAB_007fc042;
    dVar7 = _atof(pcVar5);
    param_1 = (float)dVar7;
  }
  *(float *)(iVar1 + 0x44) = param_1;
  iVar4 = FUN_007300a0("Local");
  if (iVar4 == 0) {
LAB_007fc082:
    bVar6 = false;
  }
  else {
    pcVar5 = (char *)(iVar4 + 0x30);
    if (0xf < *(uint *)(iVar4 + 0x44)) {
      pcVar5 = *(char **)pcVar5;
    }
    if (pcVar5 == (char *)0x0) goto LAB_007fc082;
    iVar4 = __stricmp(pcVar5,"true");
    bVar6 = iVar4 == 0;
  }
  *(uint *)(iVar1 + 4) = (uint)bVar6;
  iVar4 = FUN_007300a0("ParticleSize");
  if (iVar4 != 0) {
    pcVar5 = (char *)(iVar4 + 0x30);
    if (0xf < *(uint *)(iVar4 + 0x44)) {
      pcVar5 = *(char **)pcVar5;
    }
    if (pcVar5 != (char *)0x0) {
      dVar7 = _atof(pcVar5);
      param_1 = (float)dVar7;
      goto LAB_007fc0b9;
    }
  }
  param_1 = 0.0;
LAB_007fc0b9:
  *(float *)(iVar1 + 0x7c) = param_1;
  FUN_007fad30(iVar1);
  FUN_007fc0f0(iVar1,uVar2);
  FUN_008009e0(iVar1,uVar3);
  return 1;
}

