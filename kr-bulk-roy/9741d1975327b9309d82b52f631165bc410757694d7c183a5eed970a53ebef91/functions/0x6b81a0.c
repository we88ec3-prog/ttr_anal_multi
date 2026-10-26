
void FUN_006b81a0(int param_1)

{
  ushort uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uStack_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093bffc;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  iVar2 = (**(code **)(*DAT_00fba7a4 + 0x20))();
  if (iVar2 != 0) {
    uVar1 = *(ushort *)(iVar2 + 0x88);
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 1;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c = 0xffffffff;
    }
    iVar2 = 0;
    uStack_20 = uStack_20 & 0xffffff00;
    puVar3 = (undefined4 *)(param_1 + 0x80);
    do {
      if ((int)*(char *)((int)&DAT_00f94220 + iVar2) == (uint)uVar1) {
        uStack_20 = CONCAT31(uStack_20._1_3_,1);
      }
      (**(code **)(*(int *)*puVar3 + 0x90))(uStack_20);
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar2 < 3);
  }
  ExceptionList = local_14;
  return;
}

