
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007cb940(void)

{
  int *unaff_ESI;
  float in_stack_00000010;
  undefined4 *puStack_138;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined1 local_98 [140];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)local_98;
  if (0.0 <= in_stack_00000010) {
    (**(code **)(*unaff_ESI + 0xec))();
    (**(code **)(*unaff_ESI + 0x10))();
    (**(code **)(*unaff_ESI + 0x104))();
    (**(code **)(*unaff_ESI + 0x104))();
    (**(code **)(*unaff_ESI + 0xe4))();
    (**(code **)(*unaff_ESI + 0xe4))();
    uStack_e8 = 0x7cb9d6;
    (**(code **)(*unaff_ESI + 0xe4))();
    uStack_e8 = 0xf;
    uStack_ec = 0x14;
    (**(code **)(*unaff_ESI + 0xe4))();
    (**(code **)(*unaff_ESI + 0xe4))();
    (**(code **)(*unaff_ESI + 0xe4))();
    (**(code **)(*unaff_ESI + 0xe4))();
    (**(code **)(*unaff_ESI + 0x10c))();
    puStack_138 = (undefined4 *)0x7cba37;
    (**(code **)(*unaff_ESI + 0x10c))();
    puStack_138 = (undefined4 *)0x0;
    D3DXCreateSphere();
    puStack_138 = &uStack_ec;
    (**(code **)(*unaff_ESI + 0xb4))();
    D3DXMatrixAffineTransformation(&puStack_138,0x3f800000);
    (**(code **)(*unaff_ESI + 0xb0))();
    (**(code **)(_DAT_00000100 + 0xc))(0x100,0);
    (**(code **)(*unaff_ESI + 0xa8))();
    (**(code **)(*unaff_ESI + 0xa4))();
    (**(code **)(*unaff_ESI + 0xb0))();
    (**(code **)(_DAT_00000100 + 8))();
    (**(code **)(_DAT_00000100 + 0x14))();
    (**(code **)(_DAT_00000100 + 8))(0x100);
  }
  __security_check_cookie(local_c ^ (uint)local_98);
  return;
}

