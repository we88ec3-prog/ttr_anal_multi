
void FUN_00416020(int param_1)

{
  void *pvVar1;
  undefined4 **ppuVar2;
  undefined4 **ppuVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *local_28;
  uint local_24;
  int local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00945954;
  local_14 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffffc8;
  ExceptionList = &local_14;
  puVar6 = (undefined4 *)(param_1 + 0x2b4);
  local_24 = 0xf;
  do {
    pvVar1 = (void *)puVar6[0x3b];
    if (pvVar1 != (void *)puVar6[0x3c]) {
      FID_conflict__memcpy(pvVar1,(void *)puVar6[0x3c],0);
      puVar6[0x3c] = pvVar1;
    }
    pvVar1 = (void *)puVar6[-1];
    if (pvVar1 != (void *)*puVar6) {
      FID_conflict__memcpy(pvVar1,(void *)*puVar6,0);
      *puVar6 = pvVar1;
    }
    puVar6 = puVar6 + 4;
    local_24 = local_24 + -1;
  } while (local_24 != 0);
  if ((DAT_00fb1350 & 1) == 0) {
    DAT_00fb1350 = DAT_00fb1350 | 1;
    local_c = 0;
    FUN_00511ca0(uVar4);
    _atexit((_func_4879 *)&LAB_00bccf40);
    local_c = 0xffffffff;
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  local_20 = DAT_00f93950;
  local_24 = 0;
  if (DAT_00fb135c - DAT_00fb1358 >> 2 != 0) {
    do {
      if ((DAT_00f94390 & 1) == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        local_c = 2;
        FUN_004e1590();
        _atexit((_func_4879 *)&LAB_00bccc80);
        local_c = 0xffffffff;
      }
      iVar7 = DAT_00f94308;
      puVar6 = *(undefined4 **)(DAT_00fb1358 + local_24 * 4);
      if ((DAT_00f8d9a4 & 1) == 0) {
        DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
        local_c = 3;
        FUN_0051c120();
        _atexit((_func_4879 *)&LAB_00bccc90);
        local_c = 0xffffffff;
      }
      iVar5 = FUN_0051d700(*puVar6);
      if ((puVar6[0xb] != 0) && ((puVar6[0xd] == 0 || (local_20 <= (int)puVar6[0xd])))) {
        if (puVar6[9] == 1) {
          local_28 = puVar6;
          if ((DAT_00f94390 & 1) == 0) {
            DAT_00f94390 = DAT_00f94390 | 1;
            local_c = 4;
            FUN_004e1590();
            _atexit((_func_4879 *)&LAB_00bccc80);
            local_c = 0xffffffff;
          }
          if ((puVar6[0xd] == 0) && ((int)puVar6[0xc] < DAT_00f93950)) {
            ppuVar2 = *(undefined4 ***)(param_1 + 0x484);
            if (&local_28 < ppuVar2) {
              ppuVar3 = *(undefined4 ***)(param_1 + 0x480);
              if (ppuVar3 <= &local_28) {
                if (ppuVar2 == *(undefined4 ***)(param_1 + 0x488)) {
                  FUN_004deab0();
                }
                if (*(undefined4 **)(param_1 + 0x484) != (undefined4 *)0x0) {
                  **(undefined4 **)(param_1 + 0x484) =
                       *(undefined4 *)
                        (*(int *)(param_1 + 0x480) + ((int)&local_28 - (int)ppuVar3 >> 2) * 4);
                }
                *(int *)(param_1 + 0x484) = *(int *)(param_1 + 0x484) + 4;
                goto LAB_004164fb;
              }
            }
            if (ppuVar2 == *(undefined4 ***)(param_1 + 0x488)) {
              FUN_004deab0();
            }
            if (*(int **)(param_1 + 0x484) != (int *)0x0) {
              **(int **)(param_1 + 0x484) = (int)puVar6;
            }
            *(int *)(param_1 + 0x484) = *(int *)(param_1 + 0x484) + 4;
          }
          else {
            ppuVar2 = *(undefined4 ***)(param_1 + 0x394);
            if (&local_28 < ppuVar2) {
              ppuVar3 = *(undefined4 ***)(param_1 + 0x390);
              if (ppuVar3 <= &local_28) {
                if (ppuVar2 == *(undefined4 ***)(param_1 + 0x398)) {
                  FUN_004deab0();
                }
                if (*(undefined4 **)(param_1 + 0x394) != (undefined4 *)0x0) {
                  **(undefined4 **)(param_1 + 0x394) =
                       *(undefined4 *)
                        (*(int *)(param_1 + 0x390) + ((int)&local_28 - (int)ppuVar3 >> 2) * 4);
                }
                *(int *)(param_1 + 0x394) = *(int *)(param_1 + 0x394) + 4;
                goto LAB_004164fb;
              }
            }
            if (ppuVar2 == *(undefined4 ***)(param_1 + 0x398)) {
              FUN_004deab0();
            }
            if (*(int **)(param_1 + 0x394) != (int *)0x0) {
              **(int **)(param_1 + 0x394) = (int)puVar6;
            }
            *(int *)(param_1 + 0x394) = *(int *)(param_1 + 0x394) + 4;
          }
        }
        else if (puVar6[9] == 2) {
          local_28 = puVar6;
          if ((DAT_00f94390 & 1) == 0) {
            DAT_00f94390 = DAT_00f94390 | 1;
            local_c = 5;
            FUN_004e1590();
            _atexit((_func_4879 *)&LAB_00bccc80);
            local_c = 0xffffffff;
          }
          if ((puVar6[0xd] == 0) && ((int)puVar6[0xc] < DAT_00f93950)) {
            FUN_00443d10();
          }
          else {
            ppuVar2 = *(undefined4 ***)(param_1 + 0x2d4);
            if (&local_28 < ppuVar2) {
              ppuVar3 = *(undefined4 ***)(param_1 + 0x2d0);
              if (ppuVar3 <= &local_28) {
                if (ppuVar2 == *(undefined4 ***)(param_1 + 0x2d8)) {
                  FUN_004deab0();
                }
                if (*(undefined4 **)(param_1 + 0x2d4) != (undefined4 *)0x0) {
                  **(undefined4 **)(param_1 + 0x2d4) =
                       *(undefined4 *)
                        (*(int *)(param_1 + 0x2d0) + ((int)&local_28 - (int)ppuVar3 >> 2) * 4);
                }
                *(int *)(param_1 + 0x2d4) = *(int *)(param_1 + 0x2d4) + 4;
                goto LAB_004164fb;
              }
            }
            if (ppuVar2 == *(undefined4 ***)(param_1 + 0x2d8)) {
              FUN_004deab0();
            }
            if (*(int **)(param_1 + 0x2d4) != (int *)0x0) {
              **(int **)(param_1 + 0x2d4) = (int)puVar6;
            }
            *(int *)(param_1 + 0x2d4) = *(int *)(param_1 + 0x2d4) + 4;
          }
        }
        else {
          switch(*(undefined4 *)(iVar5 + 8)) {
          case 9:
          case 0x21:
            break;
          default:
            break;
          case 0x11:
            break;
          case 0x12:
            break;
          case 0x13:
            break;
          case 0x1e:
            local_28 = (undefined4 *)(uint)*(ushort *)(iVar5 + 0x80);
            FUN_004dae30(&local_28);
            if (local_1c == *(int *)(iVar7 + 4)) {
              iVar7 = iVar7 + 0x30;
            }
            else {
              iVar7 = local_1c + 0x10;
            }
            if ((*(char *)(iVar7 + 0x39) == '\0') &&
               (FUN_00415f70(param_1,puVar6), *(char *)(iVar7 + 0x39) == '\0')) goto LAB_004164fb;
            break;
          case 0x20:
            break;
          case 0x24:
            break;
          case 0x25:
            break;
          case 0x26:
            break;
          case 0x27:
          }
          FUN_00415f70(param_1,puVar6);
        }
      }
LAB_004164fb:
      local_24 = local_24 + 1;
    } while (local_24 < (uint)(DAT_00fb135c - DAT_00fb1358 >> 2));
  }
  ExceptionList = local_14;
  return;
}

