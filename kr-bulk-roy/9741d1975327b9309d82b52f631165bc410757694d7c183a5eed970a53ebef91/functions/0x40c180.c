
/* WARNING: Removing unreachable block (ram,0x0040c20e) */

void FUN_0040c180(undefined4 param_1)

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
    FUN_0040b310("WEAPON_LEVELUP_SUCCESS");
    local_8 = 0;
    uVar4 = FUN_0040b3f0();
    piVar2 = (int *)FUN_0080ab00(uVar4);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x14))();
    }
    local_8 = 0xffffffff;
    uVar4 = 0x196;
    FUN_005854b0(0x196,0,0);
    uVar4 = FUN_00585330(uVar4);
    uVar3 = 0x1e0;
    break;
  case 1:
    uVar4 = 0x196;
    FUN_005854b0(0x196,0,0,uVar1);
    uVar4 = FUN_00585330(uVar4);
    uVar3 = 0x1df;
    break;
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
    uVar3 = 0xe5;
    break;
  default:
    goto switchD_0040c1b5_default;
  }
  FUN_005854b0(uVar3,uVar4);
  uVar4 = FUN_00585330(uVar3);
  FUN_00404b10(0xca,uVar4);
switchD_0040c1b5_default:
  (**(code **)(*unaff_EDI + 0x16c))(1);
  FUN_0040c360(unaff_EDI);
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}

