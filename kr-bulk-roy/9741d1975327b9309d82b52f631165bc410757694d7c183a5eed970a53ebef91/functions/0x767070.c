
void FUN_00767070(void)

{
  uint uVar1;
  uint uVar2;
  int *in_EAX;
  uint uVar3;
  undefined4 *puVar4;
  int *piVar5;
  int in_ECX;
  int iVar6;
  int *piVar7;
  int local_8;
  
  local_8 = in_ECX;
  if ((int *)in_EAX[0x3d] != (int *)0x0) {
    uVar2 = in_EAX[0x4f];
    uVar3 = in_EAX[0x45] - in_EAX[0x44] >> 2;
    if (uVar2 < uVar3) {
      uVar1 = uVar2 + 1;
      local_8 = 0;
      if (uVar1 == uVar3) {
        puVar4 = *(undefined4 **)(in_EAX[0x44] + uVar2 * 4);
        piVar5 = puVar4 + 4;
        if (*piVar5 == 0) goto LAB_0076712d;
        if (7 < (uint)puVar4[5]) {
          puVar4 = (undefined4 *)*puVar4;
        }
        if (*(short *)((int)puVar4 + *piVar5 * 2 + -2) != 10) goto LAB_0076712d;
        in_EAX[0x50] = 0;
      }
      else {
        piVar5 = *(int **)(in_EAX[0x44] + uVar1 * 4);
        iVar6 = piVar5[4];
        if (iVar6 == 0) {
          iVar6 = 0;
        }
        else {
          piVar7 = piVar5;
          if (7 < (uint)piVar5[5]) {
            piVar7 = (int *)*piVar5;
          }
          if (*(short *)((int)piVar7 + iVar6 * 2 + -2) == 10) {
            iVar6 = iVar6 + -1;
          }
        }
        if (7 < (uint)piVar5[5]) {
          piVar5 = (int *)*piVar5;
        }
        (**(code **)(*(int *)in_EAX[0x3d] + 0x38))(&local_8,in_EAX[0x51],piVar5,iVar6);
        in_EAX[0x50] = local_8;
      }
      in_EAX[0x4f] = uVar1;
    }
  }
LAB_0076712d:
  FUN_00767ba0();
  FUN_00767ec0();
  FUN_00767fa0();
  (**(code **)(*in_EAX + 0x1b0))();
  return;
}

