
void FUN_005fff60(undefined *param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 *puVar8;
  char *pcVar9;
  undefined *in_ECX;
  undefined *puVar10;
  undefined1 *puVar11;
  undefined1 auStack_214 [20];
  undefined4 uStack_200;
  undefined2 *puStack_1fc;
  undefined1 auStack_1f8 [12];
  undefined4 uStack_1ec;
  undefined4 uStack_1e8;
  undefined *puStack_1e4;
  undefined *puStack_1e0;
  undefined *puStack_1dc;
  undefined *local_1c4;
  undefined *local_1c0;
  int local_1bc;
  undefined1 *local_1b8;
  undefined1 *local_1b4;
  undefined *local_1b0;
  undefined1 *puStack_1ac;
  undefined1 *puStack_1a8;
  undefined auStack_1a4 [112];
  undefined auStack_134 [56];
  undefined auStack_fc [56];
  undefined auStack_c4 [56];
  undefined auStack_8c [56];
  undefined auStack_54 [56];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00946ed8;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_1c4;
  ExceptionList = &local_14;
  puVar10 = *(undefined **)(in_ECX + 0xf0);
  local_1c4 = param_1;
  local_1c0 = puVar10;
  local_1b0 = in_ECX;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    puStack_1dc = (undefined *)0x5fffe1;
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if ((puVar10 != (undefined *)0x1) || (DAT_00f94300 + 0x16f8 == 0)) {
    puStack_1e0 = &DAT_00c292c8;
    puStack_1e4 = (undefined *)0x60001b;
    puStack_1dc = puVar10;
    FUN_006edb60();
    goto switchD_0060042b_caseD_6;
  }
  if (((int)param_1 < 1) || (100 < (int)param_1)) {
    puStack_1dc = (undefined *)0x600065;
    FUN_006edb60();
    puStack_1e0 = &DAT_00c292ec;
    puStack_1e4 = (undefined *)0x600074;
    puStack_1dc = puVar10;
    FUN_006edb60();
    goto switchD_0060042b_caseD_6;
  }
  local_1bc = DAT_00f94300 + 0x16f8 + (int)param_1 * 0x20;
  if (((*(int *)(local_1bc + 0xc) == 0) || (*(int *)(local_1bc + 8) == 0)) || (local_1bc == 0)) {
    puStack_1e0 = &DAT_00c292ec;
    puStack_1e4 = (undefined *)0x600053;
    puStack_1dc = puVar10;
    FUN_006edb60();
    goto switchD_0060042b_caseD_6;
  }
  iVar5 = **(int **)(in_ECX + 0x110);
  if (iVar5 == 1) {
    puStack_1dc = *(undefined **)(in_ECX + 0xf0);
    puStack_1e4 = (undefined *)0x600097;
    puStack_1e0 = in_ECX;
    FUN_00601bb0();
    goto switchD_0060042b_caseD_6;
  }
  if (iVar5 == 2) {
    puStack_1dc = (undefined *)0x6000ad;
    FUN_00602430();
    goto switchD_0060042b_caseD_6;
  }
  if (iVar5 == 3) {
    puStack_1dc = *(undefined **)(in_ECX + 0xf0);
    puStack_1e0 = (undefined *)0x6000c4;
    FUN_00602790();
    goto switchD_0060042b_caseD_6;
  }
  if (iVar5 == 4) {
    puStack_1dc = *(undefined **)(in_ECX + 0xf0);
    puStack_1e0 = (undefined *)0x6000db;
    FUN_00602860();
    goto switchD_0060042b_caseD_6;
  }
  if (iVar5 == 5) {
    puStack_1dc = *(undefined **)(in_ECX + 0xf0);
    puStack_1e0 = (undefined *)0x6000f2;
    FUN_00602b80();
    goto switchD_0060042b_caseD_6;
  }
  if (iVar5 == 6) {
    puStack_1dc = *(undefined **)(in_ECX + 0xf0);
    puStack_1e0 = (undefined *)0x600109;
    FUN_00602d20();
    goto switchD_0060042b_caseD_6;
  }
  if (iVar5 == 7) {
    puStack_1dc = *(undefined **)(in_ECX + 0xf0);
    puStack_1e0 = (undefined *)0x600120;
    FUN_00602c50();
    goto switchD_0060042b_caseD_6;
  }
  if (iVar5 == 8) {
    puStack_1dc = *(undefined **)(in_ECX + 0xf0);
    puStack_1e0 = (undefined *)0x600137;
    FUN_00602df0();
    goto switchD_0060042b_caseD_6;
  }
  if (iVar5 == 10) {
    puStack_1dc = *(undefined **)(in_ECX + 0xf0);
    puStack_1e0 = (undefined *)0x60014e;
    FUN_00602f90();
    goto switchD_0060042b_caseD_6;
  }
  if (iVar5 == 9) {
    puStack_1dc = *(undefined **)(in_ECX + 0xf0);
    puStack_1e0 = (undefined *)0x600165;
    FUN_00602ec0();
    goto switchD_0060042b_caseD_6;
  }
  if (iVar5 == 0xb) {
    puStack_1dc = *(undefined **)(in_ECX + 0xf0);
    puStack_1e0 = (undefined *)0x60017c;
    FUN_00603060();
    goto switchD_0060042b_caseD_6;
  }
  if (iVar5 == 0xc) {
    puStack_1dc = *(undefined **)(in_ECX + 0xf0);
    puStack_1e0 = (undefined *)0x600193;
    FUN_00603130();
    goto switchD_0060042b_caseD_6;
  }
  if (iVar5 == 0xd) {
    puStack_1dc = *(undefined **)(in_ECX + 0xf0);
    puStack_1e0 = (undefined *)0x6001aa;
    FUN_00603200();
    goto switchD_0060042b_caseD_6;
  }
  if (iVar5 == 0xe) {
    puStack_1dc = *(undefined **)(in_ECX + 0xf0);
    puStack_1e0 = (undefined *)0x6001c1;
    FUN_00603970();
    goto switchD_0060042b_caseD_6;
  }
  if (iVar5 == 0xf) {
    puStack_1dc = *(undefined **)(in_ECX + 0xf0);
    puStack_1e0 = (undefined *)0x6001d8;
    FUN_00603a40();
    goto switchD_0060042b_caseD_6;
  }
  if (iVar5 == 0x10) {
    puStack_1dc = *(undefined **)(in_ECX + 0xf0);
    puStack_1e0 = (undefined *)0x6001ef;
    FUN_00603b10();
    goto switchD_0060042b_caseD_6;
  }
  if (iVar5 == 0x11) {
    puStack_1dc = *(undefined **)(in_ECX + 0xf0);
    puStack_1e0 = (undefined *)0x600206;
    FUN_00602210();
    goto switchD_0060042b_caseD_6;
  }
  if (iVar5 == 0x12) {
    puStack_1dc = *(undefined **)(in_ECX + 0xf0);
    puStack_1e0 = (undefined *)0x60021d;
    FUN_00603be0();
    goto switchD_0060042b_caseD_6;
  }
  if (iVar5 == 0x13) {
    puStack_1dc = *(undefined **)(in_ECX + 0xf0);
    puStack_1e0 = (undefined *)0x600234;
    FUN_00603cb0();
    goto switchD_0060042b_caseD_6;
  }
  if (iVar5 == 0x14) {
    puStack_1dc = *(undefined **)(in_ECX + 0xf0);
    puStack_1e0 = (undefined *)0x60024b;
    FUN_00603d80();
    goto switchD_0060042b_caseD_6;
  }
  FUN_00404c10();
  iVar5 = local_1bc;
  iVar3 = FUN_0051d6d0();
  if ((iVar3 == 0) || (local_1b8 = *(undefined1 **)(iVar3 + 0x54), local_1b8 == (undefined1 *)0x0))
  goto switchD_0060042b_caseD_6;
  if (*(int *)(iVar3 + 0x68) != 0) {
    FUN_00404ba0();
    puStack_1dc = (undefined *)0x60029a;
    iVar4 = FUN_004d9c50();
    if ((iVar4 != 0) && (*(int *)(iVar4 + 0xc) != 0)) goto LAB_006002d5;
    FUN_004054c0();
    puStack_1dc = (undefined *)0x0;
    local_1b4 = auStack_1f8;
    puStack_1fc = &DAT_00bed1fc;
    uStack_200 = 0x6002c0;
    FUN_00402250();
    local_c = 1;
    puStack_1fc = (undefined2 *)0x10a;
    goto LAB_006003d1;
  }
LAB_006002d5:
  puStack_1dc = *(undefined **)(iVar5 + 0x10);
  puStack_1e0 = (undefined *)0x6002e2;
  FUN_00409560();
  puStack_1e0 = (undefined *)0x6002e9;
  iVar5 = FUN_004dc700();
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0x24) != 0)) {
    puStack_1e0 = (undefined *)0x6002fd;
    FUN_004146b0();
    puStack_1dc = (undefined *)0x600307;
    iVar5 = FUN_00824e30();
    if (iVar5 != 0) {
      puStack_1dc = local_1c0;
      puStack_1e0 = (undefined *)0x60031e;
      FUN_005f5e70();
    }
    goto switchD_0060042b_caseD_6;
  }
  FUN_0040f060();
  if (DAT_00fba7a4 == (int *)0x0) goto switchD_0060042b_caseD_6;
  puStack_1dc = (undefined *)0x60033f;
  iVar5 = (**(code **)(*DAT_00fba7a4 + 0x1c))();
  if (iVar5 == 0) goto switchD_0060042b_caseD_6;
  puVar10 = (undefined *)(uint)*(ushort *)(iVar5 + 0x88);
  puStack_1dc = (undefined *)0x60035e;
  cVar2 = FUN_005ffc70();
  if (cVar2 != '\0') {
    if (cVar2 == '\a') {
      FUN_004054c0();
      puStack_1dc = (undefined *)0x0;
      local_1b4 = auStack_1f8;
      puStack_1fc = &DAT_00bed1fc;
      uStack_200 = 0x6003c1;
      FUN_00402250();
      local_c = 2;
      puStack_1fc = (undefined2 *)0x1af;
    }
    else {
      if (cVar2 != '\t') goto switchD_0060042b_caseD_6;
      FUN_004054c0();
      puStack_1dc = (undefined *)0x0;
      local_1b4 = auStack_1f8;
      puStack_1fc = &DAT_00bed1fc;
      uStack_200 = 0x600393;
      FUN_00402250();
      local_c = 3;
      puStack_1fc = (undefined2 *)0x1ac;
    }
LAB_006003d1:
    uStack_200 = 0x6003d6;
    FUN_005854b0();
    uStack_200 = 0x6003dd;
    uVar6 = FUN_00585330();
    local_1b8 = auStack_214;
LAB_006003e4:
    FUN_00402250(uVar6);
    uVar6 = 0xca;
    goto LAB_006003f1;
  }
  iVar5 = *(int *)(local_1b8 + 8);
  if (param_2 != '\0') {
    switch(iVar5) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x1b:
    case 0x20:
    case 0x24:
    case 0x25:
    case 0x28:
    case 0x29:
    case 0x2a:
    case 0x2b:
      FUN_00520f40();
      puStack_1e0 = (undefined *)0x600e6b;
      puStack_1dc = puVar10;
      FUN_00601130();
      break;
    case 5:
    case 0xd:
    case 0x1a:
      iVar5 = FUN_00404ba0();
      iVar3 = 1;
      pcVar9 = (char *)(*(int *)(iVar5 + 0x691c) + 0x1c);
      do {
        if (*pcVar9 == '\0') {
          if ((0 < iVar3) && (iVar3 < 5)) {
            FUN_00404ba0();
            puStack_1dc = (undefined *)0x600ef1;
            FUN_0050c490();
          }
          break;
        }
        iVar3 = iVar3 + 1;
        pcVar9 = pcVar9 + 0x10;
      } while (iVar3 < 5);
      break;
    case 0x10:
    case 0x1c:
      puStack_1dc = local_1c4;
      puStack_1e0 = local_1c0;
      puStack_1e4 = local_1b0;
      uStack_1e8 = 0x600e8c;
      FUN_006014d0();
      break;
    case 0x19:
      puStack_1dc = local_1c4;
      puStack_1e0 = local_1c0;
      puStack_1e4 = local_1b0;
      uStack_1e8 = 0x600ead;
      FUN_00601860();
      break;
    case 0x1d:
      puStack_1dc = (undefined *)0x600f10;
      iVar5 = FUN_00891268();
      if (iVar5 != 0) {
        puStack_1dc = (undefined *)0x1;
        puStack_1e0 = (undefined *)0x600f27;
        FUN_00753d00();
      }
      FUN_00404aa0();
      FUN_00750020();
      break;
    case 0x1f:
      puStack_1dc = *(undefined **)(iVar3 + 0x1c);
      puStack_1e0 = (undefined *)0x600f00;
      FUN_00414720();
      puStack_1e0 = (undefined *)0x600f07;
      FUN_00571580();
    }
    goto switchD_0060042b_caseD_6;
  }
  switch(iVar5) {
  case 1:
  case 2:
  case 3:
  case 4:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x1b:
  case 0x20:
  case 0x24:
  case 0x25:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
    if (iVar5 - 1U < 0x2b) {
      FUN_00520f40();
    }
    puStack_1e0 = (undefined *)0x60044f;
    puStack_1dc = puVar10;
    FUN_00601130();
    break;
  case 5:
  case 0xd:
    iVar5 = FUN_00404ba0();
    if (((*(int *)(iVar5 + 0x5f4c) != 4) && (iVar5 = FUN_00404ba0(), *(int *)(iVar5 + 0x5f4c) != 9))
       && (iVar5 = FUN_00404ba0(), *(int *)(iVar5 + 0x5f4c) != 0x1c)) break;
LAB_00600482:
    FUN_00414680();
    puStack_1dc = *(undefined **)(local_1bc + 0xc);
    puStack_1e0 = local_1c4;
    puStack_1e4 = local_1c0;
    uStack_1e8 = 0x6004a0;
    FUN_004a39f0();
    break;
  case 0x10:
  case 0x1c:
    puStack_1dc = local_1c4;
    puStack_1e0 = local_1c0;
    puStack_1e4 = local_1b0;
    uStack_1e8 = 0x600513;
    FUN_006014d0();
    break;
  case 0x15:
  case 0x26:
  case 0x27:
    if (*(int *)(local_1b8 + 0x148) != *(int *)(local_1b8 + 0x14c)) {
      local_1b4 = (undefined1 *)(*(int *)(local_1b8 + 0x14c) - *(int *)(local_1b8 + 0x148) >> 2);
      puVar11 = (undefined1 *)0x0;
      bVar1 = true;
      if (local_1b4 != (undefined1 *)0x0) {
        do {
          switch(*(undefined2 *)(*(int *)(*(int *)(local_1b8 + 0x148) + (int)puVar11 * 4) + 8)) {
          case 0xd:
            FUN_0040f060();
            iVar5 = (**(code **)(*DAT_00fba7a4 + 0x20))();
            if (iVar5 != 0) {
              FUN_00404ba0();
              puStack_1dc = (undefined *)0x6007cf;
              iVar5 = FUN_00509650();
              if (iVar5 != 0) {
                puStack_1dc = (undefined *)0x6007e4;
                puStack_1dc = (undefined *)FUN_00474db0();
                puStack_1e0 = (undefined *)0x6007ea;
                iVar5 = FUN_00826610();
                if (iVar5 != 0) {
                  FUN_004054c0();
                  puStack_1dc = (undefined *)0x0;
                  puStack_1a8 = auStack_1f8;
                  puStack_1fc = &DAT_00bed1fc;
                  uStack_200 = 0x60080e;
                  FUN_00402250();
                  puStack_1fc = (undefined2 *)0xf9;
                  local_c = 10;
                  uStack_200 = 0x600823;
                  FUN_005854b0();
                  uStack_200 = 0x60082a;
                  uVar6 = FUN_00585330();
                  puStack_1ac = auStack_214;
                  FUN_00402250(uVar6);
                  local_c = 0xffffffff;
                  FUN_0058b270(0xca);
                  bVar1 = false;
                }
              }
            }
            break;
          case 0x12:
            iVar5 = FUN_00404ba0();
            iVar5 = *(int *)(iVar5 + 0x5f4c);
            if (((iVar5 == 3) || (iVar5 == 5)) ||
               ((iVar5 == 7 ||
                ((((iVar5 == 0x17 || (iVar5 == 0x18)) || (iVar5 == 0x15)) ||
                 ((iVar5 == 8 || (iVar5 == 0x1b)))))))) {
              puStack_1dc = (undefined *)0x600947;
              puVar8 = (undefined4 *)FUN_00891268();
              if (puVar8 == (undefined4 *)0x0) goto LAB_0060088a;
              uVar6 = *(undefined4 *)(local_1bc + 0xc);
              puVar8[1] = 0xffffffff;
              puVar8[2] = 0xffffffff;
              puVar8[3] = 0;
              puVar8[4] = 0xf4325;
              *puVar8 = FoxUI::FXUIEventI1::vftable;
              puVar8[5] = uVar6;
              FUN_004072a0();
              bVar1 = false;
            }
            else {
              FUN_004054c0();
              puStack_1dc = (undefined *)0x0;
              puStack_1ac = auStack_1f8;
              puStack_1fc = &DAT_00bed1fc;
              uStack_200 = 0x6008f9;
              FUN_00402250();
              puStack_1fc = (undefined2 *)0x1a9;
              local_c = 0xb;
              uStack_200 = 0x60090e;
              FUN_005854b0();
              uStack_200 = 0x600915;
              uVar6 = FUN_00585330();
              puStack_1a8 = auStack_214;
              FUN_00402250(uVar6);
              local_c = 0xffffffff;
              FUN_0058b270(0xca);
              bVar1 = false;
            }
            break;
          case 0x16:
            puStack_1dc = (undefined *)0x60085f;
            iVar5 = FUN_00891268();
            if (iVar5 == 0) {
LAB_0060088a:
              FUN_004072a0();
              bVar1 = false;
            }
            else {
              puStack_1dc = (undefined *)0xf4327;
              puStack_1e0 = (undefined *)0x60087c;
              FUN_00753e00();
              FUN_004072a0();
              bVar1 = false;
            }
            break;
          case 0x1a:
            puStack_1dc = (undefined *)0x60098b;
            iVar5 = FUN_00891268();
            if (iVar5 != 0) {
              puStack_1dc = (undefined *)0xf4340;
              puStack_1e0 = (undefined *)0x6009ab;
              FUN_00753e00();
            }
            FUN_004072a0();
          }
          puVar11 = puVar11 + 1;
        } while (puVar11 < local_1b4);
        if (!bVar1) break;
      }
      if (*(int *)(local_1b8 + 0x100) == 0) {
        FUN_00414680();
        puStack_1dc = *(undefined **)(local_1bc + 0xc);
        puStack_1e0 = local_1c4;
        puStack_1e4 = local_1c0;
        uStack_1e8 = 0x600ae8;
        FUN_004a39f0();
      }
      else {
        puStack_1dc = (undefined *)0x6009e4;
        FUN_00757200();
        puVar11 = local_1b8 + 0xf0;
        local_c = 0xc;
        puStack_1e0 = (undefined *)0x600a06;
        puStack_1dc = puVar11;
        iVar5 = FUN_00466320();
        puStack_1e0 = (undefined *)0x600a15;
        puStack_1dc = puVar11;
        iVar3 = FUN_00466320();
        FUN_00757f20();
        puStack_1dc = (undefined *)((iVar3 - iVar5) + -1);
        puStack_1e4 = (undefined *)0x600a3d;
        puStack_1e0 = (undefined *)iVar5;
        FUN_007591a0();
        puStack_1dc = (undefined *)0x600a44;
        iVar5 = FUN_00891268();
        if (iVar5 == 0) {
          uVar6 = 0;
        }
        else {
          puStack_1dc = local_1c4;
          puStack_1e0 = (undefined *)0xf4383;
          puStack_1e4 = (undefined *)0x600a66;
          uVar6 = FUN_00753e30();
        }
        puStack_1dc = (undefined *)0x600a7d;
        FUN_007572f0();
        puStack_1e4 = auStack_1a4;
        uStack_1e8 = 0xcf;
        local_c._0_1_ = 0xd;
        uStack_1ec = 0x600a9d;
        puStack_1e0 = auStack_fc;
        puStack_1dc = (undefined *)uVar6;
        FUN_00407330();
        local_c = CONCAT31(local_c._1_3_,0xc);
        puStack_1dc = (undefined *)0x600ab0;
        FUN_00757640();
        local_c = 0xffffffff;
        puStack_1dc = (undefined *)0x600ac5;
        FUN_00757640();
      }
    }
    break;
  case 0x17:
    iVar5 = FUN_00404ba0();
    if (((puVar10 < (undefined *)0xa) &&
        (iVar5 = (int)puVar10 * 0x210 + *(int *)(iVar5 + 0x6924), *(int *)(iVar5 + 0x5c) != 0)) &&
       (iVar5 != 0)) {
      iVar5 = *(int *)(iVar5 + 8);
      FUN_00404ba0();
      iVar3 = FUN_004d43d0();
      if (iVar5 < iVar3) goto LAB_00600482;
    }
    FUN_004054c0();
    puStack_1dc = (undefined *)0x0;
    local_1b4 = auStack_1f8;
    puStack_1fc = &DAT_00bed1fc;
    uStack_200 = 0x600592;
    FUN_00402250();
    local_c = 4;
    puStack_1fc = (undefined2 *)0xf6;
    goto LAB_006003d1;
  case 0x19:
    puStack_1dc = local_1c4;
    puStack_1e0 = local_1c0;
    puStack_1e4 = local_1b0;
    uStack_1e8 = 0x600534;
    FUN_00601860();
    break;
  case 0x1a:
    iVar5 = FUN_00404ba0();
    if (((*(int *)(iVar5 + 0x5f4c) == 4) || (iVar5 = FUN_00404ba0(), *(int *)(iVar5 + 0x5f4c) == 9))
       && (iVar5 = FUN_004c9530(), iVar5 != 0)) {
      FUN_00414680();
      puStack_1dc = *(undefined **)(local_1bc + 0xc);
      puStack_1e0 = local_1c4;
      puStack_1e4 = local_1c0;
      uStack_1e8 = 0x6004f2;
      FUN_004a39f0();
    }
    break;
  case 0x1d:
    iVar5 = *(int *)(iVar3 + 0x5c);
    if (iVar5 == 0) break;
    FUN_00404ba0();
    uVar7 = FUN_005099d0();
    if (uVar7 < (uint)(*(int *)(iVar5 + 0xc) - *(int *)(iVar5 + 8) >> 3)) {
      puStack_1dc = (undefined *)0x600beb;
      FUN_007572f0();
      local_c = 0xf;
      puStack_1dc = (undefined *)0x600c09;
      FUN_005854b0();
      puStack_1dc = (undefined *)0x600c10;
      FUN_00585330();
      FUN_00420070();
      local_c._0_1_ = 0x10;
      puStack_1dc = (undefined *)0x600c35;
      FUN_007574a0();
      puStack_1dc = (undefined *)0x0;
      puStack_1e0 = auStack_54;
      uStack_1e8 = 0xca;
      local_c._0_1_ = 0x11;
      uStack_1ec = 0x600c56;
      puStack_1e4 = auStack_c4;
      FUN_00407330();
      local_c = CONCAT31(local_c._1_3_,0x10);
      puStack_1dc = (undefined *)0x600c69;
      FUN_00757640();
      FUN_004fa440();
      local_c = 0xffffffff;
      puStack_1dc = (undefined *)0x600c8d;
      FUN_00757640();
      break;
    }
    FUN_004054c0();
    puStack_1dc = (undefined *)0x600c9e;
    iVar5 = FUN_00891268();
    if (iVar5 == 0) {
      puStack_1dc = (undefined *)0x0;
    }
    else {
      puStack_1dc = (undefined *)0xf436b;
      puStack_1e0 = (undefined *)0x600cb8;
      puStack_1dc = (undefined *)FUN_00753e00();
    }
    puStack_1ac = auStack_1f8;
    puStack_1fc = &DAT_00bed1fc;
    uStack_200 = 0x600cd5;
    FUN_00402250();
    puStack_1fc = (undefined2 *)0x1aa;
    local_c = 0x12;
    uStack_200 = 0x600cea;
    FUN_005854b0();
    uStack_200 = 0x600cf1;
    uVar6 = FUN_00585330();
    puStack_1a8 = auStack_214;
    FUN_00402250(uVar6);
    uVar6 = 0xcf;
    goto LAB_006003f1;
  case 0x1f:
    iVar5 = FUN_00404ba0();
    iVar5 = *(int *)(iVar5 + 0x5f4c);
    if ((((iVar5 != 3) && (iVar5 != 5)) && ((iVar5 != 7 && ((iVar5 != 0x17 && (iVar5 != 0x18))))))
       && ((iVar5 != 0x15 && ((iVar5 != 8 && (iVar5 != 0x1b)))))) {
      FUN_004054c0();
      puStack_1dc = (undefined *)0x0;
      local_1b4 = auStack_1f8;
      puStack_1fc = &DAT_00bed1fc;
      uStack_200 = 0x6005f6;
      FUN_00402250();
      local_c = 5;
      puStack_1fc = (undefined2 *)0x1a9;
      goto LAB_006003d1;
    }
    FUN_00404ba0();
    iVar5 = FUN_005099d0();
    if (iVar5 == 0) {
      puStack_1dc = (undefined *)0x600634;
      FUN_007572f0();
      local_c = 6;
      puStack_1dc = (undefined *)0x600649;
      FUN_005854b0();
      puStack_1dc = (undefined *)0x600650;
      FUN_00585330();
      FUN_004068f0();
      local_c._0_1_ = 7;
      puStack_1dc = (undefined *)0x600675;
      FUN_007574a0();
      puStack_1dc = (undefined *)0x0;
      puStack_1e0 = auStack_8c;
      uStack_1e8 = 0xca;
      local_c._0_1_ = 8;
      uStack_1ec = 0x600696;
      puStack_1e4 = auStack_134;
      FUN_00407330();
      local_c = CONCAT31(local_c._1_3_,7);
      puStack_1dc = (undefined *)0x6006a9;
      FUN_00757640();
      FUN_004fa440();
      local_c = 0xffffffff;
      puStack_1dc = (undefined *)0x6006ca;
      FUN_00757640();
      break;
    }
    FUN_004054c0();
    puStack_1dc = (undefined *)0x6006db;
    iVar5 = FUN_00891268();
    if (iVar5 == 0) {
      puStack_1dc = (undefined *)0x0;
    }
    else {
      puStack_1dc = (undefined *)0xf4384;
      puStack_1e0 = (undefined *)0x6006f5;
      puStack_1dc = (undefined *)FUN_00753e00();
    }
    local_1b4 = auStack_1f8;
    puStack_1fc = &DAT_00bed1fc;
    uStack_200 = 0x600712;
    FUN_00402250();
    puStack_1fc = (undefined2 *)0x1aa;
    local_c = 9;
    uStack_200 = 0x600727;
    FUN_005854b0();
    uStack_200 = 0x60072e;
    uVar6 = FUN_00585330();
    local_1b8 = auStack_214;
    FUN_00402250(uVar6);
    uVar6 = 0xcf;
LAB_006003f1:
    local_c = 0xffffffff;
    FUN_0058b270(uVar6);
    break;
  case 0x2c:
    iVar5 = FUN_00404ba0();
    iVar5 = *(int *)(iVar5 + 0x5f4c);
    if ((((iVar5 == 3) || (iVar5 == 5)) ||
        ((iVar5 == 7 || (((iVar5 == 0x17 || (iVar5 == 0x18)) || (iVar5 == 0x15)))))) || (iVar5 == 8)
       ) {
      puStack_1dc = (undefined *)0x600b66;
      puVar8 = (undefined4 *)FUN_00891268();
      if (puVar8 == (undefined4 *)0x0) {
        FUN_004072a0();
      }
      else {
        uVar6 = *(undefined4 *)(local_1bc + 0xc);
        puVar8[1] = 0xffffffff;
        puVar8[2] = 0xffffffff;
        puVar8[3] = 0;
        puVar8[4] = 0xf4323;
        *puVar8 = FoxUI::FXUIEventI1::vftable;
        puVar8[5] = uVar6;
        FUN_004072a0();
      }
      break;
    }
    FUN_004054c0();
    puStack_1dc = (undefined *)0x0;
    puStack_1ac = auStack_1f8;
    puStack_1fc = &DAT_00bed1fc;
    uStack_200 = 0x600b37;
    FUN_00402250();
    puStack_1fc = (undefined2 *)0x1a9;
    local_c = 0xe;
    uStack_200 = 0x600b4c;
    FUN_005854b0();
    uStack_200 = 0x600b53;
    uVar6 = FUN_00585330();
    puStack_1a8 = auStack_214;
    goto LAB_006003e4;
  case 0x2e:
    if (*(int *)(local_1b8 + 0x148) != *(int *)(local_1b8 + 0x14c)) {
      local_1b4 = (undefined1 *)(*(int *)(local_1b8 + 0x14c) - *(int *)(local_1b8 + 0x148) >> 2);
      puVar11 = (undefined1 *)0x0;
      if (local_1b4 != (undefined1 *)0x0) {
        do {
          if (*(short *)(*(int *)(*(int *)(local_1b8 + 0x148) + (int)puVar11 * 4) + 8) == 0x18) {
            iVar5 = FUN_00404ba0();
            iVar5 = *(int *)(iVar5 + 0x5f4c);
            if (((((iVar5 == 3) || (iVar5 == 5)) || (iVar5 == 7)) ||
                ((iVar5 == 0x17 || (iVar5 == 0x18)))) || ((iVar5 == 0x15 || (iVar5 == 8)))) {
              puStack_1dc = (undefined *)0x600df3;
              puVar8 = (undefined4 *)FUN_00891268();
              if (puVar8 != (undefined4 *)0x0) {
                uVar6 = *(undefined4 *)(local_1bc + 0xc);
                puVar8[1] = 0xffffffff;
                puVar8[2] = 0xffffffff;
                puVar8[3] = 0;
                puVar8[4] = 0xf4326;
                *puVar8 = FoxUI::FXUIEventI1::vftable;
                puVar8[5] = uVar6;
              }
              FUN_004072a0();
            }
            else {
              FUN_004054c0();
              puStack_1dc = (undefined *)0x0;
              puStack_1ac = auStack_1f8;
              puStack_1fc = &DAT_00bed1fc;
              uStack_200 = 0x600da8;
              FUN_00402250();
              puStack_1fc = (undefined2 *)0x1a9;
              local_c = 0x13;
              uStack_200 = 0x600dbd;
              FUN_005854b0();
              uStack_200 = 0x600dc4;
              uVar6 = FUN_00585330();
              puStack_1a8 = auStack_214;
              FUN_00402250(uVar6);
              local_c = 0xffffffff;
              FUN_0058b270(0xca);
            }
          }
          puVar11 = puVar11 + 1;
        } while (puVar11 < local_1b4);
      }
    }
  }
switchD_0060042b_caseD_6:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_1c4);
  return;
}

