
void FUN_004f1220(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  iVar2 = 0xbd5;
  puVar1 = in_ECX;
  do {
    puVar1[1] = &LAB_004b7d40;
    puVar1[2] = &DAT_00bf2375;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 2;
  } while (iVar2 != 0);
  in_ECX[0x142] = &DAT_00bf2375;
  in_ECX[0x140] = &DAT_00bf2375;
  in_ECX[0x144] = &DAT_00bf2375;
  in_ECX[0x148] = &DAT_00bf2375;
  in_ECX[0x146] = &DAT_00bf2375;
  in_ECX[0x1e0] = &DAT_00bf2375;
  in_ECX[0x1e2] = &DAT_00bf2375;
  in_ECX[0x1e6] = &DAT_00bf2375;
  in_ECX[0x1e4] = &DAT_00bf2375;
  in_ECX[0x1e8] = &DAT_00bf2375;
  in_ECX[0x141] = FUN_004f12f0;
  in_ECX[0x13f] = FUN_004f1590;
  in_ECX[0x143] = FUN_004f16e0;
  in_ECX[0x147] = FUN_004f19c0;
  in_ECX[0x145] = FUN_004f1c40;
  in_ECX[0x1df] = FUN_004f1dc0;
  in_ECX[0x1e1] = FUN_004f1ed0;
  in_ECX[0x1e5] = FUN_004f2260;
  in_ECX[0x1e3] = FUN_004f2100;
  in_ECX[0x1e7] = FUN_004f2460;
  return;
}

