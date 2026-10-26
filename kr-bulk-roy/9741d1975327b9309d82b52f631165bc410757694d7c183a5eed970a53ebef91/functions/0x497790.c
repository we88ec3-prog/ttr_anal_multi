
void FUN_00497790(int param_1)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 ****ppppuVar8;
  int *piVar9;
  undefined4 uVar10;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined1 auStack_c4 [4];
  uint local_c0;
  int local_bc;
  int local_b8;
  uint uStack_b4;
  int *piStack_b0;
  int iStack_ac;
  uint local_a8;
  int iStack_a4;
  int iStack_a0;
  undefined4 uStack_9c;
  undefined4 ***pppuStack_98;
  char *pcStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  uint uStack_88;
  uint uStack_84;
  undefined1 auStack_7c [96];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093708b;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_c4;
  ExceptionList = &local_14;
  local_b8 = param_1;
  if ((DAT_00fb11a8 & 1) == 0) {
    DAT_00fb11a8 = DAT_00fb11a8 | 1;
    local_c = 0;
    FUN_00813890(DAT_00d61f20 ^ (uint)&stack0xffffff30);
    _atexit((_func_4879 *)&LAB_00bccec0);
  }
  local_c = 0xffffffff;
  local_c0 = *(uint *)(param_1 + 2);
  FUN_0082ef00(&local_c0);
  if (local_bc == DAT_00fb11b0) {
    local_bc = 0;
  }
  else {
    local_bc = *(int *)(local_bc + 0x10);
  }
  local_a8 = 0;
  do {
    if (((uint)(*(int *)(local_bc + 0x18) - *(int *)(local_bc + 0x14) >> 2) <=
         (uint)*(byte *)(param_1 + 6)) ||
       (iVar5 = *(int *)(*(int *)(local_bc + 0x14) + (uint)*(byte *)(param_1 + 6) * 4),
       (uint)(*(int *)(iVar5 + 0x18) - *(int *)(iVar5 + 0x14) >> 2) <= local_a8)) {
      ExceptionList = local_14;
      __security_check_cookie(local_1c ^ (uint)auStack_c4);
      return;
    }
    if ((local_a8 < (uint)(*(int *)(iVar5 + 0x18) - *(int *)(iVar5 + 0x14) >> 2)) &&
       (piVar9 = *(int **)(*(int *)(iVar5 + 0x14) + local_a8 * 4), piVar9 != (int *)0x0)) {
      uVar4 = (**(code **)(*piVar9 + 4))();
      uVar4 = ~-(uint)((uVar4 & 0x14100000) != 0x14100000) & (uint)piVar9;
      uStack_b4 = uVar4;
      if ((uVar4 != 0) && (*(char *)(uVar4 + 0x29) == *(char *)(param_1 + 9))) {
        if ((DAT_00fab22c & 1) == 0) {
          DAT_00fab22c = DAT_00fab22c | 1;
          local_c = 1;
          FUN_004dec90();
          _atexit((_func_4879 *)&LAB_00bcce30);
          local_c = 0xffffffff;
        }
        uVar2 = *(ushort *)(param_1 + 7);
        local_c0 = (uint)uVar2;
        FUN_0082ef00(&local_c0);
        if (iStack_a4 == DAT_00fab13c) {
          piStack_b0 = (int *)0x0;
        }
        else {
          piStack_b0 = *(int **)(iStack_a4 + 0x10);
        }
        iVar5 = 0;
        piVar9 = DAT_00fba7a4;
        do {
          piVar9 = piVar9 + 3;
          if ((*piVar9 != 0) && (*(ushort *)(*piVar9 + 4) == uVar2)) {
            if (iVar5 != -1) {
              uStack_84 = 7;
              uStack_88 = 0;
              pppuStack_98 = (undefined4 ***)((uint)pppuStack_98 & 0xffff0000);
              local_c._1_3_ = 0;
              if ((DAT_00fc0dc4 & 1) == 0) {
                DAT_00fc0dc4 = DAT_00fc0dc4 | 1;
                local_c._0_1_ = 3;
                local_c._1_3_ = 0;
                FUN_0052a3b0();
                _atexit(FUN_00bcd980);
              }
              local_c._0_1_ = 2;
              local_c0 = *(uint *)(param_1 + 2);
              FUN_0052a340(&local_c0);
              if (iStack_a0 == DAT_00fc0dcc) {
                iStack_ac = 0;
              }
              else {
                iStack_ac = iStack_a0 + 0x10;
              }
              iVar6 = iStack_ac;
              iVar5 = *(int *)(uVar4 + 0x18);
              if ((iStack_ac == 0) || (iVar5 == 0)) goto LAB_00497be3;
              iVar3 = *(int *)(iVar5 + 4);
              if (iVar3 == 6) {
                FUN_00484eb0();
                iVar5 = FUN_005300f0();
                if (iVar5 == 0) goto LAB_00497be3;
                piVar9 = (int *)(iVar6 + 4);
                if (7 < *(uint *)(iVar6 + 0x18)) {
                  piVar9 = (int *)*piVar9;
                }
                uVar11 = 0x59;
                FUN_005855b0(0x59,piVar9);
                FUN_00585330(uVar11);
                uVar11 = FUN_00498ef0();
                local_c = CONCAT31(local_c._1_3_,5);
                FUN_00402800(uVar11);
              }
              else {
                if (iVar3 != 7) {
                  if (iVar3 == 9) {
                    local_c0 = 0;
                    if (*(int *)(iVar5 + 0x10) - *(int *)(iVar5 + 0xc) >> 1 != 0) {
                      do {
                        uVar4 = local_c0;
                        FUN_00484eb0();
                        iVar6 = FUN_005300f0();
                        if (iVar6 != 0) {
                          puVar7 = (undefined4 *)(iStack_ac + 4);
                          if (7 < *(uint *)(iStack_ac + 0x18)) {
                            puVar7 = (undefined4 *)*puVar7;
                          }
                          uVar11 = 0x5a;
                          FUN_005855b0(0x5a,puVar7);
                          FUN_00585330(uVar11);
                          uVar11 = FUN_00498ef0();
                          local_c._0_1_ = 6;
                          FUN_00402800(uVar11);
                          local_c._0_1_ = 2;
                          FUN_004fa440();
                          ppppuVar8 = &pppuStack_98;
                          FUN_0040f8c0(ppppuVar8);
                          FUN_004d6b30(ppppuVar8);
                          ppppuVar8 = (undefined4 ****)pppuStack_98;
                          if (uStack_84 < 8) {
                            ppppuVar8 = &pppuStack_98;
                          }
                          uVar11 = FUN_0048a8c0(extraout_ECX,ppppuVar8);
                          FUN_0056b7f0(uVar11,ppppuVar8);
                          uVar4 = local_c0;
                        }
                        local_c0 = uVar4 + 1;
                      } while (local_c0 <
                               (uint)(*(int *)(iVar5 + 0x10) - *(int *)(iVar5 + 0xc) >> 1));
                    }
                    uStack_88 = 0;
                    ppppuVar8 = (undefined4 ****)pppuStack_98;
                    if (uStack_84 < 8) {
                      ppppuVar8 = &pppuStack_98;
                    }
                    *(undefined2 *)ppppuVar8 = 0;
                    uVar4 = uStack_b4;
                  }
                  goto LAB_00497be3;
                }
                iVar5 = FUN_00510ce0(*(undefined1 *)(iVar5 + 0xc));
                uVar4 = uStack_b4;
                if (iVar5 == 0) goto LAB_00497be3;
                piVar9 = (int *)(iVar6 + 4);
                if (7 < *(uint *)(iVar6 + 0x18)) {
                  piVar9 = (int *)*piVar9;
                }
                uVar11 = 0x58;
                FUN_005855b0(0x58,piVar9);
                FUN_00585330(uVar11);
                uVar11 = FUN_00498ef0();
                local_c = CONCAT31(local_c._1_3_,4);
                FUN_00402800(uVar11);
              }
              local_c._0_1_ = 2;
              FUN_004fa440();
              uVar4 = uStack_b4;
LAB_00497be3:
              if (1 < uStack_88) {
                ppppuVar8 = &pppuStack_98;
                FUN_0040f8c0(ppppuVar8);
                FUN_004d6b30(ppppuVar8);
                ppppuVar8 = (undefined4 ****)pppuStack_98;
                if (uStack_84 < 8) {
                  ppppuVar8 = &pppuStack_98;
                }
                uVar11 = FUN_0048a8c0(extraout_ECX_00,ppppuVar8);
                FUN_0056b7f0(uVar11,ppppuVar8);
              }
              local_c = 0xffffffff;
              param_1 = local_b8;
              if (7 < uStack_84) {
                FUN_0089120c(pppuStack_98);
                param_1 = local_b8;
              }
            }
            break;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < 3);
        if (*(int *)(uVar4 + 0x20) != 0) {
          bVar1 = *(byte *)(piStack_b0 + 0x2c);
          if ((DAT_00fb7c18 & 1) == 0) {
            DAT_00fb7c18 = DAT_00fb7c18 | 1;
            FUN_004449d0();
          }
          uStack_8c = *(undefined4 *)(uVar4 + 0x20);
          uStack_9c = (&DAT_00fb7c20)[bVar1];
          pppuStack_98 = (undefined4 ****)0x0;
          pcStack_94 = "Interrupt";
          uStack_90 = 0;
          uStack_88 = 0;
          if ((DAT_00fdf6dc & 1) == 0) {
            DAT_00fdf6dc = DAT_00fdf6dc | 1;
            local_c = 7;
            FUN_00550820();
            _atexit((_func_4879 *)&LAB_00bce6b0);
            local_c = 0xffffffff;
          }
          uVar12 = 0x3f800000;
          uVar11 = uStack_9c;
          uVar10 = (**(code **)(*piStack_b0 + 0x50))(auStack_7c,uStack_9c,0x3f800000);
          FUN_00551f20(*(undefined2 *)(local_b8 + 7),uVar10,uVar11,uVar12);
          param_1 = local_b8;
        }
      }
    }
    local_a8 = local_a8 + 1;
  } while( true );
}

