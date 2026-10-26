
int FUN_008de590(uint *param_1,int param_2,uint param_3,int param_4,int param_5)

{
  byte bVar1;
  short sVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  short *psVar10;
  uint in_EDX;
  uint *puVar11;
  uint *puVar12;
  uint local_c;
  int local_8;
  
  local_8 = 0;
  if (*(int *)(param_2 + 8) == 0) {
    return 3;
  }
  puVar3 = param_1 + 0x83;
  iVar8 = 0x100;
  do {
    *(undefined2 *)(puVar3 + -0x80) = 0;
    *(undefined2 *)puVar3 = 0;
    puVar3 = (uint *)((int)puVar3 + 2);
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  if (in_EDX < 2) {
    if (in_EDX == 0) {
      puVar3 = &DAT_00be9d00;
    }
    else {
      if (in_EDX != 1) {
        return 3;
      }
      puVar3 = &DAT_00be9f00;
    }
    puVar12 = param_1 + 3;
    puVar11 = puVar12;
    for (iVar8 = 0x80; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar11 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar11 = puVar11 + 1;
    }
    param_1[2] = 0;
    local_8 = FUN_008de1d0(*(undefined4 *)(param_4 + 0x1c));
    if (local_8 == 0) {
      uVar4 = 0;
      do {
        if (((short)*puVar12 == 0) || (iVar8 = FUN_008de250(), iVar8 == 0)) {
          *(undefined2 *)(puVar12 + 0x80) = 0;
          *(undefined2 *)puVar12 = 0;
        }
        else {
          *(short *)(puVar12 + 0x80) = (short)iVar8;
          param_1[2] = uVar4 + 1;
        }
        uVar4 = uVar4 + 1;
        puVar12 = (uint *)((int)puVar12 + 2);
      } while (uVar4 < 0x100);
    }
  }
  else {
    param_1[1] = param_5 + in_EDX;
    local_8 = FUN_008b97e0(param_4,param_5 + in_EDX);
    if (local_8 == 0) {
      uVar4 = FUN_008b9a40(param_4,&local_8);
      *param_1 = uVar4 & 0xff;
      if (local_8 == 0) {
        uVar4 = FUN_008b9a40(param_4,&local_8);
        uVar4 = uVar4 & 0xff;
        if (local_8 == 0) {
          if ((*param_1 & 0x7f) == 0) {
            param_1[2] = uVar4 + 1;
            local_8 = FUN_008babe0(param_4,uVar4);
            if (local_8 != 0) {
              return local_8;
            }
            pbVar9 = *(byte **)(param_4 + 0x20);
            uVar7 = 1;
            if (uVar4 != 0) {
              do {
                bVar1 = *pbVar9;
                pbVar9 = pbVar9 + 1;
                if (uVar7 < param_3) {
                  *(short *)((int)param_1 + (uint)bVar1 * 2 + 0x20c) = (short)uVar7;
                  *(undefined2 *)((int)param_1 + (uint)bVar1 * 2 + 0xc) =
                       *(undefined2 *)(*(int *)(param_2 + 8) + uVar7 * 2);
                }
                uVar7 = uVar7 + 1;
              } while (uVar7 <= uVar4);
            }
            FUN_008baca0(param_4);
          }
          else {
            if ((*param_1 & 0x7f) != 1) {
              return 3;
            }
            param_1[2] = 0;
            local_c = 0;
            uVar7 = 1;
            if (uVar4 != 0) {
              do {
                uVar5 = FUN_008b9a40(param_4,&local_8);
                if (local_8 != 0) {
                  return local_8;
                }
                uVar6 = FUN_008b9a40(param_4,&local_8);
                if (local_8 != 0) {
                  return local_8;
                }
                uVar6 = (uVar6 & 0xff) + 1;
                if (param_1[2] < uVar6) {
                  param_1[2] = uVar6;
                }
                uVar6 = uVar6 + uVar7;
                if (uVar7 < uVar6) {
                  pbVar9 = (byte *)((int)param_1 + (uVar5 & 0xff) * 2 + 0xc);
                  iVar8 = (uVar5 & 0xff) - uVar7;
                  do {
                    if ((uVar7 < param_3) && (iVar8 + uVar7 < 0x100)) {
                      *(short *)(pbVar9 + 0x200) = (short)uVar7;
                      *(undefined2 *)pbVar9 = *(undefined2 *)(*(int *)(param_2 + 8) + uVar7 * 2);
                    }
                    uVar7 = uVar7 + 1;
                    pbVar9 = pbVar9 + 2;
                  } while (uVar7 < uVar6);
                }
                local_c = local_c + 1;
                uVar7 = uVar6;
              } while (local_c < uVar4);
            }
            if (0x100 < param_1[2]) {
              param_1[2] = 0x100;
            }
          }
          if ((*param_1 & 0x80) != 0) {
            uVar4 = FUN_008b9a40(param_4,&local_8);
            if ((local_8 == 0) && (local_c = 0, (uVar4 & 0xff) != 0)) {
              while( true ) {
                uVar7 = FUN_008b9a40(param_4,&local_8);
                if ((local_8 != 0) || (sVar2 = FUN_008b9ab0(param_4,&local_8), local_8 != 0)) break;
                uVar5 = 0;
                *(short *)((int)param_1 + (uVar7 & 0xff) * 2 + 0xc) = sVar2;
                if (param_3 != 0) {
                  psVar10 = *(short **)(param_2 + 8);
                  do {
                    if (*psVar10 == sVar2) {
                      *(short *)((int)param_1 + (uVar7 & 0xff) * 2 + 0x20c) = (short)uVar5;
                      break;
                    }
                    uVar5 = uVar5 + 1;
                    psVar10 = psVar10 + 1;
                  } while (uVar5 < param_3);
                }
                local_c = local_c + 1;
                if ((uVar4 & 0xff) <= local_c) {
                  return 0;
                }
              }
            }
          }
        }
      }
    }
  }
  return local_8;
}

