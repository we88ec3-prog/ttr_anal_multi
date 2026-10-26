
undefined4 * FUN_005727a0(undefined4 *param_1,char *param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined **local_20 [3];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091de21;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = param_2;
  iVar3 = FUN_00891268(0x10,uVar2);
  local_8 = 0;
  local_14 = iVar3;
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    *(undefined4 *)(iVar3 + 8) = 0;
    iVar4 = FUN_00891268(0x30,uVar2);
    if (iVar4 == 0) {
      param_2 = (char *)0x0;
      std::exception::exception((exception *)local_20,&param_2);
      local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_20,&DAT_00c857a8);
    }
    *(int *)(iVar3 + 4) = iVar4;
    *(int *)iVar4 = iVar4;
    *(int *)(*(int *)(iVar3 + 4) + 4) = *(int *)(iVar3 + 4);
    *(int *)(*(int *)(iVar3 + 4) + 8) = *(int *)(iVar3 + 4);
    *(undefined1 *)(*(int *)(iVar3 + 4) + 0x2c) = 1;
    *(undefined1 *)(*(int *)(iVar3 + 4) + 0x2d) = 1;
  }
  param_1[1] = iVar3;
  puVar1 = param_1 + 2;
  *puVar1 = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  local_8 = 1;
  iVar3 = FUN_00891268(0x10,uVar2);
  local_8._0_1_ = 2;
  local_14 = iVar3;
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    *(undefined4 *)(iVar3 + 8) = 0;
    iVar4 = FUN_00891268(0x74,uVar2);
    if (iVar4 == 0) {
      param_2 = (char *)0x0;
      std::exception::exception((exception *)local_20,&param_2);
      local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_20,&DAT_00c857a8);
    }
    *(int *)(iVar3 + 4) = iVar4;
    *(int *)iVar4 = iVar4;
    *(int *)(*(int *)(iVar3 + 4) + 4) = *(int *)(iVar3 + 4);
    *(int *)(*(int *)(iVar3 + 4) + 8) = *(int *)(iVar3 + 4);
    *(undefined1 *)(*(int *)(iVar3 + 4) + 0x70) = 1;
    *(undefined1 *)(*(int *)(iVar3 + 4) + 0x71) = 1;
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  param_1[6] = iVar3;
  param_1[7] = 0;
  param_1[0xc] = 0x3f800000;
  param_1[0xd] = 0x3f800000;
  iVar3 = param_1[1];
  param_1[0xe] = 0;
  param_1[0xf] = 1;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 1;
  FUN_00504180(*(undefined4 *)(*(int *)(iVar3 + 4) + 4));
  *(int *)(*(int *)(iVar3 + 4) + 4) = *(int *)(iVar3 + 4);
  *(undefined4 *)*(undefined4 *)(iVar3 + 4) = *(undefined4 *)(iVar3 + 4);
  *(int *)(*(int *)(iVar3 + 4) + 8) = *(int *)(iVar3 + 4);
  *(undefined4 *)(iVar3 + 8) = 0;
  iVar3 = param_1[6];
  FUN_005741d0(*(undefined4 *)(*(int *)(iVar3 + 4) + 4));
  *(int *)(*(int *)(iVar3 + 4) + 4) = *(int *)(iVar3 + 4);
  *(undefined4 *)*(undefined4 *)(iVar3 + 4) = *(undefined4 *)(iVar3 + 4);
  *(int *)(*(int *)(iVar3 + 4) + 8) = *(int *)(iVar3 + 4);
  *(undefined4 *)(iVar3 + 8) = 0;
  FUN_00556160(puVar1,&param_2,*puVar1,param_1[3]);
  ExceptionList = local_10;
  return param_1;
}

