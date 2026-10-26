
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00561010(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093acde;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fe2740 & 1) == 0) {
    DAT_00fe2740 = DAT_00fe2740 | 1;
    local_c = 0;
    FUN_0055e680(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    _atexit((_func_4879 *)&DAT_00bcf2a0);
  }
  local_c = 0xffffffff;
  if (DAT_00fe2744 != (int *)0x0) {
    (**(code **)(*DAT_00fe2744 + 8))();
    DAT_00fe2744 = (int *)0x0;
  }
  if ((_DAT_00fe38cc & 1) == 0) {
    _DAT_00fe38cc = _DAT_00fe38cc | 1;
    _DAT_00fe36e4 = 0x400;
    _DAT_00fe36e8 = 0x300;
    _DAT_00fe36ec = 0;
    _atexit((_func_4879 *)&DAT_00bcf2d0);
  }
  if (DAT_00fe36e0 != (int *)0x0) {
    (**(code **)(*DAT_00fe36e0 + 8))();
    DAT_00fe36e0 = (int *)0x0;
  }
  puVar2 = *(undefined4 **)(param_1 + 0x1c);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    (**(code **)(*(int *)puVar3[4] + 0x14))();
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
        puVar5 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x15);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  ExceptionList = local_14;
  return 0;
}

