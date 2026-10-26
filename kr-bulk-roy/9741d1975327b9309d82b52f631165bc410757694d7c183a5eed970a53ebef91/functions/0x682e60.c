
undefined4 * FUN_00682e60(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined **local_28 [3];
  char *local_1c;
  undefined4 *local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00919dd3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_007564e0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  param_1[0x3b] = 0;
  *(undefined1 *)(param_1 + 0x3c) = 1;
  local_14 = param_1 + 0x43;
  *param_1 = FUI::CShopTradeWnd::vftable;
  *local_14 = 0;
  param_1[0x44] = 0;
  param_1[0x45] = 0;
  local_18 = param_1 + 0x47;
  *local_18 = 0;
  param_1[0x48] = 0;
  param_1[0x49] = 0;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  puVar1 = param_1 + 0x4b;
  param_1[0x4d] = 0;
  iVar2 = FUN_00891268(0x24);
  if (iVar2 != 0) {
    param_1[0x4c] = iVar2;
    *(int *)iVar2 = iVar2;
    *(undefined4 *)(param_1[0x4c] + 4) = param_1[0x4c];
    *(undefined4 *)(param_1[0x4c] + 8) = param_1[0x4c];
    *(undefined1 *)(param_1[0x4c] + 0x20) = 1;
    *(undefined1 *)(param_1[0x4c] + 0x21) = 1;
    local_8 = CONCAT31(local_8._1_3_,3);
    param_1[0x3d] = 0xffffffff;
    param_1[0x3e] = 0xffffffff;
    param_1[0x3f] = 0;
    param_1[0x40] = 0;
    param_1[0x41] = 0;
    param_1[0x51] = 0xffffffff;
    param_1[0x42] = 0;
    *(undefined1 *)(param_1 + 0x4f) = 0;
    FUN_00684010();
    FUN_00684010();
    local_14 = (undefined4 *)0x8;
    local_18 = (undefined4 *)0x1;
    FUN_00684080(puVar1);
    FUN_004a8680();
    local_14 = (undefined4 *)0x7;
    local_18 = (undefined4 *)0x1;
    FUN_00684080(puVar1);
    FUN_004a8680();
    local_14 = (undefined4 *)0x0;
    local_18 = (undefined4 *)0x2;
    FUN_00684080(puVar1);
    FUN_004a8680();
    local_14 = (undefined4 *)0x1;
    local_18 = (undefined4 *)0x2;
    FUN_00684080(puVar1);
    FUN_004a8680();
    local_14 = (undefined4 *)0x2;
    local_18 = (undefined4 *)0x2;
    FUN_00684080(puVar1);
    FUN_004a8680();
    local_14 = (undefined4 *)0x5;
    local_18 = (undefined4 *)0x3;
    FUN_00684080(puVar1);
    FUN_004a8680();
    local_14 = (undefined4 *)0x8;
    local_18 = (undefined4 *)0x3;
    FUN_00684080(puVar1);
    FUN_004a8680();
    local_14 = (undefined4 *)0x3;
    local_18 = (undefined4 *)0x4;
    FUN_00684080(puVar1);
    FUN_004a8680();
    local_14 = (undefined4 *)0x4;
    local_18 = (undefined4 *)0x4;
    FUN_00684080(puVar1);
    FUN_004a8680();
    local_14 = (undefined4 *)0x3;
    local_18 = (undefined4 *)0x5;
    FUN_00684080(puVar1);
    FUN_004a8680();
    local_14 = (undefined4 *)0x8;
    local_18 = (undefined4 *)0x5;
    FUN_00684080(puVar1);
    FUN_004a8680();
    local_14 = (undefined4 *)0x8;
    local_18 = (undefined4 *)0x6;
    FUN_00684080(puVar1);
    FUN_004a8680();
    local_14 = (undefined4 *)0x8;
    local_18 = (undefined4 *)0x7;
    FUN_00684080(puVar1);
    FUN_004a8680();
    local_14 = (undefined4 *)0x0;
    local_18 = (undefined4 *)0x8;
    FUN_00684080(puVar1);
    FUN_004a8680();
    local_14 = (undefined4 *)0x1;
    local_18 = (undefined4 *)0x8;
    FUN_00684080(puVar1);
    FUN_004a8680();
    local_14 = (undefined4 *)0x2;
    local_18 = (undefined4 *)0x8;
    FUN_00684080(puVar1);
    FUN_004a8680();
    local_14 = (undefined4 *)0x6;
    local_18 = (undefined4 *)0x8;
    FUN_00684080(puVar1);
    FUN_004a8680();
    local_14 = (undefined4 *)0x5;
    local_18 = (undefined4 *)0x8;
    FUN_00684080(puVar1);
    FUN_004a8680();
    local_14 = (undefined4 *)0x8;
    local_18 = (undefined4 *)0x8;
    FUN_00684080(puVar1);
    FUN_004a8680();
    ExceptionList = local_10;
    return param_1;
  }
  local_1c = (char *)0x0;
  std::exception::exception((exception *)local_28,&local_1c);
  local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_28,&DAT_00c857a8);
}

