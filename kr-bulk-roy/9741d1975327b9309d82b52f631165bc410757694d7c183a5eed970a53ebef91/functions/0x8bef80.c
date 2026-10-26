
int FUN_008bef80(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                uint *param_5)

{
  uint *puVar1;
  byte bVar2;
  uint *puVar3;
  undefined2 uVar4;
  short sVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  void *_Src;
  void *_Dst;
  int iVar9;
  uint uVar10;
  short sVar11;
  char *pcVar12;
  uint uVar13;
  size_t _Size;
  uint local_14;
  uint local_10;
  undefined4 local_c;
  int local_8;
  
  puVar3 = param_5;
  uVar10 = param_5[8];
  local_8 = 0;
  local_c = *(undefined4 *)(uVar10 + 0x44088);
  iVar6 = _strncmp(param_1,"COMMENT",7);
  if (iVar6 == 0) {
    pcVar12 = param_1 + 7;
    if (*pcVar12 != '\0') {
      pcVar12 = param_1 + 8;
    }
    local_8 = FUN_008be980(pcVar12);
  }
  else {
    if ((*param_5 & 0x20) == 0) {
      iVar6 = _strncmp(param_1,"CHARS",5);
      if (iVar6 == 0) {
        local_8 = FUN_008be0f0(param_1,param_2);
        if (local_8 == 0) {
          uVar7 = FUN_008be520(0,10);
          *(uint *)(uVar10 + 0x30) = uVar7;
          param_5[1] = uVar7;
          if (uVar7 == 0) {
            *(undefined4 *)(uVar10 + 0x30) = 0x40;
          }
          if (param_5[1] < 0x110000) {
            uVar8 = FUN_008bc7d0(local_c,0x24,0,*(undefined4 *)(uVar10 + 0x30),0,&local_8);
            *(undefined4 *)(uVar10 + 0x38) = uVar8;
            if (local_8 == 0) {
              *param_5 = *param_5 | 0x20;
              return 0;
            }
          }
          else {
            local_8 = 6;
          }
        }
      }
      else {
        local_8 = 0xb4;
      }
      goto LAB_008bf865;
    }
    iVar6 = _strncmp(param_1,"ENDFONT",7);
    if (iVar6 == 0) {
      _qsort(*(void **)(uVar10 + 0x38),*(size_t *)(uVar10 + 0x34),0x24,FUN_008be800);
      *param_5 = *param_5 & 0xfffffffe;
    }
    else {
      iVar6 = _strncmp(param_1,"ENDCHAR",7);
      if (iVar6 == 0) {
        *param_5 = *param_5 & 0xfffff03f;
        param_5[7] = 0;
      }
      else if ((((*param_5 & 0x40) == 0) || (param_5[7] != 0xffffffff)) ||
              (*(int *)(param_5[9] + 4) != 0)) {
        iVar6 = _strncmp(param_1,"STARTCHAR",9);
        if (iVar6 == 0) {
          FUN_008b9f80(local_c,param_5[6]);
          param_5[6] = 0;
          local_8 = FUN_008be0f0(param_1,param_2);
          if (local_8 != 0) goto LAB_008bf865;
          FUN_008be040();
          _Src = (void *)FUN_008be080(0x20,&local_14);
          if (_Src == (void *)0x0) {
            local_8 = 3;
            goto LAB_008bf865;
          }
          _Size = local_14 + 1;
          _Dst = (void *)FUN_008bc7d0(local_c,1,0,_Size,0,&local_8);
          param_5[6] = (uint)_Dst;
          if (local_8 != 0) goto LAB_008bf865;
          FID_conflict__memcpy(_Dst,_Src,_Size);
          *param_5 = *param_5 | 0x40;
        }
        else {
          iVar6 = _strncmp(param_1,"ENCODING",8);
          if (iVar6 == 0) {
            if ((*param_5 & 0x40) == 0) {
              local_8 = 0xb5;
              goto LAB_008bf865;
            }
            local_8 = FUN_008be0f0(param_1,param_2);
            if (local_8 != 0) goto LAB_008bf865;
            uVar7 = FUN_008be600(0,10);
            param_5[7] = uVar7;
            if ((int)uVar7 < -1) {
              param_5[7] = 0xffffffff;
            }
            uVar7 = param_5[7];
            if (uVar7 == 0xffffffff) {
              if (2 < param_5[0x880c]) {
                uVar7 = FUN_008be600(0,10);
                param_5[7] = uVar7;
              }
              uVar7 = param_5[7];
            }
            if ((int)uVar7 < -1) {
              param_5[7] = 0xffffffff;
            }
            uVar7 = param_5[7];
            if ((0 < (int)uVar7) && (0x10ffff < uVar7)) {
LAB_008bf274:
              local_8 = 3;
              goto LAB_008bf865;
            }
            if (-1 < (int)uVar7) {
              uVar13 = 1 << ((byte)uVar7 & 0x1f);
              puVar1 = param_5 + ((int)uVar7 >> 5) + 10;
              if ((*puVar1 & uVar13) == 0) {
                *puVar1 = *puVar1 | uVar13;
              }
              else {
                param_5[7] = 0xffffffff;
                *(undefined2 *)(uVar10 + 0x44084) = 1;
              }
            }
            if ((int)param_5[7] < 0) {
              if (*(int *)(param_5[9] + 4) == 0) {
                FUN_008b9f80(local_c,param_5[6]);
                param_5[6] = 0;
              }
              else {
                iVar6 = *(int *)(uVar10 + 0x3c);
                if (*(int *)(uVar10 + 0x40) == iVar6) {
                  uVar8 = FUN_008bc7d0(local_c,0x24,iVar6,iVar6 + 4,*(undefined4 *)(uVar10 + 0x44),
                                       &local_8);
                  *(undefined4 *)(uVar10 + 0x44) = uVar8;
                  if (local_8 != 0) goto LAB_008bf865;
                  *(int *)(uVar10 + 0x3c) = *(int *)(uVar10 + 0x3c) + 4;
                }
                puVar1 = (uint *)(*(int *)(uVar10 + 0x44) + *(int *)(uVar10 + 0x40) * 0x24);
                *puVar1 = param_5[6];
                puVar1[1] = *(uint *)(uVar10 + 0x40);
                *(int *)(uVar10 + 0x40) = *(int *)(uVar10 + 0x40) + 1;
              }
            }
            else {
              iVar6 = *(int *)(uVar10 + 0x30);
              if (*(int *)(uVar10 + 0x34) == iVar6) {
                uVar8 = FUN_008bc7d0(local_c,0x24,iVar6,iVar6 + 0x40,*(undefined4 *)(uVar10 + 0x38),
                                     &local_8);
                *(undefined4 *)(uVar10 + 0x38) = uVar8;
                if (local_8 != 0) goto LAB_008bf865;
                *(int *)(uVar10 + 0x30) = *(int *)(uVar10 + 0x30) + 0x40;
              }
              iVar6 = *(int *)(uVar10 + 0x34);
              *(int *)(uVar10 + 0x34) = iVar6 + 1;
              puVar1 = (uint *)(*(int *)(uVar10 + 0x38) + iVar6 * 0x24);
              *puVar1 = param_5[6];
              puVar1[1] = param_5[7];
            }
            param_5[6] = 0;
            *param_5 = *param_5 & 0x3fffff7f | 0x80;
          }
          else {
            if (param_5[7] == 0xffffffff) {
              iVar6 = *(int *)(uVar10 + 0x44) + -0x24 + *(int *)(uVar10 + 0x40) * 0x24;
            }
            else {
              iVar6 = *(int *)(uVar10 + 0x38) + -0x24 + *(int *)(uVar10 + 0x34) * 0x24;
            }
            uVar7 = *param_5;
            if ((uVar7 & 0x800) == 0) {
              iVar9 = _strncmp(param_1,"SWIDTH",6);
              if (iVar9 == 0) {
                if ((*param_5 & 0x80) == 0) {
LAB_008bf615:
                  local_8 = 0xb6;
                  goto LAB_008bf865;
                }
                local_8 = FUN_008be0f0(param_1,param_2);
                if (local_8 != 0) goto LAB_008bf865;
                uVar4 = FUN_008be520(0,10);
                *(undefined2 *)(iVar6 + 8) = uVar4;
                *param_5 = *param_5 | 0x100;
              }
              else {
                iVar9 = _strncmp(param_1,"DWIDTH",6);
                if (iVar9 == 0) {
                  if ((*param_5 & 0x80) == 0) goto LAB_008bf615;
                  local_8 = FUN_008be0f0(param_1,param_2);
                  if (local_8 != 0) goto LAB_008bf865;
                  uVar4 = FUN_008be520(0,10);
                  *(undefined2 *)(iVar6 + 10) = uVar4;
                  if ((*param_5 & 0x100) == 0) {
                    uVar4 = FUN_008b7dc0(uVar4,72000,
                                         *(int *)(uVar10 + 0x14) * *(int *)(uVar10 + 0x10));
                    *(undefined2 *)(iVar6 + 8) = uVar4;
                  }
                  *param_5 = *param_5 | 0x200;
                }
                else {
                  iVar9 = _strncmp(param_1,"BBX",3);
                  if (iVar9 != 0) {
                    iVar9 = _strncmp(param_1,"BITMAP",6);
                    if (iVar9 == 0) {
                      if ((*param_5 & 0x400) == 0) {
                        local_8 = 0xb7;
                      }
                      else {
                        uVar10 = (int)((uint)*(ushort *)(param_5[8] + 0x44086) *
                                       (uint)*(ushort *)(iVar6 + 0xc) + 7) >> 3;
                        uVar7 = *(ushort *)(iVar6 + 0xe) * uVar10;
                        *(uint *)(iVar6 + 0x1c) = uVar10;
                        if ((uVar10 < 0x10000) && (uVar7 < 0x10000)) {
                          *(short *)(iVar6 + 0x20) = (short)uVar7;
                          uVar8 = FUN_008bc7d0(local_c,1,0,uVar7 & 0xffff,0,&local_8);
                          *(undefined4 *)(iVar6 + 0x18) = uVar8;
                          if (local_8 == 0) {
                            *param_5 = *param_5 | 0x800;
                            param_5[2] = 0;
                            return 0;
                          }
                        }
                        else {
                          local_8 = 0xb8;
                        }
                      }
                      goto LAB_008bf865;
                    }
                    goto LAB_008bf274;
                  }
                  if ((*param_5 & 0x80) == 0) goto LAB_008bf615;
                  local_8 = FUN_008be0f0(param_1,param_2);
                  if (local_8 != 0) goto LAB_008bf865;
                  uVar4 = FUN_008be700(0,10);
                  *(undefined2 *)(iVar6 + 0xc) = uVar4;
                  uVar4 = FUN_008be700(0,10);
                  *(undefined2 *)(iVar6 + 0xe) = uVar4;
                  uVar4 = FUN_008be700(0,10);
                  *(undefined2 *)(iVar6 + 0x10) = uVar4;
                  sVar5 = FUN_008be700(0,10);
                  sVar11 = *(short *)(iVar6 + 0xe) + sVar5;
                  *(short *)(iVar6 + 0x12) = sVar5;
                  *(short *)(iVar6 + 0x14) = sVar11;
                  *(short *)(iVar6 + 0x16) = -sVar5;
                  sVar5 = *(short *)((int)param_5 + 0x12);
                  if (sVar5 < sVar11) {
                    sVar5 = sVar11;
                  }
                  *(short *)((int)param_5 + 0x12) = sVar5;
                  sVar5 = *(short *)(iVar6 + 0x16);
                  if (*(short *)(iVar6 + 0x16) <= (short)param_5[5]) {
                    sVar5 = (short)param_5[5];
                  }
                  *(short *)(param_5 + 5) = sVar5;
                  sVar5 = *(short *)(iVar6 + 0xc) + *(short *)(iVar6 + 0x10);
                  *(short *)((int)param_5 + 0x16) = sVar5;
                  if (sVar5 <= (short)param_5[4]) {
                    sVar5 = (short)param_5[4];
                  }
                  *(short *)(param_5 + 4) = sVar5;
                  sVar5 = *(short *)(iVar6 + 0x10);
                  if ((short)param_5[3] <= *(short *)(iVar6 + 0x10)) {
                    sVar5 = (short)param_5[3];
                  }
                  *(short *)(param_5 + 3) = sVar5;
                  sVar5 = *(short *)(iVar6 + 0x10);
                  if (*(short *)(iVar6 + 0x10) <= *(short *)((int)param_5 + 0xe)) {
                    sVar5 = *(short *)((int)param_5 + 0xe);
                  }
                  *(short *)((int)param_5 + 0xe) = sVar5;
                  if ((*param_5 & 0x200) == 0) {
                    *(undefined2 *)(iVar6 + 10) = *(undefined2 *)(iVar6 + 0xc);
                  }
                  if ((*(int *)param_5[9] != 0) &&
                     (sVar5 = FUN_008b7dc0(*(undefined2 *)(iVar6 + 10),72000,
                                           *(int *)(uVar10 + 0x14) * *(int *)(uVar10 + 0x10)),
                     sVar5 != *(short *)(iVar6 + 8))) {
                    *(short *)(iVar6 + 8) = sVar5;
                    if (param_5[7] == 0xffffffff) {
                      puVar1 = (uint *)(uVar10 + 0x22084 + (*(int *)(uVar10 + 0x40) - 1U >> 5) * 4);
                      *puVar1 = *puVar1 | 1 << ((char)*(int *)(uVar10 + 0x40) - 1U & 0x1f);
                    }
                    else {
                      puVar1 = (uint *)(uVar10 + 0x84 + (*(int *)(iVar6 + 4) >> 5) * 4);
                      *puVar1 = *puVar1 | 1 << ((byte)*(int *)(iVar6 + 4) & 0x1f);
                    }
                    *param_5 = *param_5 | 0x1000;
                    *(undefined2 *)(uVar10 + 0x44084) = 1;
                  }
                  *param_5 = *param_5 | 0x400;
                }
              }
            }
            else if (param_5[2] < (uint)*(ushort *)(iVar6 + 0xe)) {
              local_14 = *(int *)(iVar6 + 0x1c) * 2;
              param_5 = (uint *)(*(int *)(iVar6 + 0x1c) * param_5[2] + *(int *)(iVar6 + 0x18));
              local_10 = 0;
              if (local_14 != 0) {
                do {
                  uVar7 = local_10 + 1;
                  bVar2 = param_1[local_10];
                  if (((&DAT_00bd7ae8)[bVar2 >> 3] & (byte)(1 << (bVar2 & 7))) == 0) {
                    if ((local_10 < local_14) && ((*puVar3 & 0x40000000) == 0)) {
                      *puVar3 = *puVar3 | 0x40000000;
                      *(undefined2 *)(uVar10 + 0x44084) = 1;
                    }
                    break;
                  }
                  *(byte *)param_5 = *(byte *)param_5 * '\x10' + (&DAT_00bd7a28)[(char)bVar2];
                  if ((uVar7 < local_14) && ((local_10 & 1) != 0)) {
                    param_5 = (uint *)((int)param_5 + 1);
                    *(byte *)param_5 = 0;
                  }
                  local_10 = uVar7;
                } while (uVar7 < local_14);
              }
              if (*(ushort *)(iVar6 + 0xc) != 0) {
                *(byte *)param_5 =
                     *(byte *)param_5 &
                     (&DAT_00bd7b08)
                     [(uint)*(ushort *)(puVar3[8] + 0x44086) * (uint)*(ushort *)(iVar6 + 0xc) & 7];
              }
              if (((local_10 == local_14) &&
                  (((&DAT_00bd7ae8)[(byte)param_1[local_14] >> 3] &
                   (byte)(1 << (param_1[local_14] & 7U))) != 0)) && ((*puVar3 & 0x40000000) == 0)) {
                *puVar3 = *puVar3 | 0x40000000;
                *(undefined2 *)(uVar10 + 0x44084) = 1;
              }
              puVar3[2] = puVar3[2] + 1;
            }
            else if (-1 < (int)uVar7) {
              *param_5 = uVar7 | 0x80000000;
              *(undefined2 *)(uVar10 + 0x44084) = 1;
            }
          }
        }
      }
    }
  }
  if (local_8 == 0) {
    return 0;
  }
LAB_008bf865:
  if ((*puVar3 & 0x40) != 0) {
    FUN_008b9f80(local_c,puVar3[6]);
    puVar3[6] = 0;
  }
  return local_8;
}

