
/* WARNING: Removing unreachable block (ram,0x00433f18) */
/* WARNING: Removing unreachable block (ram,0x00433f23) */
/* WARNING: Removing unreachable block (ram,0x00433f26) */

int * FUN_00433da0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint *puVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  uint uStack_48;
  uint local_2c;
  _Lockit local_28 [4];
  uint local_24 [2];
  int *local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009135d2;
  local_10 = ExceptionList;
  uStack_48 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_48;
  ExceptionList = &local_10;
  piVar6 = *(int **)(*(int *)(*param_1 + 4) + 0x38 + (int)param_1);
  local_24[1] = 0;
  puVar2 = &uStack_48;
  if (piVar6 != (int *)0x0) {
    (**(code **)(*piVar6 + 4))();
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
    piVar6 = *(int **)(*(int *)(*param_1 + 4) + 0x38 + (int)param_1);
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 8))();
    }
    ExceptionList = local_10;
    return param_1;
  }
  uVar4 = FUN_004318d0(local_24);
  local_8._0_1_ = 2;
  local_1c = (int *)FUN_00430ce0(uVar4);
  local_8._0_1_ = 1;
  if (local_24[0] != 0) {
    std::_Lockit::_Lockit(local_28,0);
    iVar1 = *(int *)(local_24[0] + 4);
    if ((iVar1 != 0) && (iVar1 != -1)) {
      *(int *)(local_24[0] + 4) = iVar1 + -1;
    }
    iVar1 = *(int *)(local_24[0] + 4);
    FUN_0087dd6f();
    puVar7 = (undefined4 *)(~-(uint)(iVar1 != 0) & local_24[0]);
    if (puVar7 != (undefined4 *)0x0) {
      (**(code **)*puVar7)(1);
    }
  }
  local_8 = CONCAT31(local_8._1_3_,3);
  iVar1 = *(int *)(*param_1 + 4);
  uVar4 = *(undefined4 *)(iVar1 + 0x38 + (int)param_1);
  iVar5 = *(int *)(*param_1 + 4) + (int)param_1;
  local_2c = local_2c & 0xffffff00;
  (**(code **)(*local_1c + 0x14))
            (&param_2,local_2c,uVar4,iVar5,*(undefined2 *)(iVar1 + 0x40 + (int)param_1),param_2,
             param_3);
  local_8 = 1;
  piVar6 = (int *)FUN_00433f0d(local_2c,uVar4,iVar5);
  return piVar6;
}

