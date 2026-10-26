
void FUN_00563c40(char *param_1)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined1 auStack_13c [4];
  char *local_138;
  int local_12c;
  char local_128 [268];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009364c0;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_13c;
  ExceptionList = &local_14;
  local_138 = param_1;
  if (param_1 != (char *)0x0) {
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c = 0;
      FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffeb8);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    uVar2 = DAT_00fab22c & 1;
    piVar4 = DAT_00fb76e8 + 3;
    piVar5 = *(int **)(in_ECX + 0x30);
    for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar5 = *piVar4;
      piVar4 = piVar4 + 1;
      piVar5 = piVar5 + 1;
    }
    if (uVar2 == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 1;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
    }
    local_c = 0xffffffff;
    *(undefined4 *)(in_ECX + 0x34) = DAT_00fab178;
    __splitpath_s(local_138,(char *)0x0,0,(char *)0x0,0,local_128,0x104,(char *)0x0,0);
    FUN_007c1e00(0);
    if ((DAT_00fc0fc0 & 1) == 0) {
      DAT_00fc0fc0 = DAT_00fc0fc0 | 1;
      local_c = 2;
      FUN_006d8e50();
      _atexit((_func_4879 *)&LAB_00bcdbb0);
      local_c = 0xffffffff;
    }
    FUN_006d9780();
    if ((*(int *)(DAT_00fba838 + 0x48) - *(int *)(DAT_00fba838 + 0x44) >> 2 != 0) &&
       (piVar4 = (int *)**(int **)(DAT_00fba838 + 0x44), piVar4 != (int *)0x0)) {
      local_12c = piVar4[2];
      iVar3 = *piVar4;
      iVar1 = piVar4[1];
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_c = 3;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_c = 0xffffffff;
      }
      piVar5 = DAT_00fb76e8;
      DAT_00fb76e8[3] = iVar3;
      piVar5[4] = iVar1;
      piVar5[5] = local_12c;
      piVar5[0x33] = 0;
      local_138 = (char *)piVar4[5];
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_c = 4;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_c = 0xffffffff;
      }
      piVar5 = DAT_00fb76e8;
      uVar2 = DAT_00fb79e8 & 1;
      DAT_00fb76e8[8] = (int)local_138;
      piVar5[0x33] = 0;
      local_138 = (char *)piVar4[9];
      if (uVar2 == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_c = 5;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_c = 0xffffffff;
      }
      piVar5 = DAT_00fb76e8;
      if (*DAT_00fb76e8 != 0) {
        *(char **)(*DAT_00fb76e8 + 0x7c) = local_138;
      }
      uVar2 = DAT_00fb79e8 & 1;
      piVar5[0xc] = (int)local_138;
      local_138 = (char *)piVar4[3];
      if (uVar2 == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_c = 6;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_c = 0xffffffff;
      }
      piVar5 = DAT_00fb76e8;
      uVar2 = DAT_00fb79e8 & 1;
      DAT_00fb76e8[6] = (int)local_138;
      piVar5[0x33] = 0;
      local_138 = (char *)piVar4[6];
      if (uVar2 == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_c = 7;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
      }
      piVar4 = DAT_00fb76e8;
      DAT_00fb76e8[9] = (int)local_138;
      piVar4[0x33] = 0;
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_13c);
  return;
}

