
uint FUN_00627610(int param_1,undefined4 *param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint *puVar12;
  short local_1c;
  uint local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00928dd8;
  local_10 = ExceptionList;
  uVar7 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = (int *)(param_1 + 0x10c);
  local_18 = 0;
  do {
    iVar2 = *local_14;
    if ((DAT_00fdfb10 & 1) == 0) {
      DAT_00fdfb10 = DAT_00fdfb10 | 1;
      local_8 = 0;
      FUN_00590760(uVar7);
      _atexit((_func_4879 *)&LAB_00bce760);
      if ((DAT_00fdfb10 & 1) == 0) {
        DAT_00fdfb10 = DAT_00fdfb10 | 1;
        local_8 = 1;
        FUN_00590760(uVar7);
        _atexit((_func_4879 *)&LAB_00bce760);
      }
    }
    uVar11 = param_3 >> 0x10 & 0xff;
    uVar10 = uVar11 << 0x10 | param_3 & 0xff;
    if ((DAT_00fdfb10 & 1) == 0) {
      DAT_00fdfb10 = DAT_00fdfb10 | 1;
      local_8 = 2;
      FUN_00590760(uVar7);
      _atexit((_func_4879 *)&LAB_00bce760);
      if ((DAT_00fdfb10 & 1) == 0) {
        DAT_00fdfb10 = DAT_00fdfb10 | 1;
        local_8 = 3;
        FUN_00590760(uVar7);
        _atexit((_func_4879 *)&LAB_00bce760);
      }
    }
    puVar3 = (undefined4 *)**(undefined4 **)(iVar2 + 0x104);
    local_1c = (short)(param_3 >> 0x10);
    if (local_1c == 0x9d) {
      uVar10 = param_3 & 0xffff | 0x1d0000;
    }
    while (puVar3 != *(undefined4 **)(iVar2 + 0x104)) {
      puVar12 = (uint *)puVar3[0x10];
      uVar8 = puVar3[0x11] - (int)puVar12 >> 2;
      uVar9 = 0;
      if (uVar8 != 0) {
        do {
          if ((*puVar12 == uVar10) || (*puVar12 == ((param_3 & 0xff) << 0x10 | uVar11))) {
            uVar5 = puVar3[3];
            *param_2 = uVar5;
            ExceptionList = local_10;
            return CONCAT31((int3)((uint)uVar5 >> 8),1);
          }
          uVar9 = uVar9 + 1;
          puVar12 = puVar12 + 1;
        } while (uVar9 < uVar8);
      }
      if (*(char *)((int)puVar3 + 0x89) == '\0') {
        puVar4 = (undefined4 *)puVar3[2];
        if (*(char *)((int)puVar4 + 0x89) == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x89);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar4 + 0x89);
            puVar3 = puVar4;
            puVar4 = (undefined4 *)*puVar4;
          }
        }
        else {
          cVar1 = *(char *)((int)puVar3[1] + 0x89);
          puVar6 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
          while ((puVar3 = puVar6, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
            cVar1 = *(char *)((int)puVar3[1] + 0x89);
            puVar6 = (undefined4 *)puVar3[1];
            puVar4 = puVar3;
          }
        }
      }
    }
    local_14 = local_14 + 1;
    local_18 = local_18 + 1;
    if (2 < (int)local_18) {
      ExceptionList = local_10;
      return local_18 & 0xffffff00;
    }
  } while( true );
}

