
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00874650(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puStack_54;
  int iStack_50;
  int iStack_4c;
  undefined4 uStack_48;
  int iStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  int iStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  uStack_2c = 0x87466f;
  FUN_00781ea0();
  uStack_38 = *(undefined4 *)(param_1 + 0x84);
  uStack_2c = 0;
  uStack_30 = 4;
  iStack_34 = in_ECX + 0x2c;
  uStack_3c = 0x874684;
  FUN_006ddcc0();
  uStack_48 = *(undefined4 *)(param_1 + 0x84);
  uStack_3c = 0;
  uStack_40 = 4;
  iStack_44 = in_ECX + 0x28;
  iStack_4c = 0x874697;
  FUN_006ddcc0();
  iStack_4c = 0;
  iStack_50 = 0x14;
  puStack_54 = (undefined4 *)(in_ECX + 0x40);
  uStack_30 = 0;
  FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84));
  FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),&uStack_40,4);
  iStack_4c = 0;
  if (0 < iStack_50) {
    do {
      puVar1 = (undefined4 *)FUN_00891268(0x20);
      if (puVar1 == (undefined4 *)0x0) {
        puVar1 = (undefined4 *)0x0;
      }
      else {
        puVar1[1] = 0;
        puVar1[2] = 0;
        puVar1[3] = 0;
        puVar1[4] = 0;
        puVar1[5] = 0;
        *puVar1 = 0;
      }
      puStack_54 = puVar1;
      FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),puVar1,4,0);
      uVar6 = uRam00000040;
      if (uRam00000040 != 0) {
        iVar2 = FUN_0087dc3d(-(uint)((int)((ulonglong)uRam00000040 * 0xc >> 0x20) != 0) |
                             (uint)((ulonglong)uRam00000040 * 0xc));
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar5 = uVar6 - 1;
          if (-1 < iVar5) {
            puVar3 = (undefined4 *)(iVar2 + 8);
            do {
              puVar3[-2] = 0;
              iVar5 = iVar5 + -1;
              puVar3[-1] = 0;
              *puVar3 = 0;
              puVar3 = puVar3 + 3;
            } while (-1 < iVar5);
          }
        }
        puVar1[1] = iVar2;
        uVar6 = uRam00000040;
        if (0 < (int)uRam00000040) {
          do {
            FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),iVar2,0xc,0);
            iVar2 = iVar2 + 0xc;
            uVar6 = uVar6 - 1;
          } while (uVar6 != 0);
        }
      }
      uVar6 = uRam00000044;
      if (uRam00000044 != 0) {
        iVar2 = FUN_0087dc3d(-(uint)((int)((ulonglong)uRam00000044 * 0xc >> 0x20) != 0) |
                             (uint)((ulonglong)uRam00000044 * 0xc));
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar5 = uVar6 - 1;
          if (-1 < iVar5) {
            puVar3 = (undefined4 *)(iVar2 + 8);
            do {
              puVar3[-2] = 0;
              iVar5 = iVar5 + -1;
              puVar3[-1] = 0;
              *puVar3 = 0;
              puVar3 = puVar3 + 3;
            } while (-1 < iVar5);
          }
        }
        puVar1[2] = iVar2;
        uVar6 = uRam00000044;
        if (0 < (int)uRam00000044) {
          do {
            FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),iVar2,0xc,0);
            iVar2 = iVar2 + 0xc;
            uVar6 = uVar6 - 1;
          } while (uVar6 != 0);
        }
      }
      uVar6 = _DAT_00000048;
      if (_DAT_00000048 != 0) {
        iVar2 = FUN_0087dc3d(-(uint)((int)((ulonglong)_DAT_00000048 * 0xc >> 0x20) != 0) |
                             (uint)((ulonglong)_DAT_00000048 * 0xc));
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar5 = uVar6 - 1;
          if (-1 < iVar5) {
            puVar3 = (undefined4 *)(iVar2 + 8);
            do {
              puVar3[-2] = 0;
              iVar5 = iVar5 + -1;
              puVar3[-1] = 0;
              *puVar3 = 0;
              puVar3 = puVar3 + 3;
            } while (-1 < iVar5);
          }
        }
        puVar1[3] = iVar2;
        uVar6 = _DAT_00000048;
        if (0 < (int)_DAT_00000048) {
          do {
            FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),iVar2,0xc,0);
            iVar2 = iVar2 + 0xc;
            uVar6 = uVar6 - 1;
          } while (uVar6 != 0);
        }
      }
      uVar6 = uRam0000004c;
      if (uRam0000004c != 0) {
        iVar2 = FUN_0087dc3d(-(uint)((int)((ulonglong)uRam0000004c * 0xc >> 0x20) != 0) |
                             (uint)((ulonglong)uRam0000004c * 0xc));
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar5 = uVar6 - 1;
          if (-1 < iVar5) {
            puVar3 = (undefined4 *)(iVar2 + 8);
            do {
              puVar3[-2] = 0;
              iVar5 = iVar5 + -1;
              puVar3[-1] = 0;
              *puVar3 = 0;
              puVar3 = puVar3 + 3;
            } while (-1 < iVar5);
          }
        }
        puVar1[4] = iVar2;
        uVar6 = uRam0000004c;
        if (0 < (int)uRam0000004c) {
          do {
            FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),iVar2,0xc,0);
            iVar2 = iVar2 + 0xc;
            uVar6 = uVar6 - 1;
          } while (uVar6 != 0);
        }
      }
      uVar6 = _DAT_00000050;
      if (_DAT_00000050 != 0) {
        iVar2 = FUN_0087dc3d(-(uint)((int)((ulonglong)_DAT_00000050 * 0xc >> 0x20) != 0) |
                             (uint)((ulonglong)_DAT_00000050 * 0xc));
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar5 = uVar6 - 1;
          if (-1 < iVar5) {
            puVar3 = (undefined4 *)(iVar2 + 8);
            do {
              puVar3[-2] = 0;
              iVar5 = iVar5 + -1;
              puVar3[-1] = 0;
              *puVar3 = 0;
              puVar3 = puVar3 + 3;
            } while (-1 < iVar5);
          }
        }
        puVar1[5] = iVar2;
        uVar6 = _DAT_00000050;
        if (0 < (int)_DAT_00000050) {
          do {
            FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),iVar2,0xc,0);
            iVar2 = iVar2 + 0xc;
            uVar6 = uVar6 - 1;
          } while (uVar6 != 0);
        }
      }
      if ((&puStack_54 < ppuRam00000034) && (ppuRam00000030 <= &puStack_54)) {
        iVar2 = (int)&puStack_54 - (int)ppuRam00000030;
        if (ppuRam00000034 == _DAT_00000038) {
          uVar6 = (int)ppuRam00000034 - (int)ppuRam00000030 >> 2;
          if (0x3ffffffe < uVar6) {
LAB_00874a5e:
                    /* WARNING: Subroutine does not return */
            FUN_0087db30("vector<T> too long");
          }
          uVar6 = uVar6 + 1;
          uVar4 = (int)_DAT_00000038 - (int)ppuRam00000030 >> 2;
          if (uVar4 < uVar6) {
            if (0x3fffffff - (uVar4 >> 1) < uVar4) {
              uVar4 = 0;
            }
            else {
              uVar4 = uVar4 + (uVar4 >> 1);
            }
            if (uVar4 < uVar6) {
              uVar4 = uVar6;
            }
            FUN_00797980(uVar4);
          }
        }
        if (ppuRam00000034 != (undefined4 **)0x0) {
          puVar1 = ppuRam00000030[iVar2 >> 2];
LAB_00874a37:
          *ppuRam00000034 = puVar1;
        }
      }
      else {
        if (ppuRam00000034 == _DAT_00000038) {
          uVar6 = (int)ppuRam00000034 - (int)ppuRam00000030 >> 2;
          if (0x3ffffffe < uVar6) goto LAB_00874a5e;
          uVar6 = uVar6 + 1;
          uVar4 = (int)_DAT_00000038 - (int)ppuRam00000030 >> 2;
          if (uVar4 < uVar6) {
            if (0x3fffffff - (uVar4 >> 1) < uVar4) {
              uVar4 = 0;
            }
            else {
              uVar4 = uVar4 + (uVar4 >> 1);
            }
            if (uVar4 < uVar6) {
              uVar4 = uVar6;
            }
            FUN_00797980(uVar4);
          }
        }
        if (ppuRam00000034 != (undefined4 **)0x0) goto LAB_00874a37;
      }
      ppuRam00000034 = ppuRam00000034 + 1;
      iStack_4c = iStack_4c + 1;
    } while (iStack_4c < iStack_50);
  }
  return 1;
}

