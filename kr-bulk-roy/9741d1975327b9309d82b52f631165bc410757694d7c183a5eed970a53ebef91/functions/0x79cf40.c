
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_0079cf40(void)

{
  uint uVar1;
  int iVar2;
  int *unaff_FS_OFFSET;
  undefined **local_24 [3];
  undefined *local_18;
  char *local_14;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00938ed8;
  local_10 = *unaff_FS_OFFSET;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  local_18 = &DAT_00fc0e90;
  DAT_00fc0e98 = 0;
  DAT_00fc0e94 = FUN_00820120(uVar1);
  *(int *)DAT_00fc0e94 = DAT_00fc0e94;
  *(int *)(DAT_00fc0e94 + 4) = DAT_00fc0e94;
  *(int *)(DAT_00fc0e94 + 8) = DAT_00fc0e94;
  *(undefined1 *)(DAT_00fc0e94 + 0x18) = 1;
  *(undefined1 *)(DAT_00fc0e94 + 0x19) = 1;
  local_8 = 0;
  _DAT_00fc0ea8 = 0;
  iVar2 = FUN_00891268(0x34);
  if (iVar2 != 0) {
    DAT_00fc0ea4 = iVar2;
    *(int *)iVar2 = iVar2;
    *(int *)(DAT_00fc0ea4 + 4) = DAT_00fc0ea4;
    *(int *)(DAT_00fc0ea4 + 8) = DAT_00fc0ea4;
    *(undefined1 *)(DAT_00fc0ea4 + 0x30) = 1;
    *(undefined1 *)(DAT_00fc0ea4 + 0x31) = 1;
    DAT_00fc0eb0 = 0;
    _DAT_00fc0eb4 = 0;
    DAT_00fc0eb8 = 0;
    DAT_00fc0ebc = 0;
    _DAT_00fc0ec0 = 0;
    DAT_00fc0ec8 = 0;
    DAT_00fc0ecc = 0;
    _DAT_00fc0ed0 = 0;
    local_8 = CONCAT31(local_8._1_3_,3);
    _eh_vector_constructor_iterator_
              (&DAT_00fc0ed8,8,4,(_func_void_void_ptr *)&LAB_007a0d90,FUN_0047bb80);
    _DAT_00fc0ef8 = 0;
    DAT_00fc0efc = 0;
    InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)&DAT_00fc0f00,4000);
    DAT_00fc0f18 = 0;
    DAT_00fc0f1c = 0;
    _DAT_00fc0f20 = 0;
    InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)&DAT_00fc0f28,4000);
    DAT_00fc0f40 = 0;
    DAT_00fc0f44 = 0;
    _DAT_00fc0f48 = 0;
    DAT_00fc0f58 = 0;
    DAT_00fc0f5c = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    DAT_00fc0f54 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    __beginthread(FUN_0079dea0,0,&DAT_00fc0e90);
    *unaff_FS_OFFSET = local_10;
    return &DAT_00fc0e90;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}

