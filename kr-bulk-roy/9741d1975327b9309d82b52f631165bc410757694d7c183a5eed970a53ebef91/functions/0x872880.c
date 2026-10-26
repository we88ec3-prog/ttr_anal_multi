
/* WARNING: Removing unreachable block (ram,0x00872922) */
/* WARNING: Removing unreachable block (ram,0x00872927) */

undefined4 FUN_00872880(int param_1,int *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int in_ECX;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00906908;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  piVar1 = *(int **)(in_ECX + 0x188);
  piVar4 = *(int **)(in_ECX + 0x184);
  if (piVar4 != piVar1) {
    do {
      if ((int *)*piVar4 == param_2) break;
      piVar4 = piVar4 + 1;
    } while (piVar4 != piVar1);
    if (piVar4 != piVar1) {
      return 0;
    }
  }
  iVar5 = *(int *)(in_ECX + 0x188) - *(int *)(in_ECX + 0x184) >> 2;
  ExceptionList = &local_10;
  if ((iVar5 <= param_1) && (local_14 = (param_1 - iVar5) + 1, 0 < local_14)) {
    do {
      local_8 = 0;
      FUN_0077f8f0(uVar3);
      local_14 = local_14 + -1;
    } while (local_14 != 0);
  }
  local_8 = 0xffffffff;
  iVar5 = *(int *)(in_ECX + 0x184);
  puVar2 = *(undefined4 **)(iVar5 + param_1 * 4);
  piVar1 = (int *)(iVar5 + param_1 * 4);
  if (puVar2 != (undefined4 *)0x0) {
    piVar4 = puVar2 + 1;
    *piVar4 = *piVar4 + -1;
    if (*piVar4 == 0) {
      (**(code **)*puVar2)(1);
    }
  }
  *piVar1 = (int)param_2;
  if (param_2 != (int *)0x0) {
    iVar5 = (**(code **)(*param_2 + 8))();
    if (iVar5 == 0) {
      iVar5 = (**(code **)(*(int *)*piVar1 + 0xc))();
      *piVar1 = iVar5;
    }
    *(int *)(*piVar1 + 4) = *(int *)(*piVar1 + 4) + 1;
  }
  ExceptionList = local_10;
  return 1;
}

