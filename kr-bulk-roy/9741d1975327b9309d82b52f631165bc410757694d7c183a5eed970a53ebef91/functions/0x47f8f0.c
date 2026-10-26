
void FUN_0047f8f0(void)

{
  undefined2 in_AX;
  undefined4 *puVar1;
  int *in_ECX;
  undefined4 uVar2;
  undefined4 uVar3;
  
  switch(in_AX) {
  case 0:
                    /* WARNING: Could not recover jumptable at 0x0047f90e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*in_ECX + 0xd4))();
    return;
  case 0xfff6:
    uVar3 = 0x196;
    FUN_005854b0(0x196,0,0);
    uVar3 = FUN_00585330(uVar3);
    uVar2 = 0x142;
    break;
  case 0xfff7:
  case 0xfff8:
  case 0xfff9:
  case 0xfffa:
  case 0xfffb:
    goto switchD_0047f8fe_default;
  case 0xfffc:
    uVar3 = 0x196;
    FUN_005854b0(0x196,0,0);
    uVar3 = FUN_00585330(uVar3);
    uVar2 = 0x141;
    break;
  case 0xfffd:
    uVar3 = 0x196;
    FUN_005854b0(0x196,0,0);
    uVar3 = FUN_00585330(uVar3);
    uVar2 = 0x140;
    break;
  case 0xfffe:
    uVar3 = 0x196;
    FUN_005854b0(0x196,0,0);
    uVar3 = FUN_00585330(uVar3);
    uVar2 = 0x13f;
    break;
  case 0xffff:
    uVar3 = 0x196;
    FUN_005854b0(0x196,0,0);
    uVar3 = FUN_00585330(uVar3);
    uVar2 = 0x13e;
    break;
  default:
    return;
  }
  FUN_005854b0(uVar2,uVar3);
  uVar3 = FUN_00585330(uVar2);
  FUN_00404b10(0xca,uVar3);
  FUN_004054c0();
  puVar1 = (undefined4 *)FUN_00891268(0x14);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = FoxUI::FXUIEvent::vftable;
    puVar1[1] = 0xffffffff;
    puVar1[2] = 0xffffffff;
    puVar1[3] = 0;
    puVar1[4] = 0xf442a;
    FUN_0058aa50(puVar1);
    return;
  }
  FUN_0058aa50(0);
switchD_0047f8fe_default:
  return;
}

