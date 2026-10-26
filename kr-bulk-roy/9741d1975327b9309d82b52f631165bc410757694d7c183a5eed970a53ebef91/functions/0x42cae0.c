
void FUN_0042cae0(void)

{
  int iVar1;
  undefined ***pppuVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined **ppuVar5;
  int *piVar6;
  int in_ECX;
  undefined *puVar7;
  int iVar8;
  int iVar9;
  undefined *puVar10;
  undefined **local_58;
  undefined **local_54 [7];
  uint local_38;
  undefined4 local_30;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00931d60;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00755e50(local_14);
  FUN_00615fc0(100);
  FUN_00615fc0(200);
  FUN_0044dd40(0x136);
  FUN_0044dd40(0x19a);
  FUN_0042e590();
  FUN_006a9e80(0x262);
  FUN_006a9e80(0x26c);
  FUN_0043c570(700);
  local_54[1] = (undefined **)(in_ECX + 0x11c);
  local_54[0] = &PTR_DAT_00d6a224;
  local_58 = (undefined **)0x2c7;
  do {
    ppuVar5 = local_54[1];
    FUN_0043c570((int)local_58 + -1);
    FUN_0044dd40(local_58);
    FUN_00757710();
    local_54[0] = local_54[0] + 1;
    *(undefined4 *)(*ppuVar5 + 0x144) = 2;
    local_58 = (undefined **)((int)local_58 + 10);
    local_54[1] = ppuVar5 + 1;
  } while ((int)local_58 < 0x2e5);
  *(int *)(in_ECX + 0x128) = *(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0xc);
  *(int *)(in_ECX + 300) =
       (*(int *)(*(int *)(in_ECX + 0x10c) + 0x14) - *(int *)(*(int *)(in_ECX + 0x10c) + 0xc)) + 8;
  *(undefined4 *)(*(int *)(in_ECX + 0xf8) + 0x144) = 0x10;
  *(undefined4 *)(*(int *)(in_ECX + 0xfc) + 0x144) = 1;
  iVar8 = *(int *)(*(int *)(in_ECX + 0x100) + 0x24c);
  if ((iVar8 != 0) && (iVar8 = *(int *)(iVar8 + 0xcc), iVar8 != 0)) {
    FUN_006438f0(iVar8);
  }
  FUN_00757710();
  local_58 = &PTR_DAT_00d6a218;
  do {
    iVar8 = *(int *)(in_ECX + 0x100);
    iVar1 = *(int *)(iVar8 + 0x24c);
    if (iVar1 != 0) {
      piVar6 = *(int **)(iVar1 + 0xcc);
      if (piVar6 == (int *)0x0) {
        puVar10 = (undefined *)0xffffffff;
      }
      else {
        puVar10 = (undefined *)piVar6[0x39];
        if ((int *)piVar6[0x29] == (int *)0x0) {
          puVar10 = (undefined *)0xffffffff;
        }
        else {
          iVar1 = *(int *)piVar6[0x29];
          if (piVar6[0x2e] == piVar6[0x2f]) {
            local_54[1] = (undefined **)(**(code **)(iVar1 + 0x28))();
          }
          else {
            local_54[1] = *(undefined ***)(piVar6[0x2f] + -4);
            (**(code **)(iVar1 + 0x2c))(local_54[1]);
            if (piVar6[0x2e] != piVar6[0x2f]) {
              piVar6[0x2f] = piVar6[0x2f] + -4;
            }
          }
          local_54[1][8] = puVar10;
          local_54[0] = local_54[1];
          (**(code **)(*piVar6 + 0x70))(local_54[1]);
          pppuVar2 = (undefined ***)piVar6[0x2b];
          if (local_54 < pppuVar2) {
            if (local_54 < (undefined ***)piVar6[0x2a]) goto LAB_0042cd75;
            local_54[1] = (undefined **)((int)local_54 - piVar6[0x2a] >> 2);
            if (pppuVar2 == (undefined ***)piVar6[0x2c]) {
              FUN_004deab0();
            }
            if ((undefined4 *)piVar6[0x2b] != (undefined4 *)0x0) {
              *(undefined4 *)piVar6[0x2b] = *(undefined4 *)(piVar6[0x2a] + (int)local_54[1] * 4);
            }
          }
          else {
LAB_0042cd75:
            if (pppuVar2 == (undefined ***)piVar6[0x2c]) {
              FUN_004deab0();
            }
            if ((undefined4 *)piVar6[0x2b] != (undefined4 *)0x0) {
              *(undefined4 *)piVar6[0x2b] = local_54[1];
            }
          }
          piVar6[0x2b] = piVar6[0x2b] + 4;
          puVar7 = puVar10 + 1;
          if (puVar10 + 1 <= (undefined *)piVar6[0x39]) {
            puVar7 = (undefined *)piVar6[0x39];
          }
          piVar6[0x39] = (int)puVar7;
        }
      }
      iVar8 = *(int *)(*(int *)(iVar8 + 0x24c) + 0xcc);
      if (iVar8 != 0) {
        for (piVar6 = *(int **)(iVar8 + 0xa8);
            (piVar6 != *(int **)(iVar8 + 0xac) && (*(undefined **)(*piVar6 + 0x20) != puVar10));
            piVar6 = piVar6 + 1) {
        }
      }
      FUN_00757710();
    }
    local_58 = local_58 + 1;
    if (0xd6a223 < (int)local_58) {
      FUN_00749c50();
      FUN_00749d00();
      piVar6 = *(int **)(*(int *)(in_ECX + 0x100) + 0x24c);
      if (piVar6 != (int *)0x0) {
        puVar3 = (undefined4 *)piVar6[0x19];
        for (puVar4 = (undefined4 *)*puVar3; puVar4 != puVar3; puVar4 = (undefined4 *)*puVar4) {
          iVar8 = puVar4[2];
          if ((*(int *)(iVar8 + 0x60) != 0) && ((*(int **)(iVar8 + 0x1c))[2] != 6)) {
            (**(code **)(**(int **)(iVar8 + 0x1c) + 0x30))(iVar8);
          }
        }
        (**(code **)(*piVar6 + 0x128))();
      }
      (**(code **)(**(int **)(in_ECX + 0x100) + 200))();
      FUN_0075cc70(*(undefined4 *)(in_ECX + 0x100),PTR_DAT_00d6a218);
      (**(code **)(**(int **)(in_ECX + 0x10c) + 0x94))(0);
      FUN_00749d00();
      iVar8 = *(int *)(*(int *)(in_ECX + 0x10c) + 0xc);
      iVar1 = *(int *)(*(int *)(in_ECX + 0x104) + 0x44);
      iVar9 = *(int *)(*(int *)(in_ECX + 0x10c) + 8) - *(int *)(iVar1 + 8);
      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + iVar9;
      *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + iVar9;
      iVar8 = iVar8 - *(int *)(iVar1 + 0xc);
      *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + iVar8;
      *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + iVar8;
      *(undefined4 *)(iVar1 + 0x2c) = *(undefined4 *)(iVar1 + 8);
      *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(iVar1 + 0xc);
      *(undefined4 *)(iVar1 + 0x34) = *(undefined4 *)(iVar1 + 0x10);
      *(undefined4 *)(iVar1 + 0x38) = *(undefined4 *)(iVar1 + 0x14);
      if (*(int *)(iVar1 + 0x60) != 0) {
        iVar8 = *(int *)(*(int *)(iVar1 + 0x60) + 0x2c);
        *(int *)(iVar1 + 0x2c) = *(int *)(iVar1 + 0x2c) + iVar8;
        *(int *)(iVar1 + 0x34) = *(int *)(iVar1 + 0x34) + iVar8;
        iVar8 = *(int *)(*(int *)(iVar1 + 0x60) + 0x30);
        *(int *)(iVar1 + 0x30) = *(int *)(iVar1 + 0x30) + iVar8;
        *(int *)(iVar1 + 0x38) = *(int *)(iVar1 + 0x38) + iVar8;
      }
      puVar3 = *(undefined4 **)(iVar1 + 100);
      for (puVar4 = (undefined4 *)*puVar3; puVar4 != puVar3; puVar4 = (undefined4 *)*puVar4) {
        FUN_00746f70();
      }
      (**(code **)(**(int **)(in_ECX + 0x104) + 0xa0))(1);
      (**(code **)(**(int **)(in_ECX + 0x108) + 0xa0))(0);
      FUN_0042e680();
      local_8 = 0;
      iVar8 = *(int *)(in_ECX + 0xfc);
      if (*(char *)(iVar8 + 0x141) == '\0') {
        FUN_00757710();
      }
      else {
        FUN_006edb10("Not supported operation");
      }
      *(undefined4 *)(iVar8 + 0x168) = 0;
      *(undefined4 *)(iVar8 + 0x160) = 0;
      *(undefined4 *)(iVar8 + 0x164) = 0;
      *(undefined4 *)(iVar8 + 0x14c) = 0;
      local_8 = 0xffffffff;
      if (7 < local_38) {
        FUN_0089120c(local_54[2]);
      }
      local_54[1] = (undefined **)(in_ECX + 0x11c);
      local_54[0] = (undefined **)0x0;
      do {
        FUN_00426ec0();
        local_8 = 1;
        iVar8 = (int)*local_54[1];
        if (*(char *)(iVar8 + 0x141) == '\0') {
          FUN_00757710();
        }
        else {
          FUN_006edb10("Not supported operation");
        }
        *(undefined4 *)(iVar8 + 0x168) = 0;
        *(undefined4 *)(iVar8 + 0x160) = 0;
        *(undefined4 *)(iVar8 + 0x164) = 0;
        *(undefined4 *)(iVar8 + 0x14c) = 0;
        local_8 = 0xffffffff;
        if (7 < local_1c) {
          FUN_0089120c(local_30);
        }
        local_54[1] = local_54[1] + 1;
        local_54[0] = (undefined **)((int)local_54[0] + 1);
      } while ((int)local_54[0] < 3);
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
  } while( true );
}

