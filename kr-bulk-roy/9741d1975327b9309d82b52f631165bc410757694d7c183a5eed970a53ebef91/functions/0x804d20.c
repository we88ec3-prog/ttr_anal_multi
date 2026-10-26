
void FUN_00804d20(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 **ppuVar5;
  undefined4 **ppuVar6;
  undefined4 *_ArgList;
  HANDLE pvVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  _union_530 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  uint local_c;
  undefined4 *local_8;
  
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_34.dwOemId = 0;
  GetSystemInfo((LPSYSTEM_INFO)&local_34.s);
  *(int *)(param_1 + 0xa4) = local_20;
  local_c = 0;
  if (local_20 != 0) {
    do {
      _ArgList = (undefined4 *)FUN_00891268(0x18);
      if (_ArgList == (undefined4 *)0x0) {
        _ArgList = (undefined4 *)0x0;
      }
      else {
        *_ArgList = 0;
        _ArgList[1] = 0;
        _ArgList[2] = 0;
        _ArgList[3] = 0;
        *(undefined1 *)(_ArgList + 4) = 0;
        _ArgList[5] = 0;
      }
      *_ArgList = *(undefined4 *)(param_1 + 0xa4);
      _ArgList[1] = local_c;
      local_8 = _ArgList;
      pvVar7 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
      _ArgList[2] = pvVar7;
      puVar1 = _ArgList + 3;
      pvVar7 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
      *puVar1 = pvVar7;
      _ArgList[5] = param_1;
      __beginthread(FUN_00805190,0,_ArgList);
      puVar2 = *(undefined4 **)(param_1 + 0xac);
      if ((puVar1 < puVar2) && (puVar3 = *(undefined4 **)(param_1 + 0xa8), puVar3 <= puVar1)) {
        local_10 = (int)puVar1 - (int)puVar3 >> 2;
        if (puVar2 == *(undefined4 **)(param_1 + 0xb0)) {
          uVar8 = (int)puVar2 - (int)puVar3 >> 2;
          if (0x3ffffffe < uVar8) goto LAB_00804fa8;
          uVar8 = uVar8 + 1;
          uVar9 = (int)*(undefined4 **)(param_1 + 0xb0) - (int)puVar3 >> 2;
          if (uVar9 < uVar8) {
            if (0x3fffffff - (uVar9 >> 1) < uVar9) {
              uVar9 = 0;
            }
            else {
              uVar9 = uVar9 + (uVar9 >> 1);
            }
            if (uVar9 < uVar8) {
              uVar9 = uVar8;
            }
            FUN_00797980(uVar9);
          }
        }
        if (*(undefined4 **)(param_1 + 0xac) != (undefined4 *)0x0) {
          **(undefined4 **)(param_1 + 0xac) =
               *(undefined4 *)(*(int *)(param_1 + 0xa8) + local_10 * 4);
        }
        *(int *)(param_1 + 0xac) = *(int *)(param_1 + 0xac) + 4;
      }
      else {
        if (puVar2 == *(undefined4 **)(param_1 + 0xb0)) {
          iVar4 = *(int *)(param_1 + 0xa8);
          uVar8 = (int)puVar2 - iVar4 >> 2;
          if (0x3ffffffe < uVar8) goto LAB_00804fa8;
          uVar8 = uVar8 + 1;
          uVar9 = (int)*(undefined4 **)(param_1 + 0xb0) - iVar4 >> 2;
          if (uVar9 < uVar8) {
            if (0x3fffffff - (uVar9 >> 1) < uVar9) {
              uVar9 = 0;
            }
            else {
              uVar9 = uVar9 + (uVar9 >> 1);
            }
            if (uVar9 < uVar8) {
              uVar9 = uVar8;
            }
            FUN_00797980(uVar9);
          }
        }
        if (*(undefined4 **)(param_1 + 0xac) != (undefined4 *)0x0) {
          **(undefined4 **)(param_1 + 0xac) = *puVar1;
        }
        *(int *)(param_1 + 0xac) = *(int *)(param_1 + 0xac) + 4;
      }
      ppuVar5 = *(undefined4 ***)(param_1 + 0x98);
      puVar10 = (uint *)(param_1 + 0x94);
      if ((&local_8 < ppuVar5) && (ppuVar6 = (undefined4 **)*puVar10, ppuVar6 <= &local_8)) {
        if (ppuVar5 == *(undefined4 ***)(param_1 + 0x9c)) {
          uVar8 = (int)ppuVar5 - (int)ppuVar6 >> 2;
          if (0x3ffffffe < uVar8) {
LAB_00804fa8:
                    /* WARNING: Subroutine does not return */
            FUN_0087db30("vector<T> too long");
          }
          uVar8 = uVar8 + 1;
          uVar9 = (int)*(undefined4 ***)(param_1 + 0x9c) - (int)ppuVar6 >> 2;
          if (uVar9 < uVar8) {
            if (0x3fffffff - (uVar9 >> 1) < uVar9) {
              uVar9 = 0;
            }
            else {
              uVar9 = uVar9 + (uVar9 >> 1);
            }
            if (uVar9 < uVar8) {
              uVar9 = uVar8;
            }
            FUN_00797980(uVar9);
          }
        }
        if (*(undefined4 **)(param_1 + 0x98) != (undefined4 *)0x0) {
          **(undefined4 **)(param_1 + 0x98) =
               *(undefined4 *)(*puVar10 + ((int)&local_8 - (int)ppuVar6 >> 2) * 4);
        }
      }
      else {
        if (ppuVar5 == *(undefined4 ***)(param_1 + 0x9c)) {
          uVar8 = (int)((int)ppuVar5 - *puVar10) >> 2;
          if (0x3ffffffe < uVar8) goto LAB_00804fa8;
          uVar8 = uVar8 + 1;
          uVar9 = (int)((int)*(undefined4 ***)(param_1 + 0x9c) - *puVar10) >> 2;
          if (uVar9 < uVar8) {
            if (0x3fffffff - (uVar9 >> 1) < uVar9) {
              uVar9 = 0;
            }
            else {
              uVar9 = uVar9 + (uVar9 >> 1);
            }
            if (uVar9 < uVar8) {
              uVar9 = uVar8;
            }
            FUN_00797980(uVar9);
          }
        }
        if (*(undefined4 **)(param_1 + 0x98) != (undefined4 *)0x0) {
          **(undefined4 **)(param_1 + 0x98) = _ArgList;
        }
      }
      *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + 4;
      local_c = local_c + 1;
    } while (local_c < *(uint *)(param_1 + 0xa4));
  }
  return;
}

