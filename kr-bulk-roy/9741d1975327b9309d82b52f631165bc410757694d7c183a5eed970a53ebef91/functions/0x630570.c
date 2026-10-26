
int FUN_00630570(void)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  ushort *puVar4;
  int local_1c;
  uint local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094682c;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = 0;
  puVar4 = &DAT_00fb1170;
  do {
    if ((DAT_00fab29c & 1) == 0) {
      DAT_00fab29c = DAT_00fab29c | 1;
      local_8 = 0;
      FUN_004ffe60(uVar3);
      _atexit((_func_4879 *)&LAB_00bccf00);
      local_8 = 0xffffffff;
    }
    uVar1 = *puVar4;
    if (uVar1 != 0) {
      if ((DAT_00fab29c & 1) == 0) {
        DAT_00fab29c = DAT_00fab29c | 1;
        local_8 = 1;
        FUN_004ffe60(uVar3);
        _atexit((_func_4879 *)&LAB_00bccf00);
        local_8 = 0xffffffff;
      }
      iVar2 = DAT_00fb114c;
      local_18 = (uint)uVar1;
      FUN_00503d20(&local_18);
      if (((local_1c != *(int *)(iVar2 + 4)) && (local_1c != -0x10)) &&
         (*(int *)(local_1c + 0x14) == 1)) {
        local_14 = local_14 + 1;
      }
    }
    puVar4 = puVar4 + 1;
  } while ((int)puVar4 < 0xfb1198);
  ExceptionList = local_10;
  return local_14;
}

