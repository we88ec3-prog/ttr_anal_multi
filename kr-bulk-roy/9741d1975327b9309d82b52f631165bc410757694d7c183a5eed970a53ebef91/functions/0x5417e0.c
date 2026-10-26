
/* WARNING: Removing unreachable block (ram,0x0054191e) */
/* WARNING: Removing unreachable block (ram,0x00541926) */
/* WARNING: Removing unreachable block (ram,0x00541928) */
/* WARNING: Removing unreachable block (ram,0x0054192f) */
/* WARNING: Removing unreachable block (ram,0x00541a2f) */
/* WARNING: Removing unreachable block (ram,0x0054193b) */
/* WARNING: Removing unreachable block (ram,0x00541941) */
/* WARNING: Removing unreachable block (ram,0x005419f2) */
/* WARNING: Removing unreachable block (ram,0x005419fe) */
/* WARNING: Removing unreachable block (ram,0x00541a12) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005417e0(int param_1,undefined4 param_2)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  HANDLE hHandle;
  int iVar6;
  int *piVar7;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093938c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar5 = (undefined4 *)FUN_00891268();
  if (puVar5 != (undefined4 *)0x0) {
    *puVar5 = 0;
    *(undefined1 *)(puVar5 + 2) = 1;
    puVar5[3] = 0;
    puVar5[4] = 0;
    puVar5[5] = 0;
  }
  FUN_0047c0d0();
  local_8 = 0;
  uRam00000004 = param_2;
  uRam00000008 = 1;
  piVar7 = (int *)**(int **)(param_1 + 4);
  if (piVar7 != *(int **)(param_1 + 4)) {
    do {
      piVar2 = piVar7 + 3;
      if ((piVar2 < piRam00000010) && (piRam0000000c <= piVar2)) {
        iVar6 = (int)piVar2 - (int)piRam0000000c;
        if (piRam00000010 == _DAT_00000014) {
          FUN_006d6240();
        }
        if (piRam00000010 != (int *)0x0) {
          *piRam00000010 = piRam0000000c[iVar6 >> 2];
        }
      }
      else {
        if (piRam00000010 == _DAT_00000014) {
          FUN_006d6240();
        }
        if (piRam00000010 != (int *)0x0) {
          *piRam00000010 = *piVar2;
        }
      }
      piRam00000010 = piRam00000010 + 1;
      if (*(char *)((int)piVar7 + 0x11) == '\0') {
        piVar2 = (int *)piVar7[2];
        if (*(char *)((int)piVar2 + 0x11) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x11);
          piVar7 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x11);
            piVar7 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar7[1] + 0x11);
          piVar4 = (int *)piVar7[1];
          piVar2 = piVar7;
          while ((piVar7 = piVar4, cVar1 == '\0' && (piVar2 == (int *)piVar7[2]))) {
            cVar1 = *(char *)(piVar7[1] + 0x11);
            piVar4 = (int *)piVar7[1];
            piVar2 = piVar7;
          }
        }
      }
    } while (piVar7 != *(int **)(param_1 + 4));
  }
  uVar3 = local_8 >> 8;
  if ((DAT_00fc0f60 & 1) == 0) {
    DAT_00fc0f60 = DAT_00fc0f60 | 1;
    local_8._0_1_ = 2;
    FUN_0079cf40();
    _atexit((_func_4879 *)&LAB_00bcdb80);
    uVar3 = (uint)local_8._1_3_;
  }
  local_8 = uVar3 << 8;
  hHandle = (HANDLE)FUN_0079dce0();
  WaitForSingleObject(hHandle,0xffffffff);
  CloseHandle(hHandle);
  if ((DAT_00fe1770 & 1) == 0) {
    DAT_00fe1770 = DAT_00fe1770 | 1;
    local_8._0_1_ = 3;
    FUN_007b7da0();
    _atexit((_func_4879 *)&LAB_00bce790);
    local_8 = (uint)local_8._1_3_ << 8;
  }
  iVar6 = DAT_00fe173c;
  piVar7 = (int *)**(int **)(DAT_00fe173c + 4);
  if (piVar7 != *(int **)(DAT_00fe173c + 4)) {
    do {
      if (((int *)piVar7[9])[1] == 0) {
        (**(code **)(*(int *)piVar7[9] + 4))();
      }
      piVar7 = (int *)*piVar7;
    } while (piVar7 != (int *)*(int *)(iVar6 + 4));
  }
  ExceptionList = local_10;
  return;
}

