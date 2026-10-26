
void FUN_006d4dc0(uint param_1,int param_2)

{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int *piVar5;
  uint *in_ECX;
  int iVar6;
  int iVar7;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00926818;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_1 - 0x2711 < 9999) {
    param_1 = 0;
    puVar1 = &DAT_00fdf3f4 + param_2 * 0x10;
    while( true ) {
      if ((DAT_00fdf3ec & 1) == 0) {
        DAT_00fdf3ec = DAT_00fdf3ec | 1;
        local_8 = 0;
        FUN_006d1da0();
        _atexit((_func_4879 *)&LAB_00bce330);
        local_8 = 0xffffffff;
      }
      piVar5 = (int *)FUN_006d43f0(puVar1);
      if ((uint)(piVar5[1] - *piVar5 >> 2) <= param_1) break;
      if ((DAT_00fdf3ec & 1) == 0) {
        DAT_00fdf3ec = DAT_00fdf3ec | 1;
        local_8 = 1;
        FUN_006d1da0();
        _atexit((_func_4879 *)&LAB_00bce330);
        local_8 = 0xffffffff;
      }
      piVar5 = (int *)FUN_006d43f0(puVar1);
      if ((piVar5[1] - *piVar5 & 0xfffffffcU) == 0) {
        FUN_004a8680();
        param_1 = param_1 + 1;
      }
      else {
        FUN_006d43f0(puVar1);
        FUN_004a8680();
        param_1 = param_1 + 1;
      }
    }
    ExceptionList = local_10;
    return;
  }
  iVar6 = (param_1 + param_2 * 0x28) * 0x10;
  local_14 = 0;
  piVar5 = (int *)(&DAT_00fb8834 + iVar6);
  do {
    while( true ) {
      if ((DAT_00fb7c14 & 1) == 0) {
        DAT_00fb7c14 = DAT_00fb7c14 | 1;
        local_8 = 2;
        FUN_006d0750(uVar4);
        _atexit((_func_4879 *)&LAB_00bcd530);
        local_8 = 0xffffffff;
      }
      if ((uint)(*(int *)(&DAT_00fb8838 + iVar6) - *piVar5 >> 2) <= local_14) {
        ExceptionList = local_10;
        return;
      }
      if ((DAT_00fb7c14 & 1) == 0) {
        DAT_00fb7c14 = DAT_00fb7c14 | 1;
        local_8 = 3;
        FUN_006d0750(uVar4);
        _atexit((_func_4879 *)&LAB_00bcd530);
        local_8 = 0xffffffff;
      }
      if ((*(int *)(&DAT_00fb8838 + iVar6) - *piVar5 & 0xfffffffcU) == 0) {
        iVar7 = 0;
      }
      else {
        iVar7 = *(int *)(*piVar5 + local_14 * 4);
      }
      puVar2 = (undefined4 *)in_ECX[1];
      param_1 = iVar7;
      if (puVar2 <= &param_1) break;
      puVar3 = (undefined4 *)*in_ECX;
      if (&param_1 < puVar3) break;
      if (puVar2 == (undefined4 *)in_ECX[2]) {
        FUN_006d6240();
      }
      if ((undefined4 *)in_ECX[1] == (undefined4 *)0x0) goto LAB_006d4feb;
      *(undefined4 *)in_ECX[1] = *(undefined4 *)(*in_ECX + ((int)&param_1 - (int)puVar3 >> 2) * 4);
      in_ECX[1] = in_ECX[1] + 4;
      local_14 = local_14 + 1;
    }
    if (puVar2 == (undefined4 *)in_ECX[2]) {
      FUN_006d6240();
    }
    if ((int *)in_ECX[1] != (int *)0x0) {
      *(int *)in_ECX[1] = iVar7;
    }
LAB_006d4feb:
    in_ECX[1] = in_ECX[1] + 4;
    local_14 = local_14 + 1;
  } while( true );
}

