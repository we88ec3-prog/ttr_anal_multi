
/* WARNING: Removing unreachable block (ram,0x008fe588) */
/* WARNING: Removing unreachable block (ram,0x008fe918) */

void FUN_008fe4b0(void)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  float *pfVar6;
  undefined4 uVar7;
  float fVar8;
  int *piVar9;
  int in_ECX;
  float fVar10;
  float local_64;
  float local_60;
  char local_59;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00921c99;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_64;
  ExceptionList = &local_14;
  if (*(char *)(in_ECX + 0x1c) == '\0') goto LAB_008fecd0;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffff90);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  switch(DAT_00f9392c) {
  case 3:
  case 5:
  case 7:
  case 8:
  case 0x15:
  case 0x17:
  case 0x18:
    cVar1 = FUN_00572130();
    if (cVar1 == '\0') {
      iVar4 = *(int *)(in_ECX + 0x58);
      if (iVar4 == 0) {
        if (*(int *)(in_ECX + 0x18) % 0xf == 0) {
          local_50 = (float)((*(uint *)(in_ECX + 0x50) & 3) * 0x88 + 0xe);
          local_58 = (float)((*(uint *)(in_ECX + 0x50) >> 2) * 0xbc + 0x1c);
          local_4c = (float)(int)local_58;
          if ((int)local_58 < 0) {
            local_4c = local_4c + 4.2949673e+09;
          }
          FUN_00572140();
          FUN_008fd4a0();
          FUN_00572140();
          FUN_008fd0f0();
          *(int *)(in_ECX + 0x50) = *(int *)(in_ECX + 0x50) + 1;
        }
        uVar2 = FUN_00572120();
        if (uVar2 <= *(uint *)(in_ECX + 0x50)) {
          uVar3 = FUN_00572120();
          uVar7 = *(undefined4 *)(in_ECX + 0x18);
          *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
          *(undefined4 *)(in_ECX + 0x50) = uVar3;
          *(undefined4 *)(in_ECX + 0x58) = 1;
          *(undefined4 *)(in_ECX + 0x5c) = uVar7;
          goto LAB_008fecd0;
        }
      }
      else if (iVar4 == 1) {
        if (*(int *)(in_ECX + 0x5c) + 0x1e <= *(int *)(in_ECX + 0x18)) {
          uVar2 = 0;
          iVar4 = FUN_00572120();
          if (iVar4 != 0) {
            do {
              FUN_00572140();
              FUN_008fd0d0(0x3f800000);
              uVar2 = uVar2 + 1;
              uVar5 = FUN_00572120();
            } while (uVar2 < uVar5);
          }
          uVar7 = *(undefined4 *)(in_ECX + 0x18);
          *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
          *(undefined4 *)(in_ECX + 0x58) = 2;
          *(undefined4 *)(in_ECX + 0x5c) = uVar7;
          goto LAB_008fecd0;
        }
      }
      else {
        if (iVar4 == 2) {
          local_40 = 0x435a0000;
          local_3c = 0x43290000;
          local_59 = '\x01';
          uVar2 = 0;
          iVar4 = FUN_00572120();
          if (iVar4 != 0) {
            do {
              FUN_00572140();
              pfVar6 = (float *)FUN_008fd100();
              local_50 = *pfVar6;
              local_4c = pfVar6[1];
              local_58 = 218.0 - local_50;
              local_54 = 169.0 - local_4c;
              local_64 = local_54 * local_54 + local_58 * local_58;
              if (4.0 <= local_64) {
                local_59 = '\0';
                local_58 = local_58 * 0.4;
                local_54 = local_54 * 0.4;
                local_48 = local_58 + local_50;
                local_44 = local_4c + local_54;
                FUN_00572140();
              }
              else {
                FUN_00572140();
              }
              FUN_008fd4a0();
              uVar2 = uVar2 + 1;
              uVar5 = FUN_00572120();
            } while (uVar2 < uVar5);
            if (local_59 == '\0') goto LAB_008fecc4;
          }
          uVar7 = *(undefined4 *)(in_ECX + 0x18);
          *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
          *(undefined4 *)(in_ECX + 0x58) = 3;
          *(undefined4 *)(in_ECX + 0x5c) = uVar7;
          goto LAB_008fecd0;
        }
        if (iVar4 == 3) {
          uVar2 = *(uint *)(in_ECX + 0x54);
          uVar5 = uVar2 & 0x80000003;
          if ((int)uVar5 < 0) {
            uVar5 = (uVar5 - 1 | 0xfffffffc) + 1;
          }
          local_50 = (float)(int)(uVar5 * 0x88 + 0xe);
          local_64 = (float)(((int)(uVar2 + ((int)uVar2 >> 0x1f & 3U)) >> 2) * 0xbc + 0x1c);
          local_4c = (float)(int)local_64;
          FUN_00572140();
          pfVar6 = (float *)FUN_008fd100();
          local_60 = pfVar6[1];
          local_58 = local_50 - *pfVar6;
          local_54 = local_4c - local_60;
          local_64 = local_54 * local_54 + local_58 * local_58;
          if (4.0 <= local_64) {
            local_58 = local_58 * 0.6666667;
            local_54 = local_54 * 0.6666667;
            local_48 = local_58 + *pfVar6;
            local_44 = local_60 + local_54;
            FUN_00572140();
            FUN_008fd4a0();
          }
          else {
            FUN_00572140();
            FUN_008fd4a0();
            *(int *)(in_ECX + 0x54) = *(int *)(in_ECX + 0x54) + 1;
          }
          iVar4 = FUN_00572120();
          if (*(int *)(in_ECX + 0x54) == iVar4) {
            uVar7 = *(undefined4 *)(in_ECX + 0x18);
            *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
            *(undefined4 *)(in_ECX + 0x58) = 5;
            *(undefined4 *)(in_ECX + 0x5c) = uVar7;
            goto LAB_008fecd0;
          }
        }
        else {
          if (iVar4 == 4) {
            uVar7 = FUN_00572120();
            *(undefined4 *)(in_ECX + 0x50) = uVar7;
            uVar2 = 0;
            iVar4 = FUN_00572120();
            if (iVar4 != 0) {
              do {
                local_48 = (float)((uVar2 & 3) * 0x88 + 0xe);
                local_58 = (float)((uVar2 >> 2) * 0xbc + 0x1c);
                local_44 = (float)(int)local_58;
                if ((int)local_58 < 0) {
                  local_44 = local_44 + 4.2949673e+09;
                }
                FUN_00572140();
                FUN_008fd0f0();
                FUN_00572140();
                FUN_008fd0d0(0x3f800000);
                FUN_00572140();
                FUN_008fd4a0();
                uVar2 = uVar2 + 1;
                uVar5 = FUN_00572120();
              } while (uVar2 < uVar5);
            }
            uVar7 = *(undefined4 *)(in_ECX + 0x18);
            *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
            *(undefined4 *)(in_ECX + 0x58) = 5;
            *(undefined4 *)(in_ECX + 0x5c) = uVar7;
            goto LAB_008fecd0;
          }
          if (iVar4 == 5) {
            local_64 = 0.0;
            iVar4 = FUN_00572120();
            if (iVar4 != 0) {
              do {
                local_58 = (float)(((*(int *)(in_ECX + 0x5c) - *(int *)(in_ECX + 0x18)) + 0x11) *
                                   0xf & 0xff);
                FUN_00572140();
                FUN_008fd440();
                fVar10 = (float)((int)local_64 + 1);
                local_64 = fVar10;
                fVar8 = (float)FUN_00572120();
              } while ((uint)fVar10 < (uint)fVar8);
            }
            iVar4 = *(int *)(in_ECX + 0x18);
            if (*(int *)(in_ECX + 0x5c) + 6 <= iVar4) {
              *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
              *(undefined4 *)(in_ECX + 0x58) = 6;
              *(int *)(in_ECX + 0x5c) = iVar4;
              goto LAB_008fecd0;
            }
          }
          else if (iVar4 == 6) {
            if (*(char *)(in_ECX + 0x60) != '\0') {
              FUN_0040b3c0();
              local_c = 1;
              uVar7 = FUN_0040b3f0();
              piVar9 = (int *)FUN_0080ab00(uVar7);
              if (piVar9 != (int *)0x0) {
                (**(code **)(*piVar9 + 0x14))();
              }
              local_c = 0xffffffff;
              FUN_007cf450();
              FUN_00414680();
              FUN_004a39f0(*(undefined4 *)(in_ECX + 0x48),*(undefined4 *)(in_ECX + 0x44),
                           *(undefined4 *)(in_ECX + 0x4c),0);
              uVar7 = *(undefined4 *)(in_ECX + 0x18);
              *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
              *(undefined4 *)(in_ECX + 0x58) = 7;
              *(undefined4 *)(in_ECX + 0x5c) = uVar7;
              goto LAB_008fecd0;
            }
          }
          else {
            if (iVar4 == 7) {
              local_48 = 218.0;
              local_44 = 169.0;
              FUN_00572140();
              pfVar6 = (float *)FUN_008fd100();
              local_50 = *pfVar6;
              local_4c = pfVar6[1];
              local_64 = 218.0 - local_50;
              local_60 = 169.0 - local_4c;
              local_58 = local_60 * local_60 + local_64 * local_64;
              if (4.0 <= local_58) {
                local_64 = local_64 * 0.4;
                local_60 = local_60 * 0.4;
                local_48 = local_64 + local_50;
                local_44 = local_4c + local_60;
                FUN_00572140();
                FUN_008fd4a0();
                *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
              }
              else {
                FUN_00572140();
                FUN_008fd4a0();
                *(undefined1 *)(in_ECX + 0x2e) = 1;
                FUN_00572140();
                FUN_008fd0d0(0);
                uVar7 = *(undefined4 *)(in_ECX + 0x18);
                *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
                *(undefined4 *)(in_ECX + 0x58) = 8;
                *(undefined4 *)(in_ECX + 0x5c) = uVar7;
              }
              goto LAB_008fecd0;
            }
            if (iVar4 == 8) {
              *(uint *)(in_ECX + 0x30) =
                   (*(int *)(in_ECX + 0x5c) - *(int *)(in_ECX + 0x18)) * 0xa000000 - 0x1000000U |
                   0xffffff;
              if (*(int *)(in_ECX + 0x5c) + 0x3c <= *(int *)(in_ECX + 0x18)) {
                *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
                *(undefined4 *)(in_ECX + 0x30) = 0xffffff;
                *(undefined1 *)(in_ECX + 0x2e) = 0;
                *(undefined4 *)(in_ECX + 0x58) = 9;
                goto LAB_008fecd0;
              }
            }
            else if (iVar4 == 9) {
              if ((-1 < *(int *)(in_ECX + 100)) && (-1 < *(int *)(in_ECX + 0x68))) {
                fVar8 = 0.0;
                local_64 = 0.0;
                iVar4 = FUN_00572120();
                if (iVar4 != 0) {
                  do {
                    if (fVar8 != *(float *)(in_ECX + 100)) {
                      FUN_00572140();
                      FUN_008fd440();
                      fVar8 = local_64;
                    }
                    fVar8 = (float)((int)fVar8 + 1);
                    local_64 = fVar8;
                    fVar10 = (float)FUN_00572120();
                  } while ((uint)fVar8 < (uint)fVar10);
                }
              }
              iVar4 = *(int *)(in_ECX + 0x18);
              if (*(int *)(in_ECX + 0x5c) + 0x1e <= iVar4) {
                *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
                *(undefined4 *)(in_ECX + 0x58) = 10;
                *(int *)(in_ECX + 0x5c) = iVar4;
                goto LAB_008fecd0;
              }
            }
            else if (iVar4 == 10) {
              FUN_008fdd20();
            }
          }
        }
      }
LAB_008fecc4:
      *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
      goto LAB_008fecd0;
    }
  }
  FUN_008fdd20();
LAB_008fecd0:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_64);
  return;
}

