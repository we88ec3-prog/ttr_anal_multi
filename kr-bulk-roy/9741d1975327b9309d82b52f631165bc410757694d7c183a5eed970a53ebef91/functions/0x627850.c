
void FUN_00627850(int param_1,uint param_2)

{
  int *piVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  void *_Dst;
  uint *puVar5;
  uint *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  undefined4 *puVar12;
  uint uVar13;
  undefined4 *local_58;
  int *local_54;
  uint local_4c;
  uint local_48;
  uint local_40;
  int local_38;
  uint *local_28;
  int local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0090cd48;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  uVar13 = param_2 & 0xff;
  local_54 = (int *)(param_1 + 0x10c);
  local_38 = 0;
  do {
    puVar3 = *(undefined4 **)(*local_54 + 0x104);
    uVar8 = param_2 >> 0x10 & 0xff;
    local_48 = uVar8 | uVar13 << 0x10;
    puVar4 = (undefined4 *)*puVar3;
    local_4c = uVar8 << 0x10 | uVar13;
    local_58 = puVar4;
    if ((char)(param_2 >> 0x10) == -99) {
      local_4c = uVar13 | 0x1d0000;
      local_48 = uVar13 << 0x10 | 0x1d;
    }
    while (puVar4 != puVar3) {
      FUN_0062d9b0(puVar4 + 0x10);
      piVar1 = puVar4 + 0x10;
      local_c = 0;
      _Dst = (void *)*piVar1;
      puVar12 = puVar4;
      if (_Dst != (void *)puVar4[0x11]) {
        FID_conflict__memcpy(_Dst,(void *)puVar4[0x11],0);
        puVar4[0x11] = _Dst;
        puVar12 = local_58;
      }
      uVar8 = local_24 - (int)local_28 >> 2;
      local_40 = 0;
      puVar11 = local_28;
      if (uVar8 != 0) {
        do {
          if ((*puVar11 != local_4c) && (*puVar11 != local_48)) {
            puVar5 = (uint *)puVar4[0x11];
            if ((puVar11 < puVar5) && (puVar6 = (uint *)*piVar1, puVar6 <= puVar11)) {
              if (puVar5 == (uint *)puVar4[0x12]) {
                uVar9 = (int)puVar5 - (int)puVar6 >> 2;
                if (0x3ffffffe < uVar9) {
LAB_00627b33:
                    /* WARNING: Subroutine does not return */
                  FUN_0087db30("vector<T> too long");
                }
                uVar9 = uVar9 + 1;
                uVar10 = (int)puVar4[0x12] - (int)puVar6 >> 2;
                if (uVar10 < uVar9) {
                  if (0x3fffffff - (uVar10 >> 1) < uVar10) {
                    uVar10 = 0;
                  }
                  else {
                    uVar10 = uVar10 + (uVar10 >> 1);
                  }
                  if (uVar10 < uVar9) {
                    uVar10 = uVar9;
                  }
                  FUN_00797980(uVar10);
                }
              }
              if ((undefined4 *)puVar4[0x11] != (undefined4 *)0x0) {
                *(undefined4 *)puVar4[0x11] =
                     *(undefined4 *)(*piVar1 + ((int)puVar11 - (int)puVar6 >> 2) * 4);
              }
            }
            else {
              if (puVar5 == (uint *)puVar4[0x12]) {
                uVar9 = (int)puVar5 - *piVar1 >> 2;
                if (0x3ffffffe < uVar9) goto LAB_00627b33;
                uVar9 = uVar9 + 1;
                uVar10 = (int)puVar4[0x12] - *piVar1 >> 2;
                if (uVar10 < uVar9) {
                  if (0x3fffffff - (uVar10 >> 1) < uVar10) {
                    uVar10 = 0;
                  }
                  else {
                    uVar10 = uVar10 + (uVar10 >> 1);
                  }
                  if (uVar10 < uVar9) {
                    uVar10 = uVar9;
                  }
                  FUN_00797980(uVar10);
                }
              }
              if ((uint *)puVar4[0x11] != (uint *)0x0) {
                *(uint *)puVar4[0x11] = *puVar11;
              }
            }
            puVar4[0x11] = puVar4[0x11] + 4;
          }
          local_40 = local_40 + 1;
          puVar12 = local_58;
          puVar11 = puVar11 + 1;
        } while (local_40 < uVar8);
      }
      if (*(char *)((int)puVar12 + 0x89) == '\0') {
        puVar4 = (undefined4 *)puVar12[2];
        if (*(char *)((int)puVar4 + 0x89) == '\0') {
          cVar2 = *(char *)((int)*puVar4 + 0x89);
          puVar12 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
          while (local_58 = puVar12, cVar2 == '\0') {
            cVar2 = *(char *)((int)*puVar4 + 0x89);
            puVar12 = puVar4;
            puVar4 = (undefined4 *)*puVar4;
          }
        }
        else {
          cVar2 = *(char *)((int)puVar12[1] + 0x89);
          puVar7 = (undefined4 *)puVar12[1];
          puVar4 = puVar12;
          while ((puVar12 = puVar7, local_58 = puVar12, cVar2 == '\0' &&
                 (puVar4 == (undefined4 *)puVar12[2]))) {
            cVar2 = *(char *)((int)puVar12[1] + 0x89);
            puVar7 = (undefined4 *)puVar12[1];
            puVar4 = puVar12;
          }
        }
      }
      local_c = 0xffffffff;
      if (local_28 != (uint *)0x0) {
        FUN_0089120c(local_28);
      }
      local_28 = (uint *)0x0;
      local_24 = 0;
      puVar4 = puVar12;
    }
    local_54 = local_54 + 1;
    local_38 = local_38 + 1;
    if (2 < local_38) {
      ExceptionList = local_14;
      return;
    }
  } while( true );
}

