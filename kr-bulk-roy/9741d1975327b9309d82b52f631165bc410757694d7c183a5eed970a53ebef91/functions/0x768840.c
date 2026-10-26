
void FUN_00768840(void)

{
  int *piVar1;
  char cVar2;
  int *in_EAX;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  float10 fVar8;
  uint local_50;
  int local_4c;
  float local_48;
  uint local_44;
  
  iVar5 = in_EAX[9];
  if (in_EAX[0x44] == in_EAX[0x45]) {
    return;
  }
  uVar6 = (int)*(uint *)(iVar5 + 0xbc) >> 0x1f;
  uVar3 = *(uint *)(iVar5 + 0xbc) ^ uVar6;
  if ((uVar3 == uVar6 || (int)(uVar3 - uVar6) < 0) &&
     (uVar6 = (int)*(uint *)(iVar5 + 0xc0) >> 0x1f, uVar3 = *(uint *)(iVar5 + 0xc0) ^ uVar6,
     uVar3 == uVar6 || (int)(uVar3 - uVar6) < 0)) {
    return;
  }
  if (*(int *)(iVar5 + 0xac) < in_EAX[0xc] + in_EAX[0x31]) {
    uVar3 = in_EAX[0x4d] - 1U & ((int)(in_EAX[0x4d] - 1U) < 1) - 1;
  }
  else {
    if (*(int *)(iVar5 + 0xac) <= in_EAX[0xe] - in_EAX[0x31]) goto LAB_007688b5;
    uVar6 = in_EAX[0x45] - in_EAX[0x44] >> 2;
    uVar3 = in_EAX[0x4d] + 1;
    if (uVar6 <= uVar3) {
      cVar2 = FUN_00768190();
      if (cVar2 == '\0') {
        uVar6 = uVar6 - 1;
      }
      in_EAX[0x4d] = uVar6;
      goto LAB_007688b5;
    }
  }
  in_EAX[0x4d] = uVar3;
LAB_007688b5:
  uVar3 = (*(int *)(iVar5 + 0xa8) - in_EAX[0xb]) - in_EAX[0x31];
  local_44 = in_EAX[0x2b] - in_EAX[0x29];
  if ((int)(((int)uVar3 < 1) - 1 & uVar3) < (int)local_44) {
    local_44 = ((int)uVar3 < 1) - 1 & uVar3;
  }
  uVar3 = (*(int *)(iVar5 + 0xac) - in_EAX[0xc]) - in_EAX[0x31];
  local_50 = in_EAX[0x2c] - in_EAX[0x2a];
  if ((int)(((int)uVar3 < 1) - 1 & uVar3) < (int)local_50) {
    local_50 = ((int)uVar3 < 1) - 1 & uVar3;
  }
  piVar1 = (int *)in_EAX[0x3d];
  uVar3 = 0;
  local_4c = 0;
  if ((piVar1 != (int *)0x0) && (local_48 = (float)FUN_008fed10(), 0 < (int)local_48)) {
    cVar2 = FUN_00768190();
    local_48 = (float)(int)local_50 / (float)(int)local_48;
    if (cVar2 == '\0') {
      fVar8 = (float10)FUN_008ff2e0((double)local_48);
      local_48 = (float)fVar8;
      uVar6 = FUN_008fed10();
      uVar3 = (in_EAX[0x45] - in_EAX[0x44] >> 2) - 1;
      if ((((int)uVar6 < 1) - 1 & uVar6) + in_EAX[0x4d] < uVar3) {
        uVar3 = in_EAX[0x4d] + (((int)uVar6 < 1) - 1 & uVar6);
      }
    }
    else {
      fVar8 = (float10)FUN_008ff2e0((double)local_48);
      local_48 = (float)fVar8;
      uVar6 = FUN_008fed10();
      uVar3 = in_EAX[0x45] - in_EAX[0x44] >> 2;
      if ((((int)uVar6 < 1) - 1 & uVar6) + in_EAX[0x4d] < uVar3) {
        uVar3 = in_EAX[0x4d] + (((int)uVar6 < 1) - 1 & uVar6);
      }
    }
  }
  if (uVar3 < (uint)(in_EAX[0x45] - in_EAX[0x44] >> 2)) {
    piVar4 = *(int **)(in_EAX[0x44] + uVar3 * 4);
    iVar5 = piVar4[4];
    if (iVar5 == 0) {
      iVar5 = 0;
    }
    else {
      piVar7 = piVar4;
      if (7 < (uint)piVar4[5]) {
        piVar7 = (int *)*piVar4;
      }
      if (*(short *)((int)piVar7 + iVar5 * 2 + -2) == 10) {
        iVar5 = iVar5 + -1;
      }
    }
    if (7 < (uint)piVar4[5]) {
      piVar4 = (int *)*piVar4;
    }
    (**(code **)(*piVar1 + 0x38))(&local_4c,local_44,piVar4,iVar5);
  }
  if ((char)in_EAX[0x52] != '\0') {
    in_EAX[0x54] = uVar3;
    in_EAX[0x56] = local_4c;
  }
  in_EAX[0x4f] = uVar3;
  in_EAX[0x50] = local_4c;
  FUN_00767fa0();
  (**(code **)(*in_EAX + 0x1b0))();
  return;
}

