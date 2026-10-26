
bool FUN_00812540(int param_1)

{
  int iVar1;
  int unaff_ESI;
  
  if ((*(byte *)(unaff_ESI + 0x20) & 1) != 0) {
    alSourcef(*(undefined4 *)(param_1 + 8),0x100a,*(undefined4 *)(unaff_ESI + 0x24));
    alGetError();
  }
  if ((*(byte *)(unaff_ESI + 0x20) & 2) != 0) {
    alSourcef(*(undefined4 *)(param_1 + 8),0x100d,*(undefined4 *)(unaff_ESI + 0x28));
    alGetError();
  }
  if ((*(byte *)(unaff_ESI + 0x20) & 4) != 0) {
    alSourcef(*(undefined4 *)(param_1 + 8),0x100e,*(undefined4 *)(unaff_ESI + 0x2c));
    alGetError();
  }
  if ((*(byte *)(unaff_ESI + 0x20) & 0x20) != 0) {
    alSourcef(*(undefined4 *)(param_1 + 8),0x1020,*(undefined4 *)(unaff_ESI + 0x38));
    alGetError();
  }
  if ((*(byte *)(unaff_ESI + 0x20) & 0x40) != 0) {
    alSourcef(*(undefined4 *)(param_1 + 8),0x1023,*(undefined4 *)(unaff_ESI + 0x3c));
    alGetError();
  }
  if ((*(byte *)(unaff_ESI + 0x20) & 0x80) != 0) {
    alSourcef(*(undefined4 *)(param_1 + 8),0x1021,*(undefined4 *)(unaff_ESI + 0x40));
    alGetError();
  }
  if ((*(uint *)(unaff_ESI + 0x20) & 0x100) != 0) {
    alSourcef(*(undefined4 *)(param_1 + 8),0x1001,*(undefined4 *)(unaff_ESI + 0x44));
    alGetError();
  }
  if ((*(uint *)(unaff_ESI + 0x20) & 0x200) != 0) {
    alSourcef(*(undefined4 *)(param_1 + 8),0x1002,*(undefined4 *)(unaff_ESI + 0x48));
    alGetError();
  }
  if ((*(uint *)(unaff_ESI + 0x20) & 0x400) != 0) {
    alSourcef(*(undefined4 *)(param_1 + 8),0x1022,*(undefined4 *)(unaff_ESI + 0x4c));
    alGetError();
  }
  if ((*(uint *)(unaff_ESI + 0x20) & 0x800) != 0) {
    alSourcei(*(undefined4 *)(param_1 + 8),0x1007,*(undefined4 *)(unaff_ESI + 0x58));
    alGetError();
  }
  iVar1 = alGetError();
  return iVar1 == 0;
}

