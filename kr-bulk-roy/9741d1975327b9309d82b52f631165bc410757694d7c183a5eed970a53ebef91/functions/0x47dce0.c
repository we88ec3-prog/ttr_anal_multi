
undefined * FUN_0047dce0(void)

{
  int iVar1;
  undefined **local_24 [3];
  undefined *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009254d6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = &DAT_00fc0f68;
  DAT_00fc0f70 = 0;
  iVar1 = FUN_00891268(0x18,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (iVar1 != 0) {
    DAT_00fc0f6c = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fc0f6c + 4) = DAT_00fc0f6c;
    *(int *)(DAT_00fc0f6c + 8) = DAT_00fc0f6c;
    *(undefined1 *)(DAT_00fc0f6c + 0x14) = 1;
    *(undefined1 *)(DAT_00fc0f6c + 0x15) = 1;
    local_8._0_1_ = 0;
    local_8._1_3_ = 0;
    DAT_00fc0f78 = 0;
    DAT_00fc0f7c = 0xea61;
    FUN_0047de40();
    if ((DAT_00faaf7c & 1) == 0) {
      DAT_00faaf7c = DAT_00faaf7c | 1;
      local_8._0_1_ = 1;
      FUN_0058d410();
      _atexit((_func_4879 *)&LAB_00bccdc0);
      local_8._0_1_ = 0;
    }
    FUN_0058ee60(&DAT_00faaf80);
    if ((DAT_00faaf7c & 1) == 0) {
      DAT_00faaf7c = DAT_00faaf7c | 1;
      local_8._0_1_ = 2;
      FUN_0058d410();
      _atexit((_func_4879 *)&LAB_00bccdc0);
      local_8._0_1_ = 0;
    }
    FUN_0058ee60(&DAT_00faaf80);
    FUN_0047e750(DAT_00fc0f78);
    ExceptionList = local_10;
    return &DAT_00fc0f68;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}

