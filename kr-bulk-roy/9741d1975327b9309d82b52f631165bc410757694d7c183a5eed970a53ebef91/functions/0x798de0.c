
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00798de0(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int *unaff_FS_OFFSET;
  _union_530 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [3];
  undefined **local_28 [3];
  undefined4 *local_1c;
  char *local_18;
  char *local_14;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092a6c2;
  local_10 = *unaff_FS_OFFSET;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  local_1c = &DAT_00fb76a8;
  DAT_00fb76a8 = 0;
  DAT_00fb76ac = (undefined4 *)FUN_00891268(0x10,uVar1);
  if (DAT_00fb76ac == (undefined4 *)0x0) {
    DAT_00fb76ac = (undefined4 *)0x0;
  }
  else {
    *DAT_00fb76ac = 0;
    DAT_00fb76ac[1] = 0;
    DAT_00fb76ac[2] = 0;
    DAT_00fb76ac[3] = 0x3f800000;
  }
  DAT_00fb76b0 = (undefined4 *)FUN_00891268(0x60,uVar1);
  if (DAT_00fb76b0 == (undefined4 *)0x0) {
    DAT_00fb76b0 = (undefined4 *)0x0;
  }
  else {
    *DAT_00fb76b0 = 0;
    DAT_00fb76b0[1] = 0;
    DAT_00fb76b0[2] = 0;
    DAT_00fb76b0[3] = 0;
    DAT_00fb76b0[4] = 0;
    DAT_00fb76b0[5] = 0;
    DAT_00fb76b0[6] = 0;
    DAT_00fb76b0[7] = 0;
    DAT_00fb76b0[8] = 0;
    DAT_00fb76b0[9] = 0;
    DAT_00fb76b0[10] = 0;
    DAT_00fb76b0[0xb] = 0;
    DAT_00fb76b0[0xc] = 0;
    DAT_00fb76b0[0xd] = 0;
    DAT_00fb76b0[0xe] = 0;
    DAT_00fb76b0[0xf] = 0;
    DAT_00fb76b0[0x10] = 0;
    DAT_00fb76b0[0x11] = 0;
    DAT_00fb76b0[0x12] = 0;
    DAT_00fb76b0[0x13] = 0;
    DAT_00fb76b0[0x14] = 0;
    DAT_00fb76b0[0x15] = 0;
    DAT_00fb76b0[0x16] = 0;
    DAT_00fb76b0[0x17] = 0;
  }
  DAT_00fb76b4 = 0;
  _DAT_00fb76b8 = 0;
  _DAT_00fb76bc = 0;
  _DAT_00fb76c8 = 0;
  iVar2 = FUN_00891268(0x30,uVar1);
  if (iVar2 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_34,&local_18);
    local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00c857a8);
  }
  DAT_00fb76c4 = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00fb76c4 + 4) = DAT_00fb76c4;
  *(int *)(DAT_00fb76c4 + 8) = DAT_00fb76c4;
  *(undefined1 *)(DAT_00fb76c4 + 0x2c) = 1;
  *(undefined1 *)(DAT_00fb76c4 + 0x2d) = 1;
  local_8 = 0;
  _DAT_00fb76d4 = 0;
  iVar2 = FUN_00891268(0xc,uVar1);
  if (iVar2 == 0) {
    local_14 = (char *)0x0;
    std::exception::exception((exception *)local_28,&local_14);
    local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_28,&DAT_00c857a8);
  }
  DAT_00fb76d0 = iVar2;
  *(int *)iVar2 = iVar2;
  *(int *)(DAT_00fb76d0 + 4) = DAT_00fb76d0;
  local_8._0_1_ = 1;
  _DAT_00fb76dc = 0;
  _DAT_00fb76e0 = 0;
  DAT_00fb76e4 = 1;
  DAT_00fb76e8 = 0;
  _DAT_00fb7734 = 0;
  DAT_00fb7738 = 0;
  DAT_00fb7740 = FUN_00891268(0x2c058,uVar1);
  if (DAT_00fb7740 == 0) {
    DAT_00fb7740 = 0;
  }
  else {
    iVar2 = 0x15;
    puVar3 = (undefined4 *)(DAT_00fb7740 + 0x2000);
    do {
      *puVar3 = 0;
      puVar3 = puVar3 + 0x801;
      iVar2 = iVar2 + -1;
    } while (-1 < iVar2);
  }
  DAT_00fb7744 = (undefined4 *)FUN_00891268(0x10);
  if (DAT_00fb7744 == (undefined4 *)0x0) {
    DAT_00fb7744 = (undefined4 *)0x0;
  }
  else {
    *DAT_00fb7744 = 0;
    DAT_00fb7744[1] = 0;
    DAT_00fb7744[2] = 0;
  }
  DAT_00fb7748 = 0;
  DAT_00fb774c = 0;
  _DAT_00fb7750 = 0;
  _DAT_00fb775c = 0;
  iVar2 = FUN_00891268(0x14);
  if (iVar2 != 0) {
    DAT_00fb7758 = iVar2;
    *(int *)iVar2 = iVar2;
    *(int *)(DAT_00fb7758 + 4) = DAT_00fb7758;
    *(int *)(DAT_00fb7758 + 8) = DAT_00fb7758;
    *(undefined1 *)(DAT_00fb7758 + 0x10) = 1;
    *(undefined1 *)(DAT_00fb7758 + 0x11) = 1;
    local_8._0_1_ = 2;
    _DAT_00fb776c = 0;
    iVar2 = FUN_00891268(0x14);
    if (iVar2 != 0) {
      DAT_00fb7768 = iVar2;
      *(int *)iVar2 = iVar2;
      *(int *)(DAT_00fb7768 + 4) = DAT_00fb7768;
      *(int *)(DAT_00fb7768 + 8) = DAT_00fb7768;
      *(undefined1 *)(DAT_00fb7768 + 0x10) = 1;
      *(undefined1 *)(DAT_00fb7768 + 0x11) = 1;
      local_8._0_1_ = 3;
      _eh_vector_constructor_iterator_
                (&DAT_00fb7774,0x10,0x20,(_func_void_void_ptr *)&LAB_00689330,FUN_00418290);
      DAT_00fb7974 = 0;
      DAT_00fb7978 = 0;
      _DAT_00fb797c = 0;
      DAT_00fb7994 = 0;
      DAT_00fb7984 = 0;
      DAT_00fb7998 = 0;
      DAT_00fb7988 = 0;
      DAT_00fb799c = 0;
      DAT_00fb798c = 1;
      DAT_00fb79a0 = 0;
      DAT_00fb7990 = 0;
      DAT_00fb79a4 = 0xff8070cb;
      _DAT_00fb79a8 = 0;
      _DAT_00fb79ac = 0;
      DAT_00fb79b0 = 0;
      _DAT_00fb79b4 = 0;
      _DAT_00fb79b8 = 0;
      DAT_00fb79c0 = 0;
      _DAT_00fb79c4 = 0;
      _DAT_00fb79c8 = 0;
      DAT_00fb79d0 = 0;
      _DAT_00fb79d4 = 0;
      _DAT_00fb79d8 = 0;
      DAT_00fb79e0 = 0;
      local_8._0_1_ = 6;
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00fb7704);
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00fb771c);
      local_58.dwOemId = 0;
      local_54 = 0;
      local_50 = 0;
      local_4c = 0;
      local_48 = 0;
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
      local_38 = 0;
      GetSystemInfo((LPSYSTEM_INFO)&local_58.s);
      FUN_006ee380(&DAT_00fb79ac);
      if ((DAT_00fe1df8 & 1) == 0) {
        DAT_00fe1df8 = DAT_00fe1df8 | 1;
        local_8._0_1_ = 7;
        FUN_00716be0();
        _atexit((_func_4879 *)&LAB_00bcf1a0);
        local_8._0_1_ = 6;
      }
      iVar2 = FUN_00716440(&DAT_00fe1dfc);
      if (iVar2 == 0) {
        _DAT_00fb79a8 = 0;
        if ((DAT_00fe1df8 & 1) == 0) {
          DAT_00fe1df8 = DAT_00fe1df8 | 1;
          local_8._0_1_ = 8;
          FUN_00716be0();
          _atexit((_func_4879 *)&LAB_00bcf1a0);
          local_8._0_1_ = 6;
        }
        FUN_00716040("CHA_ABF","*.abf",1);
        if ((DAT_00fe1df8 & 1) == 0) {
          DAT_00fe1df8 = DAT_00fe1df8 | 1;
          local_8._0_1_ = 9;
          FUN_00716be0();
          _atexit((_func_4879 *)&LAB_00bcf1a0);
          local_8._0_1_ = 6;
        }
        FUN_00716040("MAP_OBJ","*.gb3",1);
        if ((DAT_00fe1df8 & 1) == 0) {
          DAT_00fe1df8 = DAT_00fe1df8 | 1;
          local_8._0_1_ = 10;
          FUN_00716be0();
          _atexit((_func_4879 *)&LAB_00bcf1a0);
          local_8._0_1_ = 6;
        }
        FUN_00716040("MAP_PTC","*.ptc",1);
        if ((DAT_00fe1df8 & 1) == 0) {
          DAT_00fe1df8 = DAT_00fe1df8 | 1;
          local_8._0_1_ = 0xb;
          FUN_00716be0();
          _atexit((_func_4879 *)&LAB_00bcf1a0);
          local_8._0_1_ = 6;
        }
        FUN_00716040("MAP_MO3","*.mo3",1);
        if ((DAT_00fe1df8 & 1) == 0) {
          DAT_00fe1df8 = DAT_00fe1df8 | 1;
          local_8._0_1_ = 0xc;
          FUN_00716be0();
          _atexit((_func_4879 *)&LAB_00bcf1a0);
          local_8._0_1_ = 6;
        }
        FUN_00716040("MAP_DDS","*.dds",1);
        if ((DAT_00fe1df8 & 1) == 0) {
          DAT_00fe1df8 = DAT_00fe1df8 | 1;
          local_8._0_1_ = 0xd;
          FUN_00716be0();
          _atexit((_func_4879 *)&LAB_00bcf1a0);
          local_8._0_1_ = 6;
        }
        FUN_00716040("MAP_MRE","*.mre",1);
        if ((DAT_00fe1df8 & 1) == 0) {
          DAT_00fe1df8 = DAT_00fe1df8 | 1;
          local_8._0_1_ = 0xe;
          FUN_00716be0();
          _atexit((_func_4879 *)&LAB_00bcf1a0);
          local_8._0_1_ = 6;
        }
        FUN_00716040("MAP_FLD","*.fld",1);
        if ((DAT_00fe1df8 & 1) == 0) {
          DAT_00fe1df8 = DAT_00fe1df8 | 1;
          local_8._0_1_ = 0xf;
          FUN_00716be0();
          _atexit((_func_4879 *)&LAB_00bcf1a0);
          local_8._0_1_ = 6;
        }
        FUN_00716040("EFF_EFF","*.eff",1);
        if ((DAT_00fe1df8 & 1) == 0) {
          DAT_00fe1df8 = DAT_00fe1df8 | 1;
          local_8._0_1_ = 0x10;
          FUN_00716be0();
          _atexit((_func_4879 *)&LAB_00bcf1a0);
          local_8._0_1_ = 6;
        }
        FUN_00716040("EFF_DDS","*.dds",1);
        if ((DAT_00fe1df8 & 1) == 0) {
          DAT_00fe1df8 = DAT_00fe1df8 | 1;
          local_8._0_1_ = 0x11;
          FUN_00716be0();
          _atexit((_func_4879 *)&LAB_00bcf1a0);
          local_8._0_1_ = 6;
        }
        FUN_00716040("COMMON_DDS","*.dds",1);
        if ((DAT_00fe1df8 & 1) == 0) {
          DAT_00fe1df8 = DAT_00fe1df8 | 1;
          local_8._0_1_ = 0x12;
          FUN_00716be0();
          _atexit((_func_4879 *)&LAB_00bcf1a0);
          local_8._0_1_ = 6;
        }
        FUN_00716240(&DAT_00fe1dfc);
      }
      else {
        _DAT_00fb79a8 = 1;
      }
      *unaff_FS_OFFSET = local_10;
      return &DAT_00fb76a8;
    }
    local_14 = (char *)0x0;
    std::exception::exception((exception *)local_28,&local_14);
    local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_28,&DAT_00c857a8);
  }
  local_18 = (char *)0x0;
  std::exception::exception((exception *)local_34,&local_18);
  local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_34,&DAT_00c857a8);
}

