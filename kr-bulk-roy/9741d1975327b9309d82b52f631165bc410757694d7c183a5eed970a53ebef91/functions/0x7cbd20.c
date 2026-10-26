
void FUN_007cbd20(undefined4 param_1,int param_2)

{
  uint uVar1;
  undefined4 extraout_EDX;
  int *unaff_ESI;
  undefined4 uVar2;
  
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  (**(code **)(*unaff_ESI + 0xe8))();
  (**(code **)(*unaff_ESI + 0xe8))();
  (**(code **)(*unaff_ESI + 0x108))();
  (**(code **)(*unaff_ESI + 0x108))();
  (**(code **)(*unaff_ESI + 0xe4))();
  (**(code **)(*unaff_ESI + 0x10c))();
  (**(code **)(*unaff_ESI + 0x10c))();
  (**(code **)(*unaff_ESI + 0xb0))();
  (**(code **)(*unaff_ESI + 0x104))();
  if (1 < param_2) {
    param_2 = param_2 + -1;
    do {
      (**(code **)(*unaff_ESI + 0x164))();
      (**(code **)(*unaff_ESI + 0x14c))();
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  (**(code **)(*unaff_ESI + 0xe4))();
  (**(code **)(*unaff_ESI + 0x10c))();
  (**(code **)(*unaff_ESI + 0x10c))();
  (**(code **)(*unaff_ESI + 0xe4))();
  uVar2 = 1;
  (**(code **)(*unaff_ESI + 0xe4))();
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc,extraout_EDX,uVar2);
  return;
}

