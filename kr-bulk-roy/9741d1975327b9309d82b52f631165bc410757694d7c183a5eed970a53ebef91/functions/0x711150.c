
void FUN_00711150(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  int local_10;
  int local_c;
  int local_8;
  
  piVar1 = *(int **)(param_1 + 0x30);
  local_c = -1;
  local_8 = FUN_00711010();
  iVar2 = *(int *)(param_1 + 0x10);
  do {
    if (iVar2 != 0x105) {
      if (*(int *)(param_1 + 0x10) == 0x104) {
        piVar1[8] = -1;
        local_10 = FUN_00713370(0x7fff8016,*(undefined4 *)(piVar1[3] + 8));
        FUN_00711fe0();
        FUN_00711fe0();
        piVar1[7] = piVar1[6];
        FUN_00711fe0();
        *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 4);
        if (*(int *)(param_1 + 0x20) == 0x11f) {
          uVar4 = FUN_006ffec0(param_1 + 0x18);
          *(undefined4 *)(param_1 + 0x10) = uVar4;
        }
        else {
          *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x20);
          *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x24);
          *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x28);
          *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x2c);
          *(undefined4 *)(param_1 + 0x20) = 0x11f;
        }
        iVar2 = *(int *)(param_1 + 0x30);
        local_12 = 0;
        local_18 = 0xffffffff;
        local_14 = *(undefined1 *)(iVar2 + 0x32);
        local_13 = 0;
        local_1c = *(undefined4 *)(iVar2 + 0x14);
        *(undefined4 **)(iVar2 + 0x14) = &local_1c;
        FUN_00711b20(param_1);
        FUN_0070de40();
      }
      else {
        FUN_00711fe0();
      }
      piVar1[7] = piVar1[6];
      FUN_00711fe0();
      if (*(int *)(param_1 + 0x10) == 0x106) {
        *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 4);
        if (*(int *)(param_1 + 0x20) != 0x11f) {
          *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x20);
          *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x24);
          *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x28);
          *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x2c);
          *(undefined4 *)(param_1 + 0x20) = 0x11f;
          return;
        }
        uVar4 = FUN_006ffec0(param_1 + 0x18);
        *(undefined4 *)(param_1 + 0x10) = uVar4;
        return;
      }
      if (param_2 == *(int *)(param_1 + 4)) {
        uVar4 = FUN_006f7c30(*(undefined4 *)(param_1 + 0x34),"\'%s\' expected",&DAT_00c42cc0);
                    /* WARNING: Subroutine does not return */
        FUN_006ff130(param_1,uVar4,*(undefined4 *)(param_1 + 0x10));
      }
      uVar4 = FUN_006f7c30(*(undefined4 *)(param_1 + 0x34),
                           "\'%s\' expected (to close \'%s\' at line %d)",&DAT_00c42cc0,
                           &DAT_00c42cb8,param_2);
                    /* WARNING: Subroutine does not return */
      FUN_006ff130(param_1,uVar4,*(undefined4 *)(param_1 + 0x10));
    }
    iVar2 = piVar1[8];
    piVar1[8] = -1;
    local_10 = FUN_00713370(0x7fff8016,*(undefined4 *)(piVar1[3] + 8));
    iVar7 = local_10;
    if ((iVar2 != -1) && (iVar7 = iVar2, local_10 != -1)) {
      iVar6 = *(int *)(*piVar1 + 0xc);
      iVar7 = local_10;
      do {
        iVar5 = iVar7;
        uVar3 = *(uint *)(iVar6 + iVar5 * 4) >> 0xe;
        if (uVar3 == 0x1fffe) break;
        iVar7 = (uVar3 - 0x1fffe) + iVar5;
      } while (iVar7 != -1);
      uVar3 = (iVar2 - iVar5) - 1;
      uVar8 = (int)uVar3 >> 0x1f;
      if (0x1ffff < (int)((uVar3 ^ uVar8) - uVar8)) {
                    /* WARNING: Subroutine does not return */
        FUN_006ff130(piVar1[3],"control structure too long",*(undefined4 *)(piVar1[3] + 0x10));
      }
      *(uint *)(iVar6 + iVar5 * 4) =
           ((iVar2 - iVar5) + 0x1fffe) * 0x4000 ^ *(uint *)(iVar6 + iVar5 * 4) & 0x3fff;
      iVar7 = local_10;
    }
    iVar2 = local_c;
    if ((iVar7 != -1) && (iVar2 = iVar7, local_c != -1)) {
      iVar6 = *(int *)(*piVar1 + 0xc);
      iVar2 = local_c;
      do {
        iVar5 = iVar2;
        uVar3 = *(uint *)(iVar6 + iVar5 * 4) >> 0xe;
        if (uVar3 == 0x1fffe) break;
        iVar2 = (uVar3 - 0x1fffe) + iVar5;
      } while (iVar2 != -1);
      uVar3 = (iVar7 - iVar5) - 1;
      uVar8 = (int)uVar3 >> 0x1f;
      if (0x1ffff < (int)((uVar3 ^ uVar8) - uVar8)) {
                    /* WARNING: Subroutine does not return */
        FUN_006ff130(piVar1[3],"control structure too long",*(undefined4 *)(piVar1[3] + 0x10));
      }
      *(uint *)(iVar6 + iVar5 * 4) =
           ((iVar7 - iVar5) + 0x1fffe) * 0x4000 ^ *(uint *)(iVar6 + iVar5 * 4) & 0x3fff;
      iVar2 = local_c;
    }
    local_c = iVar2;
    piVar1[7] = piVar1[6];
    if (local_8 != -1) {
      if (piVar1[8] == -1) {
        piVar1[8] = local_8;
      }
      else {
        iVar7 = *(int *)(*piVar1 + 0xc);
        iVar2 = piVar1[8];
        do {
          iVar6 = iVar2;
          uVar3 = *(uint *)(iVar7 + iVar6 * 4) >> 0xe;
          if (uVar3 == 0x1fffe) break;
          iVar2 = (uVar3 - 0x1fffe) + iVar6;
        } while (iVar2 != -1);
        uVar3 = (local_8 - iVar6) - 1;
        uVar8 = (int)uVar3 >> 0x1f;
        if (0x1ffff < (int)((uVar3 ^ uVar8) - uVar8)) {
                    /* WARNING: Subroutine does not return */
          FUN_006ff130(piVar1[3],"control structure too long",*(undefined4 *)(piVar1[3] + 0x10));
        }
        *(uint *)(iVar7 + iVar6 * 4) =
             ((local_8 - iVar6) + 0x1fffe) * 0x4000 ^ *(uint *)(iVar7 + iVar6 * 4) & 0x3fff;
      }
    }
    local_8 = FUN_00711010();
    iVar2 = *(int *)(param_1 + 0x10);
  } while( true );
}

