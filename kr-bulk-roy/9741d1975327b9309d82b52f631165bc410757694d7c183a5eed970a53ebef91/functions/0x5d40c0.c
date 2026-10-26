
void FUN_005d40c0(int param_1)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_44 [4];
  int iStack_40;
  undefined4 uStack_3c;
  uint uStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009436f4;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_44;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffffb0);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  iStack_40 = (**(code **)(*DAT_00fba7a4 + 0x20))();
  if (iStack_40 != 0) {
    uVar1 = *(ushort *)(iStack_40 + 0x88);
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_c = 1;
      FUN_005c3de0();
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_c = 0xffffffff;
    }
    uStack_3c = (&DAT_00f943f0)[uVar1];
    iVar2 = *(int *)(param_1 + 0x80);
    if ((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) {
      iVar2 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))();
      if (iVar2 == 0xbf6b) {
        FUN_0077b200();
      }
    }
    uVar3 = FUN_0040ef80();
    local_c = 2;
    FUN_00757800(uVar3);
    local_c = 0xffffffff;
    if (7 < uStack_24) {
      FUN_0089120c(uStack_38);
    }
    uStack_38 = uStack_38 & 0xffff0000;
    uStack_24 = 7;
    uStack_28 = 0;
    (**(code **)(**(int **)(param_1 + 0x80) + 200))();
    (**(code **)(**(int **)(param_1 + 0x88) + 200))();
    FUN_005d3fa0(param_1);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_44);
  return;
}

