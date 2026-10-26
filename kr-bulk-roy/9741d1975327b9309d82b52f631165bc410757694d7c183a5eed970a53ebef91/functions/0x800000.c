
float * FUN_00800000(float *param_1)

{
  float *pfVar1;
  int iVar2;
  char *pcVar3;
  int *in_ECX;
  double dVar4;
  float local_10;
  float local_c;
  float local_8;
  
  pfVar1 = param_1;
  *param_1 = 0.0;
  param_1[1] = 0.0;
  param_1[2] = 0.0;
  param_1[3] = 0.0;
  if (in_ECX == (int *)0x0) {
    return param_1;
  }
  (**(code **)(*in_ECX + 0x14))();
  iVar2 = FUN_007300a0("EndVariation");
  if (iVar2 == 0) {
LAB_0080005a:
    local_10 = 0.0;
  }
  else {
    pcVar3 = (char *)(iVar2 + 0x30);
    if (0xf < *(uint *)(iVar2 + 0x44)) {
      pcVar3 = *(char **)pcVar3;
    }
    if (pcVar3 == (char *)0x0) goto LAB_0080005a;
    dVar4 = _atof(pcVar3);
    local_10 = (float)dVar4;
  }
  iVar2 = FUN_007300a0("StartVariation");
  if (iVar2 == 0) {
LAB_00800089:
    local_c = 0.0;
  }
  else {
    pcVar3 = (char *)(iVar2 + 0x30);
    if (0xf < *(uint *)(iVar2 + 0x44)) {
      pcVar3 = *(char **)pcVar3;
    }
    if (pcVar3 == (char *)0x0) goto LAB_00800089;
    dVar4 = _atof(pcVar3);
    local_c = (float)dVar4;
  }
  iVar2 = FUN_007300a0("EndValue");
  if (iVar2 == 0) {
LAB_008000b8:
    local_8 = 0.0;
  }
  else {
    pcVar3 = (char *)(iVar2 + 0x30);
    if (0xf < *(uint *)(iVar2 + 0x44)) {
      pcVar3 = *(char **)pcVar3;
    }
    if (pcVar3 == (char *)0x0) goto LAB_008000b8;
    dVar4 = _atof(pcVar3);
    local_8 = (float)dVar4;
  }
  iVar2 = FUN_007300a0("StartValue");
  if (iVar2 != 0) {
    pcVar3 = (char *)(iVar2 + 0x30);
    if (0xf < *(uint *)(iVar2 + 0x44)) {
      pcVar3 = *(char **)pcVar3;
    }
    if (pcVar3 != (char *)0x0) {
      dVar4 = _atof(pcVar3);
      param_1 = (float *)(float)dVar4;
      goto LAB_008000ec;
    }
  }
  param_1 = (float *)0x0;
LAB_008000ec:
  *pfVar1 = (float)param_1;
  pfVar1[1] = local_8;
  pfVar1[2] = local_c;
  pfVar1[3] = local_10;
  return pfVar1;
}

