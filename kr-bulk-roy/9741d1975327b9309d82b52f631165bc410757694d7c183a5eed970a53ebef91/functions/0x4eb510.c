
undefined4 FUN_004eb510(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  undefined4 *puVar4;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00929abc;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  if (param_2 < 3) {
    local_1c = 0;
  }
  else {
    local_1c = (param_2 - 3) / 6;
  }
  if (local_1c != 0) {
    puVar4 = (undefined4 *)(param_1 + 3);
    do {
      iVar2 = FUN_004ec270(1);
      if ((DAT_00fb75b0 & 1) == 0) {
        DAT_00fb75b0 = DAT_00fb75b0 | 1;
        local_c = 0;
        FUN_004f3d80();
        _atexit((_func_4879 *)&LAB_00bcd1e0);
        local_c = 0xffffffff;
      }
      FUN_004f6a30(*puVar4);
      *(undefined2 *)(iVar2 + 0x14) = *(undefined2 *)(puVar4 + 1);
      *(bool *)(iVar2 + 0x12) = *(int *)(iVar2 + 4) == *(int *)(in_ECX + 0x5ec8);
      iVar3 = FUN_00404ba0();
      if (*(int *)(iVar2 + 4) == *(int *)(iVar3 + 0x5f50)) {
        *(int *)(in_ECX + 0x5ebc) = iVar2;
      }
      puVar4 = (undefined4 *)((int)puVar4 + 6);
      local_1c = local_1c - 1;
    } while (local_1c != 0);
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 1;
    FUN_00587480(uVar1);
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  FUN_0058aad0(0xf4259);
  ExceptionList = local_14;
  return 0;
}

