
void FUN_006bd7f0(void)

{
  undefined4 uVar1;
  undefined4 local_40 [2];
  char *local_38;
  undefined **local_34 [3];
  undefined1 local_28 [4];
  undefined4 *local_24;
  undefined4 local_20;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00922ab0;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  local_20 = 0;
  local_24 = (undefined4 *)FUN_00891268(0x14,DAT_00d61f20 ^ (uint)&stack0xffffffb8);
  if (local_24 != (undefined4 *)0x0) {
    *local_24 = local_24;
    local_24[1] = local_24;
    local_24[2] = local_24;
    *(undefined1 *)(local_24 + 4) = 1;
    *(undefined1 *)((int)local_24 + 0x11) = 1;
    local_c = 0;
    local_40[0] = 0xd4;
    uVar1 = FUN_006bde40(local_40);
    FUN_0044bbd0(local_28,uVar1);
    local_40[0] = 0xd3;
    uVar1 = FUN_006bde40(local_40);
    FUN_0044bbd0(local_28,uVar1);
    local_40[0] = 0x93;
    uVar1 = FUN_006bde40(local_40);
    FUN_0044bbd0(local_28,uVar1);
    local_40[0] = 0x92;
    uVar1 = FUN_006bde40(local_40);
    FUN_0044bbd0(local_28,uVar1);
    local_40[0] = 0x11c;
    uVar1 = FUN_006bde40(local_40);
    FUN_0044bbd0(local_28,uVar1);
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c._0_1_ = 1;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_c = (uint)local_c._1_3_ << 8;
    }
    FUN_0058b450(local_28);
    local_c = 2;
    FUN_004ca160(*local_24,local_24);
    FUN_0089120c(local_24);
    ExceptionList = local_14;
    return;
  }
  local_38 = (char *)0x0;
  std::exception::exception((exception *)local_34,&local_38);
  local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_34,&DAT_00c857a8);
}

