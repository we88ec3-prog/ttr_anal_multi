
void FUN_0075e310(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *in_ECX;
  
  iVar1 = in_ECX[0x31];
  if (*(int *)(param_1 + 0x10) == 0x579) {
    switch(*(undefined4 *)(param_1 + 8)) {
    case 0:
      (**(code **)(*in_ECX + 0x178))();
      (**(code **)(*in_ECX + 0x128))();
      puVar2 = (undefined4 *)FUN_00891268(0x14);
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = FoxUI::FXUIEvent::vftable;
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0x5e1;
      }
      break;
    case 1:
      (**(code **)(*in_ECX + 0x180))();
      (**(code **)(*in_ECX + 0x128))();
      puVar2 = (undefined4 *)FUN_00891268(0x14);
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = FoxUI::FXUIEvent::vftable;
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0x5e2;
      }
      break;
    case 2:
      (**(code **)(*in_ECX + 0x188))();
      (**(code **)(*in_ECX + 0x128))();
      puVar2 = (undefined4 *)FUN_00891268(0x14);
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = FoxUI::FXUIEvent::vftable;
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0x5e5;
      }
      break;
    case 3:
      (**(code **)(*in_ECX + 0x194))();
      (**(code **)(*in_ECX + 0x128))();
      puVar2 = (undefined4 *)FUN_00891268(0x14);
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = FoxUI::FXUIEvent::vftable;
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0x5e3;
      }
      break;
    case 4:
      (**(code **)(*in_ECX + 0x198))();
      (**(code **)(*in_ECX + 0x128))();
      puVar2 = (undefined4 *)FUN_00891268(0x14);
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = FoxUI::FXUIEvent::vftable;
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0x5e4;
      }
      break;
    default:
      goto switchD_0075e350_default;
    }
  }
  else {
    if (*(int *)(param_1 + 0x10) != 0x57b) goto switchD_0075e350_default;
    switch(*(undefined4 *)(param_1 + 8)) {
    case 0:
      (**(code **)(*in_ECX + 0x174))();
      (**(code **)(*in_ECX + 0x128))();
      puVar2 = (undefined4 *)FUN_00891268(0x14);
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = FoxUI::FXUIEvent::vftable;
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0x5dc;
      }
      break;
    case 1:
      (**(code **)(*in_ECX + 0x17c))();
      (**(code **)(*in_ECX + 0x128))();
      puVar2 = (undefined4 *)FUN_00891268(0x14);
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = FoxUI::FXUIEvent::vftable;
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0x5dd;
      }
      break;
    case 2:
      (**(code **)(*in_ECX + 0x184))();
      (**(code **)(*in_ECX + 0x128))();
      puVar2 = (undefined4 *)FUN_00891268(0x14);
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = FoxUI::FXUIEvent::vftable;
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0x5e0;
      }
      break;
    case 3:
      (**(code **)(*in_ECX + 0x18c))();
      (**(code **)(*in_ECX + 0x128))();
      puVar2 = (undefined4 *)FUN_00891268(0x14);
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = FoxUI::FXUIEvent::vftable;
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0x5de;
      }
      break;
    case 4:
      (**(code **)(*in_ECX + 400))();
      (**(code **)(*in_ECX + 0x128))();
      puVar2 = (undefined4 *)FUN_00891268(0x14);
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = FoxUI::FXUIEvent::vftable;
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0x5df;
      }
      break;
    default:
      goto switchD_0075e350_default;
    }
  }
  FUN_00748900();
switchD_0075e350_default:
  if (iVar1 != in_ECX[0x31]) {
    puVar2 = (undefined4 *)FUN_00891268(0x14);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = FoxUI::FXUIEvent::vftable;
      puVar2[1] = 0xffffffff;
      puVar2[2] = 0xffffffff;
      puVar2[3] = 0;
      puVar2[4] = 0x5e6;
      FUN_00748900();
      return;
    }
    FUN_00748900();
  }
  return;
}

