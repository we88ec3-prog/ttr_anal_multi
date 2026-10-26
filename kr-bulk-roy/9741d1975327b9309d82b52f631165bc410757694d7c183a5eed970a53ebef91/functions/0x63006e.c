
/* WARNING (jumptable): Unable to track spacebase fully for stack */

void FUN_0063006e(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  code *pcVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 *puVar10;
  int unaff_EBX;
  undefined4 *in_stack_00000014;
  int in_stack_00000018;
  undefined4 in_stack_0000001c;
  int in_stack_00000020;
  int in_stack_00000024;
  int in_stack_00000028;
  int in_stack_0000002c;
  int in_stack_00000030;
  int in_stack_00000034;
  undefined4 in_stack_00000038;
  undefined4 in_stack_00000040;
  int in_stack_00000044;
  undefined4 *in_stack_00000048;
  int in_stack_0000004c;
  int in_stack_00000050;
  int in_stack_00000054;
  int in_stack_00000058;
  int in_stack_0000005c;
  int in_stack_00000060;
  undefined4 *in_stack_00000064;
  int in_stack_00000068;
  undefined4 in_stack_0000006c;
  uint in_stack_00000080;
  uint in_stack_00000088;
  void *in_stack_00000090;
  undefined1 uStack00000098;
  uint3 uStack00000099;
  undefined2 local_1c [6];
  undefined4 uStack_10;
  undefined4 *local_c;
  undefined4 local_8;
  
  do {
    iVar7 = in_stack_00000018;
    FUN_00757710();
    *(undefined4 *)(*(int *)(iVar7 + 0x248) + 0x154) = 0xff0099ff;
LAB_00630285:
    if (in_stack_0000001c._3_1_ == '\0') {
      local_8 = 0x6303a4;
      FUN_00757800();
      uVar6 = DAT_00fab100 & 1;
      *(undefined4 *)(iVar7 + 0x154) = 0xffffffff;
      if (uVar6 == 0) {
        _uStack00000098 = CONCAT31(uStack00000099,0x10);
        goto LAB_006303c6;
      }
    }
    else {
      in_stack_00000014 = (undefined4 *)local_1c;
      local_8 = 7;
      local_c = (undefined4 *)0x0;
      local_1c[0] = 0;
      FUN_004026e0(unaff_EBX + 0x4c,0,0xffffffff);
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        uStack00000098 = 10;
        FUN_00584c40(&DAT_00fe5ac4);
        _atexit((_func_4879 *)&LAB_00bcf390);
      }
      uStack00000098 = 9;
      in_stack_00000014 = (undefined4 *)0x287;
      FUN_005740f0(&stack0x00000014);
      if (in_stack_00000054 == DAT_00fe5ac8) {
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      puVar8 = (undefined4 *)(in_stack_00000054 + 0x10);
      if (7 < *(uint *)(in_stack_00000054 + 0x24)) {
        puVar8 = (undefined4 *)*puVar8;
      }
      uStack00000098 = 0;
      FUN_00424c80(puVar8);
      _uStack00000098 = CONCAT31(uStack00000099,0xb);
      local_8 = 0x63035d;
      FUN_00757800();
      if (7 < in_stack_00000080) {
        local_8 = 0x630371;
        FUN_0089120c();
      }
      uVar6 = DAT_00fab100 & 1;
      *(undefined4 *)(iVar7 + 0x154) = 0xffffff57;
      if (uVar6 == 0) {
        _uStack00000098 = CONCAT31(uStack00000099,0xc);
LAB_006303c6:
        DAT_00fab100 = DAT_00fab100 | 1;
        FUN_0049d6a0();
        local_8 = 0x6303d5;
        _atexit((_func_4879 *)&LAB_00bcce20);
      }
    }
    do {
      _uStack00000098 = 0xffffffff;
      if (in_stack_00000030 != 0) {
        local_8 = 0x6303f3;
        FUN_0089120c();
      }
      in_stack_00000030 = 0;
      in_stack_00000034 = 0;
      in_stack_00000038 = 0;
      do {
        in_stack_0000002c = in_stack_0000002c + 1;
        if (in_stack_0000005c <= in_stack_0000002c) {
          piVar2 = *(int **)(in_stack_00000020 + 0x110);
          puVar8 = (undefined4 *)piVar2[0x19];
          for (puVar10 = (undefined4 *)*puVar8; puVar10 != puVar8; puVar10 = (undefined4 *)*puVar10)
          {
            if ((*(int *)(puVar10[2] + 0x60) != 0) &&
               (piVar3 = *(int **)(puVar10[2] + 0x1c), piVar3[2] != 6)) {
              local_8 = 0x63044a;
              (**(code **)(*piVar3 + 0x30))();
            }
          }
          (**(code **)(*piVar2 + 0x128))();
          (**(code **)(**(int **)(in_stack_00000020 + 0x110) + 200))();
          ExceptionList = in_stack_00000090;
          __security_check_cookie(in_stack_00000088 ^ (uint)&stack0x00000010);
          return;
        }
        iVar7 = *(int *)(*(int *)(in_stack_00000020 + 0x114) + in_stack_0000002c * 4);
        in_stack_00000024 = iVar7;
      } while (iVar7 == 0);
      in_stack_0000001c._3_1_ = '\0';
      in_stack_00000030 = 0;
      in_stack_00000034 = 0;
      in_stack_00000038 = 0;
      _uStack00000098 = 0;
      if ((DAT_00fab29c & 1) == 0) {
        DAT_00fab29c = DAT_00fab29c | 1;
        uStack00000098 = 1;
        uStack00000099 = 0;
        FUN_004ffe60();
        local_8 = 0x62fb66;
        _atexit((_func_4879 *)&LAB_00bccf00);
        _uStack00000098 = (uint)uStack00000099 << 8;
      }
      local_8 = *(undefined4 *)(iVar7 + 0x2c);
      local_c = &DAT_00fab2a0;
      uStack_10 = 0x62fb84;
      FUN_00500e00();
      iVar5 = in_stack_00000034 - in_stack_00000030 >> 2;
      iVar9 = 0;
      if (0 < iVar5) {
        do {
          if (iVar7 == *(int *)(in_stack_00000030 + iVar9 * 4)) {
            in_stack_0000001c._3_1_ = '\x01';
            break;
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 < iVar5);
      }
    } while (*(int *)(iVar7 + 4) != 1);
    piVar2 = *(int **)(*(int *)(in_stack_00000020 + 0x110) + 0xcc);
    if (piVar2 == (int *)0x0) {
LAB_0062fcc6:
      in_stack_00000018 = 0;
    }
    else {
      iVar7 = piVar2[0x39];
      if ((int *)piVar2[0x29] == (int *)0x0) goto LAB_0062fcc6;
      iVar5 = *(int *)piVar2[0x29];
      if (piVar2[0x2e] == piVar2[0x2f]) {
        iVar9 = (**(code **)(iVar5 + 0x28))();
        in_stack_00000028 = iVar9;
      }
      else {
        iVar9 = *(int *)(piVar2[0x2f] + -4);
        local_8 = 0x62fc0e;
        in_stack_00000028 = iVar9;
        (**(code **)(iVar5 + 0x2c))();
        if (piVar2[0x2e] != piVar2[0x2f]) {
          piVar2[0x2f] = piVar2[0x2f] + -4;
        }
      }
      *(int *)(iVar9 + 0x20) = iVar7;
      local_8 = 0x62fc36;
      in_stack_00000018 = iVar9;
      (**(code **)(*piVar2 + 0x70))();
      puVar8 = (undefined4 *)piVar2[0x2b];
      if (&stack0x00000018 < puVar8) {
        puVar10 = (undefined4 *)piVar2[0x2a];
        if (&stack0x00000018 < puVar10) goto LAB_0062fc85;
        if (puVar8 == (undefined4 *)piVar2[0x2c]) {
          FUN_004deab0();
        }
        if ((undefined4 *)piVar2[0x2b] != (undefined4 *)0x0) {
          *(undefined4 *)piVar2[0x2b] =
               *(undefined4 *)(piVar2[0x2a] + ((int)&stack0x00000018 - (int)puVar10 >> 2) * 4);
        }
      }
      else {
LAB_0062fc85:
        if (puVar8 == (undefined4 *)piVar2[0x2c]) {
          FUN_004deab0();
        }
        if ((int *)piVar2[0x2b] != (int *)0x0) {
          *(int *)piVar2[0x2b] = iVar9;
        }
      }
      piVar2[0x2b] = piVar2[0x2b] + 4;
      uVar6 = iVar7 + 1;
      if (uVar6 <= (uint)piVar2[0x39]) {
        uVar6 = piVar2[0x39];
      }
      piVar2[0x39] = uVar6;
      in_stack_00000018 = in_stack_00000028;
    }
    FUN_00630a50();
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      uStack00000098 = 2;
      FUN_005c3de0();
      local_8 = 0x62fcf8;
      _atexit((_func_4879 *)&LAB_00bccc30);
      _uStack00000098 = (uint)uStack00000099 << 8;
    }
    cVar1 = *(char *)((int)DAT_00f94574[1] + 0x15);
    puVar8 = (undefined4 *)DAT_00f94574[1];
    in_stack_00000014 = DAT_00f94574;
    while (puVar10 = puVar8, cVar1 == '\0') {
      if ((uint)puVar10[3] < *(uint *)(in_stack_00000024 + 0x24)) {
        puVar8 = (undefined4 *)puVar10[2];
        puVar10 = in_stack_00000014;
      }
      else {
        puVar8 = (undefined4 *)*puVar10;
      }
      cVar1 = *(char *)((int)puVar8 + 0x15);
      in_stack_00000014 = puVar10;
    }
    if ((in_stack_00000014 == DAT_00f94574) ||
       (*(uint *)(in_stack_00000024 + 0x24) < (uint)in_stack_00000014[3])) {
      in_stack_00000048 = DAT_00f94574;
      puVar8 = &stack0x00000048;
    }
    else {
      puVar8 = &stack0x00000014;
    }
    if ((undefined4 *)*puVar8 == DAT_00f94574) {
      iVar7 = 0;
    }
    else {
      iVar7 = ((undefined4 *)*puVar8)[4];
    }
    iVar5 = *(int *)(in_stack_00000018 + 0x24c);
    if ((((*(char *)(iVar5 + 0xa4) != '\0') && (*(int **)(iVar5 + 0x94) != (int *)0x0)) &&
        (iVar9 = (**(code **)(**(int **)(iVar5 + 0x94) + 4))(), iVar9 == 0xbf6b)) &&
       (iVar5 = *(int *)(iVar5 + 0x94), *(int *)(iVar5 + 0x10) != iVar7)) {
      if (((iVar7 != 0) && (piVar2 = *(int **)(iVar7 + 8), piVar2 != (int *)0x0)) &&
         (piVar2[0x27] = piVar2[0x27] + 1, piVar2[0x27] == 1)) {
        (**(code **)(*piVar2 + 0x24))();
      }
      if ((*(int *)(iVar5 + 0x10) != 0) &&
         (piVar2 = *(int **)(*(int *)(iVar5 + 0x10) + 8), piVar2 != (int *)0x0)) {
        piVar3 = piVar2 + 0x27;
        *piVar3 = *piVar3 + -1;
        if (*piVar3 == 0) {
          (**(code **)(*piVar2 + 0x28))();
        }
      }
      *(int *)(iVar5 + 0x10) = iVar7;
    }
    if ((DAT_00fe17b8 & 1) == 0) {
      DAT_00fe17b8 = DAT_00fe17b8 | 1;
      uStack00000098 = 3;
      FUN_0050caf0();
      local_8 = 0x62fe04;
      _atexit((_func_4879 *)&LAB_00bce7e0);
      _uStack00000098 = (uint)uStack00000099 << 8;
    }
    cVar1 = *(char *)((int)DAT_00fe17e4[1] + 0x31);
    puVar8 = (undefined4 *)DAT_00fe17e4[1];
    in_stack_00000014 = DAT_00fe17e4;
    while (puVar10 = puVar8, cVar1 == '\0') {
      if ((int)puVar10[3] < *(int *)(in_stack_00000024 + 0x24)) {
        puVar8 = (undefined4 *)puVar10[2];
        puVar10 = in_stack_00000014;
      }
      else {
        puVar8 = (undefined4 *)*puVar10;
      }
      cVar1 = *(char *)((int)puVar8 + 0x31);
      in_stack_00000014 = puVar10;
    }
    if ((in_stack_00000014 == DAT_00fe17e4) ||
       (*(int *)(in_stack_00000024 + 0x24) < (int)in_stack_00000014[3])) {
      in_stack_00000064 = DAT_00fe17e4;
      puVar8 = &stack0x00000064;
    }
    else {
      puVar8 = &stack0x00000014;
    }
    puVar8 = (undefined4 *)*puVar8;
    if ((puVar8 != DAT_00fe17e4) && (puVar8 != (undefined4 *)0xfffffff0)) {
      if ((DAT_00f94394 & 1) == 0) {
        DAT_00f94394 = DAT_00f94394 | 1;
        uStack00000098 = 4;
        FUN_005c3de0();
        local_8 = 0x62fe9b;
        _atexit((_func_4879 *)&LAB_00bccc30);
        _uStack00000098 = (uint)uStack00000099 << 8;
      }
      in_stack_00000014 = (undefined4 *)puVar8[5];
      local_8 = 0x62fec6;
      FUN_0082ef00();
      if (((*(char *)(*(int *)(in_stack_00000018 + 0x250) + 0xa4) != '\0') &&
          (piVar2 = *(int **)(*(int *)(in_stack_00000018 + 0x250) + 0x94), piVar2 != (int *)0x0)) &&
         (iVar7 = (**(code **)(*piVar2 + 4))(), iVar7 == 0xbf6b)) {
        FUN_0077b200();
      }
    }
    unaff_EBX = in_stack_00000024;
    iVar7 = in_stack_00000018;
    if (*(int *)(in_stack_00000024 + 4) == 2) {
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        uStack00000098 = 5;
        local_8 = 0x62ff3d;
        FUN_00584c40();
        local_8 = 0x62ff47;
        _atexit((_func_4879 *)&LAB_00bcf390);
        _uStack00000098 = (uint)uStack00000099 << 8;
      }
      in_stack_00000014 = (undefined4 *)0x28c;
      local_8 = 0x62ff6d;
      FUN_005740f0();
      iVar7 = in_stack_00000018;
      if (in_stack_00000068 == DAT_00fe5ac8) {
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      FUN_00757710();
      *(undefined4 *)(*(int *)(iVar7 + 0x248) + 0x154) = 0xff0099ff;
      goto LAB_00630285;
    }
    switch(*(undefined4 *)(in_stack_00000024 + 8)) {
    case 1:
      if (*(int *)(in_stack_00000024 + 4) == 1) {
        in_stack_00000014 = (undefined4 *)0x28c;
        iVar5 = FUN_00585620();
        local_8 = 0x62ffee;
        FUN_005740f0();
        iVar7 = in_stack_00000018;
        if (in_stack_00000050 == *(int *)(iVar5 + 4)) {
          pcVar4 = (code *)swi(3);
          (*pcVar4)();
          return;
        }
        FUN_00757710();
        *(undefined4 *)(*(int *)(iVar7 + 0x248) + 0x154) = 0xff0099ff;
        goto LAB_00630285;
      }
      in_stack_00000014 = (undefined4 *)0x288;
      iVar7 = FUN_00585620();
      local_8 = 0x630055;
      FUN_005740f0();
      if (in_stack_00000060 == *(int *)(iVar7 + 4)) {
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      break;
    case 2:
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        uStack00000098 = 6;
        local_8 = 0x6300bf;
        FUN_00584c40();
        local_8 = 0x6300c9;
        _atexit((_func_4879 *)&LAB_00bcf390);
        _uStack00000098 = (uint)uStack00000099 << 8;
      }
      in_stack_00000014 = (undefined4 *)0x289;
      local_8 = 0x6300ef;
      FUN_005740f0();
      iVar7 = in_stack_00000018;
      if (in_stack_00000058 == DAT_00fe5ac8) {
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      FUN_00757710();
      *(undefined4 *)(*(int *)(iVar7 + 0x248) + 0x154) = 0xffff9900;
      goto LAB_00630285;
    case 3:
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        uStack00000098 = 7;
        local_8 = 0x63015a;
        FUN_00584c40();
        local_8 = 0x630164;
        _atexit((_func_4879 *)&LAB_00bcf390);
        _uStack00000098 = (uint)uStack00000099 << 8;
      }
      in_stack_00000014 = (undefined4 *)0x28a;
      local_8 = 0x63018a;
      FUN_005740f0();
      iVar7 = in_stack_00000018;
      if (in_stack_00000044 == DAT_00fe5ac8) {
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      FUN_00757710();
      *(undefined4 *)(*(int *)(iVar7 + 0x248) + 0x154) = 0xffcccccc;
      goto LAB_00630285;
    case 4:
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        uStack00000098 = 8;
        local_8 = 0x6301f5;
        FUN_00584c40();
        local_8 = 0x6301ff;
        _atexit((_func_4879 *)&LAB_00bcf390);
        _uStack00000098 = (uint)uStack00000099 << 8;
      }
      in_stack_00000014 = (undefined4 *)0x28b;
      local_8 = 0x630225;
      FUN_005740f0();
      iVar7 = in_stack_00000018;
      if (in_stack_0000004c == DAT_00fe5ac8) {
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      FUN_00757710();
      *(undefined4 *)(*(int *)(iVar7 + 0x248) + 0x154) = 0xffcc3333;
      goto LAB_00630285;
    default:
      FUN_00757710();
      goto LAB_00630285;
    }
  } while( true );
}

