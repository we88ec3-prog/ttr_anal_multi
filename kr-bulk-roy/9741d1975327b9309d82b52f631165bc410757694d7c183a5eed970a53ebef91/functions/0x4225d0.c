
undefined4 FUN_004225d0(int param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined4 *puVar5;
  uint uVar6;
  int local_30;
  undefined4 *local_2c;
  int local_28;
  uint local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0094589a;
  local_14 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffc0;
  ExceptionList = &local_14;
  if (*(char *)(param_1 + 2) == '\a') {
    local_28 = in_ECX;
    if (param_2 < 0x12) {
      FUN_006edb60(&DAT_00bf6cbc,uVar3);
    }
    iVar2 = DAT_00fb7348;
    uVar6 = DAT_00f94390 & 1;
    *(undefined4 *)(DAT_00fb7348 + 8) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(param_1 + 0xc);
    *(undefined2 *)(iVar2 + 0x14) = *(undefined2 *)(param_1 + 0x10);
    if (uVar6 == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c = 0xffffffff;
    }
    DAT_00f942d9 = *(undefined1 *)(param_1 + 0xc);
    local_30 = 0;
    puVar5 = (undefined4 *)(param_1 + 0x12);
    uVar6 = 0x12;
    if (*(char *)(param_1 + 0x11) != '\0') {
      do {
        local_20 = uVar6 + 5;
        local_2c = puVar5;
        if (param_2 < local_20) {
          FUN_006edb60(&DAT_00bf6cbc,uVar3);
        }
        FUN_004de9c0();
        local_30 = local_30 + 1;
        puVar5 = (undefined4 *)((int)puVar5 + 5);
        uVar6 = local_20;
      } while (local_30 < (int)(uint)*(byte *)(param_1 + 0x11));
    }
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 1;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_c = 0xffffffff;
    }
    puVar4 = (undefined4 *)FUN_00891268(0x20);
    puVar5 = (undefined4 *)0x0;
    if (puVar4 != (undefined4 *)0x0) {
      cVar1 = *(char *)(param_1 + 3);
      puVar4[3] = 0;
      puVar4[6] = 0;
      puVar4[1] = 0xffffffff;
      puVar4[2] = 0xffffffff;
      puVar4[4] = 0xf426b;
      *puVar4 = FoxUI::FXUIEventI3::vftable;
      puVar4[5] = 1;
      puVar4[7] = (int)cVar1;
      puVar5 = puVar4;
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_c = 2;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_c = 0xffffffff;
    }
    local_2c = puVar5;
    FUN_00804260(&local_2c);
    FUN_004ba8c0(*(undefined4 *)(param_1 + 0xd));
    *(undefined4 *)(local_28 + 0x5eb4) = 1;
    ExceptionList = local_14;
    return 0;
  }
  FUN_006edb60(&DAT_00bf6c88,uVar3);
  ExceptionList = local_14;
  return 0x80004005;
}

