
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ce830(int param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined **ppuVar6;
  undefined **ppuVar7;
  undefined4 uVar8;
  undefined **appuStack_3c [5];
  void *pvStack_28;
  undefined4 uStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0094387a;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffb8;
  ExceptionList = &local_14;
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_c = 0;
    FUN_00539c20(uVar1);
    _atexit((_func_4879 *)&LAB_00bccfb0);
  }
  local_c = 0xffffffff;
  if ((DAT_00fb7258 == 0) || (1 < *(uint *)(DAT_00fb7258 + 0x20))) {
    (**(code **)(**(int **)(param_1 + 0x300) + 0x94))(0);
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x300) + 0x94))(1);
  }
  (**(code **)(**(int **)(param_1 + 0x2fc) + 0x94))(0);
  iVar2 = FUN_004adcd0();
  appuStack_3c[0] = *(undefined ***)(iVar2 + 0x10);
  ppuVar6 = (undefined **)0x0;
  if (appuStack_3c[0] != (undefined **)0x0) {
    do {
      ppuVar7 = ppuVar6;
      FUN_00542210(ppuVar6);
      piVar3 = (int *)FUN_0050b4b0(ppuVar7);
      if ((int *)*piVar3 == (int *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)*piVar3;
      }
      uVar4 = (uint)piVar3[2] >> 2;
      if (*(uint *)(iVar2 + 8) <= uVar4) {
        uVar4 = uVar4 - *(uint *)(iVar2 + 8);
      }
    } while ((*(char *)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + uVar4 * 4) + (piVar3[2] & 3U) * 4) +
                       0x24) != '\0') &&
            (ppuVar6 = (undefined **)((int)ppuVar6 + 1), ppuVar6 < appuStack_3c[0]));
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_14 = (void *)0x1;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_14 = (void *)0xffffffff;
  }
  if ((DAT_00f94300 == -0x50c0) || (*(int *)(DAT_00f94300 + 0x50d0) == 0)) {
    uVar8 = 0;
  }
  else {
    uVar8 = 1;
  }
  (**(code **)(**(int **)(param_1 + 0x108) + 0x98))(uVar8);
  if ((DAT_00fe18a0 & 1) == 0) {
    DAT_00fe18a0 = DAT_00fe18a0 | 1;
    uStack_18 = 2;
    DAT_00fe18a4 = (undefined4 *)0x0;
    puVar5 = (undefined4 *)FUN_00891268(8);
    if (puVar5 == (undefined4 *)0x0) {
      std::exception::exception((exception *)appuStack_3c,(char **)&stack0xffffffc0);
      appuStack_3c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(appuStack_3c,&DAT_00c857a8);
    }
    DAT_00fe18a4 = puVar5;
    *puVar5 = 0;
    puVar5[1] = 0;
    *DAT_00fe18a4 = &DAT_00fe18a4;
    _DAT_00fe18a8 = 0;
    _DAT_00fe18ac = 0;
    _DAT_00fe18b0 = 0;
    _DAT_00fe18b4 = 0;
    _DAT_00fe18bc = 1;
    DAT_00fe18be = 0;
    _DAT_00fe18c0 = 0;
    _atexit((_func_4879 *)&LAB_00bce8c0);
    uStack_18 = 0xffffffff;
  }
  (**(code **)(**(int **)(param_1 + 0x2f8) + 0x94))(DAT_00fe18bd);
  (**(code **)(**(int **)(param_1 + 0xfc) + 0x98))(uVar1);
  ExceptionList = pvStack_28;
  return;
}

