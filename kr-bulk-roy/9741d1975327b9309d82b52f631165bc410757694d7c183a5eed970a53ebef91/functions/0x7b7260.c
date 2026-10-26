
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_007b7260(void)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined **local_3c [3];
  undefined **local_30 [3];
  undefined *local_24;
  char *local_20;
  char *local_1c;
  int local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090a040;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_24 = &DAT_00fc1260;
  FUN_007b7b30(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  DAT_00fc1270 = (undefined4 *)0x0;
  puVar1 = (undefined4 *)FUN_00891268(8);
  if (puVar1 == (undefined4 *)0x0) {
    local_20 = (char *)0x0;
    std::exception::exception((exception *)local_3c,&local_20);
    local_3c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_3c,&DAT_00c857a8);
  }
  DAT_00fc1270 = puVar1;
  puVar1[1] = 0;
  *puVar1 = 0;
  *DAT_00fc1270 = &DAT_00fc1270;
  DAT_00fc1274 = 0;
  DAT_00fc1278 = 0;
  DAT_00fc127c = 0;
  DAT_00fc1280 = 0;
  local_8 = CONCAT31(local_8._1_3_,1);
  DAT_00fc1688 = 0;
  _DAT_00fc168c = 0;
  _memset(&DAT_00fc1288,0,0x400);
  local_18 = 0;
  do {
    local_14 = (undefined4 *)FUN_00891268(0x28);
    if (local_14 == (undefined4 *)0x0) {
      local_14 = (undefined4 *)0x0;
    }
    else {
      *local_14 = IS3D::CTrail::vftable;
      local_14[1] = 0;
      local_14[2] = 0;
      local_14[3] = 0;
      local_14[4] = 0;
      local_14[5] = 0;
      local_14[8] = 0;
      local_14[9] = 0;
      local_14[7] = 0;
    }
    if (((DAT_00fc1280 + DAT_00fc127c & 3U) == 0) && (DAT_00fc1278 <= DAT_00fc1280 + 4U >> 2)) {
      FUN_00636f70(&DAT_00fc1270);
    }
    uVar4 = DAT_00fc1280 + DAT_00fc127c;
    uVar3 = uVar4 >> 2;
    if (DAT_00fc1278 <= uVar3) {
      uVar3 = uVar3 - DAT_00fc1278;
    }
    if (*(int *)(DAT_00fc1274 + uVar3 * 4) == 0) {
      iVar2 = FUN_00891268(0x10);
      if (iVar2 == 0) {
        local_1c = (char *)0x0;
        std::exception::exception((exception *)local_30,&local_1c);
        local_30[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(local_30,&DAT_00c857a8);
      }
      *(int *)(DAT_00fc1274 + uVar3 * 4) = iVar2;
    }
    puVar1 = (undefined4 *)(*(int *)(DAT_00fc1274 + uVar3 * 4) + (uVar4 & 3) * 4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = local_14;
    }
    DAT_00fc1280 = DAT_00fc1280 + 1;
    local_18 = local_18 + 1;
  } while (local_18 < 0x100);
  ExceptionList = local_10;
  return &DAT_00fc1260;
}

