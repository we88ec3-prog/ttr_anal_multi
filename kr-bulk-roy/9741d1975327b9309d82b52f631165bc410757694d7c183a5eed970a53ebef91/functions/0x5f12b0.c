
void FUN_005f12b0(void)

{
  int iVar1;
  int *in_ECX;
  int *piVar2;
  int iVar3;
  
  FUN_007545b0();
  (**(code **)(*in_ECX + 0xbc))
            (in_ECX[2],in_ECX[3],in_ECX[4],*(int *)(in_ECX[0x66] + 0x14) + 0xc3 + in_ECX[3]);
  iVar3 = 0;
  piVar2 = in_ECX + 0x7b;
  do {
    iVar1 = *(int *)(in_ECX[0x66] + 0x14) + 10 + iVar3;
    FUN_00749a00(*(undefined4 *)(piVar2[-9] + 8),iVar1);
    FUN_00749a00(*(undefined4 *)(*piVar2 + 8),iVar1);
    FUN_00749a00(*(undefined4 *)(piVar2[3] + 8),iVar1 + 0x14);
    iVar3 = iVar3 + 0x3c;
    piVar2 = piVar2 + 1;
  } while (iVar3 < 0xb4);
  return;
}

