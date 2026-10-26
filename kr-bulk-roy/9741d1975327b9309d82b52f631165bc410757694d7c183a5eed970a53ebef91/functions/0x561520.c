
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00561520(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093ac7c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fe2740 & 1) == 0) {
    DAT_00fe2740 = DAT_00fe2740 | 1;
    local_c = 0;
    FUN_0055e680(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
    _atexit((_func_4879 *)&DAT_00bcf2a0);
  }
  local_c = 0xffffffff;
  FUN_0055e790();
  if (*(int *)(in_ECX + 0x28) != 0) {
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 1;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
      local_c = 0xffffffff;
    }
    *(undefined4 *)(DAT_00fba7a4 + 0x58) = 1;
    if (*(int *)(in_ECX + 0x2c) == 0) {
      FUN_006f4dd0("f_doCoTask",0,0);
    }
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x1c);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    (**(code **)(*(int *)puVar3[4] + 0x20))();
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
  if ((_DAT_00fe36dc & 1) == 0) {
    _DAT_00fe36dc = _DAT_00fe36dc | 1;
    _DAT_00fe36d4 = 0;
    _DAT_00fe36d8 = 0;
  }
  FUN_00560090(&DAT_00fe36d4);
  ExceptionList = local_14;
  return 0;
}

