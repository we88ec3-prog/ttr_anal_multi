
/* WARNING: Removing unreachable block (ram,0x0042ef34) */
/* WARNING: Removing unreachable block (ram,0x0042ef3f) */
/* WARNING: Removing unreachable block (ram,0x0042ef42) */

int * FUN_0042edc0(int *param_1,undefined4 param_2)

{
  int iVar1;
  uint *puVar2;
  char cVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uStack_44;
  uint local_28;
  _Lockit local_24 [4];
  uint local_20 [2];
  int *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00910f32;
  local_10 = ExceptionList;
  uStack_44 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_44;
  ExceptionList = &local_10;
  piVar5 = *(int **)(*(int *)(*param_1 + 4) + 0x38 + (int)param_1);
  local_20[1] = 0;
  puVar2 = &uStack_44;
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 4))();
    puVar2 = (uint *)local_14;
  }
  local_14 = (undefined1 *)puVar2;
  local_8 = 0;
  if ((*(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1) == 0) &&
     (*(int *)(*(int *)(*param_1 + 4) + 0x3c + (int)param_1) != 0)) {
    FUN_006de0c0();
  }
  local_8 = 1;
  if (*(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1) != 0) {
    local_8 = 5;
    cVar3 = thunk_FUN_0089ccbb();
    if (cVar3 == '\0') {
      FUN_006ddfe0();
    }
    local_8 = 0xffffffff;
    piVar5 = *(int **)(*(int *)(*param_1 + 4) + 0x38 + (int)param_1);
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 8))();
    }
    ExceptionList = local_10;
    return param_1;
  }
  uVar4 = FUN_004318d0(local_20);
  local_8._0_1_ = 2;
  local_18 = (int *)FUN_00430ce0(uVar4);
  local_8._0_1_ = 1;
  if (local_20[0] != 0) {
    std::_Lockit::_Lockit(local_24,0);
    iVar1 = *(int *)(local_20[0] + 4);
    if ((iVar1 != 0) && (iVar1 != -1)) {
      *(int *)(local_20[0] + 4) = iVar1 + -1;
    }
    iVar1 = *(int *)(local_20[0] + 4);
    FUN_0087dd6f();
    puVar6 = (undefined4 *)(~-(uint)(iVar1 != 0) & local_20[0]);
    if (puVar6 != (undefined4 *)0x0) {
      (**(code **)*puVar6)(1);
    }
  }
  local_8 = CONCAT31(local_8._1_3_,3);
  iVar1 = *(int *)(*param_1 + 4);
  uVar4 = *(undefined4 *)(iVar1 + 0x38 + (int)param_1);
  local_28 = local_28 & 0xffffff00;
  uVar7 = local_28;
  (**(code **)(*local_18 + 0x1c))
            (&local_28,local_28,uVar4,*(int *)(*param_1 + 4) + (int)param_1,
             *(undefined2 *)(iVar1 + 0x40 + (int)param_1),param_2);
  local_8 = 1;
  piVar5 = (int *)FUN_0042ef29(uVar7,uVar4);
  return piVar5;
}

