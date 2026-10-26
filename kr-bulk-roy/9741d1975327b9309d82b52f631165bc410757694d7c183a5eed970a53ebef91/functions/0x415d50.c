
void FUN_00415d50(void)

{
  void *_Dst;
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int in_ECX;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  int local_28;
  uint *local_24;
  int local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009405be;
  local_14 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffc8;
  ExceptionList = &local_14;
  puVar6 = (uint *)(in_ECX + 0x1c4);
  local_28 = 0xf;
  local_24 = puVar6;
  do {
    _Dst = (void *)puVar6[-1];
    if (_Dst != (void *)*puVar6) {
      FID_conflict__memcpy(_Dst,(void *)*puVar6,0);
      *puVar6 = (uint)_Dst;
    }
    puVar6 = puVar6 + 4;
    local_28 = local_28 + -1;
  } while (local_28 != 0);
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(uVar3);
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  local_20 = DAT_00f93950;
  local_1c = 0;
  iVar4 = DAT_00f93950;
  puVar6 = local_24;
  do {
    local_24 = (uint *)0x0;
    if ((int)(puVar6[0x3c] - puVar6[0x3b]) >> 2 != 0) {
      do {
        local_28 = *(int *)(puVar6[0x3b] + (int)local_24 * 4);
        if (((*(int *)(local_28 + 0x30) == 0) || (*(int *)(local_28 + 0x30) <= iVar4)) &&
           ((*(int *)(local_28 + 0x34) == 0 || (iVar4 <= *(int *)(local_28 + 0x34))))) {
          piVar1 = (int *)*puVar6;
          if ((&local_28 < piVar1) && (piVar2 = (int *)puVar6[-1], piVar2 <= &local_28)) {
            if (piVar1 == (int *)puVar6[1]) {
              uVar3 = (int)piVar1 - (int)piVar2 >> 2;
              if (0x3ffffffe < uVar3) {
LAB_00415f5f:
                    /* WARNING: Subroutine does not return */
                FUN_0087db30("vector<T> too long");
              }
              uVar3 = uVar3 + 1;
              uVar5 = (int)puVar6[1] - (int)piVar2 >> 2;
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
            if ((undefined4 *)*puVar6 != (undefined4 *)0x0) {
              *(undefined4 *)*puVar6 =
                   *(undefined4 *)(puVar6[-1] + ((int)&local_28 - (int)piVar2 >> 2) * 4);
            }
          }
          else {
            if (piVar1 == (int *)puVar6[1]) {
              uVar3 = (int)((int)piVar1 - puVar6[-1]) >> 2;
              if (0x3ffffffe < uVar3) goto LAB_00415f5f;
              uVar3 = uVar3 + 1;
              uVar5 = (int)((int)puVar6[1] - puVar6[-1]) >> 2;
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
            if ((int *)*puVar6 != (int *)0x0) {
              *(int *)*puVar6 = local_28;
            }
          }
          *puVar6 = *puVar6 + 4;
        }
        local_24 = (uint *)((int)local_24 + 1);
        iVar4 = local_20;
      } while (local_24 < (uint)((int)(puVar6[0x3c] - puVar6[0x3b]) >> 2));
    }
    local_1c = local_1c + 1;
    puVar6 = puVar6 + 4;
    if (0xe < local_1c) {
      ExceptionList = local_14;
      return;
    }
  } while( true );
}

