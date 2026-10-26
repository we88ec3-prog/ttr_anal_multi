
void FUN_008fdaf0(void)

{
  undefined4 *puVar1;
  undefined4 *unaff_EDI;
  undefined1 local_68 [4];
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
  puStack_c = &LAB_00921ae3;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_005716f0(local_14);
  local_8 = 0;
  *unaff_EDI = CRandomItemViewer::vftable;
  FUN_005720d0();
  local_8._0_1_ = 1;
  unaff_EDI[0x1c] = 0xffffffff;
  unaff_EDI[0x19] = 0xffffffff;
  unaff_EDI[0x1a] = 0xffffffff;
  unaff_EDI[0x1b] = 0xffffffff;
  unaff_EDI[5] = 0;
  unaff_EDI[6] = 0;
  *(undefined1 *)(unaff_EDI + 7) = 0;
  unaff_EDI[8] = 0;
  unaff_EDI[9] = 0;
  *(undefined2 *)(unaff_EDI + 0xb) = 0;
  *(undefined1 *)((int)unaff_EDI + 0x2e) = 0;
  unaff_EDI[0xd] = 0x36;
  unaff_EDI[0xe] = 0x1c;
  unaff_EDI[0xf] = 0xca;
  unaff_EDI[0x10] = 0xe4;
  unaff_EDI[0xc] = 0;
  unaff_EDI[0x11] = 0;
  unaff_EDI[0x12] = 0;
  unaff_EDI[0x13] = 0;
  unaff_EDI[0x14] = 0;
  unaff_EDI[0x15] = 0;
  unaff_EDI[0x16] = 0;
  unaff_EDI[0x17] = 0;
  *(undefined1 *)(unaff_EDI + 0x18) = 0;
  local_24 = 0;
  _memset(local_64,0,0x40);
  local_20 = 0xc;
  local_1c = 4;
  local_18 = 1;
  _wcscpy_s(local_64,0x20,(wchar_t *)PTR_DAT_00d6a230);
  if ((DAT_00fb7bc8 & 1) == 0) {
    DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
    local_8._0_1_ = 2;
    FUN_00734ef0();
    _atexit((_func_4879 *)&LAB_00bcd4f0);
    local_8._0_1_ = 1;
  }
  puVar1 = (undefined4 *)FUN_00735850(&DAT_00fb7b70,local_68);
  unaff_EDI[0x1c] = *puVar1;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

