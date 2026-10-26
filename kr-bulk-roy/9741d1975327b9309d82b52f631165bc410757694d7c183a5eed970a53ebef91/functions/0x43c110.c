
void FUN_0043c110(void)

{
  int iVar1;
  char *pcVar2;
  char cVar3;
  uint uVar4;
  int *piVar5;
  undefined4 *puVar6;
  int in_ECX;
  undefined4 *puVar7;
  float fVar8;
  float fVar9;
  int *unaff_EDI;
  int *piVar10;
  int iStack_88;
  int iStack_84;
  undefined *puStack_80;
  undefined ***pppuStack_7c;
  int local_64;
  float local_60;
  int local_5c;
  char *local_58;
  int local_54;
  char *local_50;
  char *local_4c;
  undefined4 *local_48;
  undefined4 *local_44;
  uint local_40;
  undefined **local_3c;
  void *pvStack_38;
  int local_2c;
  int iStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093431c;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_64;
  ExceptionList = &local_14;
  local_5c = in_ECX;
  if ((DAT_00fb7a08 & 1) == 0) {
    DAT_00fb7a08 = DAT_00fb7a08 | 1;
    local_c = 0;
    FUN_0081ee80();
    pppuStack_7c = (undefined ***)0x43c174;
    _atexit(FUN_00bcd310);
  }
  pcVar2 = DAT_00fb7a14;
  local_c = 0xffffffff;
  iVar1 = *(int *)(*(int *)(in_ECX + 0xf8) + 0xcc);
  local_4c = DAT_00fb7a14;
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0xe0) = 0;
  }
  pppuStack_7c = *(undefined ****)(*(int *)(in_ECX + 0xf8) + 0xcc);
  if (pppuStack_7c != (undefined ***)0x0) {
    puStack_80 = (undefined *)0x43c1bb;
    cVar3 = FUN_00408920();
    if (cVar3 != '\0') {
      local_50 = pcVar2;
      local_60 = (float)(int)pcVar2;
      if ((int)pcVar2 < 0) {
        local_60 = local_60 + 4.2949673e+09;
      }
      local_60 = local_60 * 0.5;
      pppuStack_7c = (undefined ***)0x43c1ec;
      FUN_0043c810();
      uVar4 = FUN_008fed10();
      local_64 = 1;
      local_60 = 0.0;
      local_40 = uVar4;
      do {
        local_54 = 0;
        fVar9 = local_60;
        if (0 < (int)uVar4) {
          local_58 = (char *)((int)local_60 + 1);
          fVar8 = local_60;
          do {
            in_ECX = local_5c;
            if (local_4c < local_58) break;
            iVar1 = *(int *)(*(int *)(local_5c + 0xf8) + 0xcc);
            if (iVar1 != 0) {
              for (piVar5 = *(int **)(iVar1 + 0xa8); piVar5 != *(int **)(iVar1 + 0xac);
                  piVar5 = piVar5 + 1) {
                piVar10 = (int *)*piVar5;
                if ((float)piVar10[8] == fVar8) goto LAB_0043c263;
              }
            }
            piVar10 = (int *)0x0;
LAB_0043c263:
            if (piVar10 != (int *)0x0) {
              if ((DAT_00fb7a08 & 1) == 0) {
                DAT_00fb7a08 = DAT_00fb7a08 | 1;
                local_c = 1;
                DAT_00fb7a14 = (char *)0x0;
                pppuStack_7c = (undefined ***)0x43c294;
                puVar6 = (undefined4 *)FUN_00891268();
                if (puVar6 == (undefined4 *)0x0) {
                  local_50 = (char *)0x0;
                  pppuStack_7c = (undefined ***)0x43c465;
                  std::exception::exception((exception *)&local_3c,&local_50);
                  pppuStack_7c = &local_3c;
                  local_3c = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
                  puStack_80 = &UNK_0043c47c;
                  __CxxThrowException_8();
                }
                DAT_00fb7a10 = puVar6;
                *puVar6 = puVar6;
                DAT_00fb7a10[1] = DAT_00fb7a10;
                DAT_00fb7a10[2] = DAT_00fb7a10;
                *(undefined1 *)(DAT_00fb7a10 + 0xe) = 1;
                *(undefined1 *)((int)DAT_00fb7a10 + 0x39) = 1;
                pppuStack_7c = (undefined ***)0x43c2d3;
                _atexit(FUN_00bcd310);
                local_c = 0xffffffff;
              }
              cVar3 = *(char *)((int)DAT_00fb7a10[1] + 0x39);
              puVar6 = (undefined4 *)DAT_00fb7a10[1];
              local_48 = DAT_00fb7a10;
              while (puVar7 = puVar6, cVar3 == '\0') {
                if (*(byte *)(puVar7 + 3) < (byte)local_64) {
                  puVar6 = (undefined4 *)puVar7[2];
                  puVar7 = local_48;
                }
                else {
                  puVar6 = (undefined4 *)*puVar7;
                }
                cVar3 = *(char *)((int)puVar6 + 0x39);
                local_48 = puVar7;
              }
              if ((local_48 == DAT_00fb7a10) || ((byte)local_64 < *(byte *)(local_48 + 3))) {
                local_44 = DAT_00fb7a10;
              }
              pppuStack_7c = (undefined ***)0x43c33a;
              FUN_0043bd10();
              (**(code **)(*piVar10 + 200))();
              local_64 = local_64 + 1;
              uVar4 = local_40;
              fVar9 = local_60;
            }
            local_54 = local_54 + 1;
            local_58 = local_58 + (int)fVar9 + 1;
            fVar8 = (float)((int)fVar8 + 2);
            in_ECX = local_5c;
          } while (local_54 < (int)uVar4);
        }
        local_60 = (float)((int)fVar9 + 1);
      } while ((int)local_60 < 2);
    }
  }
  piVar5 = *(int **)(in_ECX + 0xf8);
  pppuStack_7c = (undefined ***)0x43c396;
  (**(code **)(*piVar5 + 0x178))();
  iStack_84 = piVar5[3];
  iStack_88 = piVar5[2];
  pppuStack_7c = (undefined ***)
                 (((piVar5[0x30] + piVar5[0x31] * 2 + piVar5[0x2e]) - local_2c) + iStack_24 +
                 iStack_84);
  puStack_80 = (undefined *)piVar5[4];
  (**(code **)(*piVar5 + 0xbc))();
  FUN_00749920(unaff_EDI[0x3e]);
  (**(code **)(*(int *)unaff_EDI[0x3e] + 200))();
  local_44 = (undefined4 *)unaff_EDI[5];
  (**(code **)(*unaff_EDI + 0xbc))
            (unaff_EDI[2],unaff_EDI[3],unaff_EDI[4],*(int *)(unaff_EDI[0x3e] + 0x14) + unaff_EDI[3])
  ;
  ExceptionList = pvStack_38;
  __security_check_cookie(local_40 ^ (uint)&iStack_88);
  return;
}

