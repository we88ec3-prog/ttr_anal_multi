
void FUN_0080c240(uint *param_1)

{
  undefined4 **ppuVar1;
  undefined4 **ppuVar2;
  undefined4 *puVar3;
  HANDLE pvVar4;
  undefined4 *_ArgList;
  uintptr_t *puVar5;
  uintptr_t uVar6;
  uint uVar7;
  uint uVar8;
  uintptr_t *puVar9;
  int local_c;
  undefined4 *local_8;
  
  local_c = 0;
  if (0 < (int)param_1[4]) {
    do {
      puVar3 = (undefined4 *)FUN_00891268(0x38);
      if (puVar3 == (undefined4 *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        *puVar3 = 0;
        puVar3[1] = 0xffffffff;
        puVar3[2] = 0;
        puVar3[3] = 0;
        puVar3[4] = 0;
        puVar3[5] = 0;
        puVar3[0xc] = 0xf;
        puVar3[0xb] = 0;
        *(undefined1 *)(puVar3 + 7) = 0;
      }
      local_8 = puVar3;
      pvVar4 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      puVar3[1] = pvVar4;
      puVar3[3] = local_c;
      puVar3[5] = 0;
      _ArgList = (undefined4 *)FUN_00891268(0xc);
      if (_ArgList == (undefined4 *)0x0) {
        _ArgList = (undefined4 *)0x0;
      }
      else {
        *_ArgList = FunctorArg0Func<void,ThreadedLoader<MoonSound::ThreadedLoadFunctor>::ThreadInfo*>
                    ::vftable;
        _ArgList[1] = puVar3;
        _ArgList[2] = FUN_0080c830;
      }
      puVar5 = (uintptr_t *)FUN_00891268(0xc);
      puVar9 = (uintptr_t *)0x0;
      if (puVar5 != (uintptr_t *)0x0) {
        puVar5[1] = 0;
        puVar5[2] = 0;
        *puVar5 = 0xffffffff;
        puVar9 = puVar5;
      }
      puVar9[2] = (uintptr_t)_ArgList;
      uVar6 = __beginthreadex((void *)0x0,0,FUN_004fb740,_ArgList,0,puVar9 + 1);
      *puVar9 = uVar6;
      if (uVar6 == 0xffffffff) {
        FUN_0089120c(puVar9);
        puVar9 = (uintptr_t *)0x0;
      }
      *puVar3 = puVar9;
      ppuVar1 = (undefined4 **)param_1[1];
      if ((&local_8 < ppuVar1) && (ppuVar2 = (undefined4 **)*param_1, ppuVar2 <= &local_8)) {
        if (ppuVar1 == (undefined4 **)param_1[2]) {
          uVar7 = (int)ppuVar1 - (int)ppuVar2 >> 2;
          if (0x3ffffffe < uVar7) {
LAB_0080c3f3:
                    /* WARNING: Subroutine does not return */
            FUN_0087db30("vector<T> too long");
          }
          uVar7 = uVar7 + 1;
          uVar8 = (int)param_1[2] - (int)ppuVar2 >> 2;
          if (uVar8 < uVar7) {
            if (0x3fffffff - (uVar8 >> 1) < uVar8) {
              uVar8 = 0;
            }
            else {
              uVar8 = uVar8 + (uVar8 >> 1);
            }
            if (uVar8 < uVar7) {
              uVar8 = uVar7;
            }
            FUN_00797980(uVar8);
          }
        }
        if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
          *(undefined4 *)param_1[1] =
               *(undefined4 *)(*param_1 + ((int)&local_8 - (int)ppuVar2 >> 2) * 4);
        }
      }
      else {
        if (ppuVar1 == (undefined4 **)param_1[2]) {
          uVar7 = (int)((int)ppuVar1 - *param_1) >> 2;
          if (0x3ffffffe < uVar7) goto LAB_0080c3f3;
          uVar7 = uVar7 + 1;
          uVar8 = (int)((int)param_1[2] - *param_1) >> 2;
          if (uVar8 < uVar7) {
            if (0x3fffffff - (uVar8 >> 1) < uVar8) {
              uVar8 = 0;
            }
            else {
              uVar8 = uVar8 + (uVar8 >> 1);
            }
            if (uVar8 < uVar7) {
              uVar8 = uVar7;
            }
            FUN_00797980(uVar8);
          }
        }
        if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
          *(undefined4 *)param_1[1] = puVar3;
        }
      }
      param_1[1] = param_1[1] + 4;
      local_c = local_c + 1;
    } while (local_c < (int)param_1[4]);
  }
  return;
}

