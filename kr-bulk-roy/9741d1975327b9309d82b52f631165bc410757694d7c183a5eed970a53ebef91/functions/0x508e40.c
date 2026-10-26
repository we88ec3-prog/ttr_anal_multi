
int FUN_00508e40(uint param_1)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  uint *puVar5;
  int local_2c;
  int local_28;
  uint local_24;
  int local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0094008c;
  local_14 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffffc8;
  ExceptionList = &local_14;
  local_2c = 0;
  puVar5 = (uint *)(in_ECX + 0x2c);
  local_28 = 100;
  do {
    if (puVar5[-2] == param_1) {
      uVar2 = *puVar5;
      if ((DAT_00f8d9a4 & 1) == 0) {
        DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
        local_c = 0;
        FUN_0051c120(uVar4);
        _atexit((_func_4879 *)&LAB_00bccc90);
        local_c = 0xffffffff;
      }
      local_24 = uVar2;
      FUN_008438c0(&local_24);
      if ((local_20 != DAT_00f8d91c) && (*(int *)(local_20 + 0x10) != 0)) {
        iVar3 = *(int *)(*(int *)(local_20 + 0x10) + 0x68);
        if (iVar3 != 0) {
          uVar1 = *(ushort *)(iVar3 + 8);
          if ((DAT_00f94390 & 1) == 0) {
            DAT_00f94390 = DAT_00f94390 | 1;
            local_c = 1;
            FUN_004e1590();
            _atexit((_func_4879 *)&LAB_00bccc80);
            local_c = 0xffffffff;
          }
          iVar3 = DAT_00f94308;
          local_24 = (uint)uVar1;
          FUN_004a4cc0(&local_24);
          if (((local_1c == *(int *)(iVar3 + 0x14)) || (*(int *)(local_1c + 0x10) == 0)) ||
             (*(int *)(*(int *)(local_1c + 0x10) + 0xc) == 0)) goto LAB_00508f5d;
        }
        local_2c = local_2c + puVar5[-1];
      }
    }
LAB_00508f5d:
    puVar5 = puVar5 + 8;
    local_28 = local_28 + -1;
    if (local_28 == 0) {
      ExceptionList = local_14;
      return local_2c;
    }
  } while( true );
}

