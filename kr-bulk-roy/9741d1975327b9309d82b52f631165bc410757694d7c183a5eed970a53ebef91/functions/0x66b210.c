
void FUN_0066b210(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 auStack_7c [20];
  undefined4 uStack_68;
  undefined2 *puStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  int iStack_48;
  int *piStack_44;
  int local_28;
  undefined1 *local_24;
  undefined4 local_20;
  undefined1 *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093cfe6;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (*(int *)(param_2 + 0x14) == 0xf43a5) {
    local_1c = *(undefined1 **)(param_2 + 0x18);
    iVar2 = *(int *)(param_2 + 0x1c);
    iVar4 = *(int *)(iVar2 + 4);
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590();
      piStack_44 = (int *)0x66b280;
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    local_c = 0xffffffff;
    if ((iVar4 == 1) && (iVar4 = DAT_00f94300 + 0x16f8, iVar4 != 0)) {
      if (99 < *(int *)(iVar2 + 8) - 1U) {
        piStack_44 = (int *)0x66b3a1;
        FUN_006edb60();
        ExceptionList = local_14;
        return;
      }
      iVar3 = *(int *)(iVar2 + 8) * 0x20;
      iVar1 = iVar3 + iVar4;
      if (((*(int *)(iVar3 + 0xc + iVar4) != 0) && (*(int *)(iVar1 + 8) != 0)) && (iVar1 != 0)) {
        local_24 = *(undefined1 **)(iVar1 + 0x10);
        local_20 = *(undefined4 *)(iVar1 + 0x14);
        iVar4 = FUN_00409560();
        piStack_44 = &local_28;
        uStack_4c = 0x66b305;
        iStack_48 = iVar4;
        FUN_004dd400();
        if (((local_28 != *(int *)(iVar4 + 4)) && (*(int *)(local_28 + 0x18) != 0)) &&
           (*(char *)(*(int *)(local_28 + 0x18) + 0x15) != '\0')) {
          FUN_004054c0();
          piStack_44 = (int *)0x0;
          local_1c = (undefined1 *)&uStack_60;
          puStack_64 = &DAT_00bed1fc;
          uStack_68 = 0x66b345;
          FUN_00402250();
          puStack_64 = (undefined2 *)0xaf;
          local_c = 1;
          uStack_68 = 0x66b357;
          FUN_005854b0();
          uStack_68 = 0x66b35e;
          uVar5 = FUN_00585330();
          local_24 = auStack_7c;
          FUN_00402250(uVar5);
          local_c = 0xffffffff;
          FUN_0058b270(0xca);
          ExceptionList = local_14;
          return;
        }
        local_28 = *(int *)(iVar1 + 0xc);
        iVar4 = FUN_00404c10();
        piStack_44 = (int *)0x66b3df;
        FUN_008438c0();
        if ((local_24 != (undefined1 *)*(int *)(iVar4 + 4)) && (*(int *)((int)local_24 + 0x10) != 0)
           ) {
          iVar4 = FUN_0051bfc0();
          if (iVar4 == 0) {
            piStack_44 = *(int **)(iVar1 + 0x14);
            iStack_48 = *(undefined4 *)(iVar1 + 0x10);
            uStack_4c = *(undefined4 *)(iVar1 + 4);
            uStack_50 = *(undefined4 *)(iVar1 + 0xc);
            uStack_54 = *(undefined4 *)(iVar2 + 8);
            uStack_58 = *(undefined4 *)(iVar2 + 4);
            uStack_5c = *(undefined4 *)(iVar2 + 0xc);
            uStack_60 = param_1;
            puStack_64 = (undefined2 *)0x66b422;
            FUN_0066ab60();
          }
        }
      }
    }
  }
  ExceptionList = local_14;
  return;
}

