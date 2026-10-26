
void FUN_00611230(void)

{
  int iVar1;
  int *in_ECX;
  int iVar2;
  int iVar3;
  
  FUN_007545b0();
  iVar1 = in_ECX[0x5a];
  iVar2 = *(int *)(in_ECX[0x5d] + 0x14) + 10;
  (**(code **)(*(int *)in_ECX[0x5a] + 0xbc))
            (*(undefined4 *)(iVar1 + 8),*(int *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 0x10),
             *(int *)(iVar1 + 0xc) + iVar2);
  FUN_00749a00(*(undefined4 *)(in_ECX[0x5e] + 8),iVar2);
  FUN_007545b0();
  iVar1 = in_ECX[0x5e];
  iVar3 = *(int *)(in_ECX[0x60] + 0x14) + 10;
  (**(code **)(*(int *)in_ECX[0x5e] + 0xbc))
            (*(undefined4 *)(iVar1 + 8),*(int *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 0x10),
             *(int *)(iVar1 + 0xc) + iVar3);
  (**(code **)(*in_ECX + 0xbc))(in_ECX[2],in_ECX[3],in_ECX[4],iVar3 + in_ECX[3] + iVar2);
  return;
}

