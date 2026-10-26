
void FUN_007686a0(void)

{
  char cVar1;
  int *in_EAX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  float10 fVar7;
  int local_4c;
  uint local_48;
  float local_44;
  
  iVar5 = (*(int *)(in_EAX[9] + 0xa8) - in_EAX[0xb]) - in_EAX[0x31];
  local_44 = (float)((*(int *)(in_EAX[9] + 0xac) - in_EAX[0xc]) - in_EAX[0x31]);
  if ((((iVar5 < 0) || (in_EAX[0x2b] - in_EAX[0x29] < iVar5)) || ((int)local_44 < 0)) ||
     (in_EAX[0x2c] - in_EAX[0x2a] < (int)local_44)) goto LAB_0076882b;
  local_4c = 0;
  if (in_EAX[0x3d] == 0) {
    local_48 = 0;
  }
  else {
    local_48 = *(undefined4 *)(in_EAX[0x3d] + 0x10);
    local_48 = FUN_008fed10();
  }
  local_44 = (float)(int)local_44 / (float)(int)local_48;
  fVar7 = (float10)FUN_008ff2e0((double)local_44);
  local_44 = (float)fVar7;
  iVar2 = FUN_008fed10();
  local_48 = iVar2 + in_EAX[0x4d];
  uVar6 = in_EAX[0x45] - in_EAX[0x44] >> 2;
  if (local_48 < uVar6) {
    puVar3 = *(undefined4 **)(in_EAX[0x44] + local_48 * 4);
LAB_007687be:
    iVar2 = puVar3[4];
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      puVar4 = puVar3;
      if (7 < (uint)puVar3[5]) {
        puVar4 = (undefined4 *)*puVar3;
      }
      if (*(short *)((int)puVar4 + iVar2 * 2 + -2) == 10) {
        iVar2 = iVar2 + -1;
      }
    }
    if (7 < (uint)puVar3[5]) {
      puVar3 = (undefined4 *)*puVar3;
    }
    (**(code **)(*(int *)in_EAX[0x3d] + 0x38))(&local_4c,iVar5,puVar3,iVar2);
  }
  else {
    cVar1 = FUN_00768190();
    if (cVar1 == '\0') {
      puVar3 = *(undefined4 **)(in_EAX[0x44] + -4 + uVar6 * 4);
      local_48 = uVar6 - 1;
      goto LAB_007687be;
    }
    local_4c = 0;
    local_48 = uVar6;
  }
  in_EAX[0x4f] = local_48;
  in_EAX[0x50] = local_4c;
  FUN_00767b30();
  FUN_00767ba0();
  FUN_00767fa0();
LAB_0076882b:
  (**(code **)(*in_EAX + 0x1b0))();
  return;
}

