
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0048fff0(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uStack_24;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0093b432;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  (**(code **)(**(int **)(param_1 + 0xbf50) + 0x34))
            (*(int **)(param_1 + 0xbf50),DAT_00d61f20 ^ (uint)&stack0xffffffd0);
  if ((DAT_00fcde40 & 1) == 0) {
    DAT_00fcde40 = DAT_00fcde40 | 1;
    puStack_10 = (undefined1 *)0x0;
    FUN_00736880();
    _atexit(FUN_00bce6f0);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  FUN_00736a20();
  if ((DAT_00fc18fc & 1) == 0) {
    DAT_00fc18fc = DAT_00fc18fc | 1;
    puStack_10 = (undefined1 *)0x1;
    FUN_005548f0();
    _atexit((_func_4879 *)&LAB_00bcdcd0);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  if ((DAT_00fc1a34 & 1) == 0) {
    DAT_00fc1a34 = DAT_00fc1a34 | 1;
    puStack_10 = (undefined1 *)0x2;
    FUN_00737210();
    _atexit(FUN_00bce000);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  FUN_00737450();
  if ((DAT_00fc1bf4 & 1) == 0) {
    DAT_00fc1bf4 = DAT_00fc1bf4 | 1;
    puStack_10 = (undefined1 *)0x3;
    FUN_0057ef90();
    _atexit((_func_4879 *)&LAB_00bcdfb0);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  FUN_0057f7c0();
  if ((DAT_00fb131c & 1) == 0) {
    DAT_00fb131c = DAT_00fb131c | 1;
    puStack_10 = (undefined1 *)0x4;
    FUN_00570ec0();
    _atexit((_func_4879 *)&LAB_00bccf50);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  uVar4 = 0;
  do {
    if (*(int **)((int)&DAT_00fb1320 + uVar4) != (int *)0x0) {
      (**(code **)(**(int **)((int)&DAT_00fb1320 + uVar4) + 0xc))();
    }
    uVar4 = uVar4 + 4;
  } while (uVar4 < 0xc);
  FUN_007ab270();
  iVar3 = FUN_006dfc40();
  uVar1 = *(undefined4 *)(iVar3 + 0x18);
  iVar3 = FUN_006dfc40();
  uVar2 = *(undefined4 *)(iVar3 + 0x1c);
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    puStack_10 = (undefined1 *)0x5;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  FUN_00797e50(uVar1,uVar2);
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    puStack_10 = (undefined1 *)0x6;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  FUN_004e12f0(*DAT_00fab13c,DAT_00fab13c,uStack_24);
  if ((DAT_00fb73b8 & 1) == 0) {
    DAT_00fb73b8 = DAT_00fb73b8 | 1;
    puStack_10 = (undefined1 *)0x7;
    FUN_00560170();
    _atexit((_func_4879 *)&LAB_00bcd110);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  FUN_00561140(&DAT_00fb73c0);
  if ((_DAT_00fd2cf0 & 1) == 0) {
    _DAT_00fd2cf0 = _DAT_00fd2cf0 | 1;
    FUN_00738090();
    _atexit((_func_4879 *)&DAT_00bce680);
  }
  DAT_00fd2ce0 = uVar1;
  DAT_00fd2ce4 = uVar2;
  if ((_DAT_00fdf3c0 & 1) == 0) {
    _DAT_00fdf3c0 = _DAT_00fdf3c0 | 1;
    DAT_00fdf3c4 = 0;
    _atexit((_func_4879 *)&DAT_00bcdf50);
  }
  (**(code **)(*(int *)(*(int *)(DAT_00fdf3c4 + 0x60) + 8) + 4))();
  if ((DAT_00fb7354 & 1) == 0) {
    DAT_00fb7354 = DAT_00fb7354 | 1;
    puStack_10 = (undefined1 *)0x8;
    FUN_005533d0();
    _atexit((_func_4879 *)&LAB_00bcd100);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  FUN_00553550(uVar1,uVar2);
  if ((DAT_00fc1b88 & 1) == 0) {
    DAT_00fc1b88 = DAT_00fc1b88 | 1;
    puStack_10 = (undefined1 *)0x9;
    FUN_00581c10();
    _atexit((_func_4879 *)&LAB_00bcdfa0);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  iVar3 = DAT_00fc1b94;
  _DAT_00fc1bb4 = uVar1;
  _DAT_00fc1bb8 = uVar2;
  if (DAT_00fc1b94 != 0) {
    *(undefined4 *)(DAT_00fc1b94 + 0x48) = uVar1;
    *(undefined4 *)(iVar3 + 0x4c) = uVar2;
  }
  if ((DAT_00fc1b14 & 1) == 0) {
    DAT_00fc1b14 = DAT_00fc1b14 | 1;
    puStack_10 = (undefined1 *)0xa;
    FUN_0055ee90();
    _atexit((_func_4879 *)&LAB_00bcdf90);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  iVar3 = DAT_00fc1b1c;
  uVar4 = DAT_00faadd4 & 1;
  _DAT_00fc1b48 = uVar1;
  _DAT_00fc1b4c = uVar2;
  *(undefined4 *)(DAT_00fc1b1c + 0x48) = uVar1;
  *(undefined4 *)(iVar3 + 0x4c) = uVar2;
  if (uVar4 == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    puStack_10 = (undefined1 *)0xb;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    puStack_10 = (undefined1 *)0xc;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  uVar6 = DAT_00f95bc0;
  uVar5 = DAT_00f95bbc;
  if ((_DAT_00fd8f0c & 1) == 0) {
    _DAT_00fd8f0c = _DAT_00fd8f0c | 1;
    FUN_00559120();
    _atexit((_func_4879 *)&DAT_00bcdf60);
  }
  FUN_005591d0(uVar2,uVar5,uVar6);
  uVar5 = uVar2;
  FUN_0048a010(uVar2,uVar6);
  FUN_0041d9b0(uVar5,uVar6);
  if ((DAT_00fc18fc & 1) == 0) {
    DAT_00fc18fc = DAT_00fc18fc | 1;
    puStack_10 = (undefined1 *)0xd;
    FUN_005548f0();
    _atexit((_func_4879 *)&LAB_00bcdcd0);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  iVar3 = *(int *)(param_1 + 0xbfdc);
  if (*(int *)(iVar3 + 4) == 1) {
    *(undefined4 *)(iVar3 + 4) = 2;
    (**(code **)(**(int **)(iVar3 + 0x18) + 0x10))();
  }
  iVar3 = 4;
  do {
    (**(code **)(**(int **)(param_1 + 0x10) + 0xac))
              (*(int **)(param_1 + 0x10),0,0,7,0xff000000,0x3f800000,0);
    (**(code **)(**(int **)(param_1 + 0x10) + 0x44))(*(int **)(param_1 + 0x10),0,0,0,0);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(param_1 + 0xbfd0) = 0;
  if (*(int *)(param_1 + 0xbfe0) != 0) {
    FUN_006dcb30();
  }
  *(undefined4 *)(param_1 + 0xbfd4) = 1;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    puStack_10 = (undefined1 *)0xe;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  FUN_00589f60(&DAT_00faadd8,uVar1,uVar2);
  *(undefined4 *)(param_1 + 0xc074) = 2;
  ExceptionList = pvStack_18;
  return 0;
}

