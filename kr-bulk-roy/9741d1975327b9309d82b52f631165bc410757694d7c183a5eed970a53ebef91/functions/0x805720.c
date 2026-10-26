
undefined4 FUN_00805720(uint *param_1)

{
  int *piVar1;
  int *piVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined **local_28 [3];
  char *local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puVar3 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00909a0b;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  EnterCriticalSection((LPCRITICAL_SECTION)param_1[0xd]);
  local_18 = 0;
  do {
    iVar5 = FUN_00891268(0xa0d8,uVar4);
    local_8 = 0;
    if (iVar5 == 0) {
      param_1 = (uint *)0x0;
    }
    else {
      param_1 = (uint *)FUN_00805ca0(iVar5);
    }
    local_8 = 0xffffffff;
    *(uint *)((int)param_1 + 0xa0c8) = puVar3[0xe];
    *(uint *)((int)param_1 + 0xa0cc) = puVar3[0xf];
    *(uint *)((int)param_1 + 0xa0d0) = puVar3[0x10];
    local_14 = (int)param_1;
    if (((puVar3[7] + puVar3[8] & 3) == 0) && (puVar3[6] <= puVar3[8] + 4 >> 2)) {
      FUN_00636f70(puVar3 + 4);
    }
    uVar6 = puVar3[7];
    uVar7 = puVar3[8];
    uVar8 = uVar6 + uVar7 >> 2;
    if (puVar3[6] <= uVar8) {
      uVar8 = uVar8 - puVar3[6];
    }
    if (*(int *)(puVar3[5] + uVar8 * 4) == 0) {
      iVar5 = FUN_00891268(0x10);
      if (iVar5 == 0) {
        local_1c = (char *)0x0;
        std::exception::exception((exception *)local_28,&local_1c);
        local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(local_28,&DAT_00c857a8);
      }
      *(int *)(puVar3[5] + uVar8 * 4) = iVar5;
    }
    piVar1 = (int *)(*(int *)(puVar3[5] + uVar8 * 4) + (uVar6 + uVar7 & 3) * 4);
    if (piVar1 != (int *)0x0) {
      *piVar1 = (int)param_1;
    }
    puVar3[8] = puVar3[8] + 1;
    piVar1 = (int *)puVar3[1];
    if ((&local_14 < piVar1) && (piVar2 = (int *)*puVar3, piVar2 <= &local_14)) {
      if (piVar1 == (int *)puVar3[2]) {
        uVar6 = (int)piVar1 - (int)piVar2 >> 2;
        if (0x3ffffffe < uVar6) {
LAB_0080593d:
                    /* WARNING: Subroutine does not return */
          FUN_0087db30("vector<T> too long");
        }
        uVar6 = uVar6 + 1;
        uVar7 = (int)puVar3[2] - (int)piVar2 >> 2;
        if (uVar7 < uVar6) {
          if (0x3fffffff - (uVar7 >> 1) < uVar7) {
            uVar7 = 0;
          }
          else {
            uVar7 = uVar7 + (uVar7 >> 1);
          }
          if (uVar7 < uVar6) {
            uVar7 = uVar6;
          }
          FUN_00797980(uVar7);
        }
      }
      if ((undefined4 *)puVar3[1] != (undefined4 *)0x0) {
        *(undefined4 *)puVar3[1] =
             *(undefined4 *)(*puVar3 + ((int)&local_14 - (int)piVar2 >> 2) * 4);
      }
    }
    else {
      if (piVar1 == (int *)puVar3[2]) {
        uVar6 = (int)((int)piVar1 - *puVar3) >> 2;
        if (0x3ffffffe < uVar6) goto LAB_0080593d;
        uVar6 = uVar6 + 1;
        uVar7 = (int)((int)puVar3[2] - *puVar3) >> 2;
        if (uVar7 < uVar6) {
          if (0x3fffffff - (uVar7 >> 1) < uVar7) {
            uVar7 = 0;
          }
          else {
            uVar7 = uVar7 + (uVar7 >> 1);
          }
          if (uVar7 < uVar6) {
            uVar7 = uVar6;
          }
          FUN_00797980(uVar7);
        }
      }
      if ((int *)puVar3[1] != (int *)0x0) {
        *(int *)puVar3[1] = (int)param_1;
      }
    }
    puVar3[1] = puVar3[1] + 4;
    local_18 = local_18 + 1;
    if (2 < local_18) {
      LeaveCriticalSection((LPCRITICAL_SECTION)puVar3[0xd]);
      ExceptionList = local_10;
      return 1;
    }
  } while( true );
}

