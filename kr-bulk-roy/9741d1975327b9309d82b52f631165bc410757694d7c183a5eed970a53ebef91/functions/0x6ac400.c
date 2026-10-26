
void FUN_006ac400(void)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  int **ppiVar4;
  int **ppiVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  int *piVar9;
  uint uVar10;
  int iVar11;
  int *piVar12;
  short *psVar13;
  int in_ECX;
  short *psVar14;
  uint local_80;
  int *local_78 [2];
  int local_70;
  int *local_6c;
  uint local_68;
  undefined4 local_58;
  uint local_54;
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092c388;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar9 = (int *)FUN_0048a740(local_14);
  iVar11 = *(int *)(*(int *)(in_ECX + 0xec) + 0xcc);
  uVar8 = (piVar9[1] - *piVar9) / 0x33;
  if (iVar11 != 0) {
    FUN_006438f0(iVar11);
  }
  local_80 = 0;
  if (uVar8 != 0) {
    local_70 = 0;
    local_78[1] = (int *)(in_ECX + 0xf0);
    do {
      piVar2 = *(int **)(*(int *)(in_ECX + 0xec) + 0xcc);
      if (piVar2 == (int *)0x0) {
LAB_006ac5d3:
        piVar12 = (int *)0x0;
      }
      else {
        iVar11 = piVar2[0x39];
        if ((int *)piVar2[0x29] == (int *)0x0) goto LAB_006ac5d3;
        iVar3 = *(int *)piVar2[0x29];
        if (piVar2[0x2e] == piVar2[0x2f]) {
          local_6c = (int *)(**(code **)(iVar3 + 0x28))();
        }
        else {
          local_6c = *(int **)(piVar2[0x2f] + -4);
          (**(code **)(iVar3 + 0x2c))(local_6c);
          if (piVar2[0x2e] != piVar2[0x2f]) {
            piVar2[0x2f] = piVar2[0x2f] + -4;
          }
        }
        piVar12 = local_6c;
        local_6c[8] = iVar11;
        local_78[0] = local_6c;
        (**(code **)(*piVar2 + 0x70))(local_6c);
        ppiVar4 = (int **)piVar2[0x2b];
        if (local_78 < ppiVar4) {
          ppiVar5 = (int **)piVar2[0x2a];
          if (local_78 < ppiVar5) goto LAB_006ac566;
          if (ppiVar4 == (int **)piVar2[0x2c]) {
            FUN_004deab0();
          }
          piVar12 = local_6c;
          if ((undefined4 *)piVar2[0x2b] != (undefined4 *)0x0) {
            *(undefined4 *)piVar2[0x2b] =
                 *(undefined4 *)(piVar2[0x2a] + ((int)local_78 - (int)ppiVar5 >> 2) * 4);
          }
        }
        else {
LAB_006ac566:
          if (ppiVar4 == (int **)piVar2[0x2c]) {
            FUN_004deab0();
          }
          if ((undefined4 *)piVar2[0x2b] != (undefined4 *)0x0) {
            *(undefined4 *)piVar2[0x2b] = piVar12;
          }
        }
        piVar2[0x2b] = piVar2[0x2b] + 4;
        uVar10 = iVar11 + 1;
        if (uVar10 <= (uint)piVar2[0x39]) {
          uVar10 = piVar2[0x39];
        }
        piVar2[0x39] = uVar10;
        iVar11 = (**(code **)(*piVar12 + 4))();
        if (iVar11 != 0x12d) {
          MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
          goto LAB_006ac5d3;
        }
      }
      piVar2 = local_78[1];
      *local_78[1] = (int)piVar12;
      FUN_00420070();
      local_8 = 0;
      local_1c = 7;
      psVar14 = (short *)(*piVar9 + local_70 + 4);
      local_20 = 0;
      local_30 = local_30 & 0xffff0000;
      psVar13 = psVar14;
      do {
        sVar1 = *psVar13;
        psVar13 = psVar13 + 1;
      } while (sVar1 != 0);
      FUN_00402160(psVar14,(int)psVar13 - (*piVar9 + local_70 + 6) >> 1);
      local_8._0_1_ = 1;
      FUN_00757710();
      FUN_00757710();
      FUN_00412df0();
      local_8 = CONCAT31(local_8._1_3_,2);
      FUN_00757710();
      if (7 < local_54) {
        FUN_0089120c(local_68);
      }
      local_54 = 7;
      local_58 = 0;
      local_68 = local_68 & 0xffff0000;
      if (7 < local_1c) {
        FUN_0089120c(local_30);
      }
      local_8 = 0xffffffff;
      local_1c = 7;
      local_20 = 0;
      local_30 = local_30 & 0xffff0000;
      if (7 < local_38) {
        FUN_0089120c(local_4c);
      }
      local_70 = local_70 + 0x33;
      local_80 = local_80 + 1;
      local_78[1] = piVar2 + 1;
      local_38 = 7;
      local_3c = 0;
      local_4c = local_4c & 0xffff0000;
    } while (local_80 < uVar8);
  }
  piVar9 = *(int **)(in_ECX + 0xec);
  puVar6 = (undefined4 *)piVar9[0x19];
  for (puVar7 = (undefined4 *)*puVar6; puVar7 != puVar6; puVar7 = (undefined4 *)*puVar7) {
    iVar11 = puVar7[2];
    if ((*(int *)(iVar11 + 0x60) != 0) && ((*(int **)(iVar11 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar11 + 0x1c) + 0x30))(iVar11);
    }
  }
  (**(code **)(*piVar9 + 0x128))();
  (**(code **)(**(int **)(in_ECX + 0xec) + 200))();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

