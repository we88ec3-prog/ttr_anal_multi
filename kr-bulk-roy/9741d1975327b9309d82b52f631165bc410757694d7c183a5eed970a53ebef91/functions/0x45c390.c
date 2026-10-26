
void FUN_0045c390(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 in_ECX;
  int in_EDX;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009341f0;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar7 = uVar2;
  FUN_0045b410(in_EDX);
  switch(in_ECX) {
  case 0:
    iVar1 = *(int *)(in_EDX + 0x104);
    *(undefined4 *)(iVar1 + 0x98) = *(undefined4 *)(iVar1 + 0xa0);
    *(undefined4 *)(iVar1 + 0x94) = 2;
    *(undefined4 *)(iVar1 + 0xa8) = 0;
    *(undefined4 *)(iVar1 + 0xb0) = 0;
    *(undefined4 *)(iVar1 + 0x90) = 0;
    FUN_0068a590();
    FUN_0040b3c0();
    local_8 = 0;
    uVar6 = FUN_0040b3f0();
    piVar4 = (int *)FUN_0080ab00(uVar6);
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x14))();
    }
    local_8 = 0xffffffff;
    FUN_007cf450();
    puVar3 = (undefined4 *)FUN_00891268(0x18);
    if (puVar3 == (undefined4 *)0x0) {
      FUN_00404aa0();
      FUN_00750020();
    }
    else {
      puVar3[1] = 0xffffffff;
      puVar3[2] = 0xffffffff;
      puVar3[3] = 0;
      puVar3[4] = 0xf4336;
      *puVar3 = FoxUI::FXUIEventI1::vftable;
      puVar3[5] = param_1;
      FUN_00404aa0();
      FUN_00750020();
    }
    goto switchD_0045c3cd_default;
  case 1:
    iVar1 = *(int *)(in_EDX + 0x104);
    *(undefined4 *)(iVar1 + 0x98) = *(undefined4 *)(iVar1 + 0xa0);
    *(undefined4 *)(iVar1 + 0x94) = 2;
    *(undefined4 *)(iVar1 + 0xa8) = 1;
    *(undefined4 *)(iVar1 + 0xb0) = 0;
    *(undefined4 *)(iVar1 + 0x90) = 0;
    FUN_0068a540();
    FUN_0040b3c0();
    local_8 = 1;
    uVar6 = FUN_0040b3f0();
    piVar4 = (int *)FUN_0080ab00(uVar6);
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x14))();
    }
    FUN_007cf450();
    goto switchD_0045c3cd_default;
  case 2:
    FUN_0068a350(uVar7);
    uVar6 = 0x196;
    FUN_005854b0(0x196,0,0);
    uVar6 = FUN_00585330(uVar6);
    uVar5 = 0x1b3;
    break;
  case 3:
    FUN_0068a350(uVar7);
    uVar6 = 0x196;
    FUN_005854b0(0x196,0,0);
    uVar6 = FUN_00585330(uVar6);
    uVar5 = 0x10;
    break;
  case 4:
    FUN_0068a350(uVar7);
    uVar6 = 0x196;
    FUN_005854b0(0x196,0,0);
    uVar6 = FUN_00585330(uVar6);
    uVar5 = 0x1b2;
    break;
  case 5:
    FUN_0068a350(uVar7);
    uVar6 = 0x196;
    FUN_005854b0(0x196,0,0);
    uVar6 = FUN_00585330(uVar6);
    uVar5 = 0xbe;
    break;
  default:
    goto switchD_0045c3cd_default;
  }
  FUN_005854b0(uVar5,uVar6);
  uVar6 = FUN_00585330(uVar5);
  FUN_00404b10(0xca,uVar6);
switchD_0045c3cd_default:
  ExceptionList = local_10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

