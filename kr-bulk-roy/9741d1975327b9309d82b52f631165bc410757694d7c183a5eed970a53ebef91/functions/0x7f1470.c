
float * FUN_007f1470(float *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int in_EAX;
  int iVar4;
  char *pcVar5;
  double dVar6;
  float local_8;
  
  if (in_EAX == 0) {
    *param_1 = 0.0;
    param_1[1] = 0.0;
    param_1[2] = 0.0;
    param_1[3] = 0.0;
    return param_1;
  }
  iVar4 = FUN_007300a0(&DAT_00c50a34);
  if (iVar4 == 0) {
LAB_007f14b6:
    local_8 = 0.0;
  }
  else {
    pcVar5 = (char *)(iVar4 + 0x30);
    if (0xf < *(uint *)(iVar4 + 0x44)) {
      pcVar5 = *(char **)pcVar5;
    }
    if (pcVar5 == (char *)0x0) goto LAB_007f14b6;
    dVar6 = _atof(pcVar5);
    local_8 = (float)dVar6;
  }
  fVar1 = local_8;
  iVar4 = FUN_007300a0(&DAT_00c50a28);
  if (iVar4 == 0) {
LAB_007f14eb:
    local_8 = 0.0;
  }
  else {
    pcVar5 = (char *)(iVar4 + 0x30);
    if (0xf < *(uint *)(iVar4 + 0x44)) {
      pcVar5 = *(char **)pcVar5;
    }
    if (pcVar5 == (char *)0x0) goto LAB_007f14eb;
    dVar6 = _atof(pcVar5);
    local_8 = (float)dVar6;
  }
  fVar2 = local_8;
  iVar4 = FUN_007300a0(&DAT_00c50a2c);
  if (iVar4 == 0) {
LAB_007f1520:
    local_8 = 0.0;
  }
  else {
    pcVar5 = (char *)(iVar4 + 0x30);
    if (0xf < *(uint *)(iVar4 + 0x44)) {
      pcVar5 = *(char **)pcVar5;
    }
    if (pcVar5 == (char *)0x0) goto LAB_007f1520;
    dVar6 = _atof(pcVar5);
    local_8 = (float)dVar6;
  }
  fVar3 = local_8;
  iVar4 = FUN_007300a0(&DAT_00c50a30);
  if (iVar4 != 0) {
    pcVar5 = (char *)(iVar4 + 0x30);
    if (0xf < *(uint *)(iVar4 + 0x44)) {
      pcVar5 = *(char **)pcVar5;
    }
    if (pcVar5 != (char *)0x0) {
      dVar6 = _atof(pcVar5);
      local_8 = (float)dVar6;
      goto LAB_007f155a;
    }
  }
  local_8 = 0.0;
LAB_007f155a:
  *param_1 = fVar2;
  param_1[1] = fVar3;
  param_1[2] = local_8;
  param_1[3] = fVar1;
  return param_1;
}

