
void FUN_00710b90(void)

{
  int *piVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int unaff_EDI;
  
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  uVar5 = *(undefined4 *)(unaff_EDI + 0x34);
  piVar1 = *(int **)(unaff_EDI + 0x30);
  FUN_006fec70(uVar5,"(for generator)",0xf);
  puVar4 = (undefined4 *)FUN_006f9d80(uVar5);
  if (puVar4[2] == 0) {
    *puVar4 = 1;
    puVar4[2] = 1;
  }
  iVar6 = *(int *)(unaff_EDI + 0x30);
  if (*(byte *)(iVar6 + 0x32) + 1 < 0xc9) goto LAB_00710c0c;
  do {
    FUN_0070d7c0();
LAB_00710c0c:
    uVar2 = FUN_0070da10();
    *(undefined2 *)(iVar6 + 0xac + (uint)*(byte *)(iVar6 + 0x32) * 2) = uVar2;
    uVar5 = *(undefined4 *)(unaff_EDI + 0x34);
    FUN_006fec70(uVar5,"(for state)",0xb);
    puVar4 = (undefined4 *)FUN_006f9d80(uVar5);
    if (puVar4[2] == 0) {
      *puVar4 = 1;
      puVar4[2] = 1;
    }
    iVar6 = *(int *)(unaff_EDI + 0x30);
    if (200 < *(byte *)(iVar6 + 0x32) + 2) {
      FUN_0070d7c0();
    }
    uVar2 = FUN_0070da10();
    *(undefined2 *)(iVar6 + 0xae + (uint)*(byte *)(iVar6 + 0x32) * 2) = uVar2;
    uVar5 = *(undefined4 *)(unaff_EDI + 0x34);
    FUN_006fec70(uVar5,"(for control)",0xd);
    puVar4 = (undefined4 *)FUN_006f9d80(uVar5);
    if (puVar4[2] == 0) {
      *puVar4 = 1;
      puVar4[2] = 1;
    }
    iVar6 = *(int *)(unaff_EDI + 0x30);
    if (200 < *(byte *)(iVar6 + 0x32) + 3) {
      FUN_0070d7c0();
    }
    uVar2 = FUN_0070da10();
    *(undefined2 *)(iVar6 + 0xb0 + (uint)*(byte *)(iVar6 + 0x32) * 2) = uVar2;
    iVar6 = *(int *)(unaff_EDI + 0x30);
    if (200 < *(byte *)(iVar6 + 0x32) + 4) {
      FUN_0070d7c0();
    }
    uVar2 = FUN_0070da10();
    *(undefined2 *)(iVar6 + 0xb2 + (uint)*(byte *)(iVar6 + 0x32) * 2) = uVar2;
    iVar7 = 4;
    while( true ) {
      if (*(int *)(unaff_EDI + 0x10) != 0x2c) {
        if (*(int *)(unaff_EDI + 0x10) != 0x10b) {
          FUN_006f7c30(*(undefined4 *)(unaff_EDI + 0x34),"\'%s\' expected",&DAT_00c42cb4);
                    /* WARNING: Subroutine does not return */
          FUN_006ff130();
        }
        *(undefined4 *)(unaff_EDI + 8) = *(undefined4 *)(unaff_EDI + 4);
        if (*(int *)(unaff_EDI + 0x20) == 0x11f) {
          uVar5 = FUN_006ffec0(unaff_EDI + 0x18);
          *(undefined4 *)(unaff_EDI + 0x10) = uVar5;
        }
        else {
          *(undefined4 *)(unaff_EDI + 0x10) = *(undefined4 *)(unaff_EDI + 0x20);
          *(undefined4 *)(unaff_EDI + 0x14) = *(undefined4 *)(unaff_EDI + 0x24);
          *(undefined4 *)(unaff_EDI + 0x18) = *(undefined4 *)(unaff_EDI + 0x28);
          *(undefined4 *)(unaff_EDI + 0x1c) = *(undefined4 *)(unaff_EDI + 0x2c);
          *(undefined4 *)(unaff_EDI + 0x20) = 0x11f;
        }
        uVar5 = FUN_0070f1c0();
        FUN_0070dda0(3,uVar5);
        iVar6 = piVar1[9] + 3;
        if ((int)(uint)*(byte *)(*piVar1 + 0x4b) < iVar6) {
          if (0xf9 < iVar6) {
                    /* WARNING: Subroutine does not return */
            FUN_006ff130(piVar1[3],"function or expression too complex",
                         *(undefined4 *)(piVar1[3] + 0x10));
          }
          *(char *)(*piVar1 + 0x4b) = (char)iVar6;
        }
        FUN_007105b0();
        __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
        return;
      }
      *(undefined4 *)(unaff_EDI + 8) = *(undefined4 *)(unaff_EDI + 4);
      if (*(int *)(unaff_EDI + 0x20) == 0x11f) {
        uVar5 = FUN_006ffec0(unaff_EDI + 0x18);
        *(undefined4 *)(unaff_EDI + 0x10) = uVar5;
      }
      else {
        *(undefined4 *)(unaff_EDI + 0x10) = *(undefined4 *)(unaff_EDI + 0x20);
        *(undefined4 *)(unaff_EDI + 0x14) = *(undefined4 *)(unaff_EDI + 0x24);
        *(undefined4 *)(unaff_EDI + 0x18) = *(undefined4 *)(unaff_EDI + 0x28);
        *(undefined4 *)(unaff_EDI + 0x1c) = *(undefined4 *)(unaff_EDI + 0x2c);
        *(undefined4 *)(unaff_EDI + 0x20) = 0x11f;
      }
      FUN_0070d950();
      iVar6 = *(int *)(unaff_EDI + 0x30);
      if (200 < (int)(*(byte *)(iVar6 + 0x32) + 1 + iVar7)) break;
      uVar2 = FUN_0070da10();
      *(undefined2 *)(iVar6 + 0xac + ((uint)*(byte *)(iVar6 + 0x32) + iVar7) * 2) = uVar2;
      iVar7 = iVar7 + 1;
    }
  } while( true );
}

