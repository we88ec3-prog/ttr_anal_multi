
void FUN_008609f0(int *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int *in_ECX;
  int *unaff_FS_OFFSET;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00904cd8;
  local_10 = *unaff_FS_OFFSET;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  piVar6 = (int *)*in_ECX;
  if (piVar6 != (int *)0x0) {
    iVar5 = (**(code **)(*piVar6 + 8))(uVar4);
    if (iVar5 == 0) {
      piVar6 = (int *)(**(code **)(*piVar6 + 0xc))();
    }
    piVar6[1] = piVar6[1] + 1;
  }
  local_8 = 0;
  puVar2 = (undefined4 *)*in_ECX;
  if (puVar2 != (undefined4 *)*param_1) {
    if (puVar2 != (undefined4 *)0x0) {
      piVar3 = puVar2 + 1;
      *piVar3 = *piVar3 + -1;
      if (*piVar3 == 0) {
        (**(code **)*puVar2)(1);
      }
    }
    piVar3 = (int *)*param_1;
    *in_ECX = (int)piVar3;
    if (piVar3 != (int *)0x0) {
      iVar5 = (**(code **)(*piVar3 + 8))();
      if (iVar5 == 0) {
        iVar5 = (**(code **)(*(int *)*in_ECX + 0xc))();
        *in_ECX = iVar5;
      }
      *(int *)(*in_ECX + 4) = *(int *)(*in_ECX + 4) + 1;
    }
  }
  piVar3 = (int *)*param_1;
  if (piVar3 != piVar6) {
    if (piVar3 != (int *)0x0) {
      piVar1 = piVar3 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (**(code **)*piVar3)(1);
      }
    }
    *param_1 = (int)piVar6;
    if (piVar6 != (int *)0x0) {
      iVar5 = (**(code **)(*piVar6 + 8))();
      if (iVar5 == 0) {
        iVar5 = (**(code **)(*(int *)*param_1 + 0xc))();
        *param_1 = iVar5;
      }
      *(int *)(*param_1 + 4) = *(int *)(*param_1 + 4) + 1;
    }
  }
  local_8 = 0xffffffff;
  if (piVar6 != (int *)0x0) {
    piVar3 = piVar6 + 1;
    *piVar3 = *piVar3 + -1;
    if (*piVar3 == 0) {
      (**(code **)*piVar6)(1);
    }
  }
  *unaff_FS_OFFSET = local_10;
  return;
}

