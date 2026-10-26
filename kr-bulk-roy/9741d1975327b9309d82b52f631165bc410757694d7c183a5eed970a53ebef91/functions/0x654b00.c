
void FUN_00654b00(int *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 *puVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar1 = (int)param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090ccab;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar8 = (int *)((int)param_1 + 0xac);
  param_1 = (int *)0x4;
  do {
    iVar9 = *piVar8;
    if (iVar9 != 0) {
      FUN_00654430(uVar2);
      FUN_0089120c(iVar9);
      *piVar8 = 0;
    }
    (**(code **)(*(int *)piVar8[0x13] + 0x94))(0);
    piVar8 = piVar8 + 1;
    param_1 = (int *)((int)param_1 + -1);
  } while (param_1 != (int *)0x0);
  if (*(int *)(iVar1 + 0xd4) == -1) {
    param_1 = (int *)0x0;
    if (*(int *)(iVar1 + 0xd8) != *(int *)(iVar1 + 0xdc)) {
      param_1 = (int *)FUN_00858240(*(int *)(iVar1 + 0xdc),0);
      piVar8 = *(int **)(iVar1 + 0xdc);
      for (piVar7 = param_1; piVar7 != piVar8; piVar7 = piVar7 + 4) {
        if (*piVar7 != 0) {
          FUN_0089120c(*piVar7);
        }
        *piVar7 = 0;
        piVar7[1] = 0;
        piVar7[2] = 0;
      }
      *(int **)(iVar1 + 0xdc) = param_1;
    }
    if (*(int *)(iVar1 + 0xe8) != *(int *)(iVar1 + 0xec)) {
      piVar5 = (int *)FUN_00858240(*(int *)(iVar1 + 0xec),param_1);
      piVar8 = *(int **)(iVar1 + 0xec);
      for (piVar7 = piVar5; piVar7 != piVar8; piVar7 = piVar7 + 4) {
        if (*piVar7 != 0) {
          FUN_0089120c(*piVar7);
        }
        *piVar7 = 0;
        piVar7[1] = 0;
        piVar7[2] = 0;
      }
      *(int **)(iVar1 + 0xec) = piVar5;
    }
    ExceptionList = local_10;
    return;
  }
  iVar9 = 0;
  if (0 < *(int *)(iVar1 + 0xd4)) {
    puVar6 = (undefined4 *)(iVar1 + 0xf8);
    do {
      iVar3 = FUN_00891268(0x38);
      local_8 = 0;
      if (iVar3 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = FUN_00654300(iVar3,(*(char *)(iVar1 + 0xd4) + '\x02') * '\x02');
      }
      local_8 = 0xffffffff;
      puVar6[-0x13] = uVar4;
      (**(code **)(*(int *)*puVar6 + 0x94))(1);
      iVar9 = iVar9 + 1;
      puVar6 = puVar6 + 1;
    } while (iVar9 < *(int *)(iVar1 + 0xd4));
  }
  FUN_00655d40();
  FUN_00655d40();
  ExceptionList = local_10;
  return;
}

