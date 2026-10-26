
void FUN_0047f1c0(void)

{
  undefined2 in_AX;
  undefined4 *puVar1;
  undefined4 uVar2;
  int *unaff_EDI;
  
  switch(in_AX) {
  case 0:
    (**(code **)(*unaff_EDI + 0xd4))();
    return;
  case 0xfff6:
    break;
  default:
    goto switchD_0047f1d9_caseD_fff7;
  case 0xfffd:
    (**(code **)(*unaff_EDI + 0xd4))();
    FUN_004054c0();
    puVar1 = (undefined4 *)FUN_00891268();
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = FoxUI::FXUIEvent::vftable;
      puVar1[1] = 0xffffffff;
      puVar1[2] = 0xffffffff;
      puVar1[3] = 0;
      puVar1[4] = 0xf433a;
      FUN_0058aa50();
      return;
    }
    FUN_0058aa50();
    return;
  case 0xfffe:
    break;
  case 0xffff:
  }
  FUN_00585620();
  uVar2 = FUN_00585330();
  FUN_00402250(uVar2);
  FUN_00759e60();
  (**(code **)(*(int *)unaff_EDI[0x40] + 200))();
switchD_0047f1d9_caseD_fff7:
  return;
}

