
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00629660(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 *puVar7;
  int *piVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  int *piVar12;
  int *piVar13;
  int *local_54;
  uint local_4c;
  char *local_44;
  undefined4 *local_40;
  undefined4 local_3c;
  undefined **local_34 [3];
  int *local_28;
  int local_24;
  undefined4 local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined1 local_c;
  undefined3 uStack_b;
  
  puStack_10 = &LAB_00926d3c;
  local_14 = ExceptionList;
  uVar9 = DAT_00d61f20 ^ (uint)&stack0xffffffa0;
  ExceptionList = &local_14;
  local_28 = (int *)0x0;
  local_24 = 0;
  local_20 = 0;
  local_c = 0;
  uStack_b = 0;
  if ((_DAT_00fc1a6c & 1) == 0) {
    _DAT_00fc1a6c = _DAT_00fc1a6c | 1;
    _atexit((_func_4879 *)&DAT_00bce3b0);
  }
  FUN_006f33f0(&local_28);
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 1;
    FUN_0054f850(uVar9);
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_c = 0;
  }
  if (DAT_00fb9111 != '\0') {
    uVar9 = local_24 - (int)local_28 >> 2;
    local_4c = 0;
    if (uVar9 != 0) {
      local_54 = local_28;
      do {
        if (*local_54 != 0) {
          if ((DAT_00fc1724 & 1) == 0) {
            DAT_00fc1724 = DAT_00fc1724 | 1;
            local_c = 2;
            FUN_006ccd20();
            _atexit((_func_4879 *)&LAB_00bce3c0);
            local_c = 0;
          }
          if (DAT_00fc1804 != 0) {
            local_3c = 0;
            puVar10 = (undefined4 *)FUN_00891268(0x10);
            if (puVar10 == (undefined4 *)0x0) {
              local_44 = (char *)0x0;
              std::exception::exception((exception *)local_34,&local_44);
              local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
              __CxxThrowException_8(local_34,&DAT_00c857a8);
            }
            *puVar10 = puVar10;
            puVar10[1] = puVar10;
            local_c = 3;
            piVar13 = (int *)*DAT_00fc1800;
            piVar12 = DAT_00fc1800;
            local_40 = puVar10;
            if (piVar13 != DAT_00fc1800) {
              do {
                iVar2 = piVar13[4];
                if (iVar2 == *local_54) {
                  puVar11 = (undefined4 *)FUN_00891268(0x24);
                  if (puVar11 != (undefined4 *)0x0) {
                    uVar3 = *(undefined4 *)(param_1 + 0x248);
                    uVar4 = *(undefined4 *)(param_1 + 0x250);
                    uVar5 = *(undefined4 *)(param_1 + 0x24c);
                    puVar11[1] = 0xffffffff;
                    puVar11[2] = 0xffffffff;
                    puVar11[3] = 0;
                    puVar11[4] = 0xf43cf;
                    *puVar11 = FoxUI::FXUIEventD4::vftable;
                    puVar11[5] = uVar5;
                    puVar11[6] = iVar2;
                    puVar11[7] = uVar4;
                    puVar11[8] = uVar3;
                  }
                  FUN_00748900();
                  piVar12 = DAT_00fc1800;
                }
                if (*(char *)((int)piVar13 + 0x19) == '\0') {
                  piVar6 = (int *)piVar13[2];
                  if (*(char *)((int)piVar6 + 0x19) == '\0') {
                    cVar1 = *(char *)(*piVar6 + 0x19);
                    piVar13 = piVar6;
                    piVar6 = (int *)*piVar6;
                    while (cVar1 == '\0') {
                      cVar1 = *(char *)(*piVar6 + 0x19);
                      piVar13 = piVar6;
                      piVar6 = (int *)*piVar6;
                    }
                  }
                  else {
                    cVar1 = *(char *)(piVar13[1] + 0x19);
                    piVar8 = (int *)piVar13[1];
                    piVar6 = piVar13;
                    while ((piVar13 = piVar8, cVar1 == '\0' && (piVar6 == (int *)piVar13[2]))) {
                      cVar1 = *(char *)(piVar13[1] + 0x19);
                      piVar8 = (int *)piVar13[1];
                      piVar6 = piVar13;
                    }
                  }
                }
              } while (piVar13 != piVar12);
            }
            local_c = 0;
            puVar11 = (undefined4 *)*puVar10;
            *puVar10 = puVar10;
            puVar10[1] = puVar10;
            local_3c = 0;
            while (puVar11 != puVar10) {
              puVar7 = (undefined4 *)*puVar11;
              FUN_0089120c(puVar11);
              puVar11 = puVar7;
            }
            FUN_0089120c(puVar10);
          }
        }
        local_54 = local_54 + 1;
        local_4c = local_4c + 1;
      } while (local_4c < uVar9);
    }
  }
  if (local_28 != (int *)0x0) {
    FUN_0089120c(local_28);
  }
  ExceptionList = local_14;
  return;
}

