
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00490550(int param_1)

{
  int iVar1;
  uint unaff_EBX;
  uint uVar2;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093b340;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 0;
    FUN_00587480(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_c = 0xffffffff;
  FUN_0058a150(&DAT_00faadd8);
  *(undefined4 *)(param_1 + 0xbfd4) = 0;
  if (*(int *)(param_1 + 0xbfe0) != 0) {
    FUN_006dcc10();
  }
  (**(code **)(**(int **)(param_1 + 0xbf50) + 0x30))(*(int **)(param_1 + 0xbf50));
  iVar1 = *(int *)(param_1 + 0xbfdc);
  if (*(int *)(iVar1 + 4) == 2) {
    *(undefined4 *)(iVar1 + 4) = 1;
    (**(code **)(**(int **)(iVar1 + 0x18) + 0x14))();
  }
  if ((DAT_00fcde40 & 1) == 0) {
    DAT_00fcde40 = DAT_00fcde40 | 1;
    puStack_10 = (undefined1 *)0x1;
    FUN_00736880();
    _atexit(FUN_00bce6f0);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  FUN_00736a90();
  if ((_DAT_00fdf3c0 & 1) == 0) {
    _DAT_00fdf3c0 = _DAT_00fdf3c0 | 1;
    DAT_00fdf3c4 = 0;
    _atexit((_func_4879 *)&DAT_00bcdf50);
  }
  (**(code **)(*(int *)(*(int *)(DAT_00fdf3c4 + 0x60) + 8) + 8))();
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    puStack_10 = (undefined1 *)0x2;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  FUN_004e1370(*DAT_00fab13c,DAT_00fab13c,unaff_EBX & 0xffffff00);
  if ((DAT_00fb73b8 & 1) == 0) {
    DAT_00fb73b8 = DAT_00fb73b8 | 1;
    puStack_10 = (undefined1 *)0x3;
    FUN_00560170();
    _atexit((_func_4879 *)&LAB_00bcd110);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  FUN_005614b0();
  FUN_007ab360();
  if ((DAT_00fc1a34 & 1) == 0) {
    DAT_00fc1a34 = DAT_00fc1a34 | 1;
    puStack_10 = (undefined1 *)0x4;
    FUN_00737210();
    _atexit(FUN_00bce000);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  if ((DAT_00fc18fc & 1) == 0) {
    DAT_00fc18fc = DAT_00fc18fc | 1;
    puStack_10 = (undefined1 *)0x5;
    FUN_005548f0();
    _atexit((_func_4879 *)&LAB_00bcdcd0);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  if ((DAT_00fb131c & 1) == 0) {
    DAT_00fb131c = DAT_00fb131c | 1;
    puStack_10 = (undefined1 *)0x6;
    FUN_00570ec0();
    _atexit((_func_4879 *)&LAB_00bccf50);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  uVar2 = 0;
  do {
    if (*(int **)((int)&DAT_00fb1320 + uVar2) != (int *)0x0) {
      (**(code **)(**(int **)((int)&DAT_00fb1320 + uVar2) + 0x10))();
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0xc);
  if ((DAT_00fc1bf4 & 1) == 0) {
    DAT_00fc1bf4 = DAT_00fc1bf4 | 1;
    puStack_10 = (undefined1 *)0x7;
    FUN_0057ef90();
    _atexit((_func_4879 *)&LAB_00bcdfb0);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  if (DAT_00fc1c74 != 0) {
    DAT_00fc1c74 = 0;
    (**(code **)(*(int *)(DAT_00fc1c04 + 8) + 8))();
    (**(code **)(*(int *)(DAT_00fc1c00 + 8) + 8))();
  }
  *(undefined4 *)(param_1 + 0xc074) = 1;
  ExceptionList = pvStack_18;
  return 0;
}

