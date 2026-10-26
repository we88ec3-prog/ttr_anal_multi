
float * FUN_007f13c0(float *param_1)

{
  float fVar1;
  int in_EAX;
  int iVar2;
  char *pcVar3;
  double dVar4;
  float local_8;
  
  if (in_EAX == 0) {
    *param_1 = 0.0;
    param_1[1] = 0.0;
    return param_1;
  }
  iVar2 = FUN_007300a0(&DAT_00c0ecb8);
  if (iVar2 == 0) {
LAB_007f1401:
    local_8 = 0.0;
  }
  else {
    pcVar3 = (char *)(iVar2 + 0x30);
    if (0xf < *(uint *)(iVar2 + 0x44)) {
      pcVar3 = *(char **)pcVar3;
    }
    if (pcVar3 == (char *)0x0) goto LAB_007f1401;
    dVar4 = _atof(pcVar3);
    local_8 = (float)dVar4;
  }
  fVar1 = local_8;
  iVar2 = FUN_007300a0(&DAT_00c0ecbc);
  if (iVar2 != 0) {
    pcVar3 = (char *)(iVar2 + 0x30);
    if (0xf < *(uint *)(iVar2 + 0x44)) {
      pcVar3 = *(char **)pcVar3;
    }
    if (pcVar3 != (char *)0x0) {
      dVar4 = _atof(pcVar3);
      local_8 = (float)dVar4;
      goto LAB_007f143c;
    }
  }
  local_8 = 0.0;
LAB_007f143c:
  *param_1 = fVar1;
  param_1[1] = local_8;
  return param_1;
}

