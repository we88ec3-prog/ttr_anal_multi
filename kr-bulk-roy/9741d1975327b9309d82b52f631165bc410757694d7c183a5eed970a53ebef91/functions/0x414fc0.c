
void FUN_00414fc0(uint param_1,int param_2)

{
  void *_Dst;
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  int unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00941f5c;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  _Dst = *(void **)(unaff_EDI + 0x1b0);
  if (_Dst != *(void **)(unaff_EDI + 0x1b4)) {
    FID_conflict__memcpy(_Dst,*(void **)(unaff_EDI + 0x1b4),0);
    *(void **)(unaff_EDI + 0x1b4) = _Dst;
  }
  FUN_00415d50(uVar3);
  iVar4 = **(int **)(*(int *)(unaff_EDI + (param_1 + 0xe) * 0x10) + param_2 * 4);
  *(int *)(unaff_EDI + 0x1ac) = iVar4;
  if ((*(int *)(unaff_EDI + 4 + (iVar4 + 0x1c) * 0x10) - *(int *)(unaff_EDI + (iVar4 + 0x1c) * 0x10)
      >> 2) + (*(int *)(unaff_EDI + 4 + (iVar4 + 0x3a) * 0x10) -
               *(int *)(unaff_EDI + (iVar4 + 0x3a) * 0x10) >> 2) == 0) {
    *(undefined4 *)(unaff_EDI + 0x1ac) =
         *(undefined4 *)**(undefined4 **)(unaff_EDI + (param_1 + 0xe) * 0x10);
  }
  iVar4 = *(int *)(unaff_EDI + 0x1ac) + 0x1c;
  param_1 = 0;
  if (*(int *)(unaff_EDI + 4 + iVar4 * 0x10) - *(int *)(unaff_EDI + iVar4 * 0x10) >> 2 != 0) {
    do {
      iVar4 = *(int *)(unaff_EDI + (*(int *)(unaff_EDI + 0x1ac) + 0x1c) * 0x10);
      if ((DAT_00f8d9a4 & 1) == 0) {
        DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
        local_8 = 0;
        FUN_0051c120();
        _atexit((_func_4879 *)&LAB_00bccc90);
        local_8 = 0xffffffff;
      }
      iVar4 = FUN_0051d700(**(undefined4 **)(iVar4 + param_1 * 4));
      if ((*(int *)(iVar4 + 4) == *(int *)(unaff_EDI + 0x1a8)) || (*(int *)(iVar4 + 4) == 0)) {
        puVar6 = (undefined4 *)
                 (*(int *)(unaff_EDI + (*(int *)(unaff_EDI + 0x1ac) + 0x1c) * 0x10) + param_1 * 4);
        puVar1 = *(undefined4 **)(unaff_EDI + 0x1b4);
        if ((puVar6 < puVar1) && (puVar2 = *(undefined4 **)(unaff_EDI + 0x1b0), puVar2 <= puVar6)) {
          if (puVar1 == *(undefined4 **)(unaff_EDI + 0x1b8)) {
            FUN_004deab0();
          }
          if (*(undefined4 **)(unaff_EDI + 0x1b4) != (undefined4 *)0x0) {
            **(undefined4 **)(unaff_EDI + 0x1b4) =
                 *(undefined4 *)(*(int *)(unaff_EDI + 0x1b0) + ((int)puVar6 - (int)puVar2 >> 2) * 4)
            ;
          }
        }
        else {
          if (puVar1 == *(undefined4 **)(unaff_EDI + 0x1b8)) {
            FUN_004deab0();
          }
          if (*(undefined4 **)(unaff_EDI + 0x1b4) != (undefined4 *)0x0) {
            **(undefined4 **)(unaff_EDI + 0x1b4) = *puVar6;
          }
        }
        *(int *)(unaff_EDI + 0x1b4) = *(int *)(unaff_EDI + 0x1b4) + 4;
      }
      iVar4 = *(int *)(unaff_EDI + 0x1ac) + 0x1c;
      param_1 = param_1 + 1;
    } while (param_1 < (uint)(*(int *)(unaff_EDI + 4 + iVar4 * 0x10) -
                              *(int *)(unaff_EDI + iVar4 * 0x10) >> 2));
  }
  iVar4 = *(int *)(unaff_EDI + 0x1ac) + 0x3a;
  param_1 = 0;
  if (*(int *)(unaff_EDI + 4 + iVar4 * 0x10) - *(int *)(unaff_EDI + iVar4 * 0x10) >> 2 != 0) {
    do {
      iVar4 = *(int *)(unaff_EDI + (*(int *)(unaff_EDI + 0x1ac) + 0x3a) * 0x10);
      if ((DAT_00f8d9a4 & 1) == 0) {
        DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
        local_8 = 1;
        FUN_0051c120();
        _atexit((_func_4879 *)&LAB_00bccc90);
        local_8 = 0xffffffff;
      }
      iVar4 = FUN_0051d700(**(undefined4 **)(iVar4 + param_1 * 4));
      if ((*(int *)(iVar4 + 4) == *(int *)(unaff_EDI + 0x1a8)) || (*(int *)(iVar4 + 4) == 0)) {
        puVar6 = (undefined4 *)
                 (*(int *)(unaff_EDI + (*(int *)(unaff_EDI + 0x1ac) + 0x3a) * 0x10) + param_1 * 4);
        puVar1 = *(undefined4 **)(unaff_EDI + 0x1b4);
        if ((puVar6 < puVar1) && (puVar2 = *(undefined4 **)(unaff_EDI + 0x1b0), puVar2 <= puVar6)) {
          if (puVar1 == *(undefined4 **)(unaff_EDI + 0x1b8)) {
            uVar3 = (int)puVar1 - (int)puVar2 >> 2;
            if (0x3ffffffe < uVar3) {
LAB_00415369:
                    /* WARNING: Subroutine does not return */
              FUN_0087db30("vector<T> too long");
            }
            uVar3 = uVar3 + 1;
            uVar5 = (int)*(undefined4 **)(unaff_EDI + 0x1b8) - (int)puVar2 >> 2;
            if (uVar5 < uVar3) {
              if (0x3fffffff - (uVar5 >> 1) < uVar5) {
                uVar5 = 0;
              }
              else {
                uVar5 = uVar5 + (uVar5 >> 1);
              }
              if (uVar5 < uVar3) {
                uVar5 = uVar3;
              }
              FUN_00797980(uVar5);
            }
          }
          if (*(undefined4 **)(unaff_EDI + 0x1b4) != (undefined4 *)0x0) {
            **(undefined4 **)(unaff_EDI + 0x1b4) =
                 *(undefined4 *)(*(int *)(unaff_EDI + 0x1b0) + ((int)puVar6 - (int)puVar2 >> 2) * 4)
            ;
          }
        }
        else {
          if (puVar1 == *(undefined4 **)(unaff_EDI + 0x1b8)) {
            uVar3 = (int)puVar1 - *(int *)(unaff_EDI + 0x1b0) >> 2;
            if (0x3ffffffe < uVar3) goto LAB_00415369;
            uVar3 = uVar3 + 1;
            uVar5 = (int)*(undefined4 **)(unaff_EDI + 0x1b8) - *(int *)(unaff_EDI + 0x1b0) >> 2;
            if (uVar5 < uVar3) {
              if (0x3fffffff - (uVar5 >> 1) < uVar5) {
                uVar5 = 0;
              }
              else {
                uVar5 = uVar5 + (uVar5 >> 1);
              }
              if (uVar5 < uVar3) {
                uVar5 = uVar3;
              }
              FUN_00797980(uVar5);
            }
          }
          if (*(undefined4 **)(unaff_EDI + 0x1b4) != (undefined4 *)0x0) {
            **(undefined4 **)(unaff_EDI + 0x1b4) = *puVar6;
          }
        }
        *(int *)(unaff_EDI + 0x1b4) = *(int *)(unaff_EDI + 0x1b4) + 4;
      }
      iVar4 = *(int *)(unaff_EDI + 0x1ac) + 0x3a;
      param_1 = param_1 + 1;
    } while (param_1 < (uint)(*(int *)(unaff_EDI + 4 + iVar4 * 0x10) -
                              *(int *)(unaff_EDI + iVar4 * 0x10) >> 2));
  }
  FUN_00416580(unaff_EDI);
  ExceptionList = local_10;
  return;
}

