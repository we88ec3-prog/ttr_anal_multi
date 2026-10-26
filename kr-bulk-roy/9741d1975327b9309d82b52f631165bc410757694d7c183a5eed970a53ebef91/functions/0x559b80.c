
void FUN_00559b80(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined3 uVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *unaff_ESI;
  undefined **local_7c [3];
  undefined1 local_70 [4];
  char *local_6c;
  wchar_t local_68 [32];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00922044;
  local_10 = ExceptionList;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *unaff_ESI = param_1;
  unaff_ESI[1] = 0;
  unaff_ESI[2] = 0;
  unaff_ESI[3] = 0;
  puVar1 = unaff_ESI + 4;
  *puVar1 = 0;
  puVar3 = (undefined4 *)FUN_00891268(8,local_18);
  if (puVar3 != (undefined4 *)0x0) {
    *puVar1 = puVar3;
    *puVar3 = 0;
    puVar3[1] = 0;
    *(undefined4 **)*puVar1 = puVar1;
    unaff_ESI[5] = 0;
    unaff_ESI[6] = 0;
    unaff_ESI[7] = 0;
    unaff_ESI[8] = 0;
    unaff_ESI[10] = 0;
    unaff_ESI[0xb] = 0;
    unaff_ESI[0xc] = 0;
    local_8._1_3_ = 0;
    uVar2 = local_8._1_3_;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    unaff_ESI[0xe] = 0;
    unaff_ESI[0x15] = 0;
    unaff_ESI[0x3a] = 0;
    unaff_ESI[0x3b] = 0;
    if (DAT_00e4b338 == -1) {
      local_28 = 0;
      _memset(local_68,0,0x40);
      local_24 = 0xe;
      local_20 = 4;
      local_1c = 0;
      _wcscpy_s(local_68,0x20,(wchar_t *)PTR_DAT_00d6a230);
      if ((DAT_00fb7bc8 & 1) == 0) {
        DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
        local_8._0_1_ = 2;
        FUN_00734ef0();
        _atexit((_func_4879 *)&LAB_00bcd4f0);
        local_8._0_1_ = 1;
      }
      piVar4 = (int *)FUN_00735850(&DAT_00fb7b70,local_70);
      DAT_00e4b338 = *piVar4;
      uVar2 = local_8._1_3_;
    }
    local_8._1_3_ = uVar2;
    unaff_ESI[0x3d] = 0;
    unaff_ESI[0x3c] = 0;
    unaff_ESI[0x3f] = 0;
    unaff_ESI[0x3e] = 0;
    unaff_ESI[0x40] = 0xffffffff;
    ExceptionList = local_10;
    __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_6c = (char *)0x0;
  std::exception::exception((exception *)local_7c,&local_6c);
  local_7c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_7c,&DAT_00c857a8);
}

