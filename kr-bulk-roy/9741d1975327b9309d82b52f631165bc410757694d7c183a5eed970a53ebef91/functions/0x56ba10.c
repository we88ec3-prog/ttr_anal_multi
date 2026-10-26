
void FUN_0056ba10(void)

{
  short *psVar1;
  short sVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  short *psVar7;
  int *in_ECX;
  int *local_2c;
  uint local_24;
  undefined4 local_20;
  int *local_1c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00921f28;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fb7bc8 & 1) == 0) {
    DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
    local_8 = 0;
    FUN_00734ef0(uVar4);
    _atexit((_func_4879 *)&LAB_00bcd4f0);
  }
  local_20 = DAT_00fb7b90;
  if ((DAT_00fb7bc8 & 1) == 0) {
    DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
    local_8 = 1;
    FUN_00734ef0(uVar4);
    _atexit((_func_4879 *)&LAB_00bcd4f0);
  }
  local_8 = 0xffffffff;
  iVar5 = *in_ECX;
  local_14 = iVar5;
  FUN_00736180(&local_14);
  if ((local_18 == DAT_00fb7b80) || (DAT_00fb7b90 = iVar5, local_18 == (int *)0xfffffff0)) {
    DAT_00fb7b90 = DAT_00fb7b8c;
  }
  iVar5 = FUN_006dfc40();
  iVar5 = (*(uint *)(iVar5 + 0x1c) >> 1) - in_ECX[8];
  local_1c = in_ECX + 1;
  local_14 = iVar5;
  FUN_00542210();
  iVar6 = FUN_004d8460();
  if (local_24 != *(uint *)(iVar6 + 8)) {
    do {
      if (local_2c == (int *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = *local_2c;
      }
      uVar4 = local_24;
      if (*(uint *)(iVar6 + 8) <= local_24) {
        uVar4 = local_24 - *(uint *)(iVar6 + 8);
      }
      psVar7 = *(short **)(*(int *)(iVar6 + 4) + uVar4 * 4);
      psVar1 = psVar7 + 1;
      do {
        sVar2 = *psVar7;
        psVar7 = psVar7 + 1;
      } while (sVar2 != 0);
      if ((int)psVar7 - (int)psVar1 >> 1 == 0) {
        if (local_2c == (int *)0x0) {
          iVar6 = 0;
        }
        else {
          iVar6 = *local_2c;
        }
        uVar4 = local_24;
        if (*(uint *)(iVar6 + 8) <= local_24) {
          uVar4 = local_24 - *(uint *)(iVar6 + 8);
        }
        if (0.0 < *(float *)(*(int *)(*(int *)(iVar6 + 4) + uVar4 * 4) + 0x208)) goto LAB_0056bb78;
      }
      else {
LAB_0056bb78:
        if (DAT_00fba7cc == 0) {
          iVar5 = FUN_00891268(0x1380);
          if (iVar5 == 0) {
            DAT_00fba7cc = 0;
          }
          else {
            DAT_00fba7cc = FUN_006df3d0();
          }
        }
        if ((DAT_00d63d09 != '\0') &&
           (EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8), DAT_00d63d09 != '\0')) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
        }
        if (local_2c == (int *)0x0) {
          iVar5 = 0;
        }
        else {
          iVar5 = *local_2c;
        }
        uVar4 = local_24;
        if (*(uint *)(iVar5 + 8) <= local_24) {
          uVar4 = local_24 - *(uint *)(iVar5 + 8);
        }
        local_18 = *(int **)(*(int *)(iVar5 + 4) + uVar4 * 4);
        if (local_2c == (int *)0x0) {
          iVar5 = 0;
        }
        else {
          iVar5 = *local_2c;
        }
        uVar4 = local_24;
        if (*(uint *)(iVar5 + 8) <= local_24) {
          uVar4 = local_24 - *(uint *)(iVar5 + 8);
        }
        iVar5 = *(int *)(*(int *)(iVar5 + 4) + uVar4 * 4);
        if (local_2c == (int *)0x0) {
          iVar6 = 0;
        }
        else {
          iVar6 = *local_2c;
        }
        uVar4 = local_24;
        if (*(uint *)(iVar6 + 8) <= local_24) {
          uVar4 = local_24 - *(uint *)(iVar6 + 8);
        }
        uVar3 = *(undefined4 *)(*(int *)(iVar6 + 4) + uVar4 * 4);
        if ((DAT_00fb7bc8 & 1) == 0) {
          DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
          local_8 = 2;
          FUN_00734ef0();
          _atexit((_func_4879 *)&LAB_00bcd4f0);
          local_8 = 0xffffffff;
        }
        FUN_00735c90(0,uVar3,(int)(float)local_18[0x82] << 0x18 |
                             *(uint *)(iVar5 + 0x200) & 0xffffff,0xff000000);
        iVar5 = local_14;
      }
      iVar5 = iVar5 + 0x14;
      local_24 = local_24 + 1;
      local_14 = iVar5;
      iVar6 = FUN_004d8460();
    } while (local_24 != *(uint *)(iVar6 + 8));
  }
  if ((DAT_00fb7bc8 & 1) == 0) {
    DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
    local_8 = 3;
    FUN_00734ef0();
    _atexit((_func_4879 *)&LAB_00bcd4f0);
  }
  uVar3 = local_20;
  FUN_00736180(&local_20);
  if ((local_1c != DAT_00fb7b80) && (local_1c != (int *)0xfffffff0)) {
    DAT_00fb7b90 = uVar3;
    ExceptionList = local_10;
    return;
  }
  DAT_00fb7b90 = DAT_00fb7b8c;
  ExceptionList = local_10;
  return;
}

