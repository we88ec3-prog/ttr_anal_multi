
void FUN_007ccc00(void)

{
  int *unaff_ESI;
  undefined4 uStack_1b0;
  undefined4 uStack_1ac;
  undefined1 auStack_8c [128];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_8c;
  (**(code **)(*unaff_ESI + 0xe8))();
  (**(code **)(*unaff_ESI + 0xe8))();
  (**(code **)(*unaff_ESI + 0x108))();
  (**(code **)(*unaff_ESI + 0x108))();
  (**(code **)(*unaff_ESI + 0xe8))();
  (**(code **)(*unaff_ESI + 0xe8))();
  (**(code **)(*unaff_ESI + 0xe4))();
  (**(code **)(*unaff_ESI + 0xe4))();
  (**(code **)(*unaff_ESI + 0xe4))();
  (**(code **)(*unaff_ESI + 0x10c))();
  (**(code **)(*unaff_ESI + 0x10c))();
  (**(code **)(*unaff_ESI + 0xb0))();
  (**(code **)(*unaff_ESI + 0x104))();
  (**(code **)(*unaff_ESI + 0x164))();
  (**(code **)(*unaff_ESI + 0x14c))();
  (**(code **)(*unaff_ESI + 0xe4))();
  (**(code **)(*unaff_ESI + 0x10c))();
  (**(code **)(*unaff_ESI + 0x10c))();
  (**(code **)(*unaff_ESI + 0xe4))();
  (**(code **)(*unaff_ESI + 0xe4))();
  uStack_1ac = 0x7cce14;
  (**(code **)(*unaff_ESI + 0xe4))();
  uStack_1ac = 1;
  uStack_1b0 = 7;
  (**(code **)(*unaff_ESI + 0xe4))();
  __security_check_cookie((uint)unaff_ESI ^ (uint)&uStack_1b0);
  return;
}

