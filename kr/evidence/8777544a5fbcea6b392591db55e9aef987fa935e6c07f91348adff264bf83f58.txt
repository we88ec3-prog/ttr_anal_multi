
void FUN_005961c0(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  char cVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  int *in_ECX;
  undefined4 *puVar8;
  int *piVar9;
  bool bVar10;
  undefined4 *local_30;
  int local_2c;
  undefined4 *local_28;
  int local_24;
  int *local_20;
  undefined4 *local_1c;
  int *local_18;
  char local_13;
  char local_12;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093aeea;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = in_ECX;
  local_20 = (int *)FUN_00761010(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  puVar8 = (undefined4 *)0x0;
  local_11 = '\0';
  if ((local_20 != (int *)0x0) && (((uint)local_20[10] >> 0xd & 1) != 0)) {
    local_11 = '\x01';
  }
  if ((DAT_00fb73b8 & 1) == 0) {
    DAT_00fb73b8 = DAT_00fb73b8 | 1;
    local_8 = 0;
    FUN_00560170();
    _atexit((_func_4879 *)&LAB_00bcd110);
    local_8 = 0xffffffff;
  }
  local_13 = DAT_00fb73e8 != 0;
  do {
    local_12 = '\0';
    local_28 = puVar8;
    iVar6 = FUN_006d4ce0();
    if (((local_13 == '\0') || (puVar8 == (undefined4 *)0xd)) || (puVar8 == (undefined4 *)0xe)) {
      if (iVar6 == 1) {
        if (local_20 == (int *)0x0) {
LAB_00596284:
          cVar5 = local_12;
        }
        else {
          cVar4 = (**(code **)(*local_20 + 0xec))(puVar8);
          cVar5 = '\x01';
          if (cVar4 == '\0') goto LAB_00596284;
        }
        if (local_11 != '\0') goto LAB_0059634d;
        if ((cVar5 == '\0') && (cVar5 = FUN_00596140(1), cVar5 == '\0')) {
          cVar5 = (**(code **)(*in_ECX + 0xec))(puVar8);
          goto LAB_0059634d;
        }
      }
      else {
        if (iVar6 != 3) goto LAB_00596386;
        if ((local_20 != (int *)0x0) &&
           (cVar5 = (**(code **)(*local_20 + 0xf0))(puVar8), cVar5 != '\0')) {
          local_12 = '\x01';
        }
        cVar5 = local_12;
        if (local_11 == '\0') {
          if (local_12 == '\0') {
            local_1c = puVar8;
            FUN_0082ef00(&local_1c);
            if (local_24 != in_ECX[0x21]) {
              puVar2 = *(undefined4 **)(*(int *)(local_24 + 0x10) + 4);
              in_ECX = local_18;
              for (puVar1 = (undefined4 *)*puVar2; local_18 = in_ECX, puVar1 != puVar2;
                  puVar1 = (undefined4 *)*puVar1) {
                cVar5 = (**(code **)(*(int *)puVar1[2] + 0xf0))(puVar8);
                if (cVar5 != '\0') goto LAB_00596351;
                in_ECX = local_18;
              }
            }
            cVar5 = (**(code **)(*in_ECX + 0xf0))(puVar8);
            goto LAB_0059634d;
          }
          goto LAB_00596351;
        }
LAB_0059634d:
        if (cVar5 == '\0') goto LAB_00596386;
      }
LAB_00596351:
      iVar6 = *param_1;
      iVar7 = FUN_0074d700(iVar6,*(undefined4 *)(iVar6 + 4),&local_28);
      if (param_1[1] == 0x3ffffffe) goto LAB_00596433;
      param_1[1] = param_1[1] + 1;
      *(int *)(iVar6 + 4) = iVar7;
      **(int **)(iVar7 + 4) = iVar7;
      in_ECX = local_18;
    }
LAB_00596386:
    puVar8 = (undefined4 *)((int)puVar8 + 1);
  } while ((int)puVar8 < 0x28);
  if ((DAT_00fdf3ec & 1) == 0) {
    DAT_00fdf3ec = DAT_00fdf3ec | 1;
    local_8 = 1;
    FUN_006d1da0();
    _atexit((_func_4879 *)&LAB_00bce330);
    local_8 = 0xffffffff;
  }
  puVar8 = (undefined4 *)*DAT_00fdf624;
  puVar2 = DAT_00fdf624;
  local_1c = puVar8;
  if ((DAT_00fdf3ec & 1) == 0) {
    DAT_00fdf3ec = DAT_00fdf3ec | 1;
    local_8 = 2;
    FUN_006d1da0();
    _atexit((_func_4879 *)&LAB_00bce330);
    local_8 = 0xffffffff;
    puVar2 = DAT_00fdf624;
  }
  do {
    while( true ) {
      puVar1 = DAT_00fdf624;
      if (puVar8 == DAT_00fdf624) {
        DAT_00fdf624 = puVar2;
        ExceptionList = local_10;
        return;
      }
      puVar8 = (undefined4 *)local_1c[2];
      if ((local_13 == '\0') || (((undefined4 *)0x2af8 < puVar8 && (puVar8 < (undefined4 *)0x2afb)))
         ) break;
      local_1c = (undefined4 *)*local_1c;
      puVar8 = local_1c;
      DAT_00fdf624 = puVar1;
    }
    bVar10 = false;
    DAT_00fdf624 = puVar2;
    local_30 = puVar8;
    iVar6 = FUN_006d4ce0();
    if (iVar6 == 1) {
      if ((local_20 != (int *)0x0) &&
         (cVar5 = (**(code **)(*local_20 + 0xec))(puVar8), cVar5 != '\0')) {
        bVar10 = true;
      }
      piVar9 = local_18;
      if (local_11 == '\0') {
        if (!bVar10) {
          local_28 = puVar8;
          FUN_0082ef00(&local_28);
          if (local_24 != piVar9[0x21]) {
            puVar2 = *(undefined4 **)(*(int *)(local_24 + 0x10) + 4);
            piVar9 = local_18;
            for (puVar3 = (undefined4 *)*puVar2; local_18 = piVar9, puVar3 != puVar2;
                puVar3 = (undefined4 *)*puVar3) {
              cVar5 = (**(code **)(*(int *)puVar3[2] + 0xf0))(puVar8);
              if (cVar5 != '\0') goto LAB_00596570;
              piVar9 = local_18;
            }
          }
          cVar5 = (**(code **)(*piVar9 + 0xec))(puVar8);
          bVar10 = cVar5 == '\0';
          goto LAB_0059656e;
        }
      }
      else {
LAB_0059656c:
        bVar10 = !bVar10;
LAB_0059656e:
        if (bVar10) goto LAB_005965a2;
      }
LAB_00596570:
      iVar6 = *param_1;
      iVar7 = FUN_0074d700(iVar6,*(undefined4 *)(iVar6 + 4),&local_30);
      if (param_1[1] == 0x3ffffffe) {
LAB_00596433:
                    /* WARNING: Subroutine does not return */
        FUN_0087db30("list<T> too long");
      }
      param_1[1] = param_1[1] + 1;
      *(int *)(iVar6 + 4) = iVar7;
      **(int **)(iVar7 + 4) = iVar7;
    }
    else if (iVar6 == 3) {
      if ((local_20 != (int *)0x0) &&
         (cVar5 = (**(code **)(*local_20 + 0xf0))(puVar8), cVar5 != '\0')) {
        bVar10 = true;
      }
      piVar9 = local_18;
      if (local_11 == '\0') {
        if (!bVar10) {
          local_28 = puVar8;
          FUN_0082ef00(&local_28);
          if (local_2c != piVar9[0x21]) {
            puVar2 = *(undefined4 **)(*(int *)(local_2c + 0x10) + 4);
            piVar9 = local_18;
            for (puVar3 = (undefined4 *)*puVar2; local_18 = piVar9, puVar3 != puVar2;
                puVar3 = (undefined4 *)*puVar3) {
              cVar5 = (**(code **)(*(int *)puVar3[2] + 0xf0))(puVar8);
              if (cVar5 != '\0') goto LAB_00596570;
              piVar9 = local_18;
            }
          }
          cVar5 = (**(code **)(*piVar9 + 0xf0))(puVar8);
          bVar10 = cVar5 == '\0';
          goto LAB_0059656e;
        }
        goto LAB_00596570;
      }
      goto LAB_0059656c;
    }
LAB_005965a2:
    local_1c = (undefined4 *)*local_1c;
    puVar2 = DAT_00fdf624;
    puVar8 = local_1c;
    DAT_00fdf624 = puVar1;
  } while( true );
}

