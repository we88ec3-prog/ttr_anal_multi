
uint FUN_0062b240(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00928ca8;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fdfb10 & 1) == 0) {
    DAT_00fdfb10 = DAT_00fdfb10 | 1;
    local_8 = 0;
    FUN_00590760(uVar3);
    _atexit((_func_4879 *)&LAB_00bce760);
    if ((DAT_00fdfb10 & 1) == 0) {
      DAT_00fdfb10 = DAT_00fdfb10 | 1;
      local_8 = 1;
      FUN_00590760(uVar3);
      _atexit((_func_4879 *)&LAB_00bce760);
    }
  }
  uVar7 = param_3 >> 0x10 & 0xff;
  local_14 = (undefined4 *)(uVar7 << 0x10 | param_3 & 0xff);
  if ((DAT_00fdfb10 & 1) == 0) {
    DAT_00fdfb10 = DAT_00fdfb10 | 1;
    local_8 = 2;
    FUN_00590760(uVar3);
    _atexit((_func_4879 *)&LAB_00bce760);
    if ((DAT_00fdfb10 & 1) == 0) {
      DAT_00fdfb10 = DAT_00fdfb10 | 1;
      local_8 = 3;
      FUN_00590760(uVar3);
      _atexit((_func_4879 *)&LAB_00bce760);
    }
  }
  puVar8 = *(undefined4 **)param_1[0x41];
  puVar4 = param_1;
  if ((short)(param_3 >> 0x10) == 0x9d) {
    local_14 = (undefined4 *)(param_3 & 0xffff | 0x1d0000);
    puVar4 = local_14;
  }
  do {
    do {
      while( true ) {
        do {
          puVar5 = puVar8;
          if (puVar5 == (undefined4 *)param_1[0x41]) {
            ExceptionList = local_10;
            return (uint)puVar4 & 0xffffff00;
          }
          puVar8 = (undefined4 *)puVar5[0x10];
          puVar4 = (undefined4 *)(puVar5[0x11] - (int)puVar8 >> 2);
          puVar6 = (undefined4 *)0x0;
          if (puVar4 != (undefined4 *)0x0) {
            do {
              if (((undefined4 *)*puVar8 == local_14) ||
                 ((undefined4 *)*puVar8 == (undefined4 *)((param_3 & 0xff) << 0x10 | uVar7))) {
                uVar2 = puVar5[3];
                *param_2 = uVar2;
                ExceptionList = local_10;
                return CONCAT31((int3)((uint)uVar2 >> 8),1);
              }
              puVar6 = (undefined4 *)((int)puVar6 + 1);
              puVar8 = puVar8 + 1;
            } while (puVar6 < puVar4);
          }
          puVar8 = puVar5;
        } while (*(char *)((int)puVar5 + 0x89) != '\0');
        puVar8 = (undefined4 *)puVar5[2];
        if (*(char *)((int)puVar8 + 0x89) != '\0') break;
        cVar1 = *(char *)((int)*puVar8 + 0x89);
        puVar4 = (undefined4 *)*puVar8;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x89);
          puVar8 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      puVar8 = (undefined4 *)puVar5[1];
      puVar4 = puVar8;
    } while (*(char *)((int)puVar8 + 0x89) != '\0');
    do {
      puVar6 = puVar8;
      puVar8 = puVar6;
      puVar4 = puVar6;
      if (puVar5 != (undefined4 *)puVar6[2]) break;
      puVar4 = (undefined4 *)puVar6[1];
      puVar8 = puVar4;
      puVar5 = puVar6;
    } while (*(char *)((int)puVar4 + 0x89) == '\0');
  } while( true );
}

