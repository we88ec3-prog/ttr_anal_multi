
/* WARNING: Removing unreachable block (ram,0x00563b7f) */
/* WARNING: Removing unreachable block (ram,0x00563b8a) */
/* WARNING: Removing unreachable block (ram,0x00563bfb) */
/* WARNING: Removing unreachable block (ram,0x00563c07) */
/* WARNING: Removing unreachable block (ram,0x00563c1b) */

void FUN_00563a70(void)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  HANDLE hHandle;
  int in_ECX;
  int *piVar6;
  void *local_14;
  undefined1 *puStack_10;
  int iStack_c;
  
  iStack_c = 0xffffffff;
  puStack_10 = &LAB_0093933e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  piVar6 = (int *)**(int **)(in_ECX + 0x1c);
  if (piVar6 != *(int **)(in_ECX + 0x1c)) {
    do {
      piVar2 = (int *)piVar6[4];
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0x14))();
        (**(code **)*piVar2)();
      }
      if (*(char *)((int)piVar6 + 0x15) == '\0') {
        piVar2 = (int *)piVar6[2];
        if (*(char *)((int)piVar2 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x15);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x15);
            piVar6 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar6[1] + 0x15);
          piVar4 = (int *)piVar6[1];
          piVar2 = piVar6;
          while ((piVar6 = piVar4, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
            cVar1 = *(char *)(piVar6[1] + 0x15);
            piVar4 = (int *)piVar6[1];
            piVar2 = piVar6;
          }
        }
      }
    } while (piVar6 != *(int **)(in_ECX + 0x1c));
  }
  FUN_00823850();
  puVar5 = (undefined4 *)FUN_00891268();
  if (puVar5 != (undefined4 *)0x0) {
    *puVar5 = 0;
    *(undefined1 *)(puVar5 + 2) = 1;
    puVar5[3] = 0;
    puVar5[4] = 0;
    puVar5[5] = 0;
  }
  FUN_0047c0d0();
  uRam00000008 = 1;
  uRam00000004 = 3;
  uVar3 = 0;
  if ((DAT_00fc0f60 & 1) == 0) {
    DAT_00fc0f60 = DAT_00fc0f60 | 1;
    iStack_c._1_3_ = 0;
    iStack_c._0_1_ = 2;
    FUN_0079cf40();
    _atexit((_func_4879 *)&LAB_00bcdb80);
    uVar3 = (uint)iStack_c._1_3_;
  }
  iStack_c = uVar3 << 8;
  hHandle = (HANDLE)FUN_0079dce0();
  WaitForSingleObject(hHandle,0xffffffff);
  CloseHandle(hHandle);
  FUN_00851420();
  ExceptionList = local_14;
  return;
}

