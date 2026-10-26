
undefined4 FUN_008f7f60(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  void *_Dst;
  int iVar4;
  undefined **ppuVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  byte bVar9;
  int local_c;
  uint local_8;
  
  iVar2 = *param_1;
  uVar3 = *(undefined4 *)(iVar2 + 0x5c);
  _Dst = (void *)param_1[2];
  _memset(_Dst,0x7f,param_1[1]);
  iVar4 = FUN_008b8c70(iVar2,0x756e6963);
  if (iVar4 == 0) {
    ppuVar5 = &PTR_DAT_00bebbe0;
    local_c = 0;
    do {
      piVar7 = *(int **)((&PTR_DAT_00bebb88)[*(int *)(*ppuVar5 + 8)] + 4);
      if ((piVar7 != (int *)0x0) && (*(int *)(*ppuVar5 + 0x10) == 10)) {
        iVar4 = *piVar7;
        while (iVar4 != 0) {
          local_8 = FUN_008b8ce0(iVar2,iVar4);
          if (((local_8 != 0) && (local_8 < (uint)param_1[1])) &&
             (*(char *)(local_8 + (int)_Dst) == '\x7f')) {
            *(undefined1 *)(local_8 + (int)_Dst) = (undefined1)local_c;
          }
          for (uVar6 = FUN_008b8d10(iVar2,iVar4,&local_8);
              (local_8 != 0 && (uVar6 <= (uint)piVar7[1]));
              uVar6 = FUN_008b8d10(iVar2,uVar6,&local_8)) {
            if ((local_8 < (uint)param_1[1]) && (*(char *)(local_8 + (int)_Dst) == '\x7f')) {
              *(undefined1 *)(local_8 + (int)_Dst) = (undefined1)local_c;
            }
          }
          piVar1 = piVar7 + 2;
          piVar7 = piVar7 + 2;
          iVar4 = *piVar1;
        }
      }
      local_c = local_c + 1;
      ppuVar5 = &PTR_DAT_00bebbe0 + local_c;
    } while ((&PTR_DAT_00bebbe0)[local_c] != (undefined *)0x0);
    ppuVar5 = &PTR_DAT_00bebbe0;
    do {
      ppuVar5 = ppuVar5 + 1;
    } while (*ppuVar5 != (undefined *)0x0);
    uVar6 = 0x30;
    do {
      uVar8 = FUN_008b8ce0(iVar2,uVar6);
      if ((uVar8 != 0) && (uVar8 < (uint)param_1[1])) {
        *(byte *)(uVar8 + (int)_Dst) = *(byte *)(uVar8 + (int)_Dst) | 0x80;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < 0x3a);
  }
  if ((*(int *)(param_1[0x33] + 0xc) != 0x7f) && (iVar4 = 0, 0 < param_1[1])) {
    do {
      if ((*(byte *)(iVar4 + (int)_Dst) & 0x7f) == 0x7f) {
        bVar9 = *(byte *)(iVar4 + (int)_Dst) & 0x80;
        *(byte *)(iVar4 + (int)_Dst) = bVar9;
        *(byte *)(iVar4 + (int)_Dst) = *(byte *)(param_1[0x33] + 0xc) | bVar9;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_1[1]);
  }
  FUN_008ba740(iVar2,uVar3);
  return 0;
}

