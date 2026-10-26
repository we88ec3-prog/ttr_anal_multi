
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_004dec90(void)

{
  uint uVar1;
  int iVar2;
  int *unaff_FS_OFFSET;
  undefined **local_34 [3];
  undefined **local_28 [3];
  undefined4 *local_1c;
  char *local_18;
  char *local_14;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00933ddb;
  local_10 = *unaff_FS_OFFSET;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  local_1c = &DAT_00fab130;
  iVar2 = FUN_00891268(0x5f24,uVar1);
  if (iVar2 == 0) {
    DAT_00fab130 = 0;
  }
  else {
    DAT_00fab130 = FUN_004dd700();
  }
  DAT_00fab134 = (undefined4 *)FUN_00891268(0x40,uVar1);
  if (DAT_00fab134 == (undefined4 *)0x0) {
    DAT_00fab134 = (undefined4 *)0x0;
  }
  else {
    *DAT_00fab134 = 0;
    DAT_00fab134[1] = 0;
    DAT_00fab134[2] = 0;
    DAT_00fab134[4] = 0;
    DAT_00fab134[5] = 0;
    DAT_00fab134[6] = 0;
    DAT_00fab134[8] = 0;
    DAT_00fab134[9] = 0;
    DAT_00fab134[10] = 0;
    DAT_00fab134[0xc] = 0;
    *(undefined2 *)(DAT_00fab134 + 0xd) = 0x38;
  }
  _DAT_00fab140 = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_34,&local_18);
    local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00c857a8);
  }
  DAT_00fab13c = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00fab13c + 4) = DAT_00fab13c;
  *(int *)(DAT_00fab13c + 8) = DAT_00fab13c;
  *(undefined1 *)(DAT_00fab13c + 0x14) = 1;
  *(undefined1 *)(DAT_00fab13c + 0x15) = 1;
  local_8 = 0;
  _DAT_00fab150 = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 == 0) {
    local_14 = (char *)0x0;
    std::exception::exception((exception *)local_28,&local_14);
    local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_28,&DAT_00c857a8);
  }
  DAT_00fab14c = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00fab14c + 4) = DAT_00fab14c;
  *(int *)(DAT_00fab14c + 8) = DAT_00fab14c;
  *(undefined1 *)(DAT_00fab14c + 0x14) = 1;
  *(undefined1 *)(DAT_00fab14c + 0x15) = 1;
  local_8._0_1_ = 1;
  _DAT_00fab160 = 0;
  iVar2 = FUN_00891268(0x18);
  if (iVar2 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_34,&local_18);
    local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00c857a8);
  }
  DAT_00fab15c = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00fab15c + 4) = DAT_00fab15c;
  *(int *)(DAT_00fab15c + 8) = DAT_00fab15c;
  *(undefined1 *)(DAT_00fab15c + 0x14) = 1;
  *(undefined1 *)(DAT_00fab15c + 0x15) = 1;
  local_8._0_1_ = 2;
  _DAT_00fab170 = 0;
  iVar2 = FUN_00891268(0x18);
  if (iVar2 == 0) {
    local_14 = (char *)0x0;
    std::exception::exception((exception *)local_28,&local_14);
    local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_28,&DAT_00c857a8);
  }
  DAT_00fab16c = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00fab16c + 4) = DAT_00fab16c;
  *(int *)(DAT_00fab16c + 8) = DAT_00fab16c;
  *(undefined1 *)(DAT_00fab16c + 0x14) = 1;
  *(undefined1 *)(DAT_00fab16c + 0x15) = 1;
  local_8._0_1_ = 3;
  DAT_00fab178 = 0xffffffff;
  DAT_00fab1bc = 0xffffffff;
  DAT_00fab1c0 = 0xffffffff;
  _DAT_00fab1c4 = 0xffffffff;
  _DAT_00fab1c8 = 0;
  DAT_00fab1cc = 0;
  FUN_004e1130(&DAT_00fab1c8,0);
  local_8._0_1_ = 4;
  DAT_00fab1d0 = 0;
  DAT_00fab1d4 = 0;
  _DAT_00fab1d8 = 0;
  _DAT_00fab1dc = 0;
  _DAT_00fab1e0 = 0;
  DAT_00fab1e4 = 0;
  FUN_006d6be0(&DAT_00fab200);
  local_8._0_1_ = 5;
  _DAT_00fab220 = 0;
  _DAT_00fab224 = 0;
  DAT_00fab228 = 0;
  if (DAT_00fba7a4 != (int *)0x0) {
    if (DAT_00fba7ac == 0) {
      FUN_00544f50();
      goto LAB_004def1b;
    }
    (**(code **)(*DAT_00fba7a4 + 0x28))();
    if (DAT_00fba7a4 != (int *)0x0) {
      (**(code **)*DAT_00fba7a4)(1);
    }
  }
  local_18 = (char *)FUN_00891268(0xb4);
  local_8._0_1_ = 9;
  if (local_18 == (char *)0x0) {
    DAT_00fba7a4 = (int *)0x0;
  }
  else {
    DAT_00fba7a4 = (int *)FUN_005471e0();
  }
  local_8 = CONCAT31(local_8._1_3_,5);
  (**(code **)(*DAT_00fba7a4 + 0x24))();
LAB_004def1b:
  *unaff_FS_OFFSET = local_10;
  return &DAT_00fab130;
}

