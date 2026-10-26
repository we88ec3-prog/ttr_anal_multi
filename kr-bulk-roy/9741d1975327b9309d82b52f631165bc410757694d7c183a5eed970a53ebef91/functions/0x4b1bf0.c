
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004b1bf0(undefined4 *param_1)

{
  char cVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00947d7c;
  local_14 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(uVar3);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  FUN_0053da80(DAT_00fab134);
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 1;
    FUN_004dec90(uVar3);
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  iVar4 = DAT_00fab134;
  uVar3 = DAT_00fd9244 & 1;
  *(undefined4 *)(DAT_00fab134 + 0x34) = *param_1;
  *(undefined4 *)(iVar4 + 0x38) = param_1[1];
  *(undefined1 *)(iVar4 + 0x3c) = *(undefined1 *)(param_1 + 2);
  if (uVar3 == 0) {
    DAT_00fd9244 = DAT_00fd9244 | 1;
    local_c = 2;
    FUN_00554410();
    _atexit((_func_4879 *)&LAB_00bcdfc0);
    local_c = 0xffffffff;
  }
  _DAT_00fd9254 = 0;
  if ((DAT_00fb73b8 & 1) == 0) {
    DAT_00fb73b8 = DAT_00fb73b8 | 1;
    local_c = 3;
    FUN_00560170();
    _atexit((_func_4879 *)&LAB_00bcd110);
    local_c = 0xffffffff;
  }
  FUN_005624b0(0);
  cVar1 = *(char *)((int)param_1 + 2);
  if (cVar1 == '\0') {
    if ((_DAT_00fe1898 & 1) == 0) {
      _DAT_00fe1898 = _DAT_00fe1898 | 1;
      _atexit((_func_4879 *)&DAT_00bce820);
    }
    FUN_00552fc0();
  }
  else if (cVar1 == '\x02') {
    if ((DAT_00fc0e40 & 1) == 0) {
      DAT_00fc0e40 = DAT_00fc0e40 | 1;
      local_c = 4;
      FUN_00540770();
      _atexit((_func_4879 *)&LAB_00bcdb60);
      local_c = 0xffffffff;
    }
    FUN_00540980(*(undefined2 *)((int)param_1 + 7));
    if ((_DAT_00fe1898 & 1) == 0) {
      _DAT_00fe1898 = _DAT_00fe1898 | 1;
      _atexit((_func_4879 *)&DAT_00bce820);
    }
    FUN_00552fc0();
  }
  else if (cVar1 == '\x06') {
    if ((DAT_00fc0e40 & 1) == 0) {
      DAT_00fc0e40 = DAT_00fc0e40 | 1;
      local_c = 5;
      FUN_00540770();
      _atexit((_func_4879 *)&LAB_00bcdb60);
      local_c = 0xffffffff;
    }
    FUN_00540980(*(undefined2 *)((int)param_1 + 7));
    uVar2 = *(ushort *)((int)param_1 + 3);
    iVar4 = FUN_0040f060();
    *(uint *)(iVar4 + 0x8c) = (uint)uVar2;
  }
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_c = 6;
    FUN_00539c20();
    _atexit((_func_4879 *)&LAB_00bccfb0);
    local_c = 0xffffffff;
  }
  if (DAT_00fb7258 != 0) {
    uVar3 = 0;
    iVar4 = *(int *)(DAT_00fb7258 + 0x2c) - *(int *)(DAT_00fb7258 + 0x28) >> 2;
    if (iVar4 != 0) {
      piVar5 = *(int **)(DAT_00fb7258 + 0x28);
      do {
        if (*(char *)(*piVar5 + 10) != '\0') {
          uVar3 = uVar3 + 1;
        }
        piVar5 = piVar5 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      if (1 < uVar3) {
        if ((DAT_00faadd4 & 1) == 0) {
          DAT_00faadd4 = DAT_00faadd4 | 1;
          local_c = 7;
          FUN_00587480();
          _atexit((_func_4879 *)&LAB_00bcccc0);
          local_c = 0xffffffff;
        }
        FUN_0058aad0(0xf4406);
      }
    }
  }
  if ((*(char *)((int)param_1 + 2) == '\0') || (*(char *)((int)param_1 + 2) == '\x05')) {
    if ((DAT_00fc0f60 & 1) == 0) {
      DAT_00fc0f60 = DAT_00fc0f60 | 1;
      local_c = 8;
      FUN_0079cf40();
      _atexit((_func_4879 *)&LAB_00bcdb80);
      local_c = 0xffffffff;
    }
    FUN_0079d9c0(&DAT_00fc0e90,1);
    if ((DAT_00fd94d8 & 1) == 0) {
      DAT_00fd94d8 = DAT_00fd94d8 | 1;
      local_c = 9;
      FUN_007b5430();
      _atexit((_func_4879 *)&LAB_00bce660);
      local_c = 0xffffffff;
    }
    _DAT_00fd94b0 = 1;
    DAT_00fba830 = 0;
    if ((DAT_00fc0e40 & 1) == 0) {
      DAT_00fc0e40 = DAT_00fc0e40 | 1;
      local_c = 10;
      FUN_00540770();
      _atexit((_func_4879 *)&LAB_00bcdb60);
      local_c = 0xffffffff;
    }
    FUN_00540a40(*(undefined2 *)((int)param_1 + 3));
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 0xb;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
      local_c = 0xffffffff;
    }
    DAT_00fab1bc = (uint)*(ushort *)((int)param_1 + 3);
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 0xc;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
      local_c = 0xffffffff;
    }
    uVar3 = DAT_00fab1bc;
    if ((DAT_00fab29c & 1) == 0) {
      DAT_00fab29c = DAT_00fab29c | 1;
      local_c = 0xd;
      FUN_004ffe60();
      _atexit((_func_4879 *)&LAB_00bccf00);
      local_c = 0xffffffff;
    }
    FUN_00500240(&DAT_00fab2a0,uVar3);
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      local_c = 0xe;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
      local_c = 0xffffffff;
    }
    if ((DAT_00fab090 == (int *)0x0) && (DAT_00fab028 != (int *)0x0)) {
      DAT_00fab090 = (int *)(**(code **)(*DAT_00fab028 + 0x20))();
      (**(code **)(*DAT_00fab090 + 0x18))(3);
    }
    uVar6 = 2;
  }
  else {
    if ((DAT_00fc0f60 & 1) == 0) {
      DAT_00fc0f60 = DAT_00fc0f60 | 1;
      local_c = 0xf;
      FUN_0079cf40();
      _atexit((_func_4879 *)&LAB_00bcdb80);
      local_c = 0xffffffff;
    }
    FUN_0079d9c0(&DAT_00fc0e90,2);
    if ((DAT_00fd94d8 & 1) == 0) {
      DAT_00fd94d8 = DAT_00fd94d8 | 1;
      local_c = 0x10;
      FUN_007b5430();
      _atexit((_func_4879 *)&LAB_00bce660);
      local_c = 0xffffffff;
    }
    _DAT_00fd94b0 = 2;
    uVar2 = *(ushort *)((int)param_1 + 3);
    DAT_00fba830 = 1;
    iVar4 = FUN_0040f060();
    uVar3 = DAT_00fab0d4 & 1;
    *(uint *)(iVar4 + 0x90) = (uint)uVar2;
    if (uVar3 == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      local_c = 0x11;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
      local_c = 0xffffffff;
    }
    if ((DAT_00fab090 == (int *)0x0) && (DAT_00fab028 != (int *)0x0)) {
      DAT_00fab090 = (int *)(**(code **)(*DAT_00fab028 + 0x20))();
      (**(code **)(*DAT_00fab090 + 0x18))(3);
    }
    uVar6 = 4;
  }
  (**(code **)(*DAT_00fab090 + 0x18))(uVar6);
  ExceptionList = pvStack_18;
  return 0;
}

