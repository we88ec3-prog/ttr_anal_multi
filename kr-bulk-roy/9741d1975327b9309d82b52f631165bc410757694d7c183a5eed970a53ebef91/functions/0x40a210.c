
/* WARNING: Removing unreachable block (ram,0x0040a2be) */

void FUN_0040a210(undefined4 param_1)

{
  uint uVar1;
  int *piVar2;
  int *unaff_EDI;
  undefined4 uVar3;
  undefined4 uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00934528;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  switch(param_1) {
  case 0:
    uVar4 = 0x196;
    FUN_005854b0(0x196,0,0,uVar1);
    uVar4 = FUN_00585330(uVar4);
    uVar3 = 0x1da;
    break;
  case 1:
    FUN_0040b310("EQUIP_REINFORCE_FAILED");
    local_8 = 0;
    uVar4 = FUN_0040b3f0();
    piVar2 = (int *)FUN_0080ab00(uVar4);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x14))();
    }
    local_8 = 0xffffffff;
    goto switchD_0040a245_default;
  case 2:
    uVar4 = 0x196;
    FUN_005854b0(0x196,0,0,uVar1);
    uVar4 = FUN_00585330(uVar4);
    uVar3 = 0x10;
    break;
  case 3:
    uVar4 = 0x196;
    FUN_005854b0(0x196,0,0,uVar1);
    uVar4 = FUN_00585330(uVar4);
    uVar3 = 0xbe;
    break;
  default:
    goto switchD_0040a245_default;
  }
  FUN_005854b0(uVar3,uVar4);
  uVar4 = FUN_00585330(uVar3);
  FUN_00404b10(0xca,uVar4);
switchD_0040a245_default:
  (**(code **)(*unaff_EDI + 0x16c))(1);
  FUN_00408350(unaff_EDI[0x40]);
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}

