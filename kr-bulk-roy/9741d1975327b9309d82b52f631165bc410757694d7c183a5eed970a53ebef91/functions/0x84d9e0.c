
void FUN_0084d9e0(int param_1)

{
  void *pvVar1;
  int *piVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined4 *_Src;
  int iVar9;
  int *piVar10;
  undefined4 *puVar11;
  int *piVar12;
  undefined1 local_a8 [8];
  int *local_a0;
  int *local_98;
  void *local_8c;
  void *local_88;
  undefined4 local_84;
  uint local_7c;
  undefined4 local_78;
  int local_74;
  int local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 *local_64;
  undefined4 *local_60;
  undefined4 *local_5c;
  int local_54;
  undefined4 local_50;
  int *local_4c;
  int local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  int local_30;
  int *local_2c;
  int local_28;
  int local_24 [5];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8._0_1_ = 0xff;
  local_8._1_3_ = 0xffffff;
  puStack_c = &LAB_009113eb;
  local_10 = ExceptionList;
  local_24[3] = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_28 = param_1;
  if ((*(int *)(param_1 + 0x40) != 0) && (*(int *)(param_1 + 0x44) != 0)) {
    local_38 = param_1 + 0x48;
    FUN_008503c0(local_24[3]);
    local_3c = param_1 + 0x28;
    FUN_006dd8b0();
    if (*(int *)(param_1 + 0x58) != *(int *)(param_1 + 0x5c)) {
      uVar4 = FUN_004fa270(*(int *)(param_1 + 0x58));
      *(undefined4 *)(param_1 + 0x5c) = uVar4;
    }
    local_8c = (void *)0x0;
    local_88 = (void *)0x0;
    local_84 = 0;
    local_8 = 0;
    iVar5 = FUN_00857520(0);
    if (iVar5 == 0) {
      local_44 = 0;
    }
    else {
      local_44 = *(uint *)(iVar5 + 8);
    }
    uVar6 = ((*(int **)(param_1 + 0x44))[1] - **(int **)(param_1 + 0x44)) / 0x14;
    local_7c = uVar6;
    FUN_00850230();
    FUN_005f7e40(local_44);
    FUN_0084fba0();
    _Src = (undefined4 *)0x0;
    local_64 = (undefined4 *)0x0;
    local_60 = (undefined4 *)0x0;
    local_5c = (undefined4 *)0x0;
    local_54 = 0;
    local_50 = 0;
    local_8._0_1_ = 1;
    local_2c = (int *)**(int **)(local_28 + 0x44);
    local_24[0] = 0;
    local_24[1] = 0;
    local_24[2] = 0;
    local_30 = 0;
    local_3c = FUN_00857b00(0,0);
    if (local_3c == 0xffffffff) {
      FUN_007838f0();
      FUN_00418290();
    }
    else {
      FUN_00850740();
      local_8 = CONCAT31(local_8._1_3_,2);
      local_38 = 0;
      if (uVar6 != 0) {
        local_a0 = (int *)(local_3c * 0xc);
        local_4c = local_2c;
        do {
          local_40 = 0;
          local_2c = local_a0;
          do {
            puVar11 = local_64;
            iVar5 = *(int *)((int)local_2c + *local_4c);
            local_48 = iVar5;
            if (local_64 != _Src) {
              FID_conflict__memcpy(local_64,_Src,0);
              local_60 = puVar11;
              _Src = puVar11;
            }
            local_54 = 0;
            local_3c = 0;
            if (*(int *)(*(int *)(local_28 + 0x44) + 0x14) -
                *(int *)(*(int *)(local_28 + 0x44) + 0x10) >> 4 != 0) {
              local_34 = local_40;
              do {
                puVar11 = (undefined4 *)(*local_4c + local_34);
                if ((puVar11 < _Src) && (local_64 <= puVar11)) {
                  iVar5 = (int)puVar11 - (int)local_64;
                  if (_Src == local_5c) {
                    uVar6 = (int)_Src - (int)local_64 >> 2;
                    if (0x3ffffffe < uVar6) {
LAB_0084ddf5:
                    /* WARNING: Subroutine does not return */
                      FUN_0087db30("vector<T> too long");
                    }
                    uVar6 = uVar6 + 1;
                    uVar8 = (int)local_5c - (int)local_64 >> 2;
                    if (uVar8 < uVar6) {
                      if (0x3fffffff - (uVar8 >> 1) < uVar8) {
                        uVar8 = 0;
                      }
                      else {
                        uVar8 = uVar8 + (uVar8 >> 1);
                      }
                      if (uVar8 < uVar6) {
                        uVar8 = uVar6;
                      }
                      FUN_00797980(uVar8);
                      _Src = local_60;
                    }
                  }
                  if (_Src != (undefined4 *)0x0) {
                    *_Src = local_64[iVar5 >> 2];
                  }
                }
                else {
                  if (_Src == local_5c) {
                    uVar6 = (int)_Src - (int)local_64 >> 2;
                    if (0x3ffffffe < uVar6) goto LAB_0084ddf5;
                    uVar6 = uVar6 + 1;
                    uVar8 = (int)local_5c - (int)local_64 >> 2;
                    if (uVar8 < uVar6) {
                      if (0x3fffffff - (uVar8 >> 1) < uVar8) {
                        uVar8 = 0;
                      }
                      else {
                        uVar8 = uVar8 + (uVar8 >> 1);
                      }
                      if (uVar8 < uVar6) {
                        uVar8 = uVar6;
                      }
                      FUN_00797980(uVar8);
                      _Src = local_60;
                    }
                  }
                  if (_Src != (undefined4 *)0x0) {
                    *_Src = *puVar11;
                  }
                }
                local_54 = local_48;
                local_34 = local_34 + 0xc;
                local_3c = local_3c + 1;
                _Src = _Src + 1;
                iVar5 = local_48;
                local_60 = _Src;
              } while (local_3c <
                       (uint)(*(int *)(*(int *)(local_28 + 0x44) + 0x14) -
                              *(int *)(*(int *)(local_28 + 0x44) + 0x10) >> 4));
            }
            iVar7 = local_54;
            if (*(int *)((int)local_8c + iVar5 * 4) == 0) {
              *(undefined4 *)((int)local_8c + iVar5 * 4) = 1;
              iVar5 = *(int *)(local_28 + 0x48) + iVar5 * 0x18;
              FUN_004738a0(&local_64);
              *(int *)(iVar5 + 0x10) = iVar7;
              *(undefined4 *)(iVar5 + 0x14) = local_50;
              *(int *)((int)local_24 + local_40) = local_48;
            }
            else {
              cVar3 = FUN_0084fb20(local_28,iVar5,&local_30);
              if (cVar3 == '\0') {
                iVar5 = (*(int *)(local_28 + 0x4c) - *(int *)(local_28 + 0x48)) / 0x18;
                piVar10 = (int *)(*(int *)(local_28 + 0x48) + 0x10 + local_48 * 0x18);
                local_54 = *piVar10;
                *piVar10 = iVar5;
                local_30 = iVar5;
                FUN_008502e0();
                *(int *)((int)local_24 + local_40) = iVar5;
                _Src = local_60;
              }
              else {
                *(int *)((int)local_24 + local_40) = local_30;
              }
            }
            piVar10 = local_4c;
            local_2c = local_2c + 1;
            local_40 = local_40 + 4;
          } while (local_40 < 0xc);
          local_74 = local_4c[4];
          local_70 = local_24[0];
          local_6c = local_24[1];
          local_68 = local_24[2];
          uVar4 = FUN_0082b0b0();
          FUN_00853a60(local_a8,uVar4);
          local_38 = local_38 + 1;
          local_4c = piVar10 + 5;
        } while (local_38 < local_7c);
      }
      pvVar1 = local_8c;
      uVar6 = 0;
      if (local_44 != 0) {
        iVar5 = 0;
        do {
          if (*(int *)((int)local_8c + uVar6 * 4) == 0) {
            *(uint *)(iVar5 + 0x10 + *(int *)(local_28 + 0x48)) = uVar6;
          }
          uVar6 = uVar6 + 1;
          iVar5 = iVar5 + 0x18;
        } while (uVar6 < local_44);
      }
      if (local_8c != local_88) {
        FID_conflict__memcpy(local_8c,local_88,0);
        local_88 = pvVar1;
      }
      piVar10 = (int *)*local_98;
      iVar5 = piVar10[3];
      local_38 = (*(int *)(local_28 + 0x4c) - *(int *)(local_28 + 0x48)) / 0x18;
      local_78 = 0;
      local_74 = 0;
      local_70 = 0;
      local_6c = 0;
      local_68 = 0;
      local_2c = (int *)0x0;
      piVar12 = (int *)(local_28 + 0x58);
      local_30 = 0;
      FUN_008503f0();
      *(int *)*piVar12 = iVar5;
      *(undefined4 *)(*piVar12 + 4) = 0;
      *(uint *)(*piVar12 + 0x10) = local_38;
      if (piVar10 != local_98) {
        iVar7 = 0;
        local_34 = 0;
        do {
          piVar12 = (int *)(*(int *)(local_28 + 0x28) + local_34);
          *piVar12 = piVar10[4];
          piVar12[1] = piVar10[5];
          piVar12[2] = piVar10[6];
          iVar9 = piVar10[3];
          if (iVar5 == iVar9) {
            piVar12 = (int *)(iVar7 + 8 + *(int *)(local_28 + 0x58));
            *piVar12 = *piVar12 + 1;
            iVar9 = iVar5;
          }
          else {
            local_2c = (int *)((int)local_2c + 1);
            piVar12 = (int *)(local_28 + 0x58);
            local_78 = 0;
            local_74 = 0;
            local_70 = 0;
            local_6c = 0;
            local_68 = 0;
            FUN_008503f0();
            iVar7 = (int)local_2c * 0x14;
            *(int *)(iVar7 + *piVar12) = iVar9;
            *(int *)(iVar7 + 4 + *piVar12) = local_30;
            *(undefined4 *)(iVar7 + 8 + *piVar12) = 1;
            *(undefined4 *)(iVar7 + 0xc + *piVar12) = 0;
            *(uint *)(iVar7 + 0x10 + *piVar12) = local_38;
          }
          if (*(char *)((int)piVar10 + 0x1d) == '\0') {
            piVar12 = (int *)piVar10[2];
            if (*(char *)((int)piVar12 + 0x1d) == '\0') {
              cVar3 = *(char *)(*piVar12 + 0x1d);
              piVar10 = piVar12;
              piVar12 = (int *)*piVar12;
              while (cVar3 == '\0') {
                cVar3 = *(char *)(*piVar12 + 0x1d);
                piVar10 = piVar12;
                piVar12 = (int *)*piVar12;
              }
            }
            else {
              cVar3 = *(char *)(piVar10[1] + 0x1d);
              piVar2 = (int *)piVar10[1];
              piVar12 = piVar10;
              while ((piVar10 = piVar2, cVar3 == '\0' && (piVar12 == (int *)piVar10[2]))) {
                cVar3 = *(char *)(piVar10[1] + 0x1d);
                piVar2 = (int *)piVar10[1];
                piVar12 = piVar10;
              }
            }
          }
          local_30 = local_30 + 1;
          local_34 = local_34 + 0xc;
          iVar5 = iVar9;
        } while (piVar10 != local_98);
      }
      *(undefined4 *)(local_28 + 0x38) = 0;
      local_8._0_1_ = 3;
      FUN_008512c0(*local_98,local_98);
      FUN_0089120c(local_98);
      if (local_64 != (undefined4 *)0x0) {
        FUN_0089120c(local_64);
      }
      if (local_8c != (void *)0x0) {
        FUN_0089120c(local_8c);
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_24[3] ^ (uint)&stack0xfffffffc);
  return;
}

