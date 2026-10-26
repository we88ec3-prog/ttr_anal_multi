
void FUN_0047a6d0(void)

{
  uint _ElementSize;
  short sVar1;
  FILE *_File;
  int iVar2;
  long lVar3;
  size_t sVar4;
  size_t sVar5;
  uint uVar6;
  byte *pbVar7;
  ushort uVar8;
  ushort uVar9;
  undefined4 local_e0;
  uint local_dc;
  undefined4 local_d8;
  byte local_d4 [100];
  byte local_70 [104];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  FUN_00402160(&DAT_00bed1fc,0);
  _File = _fopen("save.data","rb");
  if (_File != (FILE *)0x0) {
    iVar2 = __fileno(_File);
    lVar3 = __filelength(iVar2);
    _ElementSize = lVar3 - 2;
    if (_ElementSize < 0x33) {
      local_70[0] = 0;
      _memset(local_70 + 1,0,0x65);
      local_e0 = 0;
      sVar4 = _fread(&local_e0,2,1,_File);
      sVar5 = _fread(local_70,_ElementSize,1,_File);
      if (sVar4 != 0 && sVar5 != 0) {
        local_d4[0] = 0x1b;
        _memset(local_d4 + 1,0,99);
        iVar2 = 1;
        do {
          local_d4[iVar2] = local_d4[iVar2 + -1] * -0x3b;
          iVar2 = iVar2 + 1;
        } while (iVar2 < 100);
        uVar9 = 0;
        uVar6 = 0;
        if (_ElementSize != 0) {
          do {
            local_70[uVar6] = local_70[uVar6] ^ local_d4[uVar6];
            uVar6 = uVar6 + 1;
          } while (uVar6 < _ElementSize);
        }
        iVar2 = 100;
        pbVar7 = local_d4;
        do {
          *pbVar7 = 0;
          pbVar7 = pbVar7 + 1;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
        uVar6 = 0;
        local_d8 = 0;
        local_dc = 0;
        if (1 < (int)_ElementSize) {
          uVar8 = 0;
          do {
            uVar8 = uVar8 + local_70[uVar6];
            iVar2 = uVar6 + 1;
            uVar6 = uVar6 + 2;
            uVar9 = uVar9 + local_70[iVar2];
          } while ((int)uVar6 < lVar3 + -3);
          local_dc = (uint)uVar9;
          local_d8 = (uint)uVar8;
        }
        uVar9 = 0;
        if (uVar6 < _ElementSize) {
          uVar9 = (ushort)local_70[uVar6];
        }
        if ((short)local_e0 == (ushort)((short)local_dc + (short)local_d8 + uVar9)) {
          pbVar7 = local_70;
          do {
            sVar1 = *(short *)pbVar7;
            pbVar7 = pbVar7 + 2;
          } while (sVar1 != 0);
          FUN_00402160(local_70,(int)pbVar7 - (int)(local_70 + 2) >> 1);
        }
      }
    }
    _fclose(_File);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

