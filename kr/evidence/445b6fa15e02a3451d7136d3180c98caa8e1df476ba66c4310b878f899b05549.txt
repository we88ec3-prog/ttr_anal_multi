
undefined4 FUN_004e2e70(int param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 **ppuVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint local_2c;
  int local_28;
  uint local_24;
  undefined4 *local_20;
  undefined4 *local_1c [2];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0091758e;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffc8;
  ExceptionList = &local_14;
  local_24 = 0;
  if (*(int *)(param_1 + 0x6900) - *(int *)(param_1 + 0x68fc) >> 2 != 0) {
    local_28 = 1;
    iVar7 = DAT_00fe1d98;
    do {
      local_2c = *(uint *)(*(int *)(param_1 + 0x68fc) + local_24 * 4);
      iVar9 = 0;
      do {
        if ((local_2c & 1) != 0) {
          puVar5 = (undefined4 *)(*(undefined4 **)(iVar7 + 0xc))[1];
          iVar8 = local_28 + iVar9;
          cVar1 = *(char *)((int)puVar5 + 0x35);
          local_20 = *(undefined4 **)(iVar7 + 0xc);
          while (cVar1 == '\0') {
            if ((int)puVar5[3] < iVar8) {
              puVar3 = (undefined4 *)puVar5[2];
              puVar5 = local_20;
            }
            else {
              puVar3 = (undefined4 *)*puVar5;
            }
            local_20 = puVar5;
            puVar5 = puVar3;
            cVar1 = *(char *)((int)puVar3 + 0x35);
          }
          if ((local_20 == *(undefined4 **)(iVar7 + 0xc)) || (iVar8 < (int)local_20[3])) {
            local_1c[0] = *(undefined4 **)(iVar7 + 0xc);
            ppuVar4 = local_1c;
          }
          else {
            ppuVar4 = &local_20;
          }
          if (((*ppuVar4 != *(undefined4 **)(iVar7 + 0xc)) && ((*ppuVar4)[5] == 1)) &&
             (iVar8 == param_2)) {
            if ((DAT_00fb9390 & 1) == 0) {
              DAT_00fb9390 = DAT_00fb9390 | 1;
              local_c = 0;
              FUN_0044ad70(uVar2);
              _atexit((_func_4879 *)&LAB_00bcd610);
              iVar7 = DAT_00fe1d98;
            }
            puVar5 = (undefined4 *)DAT_00fb9398[1];
            cVar1 = *(char *)((int)puVar5 + 0x15);
            puVar3 = puVar5;
            while (cVar1 == '\0') {
              if ((int)puVar3[3] < 5) {
                puVar3 = (undefined4 *)puVar3[2];
              }
              else {
                puVar3 = (undefined4 *)*puVar3;
              }
              cVar1 = *(char *)((int)puVar3 + 0x15);
            }
            puVar3 = DAT_00fb9398;
            if (*(char *)((int)puVar5 + 0x15) != '\0') {
              ExceptionList = local_14;
              return 1;
            }
            do {
              if ((int)puVar5[3] < 4) {
                puVar6 = (undefined4 *)puVar5[2];
              }
              else {
                puVar6 = (undefined4 *)*puVar5;
                puVar3 = puVar5;
              }
              puVar5 = puVar6;
            } while (*(char *)((int)puVar6 + 0x15) == '\0');
            if (puVar3 == DAT_00fb9398) {
              ExceptionList = local_14;
              return 1;
            }
            if (iVar8 <= (int)(uint)*(byte *)(puVar3[4] + 1)) {
              ExceptionList = local_14;
              return 1;
            }
          }
        }
        local_2c = local_2c >> 1;
        iVar9 = iVar9 + 1;
      } while (iVar9 < 0x20);
      local_28 = local_28 + 0x20;
      local_24 = local_24 + 1;
    } while (local_24 < (uint)(*(int *)(param_1 + 0x6900) - *(int *)(param_1 + 0x68fc) >> 2));
  }
  ExceptionList = local_14;
  return 0;
}

