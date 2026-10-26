
void FUN_0061bfd0(int param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  int *in_ECX;
  uint uVar8;
  int *piVar9;
  int iVar10;
  int *local_24;
  int local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00946aa4;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  uVar2 = *(uint *)(param_1 + 0x10);
  if (uVar2 < 0x642) {
    if (uVar2 == 0x641) {
      if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x45] + 0x20)) {
        uVar6 = FUN_0075cdd0();
        if (in_ECX[0x3f] == 0) {
          in_ECX[0x85] = 0;
          FUN_00823850();
          FUN_0061c660();
          (**(code **)(*in_ECX + 200))();
          iVar10 = FUN_0075cdd0();
          in_ECX[0x87] = iVar10;
          ExceptionList = local_14;
          return;
        }
        FUN_0075cd30();
        (**(code **)(*(int *)in_ECX[0x45] + 200))();
        puVar5 = (undefined4 *)FUN_00891268();
        if (puVar5 != (undefined4 *)0x0) {
          puVar5[1] = 0xffffffff;
          puVar5[2] = 0xffffffff;
          puVar5[3] = 0;
          puVar5[4] = 0xf4431;
          *puVar5 = FoxUI::FXUIEventI1::vftable;
          puVar5[5] = uVar6;
        }
        FUN_005854b0();
        FUN_00585330();
        FUN_00404b10();
        ExceptionList = local_14;
        return;
      }
    }
    else {
      if (uVar2 == 0x578) {
        iVar10 = *(int *)(param_1 + 8);
        if (iVar10 == *(int *)(in_ECX[0x41] + 0x20)) {
          if (in_ECX[0x3f] != 0) {
            puVar5 = (undefined4 *)FUN_00891268();
            if (puVar5 != (undefined4 *)0x0) {
              *puVar5 = FoxUI::FXUIEvent::vftable;
              puVar5[1] = 0xffffffff;
              puVar5[2] = 0xffffffff;
              puVar5[3] = 0;
              puVar5[4] = 0xf43b5;
            }
            FUN_005854b0();
            FUN_00585330();
            FUN_00402250();
            local_c = 2;
            FUN_005854b0();
            uVar6 = FUN_00585330();
            FUN_00402250(uVar6);
            local_c = 0xffffffff;
            FUN_0058b270(0xcf);
          }
        }
        else if (iVar10 == *(int *)(in_ECX[0x43] + 0x20)) {
          FUN_0061ccd0();
          (**(code **)(*in_ECX + 0xd4))();
        }
        else if (iVar10 == *(int *)(in_ECX[0x42] + 0x20)) {
          FUN_0061ccd0();
          FUN_0061c660();
          (**(code **)(*in_ECX + 200))();
        }
        FUN_00443dc0();
        iVar10 = FUN_006f1b90();
        if (iVar10 == 0) {
          FUN_00443dc0();
          iVar10 = FUN_006f1b90();
          if (iVar10 == 0) {
            ExceptionList = local_14;
            return;
          }
        }
        piVar1 = in_ECX + 0x46;
        iVar10 = 0;
        do {
          iVar7 = 0;
          piVar9 = piVar1;
          do {
            if (*(int *)(param_1 + 8) == *(int *)(*piVar9 + 0x20)) {
              FUN_0061dd30();
              break;
            }
            iVar7 = iVar7 + 1;
            piVar9 = piVar9 + 1;
          } while (iVar7 < 7);
          iVar10 = iVar10 + 1;
          piVar1 = piVar1 + 7;
          if (2 < iVar10) {
            ExceptionList = local_14;
            return;
          }
        } while( true );
      }
      if (uVar2 == 0x57a) {
        local_24 = in_ECX + 0x46;
        local_1c = 0x46;
LAB_0061c273:
        iVar10 = 0;
        piVar1 = local_24;
        do {
          if (*(int *)(param_1 + 8) == *(int *)(*piVar1 + 0x20)) {
            if ((DAT_00f94390 & 1) == 0) {
              DAT_00f94390 = DAT_00f94390 | 1;
              local_c = 0;
              FUN_004e1590();
              _atexit((_func_4879 *)&LAB_00bccc80);
              local_c = 0xffffffff;
            }
            if ((uint)in_ECX[0x86] < 10) {
              uVar2 = DAT_00f94304 + in_ECX[0x86] * 0x210;
              uVar2 = -(uint)(*(int *)(uVar2 + 0x5c) != 0) & uVar2;
            }
            else {
              uVar2 = 0;
            }
            if (uVar2 != 0) {
              piVar1 = *(int **)(uVar2 + 0xfc);
              uVar2 = *(int *)(uVar2 + 0x100) - (int)piVar1 >> 3;
              uVar4 = 0;
              if (uVar2 == 0) goto LAB_0061c32e;
              goto LAB_0061c320;
            }
            break;
          }
          iVar10 = iVar10 + 1;
          piVar1 = piVar1 + 1;
        } while (iVar10 < 7);
        goto LAB_0061c344;
      }
      if (uVar2 == 0x58c) {
        local_24 = in_ECX + 0x46;
        local_20 = 0x46;
LAB_0061c054:
        iVar10 = 0;
        piVar1 = local_24;
        do {
          if (*(int *)(param_1 + 8) == *(int *)(*piVar1 + 0x20)) {
            if ((DAT_00f94390 & 1) == 0) {
              DAT_00f94390 = DAT_00f94390 | 1;
              local_c = 1;
              FUN_004e1590();
              _atexit((_func_4879 *)&LAB_00bccc80);
              local_c = 0xffffffff;
            }
            if ((uint)in_ECX[0x86] < 10) {
              uVar2 = in_ECX[0x86] * 0x210 + DAT_00f94304;
              uVar2 = -(uint)(*(int *)(uVar2 + 0x5c) != 0) & uVar2;
            }
            else {
              uVar2 = 0;
            }
            iVar7 = *(int *)(in_ECX[local_20 + iVar10] + 0x248);
            if (DAT_00fba80c == 0) {
              iVar3 = FUN_00891268();
              if (iVar3 == 0) {
                DAT_00fba80c = 0;
              }
              else {
                DAT_00fba80c = FUN_006f1370();
              }
            }
            if ((*(int *)(DAT_00fba80c + 0x20) != 0) &&
               ((*(char *)(DAT_00fba80c + 0x17d) != '\0' ||
                ((*(int *)(DAT_00fba80c + 0x20) != 0 && (*(char *)(DAT_00fba80c + 0x1fd) != '\0'))))
               )) {
              piVar1 = *(int **)(uVar2 + 0xfc);
              uVar4 = *(int *)(uVar2 + 0x100) - (int)piVar1 >> 3;
              uVar8 = 0;
              piVar9 = piVar1;
              if (uVar4 == 0) goto LAB_0061c196;
              goto LAB_0061c182;
            }
            FUN_0041d5c0();
            FUN_0061cf40();
            break;
          }
          iVar10 = iVar10 + 1;
          piVar1 = piVar1 + 1;
        } while (iVar10 < 7);
        goto LAB_0061c20d;
      }
    }
  }
  else if (uVar2 == 0xf43b5) {
    iVar10 = FUN_004068c0();
    if (*(int *)(iVar10 + 0x14) == 0x6a7) {
      FUN_0061d360();
      (**(code **)(*in_ECX + 200))();
    }
  }
  else if (uVar2 == 0xf4431) {
    FUN_0061d5c0();
    ExceptionList = local_14;
    return;
  }
  ExceptionList = local_14;
  return;
  while( true ) {
    uVar4 = uVar4 + 1;
    piVar1 = piVar1 + 2;
    if (uVar2 <= uVar4) break;
LAB_0061c320:
    if (*piVar1 == *(int *)(in_ECX[local_1c + iVar10] + 0x248)) break;
  }
LAB_0061c32e:
  FUN_0061ccf0();
LAB_0061c344:
  local_24 = local_24 + 7;
  local_1c = local_1c + 7;
  if (0x5a < local_1c) {
    ExceptionList = local_14;
    return;
  }
  goto LAB_0061c273;
  while( true ) {
    uVar8 = uVar8 + 1;
    piVar9 = piVar9 + 2;
    if (uVar4 <= uVar8) break;
LAB_0061c182:
    if (*piVar9 == iVar7) {
      uVar4 = (uint)*(ushort *)(piVar1 + uVar8 * 2 + 1);
      goto LAB_0061c198;
    }
  }
LAB_0061c196:
  uVar4 = 0;
LAB_0061c198:
  if ((uVar4 & 0xff) < (uint)*(byte *)(in_ECX[local_20 + iVar10] + 0x250)) {
    local_1c = (uint)*(byte *)(in_ECX[local_20 + iVar10] + 0x250) - (uVar4 & 0xff);
    do {
      piVar1 = *(int **)(uVar2 + 0xfc);
      uVar4 = *(int *)(uVar2 + 0x100) - (int)piVar1 >> 3;
      if (uVar4 != 0) {
        uVar8 = 0;
        do {
          if (*piVar1 == iVar7) break;
          uVar8 = uVar8 + 1;
          piVar1 = piVar1 + 2;
        } while (uVar8 < uVar4);
      }
      FUN_0061cf40();
      local_1c = local_1c + -1;
    } while (local_1c != 0);
  }
LAB_0061c20d:
  local_24 = local_24 + 7;
  local_20 = local_20 + 7;
  if (0x5a < local_20) {
    ExceptionList = local_14;
    return;
  }
  goto LAB_0061c054;
}

