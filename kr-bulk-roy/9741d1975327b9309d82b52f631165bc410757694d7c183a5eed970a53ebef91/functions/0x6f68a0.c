
char * FUN_006f68a0(char *param_1)

{
  char *pcVar1;
  undefined4 *puVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int unaff_ESI;
  
  puVar2 = (undefined4 *)FUN_006f50f0();
  puVar5 = *(undefined4 **)(unaff_ESI + 8);
  *puVar5 = *puVar2;
  puVar5[1] = puVar2[1];
  puVar5[2] = puVar2[2];
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
  while( true ) {
    pcVar3 = _strchr(param_1,0x2e);
    pcVar1 = param_1;
    if (pcVar3 == (char *)0x0) {
      do {
        pcVar3 = pcVar1;
        pcVar1 = pcVar3 + 1;
      } while (*pcVar3 != '\0');
    }
    if (*(uint *)(*(int *)(unaff_ESI + 0x10) + 0x40) <= *(uint *)(*(int *)(unaff_ESI + 0x10) + 0x44)
       ) {
      FUN_006fb3a0();
    }
    puVar5 = *(undefined4 **)(unaff_ESI + 8);
    uVar4 = FUN_006fec70();
    *puVar5 = uVar4;
    puVar5[2] = 4;
    *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
    puVar5 = (undefined4 *)FUN_006f9c50();
    iVar6 = *(int *)(unaff_ESI + 8);
    *(undefined4 *)(iVar6 + -0x10) = *puVar5;
    *(undefined4 *)(iVar6 + -0xc) = puVar5[1];
    *(undefined4 *)(iVar6 + -8) = puVar5[2];
    iVar6 = *(int *)(unaff_ESI + 8);
    puVar5 = (undefined4 *)(iVar6 + -0x10);
    if (puVar5 == &DAT_00c0bfc8) break;
    if (*(int *)(iVar6 + -8) == 0) {
      *(undefined4 **)(unaff_ESI + 8) = puVar5;
      if (*(uint *)(*(int *)(unaff_ESI + 0x10) + 0x40) <=
          *(uint *)(*(int *)(unaff_ESI + 0x10) + 0x44)) {
        FUN_006fb3a0();
      }
      puVar5 = *(undefined4 **)(unaff_ESI + 8);
      puVar2 = (undefined4 *)FUN_00700880();
      iVar6 = *(int *)(unaff_ESI + 0x10);
      *puVar2 = *(undefined4 *)(iVar6 + 0x1c);
      *(undefined4 **)(iVar6 + 0x1c) = puVar2;
      *(byte *)((int)puVar2 + 5) = *(byte *)(iVar6 + 0x14) & 3;
      *(undefined1 *)(puVar2 + 1) = 5;
      puVar2[2] = 0;
      puVar2[3] = 0;
      puVar2[7] = 0;
      *(undefined2 *)((int)puVar2 + 6) = 0xff;
      puVar2[4] = &DAT_00c0bfa8;
      uVar4 = FUN_00700880();
      puVar2[3] = uVar4;
      if ((int)puVar2[7] < 0) {
        iVar6 = puVar2[7] << 4;
        do {
          iVar6 = iVar6 + 0x10;
          *(undefined4 *)(puVar2[3] + -8 + iVar6) = 0;
        } while (iVar6 < 0);
      }
      puVar2[7] = 0;
      FUN_006f9560();
      *puVar5 = puVar2;
      puVar5[2] = 5;
      *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
      if (*(uint *)(*(int *)(unaff_ESI + 0x10) + 0x40) <=
          *(uint *)(*(int *)(unaff_ESI + 0x10) + 0x44)) {
        FUN_006fb3a0();
      }
      puVar5 = *(undefined4 **)(unaff_ESI + 8);
      uVar4 = FUN_006fec70();
      *puVar5 = uVar4;
      puVar5[2] = 4;
      *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
      puVar5 = *(undefined4 **)(unaff_ESI + 8);
      *puVar5 = puVar5[-8];
      puVar5[1] = puVar5[-7];
      puVar5[2] = puVar5[-6];
      *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
      FUN_006fb9a0();
      *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + -0x20;
    }
    else if ((puVar5 == &DAT_00c0bfc8) || (*(int *)(iVar6 + -8) != 5)) break;
    puVar2 = *(undefined4 **)(unaff_ESI + 8);
    puVar5 = puVar2 + -4;
    if (puVar5 < puVar2) {
      puVar2 = puVar2 + -8;
      do {
        *puVar2 = *puVar5;
        puVar2[1] = puVar5[1];
        puVar2[2] = puVar2[6];
        puVar5 = puVar5 + 4;
        puVar2 = puVar2 + 4;
      } while (puVar5 < *(undefined4 **)(unaff_ESI + 8));
    }
    *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + -0x10;
    param_1 = pcVar3 + 1;
    if (*pcVar3 != '.') {
      return (char *)0x0;
    }
  }
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + -0x20;
  return param_1;
}

