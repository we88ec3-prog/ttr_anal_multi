
void FUN_005fc820(void)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  undefined4 uVar9;
  int *local_1c [2];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093ebac;
  local_14 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(uVar3);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  iVar8 = 0;
  if (DAT_00f94300 != -0x16f8) {
    iVar8 = *(int *)(DAT_00f94300 + 0x2398);
  }
  iVar2 = (iVar8 % 0x14) / 5;
  uVar6 = 0;
  uVar4 = *(int *)(DAT_00fe1d9c + 0xc) - *(int *)(DAT_00fe1d9c + 8) >> 4;
  if (uVar4 != 0) {
    local_1c[0] = *(int **)(DAT_00fe1d9c + 8);
    piVar7 = local_1c[0];
    while ((*piVar7 != iVar8 / 0x14 + 1 || (piVar7[1] != iVar2 + 1))) {
      uVar6 = uVar6 + 1;
      piVar7 = piVar7 + 4;
      if (uVar4 <= uVar6) {
        ExceptionList = local_14;
        return;
      }
    }
    piVar7 = local_1c[0] + uVar6 * 4;
    if (piVar7 != (int *)0x0) {
      if ((DAT_00f94390 & 1) == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        local_c = 1;
        FUN_004e1590(uVar3);
        _atexit((_func_4879 *)&LAB_00bccc80);
      }
      local_c = 0xffffffff;
      if (DAT_00f94244 < piVar7[3]) {
        local_1c[0] = (int *)0xc;
        iVar8 = FUN_005854b0();
        FUN_005740f0(local_1c);
        if (iVar2 + 1 != *(int *)(iVar8 + 4)) {
          puVar5 = (undefined4 *)(iVar2 + 0x11);
          if (7 < *(uint *)(iVar2 + 0x25)) {
            puVar5 = (undefined4 *)*puVar5;
          }
          FUN_00404b10(0xca,puVar5,&DAT_00bed1fc,0,0);
          ExceptionList = local_14;
          return;
        }
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      if (99 < iVar8) {
        uVar9 = 0xe;
        FUN_005854b0(0xe,&DAT_00bed1fc,0,0);
        uVar9 = FUN_00585330(uVar9);
        FUN_00404b10(0xca,uVar9);
        ExceptionList = local_14;
        return;
      }
      FUN_00414680();
      FUN_004a36a0();
    }
  }
  ExceptionList = local_14;
  return;
}

