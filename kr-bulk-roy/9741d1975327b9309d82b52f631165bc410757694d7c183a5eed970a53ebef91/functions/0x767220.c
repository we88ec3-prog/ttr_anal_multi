
void FUN_00767220(void)

{
  int *piVar1;
  char cVar2;
  int *in_EAX;
  uint uVar3;
  undefined4 *puVar4;
  int in_ECX;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  int local_8;
  
  piVar1 = (int *)in_EAX[0x3d];
  local_8 = in_ECX;
  if (piVar1 == (int *)0x0) goto LAB_007672eb;
  uVar3 = in_EAX[0x4e] + in_EAX[0x4f];
  uVar7 = in_EAX[0x45] - in_EAX[0x44] >> 2;
  local_8 = 0;
  if (uVar3 < uVar7) {
    puVar4 = *(undefined4 **)(in_EAX[0x44] + uVar3 * 4);
    iVar5 = puVar4[4];
    if (iVar5 == 0) {
LAB_007672b6:
      iVar5 = 0;
    }
    else {
      puVar6 = puVar4;
      if (7 < (uint)puVar4[5]) {
        puVar6 = (undefined4 *)*puVar4;
      }
LAB_007672ab:
      if (*(short *)((int)puVar6 + iVar5 * 2 + -2) == 10) {
        iVar5 = iVar5 + -1;
      }
    }
    if (7 < (uint)puVar4[5]) {
      puVar4 = (undefined4 *)*puVar4;
    }
    (**(code **)(*piVar1 + 0x38))(&local_8,in_EAX[0x51],puVar4,iVar5);
    uVar7 = uVar3;
  }
  else {
    cVar2 = FUN_00768190();
    if (cVar2 == '\0') {
      uVar3 = -(uint)(uVar7 - 1 != 0) & uVar7 - 1;
      puVar4 = *(undefined4 **)(in_EAX[0x44] + uVar3 * 4);
      iVar5 = puVar4[4];
      if (iVar5 == 0) goto LAB_007672b6;
      puVar6 = puVar4;
      if (7 < (uint)puVar4[5]) {
        puVar6 = (undefined4 *)*puVar4;
      }
      goto LAB_007672ab;
    }
  }
  in_EAX[0x4f] = uVar7;
  in_EAX[0x50] = local_8;
  in_EAX[0x4d] = uVar7;
LAB_007672eb:
  FUN_00767ba0();
  FUN_00767ec0();
  FUN_00767fa0();
  (**(code **)(*in_EAX + 0x1b0))();
  return;
}

