
void FUN_005ee8b0(void)

{
  int *in_ECX;
  int iVar1;
  
  FUN_007545b0();
  iVar1 = *(int *)(in_ECX[0x66] + 0x14);
  if ((*(uint *)(in_ECX[0x6d] + 0x28) >> 8 & 1) != 0) {
    FUN_00749a00(*(undefined4 *)(in_ECX[0x6c] + 8),iVar1 + 0xf);
    FUN_00749a00(*(undefined4 *)(in_ECX[0x6e] + 8),iVar1 + 0xf);
    FUN_00749a00(*(undefined4 *)(in_ECX[0x6f] + 8),iVar1 + 0x23);
    FUN_00749a00(*(undefined4 *)(in_ECX[0x70] + 8),iVar1 + 0x37);
    FUN_007545b0();
    iVar1 = *(int *)(in_ECX[0x70] + 0x14) + 0xf;
  }
  (**(code **)(*in_ECX + 0xbc))(in_ECX[2],in_ECX[3],in_ECX[4],in_ECX[3] + 0xf + iVar1);
  return;
}

