
void FUN_00539df0(void)

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
  in_ECX[0x11c] = &DAT_00bf2375;
  in_ECX[0x11e] = &DAT_00bf2375;
  in_ECX[0x120] = &DAT_00bf2375;
  in_ECX[0x122] = &DAT_00bf2375;
  in_ECX[0x112] = &DAT_00bf2375;
  in_ECX[0x114] = &DAT_00bf2375;
  in_ECX[0x118] = &DAT_00bf2375;
  in_ECX[0x116] = &DAT_00bf2375;
  in_ECX[0x11a] = &DAT_00bf2375;
  in_ECX[0x11b] = FUN_00539eb0;
  in_ECX[0x11d] = FUN_0053a050;
  in_ECX[0x11f] = FUN_0053a0a0;
  in_ECX[0x121] = FUN_0053a2d0;
  in_ECX[0x111] = FUN_0053a440;
  in_ECX[0x113] = FUN_0053a760;
  in_ECX[0x117] = FUN_0053a8c0;
  in_ECX[0x115] = FUN_0053a920;
  in_ECX[0x119] = &LAB_0053a940;
  return;
}

