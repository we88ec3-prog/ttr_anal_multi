
void FUN_0049c480(void)

{
  int iVar1;
  undefined4 *puVar2;
  int unaff_ESI;
  int *unaff_FS_OFFSET;
  undefined **local_78 [3];
  undefined1 local_6c [4];
  char *local_68;
  wchar_t local_64 [32];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  int local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00922318;
  local_10 = *unaff_FS_OFFSET;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  *(undefined4 *)(unaff_ESI + 8) = 0;
  iVar1 = FUN_00891268(0x18,local_14);
  if (iVar1 != 0) {
    *(int *)(unaff_ESI + 4) = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(*(int *)(unaff_ESI + 4) + 4) = *(int *)(unaff_ESI + 4);
    *(int *)(*(int *)(unaff_ESI + 4) + 8) = *(int *)(unaff_ESI + 4);
    *(undefined1 *)(*(int *)(unaff_ESI + 4) + 0x14) = 1;
    *(undefined1 *)(*(int *)(unaff_ESI + 4) + 0x15) = 1;
    *(undefined4 *)(unaff_ESI + 0x10) = 0xffffffff;
    local_8 = 0;
    *(undefined4 *)(unaff_ESI + 0x28) = 0xffffffff;
    *(undefined4 *)(unaff_ESI + 0x1c) = 0;
    *(undefined4 *)(unaff_ESI + 0x20) = 0;
    *(undefined4 *)(unaff_ESI + 0x24) = 0;
    *(undefined4 *)(unaff_ESI + 0x18) = 0;
    local_24 = 0;
    _memset(local_64,0,0x40);
    local_20 = 0xc;
    local_1c = 4;
    local_18 = 1;
    _wcscpy_s(local_64,0x20,(wchar_t *)PTR_DAT_00d6a230);
    if ((DAT_00fb7bc8 & 1) == 0) {
      DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
      local_8._0_1_ = 1;
      FUN_00734ef0();
      _atexit((_func_4879 *)&LAB_00bcd4f0);
      local_8 = (uint)local_8._1_3_ << 8;
    }
    puVar2 = (undefined4 *)FUN_00735850(&DAT_00fb7b70,local_6c);
    *(undefined4 *)(unaff_ESI + 0x28) = *puVar2;
    *unaff_FS_OFFSET = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_68 = (char *)0x0;
  std::exception::exception((exception *)local_78,&local_68);
  local_78[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_78,&DAT_00c857a8);
}

