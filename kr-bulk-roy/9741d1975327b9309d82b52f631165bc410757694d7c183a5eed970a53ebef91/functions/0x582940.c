
/* WARNING: Type propagation algorithm not settling */

void FUN_00582940(undefined4 *param_1)

{
  byte bVar1;
  short sVar2;
  undefined4 uVar3;
  FILE *_File;
  uint uVar4;
  void *_DstBuf;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  char *pcVar8;
  short *psVar9;
  byte bVar10;
  ushort uVar11;
  undefined4 *puVar12;
  short *psVar13;
  undefined1 auStack_fc [7];
  byte bStack_f5;
  undefined4 *local_f4;
  uint uStack_f0;
  undefined4 *puStack_ec;
  FILE *local_e8;
  int iStack_e4;
  uint uStack_e0;
  void *pvStack_dc;
  undefined4 *puStack_d8;
  int iStack_d0;
  int iStack_cc;
  int iStack_c8;
  undefined4 uStack_c4;
  int iStack_c0;
  code *pcStack_bc;
  code *pcStack_b8;
  undefined4 uStack_b4;
  uint uStack_a4;
  undefined4 uStack_94;
  uint uStack_90;
  short sStack_88;
  undefined1 auStack_86 [106];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0092adbb;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_fc;
  ExceptionList = &local_14;
  local_f4 = param_1;
  _File = _fopen("whsprcac.dat","rb");
  local_e8 = _File;
  if (_File != (FILE *)0x0) {
    _fseek(_File,0,2);
    uVar4 = _ftell(_File);
    _fseek(_File,0,0);
    _DstBuf = (void *)FUN_0087dc3d(uVar4);
    puStack_ec = (undefined4 *)(uVar4 - 4);
    _fread(_DstBuf,(size_t)puStack_ec,1,_File);
    _fread(&iStack_e4,4,1,_File);
    uVar5 = 0;
    uStack_f0 = 0;
    if (local_f4[4] != 0) {
      uStack_e0 = local_f4[5];
      uVar11 = 0;
      do {
        puVar7 = local_f4;
        if (7 < uStack_e0) {
          puVar7 = (undefined4 *)*local_f4;
        }
        uVar11 = uVar11 + *(short *)((int)puVar7 + uVar5 * 2);
        uVar5 = uVar5 + 1;
      } while (uVar5 < (uint)local_f4[4]);
      uStack_f0 = (uint)uVar11;
      _File = local_e8;
    }
    bStack_f5 = (byte)(uStack_f0 >> 8);
    uVar5 = 0;
    bVar10 = (byte)uStack_f0;
    if (uVar4 != 0) {
      do {
        bVar1 = *(byte *)(uVar5 + (int)_DstBuf);
        *(byte *)(uVar5 + (int)_DstBuf) = bVar1 ^ bVar10;
        uVar5 = uVar5 + 1;
        _File = local_e8;
        bVar10 = bStack_f5;
        bStack_f5 = bVar1;
      } while (uVar5 < uVar4);
    }
    uStack_f0 = FUN_0087dc3d(iStack_e4);
    puStack_d8 = puStack_ec;
    iStack_cc = iStack_e4;
    uStack_c4 = 0;
    pcStack_bc = FUN_0072b9c0;
    uStack_b4 = 0;
    pcStack_b8 = FUN_0072b9e0;
    pvStack_dc = _DstBuf;
    iStack_d0 = uStack_f0;
    iVar6 = FUN_0072b9c0(0,1,0x2530);
    if (iVar6 == 0) {
      puVar7 = (undefined4 *)0xfffffffc;
    }
    else {
      *(undefined4 *)(iVar6 + 8) = 1;
      *(undefined4 *)(iVar6 + 0x24) = 0xf;
      *(undefined4 *)(iVar6 + 0x34) = 0;
      iStack_c0 = iVar6;
      puVar7 = (undefined4 *)FUN_007272b0();
      if (puVar7 == (undefined4 *)0x0) {
        puStack_ec = (undefined4 *)FUN_007274b0(&pvStack_dc,4);
        uVar3 = uStack_b4;
        iVar6 = iStack_c0;
        if (puStack_ec == (undefined4 *)0x1) {
          iStack_e4 = iStack_c8;
          if ((iStack_c0 == 0) || (pcStack_b8 == (code *)0x0)) {
            puVar7 = (undefined4 *)0xfffffffe;
          }
          else {
            if (*(int *)(iStack_c0 + 0x34) != 0) {
              (*pcStack_b8)(uStack_b4,*(int *)(iStack_c0 + 0x34));
            }
            (*pcStack_b8)(uVar3,iVar6);
            _File = local_e8;
            puVar7 = (undefined4 *)0x0;
          }
        }
        else {
          if ((iStack_c0 != 0) && (pcStack_b8 != (code *)0x0)) {
            if (*(int *)(iStack_c0 + 0x34) != 0) {
              (*pcStack_b8)(uStack_b4,*(int *)(iStack_c0 + 0x34));
            }
            (*pcStack_b8)(uStack_b4,iVar6);
          }
          if ((puStack_ec == (undefined4 *)0x2) ||
             ((puVar7 = puStack_ec, puStack_ec == (undefined4 *)0xfffffffb &&
              (puStack_d8 == (undefined4 *)0x0)))) {
            puVar7 = (undefined4 *)0xfffffffd;
          }
        }
      }
    }
    FUN_00891d3d(_DstBuf);
    uVar4 = uStack_f0;
    if (puVar7 == (undefined4 *)0x0) {
      pcVar8 = "Sequence~_~";
      uVar5 = 0xc;
      do {
        if (*(int *)(uStack_f0 + -0xc11444 + (int)pcVar8) != *(int *)pcVar8) goto LAB_00582cb9;
        uVar5 = uVar5 - 4;
        pcVar8 = (char *)((int)pcVar8 + 4);
      } while (3 < uVar5);
      uVar5 = (iStack_e4 - 0xcU) / 100;
      if (uVar5 != 0) {
        sStack_88 = 0;
        _memset(auStack_86,0,100);
        puVar12 = (undefined4 *)(uVar5 - 1);
        puVar7 = (undefined4 *)(uVar4 + 0x70);
        _File = local_e8;
        if (puVar12 != (undefined4 *)0x0) {
          puStack_ec = local_f4 + 7;
          local_f4 = puVar12;
          do {
            uStack_a4 = uStack_a4 & 0xffff0000;
            psVar9 = &sStack_88;
            puVar12 = puVar7;
            psVar13 = &sStack_88;
            for (iVar6 = 0x19; iVar6 != 0; iVar6 = iVar6 + -1) {
              *(undefined4 *)psVar13 = *puVar12;
              puVar12 = puVar12 + 1;
              psVar13 = psVar13 + 2;
            }
            uStack_90 = 7;
            uStack_94 = 0;
            do {
              sVar2 = *psVar9;
              psVar9 = psVar9 + 1;
            } while (sVar2 != 0);
            FUN_00402160(&sStack_88,(int)psVar9 - (int)auStack_86 >> 1);
            uStack_c = 0;
            FUN_0049c120();
            uStack_c = 0xffffffff;
            if (7 < uStack_90) {
              FUN_0089120c(uStack_a4);
            }
            puVar7 = puVar7 + 0x19;
            local_f4 = (undefined4 *)((int)local_f4 + -1);
            _File = local_e8;
          } while (local_f4 != (undefined4 *)0x0);
        }
      }
    }
LAB_00582cb9:
    FUN_00891d3d(uStack_f0);
    _fclose(_File);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_fc);
  return;
}

