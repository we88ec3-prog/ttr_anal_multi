
void FUN_005c4900(void)

{
  char cVar1;
  uint uVar2;
  void *pvVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  wchar_t *_Str2;
  undefined4 **ppuVar8;
  int in_ECX;
  undefined4 *puVar9;
  wchar_t *****_Str1;
  int *piVar10;
  undefined4 *puVar11;
  int *piVar12;
  int iVar13;
  undefined4 *local_58;
  undefined4 *local_54;
  int *local_50;
  int local_4c;
  int local_48;
  int *local_44;
  int local_40;
  int local_3c;
  undefined4 *local_38;
  void *local_34;
  wchar_t ****local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009290cc;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar13 = in_ECX + 0x130;
  local_44 = &DAT_00f82fdc;
  local_40 = in_ECX;
  local_14 = uVar5;
  do {
    piVar10 = local_44;
    local_3c = iVar13;
    if ((DAT_00fe1e44 & 1) == 0) {
      DAT_00fe1e44 = DAT_00fe1e44 | 1;
      local_8 = 0;
      FUN_00531b40(uVar5);
      _atexit(thunk_FUN_00531c60);
      local_8 = 0xffffffff;
    }
    piVar12 = (int *)**(int **)(&DAT_00fe1eac + *piVar10 * 0x10);
    if ((DAT_00fe1e44 & 1) == 0) {
      DAT_00fe1e44 = DAT_00fe1e44 | 1;
      local_8 = 1;
      FUN_00531b40(uVar5);
      _atexit(thunk_FUN_00531c60);
      local_8 = 0xffffffff;
    }
    local_50 = *(int **)(&DAT_00fe1eac + *piVar10 * 0x10);
    if (piVar12 != local_50) {
      do {
        if (piVar12[0xb] == 0) {
          local_34 = _malloc(0xa0);
          local_8 = 2;
          if (local_34 == (void *)0x0) {
            iVar6 = 0;
          }
          else {
            piVar10 = piVar12 + 0xe;
            if (7 < (uint)piVar12[0x13]) {
              piVar10 = (int *)*piVar10;
            }
            iVar6 = FUN_00763060(local_34,piVar10);
          }
          local_8 = 0xffffffff;
          puVar11 = (undefined4 *)(*(undefined4 **)(iVar13 + 4))[1];
          uVar2 = piVar12[3];
          cVar1 = *(char *)((int)puVar11 + 0x15);
          local_38 = *(undefined4 **)(iVar13 + 4);
          while (cVar1 == '\0') {
            if ((uint)puVar11[3] < uVar2) {
              puVar9 = (undefined4 *)puVar11[2];
              puVar11 = local_38;
            }
            else {
              puVar9 = (undefined4 *)*puVar11;
            }
            local_38 = puVar11;
            puVar11 = puVar9;
            cVar1 = *(char *)((int)puVar9 + 0x15);
          }
          if ((local_38 == *(undefined4 **)(iVar13 + 4)) || (uVar2 < (uint)local_38[3])) {
            local_54 = *(undefined4 **)(iVar13 + 4);
            ppuVar8 = &local_54;
          }
          else {
            ppuVar8 = &local_38;
          }
          if (*ppuVar8 == *(undefined4 **)(iVar13 + 4)) {
            *(uint *)(iVar6 + 0xc) = uVar2;
            uVar7 = FUN_0057ef20();
            FUN_0082f200(iVar13,uVar7);
          }
          if (*(char *)((int)piVar12 + 0x55) == '\0') {
            piVar10 = (int *)piVar12[2];
            if (*(char *)((int)piVar10 + 0x55) == '\0') {
              cVar1 = *(char *)(*piVar10 + 0x55);
              piVar12 = piVar10;
              piVar10 = (int *)*piVar10;
              while (cVar1 == '\0') {
                cVar1 = *(char *)(*piVar10 + 0x55);
                piVar12 = piVar10;
                piVar10 = (int *)*piVar10;
              }
            }
            else {
              cVar1 = *(char *)(piVar12[1] + 0x55);
              piVar4 = (int *)piVar12[1];
              piVar10 = piVar12;
              while ((piVar12 = piVar4, cVar1 == '\0' && (piVar10 == (int *)piVar12[2]))) {
                cVar1 = *(char *)(piVar12[1] + 0x55);
                piVar4 = (int *)piVar12[1];
                piVar10 = piVar12;
              }
            }
          }
        }
        else if (piVar12[0xb] == 1) {
          local_34 = (void *)piVar12[0xc];
          local_30[0] = (wchar_t ****)((uint)local_30[0] & 0xffff0000);
          local_1c = 7;
          local_20 = 0;
          FUN_00402160(L"Quest_Tuto",10);
          iVar13 = local_40;
          local_38 = (undefined4 *)FUN_005c7610();
          if (local_38 == *(undefined4 **)(iVar13 + 8)) {
LAB_005c4b3f:
            local_58 = *(undefined4 **)(iVar13 + 8);
            ppuVar8 = &local_58;
          }
          else {
            _Str2 = (wchar_t *)(local_38 + 3);
            if (7 < (uint)local_38[8]) {
              _Str2 = *(wchar_t **)_Str2;
            }
            _Str1 = (wchar_t *****)local_30[0];
            if (local_1c < 8) {
              _Str1 = local_30;
            }
            iVar6 = __wcsicmp((wchar_t *)_Str1,_Str2);
            if (0 < iVar6) goto LAB_005c4b3f;
            ppuVar8 = &local_38;
          }
          puVar11 = *ppuVar8;
          if (7 < local_1c) {
            FUN_0089120c(local_30[0]);
          }
          if ((((puVar11 != *(undefined4 **)(local_40 + 8)) && (iVar13 = puVar11[10], iVar13 != 0))
              && (FUN_0082ef00(&local_34), local_48 != *(int *)(iVar13 + 0xc))) &&
             (iVar13 = *(int *)(local_48 + 0x10), iVar13 != 0)) {
            local_34 = _malloc(0xa0);
            local_8 = 3;
            if (local_34 == (void *)0x0) {
              local_38 = (undefined4 *)0x0;
            }
            else {
              piVar10 = (int *)(iVar13 + 0x2c);
              if (7 < *(uint *)(iVar13 + 0x40)) {
                piVar10 = (int *)*piVar10;
              }
              local_38 = (undefined4 *)FUN_00763060(local_34,piVar10);
            }
            iVar13 = local_3c;
            local_8 = 0xffffffff;
            pvVar3 = (void *)piVar12[3];
            local_34 = pvVar3;
            FUN_0082ef00(&local_34);
            if (local_4c == *(int *)(iVar13 + 4)) {
              local_38[3] = pvVar3;
              uVar7 = FUN_0057ef20();
              FUN_0082f200(iVar13,uVar7);
            }
          }
          if (*(char *)((int)piVar12 + 0x55) == '\0') {
            piVar10 = (int *)piVar12[2];
            if (*(char *)((int)piVar10 + 0x55) == '\0') {
              cVar1 = *(char *)(*piVar10 + 0x55);
              piVar12 = piVar10;
              piVar10 = (int *)*piVar10;
              while (cVar1 == '\0') {
                cVar1 = *(char *)(*piVar10 + 0x55);
                piVar12 = piVar10;
                piVar10 = (int *)*piVar10;
              }
            }
            else {
              cVar1 = *(char *)(piVar12[1] + 0x55);
              piVar4 = (int *)piVar12[1];
              piVar10 = piVar12;
              while ((piVar12 = piVar4, cVar1 == '\0' && (piVar10 == (int *)piVar12[2]))) {
                cVar1 = *(char *)(piVar12[1] + 0x55);
                piVar4 = (int *)piVar12[1];
                piVar10 = piVar12;
              }
            }
          }
        }
        piVar10 = local_44;
        iVar13 = local_3c;
      } while (piVar12 != local_50);
    }
    local_44 = piVar10 + 1;
    iVar13 = iVar13 + 0x18;
    if (0xf82feb < (int)local_44) {
      ExceptionList = local_10;
      local_3c = iVar13;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
  } while( true );
}

