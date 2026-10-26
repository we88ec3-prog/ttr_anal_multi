
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_004ffe60(void)

{
  uint uVar1;
  int iVar2;
  undefined **local_24 [3];
  undefined4 *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0094427e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = &DAT_00fab2a0;
  local_8 = 0;
  DAT_00fab2a0 = CQuestMgr::vftable;
  local_14 = (char *)FUN_00891268(0x10,uVar1);
  local_8._0_1_ = 1;
  if (local_14 == (char *)0x0) {
    DAT_00fb114c = 0;
  }
  else {
    DAT_00fb114c = FUN_00504370();
  }
  DAT_00fb1150 = 0;
  DAT_00fb1154 = 0;
  _DAT_00fb1158 = 0;
  _DAT_00fb1160 = 0;
  _DAT_00fb1164 = 0;
  _DAT_00fb1168 = 0;
  local_8._0_1_ = 3;
  _DAT_00fb11a0 = 0;
  iVar2 = FUN_00891268(0x30,uVar1);
  if (iVar2 != 0) {
    DAT_00fb119c = iVar2;
    *(int *)iVar2 = iVar2;
    *(int *)(DAT_00fb119c + 4) = DAT_00fb119c;
    *(int *)(DAT_00fb119c + 8) = DAT_00fb119c;
    *(undefined1 *)(DAT_00fb119c + 0x2c) = 1;
    *(undefined1 *)(DAT_00fb119c + 0x2d) = 1;
    local_8 = CONCAT31(local_8._1_3_,4);
    FUN_005020b0();
    FUN_005038f0();
    ExceptionList = local_10;
    return &DAT_00fab2a0;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}

