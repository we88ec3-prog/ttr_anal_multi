
void FUN_00699260(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int *in_ECX;
  undefined4 *puVar4;
  int *piVar5;
  undefined8 uVar6;
  longlong lVar7;
  undefined1 auStack_8c [20];
  undefined4 uStack_78;
  undefined4 uStack_74;
  int aiStack_70 [4];
  undefined4 uStack_60;
  undefined1 *local_3c;
  int *piStack_38;
  undefined4 *puStack_34;
  int *local_30;
  undefined4 uStack_2c;
  uint uStack_28;
  int iStack_24;
  undefined4 uStack_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00932b34;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_3c;
  ExceptionList = &local_14;
  local_30 = param_1;
  if (in_ECX == (int *)0x0) {
LAB_006992ca:
    in_ECX = (int *)0x0;
  }
  else {
    iVar1 = (**(code **)(*in_ECX + 4))();
    if (iVar1 != 0x105bd) {
      uStack_60 = 0x6992ca;
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_006992ca;
    }
  }
  iVar1 = in_ECX[6];
  local_3c = (undefined1 *)in_ECX[5];
  if (iVar1 == 0) goto LAB_006995a2;
  switch(*(undefined1 *)(iVar1 + 2)) {
  case 1:
  case 2:
    puStack_34 = (undefined4 *)FUN_00891268();
    if (puStack_34 == (undefined4 *)0x0) {
      puStack_34 = (undefined4 *)0x0;
    }
    else {
      puStack_34[1] = 0xffffffff;
      puStack_34[2] = 0xffffffff;
      puStack_34[3] = 0;
      puStack_34[4] = 0xf4309;
      *puStack_34 = FUI::FXUICashShopCartBuyResult::vftable;
      puStack_34[5] = 0;
      puStack_34[6] = 0;
      puStack_34[7] = 0;
    }
    if (*(int *)(local_30[0x3d] + 0xcc) == 0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)(*(int *)(local_30[0x3d] + 0xcc) + 0xa8);
    }
    piVar5 = (int *)piVar2[1];
    piVar2 = (int *)*piVar2;
    piStack_38 = piVar5;
    if ((local_3c < (undefined1 *)0x3) ||
       ((undefined1 *)((uint)(local_3c + -3) >> 4) == (undefined1 *)0x0)) {
      if (piVar2 != piVar5) {
        do {
          uStack_28 = **(uint **)(*piVar2 + 0x25c);
          uStack_2c = 1;
          iStack_24 = FUN_00698980();
          iStack_24 = iStack_24 + 1;
          uStack_20 = FUN_006989b0();
          FUN_0053eba0();
          piVar2 = piVar2 + 1;
        } while (piVar2 != piStack_38);
      }
    }
    else {
      puVar4 = (undefined4 *)(iVar1 + 3);
      local_3c = (undefined1 *)((uint)(local_3c + -3) >> 4);
      do {
        if (puVar4 != (undefined4 *)0x0) {
          uStack_2c = *puVar4;
          uStack_28 = puVar4[1];
          iStack_24 = puVar4[2];
          lVar7 = (ulonglong)uStack_28 << 0x20;
          while( true ) {
            uStack_20 = (undefined4)lVar7;
            if (piVar2 == piVar5) break;
            if (**(int **)(*piVar2 + 0x25c) == (int)((ulonglong)lVar7 >> 0x20)) {
              uVar6 = FUN_00698980();
              lVar7 = CONCAT44((int)((ulonglong)uVar6 >> 0x20),uStack_20);
              if ((int)uVar6 + 1 == iStack_24) {
                lVar7 = FUN_006989b0();
              }
            }
            piVar2 = piVar2 + 1;
          }
          FUN_0053eba0();
          piVar5 = piStack_38;
        }
        puVar4 = puVar4 + 4;
        local_3c = local_3c + -1;
      } while (local_3c != (undefined1 *)0x0);
      local_3c = (undefined1 *)0x0;
    }
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      uStack_c = 0;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      uStack_c = 0xffffffff;
    }
    FUN_0058aa50();
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      uStack_c = 1;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      uStack_c = 0xffffffff;
    }
    FUN_0058afa0();
    (**(code **)(*local_30 + 0xd4))();
    goto switchD_006992ec_default;
  case 3:
    FUN_004054c0();
    FUN_005854b0();
    uStack_74 = FUN_00585330();
    piStack_38 = aiStack_70;
    uStack_78 = 0x6994ec;
    FUN_00402250();
    uStack_c = 2;
    uStack_74 = 0x13;
    break;
  case 4:
    FUN_004054c0();
    FUN_005854b0();
    uStack_74 = FUN_00585330();
    piStack_38 = aiStack_70;
    uStack_78 = 0x69951f;
    FUN_00402250();
    uStack_c = 3;
    uStack_74 = 0x15;
    break;
  case 5:
    FUN_004054c0();
    FUN_005854b0();
    uStack_74 = FUN_00585330();
    piStack_38 = aiStack_70;
    uStack_78 = 0x699552;
    FUN_00402250();
    uStack_c = 4;
    uStack_74 = 0x109;
    break;
  default:
    goto switchD_006992ec_default;
  }
  uStack_78 = 0x699564;
  FUN_005854b0();
  uStack_78 = 0x69956b;
  uVar3 = FUN_00585330();
  local_3c = auStack_8c;
  FUN_00402250(uVar3);
  uStack_c = 0xffffffff;
  FUN_0058b270(0xca);
switchD_006992ec_default:
  (**(code **)(*local_30 + 0x90))();
LAB_006995a2:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_3c);
  return;
}

