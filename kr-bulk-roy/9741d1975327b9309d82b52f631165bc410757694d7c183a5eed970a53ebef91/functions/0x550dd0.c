
void FUN_00550dd0(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  void **ppvVar5;
  undefined4 *puVar6;
  uint uVar7;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091b31e;
  uVar7 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  puVar2 = *(undefined4 **)(param_1 + 0x14);
  puVar3 = (undefined4 *)*puVar2;
  ppvVar5 = &local_10;
  local_10 = ExceptionList;
  while (ExceptionList = ppvVar5, puVar3 != puVar2) {
    if ((DAT_00fe1770 & 1) == 0) {
      DAT_00fe1770 = DAT_00fe1770 | 1;
      local_8 = 0;
      FUN_007b7da0(uVar7);
      _atexit((_func_4879 *)&LAB_00bce790);
      local_8 = 0xffffffff;
    }
    FUN_007b8090();
    ppvVar5 = ExceptionList;
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
  ExceptionList = local_10;
  return;
}

