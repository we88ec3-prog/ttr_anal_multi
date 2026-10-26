
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_006891e0(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0094713e;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  if ((_DAT_00fc16fc & 1) == 0) {
    _DAT_00fc16fc = _DAT_00fc16fc | 1;
    DAT_00fc1700 = 0;
    DAT_00fc1704 = 0;
    _DAT_00fc1708 = 0;
    _atexit((_func_4879 *)&LAB_00bce4c0);
  }
  uVar4 = DAT_00fc1704 - DAT_00fc1700 >> 2;
  uVar3 = 0;
  *(undefined4 *)(param_1 + 0x174) = 0;
  if (uVar4 != 0) {
    do {
      if ((_DAT_00fc16fc & 1) == 0) {
        _DAT_00fc16fc = _DAT_00fc16fc | 1;
        DAT_00fc1700 = 0;
        DAT_00fc1704 = 0;
        _DAT_00fc1708 = 0;
        _atexit((_func_4879 *)&LAB_00bce4c0);
      }
      if ((uVar3 < (uint)(DAT_00fc1704 - DAT_00fc1700 >> 2)) &&
         (0 < *(int *)(DAT_00fc1700 + uVar3 * 4))) {
        if ((DAT_00f94390 & 1) == 0) {
          DAT_00f94390 = DAT_00f94390 | 1;
          local_c = 0;
          FUN_004e1590(uVar1);
          _atexit((_func_4879 *)&LAB_00bccc80);
          local_c = 0xffffffff;
        }
        iVar2 = 0;
        if (DAT_00f94300 != -0x16f8) {
          iVar2 = FUN_005090e0();
        }
        *(int *)(param_1 + 0x174) = *(int *)(param_1 + 0x174) + iVar2;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar4);
  }
  ExceptionList = local_14;
  return 0 < *(int *)(param_1 + 0x174);
}

