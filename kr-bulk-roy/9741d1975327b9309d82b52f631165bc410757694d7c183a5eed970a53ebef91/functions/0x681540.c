
/* WARNING: Removing unreachable block (ram,0x00681753) */

void FUN_00681540(void)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  undefined4 *puVar4;
  int *unaff_EDI;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined1 auStack_40 [36];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00932bd6;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_40;
  ExceptionList = &local_14;
  puVar4 = (undefined4 *)FUN_00891268();
  if (puVar4 != (undefined4 *)0x0) {
    iVar1 = unaff_EDI[0x3f];
    iVar2 = unaff_EDI[0x3e];
    puVar4[1] = 0xffffffff;
    puVar4[2] = 0xffffffff;
    puVar4[3] = 0;
    puVar4[4] = 0xf4369;
    *puVar4 = FoxUI::FXUIEventI2::vftable;
    puVar4[5] = iVar2;
    puVar4[6] = iVar1;
  }
  FUN_004072a0();
  (**(code **)(*(int *)unaff_EDI[0x41] + 0x19c))();
  FUN_00757710();
  (**(code **)(*(int *)unaff_EDI[0x43] + 0x19c))();
  (**(code **)(*(int *)unaff_EDI[0x44] + 0x19c))();
  (**(code **)(*(int *)unaff_EDI[0x45] + 0x19c))();
  FUN_00757710();
  FUN_00757710();
  FUN_00757710();
  (**(code **)(*(int *)unaff_EDI[0x43] + 0xa0))();
  (**(code **)(*(int *)unaff_EDI[0x44] + 0xa0))();
  (**(code **)(*(int *)unaff_EDI[0x45] + 0xa0))();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    uStack_a0 = 0x6816d8;
    FUN_00584c40();
    uStack_a0 = 0x6816e2;
    _atexit((_func_4879 *)&LAB_00bcf390);
  }
  uStack_a0 = 0x681704;
  FUN_005740f0();
  if (DAT_00fe5ac8 == -1) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  FUN_004068f0();
  uStack_a0 = 0x681748;
  FUN_00757800();
  uStack_a0 = 0x681788;
  (**(code **)(*(int *)unaff_EDI[0x3d] + 0x94))();
  unaff_EDI[0x3e] = -1;
  unaff_EDI[0x3f] = -1;
  uStack_a0 = 0;
  uStack_a4 = 0x6817a6;
  (**(code **)(*(int *)unaff_EDI[0x43] + 0xa0))();
  uStack_a4 = 0;
  (**(code **)(*(int *)unaff_EDI[0x44] + 0xa0))();
  (**(code **)(*(int *)unaff_EDI[0x45] + 0xa0))(0);
  unaff_EDI[0x40] = -1;
  (**(code **)(*(int *)unaff_EDI[0x48] + 0x90))(0);
  FUN_00757710();
  (**(code **)(*(int *)unaff_EDI[0x49] + 0x94))(0);
  (**(code **)(*unaff_EDI + 200))();
  ExceptionList = (void *)0xffffffff;
  __security_check_cookie(&uStack_a4);
  return;
}

