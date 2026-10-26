
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0055ee90(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined **local_88 [3];
  undefined **local_7c [3];
  undefined1 local_70 [4];
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
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093a845;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  DAT_00fc1b20 = 0;
  DAT_00fc1b24 = (undefined4 *)0x0;
  local_14 = uVar1;
  puVar2 = (undefined4 *)FUN_00891268(8,uVar1);
  if (puVar2 == (undefined4 *)0x0) {
    local_68 = (char *)0x0;
    std::exception::exception((exception *)local_7c,&local_68);
    local_7c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_7c,&DAT_00c857a8);
  }
  DAT_00fc1b24 = puVar2;
  *puVar2 = 0;
  puVar2[1] = 0;
  *DAT_00fc1b24 = &DAT_00fc1b24;
  _DAT_00fc1b28 = 0;
  _DAT_00fc1b2c = 0;
  _DAT_00fc1b30 = 0;
  _DAT_00fc1b34 = 0;
  local_8 = 0;
  DAT_00fc1b3c = 0;
  _DAT_00fc1b40 = 0;
  _DAT_00fc1b44 = 0;
  _DAT_00fc1b48 = 0x400;
  _DAT_00fc1b4c = 0x300;
  _DAT_00fc1b54 = CDialogTable::vftable;
  _DAT_00fc1b60 = 0;
  iVar3 = FUN_00891268(0x18,uVar1);
  if (iVar3 != 0) {
    DAT_00fc1b5c = iVar3;
    *(int *)iVar3 = iVar3;
    *(int *)(DAT_00fc1b5c + 4) = DAT_00fc1b5c;
    *(int *)(DAT_00fc1b5c + 8) = DAT_00fc1b5c;
    *(undefined1 *)(DAT_00fc1b5c + 0x14) = 1;
    *(undefined1 *)(DAT_00fc1b5c + 0x15) = 1;
    local_8._0_1_ = 1;
    _DAT_00fc1b68 = 0;
    _DAT_00fc1b6c = 0x3f800000;
    _DAT_00fc1b70 = 0;
    _DAT_00fc1b74 = 0;
    _DAT_00fc1b78 = 0x3f800000;
    _DAT_00fc1b7c = 0;
    _DAT_00fc1b80 = 0x3f800000;
    _DAT_00fc1b84 = 0;
    DAT_00fc1b18 = 0;
    local_24 = 0;
    _memset(local_64,0,0x40);
    local_20 = 0x1a;
    local_1c = 4;
    local_18 = 1;
    _wcscpy_s(local_64,0x20,(wchar_t *)PTR_DAT_00d6a23c);
    local_68 = (char *)FUN_00891268(0x50,uVar1);
    local_8._0_1_ = 2;
    if (local_68 == (char *)0x0) {
      DAT_00fc1b1c = 0;
    }
    else {
      DAT_00fc1b1c = FUN_0056c570(local_68,local_64);
    }
    if ((DAT_00fdf3d4 & 1) == 0) {
      DAT_00fdf3d4 = DAT_00fdf3d4 | 1;
      local_8._0_1_ = 3;
      FUN_006f4380();
      _atexit((_func_4879 *)&LAB_00bce6d0);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    uVar4 = FUN_0055fd70(local_70,&DAT_00fdf3c8);
    FUN_0055fe50(uVar4);
    FUN_00513560(&DAT_00fc1b54);
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

