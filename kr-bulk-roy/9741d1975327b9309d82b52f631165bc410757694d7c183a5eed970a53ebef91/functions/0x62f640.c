
void FUN_0062f640(int param_1)

{
  ushort uVar1;
  void *_Dst;
  int iVar2;
  uint uVar3;
  ushort *puVar4;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094695c;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  _Dst = *(void **)(param_1 + 0x114);
  if (_Dst != *(void **)(param_1 + 0x118)) {
    FID_conflict__memcpy(_Dst,*(void **)(param_1 + 0x118),0);
    *(void **)(param_1 + 0x118) = _Dst;
  }
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
      local_14 = (uint)uVar1;
      FUN_00503d20(&local_14);
      if (local_18 == *(int *)(iVar2 + 4)) {
        local_14 = 0;
      }
      else {
        local_14 = local_18 + 0x10;
      }
      if ((local_14 != 0) && (*(int *)(local_14 + 4) == 1)) {
        FUN_00443d10();
      }
    }
    puVar4 = puVar4 + 1;
  } while ((int)puVar4 < 0xfb1198);
  FUN_0062fa90();
  ExceptionList = local_10;
  return;
}

