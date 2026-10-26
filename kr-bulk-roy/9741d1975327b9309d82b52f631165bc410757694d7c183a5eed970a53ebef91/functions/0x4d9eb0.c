
undefined4 FUN_004d9eb0(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  uint in_ECX;
  char *pcVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  char *local_44;
  int local_40;
  char *local_3c;
  short local_38;
  uint *local_34;
  undefined **local_30 [3];
  undefined **local_24 [4];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00924bba;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  local_40 = param_1 + 0x10;
  FUN_004e0fc0(local_40,DAT_00d61f20 ^ (uint)&stack0xffffffb0);
  local_44 = (char *)0x0;
  if (in_ECX < 2) {
    pcVar5 = (char *)0x0;
  }
  else {
    pcVar5 = (char *)((in_ECX - 2) / 9);
  }
  if (pcVar5 != (char *)0x0) {
    pbVar6 = (byte *)(param_2 + 5);
    local_3c = pcVar5;
    do {
      local_34 = (uint *)FUN_00891268(0x14);
      iVar3 = local_40;
      if (local_34 == (uint *)0x0) {
        local_34 = (uint *)0x0;
      }
      else {
        *local_34 = 0;
        local_34[1] = 0;
        local_34[2] = 0;
        local_34[3] = 0;
        local_34[4] = 0;
      }
      local_34[2] = *(uint *)(pbVar6 + 2);
      local_34[1] = (uint)*pbVar6;
      *local_34 = (uint)pbVar6[1];
      local_34[3] = 1;
      *(byte *)(local_34 + 4) = pbVar6[-1];
      local_38 = *(short *)(pbVar6 + -3);
      if (local_38 == 0xc) {
        local_44 = (char *)0x1;
      }
      uVar1 = FUN_004ca670();
      FUN_004a4df0(iVar3,uVar1);
      pbVar6 = pbVar6 + 9;
      local_3c = local_3c + -1;
    } while (local_3c != (char *)0x0);
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  FUN_0058aad0(0xf4288);
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 1;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  puVar2 = (undefined4 *)FUN_00891268(0x1c);
  puVar4 = (undefined4 *)0x0;
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[3] = 0;
    puVar2[1] = 0xffffffff;
    puVar2[2] = 0xffffffff;
    puVar2[4] = 0xf42a4;
    *puVar2 = FoxUI::FXUIEventI2::vftable;
    puVar2[5] = 1;
    puVar2[6] = 1;
    puVar4 = puVar2;
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_c = 2;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_c = 0xffffffff;
  }
  if (((DAT_00f95c78 + DAT_00f95c7c & 3U) == 0) && (DAT_00f95c74 <= DAT_00f95c7c + 4U >> 2)) {
    FUN_00636f70(&DAT_00f95c6c);
  }
  uVar8 = DAT_00f95c78 + DAT_00f95c7c;
  uVar7 = uVar8 >> 2;
  if (DAT_00f95c74 <= uVar7) {
    uVar7 = uVar7 - DAT_00f95c74;
  }
  if (*(int *)(DAT_00f95c70 + uVar7 * 4) == 0) {
    iVar3 = FUN_00891268(0x10);
    if (iVar3 == 0) {
      local_3c = (char *)0x0;
      std::exception::exception((exception *)local_30,&local_3c);
      local_30[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_30,&DAT_00c857a8);
    }
    *(int *)(DAT_00f95c70 + uVar7 * 4) = iVar3;
  }
  puVar2 = (undefined4 *)(*(int *)(DAT_00f95c70 + uVar7 * 4) + (uVar8 & 3) * 4);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = puVar4;
  }
  DAT_00f95c7c = DAT_00f95c7c + 1;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 3;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  puVar4 = (undefined4 *)FUN_00891268(0x1c);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar4[1] = 0xffffffff;
    puVar4[2] = 0xffffffff;
    puVar4[3] = 0;
    puVar4[4] = 0xf42a4;
    *puVar4 = FoxUI::FXUIEventI2::vftable;
    puVar4[5] = 2;
    puVar4[6] = 1;
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_c = 4;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_c = 0xffffffff;
  }
  if (((DAT_00f95c78 + DAT_00f95c7c & 3U) == 0) && (DAT_00f95c74 <= DAT_00f95c7c + 4U >> 2)) {
    FUN_00636f70(&DAT_00f95c6c);
  }
  uVar8 = DAT_00f95c78 + DAT_00f95c7c;
  uVar7 = uVar8 >> 2;
  if (DAT_00f95c74 <= uVar7) {
    uVar7 = uVar7 - DAT_00f95c74;
  }
  if (*(int *)(DAT_00f95c70 + uVar7 * 4) == 0) {
    iVar3 = FUN_00891268(0x10);
    if (iVar3 == 0) {
      local_3c = (char *)0x0;
      std::exception::exception((exception *)local_30,&local_3c);
      local_30[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_30,&DAT_00c857a8);
    }
    *(int *)(DAT_00f95c70 + uVar7 * 4) = iVar3;
  }
  puVar2 = (undefined4 *)(*(int *)(DAT_00f95c70 + uVar7 * 4) + (uVar8 & 3) * 4);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = puVar4;
  }
  DAT_00f95c7c = DAT_00f95c7c + 1;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 5;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  puVar4 = (undefined4 *)FUN_00891268(0x1c);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar4[1] = 0xffffffff;
    puVar4[2] = 0xffffffff;
    puVar4[3] = 0;
    puVar4[4] = 0xf42a4;
    *puVar4 = FoxUI::FXUIEventI2::vftable;
    puVar4[5] = 3;
    puVar4[6] = 1;
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_c = 6;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_c = 0xffffffff;
  }
  if (((DAT_00f95c78 + DAT_00f95c7c & 3U) == 0) && (DAT_00f95c74 <= DAT_00f95c7c + 4U >> 2)) {
    FUN_00636f70(&DAT_00f95c6c);
  }
  uVar8 = DAT_00f95c78 + DAT_00f95c7c;
  uVar7 = uVar8 >> 2;
  if (DAT_00f95c74 <= uVar7) {
    uVar7 = uVar7 - DAT_00f95c74;
  }
  if (*(int *)(DAT_00f95c70 + uVar7 * 4) == 0) {
    iVar3 = FUN_00891268(0x10);
    if (iVar3 == 0) {
      local_3c = (char *)0x0;
      std::exception::exception((exception *)local_30,&local_3c);
      local_30[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_30,&DAT_00c857a8);
    }
    *(int *)(DAT_00f95c70 + uVar7 * 4) = iVar3;
  }
  puVar2 = (undefined4 *)(*(int *)(DAT_00f95c70 + uVar7 * 4) + (uVar8 & 3) * 4);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = puVar4;
  }
  DAT_00f95c7c = DAT_00f95c7c + 1;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 7;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  puVar4 = (undefined4 *)FUN_00891268(0x1c);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar4[1] = 0xffffffff;
    puVar4[2] = 0xffffffff;
    puVar4[3] = 0;
    puVar4[4] = 0xf42a4;
    *puVar4 = FoxUI::FXUIEventI2::vftable;
    puVar4[5] = 4;
    puVar4[6] = local_44;
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_c = 8;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_c = 0xffffffff;
  }
  if (((DAT_00f95c78 + DAT_00f95c7c & 3U) == 0) && (DAT_00f95c74 <= DAT_00f95c7c + 4U >> 2)) {
    FUN_00636f70(&DAT_00f95c6c);
  }
  uVar8 = DAT_00f95c78 + DAT_00f95c7c;
  uVar7 = uVar8 >> 2;
  if (DAT_00f95c74 <= uVar7) {
    uVar7 = uVar7 - DAT_00f95c74;
  }
  if (*(int *)(DAT_00f95c70 + uVar7 * 4) == 0) {
    iVar3 = FUN_00891268(0x10);
    if (iVar3 == 0) {
      local_3c = (char *)0x0;
      std::exception::exception((exception *)local_30,&local_3c);
      local_30[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_30,&DAT_00c857a8);
    }
    *(int *)(DAT_00f95c70 + uVar7 * 4) = iVar3;
  }
  puVar2 = (undefined4 *)(*(int *)(DAT_00f95c70 + uVar7 * 4) + (uVar8 & 3) * 4);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = puVar4;
  }
  DAT_00f95c7c = DAT_00f95c7c + 1;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 9;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  puVar4 = (undefined4 *)FUN_00891268(0x1c);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar4[1] = 0xffffffff;
    puVar4[2] = 0xffffffff;
    puVar4[3] = 0;
    puVar4[4] = 0xf42a4;
    *puVar4 = FoxUI::FXUIEventI2::vftable;
    puVar4[5] = 5;
    puVar4[6] = local_44;
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_c = 10;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_c = 0xffffffff;
  }
  if (((DAT_00f95c78 + DAT_00f95c7c & 3U) == 0) && (DAT_00f95c74 <= DAT_00f95c7c + 4U >> 2)) {
    FUN_00636f70(&DAT_00f95c6c);
  }
  uVar8 = DAT_00f95c78 + DAT_00f95c7c;
  uVar7 = uVar8 >> 2;
  if (DAT_00f95c74 <= uVar7) {
    uVar7 = uVar7 - DAT_00f95c74;
  }
  if (*(int *)(DAT_00f95c70 + uVar7 * 4) == 0) {
    iVar3 = FUN_00891268(0x10);
    if (iVar3 == 0) {
      local_44 = (char *)0x0;
      std::exception::exception((exception *)local_24,&local_44);
      local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_24,&DAT_00c857a8);
    }
    *(int *)(DAT_00f95c70 + uVar7 * 4) = iVar3;
  }
  puVar2 = (undefined4 *)(*(int *)(DAT_00f95c70 + uVar7 * 4) + (uVar8 & 3) * 4);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = puVar4;
  }
  DAT_00f95c7c = DAT_00f95c7c + 1;
  ExceptionList = local_14;
  return 0;
}

