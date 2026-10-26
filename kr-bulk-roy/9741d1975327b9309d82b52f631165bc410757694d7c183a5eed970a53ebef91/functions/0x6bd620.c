
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006bd620(int param_1,int param_2,undefined1 param_3)

{
  int *piVar1;
  DWORD DVar2;
  int in_ECX;
  int *piVar3;
  
  if ((_DAT_00fc1aec & 1) == 0) {
    _DAT_00fc1aec = _DAT_00fc1aec | 1;
    DAT_00fc1af0 = (int *)0x0;
    DAT_00fc1af4 = (int *)0x0;
    _DAT_00fc1af8 = 0;
    _atexit((_func_4879 *)&LAB_00bcdd10);
  }
  piVar3 = (int *)0x0;
  for (piVar1 = DAT_00fc1af0; piVar1 != DAT_00fc1af4; piVar1 = piVar1 + 8) {
    if ((*piVar1 == param_1) && (piVar1[1] == param_2)) {
      piVar3 = piVar1;
    }
  }
  *(int **)(in_ECX + 0x9c) = piVar3;
  if (piVar3 != (int *)0x0) {
    *(undefined1 *)(in_ECX + 0xa8) = param_3;
    DVar2 = timeGetTime();
    *(DWORD *)(in_ECX + 0xa4) = DVar2;
    FUN_006bd6b0();
  }
  return;
}

