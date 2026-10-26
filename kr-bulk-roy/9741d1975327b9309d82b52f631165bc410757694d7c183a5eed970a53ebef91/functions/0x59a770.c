
void FUN_0059a770(int param_1)

{
  int *in_EAX;
  int iVar1;
  uint uVar2;
  undefined2 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  if (in_EAX == (int *)0x0) {
LAB_0059a7a7:
    in_EAX = (int *)0x0;
  }
  else {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 != 0x105b9) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_0059a7a7;
    }
  }
  switch(in_EAX[5]) {
  case 0:
    (**(code **)(**(int **)(param_1 + 0x198) + 0xd0))();
    return;
  case 1:
    (**(code **)(**(int **)(param_1 + 0x19c) + 0xd0))();
    return;
  case 2:
    (**(code **)(**(int **)(param_1 + 0x1a0) + 0xd0))();
    return;
  case 3:
    iVar1 = FUN_00404ba0();
    switch(*(undefined4 *)(iVar1 + 0x5f4c)) {
    case 6:
      break;
    case 7:
    case 0x15:
    case 0x17:
    case 0x18:
      FUN_00414680();
      FUN_004a3bc0();
      return;
    default:
      iVar1 = FUN_0041a4d0();
      if ((*(int *)(iVar1 + 0x5ed8) == 0) || (uVar2 = FUN_00539a70(), uVar2 < 2)) {
        iVar1 = FUN_0041a4d0();
        if (*(int *)(iVar1 + 0x5ed8) == 0) {
          return;
        }
        FUN_0053ba20();
        return;
      }
      puVar4 = (undefined4 *)FUN_00891268(0x14);
      if (puVar4 == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        *puVar4 = FoxUI::FXUIEvent::vftable;
        puVar4[1] = 0xffffffff;
        puVar4[2] = 0xffffffff;
        puVar4[3] = 0;
        puVar4[4] = 0xf4409;
      }
      param_1 = *(int *)(param_1 + 0x16c);
      uVar5 = 0x196;
      FUN_005854b0(0x196,puVar4,param_1);
      puVar3 = (undefined2 *)FUN_00585330(uVar5);
      uVar5 = 0x3b;
      goto LAB_0059a920;
    }
  case 4:
    puVar4 = (undefined4 *)FUN_00891268(0x14);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      *puVar4 = FoxUI::FXUIEvent::vftable;
      puVar4[1] = 0xffffffff;
      puVar4[2] = 0xffffffff;
      puVar4[3] = 0;
      puVar4[4] = 0xf43d2;
    }
    puVar3 = &DAT_00bed1fc;
    uVar5 = 0x1bd;
    goto LAB_0059a920;
  case 5:
    goto switchD_0059a7b5_caseD_5;
  case 6:
    FUN_004054c0();
    puVar4 = (undefined4 *)FUN_00891268(0x14);
    if (puVar4 == (undefined4 *)0x0) {
      FUN_0058aa50(0);
      return;
    }
    *puVar4 = FoxUI::FXUIEvent::vftable;
    puVar4[1] = 0xffffffff;
    puVar4[2] = 0xffffffff;
    puVar4[3] = 0;
    puVar4[4] = 0xf43fe;
    FUN_0058aa50(puVar4);
    return;
  case 7:
switchD_0059a7b5_caseD_7:
    (**(code **)(**(int **)(param_1 + 0x204) + 0xd4))();
  default:
    goto switchD_0059a7b5_default;
  }
  puVar4 = (undefined4 *)FUN_00891268(0x18);
  if (puVar4 == (undefined4 *)0x0) {
LAB_0059a9a8:
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar4[1] = 0xffffffff;
    puVar4[2] = 0xffffffff;
    puVar4[3] = 0;
    puVar4[4] = 0xf4408;
    *puVar4 = FoxUI::FXUIEventI1::vftable;
    puVar4[5] = 3;
  }
  goto LAB_0059a9aa;
switchD_0059a7b5_default:
  return;
switchD_0059a7b5_caseD_5:
  iVar1 = FUN_00404ba0();
  if (*(int *)(iVar1 + 0x5f4c) != 6) {
    iVar1 = FUN_0041a4d0();
    if (*(int *)(iVar1 + 0x5ed8) != 0) {
      FUN_0053ba20();
    }
    goto switchD_0059a7b5_caseD_7;
  }
  puVar4 = (undefined4 *)FUN_00891268(0x18);
  if (puVar4 == (undefined4 *)0x0) goto LAB_0059a9a8;
  puVar4[1] = 0xffffffff;
  puVar4[2] = 0xffffffff;
  puVar4[3] = 0;
  puVar4[4] = 0xf4408;
  *puVar4 = FoxUI::FXUIEventI1::vftable;
  puVar4[5] = 5;
LAB_0059a9aa:
  uVar5 = 0x196;
  FUN_005854b0(0x196,puVar4,param_1);
  puVar3 = (undefined2 *)FUN_00585330(uVar5);
  uVar5 = 0x124;
LAB_0059a920:
  FUN_005854b0(uVar5,puVar3,puVar4,param_1);
  uVar5 = FUN_00585330(uVar5);
  FUN_00404b10(0xcf,uVar5);
  return;
}

