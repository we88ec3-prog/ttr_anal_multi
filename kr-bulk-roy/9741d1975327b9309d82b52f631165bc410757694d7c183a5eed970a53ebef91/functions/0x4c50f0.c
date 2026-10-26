
undefined4 FUN_004c50f0(int param_1,uint param_2)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  int in_ECX;
  int local_30;
  undefined4 *local_28 [2];
  uint local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0094796a;
  local_14 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffffc0;
  ExceptionList = &local_14;
  if (*(char *)(param_1 + 2) != '\x03') {
    FUN_006edb60(&DAT_00c07418,uVar4);
    ExceptionList = local_14;
    return 0x80004005;
  }
  local_20 = 0xe;
  if (param_2 < 0xe) {
    FUN_006edb60(&DAT_00bf6cbc,uVar4);
  }
  iVar3 = DAT_00fe1b58;
  *(undefined4 *)(DAT_00fe1b58 + 8) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(param_1 + 8);
  *(undefined2 *)(iVar3 + 0x10) = *(undefined2 *)(param_1 + 0xc);
  if (*(char *)(param_1 + 8) == '\0') {
    FUN_005081e0();
    FUN_004054c0();
    FUN_0058acf0(0xf426b,0,0,(int)*(char *)(param_1 + 3));
    FUN_004ba8c0(0);
    *(undefined4 *)(in_ECX + 0x5eb4) = 1;
  }
  else {
    if (*(char *)(param_1 + 8) != '\x01') {
      ExceptionList = local_14;
      return 0;
    }
    FUN_005081e0();
    local_30 = 0;
    puVar5 = (undefined4 *)(param_1 + 0xe);
    if (*(char *)(param_1 + 10) != '\0') {
      do {
        local_20 = local_20 + 5;
        local_28[0] = puVar5;
        if (param_2 < local_20) {
          FUN_006edb60(&DAT_00bf6cbc,uVar4);
        }
        FUN_004de9c0();
        local_30 = local_30 + 1;
        puVar5 = (undefined4 *)((int)puVar5 + 5);
      } while (local_30 < (int)(uint)*(byte *)(param_1 + 10));
    }
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 0;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
      local_c = 0xffffffff;
    }
    FUN_004ddad0(DAT_00fab130,*(undefined1 *)(param_1 + 9));
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 1;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_c = 0xffffffff;
    }
    puVar5 = (undefined4 *)FUN_00891268(0x20);
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      bVar1 = *(byte *)(param_1 + 9);
      cVar2 = *(char *)(param_1 + 3);
      puVar5[1] = 0xffffffff;
      puVar5[2] = 0xffffffff;
      puVar5[3] = 0;
      puVar5[4] = 0xf426b;
      *puVar5 = FoxUI::FXUIEventI3::vftable;
      puVar5[5] = 1;
      puVar5[6] = (uint)bVar1;
      puVar5[7] = (int)cVar2;
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_c = 2;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_c = 0xffffffff;
    }
    local_28[0] = puVar5;
    FUN_00804260(local_28);
    FUN_004ba8c0(1);
    *(undefined4 *)(in_ECX + 0x5eb4) = 1;
  }
  FUN_006df020();
  ExceptionList = local_14;
  return 0;
}

