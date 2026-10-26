
void FUN_0044a070(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 **ppuVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint local_30;
  undefined4 *local_28;
  undefined4 *local_24;
  undefined4 *local_20;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  puStack_10 = &LAB_00947fd6;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffc0;
  ExceptionList = &local_14;
  puVar6 = (undefined4 *)0x0;
  local_28 = (undefined4 *)0x0;
  local_24 = (undefined4 *)0x0;
  local_20 = (undefined4 *)0x0;
  local_c = 0;
  if ((*(uint *)(*(int *)(param_1 + 0xec) + 0x28) >> 9 & 1) == 0) {
    ppuVar5 = (undefined4 **)(param_1 + 0x118);
  }
  else {
    local_30 = 0;
    if (*(int *)(param_1 + 0x10c) - *(int *)(param_1 + 0x108) >> 2 != 0) {
      do {
        if ((DAT_00f94390 & 1) == 0) {
          DAT_00f94390 = DAT_00f94390 | 1;
          local_c._0_1_ = 1;
          FUN_004e1590(uVar2);
          _atexit((_func_4879 *)&LAB_00bccc80);
          local_c = (uint)local_c._1_3_ << 8;
        }
        iVar1 = local_30 * 4;
        uVar3 = FUN_00445330(*(undefined4 *)(*(int *)(param_1 + 0x108) + iVar1));
        iVar4 = FUN_004d43d0();
        if ((int)(uVar3 & 0xff) <= iVar4) {
          if (*(char *)(*(int *)(*(int *)(param_1 + 0x118) + iVar1) + 9) == '\0') {
            FUN_00443d10();
            puVar6 = local_24;
          }
          else {
            iVar4 = *(int *)(param_1 + 0x108);
            puVar7 = puVar6;
            if (puVar6 == local_20) {
              FUN_004deab0();
              puVar7 = local_24;
            }
            if (puVar7 != (undefined4 *)0x0) {
              *puVar7 = *(undefined4 *)(iVar4 + iVar1);
            }
            puVar6 = puVar7 + 1;
            local_24 = puVar6;
            if ((local_28 != puVar7) && (puVar7 != puVar6)) {
              FUN_00474630(local_28,puVar6);
            }
          }
        }
        local_30 = local_30 + 1;
      } while (local_30 < (uint)(*(int *)(param_1 + 0x10c) - *(int *)(param_1 + 0x108) >> 2));
    }
    ppuVar5 = &local_28;
  }
  FUN_004738a0(ppuVar5);
  FUN_00449b90(param_1);
  if (local_28 != (undefined4 *)0x0) {
    FUN_0089120c(local_28);
  }
  ExceptionList = local_14;
  return;
}

