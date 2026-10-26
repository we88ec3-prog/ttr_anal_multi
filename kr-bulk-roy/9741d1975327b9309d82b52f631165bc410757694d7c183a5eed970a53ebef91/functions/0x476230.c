
void FUN_00476230(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_24;
  int local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00947f6a;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffc8);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if ((DAT_00f9437c - DAT_00f94378 & 0xfffffff8U) != 0) {
    uVar3 = 0;
    do {
      if ((uint)(DAT_00f9437c - DAT_00f94378 >> 3) < uVar3) {
        FUN_005dd480();
      }
      else {
        iVar2 = DAT_00f94378 + uVar3 * 8;
        if ((DAT_00f8d9a4 & 1) == 0) {
          DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
          local_c = 1;
          FUN_0051c120();
          _atexit((_func_4879 *)&LAB_00bccc90);
          local_c = 0xffffffff;
        }
        iVar1 = DAT_00f94378;
        local_24 = *(undefined4 *)(iVar2 + 4);
        FUN_008438c0(&local_24);
        if ((local_20 == DAT_00f8d91c) || (*(int *)(local_20 + 0x10) == 0)) {
          FUN_005dd3c0(0,0,0,0,1);
        }
        else {
          iVar2 = iVar1;
          if ((DAT_00f8d9a4 & 1) == 0) {
            DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
            local_c = 2;
            FUN_0051c120();
            _atexit((_func_4879 *)&LAB_00bccc90);
            local_c = 0xffffffff;
            iVar2 = DAT_00f94378;
          }
          local_24 = *(undefined4 *)(iVar1 + uVar3 * 8 + 4);
          FUN_008438c0(&local_24);
          FUN_005dd3c0(0,0,*(undefined1 *)(iVar2 + 1 + uVar3 * 8),0,1);
        }
      }
      uVar3 = uVar3 + 1;
    } while ((int)uVar3 < 0x14);
  }
  ExceptionList = local_14;
  return;
}

