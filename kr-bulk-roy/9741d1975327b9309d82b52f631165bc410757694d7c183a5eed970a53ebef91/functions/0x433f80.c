
undefined4 FUN_00433f80(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 local_d0 [16];
  int local_c0 [5];
  uint auStack_ac [15];
  undefined **local_70 [19];
  uint local_24 [3];
  _Lockit local_18 [8];
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092031c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_24[1] = 0;
  FUN_00432890(local_d0);
  local_8 = 1;
  FUN_00433c50(local_24 + 2);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_00433a60(local_24);
  if (local_24[0] != 0) {
    std::_Lockit::_Lockit(local_18,0);
    iVar1 = *(int *)(local_24[0] + 4);
    if ((iVar1 != 0) && (iVar1 != -1)) {
      *(int *)(local_24[0] + 4) = iVar1 + -1;
    }
    iVar1 = *(int *)(local_24[0] + 4);
    FUN_0087dd6f();
    puVar2 = (undefined4 *)(~-(uint)(iVar1 != 0) & local_24[0]);
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1);
    }
  }
  local_8._0_1_ = 1;
  if (local_24[2] != 0) {
    std::_Lockit::_Lockit(local_18,0);
    iVar1 = *(int *)(local_24[2] + 4);
    if ((iVar1 != 0) && (iVar1 != -1)) {
      *(int *)(local_24[2] + 4) = iVar1 + -1;
    }
    iVar1 = *(int *)(local_24[2] + 4);
    FUN_0087dd6f();
    puVar2 = (undefined4 *)(~-(uint)(iVar1 != 0) & local_24[2]);
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1);
    }
  }
  *(uint *)((int)auStack_ac + *(int *)(local_c0[0] + 4)) =
       *(uint *)((int)auStack_ac + *(int *)(local_c0[0] + 4)) & 0xffffefff | 0x2000;
  FUN_00433da0(local_c0,param_2,param_3);
  FUN_00431020();
  local_24[1] = 1;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00431040();
  local_70[0] = std::ios_base::vftable;
  std::ios_base::_Ios_base_dtor((ios_base *)local_70);
  ExceptionList = local_10;
  return param_1;
}

