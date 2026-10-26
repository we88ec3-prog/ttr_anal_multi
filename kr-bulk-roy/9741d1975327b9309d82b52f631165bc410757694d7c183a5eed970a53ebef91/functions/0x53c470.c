
void FUN_0053c470(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *in_EDX;
  
  iVar2 = 0xbd5;
  puVar1 = in_EDX;
  do {
    puVar1[1] = &LAB_004b7d40;
    puVar1[2] = &DAT_00bf2375;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 2;
  } while (iVar2 != 0);
  in_EDX[0x214] = &DAT_00bf2375;
  in_EDX[0x216] = &DAT_00bf2375;
  in_EDX[0x218] = &DAT_00bf2375;
  in_EDX[0x21a] = &DAT_00bf2375;
  in_EDX[0x213] = FUN_0053c4e0;
  in_EDX[0x215] = FUN_0053c820;
  in_EDX[0x217] = FUN_0053cdb0;
  in_EDX[0x219] = FUN_0053c9a0;
  return;
}

