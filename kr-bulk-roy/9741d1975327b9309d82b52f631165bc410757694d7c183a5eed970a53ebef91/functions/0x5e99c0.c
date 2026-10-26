
/* WARNING: Removing unreachable block (ram,0x005e9bad) */

void FUN_005e99c0(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *unaff_ESI;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00912470;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar3 = unaff_ESI + 9;
  iVar2 = 9;
  do {
    (**(code **)(*(int *)unaff_ESI[0x17] + 0x74))(*puVar3,uVar1);
    puVar3 = puVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar3 = unaff_ESI + 0x12;
  iVar2 = 5;
  do {
    (**(code **)(*(int *)unaff_ESI[0x17] + 0x74))(*puVar3);
    puVar3 = puVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_004095e0(0x73);
  FUN_004095e0(0x74);
  FUN_004095e0(0x75);
  FUN_004095e0(0x76);
  FUN_004095e0(0x77);
  FUN_004095e0(0x78);
  FUN_004095e0(0x79);
  FUN_004095e0(0x7a);
  FUN_004095e0(0x7b);
  FUN_004095e0(0x7c);
  FUN_004095e0(0x7d);
  FUN_004095e0(0x7e);
  FUN_004095e0(0x7f);
  FUN_004095e0(0x80);
  FUN_004095e0(0x81);
  FUN_004095e0(0x82);
  FUN_004095e0(0x83);
  FUN_004095e0(0x84);
  FUN_004095e0(0x85);
  FUN_004095e0(0x86);
  FUN_004095e0(0x87);
  FUN_004095e0(0x88);
  FUN_004095e0(0x89);
  FUN_004095e0(0x8a);
  *unaff_ESI = 0;
  unaff_ESI[1] = 0;
  unaff_ESI[2] = 0;
  unaff_ESI[3] = 0;
  unaff_ESI[4] = 0;
  unaff_ESI[5] = 0;
  unaff_ESI[6] = 0;
  unaff_ESI[7] = 0;
  unaff_ESI[8] = 0;
  unaff_ESI[9] = 0;
  unaff_ESI[10] = 0;
  unaff_ESI[0xb] = 0;
  unaff_ESI[0xc] = 0;
  unaff_ESI[0xd] = 0;
  unaff_ESI[0xe] = 0;
  unaff_ESI[0xf] = 0;
  unaff_ESI[0x10] = 0;
  unaff_ESI[0x11] = 0;
  unaff_ESI[0x12] = 0;
  unaff_ESI[0x13] = 0;
  unaff_ESI[0x14] = 0;
  unaff_ESI[0x15] = 0;
  unaff_ESI[0x16] = 0;
  ExceptionList = local_10;
  return;
}

