
void FUN_00550c10(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  void **ppvVar7;
  uint uVar8;
  int in_ECX;
  int *piVar9;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009230fc;
  uVar8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  puVar2 = *(undefined4 **)(in_ECX + 0x14);
  puVar3 = (undefined4 *)*puVar2;
  ppvVar7 = &local_10;
  local_10 = ExceptionList;
  while (ExceptionList = ppvVar7, puVar3 != puVar2) {
    if ((DAT_00fe1770 & 1) == 0) {
      DAT_00fe1770 = DAT_00fe1770 | 1;
      local_8 = 0;
      FUN_007b7da0(uVar8);
      _atexit((_func_4879 *)&LAB_00bce790);
      local_8 = 0xffffffff;
    }
    FUN_007b8480(&DAT_00fe173c,0);
    ppvVar7 = ExceptionList;
    if (*(char *)((int)puVar3 + 0x15) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x15);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x15);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x15);
        puVar6 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar6, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x15);
          puVar6 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  if ((DAT_00fe1770 & 1) == 0) {
    DAT_00fe1770 = DAT_00fe1770 | 1;
    local_8 = 1;
    FUN_007b7da0(uVar8);
    _atexit((_func_4879 *)&LAB_00bce790);
    local_8 = 0xffffffff;
  }
  iVar5 = DAT_00fe173c;
  piVar9 = (int *)**(int **)(DAT_00fe173c + 4);
  if (piVar9 != *(int **)(DAT_00fe173c + 4)) {
    do {
      if (((int *)piVar9[9])[1] == 0) {
        (**(code **)(*(int *)piVar9[9] + 4))();
      }
      piVar9 = (int *)*piVar9;
    } while (piVar9 != (int *)*(int *)(iVar5 + 4));
  }
  puVar2 = *(undefined4 **)(in_ECX + 4);
  for (puVar3 = (undefined4 *)*puVar2; puVar3 != puVar2; puVar3 = (undefined4 *)*puVar3) {
    FUN_005506b0();
  }
  ExceptionList = local_10;
  return;
}

