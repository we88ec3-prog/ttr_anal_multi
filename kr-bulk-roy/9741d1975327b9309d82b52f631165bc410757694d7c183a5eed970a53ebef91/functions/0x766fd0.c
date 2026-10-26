
void FUN_00766fd0(void)

{
  int *in_EAX;
  undefined4 *puVar1;
  int *piVar2;
  int in_ECX;
  int iVar3;
  int iVar4;
  int local_8;
  
  local_8 = in_ECX;
  if (((int *)in_EAX[0x3d] != (int *)0x0) && (iVar4 = in_EAX[0x4f] + -1, -1 < iVar4)) {
    piVar2 = (int *)(in_EAX[0x44] + iVar4 * 4);
    puVar1 = (undefined4 *)*piVar2;
    iVar3 = puVar1[4];
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      if (7 < (uint)puVar1[5]) {
        puVar1 = (undefined4 *)*puVar1;
      }
      if (*(short *)((int)puVar1 + iVar3 * 2 + -2) == 10) {
        iVar3 = iVar3 + -1;
      }
    }
    local_8 = in_EAX[0x50];
    piVar2 = (int *)*piVar2;
    if (7 < (uint)piVar2[5]) {
      piVar2 = (int *)*piVar2;
    }
    (**(code **)(*(int *)in_EAX[0x3d] + 0x38))(&local_8,in_EAX[0x51],piVar2,iVar3);
    in_EAX[0x4f] = iVar4;
    in_EAX[0x50] = local_8;
  }
  FUN_00767ba0();
  FUN_00767ec0();
  FUN_00767fa0();
  (**(code **)(*in_EAX + 0x1b0))();
  return;
}

