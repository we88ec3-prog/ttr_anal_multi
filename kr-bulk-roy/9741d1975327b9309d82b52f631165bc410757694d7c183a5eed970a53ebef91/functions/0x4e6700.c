
undefined4 FUN_004e6700(int param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  char *pcVar6;
  undefined4 *puVar7;
  uint uVar8;
  char *local_3c [3];
  undefined1 local_30;
  undefined4 local_2c;
  uint local_28;
  undefined **local_24 [4];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00927636;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffb8;
  ExceptionList = &local_14;
  if ((DAT_00faaf34 & 1) == 0) {
    DAT_00faaf34 = DAT_00faaf34 | 1;
    local_c = 0;
    FUN_004073c0(uVar2);
    _atexit((_func_4879 *)&LAB_00bcccd0);
  }
  local_c = 0xffffffff;
  DAT_00faaf38 = *(undefined1 *)(param_1 + 6);
  DAT_00faaf40 = *(undefined4 *)(param_1 + 2);
  FUN_00844c60();
  if (param_2 < 7) {
    pcVar6 = (char *)0x0;
  }
  else {
    pcVar6 = (char *)((param_2 - 7) / 6);
  }
  if (pcVar6 != (char *)0x0) {
    puVar7 = (undefined4 *)(param_1 + 8);
    local_3c[0] = pcVar6;
    do {
      bVar1 = *(byte *)(puVar7 + 1);
      uVar3 = *puVar7;
      if ((DAT_00faaf34 & 1) == 0) {
        DAT_00faaf34 = DAT_00faaf34 | 1;
        local_c = 1;
        FUN_004073c0(uVar2);
        _atexit((_func_4879 *)&LAB_00bcccd0);
        local_c = 0xffffffff;
      }
      local_30 = *(undefined1 *)((int)puVar7 + -1);
      local_2c = uVar3;
      local_28 = (uint)bVar1;
      uVar3 = FUN_004edd10();
      FUN_004ed630(&DAT_00faaf4c,uVar3);
      puVar7 = (undefined4 *)((int)puVar7 + 6);
      local_3c[0] = local_3c[0] + -1;
    } while (local_3c[0] != (char *)0x0);
    local_3c[0] = (char *)0x0;
  }
  if ((DAT_00faaf34 & 1) == 0) {
    DAT_00faaf34 = DAT_00faaf34 | 1;
    local_c = 2;
    FUN_004073c0(uVar2);
    _atexit((_func_4879 *)&LAB_00bcccd0);
    local_c = 0xffffffff;
  }
  DAT_00faaf45 = 1;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 3;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  puVar4 = (undefined4 *)FUN_00891268(0x14);
  puVar7 = (undefined4 *)0x0;
  if (puVar4 != (undefined4 *)0x0) {
    puVar4[3] = 0;
    *puVar4 = FoxUI::FXUIEvent::vftable;
    puVar4[1] = 0xffffffff;
    puVar4[2] = 0xffffffff;
    puVar4[4] = 0xf4433;
    puVar7 = puVar4;
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
  uVar2 = uVar8 >> 2;
  if (DAT_00f95c74 <= uVar2) {
    uVar2 = uVar2 - DAT_00f95c74;
  }
  if (*(int *)(DAT_00f95c70 + uVar2 * 4) == 0) {
    iVar5 = FUN_00891268(0x10);
    if (iVar5 == 0) {
      local_3c[0] = (char *)0x0;
      std::exception::exception((exception *)local_24,local_3c);
      local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_24,&DAT_00c857a8);
    }
    *(int *)(DAT_00f95c70 + uVar2 * 4) = iVar5;
  }
  puVar4 = (undefined4 *)(*(int *)(DAT_00f95c70 + uVar2 * 4) + (uVar8 & 3) * 4);
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = puVar7;
  }
  DAT_00f95c7c = DAT_00f95c7c + 1;
  ExceptionList = local_14;
  return 0;
}

