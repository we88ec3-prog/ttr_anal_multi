
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d65e0(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  undefined4 unaff_ESI;
  int iVar3;
  undefined4 uVar4;
  undefined1 auStack_80 [12];
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined1 *puStack_6c;
  int iVar5;
  int iStack_4c;
  int iStack_48;
  undefined1 *puStack_44;
  uint uStack_24;
  void *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0094369a;
  local_14 = ExceptionList;
  local_1c = (void *)(DAT_00d61f20 ^ (uint)&iStack_4c);
  ExceptionList = &local_14;
  FUN_007459c0();
  iVar1 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_005d6658;
    iVar1 = FUN_00745c20();
  }
  if ((((iVar1 != 0) && (*(int *)(iVar1 + 0x60) != 0)) &&
      ((*(uint *)(iVar1 + 0x28) >> 0xc & 1) == 0)) && (*(int *)(iVar1 + 0x60) != 0)) {
    FUN_0074a010();
  }
LAB_005d6658:
  if ((DAT_00fab100 & 1) == 0) {
    DAT_00fab100 = DAT_00fab100 | 1;
    local_c = 0;
    FUN_0049d6a0();
    _atexit((_func_4879 *)&LAB_00bcce20);
    local_c = 0xffffffff;
  }
  if (((DAT_00fab104 & 0x20) == 0) && (DAT_00fab128 == '\0')) {
    (**(code **)(**(int **)(in_ECX + 0x110) + 0x90))();
  }
  else {
    (**(code **)(**(int **)(in_ECX + 0x110) + 0x90))();
  }
  (**(code **)(**(int **)(in_ECX + 0x114) + 0x90))();
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    puStack_6c = (undefined1 *)0x5d66f1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  iVar1 = CONCAT22((short)((uint)unaff_ESI >> 0x10),0xa8);
  if (DAT_00fba798 == 0) {
    puStack_6c = &stack0xffffffac;
    uStack_70 = 0;
    uStack_74 = 0x5d671d;
    (**(code **)(*DAT_00fba854 + 0x10))();
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_14 = (void *)0x1;
    FUN_004e1590();
    puStack_6c = (undefined1 *)0x5d673f;
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_14 = (void *)0xffffffff;
  }
  if ((*(int *)(in_ECX + 0xf4) == 1) && (DAT_00f94300 + 0x16f8 != 0)) {
    if (*(int *)(in_ECX + 0xf8) - 1U < 100) {
      iStack_4c = *(int *)(in_ECX + 0xf8) * 0x20 + DAT_00f94300 + 0x16f8;
      if ((((*(int *)(iStack_4c + 0xc) != 0) && (*(int *)(iStack_4c + 8) != 0)) && (iStack_4c != 0))
         && (*(int *)(iStack_4c + 0x10) != 0)) {
        iVar2 = FUN_00404c10();
        puStack_6c = (undefined1 *)0x5d67d5;
        FUN_008438c0();
        if ((iVar1 != *(int *)(iVar2 + 4)) && (*(int *)(iVar1 + 0x10) != 0)) {
          FUN_00757710();
        }
        iVar2 = FUN_004146b0();
        puStack_6c = (undefined1 *)0x5d6825;
        FUN_008438c0();
        if (iVar1 == *(int *)(iVar2 + 0x18)) {
          uVar4 = 0;
        }
        else {
          uVar4 = *(undefined4 *)(iVar1 + 0x10);
        }
        *(undefined4 *)(in_ECX + 0x118) = uVar4;
        FUN_0075ce00();
        iVar1 = *(int *)(in_ECX + 0x118);
        if (iVar1 != 0) {
          iVar1 = (*(int *)(iVar1 + 0x58) - *(int *)(iVar1 + 0x54)) / 0xc;
          iVar2 = 0;
          in_ECX = iStack_48;
          if (0 < iVar1) {
            iVar5 = 0;
            do {
              in_ECX = iStack_48;
              if (0x47 < iVar5) break;
              iVar3 = *(int *)(*(int *)(iStack_48 + 0x118) + 0x54) + iVar5;
              puStack_44 = auStack_80;
              if (*(int *)(iVar3 + 4) == 0) {
                FUN_00412df0();
                uVar4 = 0x101;
                local_14 = (void *)0x4;
                FUN_005854b0(0x101);
                uVar4 = FUN_00585330(uVar4);
                local_14 = (void *)0xffffffff;
                FUN_00424c80(uVar4);
                local_14 = (void *)0x5;
              }
              else {
                puStack_44 = auStack_80;
                FUN_00412df0();
                local_14 = (void *)0x2;
                uVar4 = 0x102;
                FUN_005854b0(0x102,*(undefined4 *)(iVar3 + 4));
                uVar4 = FUN_00585330(uVar4);
                local_14 = (void *)0xffffffff;
                FUN_004183b0(uVar4);
                local_14 = (void *)0x3;
              }
              puStack_6c = (undefined1 *)0x5d6974;
              FUN_0075cbb0();
              local_14 = (void *)0xffffffff;
              FUN_004fa440();
              iVar5 = iVar5 + 0xc;
              iVar2 = iVar2 + 1;
              in_ECX = iStack_48;
            } while (iVar2 < iVar1);
          }
        }
        if (*(int *)(*(int *)(in_ECX + 0x104) + 0x24c) != 0) {
          puStack_6c = (undefined1 *)0x5d69b1;
          FUN_00749920();
        }
        if ((DAT_00f94394 & 1) == 0) {
          DAT_00f94394 = DAT_00f94394 | 1;
          local_14 = (void *)0x6;
          FUN_005c3de0();
          puStack_6c = (undefined1 *)0x5d69d8;
          _atexit((_func_4879 *)&LAB_00bccc30);
          local_14 = (void *)0xffffffff;
        }
        if (DAT_00f943e4 != 0) {
          iStack_4c = *(int *)(iStack_4c + 4);
          puStack_6c = (undefined1 *)0x5d6a09;
          FUN_0082ef00();
        }
        FUN_00745060();
        (**(code **)(**(int **)(in_ECX + 0xfc) + 200))();
      }
    }
    else {
      puStack_6c = (undefined1 *)0x5d683f;
      FUN_006edb60();
    }
    FUN_005d6240();
  }
  ExceptionList = local_1c;
  __security_check_cookie(uStack_24 ^ (uint)&stack0xffffffac);
  return;
}

