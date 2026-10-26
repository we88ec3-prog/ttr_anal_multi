
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00581c10(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined **local_88 [3];
  undefined **local_7c [3];
  undefined4 *local_70;
  char *local_6c;
  char *local_68;
  wchar_t local_64 [32];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009271cc;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_70 = &DAT_00fc1b90;
  DAT_00fc1b90 = 0;
  DAT_00fc1b94 = 0;
  DAT_00fc1bac = 0xf;
  _DAT_00fc1ba8 = 0;
  DAT_00fc1b98._0_1_ = 0;
  local_8 = 0;
  _DAT_00fc1bbc = 0;
  _DAT_00fc1bc0 = 0;
  _DAT_00fc1bc8 = CDialogTable::vftable;
  _DAT_00fc1bd4 = 0;
  local_14 = uVar1;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 == 0) {
    local_68 = (char *)0x0;
    std::exception::exception((exception *)local_7c,&local_68);
    local_7c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_7c,&DAT_00c857a8);
  }
  DAT_00fc1bd0 = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00fc1bd0 + 4) = DAT_00fc1bd0;
  *(int *)(DAT_00fc1bd0 + 8) = DAT_00fc1bd0;
  *(undefined1 *)(DAT_00fc1bd0 + 0x14) = 1;
  *(undefined1 *)(DAT_00fc1bd0 + 0x15) = 1;
  local_8._0_1_ = 1;
  DAT_00fc1bdc = (undefined4 *)0x0;
  puVar3 = (undefined4 *)FUN_00891268(8,uVar1);
  if (puVar3 != (undefined4 *)0x0) {
    DAT_00fc1bdc = puVar3;
    puVar3[1] = 0;
    *puVar3 = 0;
    *DAT_00fc1bdc = &DAT_00fc1bdc;
    _DAT_00fc1be0 = 0;
    _DAT_00fc1be4 = 0;
    _DAT_00fc1be8 = 0;
    _DAT_00fc1bec = 0;
    local_8._0_1_ = 2;
    local_24 = 0;
    _memset(local_64,0,0x40);
    local_20 = 0x1a;
    local_1c = 4;
    local_18 = 1;
    _wcscpy_s(local_64,0x20,(wchar_t *)PTR_DAT_00d6a23c);
    local_68 = (char *)FUN_00891268(0x50,uVar1);
    local_8._0_1_ = 3;
    if (local_68 == (char *)0x0) {
      DAT_00fc1b94 = 0;
    }
    else {
      DAT_00fc1b94 = FUN_0056c570(local_68,local_64);
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_00513560(&DAT_00fc1bc8);
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_6c = (char *)0x0;
  std::exception::exception((exception *)local_88,&local_6c);
  local_88[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_88,&DAT_00c857a8);
}

