
undefined4 FUN_00846380(undefined4 *param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int in_ECX;
  int iVar9;
  int *piVar10;
  undefined4 *puVar11;
  undefined8 uVar12;
  int iStack_1fc;
  int *piStack_1f8;
  uint local_1f4;
  undefined4 *puStack_1f0;
  uint uStack_1ec;
  uint uStack_1e8;
  undefined4 local_1e0;
  undefined4 local_1dc;
  undefined4 local_1d8;
  undefined4 local_1d4;
  uint local_1d0;
  uint uStack_1cc;
  int iStack_1c8;
  undefined4 *puStack_1c4;
  undefined4 *puStack_1c0;
  undefined4 *puStack_1bc;
  int iStack_1b4;
  int iStack_1b0;
  uint uStack_1ac;
  int *piStack_198;
  undefined4 *local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 auStack_184 [4];
  undefined4 uStack_174;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 auStack_150 [13];
  undefined4 auStack_11c [13];
  undefined4 auStack_e8 [13];
  undefined4 auStack_b4 [26];
  void *local_4c;
  undefined1 *puStack_48;
  uint local_44;
  
  local_44 = 0xffffffff;
  puStack_48 = &LAB_009090c6;
  local_4c = ExceptionList;
  if (((*(int *)(in_ECX + 0x70) == 0) && (iVar9 = *(int *)(in_ECX + 0x78), iVar9 != 0)) &&
     (*(int *)(in_ECX + 0x74) != 0)) {
    iVar2 = *(int *)(in_ECX + 0x7c);
    iVar8 = *(int *)(in_ECX + 0x80);
    local_1d0 = (*(int *)(iVar9 + 0x5c) - *(int *)(iVar9 + 0x58)) / 0x14;
    if (*(int *)(iVar9 + 0x68) != 0) {
      ExceptionList = &local_4c;
      if (*(int *)(in_ECX + 0xb4) == 1) {
        FUN_00847e10(DAT_00d61f20 ^ (uint)&stack0xfffffdc0);
        local_1e0 = 0;
        local_1dc = 0;
        local_1d8 = 0;
        local_1d4 = 0;
        iVar9 = in_ECX + 0xb0;
        iVar6 = (**(code **)(*param_2 + 0x10))();
        if (iVar6 == 0) {
          if (iVar2 == iVar8) {
            if ((*(int *)(in_ECX + 0x94) == 0) && (*(int *)(in_ECX + 0x98) == 0)) {
              iVar8 = FUN_00846220();
              if (iVar8 == 0) {
                (**(code **)(*param_2 + 0x1c))(iVar9,*(undefined4 *)(in_ECX + 0x78));
              }
              else {
                iVar8 = FUN_00847910(in_ECX,&local_1e0);
                if (iVar8 != 0) {
                  (**(code **)(*param_2 + 0x1c))(iVar9,*(undefined4 *)(in_ECX + 0x78));
                }
              }
            }
            else {
              iVar8 = FUN_00847cb0(in_ECX,&local_1e0);
              if (iVar8 != 0) {
                (**(code **)(*param_2 + 0x1c))(iVar9,*(undefined4 *)(in_ECX + 0x78));
              }
            }
          }
          else {
            FUN_008470f0(in_ECX,param_2);
          }
        }
      }
      local_194 = (undefined4 *)0x0;
      local_190 = 0;
      local_18c = 0;
      local_44 = 0;
      if ((*(int *)(in_ECX + 0xb4) == 3) || (*(int *)(in_ECX + 0xb4) == 2)) {
        uVar4 = (*(int *)(in_ECX + 0x80) - *(int *)(in_ECX + 0x7c)) / 100;
        FUN_00847e40();
        uStack_1e8 = 0;
        if (uVar4 != 0) {
          iStack_1fc = 0;
          puStack_1f0 = local_194;
          do {
            iVar9 = **(int **)(in_ECX + 0xac);
            uVar3 = *(uint *)(*(int *)(in_ECX + 0x7c) + iStack_1fc + 0x50);
            if ((uint)((*(int **)(in_ECX + 0xac))[1] - iVar9 >> 2) <= uVar3) {
                    /* WARNING: Subroutine does not return */
              FUN_0087db7d();
            }
            (**(code **)(**(int **)(iVar9 + uVar3 * 4) + 0x24))();
            FUN_007cd220();
            puVar7 = auStack_184;
            puVar11 = auStack_150;
            for (iVar9 = 0xd; iVar9 != 0; iVar9 = iVar9 + -1) {
              *puVar11 = *puVar7;
              puVar7 = puVar7 + 1;
              puVar11 = puVar11 + 1;
            }
            puVar7 = (undefined4 *)FUN_007e7dd0();
            iStack_1fc = iStack_1fc + 100;
            uStack_1e8 = uStack_1e8 + 1;
            puVar11 = puStack_1f0;
            for (iVar9 = 0xd; iVar9 != 0; iVar9 = iVar9 + -1) {
              *puVar11 = *puVar7;
              puVar7 = puVar7 + 1;
              puVar11 = puVar11 + 1;
            }
            puStack_1f0 = puStack_1f0 + 0xd;
          } while (uStack_1e8 < uVar4);
        }
      }
      uStack_1ec = 0;
      if (local_1d0 != 0) {
        uStack_1e8 = 0;
        do {
          iVar9 = *(int *)(in_ECX + 0x78);
          if (uStack_1ec < (uint)((*(int *)(iVar9 + 0x5c) - *(int *)(iVar9 + 0x58)) / 0x14)) {
            iVar9 = *(int *)(uStack_1e8 + *(int *)(iVar9 + 0x58));
          }
          else {
            iVar9 = 0;
          }
          if (*(int **)(in_ECX + 0x74) != (int *)0x0) {
            iVar8 = (**(code **)(**(int **)(in_ECX + 0x74) + 0x24))();
            if (iVar8 == 0) {
              if (iVar9 == 0) {
                iStack_1fc = *(int *)(in_ECX + 0x74);
LAB_00846682:
                if (iStack_1fc != 0) {
                  iVar9 = *(int *)(in_ECX + 0xb4);
                  if (iVar9 == 1) {
                    FUN_007cd220();
                    puVar7 = auStack_150;
                    puVar11 = auStack_e8;
                    for (iVar9 = 0xd; iVar9 != 0; iVar9 = iVar9 + -1) {
                      *puVar11 = *puVar7;
                      puVar7 = puVar7 + 1;
                      puVar11 = puVar11 + 1;
                    }
                    uVar12 = FUN_00846210(in_ECX + 0xb0,0);
                    (**(code **)((int)((ulonglong)uVar12 >> 0x20) + 0x2c))
                              (uStack_1ec,auStack_e8,iStack_1fc,(int)uVar12);
                  }
                  else if ((iVar9 == 2) || (iVar9 == 3)) {
                    iVar9 = *(int *)(in_ECX + 0x78);
                    FUN_00848020();
                    if ((iStack_1c8 != *(int *)(iVar9 + 0x80)) && (iStack_1c8 != -0x10)) {
                      piStack_198 = *(int **)(iStack_1c8 + 0x14);
                      piStack_1f8 = (int *)*piStack_198;
                      puStack_1f0 = (undefined4 *)0x0;
                      if (piStack_1f8 != piStack_198) {
                        do {
                          puStack_1c4 = (undefined4 *)0x0;
                          puStack_1c0 = (undefined4 *)0x0;
                          puStack_1bc = (undefined4 *)0x0;
                          local_44 = CONCAT31(local_44._1_3_,1);
                          uStack_1ac = (uint)(*(int *)(in_ECX + 0xb4) != 2);
                          local_1f4 = 0;
                          piVar10 = (int *)(piStack_1f8[3] * 0x10 +
                                           *(int *)(*(int *)(in_ECX + 0x78) + 0x6c));
                          uStack_1cc = piVar10[1] - *piVar10 >> 2;
                          if (uStack_1cc != 0) {
                            do {
                              puVar7 = local_194 + *(int *)(*piVar10 + local_1f4 * 4) * 0xd;
                              if ((puVar7 < puStack_1c0) && (puStack_1c4 <= puVar7)) {
                                iVar9 = (int)puVar7 - (int)puStack_1c4;
                                if (puStack_1c0 == puStack_1bc) {
                                  FUN_00848230();
                                }
                                puVar7 = puStack_1c4 + (iVar9 / 0x34) * 0xd;
                              }
                              else if (puStack_1c0 == puStack_1bc) {
                                FUN_00848230();
                              }
                              if (puStack_1c0 != (undefined4 *)0x0) {
                                puVar11 = puStack_1c0;
                                for (iVar9 = 0xd; iVar9 != 0; iVar9 = iVar9 + -1) {
                                  *puVar11 = *puVar7;
                                  puVar7 = puVar7 + 1;
                                  puVar11 = puVar11 + 1;
                                }
                              }
                              local_1f4 = local_1f4 + 1;
                              puStack_1c0 = puStack_1c0 + 0xd;
                            } while (local_1f4 < uStack_1cc);
                          }
                          iVar8 = piStack_1f8[6] - piStack_1f8[5] >> 2;
                          uStack_1ac = (uint)(*(int *)(in_ECX + 0xbc) != 0);
                          iStack_1b4 = (int)puStack_1f0;
                          iStack_1b0 = iVar8;
                          _memset(auStack_184,0,0x34);
                          uStack_164 = 0x3f800000;
                          uStack_174 = 0x3f800000;
                          auStack_184[0] = 0x3f800000;
                          FUN_00780a00();
                          FUN_00791100();
                          local_1e0 = *param_1;
                          local_1dc = param_1[1];
                          local_1d8 = param_1[2];
                          uStack_160 = local_1e0;
                          uStack_15c = local_1dc;
                          uStack_158 = local_1d8;
                          puVar7 = auStack_184;
                          puVar11 = auStack_11c;
                          for (iVar9 = 0xd; iVar9 != 0; iVar9 = iVar9 + -1) {
                            *puVar11 = *puVar7;
                            puVar7 = puVar7 + 1;
                            puVar11 = puVar11 + 1;
                          }
                          uVar12 = FUN_00846210(0);
                          (**(code **)((int)((ulonglong)uVar12 >> 0x20) + 0x30))
                                    (uStack_1ec,auStack_11c,&puStack_1c4,iStack_1fc,(int)uVar12);
                          puStack_1f0 = (undefined4 *)((int)puStack_1f0 + iVar8);
                          if (*(char *)((int)piStack_1f8 + 0x35) == '\0') {
                            piVar10 = (int *)piStack_1f8[2];
                            if (*(char *)((int)piVar10 + 0x35) == '\0') {
                              cVar1 = *(char *)(*piVar10 + 0x35);
                              piStack_1f8 = piVar10;
                              piVar10 = (int *)*piVar10;
                              while (cVar1 == '\0') {
                                cVar1 = *(char *)(*piVar10 + 0x35);
                                piStack_1f8 = piVar10;
                                piVar10 = (int *)*piVar10;
                              }
                            }
                            else {
                              cVar1 = *(char *)(piStack_1f8[1] + 0x35);
                              piVar5 = (int *)piStack_1f8[1];
                              piVar10 = piStack_1f8;
                              while ((piStack_1f8 = piVar5, cVar1 == '\0' &&
                                     (piVar10 == (int *)piStack_1f8[2]))) {
                                cVar1 = *(char *)(piStack_1f8[1] + 0x35);
                                piVar5 = (int *)piStack_1f8[1];
                                piVar10 = piStack_1f8;
                              }
                            }
                          }
                          local_44 = local_44 & 0xffffff00;
                          if (puStack_1c4 != (undefined4 *)0x0) {
                            FUN_0089120c();
                          }
                        } while (piStack_1f8 != piStack_198);
                      }
                    }
                  }
                  else {
                    FUN_007cd220();
                    puVar7 = auStack_150;
                    puVar11 = auStack_b4;
                    for (iVar9 = 0xd; iVar9 != 0; iVar9 = iVar9 + -1) {
                      *puVar11 = *puVar7;
                      puVar7 = puVar7 + 1;
                      puVar11 = puVar11 + 1;
                    }
                    uVar12 = FUN_00846210(0);
                    (**(code **)((int)((ulonglong)uVar12 >> 0x20) + 0x34))
                              (uStack_1ec,auStack_b4,iStack_1fc,(int)uVar12);
                  }
                }
              }
            }
            else {
              iVar8 = (**(code **)(**(int **)(in_ECX + 0x74) + 0x38))();
              if (iVar9 < iVar8) {
                iStack_1fc = (**(code **)(**(int **)(in_ECX + 0x74) + 0x28))();
                goto LAB_00846682;
              }
            }
          }
          uStack_1e8 = uStack_1e8 + 0x14;
          uStack_1ec = uStack_1ec + 1;
        } while (uStack_1ec < local_1d0);
      }
      if (local_194 != (undefined4 *)0x0) {
        FUN_0089120c();
      }
      ExceptionList = local_4c;
      return 1;
    }
  }
  return 0;
}

