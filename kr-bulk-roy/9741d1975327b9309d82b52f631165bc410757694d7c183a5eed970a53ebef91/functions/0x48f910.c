
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0048f910(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  undefined4 uStack_20;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093b52d;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 0;
    FUN_00587480(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_c = 0xffffffff;
  FUN_00589e80();
  piVar3 = *(int **)(param_1 + 0xbfe0);
  if ((piVar3 != (int *)0x0) && (-1 < *piVar3)) {
    *piVar3 = 0;
    if (piVar3[4] != 0) {
      (**(code **)(*(int *)(piVar3[4] + 8) + 8))();
    }
    if ((undefined4 *)piVar3[2] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)piVar3[2])(1);
      piVar3[2] = 0;
    }
  }
  if ((DAT_00fdf6f4 & 1) == 0) {
    DAT_00fdf6f4 = DAT_00fdf6f4 | 1;
    local_c = 1;
    FUN_0049b490();
    local_c = 0xffffffff;
  }
  DAT_00fb9414 = 0;
  (**(code **)(*DAT_00fb941c + 8))(DAT_00fb941c);
  if ((_DAT_00fd8f0c & 1) == 0) {
    _DAT_00fd8f0c = _DAT_00fd8f0c | 1;
    FUN_00559120();
    _atexit((_func_4879 *)&DAT_00bcdf60);
  }
  FUN_00559310();
  iVar2 = FUN_0048a010();
  piVar3 = (int *)(iVar2 + 0x10);
  iVar2 = 10;
  do {
    if ((int *)*piVar3 != (int *)0x0) {
      (**(code **)(*(int *)*piVar3 + 8))();
      *piVar3 = 0;
    }
    piVar3 = piVar3 + 0xf;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if ((DAT_00fb131c & 1) == 0) {
    DAT_00fb131c = DAT_00fb131c | 1;
    puStack_10 = (undefined1 *)0x2;
    FUN_00570ec0();
    _atexit((_func_4879 *)&LAB_00bccf50);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  uVar4 = 0;
  do {
    if (*(int **)((int)&DAT_00fb1320 + uVar4) != (int *)0x0) {
      (**(code **)(**(int **)((int)&DAT_00fb1320 + uVar4) + 8))();
    }
    uVar4 = uVar4 + 4;
  } while (uVar4 < 0xc);
  if ((DAT_00fc1bf4 & 1) == 0) {
    DAT_00fc1bf4 = DAT_00fc1bf4 | 1;
    puStack_10 = (undefined1 *)0x3;
    FUN_0057ef90();
    _atexit((_func_4879 *)&LAB_00bcdfb0);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  FUN_0057f750();
  if ((_DAT_00fd2b98 & 1) == 0) {
    _DAT_00fd2b98 = _DAT_00fd2b98 | 1;
    DAT_00fd2b9c = (undefined4 *)0x0;
    DAT_00fd2ba0 = (undefined4 *)0x0;
    DAT_00fd2ba4 = 0;
    DAT_00fd2ba8 = 0;
    _DAT_00fd2bac = 0;
    _DAT_00fd2bb0 = 0;
  }
  else if ((DAT_00fd2ba8 != 0) && (DAT_00fd2ba4 != 0)) {
    if (DAT_00fd2b9c != (undefined4 *)0x0) {
      (**(code **)*DAT_00fd2b9c)(1);
      DAT_00fd2b9c = (undefined4 *)0x0;
    }
    if (DAT_00fd2ba0 != (undefined4 *)0x0) {
      (**(code **)*DAT_00fd2ba0)(1);
      DAT_00fd2ba0 = (undefined4 *)0x0;
    }
    DAT_00fd2ba4 = 0;
  }
  if ((DAT_00fd8ea8 & 1) == 0) {
    DAT_00fd8ea8 = DAT_00fd8ea8 | 1;
    puStack_10 = (undefined1 *)0x4;
    FUN_0055ac10();
    _atexit((_func_4879 *)&LAB_00bcdfe0);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  FUN_00739120(DAT_00fd8ebc);
  if ((DAT_00fb7354 & 1) == 0) {
    DAT_00fb7354 = DAT_00fb7354 | 1;
    puStack_10 = (undefined1 *)0x5;
    FUN_005533d0();
    _atexit((_func_4879 *)&LAB_00bcd100);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  FUN_00553660();
  if ((_DAT_00fdf3c0 & 1) == 0) {
    _DAT_00fdf3c0 = _DAT_00fdf3c0 | 1;
    DAT_00fdf3c4 = 0;
    _atexit((_func_4879 *)&DAT_00bcdf50);
  }
  FUN_0056e2d0();
  if ((DAT_00fd9244 & 1) == 0) {
    DAT_00fd9244 = DAT_00fd9244 | 1;
    puStack_10 = (undefined1 *)0x6;
    FUN_00554410();
    _atexit((_func_4879 *)&LAB_00bcdfc0);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  iVar2 = DAT_00fd9250;
  if (DAT_00fd9250 != 0) {
    puVar1 = (undefined4 *)(DAT_00fd9250 + 0x20);
    if (*(undefined4 **)(DAT_00fd9250 + 0x20) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(DAT_00fd9250 + 0x20))(1);
      *puVar1 = 0;
    }
    *(undefined4 *)(iVar2 + 0x60) = 0;
  }
  if ((DAT_00fb73b8 & 1) == 0) {
    DAT_00fb73b8 = DAT_00fb73b8 | 1;
    puStack_10 = (undefined1 *)0x7;
    FUN_00560170();
    _atexit((_func_4879 *)&LAB_00bcd110);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  FUN_00561010(&DAT_00fb73c0);
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    puStack_10 = (undefined1 *)0x8;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  FUN_004e1270(*DAT_00fab13c,DAT_00fab13c,uStack_20);
  (**(code **)(*DAT_00fba7a4 + 0x28))();
  if ((_DAT_00fb79ec & 1) == 0) {
    _DAT_00fb79ec = _DAT_00fb79ec | 1;
    DAT_00fb79f0 = CCheckPointMgr::vftable;
    DAT_00fb79f4 = 0;
    DAT_00fb79f8 = 0;
    DAT_00fb79fc = 0;
    DAT_00fb7a04 = 1;
    _atexit((_func_4879 *)&LAB_00bcd270);
  }
  (*(code *)DAT_00fb79f0[2])();
  FUN_007a44f0();
  if ((DAT_00fdf6dc & 1) == 0) {
    DAT_00fdf6dc = DAT_00fdf6dc | 1;
    puStack_10 = (undefined1 *)0x9;
    FUN_00550820();
    _atexit((_func_4879 *)&LAB_00bce6b0);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  (**(code **)(DAT_00fdf680 + 8))();
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    puStack_10 = (undefined1 *)0xa;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  puVar1 = DAT_00fb76e8;
  if ((undefined4 *)DAT_00fb76e8[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)DAT_00fb76e8[2])(1);
    puVar1[2] = 0;
  }
  puVar1[1] = 0;
  *puVar1 = 0;
  iVar2 = *(int *)(param_1 + 0xbfdc);
  if (*(int *)(iVar2 + 4) == 1) {
    *(undefined4 *)(iVar2 + 4) = 0;
    (**(code **)(**(int **)(iVar2 + 0x18) + 0xc))();
  }
  FUN_007ab020();
  if ((_DAT_00fd2cf0 & 1) == 0) {
    _DAT_00fd2cf0 = _DAT_00fd2cf0 | 1;
    FUN_00738090();
    _atexit((_func_4879 *)&DAT_00bce680);
  }
  if (DAT_00fd2cd0 != (int *)0x0) {
    (**(code **)(*DAT_00fd2cd0 + 8))();
    DAT_00fd2cd0 = (int *)0x0;
  }
  _DAT_00fd2bcc = 0;
  DAT_00fd2bb8 = 0;
  if ((_DAT_00fd9408 & 1) == 0) {
    _DAT_00fd9408 = _DAT_00fd9408 | 1;
    DAT_00fd940c = 0;
    _DAT_00fd9410 = 0;
    DAT_00fd9414 = (undefined4 *)0x0;
    _DAT_00fd9418 = 0;
  }
  FUN_00739120(DAT_00fd9414);
  puVar1 = DAT_00fd9414;
  if (DAT_00fd9414 != (undefined4 *)0x0) {
    *DAT_00fd9414 = Graphics::CImage::vftable;
    puStack_10 = (undefined1 *)0xb;
    FUN_00739120(puVar1);
    puStack_10 = (undefined1 *)0xffffffff;
    if (puVar1[4] != 0) {
      FUN_0089120c(puVar1[4]);
    }
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    FUN_0089120c(puVar1);
  }
  if ((DAT_00fc1a34 & 1) == 0) {
    DAT_00fc1a34 = DAT_00fc1a34 | 1;
    puStack_10 = (undefined1 *)0xc;
    FUN_00737210();
    _atexit(FUN_00bce000);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  FUN_00737660(&DAT_00fc1a38);
  if ((DAT_00fc18fc & 1) == 0) {
    DAT_00fc18fc = DAT_00fc18fc | 1;
    puStack_10 = (undefined1 *)0xd;
    FUN_005548f0();
    _atexit((_func_4879 *)&LAB_00bcdcd0);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  FUN_005558c0();
  if ((DAT_00fb7bc8 & 1) == 0) {
    DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
    puStack_10 = (undefined1 *)0xe;
    FUN_00734ef0();
    _atexit((_func_4879 *)&LAB_00bcd4f0);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  if (DAT_00fb7b74 != (int *)0x0) {
    (**(code **)(*DAT_00fb7b74 + 8))(DAT_00fb7b74);
    DAT_00fb7b74 = (int *)0x0;
  }
  FUN_00734a00();
  FUN_00736480(&DAT_00fb7b94);
  (**(code **)(*DAT_00fb7b78 + 0x18))();
  if ((DAT_00fcde40 & 1) == 0) {
    DAT_00fcde40 = DAT_00fcde40 | 1;
    puStack_10 = (undefined1 *)0xf;
    FUN_00736880();
    _atexit(FUN_00bce6f0);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  FUN_00736990(&DAT_00fcde28);
  piVar3 = *(int **)(param_1 + 0xbf50);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))(piVar3);
    *(undefined4 *)(param_1 + 0xbf50) = 0;
  }
  *(undefined4 *)(param_1 + 0xc074) = 0;
  ExceptionList = pvStack_18;
  return 0;
}

