
void FUN_008bf890(void)

{
  undefined4 uVar1;
  undefined4 *unaff_ESI;
  int iVar2;
  undefined4 *puVar3;
  uint local_8;
  
  iVar2 = 0;
  if (unaff_ESI != (undefined4 *)0x0) {
    uVar1 = unaff_ESI[0x11022];
    FUN_008b9f80(uVar1,*unaff_ESI);
    *unaff_ESI = 0;
    if (unaff_ESI[0x20] != 0) {
      FUN_008bde80(unaff_ESI[0x20]);
      FUN_008b9f80(uVar1,unaff_ESI[0x20]);
      unaff_ESI[0x20] = 0;
    }
    FUN_008b9f80(uVar1,unaff_ESI[0x15]);
    unaff_ESI[0x15] = 0;
    local_8 = 0;
    if (unaff_ESI[0x12] != 0) {
      do {
        if (*(int *)(unaff_ESI[0x14] + 4 + iVar2) == 1) {
          FUN_008b9f80(uVar1,*(undefined4 *)(unaff_ESI[0x14] + 0xc + iVar2));
          *(undefined4 *)(iVar2 + 0xc + unaff_ESI[0x14]) = 0;
        }
        local_8 = local_8 + 1;
        iVar2 = iVar2 + 0x10;
      } while (local_8 < (uint)unaff_ESI[0x12]);
    }
    FUN_008b9f80(uVar1,unaff_ESI[0x14]);
    unaff_ESI[0x14] = 0;
    local_8 = 0;
    puVar3 = (undefined4 *)unaff_ESI[0xe];
    if (unaff_ESI[0xd] != 0) {
      do {
        FUN_008b9f80(uVar1,*puVar3);
        *puVar3 = 0;
        FUN_008b9f80(uVar1,puVar3[6]);
        puVar3[6] = 0;
        local_8 = local_8 + 1;
        puVar3 = puVar3 + 9;
      } while (local_8 < (uint)unaff_ESI[0xd]);
    }
    puVar3 = (undefined4 *)unaff_ESI[0x11];
    local_8 = 0;
    if (unaff_ESI[0x10] != 0) {
      do {
        FUN_008b9f80(uVar1,*puVar3);
        *puVar3 = 0;
        FUN_008b9f80(uVar1,puVar3[6]);
        puVar3[6] = 0;
        local_8 = local_8 + 1;
        puVar3 = puVar3 + 9;
      } while (local_8 < (uint)unaff_ESI[0x10]);
    }
    FUN_008b9f80(uVar1,unaff_ESI[0xe]);
    unaff_ESI[0xe] = 0;
    FUN_008b9f80(uVar1,unaff_ESI[0x11]);
    unaff_ESI[0x11] = 0;
    local_8 = 0;
    puVar3 = (undefined4 *)unaff_ESI[0x1a];
    if (unaff_ESI[0x1c] != 0) {
      do {
        FUN_008b9f80(uVar1,*puVar3);
        *puVar3 = 0;
        FUN_008b9f80(uVar1,puVar3[6]);
        puVar3[6] = 0;
        local_8 = local_8 + 1;
        puVar3 = puVar3 + 9;
      } while (local_8 < (uint)unaff_ESI[0x1c]);
    }
    FUN_008b9f80(uVar1,unaff_ESI[0x1a]);
    unaff_ESI[0x1a] = 0;
    FUN_008bde80(unaff_ESI + 0x11025);
    puVar3 = (undefined4 *)unaff_ESI[0x11023];
    local_8 = 0;
    if (unaff_ESI[0x11024] != 0) {
      do {
        FUN_008b9f80(uVar1,*puVar3);
        *puVar3 = 0;
        if (puVar3[1] == 1) {
          FUN_008b9f80(uVar1,puVar3[3]);
          puVar3[3] = 0;
        }
        local_8 = local_8 + 1;
        puVar3 = puVar3 + 4;
      } while (local_8 < (uint)unaff_ESI[0x11024]);
    }
    FUN_008b9f80(uVar1,unaff_ESI[0x11023]);
    unaff_ESI[0x11023] = 0;
  }
  return;
}

