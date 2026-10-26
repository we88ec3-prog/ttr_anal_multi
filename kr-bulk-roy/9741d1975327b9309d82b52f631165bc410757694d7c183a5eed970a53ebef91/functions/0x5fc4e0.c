
void FUN_005fc4e0(void)

{
  code *pcVar1;
  uint uVar2;
  undefined4 *puVar3;
  int in_ECX;
  int iVar4;
  uint uVar5;
  int *piVar6;
  undefined1 auStack_94 [16];
  undefined4 local_84;
  undefined4 uStack_80;
  undefined4 *puStack_7c;
  int *piStack_78;
  undefined4 *puStack_74;
  int local_5c;
  undefined1 *local_58;
  uint local_40;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093ec04;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_5c;
  ExceptionList = &local_14;
  local_5c = in_ECX;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    puStack_74 = (undefined4 *)0x5fc542;
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  iVar4 = 0;
  if (DAT_00f94300 != -0x16f8) {
    iVar4 = *(int *)(DAT_00f94300 + 0x2398);
  }
  uVar5 = 0;
  uVar2 = *(int *)(DAT_00fe1d9c + 0xc) - *(int *)(DAT_00fe1d9c + 8) >> 4;
  if (uVar2 != 0) {
    piVar6 = *(int **)(DAT_00fe1d9c + 8);
    do {
      if ((*piVar6 == iVar4 / 0x14 + 1) && (piVar6[1] == (iVar4 % 0x14) / 5 + 1)) {
        piVar6 = *(int **)(DAT_00fe1d9c + 8) + uVar5 * 4;
        if (piVar6 != (int *)0x0) {
          if ((DAT_00f94390 & 1) == 0) {
            DAT_00f94390 = DAT_00f94390 | 1;
            local_c = 1;
            FUN_004e1590();
            puStack_74 = (undefined4 *)0x5fc5fa;
            _atexit((_func_4879 *)&LAB_00bccc80);
          }
          local_c = 0xffffffff;
          iVar4 = FUN_004d43d0();
          if (iVar4 < piVar6[2]) {
            local_58 = (undefined1 *)0xba;
            iVar4 = FUN_005854b0();
            puStack_74 = (undefined4 *)0x5fc63c;
            FUN_005740f0();
            if (local_5c == *(int *)(iVar4 + 4)) {
              pcVar1 = (code *)swi(3);
              (*pcVar1)();
              return;
            }
            puVar3 = (undefined4 *)FUN_004068f0();
            local_c = 2;
            local_5c = 0x196;
            iVar4 = FUN_005854b0();
            puStack_74 = (undefined4 *)0x5fc693;
            FUN_005740f0();
            if (local_58 == *(undefined1 **)(iVar4 + 4)) {
              pcVar1 = (code *)swi(3);
              (*pcVar1)();
              return;
            }
            piStack_78 = (int *)(local_58 + 0x10);
            if (7 < *(uint *)(local_58 + 0x24)) {
              piStack_78 = (int *)*piStack_78;
            }
            if (7 < (uint)puVar3[5]) {
              puVar3 = (undefined4 *)*puVar3;
            }
            puStack_74 = (undefined4 *)0x0;
            uStack_80 = 0xca;
            local_84 = 0x5fc6c9;
            puStack_7c = puVar3;
            FUN_00404b10();
            local_24 = local_40;
          }
          else {
            puStack_74 = (undefined4 *)0x5fc6e7;
            puStack_74 = (undefined4 *)FUN_00891268();
            if (puStack_74 == (undefined4 *)0x0) {
              puStack_74 = (undefined4 *)0x0;
            }
            else {
              *puStack_74 = FoxUI::FXUIEvent::vftable;
              puStack_74[1] = 0xffffffff;
              puStack_74[2] = 0xffffffff;
              puStack_74[3] = 0;
              puStack_74[4] = 0xf4399;
            }
            local_5c = 0x196;
            piStack_78 = (int *)0x5fc71f;
            iVar4 = FUN_005854b0();
            piStack_78 = &local_5c;
            puStack_7c = (undefined4 *)0x5fc731;
            FUN_005740f0();
            if (local_58 == *(undefined1 **)(iVar4 + 4)) {
              pcVar1 = (code *)swi(3);
              (*pcVar1)();
              return;
            }
            piStack_78 = (int *)(local_58 + 0x10);
            if (7 < *(uint *)(local_58 + 0x24)) {
              piStack_78 = (int *)*piStack_78;
            }
            local_58 = auStack_94;
            FUN_00412df0();
            local_c = 3;
            local_5c = 0xbb;
            iVar4 = FUN_005854b0();
            FUN_005740f0(&local_5c);
            if (local_58 == *(undefined1 **)(iVar4 + 4)) {
              pcVar1 = (code *)swi(3);
              (*pcVar1)();
              return;
            }
            puVar3 = (undefined4 *)(local_58 + 0x10);
            if (7 < *(uint *)(local_58 + 0x24)) {
              puVar3 = (undefined4 *)*puVar3;
            }
            local_c = 0xffffffff;
            puStack_7c = (undefined4 *)FUN_00424c80(puVar3);
            local_c = 4;
            if (7 < (uint)puStack_7c[5]) {
              puStack_7c = (undefined4 *)*puStack_7c;
            }
            uStack_80 = 0xcf;
            local_84 = 0x5fc7de;
            FUN_00404b10();
          }
          if (7 < local_24) {
            puStack_74 = (undefined4 *)0x5fc7f1;
            FUN_0089120c();
          }
        }
        break;
      }
      uVar5 = uVar5 + 1;
      piVar6 = piVar6 + 4;
    } while (uVar5 < uVar2);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_5c);
  return;
}

