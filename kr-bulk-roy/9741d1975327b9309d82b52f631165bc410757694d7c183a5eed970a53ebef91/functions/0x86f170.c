
/* WARNING: Removing unreachable block (ram,0x0086f373) */
/* WARNING: Removing unreachable block (ram,0x0086f37d) */
/* WARNING: Removing unreachable block (ram,0x0086f380) */
/* WARNING: Removing unreachable block (ram,0x0086f386) */
/* WARNING: Removing unreachable block (ram,0x0086f391) */
/* WARNING: Removing unreachable block (ram,0x0086f3a9) */
/* WARNING: Removing unreachable block (ram,0x0086f225) */
/* WARNING: Removing unreachable block (ram,0x0086f231) */
/* WARNING: Removing unreachable block (ram,0x0086f23f) */
/* WARNING: Removing unreachable block (ram,0x0086f25a) */
/* WARNING: Removing unreachable block (ram,0x0086f27a) */
/* WARNING: Removing unreachable block (ram,0x0086f274) */
/* WARNING: Removing unreachable block (ram,0x0086f27e) */
/* WARNING: Removing unreachable block (ram,0x0086f284) */
/* WARNING: Removing unreachable block (ram,0x0086f28a) */
/* WARNING: Removing unreachable block (ram,0x0086f28e) */
/* WARNING: Removing unreachable block (ram,0x0086f2a4) */
/* WARNING: Removing unreachable block (ram,0x0086f296) */
/* WARNING: Removing unreachable block (ram,0x0086f2a0) */
/* WARNING: Removing unreachable block (ram,0x0086f2a9) */
/* WARNING: Removing unreachable block (ram,0x0086f2b1) */
/* WARNING: Removing unreachable block (ram,0x0086f2b6) */
/* WARNING: Removing unreachable block (ram,0x0086f2bd) */
/* WARNING: Removing unreachable block (ram,0x0086f2cc) */
/* WARNING: Removing unreachable block (ram,0x0086f2c4) */
/* WARNING: Removing unreachable block (ram,0x0086f2d0) */
/* WARNING: Removing unreachable block (ram,0x0086f2d3) */
/* WARNING: Removing unreachable block (ram,0x0086f2da) */
/* WARNING: Removing unreachable block (ram,0x0086f2e0) */
/* WARNING: Removing unreachable block (ram,0x0086f2ef) */
/* WARNING: Removing unreachable block (ram,0x0086f324) */
/* WARNING: Removing unreachable block (ram,0x0086f329) */
/* WARNING: Removing unreachable block (ram,0x0086f336) */
/* WARNING: Removing unreachable block (ram,0x0086f33d) */
/* WARNING: Removing unreachable block (ram,0x0086f2fa) */
/* WARNING: Removing unreachable block (ram,0x0086f306) */
/* WARNING: Removing unreachable block (ram,0x0086f313) */
/* WARNING: Removing unreachable block (ram,0x0086f31a) */
/* WARNING: Removing unreachable block (ram,0x0086f343) */
/* WARNING: Removing unreachable block (ram,0x0086f347) */
/* WARNING: Removing unreachable block (ram,0x0086f35c) */
/* WARNING: Removing unreachable block (ram,0x0086f360) */

undefined4 FUN_0086f170(int *param_1)

{
  int iVar1;
  int in_ECX;
  void *pvStack_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00927ec8;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  iVar1 = *param_1;
  (**(code **)(iVar1 + 0xec))();
  (**(code **)(iVar1 + 0x14))();
  FUN_00403040(*(undefined4 *)(in_ECX + 0xc),0,0xffffffff);
  FUN_00872350();
  ExceptionList = pvStack_24;
  return 1;
}

