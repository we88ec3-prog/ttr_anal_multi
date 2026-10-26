
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_0074d990(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined **local_38 [3];
  undefined **local_2c [4];
  undefined *local_1c;
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  local_8 = 0xff;
  uStack_7 = 0xffffff;
  puStack_c = &LAB_0090efa9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_1c = &DAT_00f94810;
  _DAT_00f94810 = FoxUI::FXUI::vftable;
  FUN_0074d8d0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_0074d760();
  _DAT_00f95c14 = 0;
  _DAT_00f95c10 = 0;
  _DAT_00f95c0c = 0;
  _DAT_00f95c08 = 0;
  _DAT_00f95c28 = 0;
  iVar1 = FUN_00891268(0x18);
  if (iVar1 != 0) {
    DAT_00f95c24 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00f95c24 + 4) = DAT_00f95c24;
    *(int *)(DAT_00f95c24 + 8) = DAT_00f95c24;
    *(undefined1 *)(DAT_00f95c24 + 0x14) = 1;
    *(undefined1 *)(DAT_00f95c24 + 0x15) = 1;
    local_8 = 0;
    uStack_7 = 0;
    _DAT_00f95c34 = 0;
    iVar1 = FUN_00891268(0xc);
    if (iVar1 == 0) {
LAB_0074dfc3:
      local_14 = (char *)0x0;
      std::exception::exception((exception *)local_2c,&local_14);
      local_2c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_2c,&DAT_00c857a8);
    }
    DAT_00f95c30 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00f95c30 + 4) = DAT_00f95c30;
    local_8 = 1;
    _DAT_00f95c40 = 0;
    iVar1 = FUN_00891268(0xc);
    if (iVar1 == 0) {
      local_18 = (char *)0x0;
      std::exception::exception((exception *)local_38,&local_18);
      local_38[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_38,&DAT_00c857a8);
    }
    DAT_00f95c3c = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00f95c3c + 4) = DAT_00f95c3c;
    local_8 = 2;
    _DAT_00f95c4c = 0;
    iVar1 = FUN_00891268(0xc);
    if (iVar1 == 0) {
      local_14 = (char *)0x0;
      std::exception::exception((exception *)local_2c,&local_14);
      local_2c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_2c,&DAT_00c857a8);
    }
    DAT_00f95c48 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00f95c48 + 4) = DAT_00f95c48;
    local_8 = 3;
    DAT_00f95c54 = (undefined4 *)0x0;
    puVar2 = (undefined4 *)FUN_00891268(8);
    if (puVar2 == (undefined4 *)0x0) {
      local_18 = (char *)0x0;
      std::exception::exception((exception *)local_38,&local_18);
      local_38[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_38,&DAT_00c857a8);
    }
    DAT_00f95c54 = puVar2;
    puVar2[1] = 0;
    *puVar2 = 0;
    *DAT_00f95c54 = &DAT_00f95c54;
    _DAT_00f95c58 = 0;
    _DAT_00f95c5c = 0;
    _DAT_00f95c60 = 0;
    _DAT_00f95c64 = 0;
    local_8 = 4;
    DAT_00f95c6c = (undefined4 *)0x0;
    puVar2 = (undefined4 *)FUN_00891268(8);
    if (puVar2 != (undefined4 *)0x0) {
      DAT_00f95c6c = puVar2;
      puVar2[1] = 0;
      *puVar2 = 0;
      *DAT_00f95c6c = &DAT_00f95c6c;
      DAT_00f95c70 = 0;
      DAT_00f95c74 = 0;
      DAT_00f95c78 = 0;
      DAT_00f95c7c = 0;
      local_8 = 5;
      _DAT_00f95c88 = 0;
      iVar1 = FUN_00891268(0x18);
      if (iVar1 == 0) goto LAB_0074dfe7;
      DAT_00f95c84 = iVar1;
      *(int *)iVar1 = iVar1;
      *(int *)(DAT_00f95c84 + 4) = DAT_00f95c84;
      local_8 = 6;
      _DAT_00f95c94 = 0;
      iVar1 = FUN_00891268(0xc);
      if (iVar1 == 0) goto LAB_0074dfc3;
      DAT_00f95c90 = iVar1;
      *(int *)iVar1 = iVar1;
      *(int *)(DAT_00f95c90 + 4) = DAT_00f95c90;
      _DAT_00f95c9c = 0;
      _DAT_00f95ca0 = 0;
      _DAT_00f95ca4 = 0;
      _DAT_00f95cac = 0;
      _DAT_00f95cb0 = 0;
      _DAT_00f95cb4 = 0;
      local_8 = 9;
      _DAT_00f95cdc = 0;
      iVar1 = FUN_00891268(0xc);
      if (iVar1 != 0) {
        DAT_00f95cd8 = iVar1;
        *(int *)iVar1 = iVar1;
        *(int *)(DAT_00f95cd8 + 4) = DAT_00f95cd8;
        local_8 = 10;
        _eh_vector_constructor_iterator_
                  (&DAT_00f95ce4,0x14,4,(_func_void_void_ptr *)&LAB_0074d950,FUN_005f5d10);
        local_8 = 0xb;
        _eh_vector_constructor_iterator_
                  (&DAT_00f95d34,0x1c,4,(_func_void_void_ptr *)&LAB_0074d970,FUN_005f5d10);
        _local_8 = CONCAT31(uStack_7,0xc);
        _eh_vector_constructor_iterator_
                  (&DAT_00f95dac,0x1c,0xc00,(_func_void_void_ptr *)&LAB_0074d970,FUN_005f5d10);
        _DAT_00f94868 = 0;
        _DAT_00f95cd4 = 0;
        _DAT_00f94864 = 0;
        _DAT_00faadac = 0;
        _DAT_00f94860 = 0;
        _DAT_00f95c18 = 0;
        _DAT_00f9485c = 0;
        _DAT_00f94820 = 0;
        _DAT_00f94854 = 0;
        _DAT_00f94824 = 0;
        _DAT_00f94850 = 0;
        _DAT_00f94818 = 0;
        _DAT_00f9484c = 0;
        _DAT_00f9481c = 0;
        _DAT_00f94848 = 0;
        _DAT_00f95da4 = 0;
        _DAT_00f94840 = 0;
        _DAT_00f95da8 = 0;
        _DAT_00f9483c = 0;
        _DAT_00f94828 = 0;
        _DAT_00f94838 = 0;
        _DAT_00f9482c = 0;
        _DAT_00f94834 = 0;
        _DAT_00f948b0 = 0;
        _DAT_00f948b4 = 0;
        _DAT_00f9486c = 0x3f800000;
        DAT_00f94814 = 0;
        _DAT_00f94858 = 0x3f800000;
        _DAT_00f94844 = 0x3f800000;
        _DAT_00f94830 = 0x3f800000;
        _DAT_00f948ac = 0x3f800000;
        _DAT_00f94898 = 0x3f800000;
        _DAT_00f94884 = 0x3f800000;
        _DAT_00f94870 = 0x3f800000;
        _DAT_00f948a8 = 0;
        _DAT_00f948a4 = 0;
        _DAT_00f948a0 = 0;
        _DAT_00f9489c = 0;
        _DAT_00f94894 = 0;
        _DAT_00f94890 = 0;
        _DAT_00f9488c = 0;
        _DAT_00f94888 = 0;
        _DAT_00f94880 = 0;
        _DAT_00f9487c = 0;
        _DAT_00f94878 = 0;
        _DAT_00f94874 = 0;
        DAT_00f95bbc = 0x3f800000;
        DAT_00f95bc0 = 0x3f800000;
        _DAT_00f95bc4 = 0x3f800000;
        _DAT_00f95bc8 = 0x3f800000;
        _DAT_00f95b9c = 0x3f800000;
        _DAT_00f95ba0 = 0x3f800000;
        _DAT_00f95ba4 = 0x3f800000;
        _DAT_00f95ba8 = 0x3f800000;
        _DAT_00f95b3c = 0;
        DAT_00f95bac = 0x3f800000;
        _DAT_00f95b40 = 0;
        DAT_00f95bb0 = 0x3f800000;
        _DAT_00f95bb4 = 0x3f800000;
        _DAT_00f95bb8 = 0x3f800000;
        _DAT_00f95bcc = 0;
        _DAT_00f95bd0 = 0;
        DAT_00f95bd4 = 0;
        _DAT_00f95bd8 = 0;
        _DAT_00f95bf0 = 0;
        _DAT_00f95bf4 = 0;
        DAT_00f95bdc = 0;
        DAT_00f95be0 = 0;
        _DAT_00f95be4 = 0;
        _DAT_00f95bf8 = 0;
        _DAT_00f95bec = 0;
        _DAT_00f95be8 = 0;
        DAT_00f95bfc = 0;
        DAT_00f95c00 = 0;
        DAT_00f95c04 = 0;
        _DAT_00f95cbc = 0;
        _DAT_00f95cc0 = 0;
        _DAT_00f95b44 = 0;
        DAT_00f95b46 = 0;
        _DAT_00f95b48 = 0;
        _DAT_00f95b4c = 1;
        _DAT_00f95b50 = 2;
        _DAT_00f95b54 = 100;
        _DAT_00f95b58 = 0x66;
        _DAT_00f95b5c = 0x68;
        _DAT_00f95b60 = 0x65;
        _DAT_00f95b64 = 0x67;
        _DAT_00f95b68 = 0x69;
        _DAT_00f95b6c = 0x78;
        _DAT_00f95b70 = 0x7a;
        _DAT_00f95b74 = 0x7c;
        _DAT_00f95b78 = 0x79;
        _DAT_00f95b7c = 0x7b;
        _DAT_00f95b80 = 0x7d;
        _DAT_00f95b84 = 0x8c;
        _DAT_00f95b88 = 0x8e;
        _DAT_00f95b8c = 0x90;
        _DAT_00f95b90 = 0x8d;
        _DAT_00f95b94 = 0x8f;
        _DAT_00f95b98 = 0x91;
        DAT_00f95ccc = 0;
        _DAT_00faadb0 = 0;
        _DAT_00faadb4 = 0x200;
        _DAT_00faadb8 = 0;
        _DAT_00faadbc = 0;
        _DAT_00faadc0 = 0xa8;
        DAT_00faadc4 = 0;
        DAT_00faadc8 = 0;
        DAT_00faadcc = 3;
        DAT_00f95c1c = 0;
        ExceptionList = local_10;
        return &DAT_00f94810;
      }
    }
    local_14 = (char *)0x0;
    std::exception::exception((exception *)local_2c,&local_14);
    local_2c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_2c,&DAT_00c857a8);
  }
LAB_0074dfe7:
  local_18 = (char *)0x0;
  std::exception::exception((exception *)local_38,&local_18);
  local_38[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_38,&DAT_00c857a8);
}

