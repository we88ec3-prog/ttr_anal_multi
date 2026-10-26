
void FUN_00767160(void)

{
  int *in_EAX;
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int local_8;
  
  local_8 = in_ECX;
  if ((int *)in_EAX[0x3d] != (int *)0x0) {
    uVar4 = (in_EAX[0x4f] - in_EAX[0x4e] < 1) - 1 & in_EAX[0x4f] - in_EAX[0x4e];
    piVar3 = (int *)(in_EAX[0x44] + uVar4 * 4);
    puVar1 = (undefined4 *)*piVar3;
    iVar2 = puVar1[4];
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      if (7 < (uint)puVar1[5]) {
        puVar1 = (undefined4 *)*puVar1;
      }
      if (*(short *)((int)puVar1 + iVar2 * 2 + -2) == 10) {
        iVar2 = iVar2 + -1;
      }
    }
    local_8 = in_EAX[0x50];
    piVar3 = (int *)*piVar3;
    if (7 < (uint)piVar3[5]) {
      piVar3 = (int *)*piVar3;
    }
    (**(code **)(*(int *)in_EAX[0x3d] + 0x38))(&local_8,in_EAX[0x51],piVar3,iVar2);
    in_EAX[0x4f] = uVar4;
    in_EAX[0x50] = local_8;
    in_EAX[0x4d] = uVar4;
  }
  FUN_00767ba0();
  FUN_00767ec0();
  FUN_00767fa0();
  (**(code **)(*in_EAX + 0x1b0))();
  return;
}

