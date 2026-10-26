
void FUN_0072a540(void)

{
  ushort *puVar1;
  uint _Size;
  int *piVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  int iVar6;
  short *psVar7;
  int iVar8;
  uint uVar9;
  uint _Size_00;
  int *unaff_ESI;
  uint local_8;
  
  _Size = unaff_ESI[0xb];
  do {
    local_8 = (unaff_ESI[0xf] - unaff_ESI[0x1d]) - unaff_ESI[0x1b];
    if ((_Size - 0x106) + unaff_ESI[0xb] <= (uint)unaff_ESI[0x1b]) {
      FID_conflict__memcpy((void *)unaff_ESI[0xe],(void *)(unaff_ESI[0xe] + _Size),_Size);
      iVar8 = unaff_ESI[0x13];
      unaff_ESI[0x1c] = unaff_ESI[0x1c] - _Size;
      unaff_ESI[0x1b] = unaff_ESI[0x1b] - _Size;
      unaff_ESI[0x17] = unaff_ESI[0x17] - _Size;
      psVar7 = (short *)(unaff_ESI[0x11] + iVar8 * 2);
      do {
        puVar1 = (ushort *)(psVar7 + -1);
        psVar7 = psVar7 + -1;
        if (*puVar1 < _Size) {
          sVar5 = 0;
        }
        else {
          sVar5 = *puVar1 - (short)_Size;
        }
        iVar8 = iVar8 + -1;
        *psVar7 = sVar5;
      } while (iVar8 != 0);
      psVar7 = (short *)(unaff_ESI[0x10] + _Size * 2);
      uVar9 = _Size;
      do {
        puVar1 = (ushort *)(psVar7 + -1);
        psVar7 = psVar7 + -1;
        if (*puVar1 < _Size) {
          sVar5 = 0;
        }
        else {
          sVar5 = *puVar1 - (short)_Size;
        }
        uVar9 = uVar9 - 1;
        *psVar7 = sVar5;
      } while (uVar9 != 0);
      local_8 = local_8 + _Size;
    }
    piVar2 = (int *)*unaff_ESI;
    if (piVar2[1] == 0) {
      return;
    }
    iVar8 = unaff_ESI[0x1d];
    iVar3 = unaff_ESI[0x1b];
    uVar9 = piVar2[1];
    iVar4 = unaff_ESI[0xe];
    _Size_00 = uVar9;
    if (local_8 < uVar9) {
      _Size_00 = local_8;
    }
    if (_Size_00 != 0) {
      piVar2[1] = uVar9 - _Size_00;
      if (*(int *)(piVar2[7] + 0x18) == 1) {
        iVar6 = FUN_0072b070(_Size_00);
LAB_0072a632:
        piVar2[0xc] = iVar6;
      }
      else if (*(int *)(piVar2[7] + 0x18) == 2) {
        if (*piVar2 == 0) {
          iVar6 = 0;
        }
        else {
          iVar6 = FUN_0072b700(_Size_00);
        }
        goto LAB_0072a632;
      }
      FID_conflict__memcpy((void *)(iVar8 + iVar3 + iVar4),(void *)*piVar2,_Size_00);
      *piVar2 = *piVar2 + _Size_00;
      piVar2[2] = piVar2[2] + _Size_00;
    }
    unaff_ESI[0x1d] = unaff_ESI[0x1d] + _Size_00;
    if (2 < (uint)unaff_ESI[0x1d]) {
      uVar9 = (uint)*(byte *)(unaff_ESI[0x1b] + unaff_ESI[0xe]);
      unaff_ESI[0x12] = uVar9;
      unaff_ESI[0x12] =
           (uVar9 << ((byte)unaff_ESI[0x16] & 0x1f) ^
           (uint)((byte *)(unaff_ESI[0x1b] + unaff_ESI[0xe]))[1]) & unaff_ESI[0x15];
    }
    if (0x105 < (uint)unaff_ESI[0x1d]) {
      return;
    }
    if (*(int *)(*unaff_ESI + 4) == 0) {
      return;
    }
  } while( true );
}

