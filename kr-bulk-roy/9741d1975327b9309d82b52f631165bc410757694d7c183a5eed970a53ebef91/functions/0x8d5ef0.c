
int FUN_008d5ef0(int param_1,undefined4 *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  short *psVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  void *_Dst;
  char *pcVar10;
  ushort uVar11;
  size_t _Size;
  bool bVar12;
  undefined4 *local_1c;
  undefined4 local_18;
  uint local_14;
  char *local_10;
  uint local_c;
  undefined4 local_8;
  
  iVar7 = param_3;
  puVar4 = param_2;
  uVar9 = param_2[0x19];
  local_8 = uVar9;
  param_2 = (undefined4 *)FUN_008d57a0(param_3);
  if ((param_2 == (undefined4 *)0x0) && (iVar7 < 0)) {
    return 0;
  }
  if ((char)param_2 == '\x02') {
    puVar5 = (undefined4 *)FUN_008baee0(uVar9,0xac,&param_2);
    puVar4[0x21] = puVar5;
    if (param_2 != (undefined4 *)0x0) {
      return (int)param_2;
    }
    *puVar4 = 1;
    *puVar5 = 0;
    puVar5[0x29] = *(undefined4 *)(param_1 + 4);
    param_2 = (undefined4 *)FUN_008d56e0();
    if (param_2 != (undefined4 *)0x0) goto LAB_008d61a4;
    if (0 < param_3) {
      param_2 = (undefined4 *)0x6;
      FUN_008d5eb0(puVar4);
      return (int)param_2;
    }
    iVar7 = param_3;
    if (param_3 < 0) {
      return 0;
    }
  }
  else if (param_2 != (undefined4 *)0x0) goto LAB_008d61a4;
  iVar2 = puVar4[0x21];
  puVar4[2] = puVar4[2] | 0x12;
  puVar4[1] = iVar7;
  if (*(short *)(iVar2 + 100) == *(short *)(iVar2 + 0x66)) {
    puVar4[2] = puVar4[2] | 4;
  }
  if (*(char *)(iVar2 + 0x56) != '\0') {
    puVar4[3] = puVar4[3] | 1;
  }
  if (799 < *(ushort *)(iVar2 + 0x5a)) {
    puVar4[3] = puVar4[3] | 2;
  }
  psVar6 = (short *)FUN_008bc7d0(local_8,0x10,0,1,0,&param_2);
  puVar4[8] = psVar6;
  if (param_2 == (undefined4 *)0x0) {
    puVar4[7] = 1;
    psVar6[1] = *(short *)(iVar2 + 100);
    *psVar6 = *(short *)(iVar2 + 0x54) + *(short *)(iVar2 + 0x60);
    iVar7 = (uint)*(ushort *)(iVar2 + 0x4a) << 6;
    *(int *)(psVar6 + 2) = iVar7;
    local_c = (uint)*(ushort *)(iVar2 + 0x4e);
    if (*(ushort *)(iVar2 + 0x4e) == 0) {
      local_c = 0x48;
    }
    uVar11 = *(ushort *)(iVar2 + 0x4c);
    if (uVar11 == 0) {
      uVar11 = 0x48;
    }
    local_10 = (char *)(uint)uVar11;
    iVar7 = FUN_008b7dc0(iVar7,local_10,0x48);
    uVar8 = iVar7 + 0x20U & 0xffffffc0;
    *(uint *)(psVar6 + 6) = uVar8;
    iVar7 = (uint)*(ushort *)(iVar2 + 0x60) * 0x40;
    if (iVar7 < (int)uVar8) {
      *(int *)(psVar6 + 6) = iVar7;
      uVar9 = FUN_008b7dc0(iVar7,0x48,local_10);
      *(undefined4 *)(psVar6 + 2) = uVar9;
    }
    iVar7 = FUN_008b7dc0(*(undefined4 *)(psVar6 + 2),local_c & 0xffff,0x48);
    *(uint *)(psVar6 + 4) = iVar7 + 0x20U & 0xffffffc0;
    bVar12 = *(char *)(iVar2 + 0x5c) == 'M';
    local_18 = 0;
    local_1c = puVar4;
    if (bVar12) {
      local_18 = 0x61726d6e;
    }
    local_14 = (uint)bVar12;
    param_2 = (undefined4 *)FUN_008bcc30(&DAT_00be8220,0,&local_1c,0);
    if (param_2 == (undefined4 *)0x0) {
      if (puVar4[9] != 0) {
        puVar4[0x17] = *(undefined4 *)puVar4[10];
      }
      if (*(byte *)(iVar2 + 0x68) <= *(byte *)(iVar2 + 0x69)) {
        puVar4[4] = ((uint)*(byte *)(iVar2 + 0x69) - (uint)*(byte *)(iVar2 + 0x68)) + 2;
        if (*(uint *)(iVar2 + 0x74) < *(uint *)(iVar2 + 8)) {
          _Size = *(uint *)(iVar2 + 8) - *(uint *)(iVar2 + 0x74);
          _Dst = (void *)FUN_008baee0(local_8,_Size + 1,&param_2);
          *(void **)(iVar2 + 0xa8) = _Dst;
          if (param_2 == (undefined4 *)0x0) {
            FID_conflict__memcpy
                      (_Dst,(void *)(*(int *)(iVar2 + 0xa0) + *(int *)(iVar2 + 0x74)),_Size);
            *(undefined1 *)(_Size + *(int *)(iVar2 + 0xa8)) = 0;
            pcVar3 = *(char **)(iVar2 + 0xa8);
            local_10 = pcVar3 + 1;
            pcVar10 = pcVar3;
            do {
              cVar1 = *pcVar10;
              pcVar10 = pcVar10 + 1;
            } while (cVar1 != '\0');
            uVar9 = FUN_008bc7d0(local_8,1,_Size,pcVar10 + (1 - (int)local_10),pcVar3,&param_2);
            *(undefined4 *)(iVar2 + 0xa8) = uVar9;
            if (param_2 == (undefined4 *)0x0) {
              puVar4[5] = uVar9;
              uVar8 = puVar4[3];
              puVar4[6] = "Regular";
              if ((uVar8 & 2) != 0) {
                if ((uVar8 & 1) != 0) {
                  puVar4[6] = "Bold Italic";
                  return (int)param_2;
                }
                puVar4[6] = &DAT_00c4651c;
                return (int)param_2;
              }
              if ((uVar8 & 1) == 0) {
                return 0;
              }
              puVar4[6] = "Italic";
              return (int)param_2;
            }
          }
          goto LAB_008d61a4;
        }
      }
      param_2 = (undefined4 *)0x3;
      FUN_008d5eb0(puVar4);
      return (int)param_2;
    }
  }
LAB_008d61a4:
  FUN_008d5eb0(puVar4);
  return (int)param_2;
}

