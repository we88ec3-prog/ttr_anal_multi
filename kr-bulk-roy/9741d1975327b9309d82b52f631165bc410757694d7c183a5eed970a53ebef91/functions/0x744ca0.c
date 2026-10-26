
void FUN_00744ca0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *in_ECX;
  
  FUN_007445d0(param_1);
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 100) {
    (**(code **)(*in_ECX + 0x184))();
    puVar2 = (undefined4 *)FUN_00891268(0x14);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = FoxUI::FXUIEvent::vftable;
      puVar2[1] = 0xffffffff;
      puVar2[2] = 0xffffffff;
      puVar2[3] = 0;
      puVar2[4] = 0x57b;
    }
  }
  else if (iVar1 == 0x66) {
    (**(code **)(*in_ECX + 0x194))();
    puVar2 = (undefined4 *)FUN_00891268(0x14);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = FoxUI::FXUIEvent::vftable;
      puVar2[1] = 0xffffffff;
      puVar2[2] = 0xffffffff;
      puVar2[3] = 0;
      puVar2[4] = 0x579;
    }
  }
  else {
    if (iVar1 != 0x68) goto LAB_00744d69;
    (**(code **)(*in_ECX + 0x188))();
    puVar2 = (undefined4 *)FUN_00891268(0x14);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = FoxUI::FXUIEvent::vftable;
      puVar2[1] = 0xffffffff;
      puVar2[2] = 0xffffffff;
      puVar2[3] = 0;
      puVar2[4] = 0x578;
    }
  }
  FUN_00748900();
LAB_00744d69:
  if (*(int *)(param_1 + 0x10) == 0x7c) {
    (**(code **)(*in_ECX + 0x18c))();
    puVar2 = (undefined4 *)FUN_00891268(0x14);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = FoxUI::FXUIEvent::vftable;
      puVar2[1] = 0xffffffff;
      puVar2[2] = 0xffffffff;
      puVar2[3] = 0;
      puVar2[4] = 0x58c;
    }
    FUN_00748900();
  }
  if (*(int *)(param_1 + 0x10) == 0x69) {
    (**(code **)(*in_ECX + 400))();
    puVar2 = (undefined4 *)FUN_00891268(0x14);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = FoxUI::FXUIEvent::vftable;
      puVar2[1] = 0xffffffff;
      puVar2[2] = 0xffffffff;
      puVar2[3] = 0;
      puVar2[4] = 0x57a;
      FUN_00748900();
      return;
    }
    FUN_00748900();
  }
  return;
}

