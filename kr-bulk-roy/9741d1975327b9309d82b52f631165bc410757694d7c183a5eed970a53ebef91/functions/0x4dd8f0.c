
void FUN_004dd8f0(void)

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
  in_ECX[0x136] = &DAT_00bf2375;
  in_ECX[0x150] = &DAT_00bf2375;
  in_ECX[0xf4] = &DAT_00bf2375;
  in_ECX[0x4e] = &DAT_00bf2375;
  in_ECX[0x23c] = &DAT_00bf2375;
  in_ECX[0x154] = &DAT_00bf2375;
  in_ECX[0x158] = &DAT_00bf2375;
  in_ECX[0x224] = &DAT_00bf2375;
  in_ECX[0x220] = &DAT_00bf2375;
  in_ECX[0x135] = FUN_004ddbd0;
  in_ECX[0x14f] = FUN_004ddbf0;
  in_ECX[0xf3] = FUN_004dded0;
  in_ECX[0x4d] = FUN_004de020;
  in_ECX[0x23b] = FUN_004de100;
  in_ECX[0x153] = FUN_004de1d0;
  in_ECX[0x157] = FUN_004de370;
  in_ECX[0x223] = FUN_004de3f0;
  in_ECX[0x21f] = FUN_004de540;
  return;
}

