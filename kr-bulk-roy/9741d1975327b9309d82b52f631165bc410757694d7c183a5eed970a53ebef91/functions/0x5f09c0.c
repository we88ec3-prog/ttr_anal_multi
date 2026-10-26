
void FUN_005f09c0(void)

{
  int iVar1;
  int *in_ECX;
  int iVar2;
  
  FUN_007545b0();
  (**(code **)(*in_ECX + 0xbc))
            (in_ECX[2],in_ECX[3],in_ECX[4],*(int *)(in_ECX[0x66] + 0x14) + 0x4b + in_ECX[3]);
  iVar1 = *(int *)(in_ECX[0x66] + 0x14);
  iVar2 = iVar1 + 10;
  FUN_00749a00(*(undefined4 *)(in_ECX[0x6c] + 8),iVar2);
  FUN_00749a00(*(undefined4 *)(in_ECX[0x6f] + 8),iVar2);
  FUN_00749a00(*(undefined4 *)(in_ECX[0x70] + 8),iVar1 + 0x1e);
  return;
}

