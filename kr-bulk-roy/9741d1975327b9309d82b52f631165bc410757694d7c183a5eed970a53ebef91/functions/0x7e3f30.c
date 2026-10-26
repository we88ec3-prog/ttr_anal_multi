
float * FUN_007e3f30(float *param_1)

{
  float fVar1;
  float fVar2;
  int in_EAX;
  int iVar3;
  char *pcVar4;
  double dVar5;
  float local_8;
  
  if (in_EAX == 0) {
    *param_1 = 0.0;
    param_1[1] = 0.0;
    param_1[2] = 0.0;
    return param_1;
  }
  iVar3 = FUN_007300a0(&DAT_00c0ecb8);
  if (iVar3 == 0) {
LAB_007e3f71:
    local_8 = 0.0;
  }
  else {
    pcVar4 = (char *)(iVar3 + 0x30);
    if (0xf < *(uint *)(iVar3 + 0x44)) {
      pcVar4 = *(char **)pcVar4;
    }
    if (pcVar4 == (char *)0x0) goto LAB_007e3f71;
    dVar5 = _atof(pcVar4);
    local_8 = (float)dVar5;
  }
  fVar1 = local_8;
  iVar3 = FUN_007300a0(&DAT_00c0ecbc);
  if (iVar3 == 0) {
LAB_007e3fa7:
    local_8 = 0.0;
  }
  else {
    pcVar4 = (char *)(iVar3 + 0x30);
    if (0xf < *(uint *)(iVar3 + 0x44)) {
      pcVar4 = *(char **)pcVar4;
    }
    if (pcVar4 == (char *)0x0) goto LAB_007e3fa7;
    dVar5 = _atof(pcVar4);
    local_8 = (float)dVar5;
  }
  fVar2 = local_8;
  iVar3 = FUN_007300a0(&DAT_00c50174);
  if (iVar3 != 0) {
    pcVar4 = (char *)(iVar3 + 0x30);
    if (0xf < *(uint *)(iVar3 + 0x44)) {
      pcVar4 = *(char **)pcVar4;
    }
    if (pcVar4 != (char *)0x0) {
      dVar5 = _atof(pcVar4);
      local_8 = (float)dVar5;
      goto LAB_007e3fe3;
    }
  }
  local_8 = 0.0;
LAB_007e3fe3:
  *param_1 = fVar1;
  param_1[1] = fVar2;
  param_1[2] = local_8;
  return param_1;
}

