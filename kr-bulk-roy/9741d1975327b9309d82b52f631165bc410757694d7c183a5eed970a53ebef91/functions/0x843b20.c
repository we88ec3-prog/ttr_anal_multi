
undefined4 * FUN_00843b20(undefined4 *param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined **local_2c [5];
  char *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00914120;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_0077fed0(param_1);
  local_8 = 0;
  *param_1 = gbMaterial::vftable;
  param_1[0x17] = 0;
  uVar2 = FUN_00820120(uVar1);
  param_1[0x16] = uVar2;
  *(undefined4 *)uVar2 = uVar2;
  *(undefined4 *)(param_1[0x16] + 4) = param_1[0x16];
  *(undefined4 *)(param_1[0x16] + 8) = param_1[0x16];
  *(undefined1 *)(param_1[0x16] + 0x18) = 1;
  *(undefined1 *)(param_1[0x16] + 0x19) = 1;
  local_8._0_1_ = 1;
  _eh_vector_constructor_iterator_(param_1 + 0x19,0x10,8,FUN_00844c20,FUN_00843ab0);
  local_8._0_1_ = 2;
  _eh_vector_constructor_iterator_(param_1 + 0x39,0x10,8,FUN_00844c20,FUN_00843ab0);
  local_8._0_1_ = 3;
  param_1[0x59] = 0;
  param_1[0x5b] = 0;
  param_1[0x5e] = 0;
  iVar3 = FUN_00891268(0x18);
  if (iVar3 != 0) {
    param_1[0x5d] = iVar3;
    *(int *)iVar3 = iVar3;
    *(undefined4 *)(param_1[0x5d] + 4) = param_1[0x5d];
    *(undefined4 *)(param_1[0x5d] + 8) = param_1[0x5d];
    *(undefined1 *)(param_1[0x5d] + 0x14) = 1;
    *(undefined1 *)(param_1[0x5d] + 0x15) = 1;
    local_8 = CONCAT31(local_8._1_3_,4);
    if (param_1 + 0x5c != (undefined4 *)(param_2 + 0x170)) {
      FUN_00844d40(*(undefined4 *)param_1[0x5d],(undefined4 *)param_1[0x5d]);
      FUN_00844e00(param_2 + 0x170);
    }
    param_1[0x59] = *(undefined4 *)(param_2 + 0x164);
    param_1[0x5a] = *(undefined4 *)(param_2 + 0x168);
    if (param_1 + 0x15 != (undefined4 *)(param_2 + 0x54)) {
      FUN_00535ac0(*(undefined4 *)param_1[0x16],(undefined4 *)param_1[0x16]);
      FUN_006cf030(param_2 + 0x54);
    }
    puVar4 = (undefined4 *)(param_2 + 0xe4);
    param_1[0x5b] = *(undefined4 *)(param_2 + 0x16c);
    puVar5 = param_1 + 0x3a;
    local_14 = 8;
    do {
      if (puVar5 + -0x21 != puVar4 + -0x20) {
        FUN_00535ac0(*(undefined4 *)puVar5[-0x20],(undefined4 *)puVar5[-0x20]);
        FUN_006cf030(puVar4 + -0x20);
      }
      if (puVar5 + -1 != puVar4) {
        FUN_00535ac0(*(undefined4 *)*puVar5,(undefined4 *)*puVar5);
        FUN_006cf030(puVar4);
      }
      puVar4 = puVar4 + 4;
      puVar5 = puVar5 + 4;
      local_14 = local_14 + -1;
    } while (local_14 != 0);
    ExceptionList = local_10;
    return param_1;
  }
  local_18 = (char *)0x0;
  std::exception::exception((exception *)local_2c,&local_18);
  local_2c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_2c,&DAT_00c857a8);
}

