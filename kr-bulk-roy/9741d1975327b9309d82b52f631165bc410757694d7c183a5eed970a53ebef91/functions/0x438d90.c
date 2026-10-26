
int * FUN_00438d90(int *param_1,float param_2)

{
  int iVar1;
  uint *puVar2;
  char cVar3;
  char *pcVar4;
  int *piVar5;
  undefined4 *puVar6;
  uint uStack_44;
  uint local_24;
  _Lockit local_20 [4];
  uint local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00913592;
  local_10 = ExceptionList;
  uStack_44 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_44;
  ExceptionList = &local_10;
  piVar5 = *(int **)(*(int *)(*param_1 + 4) + 0x38 + (int)param_1);
  local_18 = 0;
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
  if (*(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1) == 0) {
    FUN_004318d0();
    local_8._0_1_ = 2;
    FUN_00430ce0();
    local_8._0_1_ = 1;
    if (local_1c != 0) {
      std::_Lockit::_Lockit(local_20,0);
      iVar1 = *(int *)(local_1c + 4);
      if ((iVar1 != 0) && (iVar1 != -1)) {
        *(int *)(local_1c + 4) = iVar1 + -1;
      }
      iVar1 = *(int *)(local_1c + 4);
      FUN_0087dd6f();
      puVar6 = (undefined4 *)(~-(uint)(iVar1 != 0) & local_1c);
      if (puVar6 != (undefined4 *)0x0) {
        (**(code **)*puVar6)();
      }
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    local_24 = local_24 & 0xffffff00;
    pcVar4 = (char *)FUN_00438d60(*(int *)(*param_1 + 4) + (int)param_1,local_24,
                                  *(undefined4 *)(*(int *)(*param_1 + 4) + 0x38 + (int)param_1),
                                  (double)param_2);
    if (*pcVar4 != '\0') {
      local_18 = 4;
    }
    local_8 = 1;
    piVar5 = (int *)FUN_00438ef2();
    return piVar5;
  }
  if (local_18 != 0) {
    FUN_00431a90();
  }
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

