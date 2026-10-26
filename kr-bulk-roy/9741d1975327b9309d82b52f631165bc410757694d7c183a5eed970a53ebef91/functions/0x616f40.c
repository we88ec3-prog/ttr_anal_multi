
void FUN_00616f40(int param_1,uint param_2,uint param_3,int param_4)

{
  undefined4 *puVar1;
  code *pcVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iStack_28;
  undefined4 *apuStack_24 [2];
  void *pvStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0093e126;
  local_14 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffffc8;
  ExceptionList = &local_14;
  cVar3 = (char)param_3;
  *(char *)(param_1 + 0x261) = cVar3;
  *(char *)(param_1 + 0x260) = (char)param_2;
  (**(code **)(**(int **)(param_1 + 0x248) + 0x19c))(param_2,param_3,uVar4);
  if ((DAT_00fab230 & 1) == 0) {
    DAT_00fab230 = DAT_00fab230 | 1;
    local_14 = (void *)0x0;
    FUN_005292c0();
    _atexit(FUN_00bcce40);
    local_14 = (void *)0xffffffff;
  }
  uVar4 = param_2 & 0xff;
  iStack_28 = uVar4 * 10000 + (param_3 & 0xff);
  FUN_00529250(&iStack_28);
  if ((apuStack_24[0] != DAT_00fab238) && (apuStack_24[0] != (undefined4 *)0xfffffff0)) {
    FUN_00757800(apuStack_24[0] + 5);
    (**(code **)(**(int **)(param_1 + 0x24c) + 200))();
  }
  if ((DAT_00fab278 & 1) == 0) {
    DAT_00fab278 = DAT_00fab278 | 1;
    local_14 = (void *)0x1;
    FUN_00817da0();
    _atexit((_func_4879 *)&LAB_00bcced0);
    local_14 = (void *)0xffffffff;
  }
  apuStack_24[0] = (undefined4 *)(param_2 & 0xff);
  FUN_008195e0(apuStack_24);
  iVar5 = iStack_28;
  if (iStack_28 != DAT_00fab280) {
    FUN_008196d0();
    puVar1 = *(undefined4 **)(iVar5 + 0x14);
    if (puVar1 == apuStack_24[0]) {
      if ((cVar3 != '\0') || (*(int *)(iVar5 + 0x18) == 0)) goto LAB_0061718a;
      apuStack_24[0] = (undefined4 *)*puVar1;
    }
    apuStack_24[0] = (undefined4 *)apuStack_24[0][4];
    if (apuStack_24[0] != (undefined4 *)0x0) {
      iVar5 = *(int *)(*(int *)(param_1 + 0x25c) + 0xcc);
      uVar7 = (int)(apuStack_24[0][0x1b] - apuStack_24[0][0x1a]) >> 3;
      if (iVar5 != 0) {
        FUN_00408920(iVar5,uVar7);
      }
      uVar6 = 0;
      if (uVar7 != 0) {
        do {
          iVar5 = *(int *)(*(int *)(param_1 + 0x25c) + 0xcc);
          if (((iVar5 == 0) || ((int)uVar6 < 0)) ||
             (*(int *)(iVar5 + 0xac) - *(int *)(iVar5 + 0xa8) >> 2 <= (int)uVar6)) {
            iVar5 = 0;
          }
          else {
            iVar5 = *(int *)(*(int *)(iVar5 + 0xa8) + uVar6 * 4);
          }
          puVar1 = (undefined4 *)(apuStack_24[0][0x1a] + uVar6 * 8);
          if ((iVar5 != 0) && (puVar1 != (undefined4 *)0x0)) {
            iStack_28 = CONCAT31(iStack_28._1_3_,*(undefined1 *)(puVar1 + 1));
            (**(code **)(**(int **)(iVar5 + 0x248) + 0x19c))(*puVar1,iStack_28,2);
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < uVar7);
      }
      FUN_00749920(*(undefined4 *)(param_1 + 0x25c));
      (**(code **)(**(int **)(param_1 + 0x25c) + 200))();
    }
  }
LAB_0061718a:
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_14 = (void *)0x2;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_14 = (void *)0xffffffff;
  }
  if (((-1 < (int)uVar4) && (uVar4 < 10)) &&
     ((iVar5 = uVar4 * 0x210 + DAT_00f94304, *(int *)(uVar4 * 0x210 + 0x5c + DAT_00f94304) != 0 &&
      ((iVar5 != 0 && ((char *)(iVar5 + 500) != (char *)0x0)))))) {
    if ((*(char *)(iVar5 + 500) == cVar3) || ((param_4 != 0 && (*(char *)(iVar5 + 0x1f5) == cVar3)))
       ) {
      uVar4 = DAT_00fe5ae4 & 1;
      *(undefined4 *)(*(int *)(param_1 + 0x250) + 0x154) = 0xff00ff00;
      if (uVar4 == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        local_14 = (void *)0x3;
        FUN_00584c40(&DAT_00fe5ac4);
        _atexit((_func_4879 *)&LAB_00bcf390);
        local_14 = (void *)0xffffffff;
      }
      apuStack_24[0] = (undefined4 *)0x2c9;
      FUN_005740f0(apuStack_24);
      if (iStack_28 == DAT_00fe5ac8) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      FUN_00757710();
      (**(code **)(**(int **)(param_1 + 0x254) + 0x94))(1);
    }
    else {
      uVar4 = DAT_00fe5ae4 & 1;
      *(undefined4 *)(*(int *)(param_1 + 0x250) + 0x154) = 0xffffffff;
      if (uVar4 == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        local_14 = (void *)0x4;
        FUN_00584c40(&DAT_00fe5ac4);
        _atexit((_func_4879 *)&LAB_00bcf390);
        local_14 = (void *)0xffffffff;
      }
      apuStack_24[0] = (undefined4 *)0x2c8;
      FUN_005740f0(apuStack_24);
      if (iStack_28 == DAT_00fe5ac8) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      FUN_00757710();
      (**(code **)(**(int **)(param_1 + 0x254) + 0x94))(0);
    }
    (**(code **)(**(int **)(param_1 + 0x250) + 200))();
  }
  ExceptionList = pvStack_1c;
  return;
}

