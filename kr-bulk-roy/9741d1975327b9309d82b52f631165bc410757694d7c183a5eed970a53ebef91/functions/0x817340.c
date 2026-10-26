
void FUN_00817340(int *param_1,uint param_2,undefined4 param_3,byte param_4,byte param_5)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  byte bVar9;
  ushort *puVar10;
  int *piVar11;
  int *piVar12;
  int iVar13;
  undefined8 uVar14;
  undefined1 *puVar15;
  int local_6c;
  int local_68;
  undefined4 local_64;
  undefined1 local_5c [8];
  undefined1 local_54 [8];
  undefined1 local_4c [8];
  undefined1 local_44 [8];
  undefined1 local_3c [8];
  undefined1 local_34 [8];
  undefined1 local_2c [8];
  int *local_24;
  uint local_20;
  uint local_1c;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00907398;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_24 = *(int **)((int)param_1 + 4);
  piVar11 = (int *)*local_24;
  param_1 = piVar11;
  if (piVar11 != local_24) {
    do {
      iVar13 = piVar11[4];
      if ((iVar13 != 0) && (*(int *)(iVar13 + 8) != 1)) {
        iVar2 = *(int *)(iVar13 + 0x14);
        iVar3 = *(int *)(iVar13 + 0x18);
        if (iVar2 == iVar3) {
          bVar9 = 0;
        }
        else {
          bVar9 = (char)(iVar3 - iVar2 >> 2) - 1;
        }
        if ((uint)bVar9 < (uint)(iVar3 - iVar2 >> 2)) {
          iVar2 = *(int *)(iVar2 + (uint)bVar9 * 4);
          local_20 = *(int *)(iVar2 + 0x18) - *(int *)(iVar2 + 0x14) >> 2;
        }
        else {
          local_20 = 0;
        }
        local_1c = 0;
        local_18 = iVar13;
        if (local_20 != 0) {
          do {
            uVar14 = FUN_0081ae80(uVar5);
            uVar6 = (uint)((ulonglong)uVar14 >> 0x20);
            iVar2 = *(int *)(*(int *)(iVar13 + 0x14) + ((uint)uVar14 & 0xff) * 4);
            if (uVar6 < (uint)(*(int *)(iVar2 + 0x18) - *(int *)(iVar2 + 0x14) >> 2)) {
              piVar12 = *(int **)(*(int *)(iVar2 + 0x14) + uVar6 * 4);
            }
            else {
              piVar12 = (int *)0x0;
            }
            uVar6 = (**(code **)(*piVar12 + 4))();
            if ((uVar6 & 0x14100000) == 0x14100000) {
              uVar6 = (**(code **)(*piVar12 + 4))();
              uVar6 = ~-(uint)((uVar6 & 0x14100000) != 0x14100000) & (uint)piVar12;
              iVar13 = local_18;
              if (uVar6 != 0) {
                iVar13 = *(int *)(uVar6 + 0x18);
                if (iVar13 != 0) {
                  if (*(int *)(iVar13 + 4) == 9) {
                    if (*(int *)(iVar13 + 8) == 0) {
                      puVar10 = *(ushort **)(iVar13 + 0xc);
                      uVar8 = 0;
                      uVar7 = *(int *)(iVar13 + 0x10) - (int)puVar10 >> 1;
                      if (uVar7 != 0) {
                        do {
                          if (param_2 == *puVar10) {
                            FUN_008177b0(local_2c,piVar11 + 3);
                            break;
                          }
                          uVar8 = uVar8 + 1;
                          puVar10 = puVar10 + 1;
                        } while (uVar8 < uVar7);
                      }
                    }
                  }
                  else if ((*(int *)(iVar13 + 4) == 6) && (param_2 == *(ushort *)(iVar13 + 8))) {
                    FUN_008177b0(local_34,piVar11 + 3);
                    iVar13 = local_18;
                    goto LAB_0081751d;
                  }
                }
                FUN_007e8a90(&local_6c,uVar6 + 8);
                iVar13 = local_6c;
                local_8 = 0;
                uVar7 = local_68 - local_6c >> 2;
                uVar6 = 0;
                if (uVar7 != 0) {
                  if (uVar7 == 0) {
                    /* WARNING: Subroutine does not return */
                    FUN_0087db7d("invalid vector<T> subscript");
                  }
                  do {
                    iVar2 = *(int *)(local_6c + uVar6 * 4);
                    iVar3 = *(int *)(iVar2 + 4);
                    if (iVar3 == 5) {
                      if (param_2 == *(ushort *)(iVar2 + 8)) {
                        piVar12 = piVar11 + 3;
                        puVar15 = local_3c;
                        goto LAB_008175ac;
                      }
                    }
                    else if (iVar3 == 2) {
                      piVar11 = param_1;
                      if ((*(uint *)(iVar2 + 8) & 1 << (param_4 & 0x1f)) != 0) {
                        piVar12 = param_1 + 3;
                        puVar15 = local_44;
LAB_008175ac:
                        FUN_008177b0(puVar15,piVar12);
                        break;
                      }
                    }
                    else if ((iVar3 == 4) &&
                            (piVar11 = param_1, (*(uint *)(iVar2 + 8) & 1 << (param_5 & 0x1f)) != 0)
                            ) {
                      piVar12 = param_1 + 3;
                      puVar15 = local_4c;
                      goto LAB_008175ac;
                    }
                    uVar6 = uVar6 + 1;
                  } while (uVar6 < uVar7);
                }
                local_8 = 0xffffffff;
                if (iVar13 != 0) {
                  FUN_0089120c(iVar13);
                }
                local_6c = 0;
                local_68 = 0;
                local_64 = 0;
                iVar13 = local_18;
              }
            }
            else {
              uVar6 = (**(code **)(*piVar12 + 4))();
              if ((uVar6 & 0x12200000) == 0x12200000) {
                uVar6 = (**(code **)(*piVar12 + 4))();
                if (param_2 ==
                    *(ushort *)((~-(uint)((uVar6 & 0x12200000) != 0x12200000) & (uint)piVar12) + 4))
                {
                  FUN_008177b0(local_54,piVar11 + 3);
                }
              }
              else {
                uVar6 = (**(code **)(*piVar12 + 4))();
                if (((uVar6 & 0x12100000) == 0x12100000) &&
                   (uVar6 = (**(code **)(*piVar12 + 4))(),
                   param_2 ==
                   *(ushort *)((~-(uint)((uVar6 & 0x12100000) != 0x12100000) & (uint)piVar12) + 4)))
                {
                  FUN_008177b0(local_5c,piVar11 + 3);
                }
              }
            }
LAB_0081751d:
            local_1c = local_1c + 1;
          } while (local_1c < local_20);
        }
      }
      if (*(char *)((int)piVar11 + 0x15) == '\0') {
        piVar12 = (int *)piVar11[2];
        if (*(char *)((int)piVar12 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar12 + 0x15);
          piVar11 = piVar12;
          piVar12 = (int *)*piVar12;
          while (param_1 = piVar11, cVar1 == '\0') {
            cVar1 = *(char *)(*piVar12 + 0x15);
            piVar11 = piVar12;
            piVar12 = (int *)*piVar12;
          }
        }
        else {
          cVar1 = *(char *)(piVar11[1] + 0x15);
          piVar4 = (int *)piVar11[1];
          piVar12 = piVar11;
          while ((piVar11 = piVar4, param_1 = piVar11, cVar1 == '\0' &&
                 (piVar12 == (int *)piVar11[2]))) {
            cVar1 = *(char *)(piVar11[1] + 0x15);
            piVar4 = (int *)piVar11[1];
            piVar12 = piVar11;
          }
        }
      }
    } while (piVar11 != local_24);
  }
  ExceptionList = local_10;
  return;
}

